#include <OneWire.h>

OneWire oneWire(14); // Data pin connected to digital pin 14
float sensorOutput[8]; // Array to store temperature outputs, maximum 8 sensors

void readTemperature(byte address[], int index) {
    oneWire.reset(); // Reset the 1-Wire bus
    oneWire.select(address); // Select the sensor based on its address
    oneWire.write(0x44); // Convert temperature command
    delay(150); // Wait for conversion (adjust for 12-bit resolution)

    oneWire.reset(); // Reset the 1-Wire bus again
    oneWire.select(address); // Select the sensor
    oneWire.write(0xBE); // Read data without using scratchpad

    byte data[2];
    // Read two bytes of data
    data[0] = oneWire.read();
    data[1] = oneWire.read();

    // Combine the two bytes into a 16-bit raw temperature value
    unsigned short rawTemperature = (data[1] << 8) | data[0];

    // Convert raw temperature value to Celsius
    float temperature = (((short)rawTemperature) / 256.0 + 40.0);

    // Store temperature in the sensorOutput array
    sensorOutput[index] = temperature;
}

void setup() {
    Serial.begin(115200); // Initialize Serial communication at 115200 baud rate
    oneWire.reset_search(); // Reset the search
    Serial.println("Scanning for OneWire devices...");
    byte address[8];
    int sensorIndex = 0; // Index for sensorOutput array

    // Scan for devices on the OneWire bus
    while (oneWire.search(address) && sensorIndex < 8) {
        Serial.print("Found OneWire device with address: ");
        for (int i = 0; i < 8; i++) {
            Serial.print(address[i], HEX);
            Serial.print(" ");
        }
        Serial.println();
        readTemperature(address, sensorIndex);
        sensorIndex++;
        delay(50); // Delay between reading each sensor
    }

    if (sensorIndex == 0) {
        Serial.println("No OneWire devices found.");
    }
}

void loop() {
    // Scan for devices on the OneWire bus and update temperatures
    byte address[8];
    int sensorIndex = 0; // Index for sensorOutput array

    // Scan for devices on the OneWire bus
    while (oneWire.search(address) && sensorIndex < 8) {
        readTemperature(address, sensorIndex);
        sensorIndex++;
        delay(50); // Delay between reading each sensor
    }

    // Example usage of temperature values
    float t1 = sensorOutput[0];
    float t2 = sensorOutput[1];

    // Print temperature values
    Serial.print("t1: ");
    Serial.println(t1);
    Serial.print("t2: ");
    Serial.println(t2);

    // Delay before next iteration
    delay(500);
}
