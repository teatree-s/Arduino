#include <FastLED.h>
#include "MSKG.FNT.h"
#include "UTF8toSJIS.h"

#define DATA_PIN 3

#define NUM_LEDS 16
CRGBArray<NUM_LEDS> leds;

#define FONT_DATA_NUM 5
byte* ledFontData[FONT_DATA_NUM];
byte* ledFontData2[FONT_DATA_NUM];
struct CRGB ledON = 0x001000;
struct CRGB ledOFF = 0x000000;
struct CRGB ledGreen = 0x001000;

int UTF8toSJIS_NUM = sizeof(UTF8toSJIS)/sizeof(unsigned long);
byte* getFontData(unsigned long utf8){
  for(int i = 0; i < UTF8toSJIS_NUM; i++) {
    if (UTF8toSJIS[i] == utf8) {
      return &MSKG_FNT[i][0];
    }
  }
}

void setup() {
  Serial.begin(9600);

  // FastLED
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

  // Font
  ledFontData[0] = getFontData(0xefbcae); // N
  ledFontData[1] = getFontData(0xefbca5); // E
  ledFontData[2] = getFontData(0xefbcb7); // W
  ledFontData[3] = getFontData(0xe38080); // _
  ledFontData[4] = getFontData(0xe38080); // _

  ledFontData2[0] = getFontData(0xe38080); // _
  ledFontData2[1] = getFontData(0xefbcb9); // Y
  ledFontData2[2] = getFontData(0xefbca5); // E
  ledFontData2[3] = getFontData(0xefbca1); // A
  ledFontData2[4] = getFontData(0xefbcb2); // R
}

// New Year
void dispString() {
  byte* ledData;
  byte* ledData2;
  for(int j = 0; j < FONT_DATA_NUM; j++) {
    ledData = ledFontData[j];
    ledData2 = ledFontData2[j];
    for(int i = 0; i < 8; i++) {
      leds[NUM_LEDS-1-0] = (ledData[i]&(0x01)) ? ledON : ledOFF;
      leds[NUM_LEDS-1-1] = (ledData[i]&(0x02)) ? ledON : ledOFF;
      leds[NUM_LEDS-1-2] = (ledData[i]&(0x04)) ? ledON : ledOFF;
      leds[NUM_LEDS-1-3] = (ledData[i]&(0x08)) ? ledON : ledOFF;
      leds[NUM_LEDS-1-4] = (ledData[i]&(0x10)) ? ledON : ledOFF;
      leds[NUM_LEDS-1-5] = (ledData[i]&(0x20)) ? ledON : ledOFF;
      leds[NUM_LEDS-1-6] = (ledData[i]&(0x40)) ? ledON : ledOFF;
      leds[NUM_LEDS-1-7] = (ledData[i]&(0x80)) ? ledON : ledOFF;
      
      leds[NUM_LEDS-1-8] = (ledData2[i]&(0x01)) ? ledGreen : ledOFF;
      leds[NUM_LEDS-1-9] = (ledData2[i]&(0x02)) ? ledGreen : ledOFF;
      leds[NUM_LEDS-1-10] = (ledData2[i]&(0x04)) ? ledGreen : ledOFF;
      leds[NUM_LEDS-1-11] = (ledData2[i]&(0x08)) ? ledGreen : ledOFF;
      leds[NUM_LEDS-1-12] = (ledData2[i]&(0x10)) ? ledGreen : ledOFF;
      leds[NUM_LEDS-1-13] = (ledData2[i]&(0x20)) ? ledGreen : ledOFF;
      leds[NUM_LEDS-1-14] = (ledData2[i]&(0x40)) ? ledGreen : ledOFF;
      leds[NUM_LEDS-1-15] = (ledData2[i]&(0x80)) ? ledGreen : ledOFF;

      FastLED.show();
      delay(1);
    }
    delay(1);
  }
}

int ledPatternNo = 0;
int dispPattern01Count = 0;

