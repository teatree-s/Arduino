/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

//initializing and declaring led rows
#define COLUMN_NUM 4
int column[COLUMN_NUM]={3,4,6,5};
//initializing and declaring led layers
#define LAYER_NUM 2
int layer[LAYER_NUM]={A3,A4};

int time = 250;

// the setup function runs once when you press reset or power the board
void setup() {
  //setting rows to ouput
  for(int i = 0; i<COLUMN_NUM; i++) {
    pinMode(column[i], OUTPUT);
  }
  //setting layers to output
  for(int i = 0; i<LAYER_NUM; i++) {
    pinMode(layer[i], OUTPUT);
  }
  //seeding random for random pattern
  randomSeed(analogRead(10));
}

// the loop function runs over and over again forever
void loop() {
  turnEverythingOff();
  flickerOn();
  turnEverythingOn();
  delay(time);

  turnOnAndOffAllByLayerUpAndDownNotTimed();
  delay(time);

  aroundEdgeDown();
  turnEverythingOff();
  delay(time);

  randomRain();
  turnEverythingOff();
  delay(time);
}

//private functions

void turnEverythingOff() {
  for(int i = 0; i<COLUMN_NUM; i++) {
    digitalWrite(column[i], 1);
  }
  for(int i = 0; i<LAYER_NUM; i++) {
    digitalWrite(layer[i], 0);
  }
}

void turnEverythingOn() {
  for(int i = 0; i<COLUMN_NUM; i++) {
    digitalWrite(column[i], 0);
  }
  //turning on layers
  for(int i = 0; i<LAYER_NUM; i++) {
    digitalWrite(layer[i], 1);
  }
}

void flickerOn() {
  int i = 150;

  while(i != 0) {
    turnEverythingOn();
    delay(i);
    turnEverythingOff();
    delay(i);
    i-= 5;
  }
}

void turnOnAndOffAllByLayerUpAndDownNotTimed() {
  int x = 75;

  for(int i = 5; i != 0; i--) {
    turnEverythingOn();
    for(int i = LAYER_NUM; i!=0; i--) {
      digitalWrite(layer[i-1], 0);
      delay(x);
    }
    for(int i = 0; i<LAYER_NUM; i++) {
      digitalWrite(layer[i], 1);
      delay(x);
    }
    for(int i = 0; i<LAYER_NUM; i++) {
      digitalWrite(layer[i], 0);
      delay(x);
    }
    for(int i = LAYER_NUM; i!=0; i--) {
      digitalWrite(layer[i-1], 1);
      delay(x);
    }
  }
}

void aroundEdgeDown()
{
  for(int x = 200; x != 0; x -=50)
  {
    turnEverythingOff();
    for(int i = LAYER_NUM; i != 0; i--)
    {
      digitalWrite(layer[i-1], 1);
      
      digitalWrite(column[0], 0);
      delay(x);
      digitalWrite(column[0], 1);
      digitalWrite(column[4], 0);
      delay(x);
      digitalWrite(column[4], 1);
      digitalWrite(column[3], 0);
      delay(x);
      digitalWrite(column[3], 1);
      digitalWrite(column[2], 0);
      delay(x);
      digitalWrite(column[2], 1);
      digitalWrite(column[1], 0);
      delay(x);
      digitalWrite(column[1], 1);
    }
  }
}

void randomRain()
{
  turnEverythingOff();
  int x = 100;
  for(int i = 0; i!=60; i+=2)
  {
    int randomColumn = random(0,COLUMN_NUM);
    digitalWrite(column[randomColumn], 0);
    digitalWrite(layer[0], 1);
    delay(x+50);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 1);
    delay(x);
    digitalWrite(layer[1], 0);
    digitalWrite(column[randomColumn], 1);
  }
}
