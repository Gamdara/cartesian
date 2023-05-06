#include "Header.h"
#include "Controller.h"

Controller robot{
  Motor(11,4), //X
  Motor(7,6), //YL
  Motor(9,8), //YR
  Motor(13,12)  //Z
};

void setup()
{  
  Serial.begin(9600);
  Serial.println("mulai");
  Serial.println("Inisialisasi...");
//inisiasi semua motor, defaultnya speed 50, accel 20
  
  robot.X.init();
  robot.YL.init();
  robot.YR.init();
  robot.Z.init();
  robot.capit.attach(5);
  delay(200);
  // robot.capit.write(0);
  // robot.capit.write(115);
  
  Serial.println("Inisialisasi Selesai...");
}

void loop()
{ 
    robot.moveZ(45000);
    robot.capit.write(120);
    robot.moveZ(-45000);
    robot.moveY(-20000);
    robot.moveZ(45000);
    robot.capit.write(0);
    robot.moveZ(-45000);
    robot.moveY(20000);
    delay(10000);
    // jalan();
    // Serial.println(robot.Z.getCurrentPosition());
}

void jalan(){
  if (Serial.available() > 0) {
    long int x,y,z,g;
    String a;

    a = Serial.readString();
    x = getValue(a,';',0).toInt();
    y = getValue(a,';',1).toInt();
    z = getValue(a,';',2).toInt();
    g = getValue(a,';',3).toInt();
    
    
    Serial.print("X : ");
    Serial.println(x);
    Serial.print("Y : ");
    Serial.println(y);
    Serial.print("Z : ");
    Serial.println(z);
    Serial.print("G : ");
    Serial.println(g);
    
    
    // robot.move(x,y,z);bisa jjuga
    robot.moveX(x);
    robot.moveY(y);
    robot.moveZ(z);
    if(g == 0)
      robot.capit.write(0);
    else
      robot.capit.write(120);
    
    delay(200);
  }
}