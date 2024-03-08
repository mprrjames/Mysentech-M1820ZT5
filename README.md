# Mysentech M1820 Code

Code for the regular dallas DS18B20 temperature IC DOES NOT work, for this temp sensor, despite the similar name.
This code is written based on info from a limited chinese datasheet but seems to work very well. The IC also has a memory area called 'scratchpad' but we aren't using that here.

Make sure to have a 4k7 resistor from data to your MCU's positive. whether that's 3.3v or 5v.

The sensor can be purchase online from LCSC:
https://www.lcsc.com/products/Temperature-Sensors_585.html?keyword=M1820


in the example code im using pin14 from my ESP32. 
on an arduino Uno you can use pins 2,3,4,5,6,7,8 to 13. Ie any digital pin that's not being used. 
These Mysentech temp sensors also have a unique ID that can be read. multiple probes can share the same data line. 

UPDATE**
I've added a second .ino file to read multiple sensors from the same IO pin.
first it scans for any devices attached, records their address, then later gets the temperature from the recorded devices based on their address.

Your'e welcome,
James
