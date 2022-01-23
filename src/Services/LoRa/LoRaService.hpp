#pragma once

#include <Arduino.h>
#include <LoRa.h>
#include <SPI.h>
#include "Entities/Message.hpp"
#include "Services/LoRa/Entities/MessageType.hpp"

class LoRaService
{
private:
    static constexpr int _serialClockPin = 5;
    static constexpr int _masterInSlaveOutPin = 19;
    static constexpr int _masterOutSlaveInPin = 27;
    static constexpr int _slaveSelectPin = 18;
    static constexpr int _resetPin = 14;
    static constexpr int _digitalPin = 26;

    static constexpr int _frequency = 868E6;
    static constexpr int _deviceId = 86;

    Message ReadMessageFromRadio();
    std::string ReadMessagePart(int length);


public:
    LoRaService();
    ~LoRaService();

    void Initialize();
    void CheckForNewMessages();
    bool SendMessage(Message message);
};