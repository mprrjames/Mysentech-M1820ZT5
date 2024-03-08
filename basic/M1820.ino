/*  Reads temperature data from the high accuracy Mysentech temperature sensor
  connected to pin 14. Make sure to use a 4.7k resistor from sensor data pin to Vcc (3.3V or 5V) */

#include <OneWire.h>
OneWire oneWire(14); // Data pin connected to digital pin 14

float readTemperature() { // The sensor need this sequnce to 
    oneWire.reset(); // Reset the 1-Wire bus
    oneWire.write(0xcc); // Skip ROM command
    oneWire.write(0x44); // Convert temperature command
    delay(75); // Wait for conversion (adjust for 12-bit resolution)

    oneWire.reset(); // Reset the 1-Wire bus again
    oneWire.write(0xcc); // Skip ROM command
    oneWire.write(0xBE); // Read data without using scratchpad

    byte data[2];
    data[0] = oneWire.read();// Read two bytes of data
    data[1] = oneWire.read();
  
    // Combine the two bytes into a 16-bit raw temperature value
    unsigned short rawTemperature = (data[1] << 8) | data[0];
    // Convert raw temperature value to Celsius
    float temperature = (((short)rawTemperature) / 256.0 + 40.0);

    return temperature;
}

void setup() {
    Serial.begin(115200); // Initialize Serial communication at 115200 baud rate
}

void loop() {
    float temperature = readTemperature();
    Serial.print("Sensor Output: [");
    Serial.print(temperature);
    Serial.println(" degC]");
    delay(50); 
}