void dispPattern01() {
  leds[0] = (0x0003<<dispPattern01Count)&0x0001 ? ledON : ledOFF;
  leds[1] = (0x0003<<dispPattern01Count)&0x0002 ? ledON : ledOFF;
  leds[2] = (0x0003<<dispPattern01Count)&0x0004 ? ledON : ledOFF;
  leds[3] = (0x0003<<dispPattern01Count)&0x0008 ? ledON : ledOFF;
  leds[4] = (0x0003<<dispPattern01Count)&0x0010 ? ledON : ledOFF;
  leds[5] = (0x0003<<dispPattern01Count)&0x0020 ? ledON : ledOFF;
  leds[6] = (0x0003<<dispPattern01Count)&0x0040 ? ledON : ledOFF;
  leds[7] = (0x0003<<dispPattern01Count)&0x0080 ? ledON : ledOFF;
  leds[8] = (0x0003<<dispPattern01Count)&0x0100 ? ledON : ledOFF;
  leds[9] = (0x0003<<dispPattern01Count)&0x0200 ? ledON : ledOFF;
  leds[10] = (0x0003<<dispPattern01Count)&0x0400 ? ledON : ledOFF;
  leds[11] = (0x0003<<dispPattern01Count)&0x0800 ? ledON : ledOFF;
  leds[12] = (0x0003<<dispPattern01Count)&0x1000 ? ledON : ledOFF;
  leds[13] = (0x0003<<dispPattern01Count)&0x2000 ? ledON : ledOFF;
  leds[14] = (0x0003<<dispPattern01Count)&0x4000 ? ledON : ledOFF;
  leds[15] = (0x0003<<dispPattern01Count)&0x8000 ? ledON : ledOFF;
  FastLED.show();
  delay(500);
  dispPattern01Count += 2;
  if (dispPattern01Count > 15) {
    dispPattern01Count = 0;
    ledPatternNo++;
  }
}

void dispPattern02() {
  leds[0] = (0x0003<<dispPattern01Count)&0x0001 ? ledON : ledOFF;
  leds[1] = (0x0003<<dispPattern01Count)&0x0002 ? ledON : ledOFF;
  leds[2] = (0x0003<<dispPattern01Count)&0x0004 ? ledON : ledOFF;
  leds[3] = (0x0003<<dispPattern01Count)&0x0008 ? ledON : ledOFF;
  leds[4] = (0x0003<<dispPattern01Count)&0x0010 ? ledON : ledOFF;
  leds[5] = (0x0003<<dispPattern01Count)&0x0020 ? ledON : ledOFF;
  leds[6] = (0x0003<<dispPattern01Count)&0x0040 ? ledON : ledOFF;
  leds[7] = (0x0003<<dispPattern01Count)&0x0080 ? ledON : ledOFF;
  leds[8] = (0x0003<<dispPattern01Count)&0x0100 ? ledON : ledOFF;
  leds[9] = (0x0003<<dispPattern01Count)&0x0200 ? ledON : ledOFF;
  leds[10] = (0x0003<<dispPattern01Count)&0x0400 ? ledON : ledOFF;
  leds[11] = (0x0003<<dispPattern01Count)&0x0800 ? ledON : ledOFF;
  FastLED.show();
  delay(500);
  dispPattern01Count += 2;
  if (dispPattern01Count > 11) {
    dispPattern01Count = 0;
    ledPatternNo++;
  }
}

void dispPattern03() {
  leds[0] = (0x0003<<dispPattern01Count)&0x0001 ? ledON : ledOFF;
  leds[1] = (0x0003<<dispPattern01Count)&0x0002 ? ledON : ledOFF;
  leds[2] = (0x0003<<dispPattern01Count)&0x0004 ? ledON : ledOFF;
  leds[3] = (0x0003<<dispPattern01Count)&0x0008 ? ledON : ledOFF;
  leds[4] = (0x0003<<dispPattern01Count)&0x0010 ? ledON : ledOFF;
  leds[5] = (0x0003<<dispPattern01Count)&0x0020 ? ledON : ledOFF;
  leds[6] = (0x0003<<dispPattern01Count)&0x0040 ? ledON : ledOFF;
  leds[7] = (0x0003<<dispPattern01Count)&0x0080 ? ledON : ledOFF;
  FastLED.show();
  delay(500);
  dispPattern01Count += 2;
  if (dispPattern01Count > 7) {
    dispPattern01Count = 0;
    ledPatternNo++;
  }
}

void dispPattern04() {
  leds[0] = (0x0003<<dispPattern01Count)&0x0001 ? ledON : ledOFF;
  leds[1] = (0x0003<<dispPattern01Count)&0x0002 ? ledON : ledOFF;
  leds[2] = (0x0003<<dispPattern01Count)&0x0004 ? ledON : ledOFF;
  leds[3] = (0x0003<<dispPattern01Count)&0x0008 ? ledON : ledOFF;
  FastLED.show();
  delay(500);
  dispPattern01Count += 2;
  if (dispPattern01Count > 3) {
    dispPattern01Count = 0;
    ledPatternNo++;
  }
}

