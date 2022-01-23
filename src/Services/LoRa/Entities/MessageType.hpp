#pragma once

#include <cstdint>

enum MessageType
{
    MessagePacket = 0,
    KeyExchangePacket,
    AcknowledgmentPacket
};
