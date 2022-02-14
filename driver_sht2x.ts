/**
 * The SHT2x Driver provides access to the functionality of the SHT20, SHT21 
 * and SHT2x sensors
*/

let sht_i2c_address = 0x40;

//% color=#4c6ef5 weight=25 icon="\uf043" block="SHT2x Sensor"
namespace SHT2xDriver {
    /**
     * Read Relative Humidity from the SHT2x Sensor.
     * Returns a number describing the relative humidity in percentage % relative
     * humidity
    */
    //% blockId="SHT2xDriver_read_humidity"
    //% block="read humidty"
    export function read_humidity(): number {
        pins.i2cWriteNumber(sht_i2c_address, 0xF3, NumberFormat.UInt8LE, false);
        basic.pause(100);
        let buff = pins.i2cReadBuffer(sht_i2c_address, 3);
        let result = buff[0] << 8;
        result |= buff[1];
        result = (((15625 * result) >> 13) - 6000) / 1000;
        return result;
    }

    /**
     * Read Temperature in degrees celcius from the SHT2x sensor.
     * Returns a number describing the ambient temperature in degrees celcius
    */
    //% blockId="SHT2xDriver_read_temperature"
    //% block="read temperature"
    export function read_temperature(): number {
        pins.i2cWriteNumber(sht_i2c_address, 0xF3, NumberFormat.UInt8LE, false);
        basic.pause(100);
        let buff = pins.i2cReadBuffer(sht_i2c_address, 3);
        let result = buff[0] << 8;
        result |= buff[1];
        result = (((21965 * result) >> 13) - 46850) / 1000;
        return result;
    }

    /** 
     * Change the I2c address used to interact with the SHT2x to the given
     * address. The I2c address should be within 0-127.
    */
    //% blockId="SHT2xDriver_set_i2c_address"
    //% block="Change i2c address to %address"
    //% advanced=true
    export function set_i2c_address(address: number) {
        if (address < 0 || address > 128) basic.showString("Invalid I2C address");
        else sht_i2c_address = address;
    }
}
