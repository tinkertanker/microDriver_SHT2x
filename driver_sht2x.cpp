#include "driver_sht2x.h"

using namespace pxt;

namespace SHT2xDriver
{
    static MicroBit uBit;
    static int sht_i2c_address = SHT2X_I2C_ADDR_DEFAULT;

    /* Write given command to SHT2x, returning the reply recieved, <0 on error
     * Actual data size 8bit - 14bit, depending on command */
    uint16_t read_sht2x(SHTCommand cmd)
    {
        MicroBitI2C i2c(I2C_SDA0, I2C_SCL0);

        if(i2c.write(sht_i2c_address, (const char *)&cmd, sizeof(uint8_t) * 1)\
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
            if(i2c.read(sht_i2c_address, (char *)&read_buf, sizeof(uint16_t) * 1)\
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
        uint16_t read_rst = read_sht2x(sht_command_humidity);
        int humidity = (int) SHT_CONV_HUMID(read_rst);
        
        dprintf("read_humidity(): Calculated %% Relative Humidity: %d %%\r\n", \
                humidity);

        return humidity;
    }


    int read_temperature()
    {
        uint16_t read_rst = read_sht2x(sht_command_temperature);
        int temperature = (int) SHT_CONV_TEMP(read_rst);
        dprintf("read_temperature(): Calculated temperature: %d dg C\r\n", \
            temperature);

        return temperature;
    }
    
    void set_i2c_address(int address)
    {
        if(address < 0 || address > 128) 
            dprint("Error: set_i2c_address(): Invaild i2c address");
            
        sht_i2c_address = address;
    }
}
