

// include the library and components.
#include <LiquidCrystal.h>
#include "src/Display/Display.h"
#include "src/StickDir/StickDir.h"
#include "src/RGBLed/RGBLed.h"
#include "src/RGBConverter/RGBConverter.h"

// initialize the components we need.
Display display = Display();
StickDir stickDir = StickDir();
RGBLed rgbLed = RGBLed();
RGBConverter rgbConverter = RGBConverter();

void setup() {
  // The stick needs to set the right input for the switch and to set the origin position.
  stickDir.setup();
}

void loop() {
  // Output the current state of the stick for debugging purposes.
  double brightness = stickDir.getDistance();
  double hue = stickDir.getAngle();

  // Convert the HSV value to RGB.
  byte rgb[3];
  rgbConverter.hsvToRgb(hue, 1, brightness, rgb);

  // Output the values on display.
  display.write(0, 0, "d" + String(brightness) + "       ");
  display.write(8, 0, "a" + String(hue) + "        ");
  display.write(0, 1, "r" + String(rgb[0]) + "        ");
  display.write(5, 1, "g" + String(rgb[1]) + "        ");
  display.write(10, 1, "b" + String(rgb[2]) + "        ");
  
  // Update the led.
  rgbLed.setRGB(rgb[0], rgb[1], rgb[2]);
  delay(10);
}
