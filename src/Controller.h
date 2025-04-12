#include <Arduino.h>

const int vrx = 4;
const int vry = 5;
const int sw = 6;

void ControllerInit() {
    pinMode(vrx, INPUT);
    pinMode(vry, INPUT);
    pinMode(sw, INPUT_PULLUP);
}

void ControllerLoop() {
    float x = analogRead(vrx);
    float y = analogRead(vry);
    int buttonState = digitalRead(sw);



    //normalize the values to -1 to 1 range (original values 0 to 4095) and set max value of 1
    float x_normalized = (x - 2048) / 2048.0 + 0.4; //with offset of 0.35
    float y_normalized =  (y - 2048) / 2048.0 - 0.4; //with offset of 0.4

    x_normalized = constrain(x_normalized, -1.0, 1.0); // constrain to -1 to 1 range
    y_normalized = constrain(y_normalized, -1.0, 1.0); // constrain to -1 to 1 range

    Serial.print("X Value: ");
    Serial.println(x_normalized); // normalize to -1 to 1 range
    Serial.println(" ");
    Serial.print("Y Value: ");
    Serial.println(y_normalized); //normalize to -1 to 1 range
    Serial.println(" ");
    Serial.print("Button State:");
    Serial.println(buttonState);
    delay(500);
}

