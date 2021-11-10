    /////////////////////////////////////////////////////////////////
   //             Arduino Breathalyzer Project             v1.01  //
  //       Get the latest version of the code here:              //
 //      http://educ8s.tv/arduino-breathalyzer-project          //
/////////////////////////////////////////////////////////////////

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
int TIME_UNTIL_WARMUP = 900;
unsigned long time;


int analogPin = 0;
int val = 0;
Adafruit_SSD1306 display(OLED_RESET);


void setup()   {                

 Serial.begin(9600);
 Serial.println("Starting...");
}


void loop() {  
  
  val = readAlcohol();
  printAlcoholVal(val);
  printAlcoholLevel(val);  
  
//  printTitle();
//  printWarming();

//  time = millis()/1000;
//  
//  if(time<=TIME_UNTIL_WARMUP)
//  {
//    time = map(time, 0, TIME_UNTIL_WARMUP, 0, 100);
//    display.drawRect(10, 50, 110, 10, WHITE); //Empty Bar
//    display.fillRect(10, 50, time,10,WHITE);
//  }else
//  {
////     printTitle();
////     printAlcohol(val);
//     
//  }
//  display.display();

delay(500);

}


void printTitle()
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(22,0);
  display.println("Breath Analyzer");
}

void printWarming()
{
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,20);
  display.println("Warming up");
}

void printAlcohol(int value)
{
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(45,25);
  display.println(val);
}

void printAlcoholVal(int value)
{
  Serial.print("Your alcohol level: ");
  Serial.println(value);
}

void printAlcoholLevel(int value)
{
  if(value<200)
  {
      Serial.println("You are sober.");
  }
  else if (value>=200 && value<280)
  {
      Serial.println("You had a beer.");
  }
  else if (value>=280 && value<350)
  {
      Serial.println("Two or more beers.");
  }
  else if (value>=350 && value <450)
  {
      Serial.println("I smell Oyzo!");
  }
  else if(value>450)
  {
     Serial.println("You are drunk!");
  }
 }
 
 int readAlcohol()
 {
  int val = 0;
  int val1;
  int val2;
  int val3; 

  val1 = analogRead(analogPin); 
  delay(10);
  val2 = analogRead(analogPin); 
  delay(10);
  val3 = analogRead(analogPin);
  
  val = (val1+val2+val3)/3;
  return val;
 }
