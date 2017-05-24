# ultrasonic
ultrasonic sensor code

The folder pi_code contains code for reading an ultrasonic distance sensor with a Raspberry Pi.

## Design

The overall digital I/O interface to the SR-04 sensor uses the Pi's SPI interface to drive the trigger pulse and measure the resulting ECHO pulse.  This is done because polling GPIO to measure the ECHO pulse time would likely cause variation based on CPU and thread/process scheduling load.  The SPI interface is run via DMA and provides a consistent measurement.

The TRIG pulse is driven with the MOSI pin, while the ECHO signal is mapped to the MISO pin of the Pi.  We do not use the clock signal or any chip select lines that are normally used or "real" SPI communication.

Note that some ultrasonic sensors seem to require a pullup for the ECHO signal to work properly, and many require a voltage divider because they are 5V sensors and the Pi is 3.3V GPIO.  Connecting a 5V sensor directly to 3.3V GPIO will almost certainly damage the Pi hardware.

