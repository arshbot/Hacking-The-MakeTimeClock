include "neopixel/neopixel.h"

#define PIXEL_COUNT 6
#define PIXEL_PIN D1
#define BUTTON_PIN A0
#define PIXEL_TYPE WS2812B

  
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE); 

char publishString[64];
bool buttonHasBeenPressed = false;
int previousButtonVolt = 0;
int victoryDanceDelayValue = 100;
int topIndexPixelOn = -1;

void setup() {
    Serial.begin(9600);
    strip.begin();
    strip.show();
}
  
void loop() {
    
    checkButtonFinishPress();
    
    if (buttonHasBeenPressed == true) {
        incrementLitPixelIndex();
    }
    
    updateLitPixels();
    finishLoop();
}

void victoryDance() {
    strip.clear();
    strip.show();
    strip.setPixelColor(5, strip.Color(61, 252, 3));
    strip.show();
    delay(victoryDanceDelayValue);
    strip.setPixelColor(0, strip.Color(3, 252, 211));
    strip.show();
    delay(victoryDanceDelayValue);
    strip.setPixelColor(1, strip.Color(3, 181, 252));
    strip.show();
    delay(victoryDanceDelayValue);
    strip.setPixelColor(2, strip.Color(3, 3, 252));
    strip.show();
    delay(victoryDanceDelayValue);
    strip.setPixelColor(3, strip.Color(144, 0, 255));
    strip.show();
    delay(victoryDanceDelayValue);
    strip.setPixelColor(4, strip.Color(242, 41, 229));
    strip.show();
    delay(200);
}

void updateLitPixels(){
    if (topIndexPixelOn != -1) {
        for(int i = 0; i <= topIndexPixelOn; i += 1) {
            strip.setPixelColor(i, strip.Color(255, 255, 0));
        }
        
        strip.show();
    }
    else {
        strip.clear();
    }
    
    strip.show();
}

void incrementLitPixelIndex() {
    topIndexPixelOn += 1;
    
    sprintf(publishString, "topIndexPixelOn set to %i", topIndexPixelOn);

    if (topIndexPixelOn > 5) {
        publishString = publishString + " - victoryDance!"
        
        topIndexPixelOn = -1;
        victoryDance();
    }
    
    Serial.println(publishString);

}

void checkButtonFinishPress() {
    int buttonVolt = analogRead(BUTTON_PIN);
    
    // The previousButtonVolt represents a pressed button when > 4000
    if (previousButtonVolt > 4000) {
        
        // Button has finished being pressed!
        if (buttonVolt < 4000) {
            buttonHasBeenPressed = true;
            
            Serial.println("Button has finished being pressed")
        }
    }
    
    previousButtonVolt = buttonVolt;
}

void finishLoop() {
    if (buttonHasBeenPressed == true) {
        buttonHasBeenPressed = false;
    }

    delay(100);
}
