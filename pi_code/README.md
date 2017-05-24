This code uses the Raspberry Pi SPI interface to trigger the sensor and capture the echo pulse.

Currently it uses the script rep to call the standard spidev_test.c file to drive the SPI interface. The sampled pulse data is saved in a file inputcap. The countbits.c program will parse the inputcap file and print out the distance.

The trigger pulse is driven with the MOSI pin.  The first few bytes in the ttt file control the pulse width.  
The echo pin is connected to MISO pin.  Depending on the ultrasonic sensor used you may need a pullup or a voltage divider on this pin.  

To adjust the trigger pulse and sample time modify the ttt file.  The first few bytes have bits set to 1.  The reset of the file has 0x00 bytes.  

Example to create new ttt file to send 12 bit trigger and sample 32000 bits:

echo -ne "\xFF\xF0" > ttt; head -c 3998 /dev/zero >> ttt

Depending on your Pi version you may need to add core_freq=250 to the config.txt file.  This prevents the Pi from dynamically switching the core frequency, which affects the spi clock frequency.


