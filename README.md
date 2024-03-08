# Mysentech M1820 Code

Code for the regular dallas DS18B20 temperature IC DOES NOT work, for this temp sensor, despite the similar name.
This code is written based on info from a limited chinese datasheet but seems to work very well. The IC also has a memory area called 'scratchpad' but we aren't using that here.

Make sure to have a 4k7 resistor from data to your MCU's positive. whether that's 3.3v or 5v.

The sensor can be purchase online from LCSC:
https://www.lcsc.com/products/Temperature-Sensors_585.html?keyword=M1820
