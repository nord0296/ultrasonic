## Summary

This code uses the Raspberry Pi SPI interface to trigger the sensor and capture the echo pulse.

Currently it uses the script "rep" to call the compiled binary of spidev_test.c to drive the SPI interface. The sampled pulse data is saved in a file inputcap. The countbits.c program parses the inputcap file and prints out the measured distance.

## Usage

```
./spidev_test -D /dev/spidev0.0 -s 1000000 -i ttt -o inputcap
```

In the above command:  
```
  Select the spi device:              -D dev/spidev0.0
  Set the spi clock rate to 1 MHz:    -s 1000000
  Input file to send out on  spi:     -i ttt
  Captured MISO data outout file:     -o inputcap
```

## Trigger Pulse and Maximum Distance Adjustment

Both the trigger pulse width and maximum ECHO pulse measured (maps to maximum distance measurement) are set by the "ttt" input file.  The file is transmitted to the SPI port and sets both the trigger waveform output on MOSI, but also the number of bytes read back via the MISO signal (setting the maximum possible ECHO pulse measured).

To adjust the trigger pulse and sample time modify the ttt file.  The first few bytes have bits set to 1 -- the number of bytes determines the length of the pulse based on the SPI clock frequency (in bits per second).

The reset of the file has 0x00 bytes, the number of which will set the maximum time that the MISO pin is read and maps to maximum possible ECHO pulse that the Pi can measure.  Obviously the ultimate maximum distance to measure is likely set by the sensor and environment, but this can be set too small and cause problems.

Example to create new "ttt" file to send 12 bit trigger and sample 32000 bits:

```
echo -ne "\xFF\xF0" > ttt; head -c 3998 /dev/zero >> ttt
```

## SPI Frequency - Mapped to Pi Core Frequency

Depending on your Pi version you may need to add core_freq=250 to the config.txt file.  This prevents the Pi from dynamically switching the core frequency, which may directly affect the spi clock frequency (causing unreliable readings).

Core Freq Reference:
(https://www.raspberrypi.org/forums/viewtopic.php?f=28&t=149864)

