//Pulsing lights - Adafruit Gemma + NeopPixel Ring
// https://github.com/OlaKarlsson/digital-bling
// 
//Code modified from code found at http://forums.adafruit.com/viewtopic.php?f=47&t=59377

#include <Adafruit_NeoPixel.h>

#define PIN 0 // assign constant PIN to the pin D0~ on the Gemma

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN);

// Change These Variables
int maxBrightness = 60;
int minBrightness = 3;
int fadeSpeed = 45;
 
void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
 
}
 
void loop() {
 
  //Set the color with Red, Gree, Blue values
  pulseColor(strip.Color(255, 0, 0), fadeSpeed); //Red
  //pulseColor(strip.Color(0, 0, 255), fadeSpeed); //Blue
}
 
 
void pulseColor(uint32_t c, uint8_t wait) {
  //Increase Brightness / Fade In
  for(int i=minBrightness; i<maxBrightness; i++) {
      strip.setBrightness(i);
      for(int x=0; x<strip.numPixels(); x++){
        strip.setPixelColor(x,c);
      }
      strip.show();
      delay(wait);
  }
  //Lower Brightness / Fade Out
  for(int i=maxBrightness; i>minBrightness; i--) {
       strip.setBrightness(i);
      for(int x=0; x<strip.numPixels(); x++){
        strip.setPixelColor(x,c);
      }
      strip.show();
      delay(wait);
  }
}
