basic.forever(() => {
    SHT2xDriver.set_i2c_address(0x80);
    basic.showString("%RH:" + SHT2xDriver.read_humidity());
    basic.showString("TMP: " + SHT2xDriver.read_temperature());
})
