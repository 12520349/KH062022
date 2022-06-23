#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "BTS7960.h"


#define MIN_PULSE_WIDTH 650
#define MAX_PULSE_WIDTH 2350
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50

uint8_t servonum = 0;


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
int R_PWM = 5;
int L_PWM = 6;
// timer 0
int L_EN = 7;
int R_EN = 8;

BTS7960 motorController(L_EN, R_EN, L_PWM, R_PWM);

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);

}

int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  Serial.println(analog_value);
  return analog_value;
}

void loop() {
  if (Serial.available() > 0) {
    String stringOne = Serial.readString(); // read the incoming data as string
    String name_motor = stringOne.substring(0, 1);
    if (name_motor == "A") {
      Serial.println("Chay motor");
      chay_motor();
      name_motor = "000";
    }
    if (name_motor == "B") {
      Serial.println("Chay servo");
      chay_servo();
      name_motor = "000";
    }
    if (name_motor == "C") {
      Serial.println("Chay servo");
      chay_servo();
      delay(500);
      Serial.println("Chay motor");
      chay_motor();
      name_motor = "000";
    }
  }
}
void chay_servo() {
  pwm.setPWM(0, 0, pulseWidth(0));
  delay(2000);
  pwm.setPWM(0, 0, pulseWidth(130));
  delay(1000);
}
void chay_motor() {
  motorController.Enable();
  int speed = 255;
  for (int j = 0; j < 5; j++) {
    motorController.TurnLeft(speed);
    delay(100);
  }

  motorController.Stop();
}
