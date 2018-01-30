/**
 * The SHT2x Driver provides access to the functionality of the SHT20, SHT21 
 * and SHT2x sensors
*/
//% color=#4c6ef5 weight=25 icon="\uf043" block="SHT2x Sensor"
namespace SHT2xDriver {
    /**
     * Read Relative Humidity from the SHT2x Sensor.
     * Returns a number describing the relative humidity in percentage % relative
     * humidity
    */
    //% shim=SHT2xDriver::read_humidity
    //% blockId="SHT2xDriver_read_humidity"
    //% block="read humidty"
    export function read_humidity(): number{
        // Dummy implementation for the simulator.
        console.log("Simulate: Read Humidity from SHT2x sensor: 50");
        return 50.0;
    }

    /**
     * Read Temperature in degrees celcius from the SHT2x sensor.
     * Returns a number describing the ambient temperature in degrees celcius
    */
    //% shim=SHT2xDriver::read_temperature
    //% blockId="SHT2xDriver_read_temperature"
    //% block="read temperature"
    export function read_temperature(): number{
        // Dummy implementation for the simulator.
        console.log("Simulate: Read Temperature from SHT2x sensor: 50");
        return 30.0;
    }

    /** 
     * Change the I2c address used to interact with the SHT2x to the given
     * address. The I2c address should be within 0-127.
    */
    //% shim=SHT2xDriver::set_i2c_address
    //% blockId="SHT2xDriver_set_i2c_address"
    //% block="Change i2c address to %address"
    //% advanced=true
    export function set_i2c_address(address:number)
    {
        // Dummy implementation for the simulator.
        if(address < 0 || address > 128) 
        { console.log("Simulate: Invaild i2c Address: "  + address); }
        else { console.log("Simulate: Set i2c address to " + address); }
    }
}
