# microDriver - SHT2X 
---
MicroBit driver for SHT20, SHT21, SHT25 digital sensor, enabliing the the 
microbit to obtain temperture or relative humidity from these sensors. The 
driver comes in both C++ library and a makecode package for use on the 
[Makecode Microbit Editor](makecode.microbit.org).

## Setup
1. Library Version
    * Include `driver.h` for the defintions.
    * Compile you program with `driver.c`.
2. Makecode Version
    * Navigate to **Add Package** and enter this repository's URL.
    * Select this package from the results.

## Usage
First ensure that the sensor is _connected properly_ to the MicroBit's I2c pins.

This package/library provides:
1. `read_temperture()` - Read ambient tempreture
    * reads the temperture from the sensor.
    * returns the tempreture as an integer in degree celcius
2. `read_humidity()` - - Read ambient relative humidity
    * reads the relative humidity from the sensor.
    * returns the relative humidity in as a integer percentage.

## Troubleshooting
1. MicroBit panics _(displays a frowning face) with an error code of 80.
    * The driver was unable to read from the sensor. Check whether the sensor
        is connected properly.

## License

MIT

## Supported targets

* for PXT/microbit
(The metadata above is needed for package search.)
