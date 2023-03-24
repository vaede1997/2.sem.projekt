#include "../Header/UR5.h"

UR5::UR5()
{
    if (modbus_connect(ur5) == -1)
    {
        std::cout << ("Modbus: Connection Failed!") << std::endl;
    }
    else
    {
        std::cout << ("Modbus: Connection Success!") << std::endl;
        connected = true;
    }
}

void UR5::setX(uint16_t cellX)
{
    if (!isConnected())
    {
        std::cout << ("Modbus: Counldn't set x!") << std::endl;
    }
    else
    {
        uint16_t val = xCorner + 40 * cellX;
        int xx = modbus_write_register(ur5, 128, val);
        if (xx == -1)
        {
            std::cout << ("Modbus: Counldn't set x!") << std::endl;
        }
    }
}

void UR5::setY(uint16_t cellY)
{
    uint16_t val = yCorner + 40 * cellY;
    if (!isConnected())
    {
        std::cout << ("Modbus: Counldn't set y!") << std::endl;
    }
    else
    {
        int xx = modbus_write_register(ur5, 129, val);
        if (xx == -1)
        {
            std::cout << ("Modbus: Counldn't set y!") << std::endl;
        }
    }
}

void UR5::setZ(uint16_t val)
{
    if (!isConnected())
    {
        std::cout << ("Modbus: Counldn't set z!") << std::endl;
    }
    else
    {
        int xx = modbus_write_register(ur5, 130, val);
        if (xx == -1)
        {
            std::cout << ("Modbus: Counldn't set z!") << std::endl;
        }
    }
}

void UR5::setCO(uint16_t val)
{
    if (!isConnected())
    {
        std::cout << ("Modbus: Counldn't set Digital Output!") << std::endl;
    }
    else
    {
        int xx = modbus_write_register(ur5, 31, val);
        if (xx == -1)
        {
            std::cout << ("Modbus: Counldn't set Digital Output!") << std::endl;
        }
    }
}

int UR5::getDO()
{

    uint16_t val;
    int xx = modbus_read_registers(ur5, 1, 1, &val);
    if (xx == -1)
    {
        std::cout << ("Modbus: Counldn't get Digital Output!") << std::endl;
        return -1;
    }
    return val;
}

bool UR5::isConnected()
{
    return connected;
}
void UR5::movePiece(int x, int y, int z)
{
    sleep_for(1s);
    setX(x);
    setY(y);
    setZ(z);
    setCO(1);
    while (getDO() != 2)
    {
    }
    sleep_for(3s); // Wait for piece to be picked up
    setCO(1);
}