#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <Arduino.h>
const int vrx = 4;
const int vry = 5;
const int sw = 6;
const int deadzoneLow = 1000; // lower bound of deadzone
const int deadzoneHigh = 3000; // upper bound of deadzone

struct Input
{
    float x;
    float y;
};

void ControllerInit() {
    pinMode(vrx, INPUT);
    pinMode(vry, INPUT);
    pinMode(sw, INPUT_PULLUP);
}

Input ControllerLoop() {
    //Read joystick values (0 to 4095)
    int x = analogRead(vrx);
    int y = analogRead(vry);
    int buttonState = digitalRead(sw);
    int yValue;
    int xValue;
    //normalize the values to -1 to 1 range (really just -1, 0, and 1)
    //if the value is in the deadzone, set it to 0
    
    
    int raw_x = x;
    if (x < 550){
        x = -1;
    } else if (x > 4000) {
        x = 1;
    } else {
        x = 0;
    }

    int raw_y = y;
    if(y < 1000) {
        y = -1;
    } else if (y > 3800) {
        y = 1;
    } else {
        y = 0;
    }
    
    Serial.print("Raw X Value: ");
    Serial.println(raw_x);
    Serial.println(" ");
    Serial.print("Raw Y Value: ");
    Serial.println(raw_y);
    Serial.print("X Value: ");
    Serial.println(x); // normalize to -1 to 1 range
    Serial.println(" ");
    Serial.print("Y Value: ");
    Serial.println(y); //normalize to -1 to 1 range
    Serial.println(" ");
    Serial.print("Button State:");
    Serial.println(buttonState);
    // delay(50); //Delay to prevent overload serial monitor
    
    Input input = {x, y};
    return input;
};

#endif // CONTROLLER_H