byte led05Red = 0x00;
byte led05Green = 0x10;
void dispPattern05() {
  leds[2] = CRGB(led05Red, led05Green, 0x00);
  leds[3] = CRGB(led05Red, led05Green, 0x00);
  leds[6] = CRGB(led05Red, led05Green, 0x00);
  leds[7] = CRGB(led05Red, led05Green, 0x00);
  leds[10] = CRGB(led05Red, led05Green, 0x00);
  leds[11] = CRGB(led05Red, led05Green, 0x00);
  leds[14] = CRGB(led05Red, led05Green, 0x00);
  leds[15] = CRGB(led05Red, led05Green, 0x00);
  FastLED.show();
  delay(250);
  led05Red += 0x02;
  if (led05Green == 0x00) {
    ledPatternNo++;
    led05Red = 0x04;
    led05Green = 0x04;
  }
  else if (led05Red > 0x10) {
    led05Green-=0x02;
  }
}

void dispPattern06() {
  leds[0] = CRGB(led05Red, led05Green, 0x00);
  leds[1] = CRGB(led05Red, led05Green, 0x00);
  leds[4] = CRGB(led05Red, led05Green, 0x00);
  leds[5] = CRGB(led05Red, led05Green, 0x00);
  leds[8] = CRGB(led05Red, led05Green, 0x00);
  leds[9] = CRGB(led05Red, led05Green, 0x00);
  leds[12] = CRGB(led05Red, led05Green, 0x00);
  leds[13] = CRGB(led05Red, led05Green, 0x00);
  FastLED.show();
  delay(250);
  led05Red += 0x02;
  if (led05Green == 0x00) {
    ledPatternNo++;
    led05Red = 0x10;
    led05Green = 0x00;
    delay(2000);
  }
  else if (led05Red > 0x10) {
    led05Green-=0x02;
  }
}

void dispPattern07() {
  leds[0] = CRGB(led05Red, 0x00, led05Green);
  leds[1] = CRGB(led05Red, 0x00, led05Green);
  leds[2] = CRGB(led05Red, 0x00, led05Green);
  leds[3] = CRGB(led05Red, 0x00, led05Green);
  leds[4] = CRGB(led05Red, 0x00, led05Green);
  leds[5] = CRGB(led05Red, 0x00, led05Green);
  leds[6] = CRGB(led05Red, 0x00, led05Green);
  leds[7] = CRGB(led05Red, 0x00, led05Green);
  leds[8] = CRGB(led05Red, 0x00, led05Green);
  leds[9] = CRGB(led05Red, 0x00, led05Green);
  leds[10] = CRGB(led05Red, 0x00, led05Green);
  leds[11] = CRGB(led05Red, 0x00, led05Green);
  leds[12] = CRGB(led05Red, 0x00, led05Green);
  leds[13] = CRGB(led05Red, 0x00, led05Green);
  leds[14] = CRGB(led05Red, 0x00, led05Green);
  leds[15] = CRGB(led05Red, 0x00, led05Green);
  FastLED.show();
  delay(250);
  led05Red -= 0x02;
  led05Green += 0x02;
  if (led05Red == 0x00) {
    ledPatternNo++;
    delay(2000);
    led05Red = 0x00;
    led05Green = 0x10;
  }
}

void dispPattern08() {
  leds[0] = 0x000000;
  leds[1] = 0x000000;
  leds[2] = 0x000000;
  leds[3] = 0x000000;
  leds[4] = 0x000000;
  leds[5] = 0x000000;
  leds[6] = 0x000000;
  leds[7] = 0x000000;
  leds[8] = 0x000000;
  leds[9] = 0x000000;
  leds[10] = 0x000000;
  leds[11] = 0x000000;
  leds[12] = 0x000000;
  leds[13] = 0x000000;
  leds[14] = 0x000000;
  leds[15] = 0x000000;
  FastLED.show();
  ledPatternNo++;
}

void loop(){ 
  Serial.println("called loop()");
  if (ledPatternNo == 0) {
    delay(2000);
    ledPatternNo++;
  }
  else if (ledPatternNo == 1) {
    dispPattern01();
  }
  else if (ledPatternNo == 2) {
    dispPattern02();
  }
  else if (ledPatternNo == 3) {
    dispPattern03();
  }
  else if (ledPatternNo == 4) {
    dispPattern04();
  }
  else if (ledPatternNo == 5) {
    dispPattern05();
  }
  else if (ledPatternNo == 6) {
    dispPattern06();
  }
  else if (ledPatternNo == 7) {
    dispPattern07();
  }
  else if (ledPatternNo == 8) {
    dispPattern08();
  }
  else {
    delay(10000);
    ledPatternNo = 0;
  }
//  dispString();
}
