This code uses the Raspberry Pi SPI interface to trigger the sensor and capture the echo pulse.

Currently it uses the script rep to call the standard spidev_test.c file to drive the SPI interface. The sampled pulse data is saved in a file inputcap. The countbits.c program will parse the inputcap file and print out the distance.
