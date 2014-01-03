MPL115A2 reader for Raspberry Pi
========

A program to read an absolute pressure sensor MPL115A2 for Raspberry Pi.

MPL115A2 is an absolute pressure sensor with a digital I2C output.
This program reads the sensor and shows current absolute pressure.
Make sure you have connected the MPL115A2 sensor to your Raspberry Pi.
## Requirements

- wiringPi library
- An MPL115A2 sensor connected to I2C bus of Respberry Pi

## Installation

    make
    make install

or just put getMPL115A2.pl on your desired place.
Add your user to the group 'i2c'.

## Usage

    $ getMPL115A2
    1006.8

or

    $ getMPL115A2.pl
    1005.8

    
## Reference

[MPL115A2 data sheet](http://cache.freescale.com/files/sensors/doc/data_sheet/MPL115A2.pdf)

## Contact

Osamu Mizuno / omzn

