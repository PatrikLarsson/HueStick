

// include the library and components.
#include <LiquidCrystal.h>
#include "src/Display/Display.h"
#include "src/StickDir/StickDir.h"


// initialize the components we need.
Display display = Display();
StickDir stickDir = StickDir();

void setup() {
  // The stick needs to set the right input for the switch and to set the origin position.
  stickDir.setup();
}

void loop() {
  // Output the current state of the stick for debugging purposes.
  display.write(0, 0, "distance: " + String(stickDir.getDistance()) + "     ");
  display.write(0, 1, "x: " + String(stickDir.getX()) + "  ");
  display.write(7, 1, "y: " + String(stickDir.getY()) + "  ");

  delay(20);
}
