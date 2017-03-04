/*
   arduino_motor_controller

   Controls the L298N H-bridge using serial messages from another device, such as a Raspberry Pi.

   Packet details:

   {ABCDEF}

   { : Starting packet delimiter (char)
   A, B, C, D: [char] Values to input for the L298N (1 = HIGH, 0 = LOW)
   E, F: [uint8_t] PWM values for ENA and ENB, respectively
   } : Ending packet delimiter (char)

*/

#include <SoftwareSerial.h>

#define IN1_PIN 7
#define IN2_PIN 6
#define IN3_PIN 5
#define IN4_PIN 4
#define ENA_PIN 9
#define ENB_PIN 3

char buf[10];
int ii;

const int ledPin = 13;

void setup() {
  Serial.begin(2400);

  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);

  pinMode(ENA_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);

    pinMode(ledPin, OUTPUT);
}

void loop() {

  while(Serial.available()) {

    buf[0] = Serial.read();
    if(buf[0] == '\xAA') {
        ii = 1;
        
        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13, LOW);

        while(Serial.available()) {
            buf[ii] = Serial.read();
            ii++;
        }
        
        delay(100);

        ApplyMotorControl();

    }
  }
}

void ApplyMotorControl() {

  if(buf[1] == '\x01') {
    digitalWrite(IN1_PIN, HIGH);
  }
  else if(buf[1] == '\x00') {
    digitalWrite(IN1_PIN, LOW);
  }

  if(buf[2] == '\x01') {
    digitalWrite(IN2_PIN, HIGH);
  }
  else if(buf[2] == '\x00') {
    digitalWrite(IN2_PIN, LOW);
  }

  if(buf[3] == '\x01') {
    digitalWrite(IN3_PIN, HIGH);
  }
  else if(buf[3] == '\x00') {
    digitalWrite(IN3_PIN, LOW);
  }

  if(buf[4] == '\x01') {
    digitalWrite(IN4_PIN, HIGH);
  }
  else if(buf[4] == '\x00') {
    digitalWrite(IN4_PIN, LOW);
  }

  analogWrite(ENA_PIN, buf[5]);
  analogWrite(ENB_PIN, buf[6]);
}

