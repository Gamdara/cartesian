#include "Arduino.h"
#define DEFAULT_SPEED 50
#define DEFAULT_ACCEL 20

class Motor{
  public:
    // AccelStepper stepper;
    int pul;
    int dir;

    Motor(){
    }
    
    Motor(int pul, int dir){
      this->pul = pul;
      this->dir = dir;
    }

    // void init(int speed = DEFAULT_SPEED, int accel = DEFAULT_ACCEL){
    //   stepper.setSpeed(speed);
    //   stepper.setAcceleration(accel);
    // }

    void init(){
      pinMode(this->pul, OUTPUT);
      pinMode(this->dir, OUTPUT);
    }

    // void move(int step){
    //   if(step < 0)
    //     digitalWrite(this->dir, HIGH);
    //   else
    //     digitalWrite(this->dir, LOW);

    //   for(int i = 0; i < step; i++){
    //     digitalWrite(13, HIGH);
    //     delayMicroseconds(60);
    //     digitalWrite(13, LOW);
    //     delayMicroseconds(60);
    //   }
    // }

    // void moveAsync(int step){
    //   stepper.moveTo(step);
    // }

    // int getCurrentPosition(){
    //   return stepper.currentPosition();
    // }
};
