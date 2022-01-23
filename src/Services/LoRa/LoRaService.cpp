#include "LoRaService.hpp"

LoRaService::LoRaService()
{

}

LoRaService::~LoRaService()
{
    LoRa.end();
}

void LoRaService::Initialize()
{
    SPI.begin(_serialClockPin, _masterInSlaveOutPin, _masterOutSlaveInPin, _slaveSelectPin);
    LoRa.setPins(_slaveSelectPin, _resetPin, _digitalPin);
    LoRa.begin(_frequency);
    LoRa.enableCrc();

    Serial.println("LoRa Model started up");
}

std::string LoRaService::ReadMessagePart(int length)
{
    std::string message = "";

    for (int i = 0; i < length; ++i)
    {
        message += (char)LoRa.read();
    }

    return message;
}

Message LoRaService::ReadMessageFromRadio()
{
    Message message {};

    message.ReceiverId = ReadMessagePart(LoRa.read());
    message.SenderId = ReadMessagePart(LoRa.read());

    int messageLength = LoRa.read();
    while (LoRa.available())
    {
        message.Message += (char) LoRa.read();
    }

    if (message.Message.length() != messageLength)
    {
        Serial.printf("Error. Message has not the right length (Expected length: %d, Actual length: %d)\n", messageLength, message.Message.length());
    }

    Serial.printf("[%s] < %s\n", message.SenderId.c_str(), message.Message.c_str());

    return message;
}


void LoRaService::CheckForNewMessages()
{
    int packetSize = LoRa.parsePacket();

    if (packetSize > 0)
    {
        MessageType messageType = (MessageType) LoRa.read();

        switch (messageType)
        {
            case MessageType::MessagePacket:
            {
                Message message = ReadMessageFromRadio();

                break;
            }

            case MessageType::AcknowledgmentPacket:
            case MessageType::KeyExchangePacket:
                break;
        }
    }
}

bool LoRaService::SendMessage(Message message)
{
    LoRa.beginPacket();
    LoRa.write(MessageType::MessagePacket);

    LoRa.write(message.ReceiverId.length());
    LoRa.print(message.ReceiverId.c_str());

    LoRa.write(message.SenderId.length());
    LoRa.print(message.SenderId.c_str());

    LoRa.write(message.Message.length());
    LoRa.print(message.Message.c_str());

    bool success = LoRa.endPacket();

    if (success)
    {
        Serial.println(("[" + message.ReceiverId + "]" + " > " + message.Message).c_str());
    }

    return success;
}