#ifndef SHT2x_DRIVER_H
#define SHT2x_DRIVER_H

#define SHT2x_DRIVER_H

#include <stddef.h>
#include "pxt.h"

#define DEBUG 1

/* DEBUG PRINT */
#ifdef DEBUG
#undef printf
#define dprint(msg) uBit.serial.printf("DEBUG: %d: %s: %s\r\n",__LINE__,__func__,msg)
#define dprintf(...) uBit.serial.printf("DEBUG: " __VA_ARGS__)
#else
#define dprint(msg)
#define dprintf(...)
// ^^ Empty Define ^^
#endif /* DEBUG PRINT */

/* Address for talking to i2c */
#define SHT2X_I2C_ADDR 0x80

#define SHT2X_PANIC_CODE 80

/* Macros for converting data from the sensor to human readable measurements */
#define SHT_CONV_TEMP(val) (-46.85 + (175.72 / 65536.0 * (double) val))
#define SHT_CONV_HUMID(val) (-6.0 + (125.0 / 65536.0 * (double) val))

namespace SHT2xDriver 
{
    /*
     * Commands for the SHT2x sensor 
     * see spec.txt or the SHT2x Datasheet
    */
    typedef enum sht_command_t
    {
        sht_command_temperature_hold = 0xE3,
        sht_command_humidity_hold  = 0xE5,
        sht_command_temperature = 0xF3,
        sht_command_humidity = 0xF5
    }SHTCommand;
    
    /* Read humidity level from the sensor in %Relative Humidity*/
    //%
    int read_humidity();

    /* Read temperature from the sensor in degree's celcius*/
    //%
    int read_temperature();
}

#endif /* ifndef SHT2x_DRIVER_H */
