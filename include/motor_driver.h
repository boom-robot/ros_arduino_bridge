#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#define LEFT_MOTOR_FORWARD 4
#define LEFT_MOTOR_BACKWARD 5

#define RIGHT_MOTOR_FORWARD 6
#define RIGHT_MOTOR_BACKWARD 7

#include <Arduino.h>

#include "commands.h"

void setMotorSpeed(int i, int spd) {
  unsigned char reverse = 0;

  if (spd < 0) {
    spd = -spd;
    reverse = 1;
  }
  if (spd > 255) spd = 255;

  if (i == LEFT) {
    if (reverse == 0) {
      analogWrite(LEFT_MOTOR_FORWARD, spd);
      analogWrite(LEFT_MOTOR_BACKWARD, 0);
    } else if (reverse == 1) {
      analogWrite(LEFT_MOTOR_BACKWARD, spd);
      analogWrite(LEFT_MOTOR_FORWARD, 0);
    }
  } else /*if (i == RIGHT) //no need for condition*/ {
    if (reverse == 0) {
      analogWrite(RIGHT_MOTOR_FORWARD, spd);
      analogWrite(RIGHT_MOTOR_BACKWARD, 0);
    } else if (reverse == 1) {
      analogWrite(RIGHT_MOTOR_BACKWARD, spd);
      analogWrite(RIGHT_MOTOR_FORWARD, 0);
    }
  }
}

void setMotorSpeeds(int leftSpeed, int rightSpeed) {
  setMotorSpeed(LEFT, leftSpeed);
  setMotorSpeed(RIGHT, rightSpeed);
}

#endif  // MOTOR_DRIVER_H