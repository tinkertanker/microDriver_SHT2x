#include "driver.h"

using namespace pxt;

namespace SHT2xDriver
{
    static MicroBit uBit;

    /* Write given command to SHT2x, returning the reply recieved, <0 on error
     * Actual data size 8bit - 14bit, depending on command */
    uint16_t read_sht2x(SHTCommand cmd)
    {
        MicroBitI2C i2c(I2C_SDA0, I2C_SCL0);

        if(i2c.write(SHT2X_I2C_ADDR, (const char *)&cmd, sizeof(uint8_t) * 1)\
                != MICROBIT_OK)
        {
            dprint("Failed to write command to SHT2x");
            uBit.panic(SHT2X_PANIC_CODE);
        }
            
        dprintf("read_sht2x(): sent command to SHT2x: %x\r\n", cmd);

        uint8_t read_buf[2] = { 0 , 0 };
        uint16_t reply = 0;
        for(int i = 0; i < 4; i ++)
        {
            if(i2c.read(SHT2X_I2C_ADDR, (char *)&read_buf, sizeof(uint16_t) * 1)\
                    == MICROBIT_OK)
            {
                //Data Preprocessing
                reply = (read_buf[0] << 8) | (read_buf[1]); //Convert to LSB first from MSB first
                reply&= ~0x0003; //Remove status bits: last 2 bits

                dprintf("read_sht2x(): obtained reply from SHT2x: %hx\r\n", reply);
                
                return reply;
            }

            fiber_sleep(30);
        }

            //Read Failure: No response from sensor before timeout
        dprint("Read Failure: No response from sensor before timeout");
        uBit.panic(SHT2X_PANIC_CODE);
        return -1;
    }

    int read_humidity()
    {
        MicroBit uBit;
        uint16_t read_rst = read_sht2x(sht_command_humidity);
        int humidity = (int) SHT_CONV_HUMID(read_rst);
        
        dprintf("read_humidity(): Calculated %% Relative Humidity: %d %%\r\n", \
                humidity);

        return humidity;
    }


    int read_temperture()
    {
        uint16_t read_rst = read_sht2x(sht_command_temperture);
        int temperture = (int) SHT_CONV_TEMP(read_rst);
        dprintf("read_temperture(): Calculated Temperture: %d dg C\r\n", \
            temperture);

        return temperture;
    }
}
