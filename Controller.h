#include <Servo.h>
#include "Motor.h"

class Controller{
    public:
    Motor X;
    Motor YL;
    Motor YR;
    Motor Z;
    Servo capit;

    Controller(){
    }
    
    Controller(Motor X, Motor YL,Motor YR,Motor Z){
      this->X = X;
      this->YL = YL;
      this->YR = YR;
      this->Z = Z;
    }

    // void run(){
    //   while (
    //       X.stepper.distanceToGo() != 0 ||
    //       YL.stepper.distanceToGo() != 0 ||
    //       YR.stepper.distanceToGo() != 0 ||
    //       Z.stepper.distanceToGo() != 0 
    //   ){
    //     X.stepper.run();
    //     YL.stepper.run();
    //     YR.stepper.run();
    //     Z.stepper.run();
    //   }
    // }

    // void move(int x, int y, int z){ 
    //   this->X.move(x);  
    //   this->YL.moveAsync(y);
    //   this->YR.moveAsync(y * -1);
      
    //   while (
    //       YL.stepper.distanceToGo() != 0 ||
    //       YR.stepper.distanceToGo() != 0
    //   ){
    //     YL.stepper.run();
    //     YR.stepper.run();
    //   } 
    //   this->Z.move(z);
       
    //   this->print();
    // }

    void moveX(long int step){ 
      // this->X.move(x); 
      if(step < 0)
        digitalWrite(this->X.dir, HIGH);
      else
        digitalWrite(this->X.dir, LOW);

      for(long int i = 0; i < abs(step); i++){
        digitalWrite(this->X.pul, HIGH);
        delayMicroseconds(60);
        digitalWrite(this->X.pul, LOW);
        delayMicroseconds(60);
      } 
    }

    void moveY(long int step){ 
      // this->YL.moveAsync(y);
      // this->YR.moveAsync(y * -1);
      
      // while (
      //     YL.stepper.distanceToGo() != 0 ||
      //     YR.stepper.distanceToGo() != 0
      // ){
      //   YL.stepper.run();
      //   YR.stepper.run();
      // }   
      if(step < 0){
        digitalWrite(this->YL.dir, HIGH);
        digitalWrite(this->YR.dir, LOW);
      }
      else{
        digitalWrite(this->YL.dir, LOW);
        digitalWrite(this->YR.dir, HIGH);
      }

      for(long int i = 0; i < abs(step); i++){
        digitalWrite(this->YL.pul, HIGH);
        digitalWrite(this->YR.pul, HIGH);
        delayMicroseconds(60);
        digitalWrite(this->YL.pul, LOW);
        digitalWrite(this->YR.pul, LOW);
        delayMicroseconds(60);
      } 
    }
    
    void moveZ(long int step){ 
      // this->Z.move(z);  
      if(step < 0)
        digitalWrite(this->Z.dir, HIGH);
      else
        digitalWrite(this->Z.dir, LOW);

      for(long int i = 0; i < abs(step); i++){
        digitalWrite(this->Z.pul, HIGH);
        delayMicroseconds(60);
        digitalWrite(this->Z.pul, LOW);
        delayMicroseconds(60);
      } 
    }
    
    void print(){
      // Serial.print("X:");
      // Serial.print(X.getCurrentPosition());
      // Serial.print(" YL:");
      // Serial.print(YL.getCurrentPosition());
      // Serial.print(" YR:");
      // Serial.print(YR.getCurrentPosition());
      // Serial.print(" Z:");
      // Serial.println(Z.getCurrentPosition());
    }
};
