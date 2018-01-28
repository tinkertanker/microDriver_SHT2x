namespace SHT2xDriver {
    /**
     * Read %Relative Humidity from the sensor.
     * Relative Humidity is the amount of water vapor in the air, expressed as 
     * a percentage of the maximum amount that the air could hold at the given 
     * temperature.
     *
     * @return number describing the relative humidity in percentage % relative
     * humidity
     */
    //% shim=SHT2xDriver::read_humidity
    //% blockId="SHT2xDriver_read_humidity"
    //% block="read humidty"
    export function read_humidity(): number{
        // Dummy implementation for the simulator.
        console.log("Simulate: Read Humidity from SHT2x sensor");
        return 50.0;
    }

    /**
     * Read Temperature in degrees celcius from the sensor.
     *
     * @return number describing the ambient tempreture in degrees celcius
     */
    //% shim=SHT2xDriver::read_temperture
    //% blockId="SHT2xDriver_read_temperature"
    //% block="read tempreture"
    export function read_temperture(): number{
        // Dummy implementation for the simulator.
        console.log("Simulate: Read Temperature from SHT2x sensor");
        return 30.0;
    }
}
