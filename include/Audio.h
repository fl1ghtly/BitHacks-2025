#include <HardwareSerial.h>
#include <DFRobotDFPlayerMini.h>

const int rxPin = 20;
const int txPin = 21;
HardwareSerial mySerial1(1);


DFRobotDFPlayerMini player; //initializing the object

void audioInit() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //Serial.println("balls");


  //no idea what the first 2 inputs mean
  //initializing the pins
  mySerial1.begin(9600, SERIAL_8N1, rxPin, txPin);

  delay(1000); //needed to apparently setup the board

void AudioInit()

void playerShoot() {
    player.play(playerShoot);
}

void playerHit() {
    player.play(playerHit);
}

void playerDies()) {
    player.play(playerDies);
}

void 


}
