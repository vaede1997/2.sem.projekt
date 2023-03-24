#pragma once
#include <modbus.h>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;
using namespace std::this_thread;

class UR5
{
private:
    modbus_t *ur5 = modbus_new_tcp("192.168.100.11", 502);
    uint16_t xCorner = 223;
    uint16_t yCorner = 470;
    bool connected = false;

public:
    UR5();
    void setX(uint16_t cellY);
    void setY(uint16_t cellY);
    void setZ(uint16_t val);
    void setCO(uint16_t val);
    int getDO();
    bool isConnected();
    void movePiece(int x, int y, int z);
};
