#include<Adafruit_LiquidCrystal.h>

#define trigger 9
#define echo 8

Adafruit_LiquidCrystal lcd(12,11,5,4,3,2);

float time = 0,
distance = 0;
const int pingPin = 9;
const int echoPin = 8;
const int buzzerPin = 13;

void setup()
{
  Serial.begin(9600);
  pinmode(buzzerPin, OUTPUT);
  lcd.begin(16,2);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  lcd.print("Ultra sonic");
  lcd.setCursor(0,1);
  lcd.print("Distance Meter");
  delay(2000);
  lcd.clear();
}

void loop()
{
  long duration;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  while(duration<6000){
    Serial.println(duration);
    int i = duration/20l
    digitalWrite(buzzerPin, HIGH);
    delay(i/2);
    digitalWrite(buzzerPin, LOW);
    delay(i);
    break;
  }
  lcd.clear();
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  time = pulseIn(echo, HIGH);
  distance = time*340/20000;
  lcd.clear();
  lcd.print("Distance");
  lcd.print(distance);
  lcd.print("cm");
  lcd.setCursor(0, 1);
  lcd.print("Distance:");
  lcd.print(distance/100);
  lcd.print("m");
  delay(1000);
}