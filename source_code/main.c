/*
mode - 1 : Chair
mode - 2 : Devices
mode - 3 : Voice
*/
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
boolean stringComplete=false;
String inputString="";
int n=0;
const int fan = 2;
const int light=3;
const int m1_d1 = 4;
const int m1_d2 = 5;
const int m2_d1 = 6;
const int m2_d2 = 7;
const int v1 = 8;
const int v2 = 9;
const int v3 =10;
const int v4 =11;
const int sw = 14;
const int led1 = 15;
const int led2 = 16;
const int led3 = 17;
char c;
int count = 1;
void setup()
{
pinMode(m1_d1, OUTPUT);
pinMode(m1_d2, OUTPUT);
pinMode(m2_d1, OUTPUT);
pinMode(m2_d2, OUTPUT);
pinMode(v1, OUTPUT);
pinMode(v2, OUTPUT);
pinMode(v3, OUTPUT);
pinMode(v4, OUTPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(fan,OUTPUT);
pinMode(light,OUTPUT);
pinMode(sw,INPUT_PULLUP);
digitalWrite(m1_d1, LOW);
digitalWrite(m1_d2, LOW);
digitalWrite(m2_d1, LOW);
digitalWrite(m2_d2, LOW);
digitalWrite(light,HIGH);
digitalwrite(fan,LOW);
digitalWrite(v1,HIGH);
digitalWrite(v2,HIGH);
digitalWrite(v3,HIGH);
digitalWrite(v4,HIGH);
Serial.begin(9600);
if(!accel.begin())
{
Serial.print("Mems Not Found");
}
else
{
Serial.print("Mems OK");
}
}
void loop()
{
if(digitalRead(sw)==LOW)
{
count = count+1;
if(count>3)
count = 1;
if(count == 1)
{
digitalWrite(led1,HIGH);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
}
else if(count == 2)
{
digitalWrite(led1,LOW);
digitalWrite(led2,HIGH);
digitalWrite(led3,LOW);
}
else
{
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,HIGH);
}
delay(1000); Serial.println(count);
}
sensors_event_t event;
Serial.print("Mems OK");
}
}
void loop()
{
if(digitalRead(sw)==LOW)
{
count = count+1;
if(count>3)
count = 1;
if(count == 1)
{
digitalWrite(led1,HIGH);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
}
else if(count == 2)
{
digitalWrite(led1,LOW);
digitalWrite(led2,HIGH);
digitalWrite(led3,LOW);
}
else
{
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,HIGH);
}
delay(1000); Serial.println(count);
}
sensors_event_t event;
accel.getEvent(&event);
Serial.println(event.acceleration.x);
Serial.println(event.acceleration.y);
delay(100);
if(event.acceleration.x<-3)
{
if(count == 1 )
{
Serial.println("Robot Moving Left");
digitalWrite(m1_d1, LOW);
digitalWrite(m1_d2, HIGH);
digitalWrite(m2_d1, HIGH);
digitalWrite(m2_d2, LOW);
delay(1000);
digitalWrite(m1_d1, LOW);
digitalWrite(m1_d2, LOW);
digitalWrite(m2_d1, LOW);
digitalWrite(m2_d2, LOW);
}
else if(count == 2)
{
digitalWrite(fan,LOW);
Serial.println("fanoff");
}
else
{
digitalWrite(v1,LOW);
delay(1000);
digitalWrite(v1,HIGH);
}
}
else if(event.acceleration.x>3)
{
if(count == 1)
{
Serial.println("Robot Moving Right");
digitalWrite(m1_d1, HIGH);
digitalWrite(m1_d2, LOW);
digitalWrite(m2_d1, LOW);
digitalWrite(m2_d2, HIGH);
delay(1000);
digitalWrite(m1_d1, LOW);
digitalWrite(m1_d2, LOW);
digitalWrite(m2_d1, LOW);
digitalWrite(m2_d2, LOW);
}
else if(count == 2)
{
digitalWrite(fan,HIGH);
Serial.println("fanon");
}
else
{
digitalWrite(v2,LOW);
delay(1000);
digitalWrite(v2,HIGH);
}
}
else if(event.acceleration.y>3)
{
if(count == 1)
{
Serial.println("Robot Moving Back");
digitalWrite(m1_d1, LOW);
digitalWrite(m1_d2, HIGH);
digitalWrite(m2_d1, LOW);
digitalWrite(m2_d2, HIGH);
delay(1000);
digitalWrite(m1_d1, LOW);
digitalWrite(m1_d2, LOW);
digitalWrite(m2_d1, LOW);
digitalWrite(m2_d2, LOW);
}
else if(count == 2)
{
digitalWrite(light,HIGH);
Serial.println("lightoff");
}
else
{
digitalWrite(v3,LOW);
delay(1000);
digitalWrite(v3,HIGH);
}
}
else if(event.acceleration.y<-3)
{
if(count == 1)
{
Serial.println("Robot Moving Forward");
digitalWrite(m1_d1, HIGH);
digitalWrite(m1_d2, LOW);
digitalWrite(m2_d1, HIGH);
digitalWrite(m2_d2, LOW);
delay(1000);
digitalWrite(m1_d1, LOW);
digitalWrite(m1_d2, LOW);
digitalWrite(m2_d1, LOW);
digitalWrite(m2_d2, LOW);
}
else if(count == 2)
{
digitalWrite(light,LOW);
Serial.println("lighton");
}
else
{
digitalWrite(v4,LOW);
delay(1000);
digitalWrite(v4,HIGH);
}
}
else
{
digitalWrite(m1_d1, LOW);
digitalWrite(m1_d2, LOW);
digitalWrite(m2_d1, LOW);
digitalWrite(m2_d2, LOW);
}
}
