/**
 * Welcome to the Plant Project
 *  
 *  TODO
 *  
 * Sensoterra Index Moisture Levels
 * 10  - complete saturation
 * 6.6 - the maximum amount of water that the soil can hold
 * 3.3 - the point at which plants begin to wilt permanently through drought
 * 0   - oven dry soil
 * 
 * Plant Levels
 * Too wet - >6.7 - 10
 * Healthy - 3.3 - <6.7
 * Too dry - 0 - 3.3 
 * created by Doru Muntean
 */

#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

// The screen has TFT_WIDTH  135 and TFT_HEIGHT 240


#define BUTTON1  35
#define BUTTON2  0

#define SOIL_MOISTURE 38

// FREE pins 37 and 38

#define NO_OF_SCREENS  2
int button1State = 0; 
int button2State = 0; 
int currentScreen = 0;

void setup()   {

  // initialize the BUTTON1 and BUTTON2 pin as an input:
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  
  //Set up the display
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  //tft.setTextSize(2); // Set character size multiplier (this increases pixel size)
  //tft.setTextColor(TFT_WHITE); // Set character (glyph) color only (background not over-written)
  tft.setTextColor(TFT_WHITE, TFT_BLACK); // Set character (glyph) foreground and backgorund colour
  //tft.setCursor(0, 0);  // Set cursor for tft.print()
}

void loop() {
  tft.fillScreen(TFT_BLACK);
  tft.drawNumber(currentScreen, 5, 5, 4); 

  tft.drawNumber(analogRead(SOIL_MOISTURE), 5, 40, 4);
    
  button1State = digitalRead(BUTTON1);
  button2State = digitalRead(BUTTON2);
  
  // check if the pushbutton is pressed.
  if (button1State == LOW) {
    currentScreen = (currentScreen + 1) % NO_OF_SCREENS;
  }

  if (currentScreen == 0) {
    tft.drawString("Sensoterra Index: 3", 5, 75, 4); // Draw text centre at position 80, 24 using font 4
  } else if (currentScreen == 1) {
    tft.drawString("Plant status: Healthy", 5, 75, 4); // Draw text centre at position 80, 24 using font 4
  }
  
  delay(1000);
}
