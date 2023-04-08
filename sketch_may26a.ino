#include <Servo.h>
#include "Ultrasonic.h"

Servo Ele_neck;

int pos = 90;
int Neck_Speed = 30;
int trigPin = 5;      // trig pin of HC-SR04
int echoPin = 6;     // Echo pin of HC-SR04

int Thou = 1000;
int Hun = 500;
int Five = 2000;
int L_Motor = 13;
int R_Motor =12;





void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // Setting baud rate to 9600. The serial port can transfer a maximum of 9600 bits per second
Ele_neck.attach(9);
pinMode(L_Motor,OUTPUT);
pinMode(R_Motor,OUTPUT);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT); //set echo pin as input to capture reflected
}

void loop() {
 digitalWrite(L_Motor, HIGH);
 digitalWrite(R_Motor, HIGH);
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH);     // send waves for 10 us
delayMicroseconds(10); 
int distance = pulseIn(echoPin, HIGH);
distance = distance / 74 / 2;
Serial.println(distance);

 digitalWrite(L_Motor, HIGH);
 digitalWrite(R_Motor, HIGH);
 
if(distance > 20){Ele_neck.write(90); }     
if(pos=90 &&  distance < 16 && distance > 13){Ele_neck.write(160);}
if(pos=160 && distance <=13){Ele_neck.write(20); }

  
if(pos=90 &&  distance < 16 && distance > 13){digitalWrite(L_Motor,LOW);
                                             digitalWrite(R_Motor, HIGH);
                                                            delay(500);}
if(pos=160 && distance <=13){digitalWrite(L_Motor,HIGH);
                             digitalWrite(R_Motor, LOW);
                                            delay(500);}

}                        
