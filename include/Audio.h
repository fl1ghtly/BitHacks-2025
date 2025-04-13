#ifndef AUDIO_H
#define AUDIO_H

#include <HardwareSerial.h>
#include <DFRobotDFPlayerMini.h>

const int rxPin = 20;
const int txPin = 21;
HardwareSerial mySerial1(1);


DFRobotDFPlayerMini player; //initializing the object

void audioInit() {
  // put your setup code here, to run once:
  Serial.begin(115200);


  //no idea what the first 2 inputs mean
  //initializing the pins
  mySerial1.begin(9600, SERIAL_8N1, rxPin, txPin);

  delay(1000); //needed to apparently setup the board
}

void AudioInit() {
    player.play(1);
}

void playerShoot() {
    player.play(5);
}

void playerHit() {
    player.play(3);
}

void playerDies() {
    player.play(6);
}

void playerMoves() {
    player.play(4);
}

void enemyMoves() {
    player.play(8);
}

void enemyShoots() {
    player.play(7);
}

void enemyHit() {
    player.play(2);
}

#endif



