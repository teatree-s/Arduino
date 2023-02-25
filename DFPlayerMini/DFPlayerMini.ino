/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/DigitalReadSerial
*/

#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h" 

const int PhotoSensorD0 = 4;
const int DfSoftwareRx = 2;
const int DfSoftwareTx = 3;

SoftwareSerial dfSoftwareSerial(DfSoftwareTx, DfSoftwareRx);
DFRobotDFPlayerMini dfDFPlayer;

// put your setup code here, to run once:
void setup() {
  Serial.begin(9600);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  dfSoftwareSerial.begin(9600);
  if (!dfDFPlayer.begin(dfSoftwareSerial)) {
    // Ignore errors
  }
  Serial.println(F("DFPlayer Mini online."));
  delay(2000);

  dfDFPlayer.volume(10);  // 0 - 30
  dfDFPlayer.stop();

  // PhotoSensor
  pinMode(PhotoSensorD0, INPUT);

  Serial.println("Initializing Done");
}

// put your main code here, to run repeatedly:
void loop() {
  static bool isPlay = false;
  int offLight = digitalRead(PhotoSensorD0);
  if (offLight) {
    if (isPlay) {
      dfDFPlayer.stop();
      isPlay = false;
    }
  } else {
    if (!isPlay) {
      dfDFPlayer.play(1);
      isPlay = true;
    }
  }
  Serial.print("Light:");
  Serial.print(!offLight);  // The serial will print the light value
  Serial.print("Play:");
  Serial.println(isPlay);
  delay(330);
}
