#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
 
int trigPin=9; 
int echoPin=7;  
int myCounter=0;   
float pingTime;  
float targetDistance; 
float speedOfSound=776.5; 
 
void setup() {
 
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
lcd.begin(16,2,LCD_5x10DOTS);
lcd.setCursor(0,0);  
lcd.print("Distanta:");  
}
 
void loop() {
 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2000); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(15); 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(10); 
 
  pingTime = pulseIn(echoPin, HIGH);  
  pingTime=pingTime/1000000; 
  pingTime=pingTime/3600; 
  targetDistance= speedOfSound * pingTime;   
  targetDistance=targetDistance/2; 
  targetDistance= targetDistance*160934,4;    
 
 
 
  lcd.setCursor(0,1);  
  lcd.print("                "); 
  lcd.setCursor(0,1);   
  lcd.print(targetDistance); 
  lcd.print(" cm");  
  delay(250); 
 
}
