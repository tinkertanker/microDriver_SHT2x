serial.setBaudRate(9600);
SHT2xDriver.set_i2c_address(0x40);
basic.forever(() => {
    serial.writeLine("%RH:" + SHT2xDriver.read_humidity());
    serial.writeLine("TMP: " + SHT2xDriver.read_temperature());
    basic.pause(2000);
})
