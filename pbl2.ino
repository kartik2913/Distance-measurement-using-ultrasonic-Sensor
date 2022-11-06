#include "NewPing.h"
#include <LiquidCrystal_I2C.h> //liquid crystal with I2C library

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

char array1[] = "What Up?!     "; //an array to print on line 0
char array2[] = "PBL-2"; //an array to print on line 1

int trigPin = 9;    // TRIG pin
int echoPin = 8;    // ECHO pin

NewPing sonar(trigPin, echoPin);
int iterations = 10;

float duration_us, distance_cm;

void setup()
{
  
  lcd.init();                      // initialize the lcd
  lcd.backlight(); //Turn on backlight
  pinMode(trigPin, OUTPUT); // config trigger pin to output mode
  pinMode(echoPin, INPUT);  // config echo pin to input mode
  lcd.setCursor(4, 0); //set cursor at top left
  lcd.print(array1);//will only print the first letter of the array
  delay(1000);
  lcd.setCursor(5, 1);
  lcd.print(array2);
  delay(1000);
  lcd.clear();
}


void loop()
{
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // measure duration of pulse from ECHO pin
  duration_us = sonar.ping_median(iterations);

  distance_cm = 0.017 * duration_us;
  
   //Clears the LCD screen and positions the cursor in the upper-left corner.
  lcd.setCursor(0, 0); // start to print at the first row
  lcd.print("Distance: ");
  lcd.setCursor(0, 1);
  lcd.print(distance_cm);
  lcd.setCursor(7, 1);
  lcd.print("cm");
}
