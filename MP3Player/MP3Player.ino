/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x64 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <Adafruit_SSD1306.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS \
  0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES 10  // Number of snowflakes in the animation example

// DF Player Mini
const int DfSoftwareRx = 2;
const int DfSoftwareTx = 3;

SoftwareSerial dfSoftwareSerial(DfSoftwareTx, DfSoftwareRx);
DFRobotDFPlayerMini dfDFPlayer;

char bufStatus[5];
char bufVolume[5];
char bufEQ[5];
char bufFolderCounts[5];
char bufFileCounts[5];
char bufCurrentFileNumber[5];

const int button1Pin = 5;
const int button2Pin = 6; 
int button1State = 0;
int button2State = 0;

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
//  delay(10000);  // Pause for 10 seconds

  // Clear the buffer
  display.clearDisplay();
  display.setRotation(2);
  display.setTextSize(1);               // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);  // Draw white text
  display.cp437(true);  // Use full 256 char 'Code Page 437' font

  // display.display() is NOT necessary after every single drawing command,
  // unless that's what you want...rather, you can batch up a bunch of
  // drawing operations and then update the screen all at once by calling
  // display.display(). These examples demonstrate both approaches...

//  testdrawchar();  // Draw characters of the default font
//  delay(2000);
//  delay(10000);    // Pause for 10 seconds

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  dfSoftwareSerial.begin(9600);
  if (!dfDFPlayer.begin(dfSoftwareSerial)) {
    // Ignore errors
  }
  delay(2000);

  dfDFPlayer.waitAvailable(2000);
//  dfDFPlayer.stop();
  dfDFPlayer.volume(10);  // 0 - 30
  dfDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  dfDFPlayer.enableLoopAll();
  delay(100);

  itoa(dfDFPlayer.readVolume(), bufVolume, 10);
  itoa(dfDFPlayer.readEQ(), bufEQ, 10);
  itoa(dfDFPlayer.readFolderCounts(), bufFolderCounts, 10);
  itoa(dfDFPlayer.readFileCounts(), bufFileCounts, 10);
  delay(100);

    dfDFPlayer.start();
//    dfDFPlayer.play(2);
//    dfDFPlayer.stop();

  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  
  Serial.println("Initializing Done");
}

void loop() {
  Serial.println("loop()");
  delay(200);  // Pause for 1 seconds

  int line = 0, h = 8;
  display.clearDisplay();

  display.setCursor(0, h*line++);
  display.write("## DF Player Mini ##");
  display.setCursor(0, h*line++);
  display.write("--------------------");
  
  display.setCursor(0, h*line++);
  display.write("State  :");
  itoa(dfDFPlayer.readState(), bufStatus, 10);
  display.write(bufStatus);

  display.setCursor(0, h*line++);
  display.write("Volume :");
  display.write(bufVolume);

//  display.setCursor(0, h*line++);
//  display.write("EQ     :");
//  display.write(bufEQ);
//
//   display.setCursor(0, h*line++);
//   display.write("FolderCounts    :");
//   display.write(bufFolderCounts);
//
//   display.setCursor(0, h*line++);
//   display.write("FileCounts      :");
//   display.write(bufFileCounts);
//
//   display.setCursor(0, h*line++);
//   display.write("Play FileNumber :");
//   itoa(dfDFPlayer.readCurrentFileNumber(), bufCurrentFileNumber, 10);
//   display.write(bufCurrentFileNumber);

  display.display();

  button1State = !digitalRead(button1Pin);
  button2State = !digitalRead(button2Pin);
  if(button1State==HIGH) {
    Serial.println("Push Button1");
    // dfDFPlayer.next();
    dfDFPlayer.volumeUp();
  }
  else if(button2State==HIGH) {
    Serial.println("Push Button2");
    // dfDFPlayer.previous();
    dfDFPlayer.volumeDown();
  }
}

void testdrawchar(void) {
  display.clearDisplay();

  display.setTextSize(1);               // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);  // Draw white text
  display.setCursor(0, 0);              // Start at top-left corner
  display.cp437(true);  // Use full 256 char 'Code Page 437' font

  // Not all the characters will fit on the display. This is normal.
  // Library will draw what it can and the rest will be clipped.
  for (int16_t i = 0; i < 256; i++) {
    if (i == '\n')
      display.write(' ');
    else
      display.write(i);
  }

  display.display();
}
