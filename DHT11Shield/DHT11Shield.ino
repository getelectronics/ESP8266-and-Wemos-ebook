/*
 * DHT11 example
 * 
 * Adafruit Unified Sensor Library: https://github.com/adafruit/Adafruit_Sensor
 * DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
 */

#include "DHT.h"

#define DHTPIN D4     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11


DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  dht.begin();
}

void loop() 
{
  // Wait a few seconds between measurements.
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early
  if (isnan(h) || isnan(t) || isnan(f)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  //we simply output all data via the serial monitor
  //Tools -> Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.println(" *F");

}
