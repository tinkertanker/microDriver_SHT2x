#include "driver.h"

using namespace pxt;
using namespace SHT2xDriver;

/* Write given command to SHT2x, returning the reply recieved, <0 on error
 * Actual data size 8bit - 14bit, depending on command */
int16_t read_sht2x(SHTCommand cmd)
{
    MicroBitI2C i2c(I2C_SDA0, I2C_SCL0);

    char read_buf[2];

    i2c.write(SHT2X_I2C_ADDR, (const char *)cmd, sizeof(uint8_t) * 1);
    dprintf("read_sht2x(): sent command to SHT2x: %x\r\n");
    f
    
    
    for(int i = 0; i < 4; i ++)
    {
        if(i2c.read(SHT2X_I2C_ADDR, read_buf, sizeof(uint8_t) * 2)\
                == MICROBIT_OK)
        {
            //Data Preprocessing
            uint8_t *data = (uint8_t *)read_buf;
            (*data) &= ~0x0003; //Remove status bits: last 2 bits

            dprintf("read_sht2x(): obtained data from SHT2x: %x\r\n", (*data));
            
            return (int16_t)(*data);
        }

        fiber_sleep(30);
    }

    //Read Failure: No response from sensor before timeout
    dprint("Read Failure: No response from sensor before timeout");
    return -1;
        
}

double read_humidity()
{
    MicroBit uBit;
    int16_t read_rst = read_sht2x(sht_command_humidity);
    if(read_rst < 0) uBit.panic(SHT2X_PANIC_CODE);

    double  r_humidity = SHT_CONV_HUMID((uint16_t)read_rst);
    dprintf("read_humidity(): Calculated %% Relative Humidity: %.2lf%%\r\n", \
            r_humidity);

    return r_humidity;
}


double read_temperture()
{
    MicroBit uBit;
    int16_t read_rst = read_sht2x(sht_command_temperture);
    if(read_rst < 0) uBit.panic(SHT2X_PANIC_CODE);
    
    double tempreture = SHT_CONV_HUMID((uint16_t)read_rst);
    dprintf("read_temperture(): Calculated Tempreture: %.2lf dg C\r\n", \
        tempreture);

    return tempreture;
}
