//Install (https://github.com/adafruit/Adafruit_NeoPixel).

#include <Adafruit_NeoPixel.h>

#define PIN            D2

long randRed, randGreen, randBlue;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() 
{
  randRed = random(255);
  randGreen = random(255);
  randBlue = random(255);
  pixels.setPixelColor(0, pixels.Color(randRed, randGreen, randBlue)); //BLUE
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(1000); // Delay for a period of time (in milliseconds).
}
