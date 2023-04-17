

#include <stdint.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdint>
class ISOBUSFrame
{
public:
    uint8_t priority = 0;
    bool page = false;
    uint16_t PGN = 0;
    uint8_t SA = 0;
    uint8_t PF = 0;
    uint8_t PS = 0;
    uint8_t data[8];

    ISOBUSFrame() {}

    ISOBUSFrame(const ISOBUSFrame &other)
    {
        priority = other.priority;
        page = other.page;
        PGN = other.PGN;
        SA = other.SA;
        PF = other.PF;
        PS = other.PS;
        memcpy(data, other.data, sizeof(data));
    }

    ISOBUSFrame(uint32_t id, const uint8_t* payload, size_t size)
    {
        SA = (uint8_t)((id >> 0) & 0xFF);
        //std::cout << "SA: " <<SA << std::endl;
        PGN = (uint16_t)((id >> 8) & 0xFFFF);
        //std::cout << "PNG: " <<PGN << std::endl;
        page = (bool)((id >> 24) & 0x01);
        //std::cout << "Page: " <<page << std::endl;
        priority = (uint8_t)((id >> 26) & 0x07);
        //std::cout << "priority: " << priority << std::endl;
        PF = (uint8_t)((PGN >> 8) & 0xFF);
        //std::cout << "PF: " <<PF << std::endl;
        PS = (uint8_t)((PGN >> 0) & 0xFF);
        //std::cout << "PS: " <<PS << std::endl;

        //memcpy(data, payload, size);
        for(int i=0;i<size;i++) {
            data[i] = (uint8_t)payload[i];
            //std::cout << "data[" << i << "] = " << static_cast<int>(data[i]) << std::endl;
        }

        //std::cout << "DATA: " << data << std::endl;
    }

    uint32_t getCanID() const
    {
        if(SA != 0)
            return (priority<<26) | (page << 24) | (PGN << 8) | (SA);
        else
            return 0;
    }
};

