/**
 * The SHT2x Driver provides access to the functionality of the SHT20, SHT21 
 * and SHT2x sensors
*/
//% color=#4c6ef5 weight=25 icon="\uf043" block="SHT2x Sensor"
namespace SHT2xDriver {
    /**
     * Read Relative Humidity from the SHT2x Sensor.
     * @return number describing the relative humidity in percentage % relative
     * humidity
    */
    //% shim=SHT2xDriver::read_humidity
    //% blockId="SHT2xDriver_read_humidity"
    //% block="read humidty"
    export function read_humidity() {
        // Dummy implementation for the simulator.
        console.log("Simulate: Read Humidity from SHT2x sensor: 50");
        return 50.0;
    }

    /**
     * Read Temperature in degrees celcius from the SHT2x sensor.
     * @return number describing the ambient temperture in degrees celcius
    */
    //% shim=SHT2xDriver::read_temperture
    //% blockId="SHT2xDriver_read_temperature"
    //% block="read temperture"
    export function read_temperture(){
        // Dummy implementation for the simulator.
        console.log("Simulate: Read Temperature from SHT2x sensor: 50");
        return 30.0;
    }
}
