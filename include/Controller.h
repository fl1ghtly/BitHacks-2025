#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <Arduino.h>
const int vrx = 15;
const int vry = 16;
const int sw = 17;
const int deadzoneLow = 1000; // lower bound of deadzone
const int deadzoneHigh = 3000; // upper bound of deadzone



void ControllerInit() {
    pinMode(vrx, INPUT);
    pinMode(vry, INPUT);
    pinMode(sw, INPUT_PULLUP);
}

void ControllerLoop() {
    //Read joystick values (0 to 4095)
    int x = analogRead(vrx);
    int y = analogRead(vry);
    int buttonState = digitalRead(sw);
    int yValue;
    int xValue;
    //normalize the values to -1 to 1 range (really just -1, 0, and 1)
    //if the value is in the deadzone, set it to 0
    x += 1000;
    if (x < 1615){
        x = -1;
    } else if (x > 4000) {
        x = 1;
    } else {
        x = 0;
    }
    
    if(y < 1000) {
        y = -1;
    } else if (y > 3800) {
        y = 1;
    } else {
        y = 0;
    }
    
    Serial.print("X Value: ");
    Serial.println(x); // normalize to -1 to 1 range
    Serial.println(" ");
    Serial.print("Y Value: ");
    Serial.println(y); //normalize to -1 to 1 range
    Serial.println(" ");
    Serial.print("Button State:");
    Serial.println(buttonState);
    delay(500);
};

#endif // CONTROLLER_H