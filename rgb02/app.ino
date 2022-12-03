#include "ColorLed.h"

ColorLed color(9,10,11);

void setup() {

}

void loop() {
    color.random();
    delay(1000);
}