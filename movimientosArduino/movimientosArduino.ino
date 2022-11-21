
#include <Braccio.h>
#include <Servo.h>

int M1=0;
int M2=0;
int M3=0;
int M4=0;

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

void setup() {

  Braccio.begin();
  
  Serial.begin(9600);
}

void loop() {
 
  while (Serial.available()==0);
   if (Serial.available()>0){
    M1 = Serial.readStringUntil(',').toInt();
    M2 = Serial.readStringUntil(',').toInt();
    M3 = Serial.readStringUntil(',').toInt();
    M4   = Serial.readString().toInt();

    M1=restriccion(M1);
    M2=restriccion(M2);
    M3=restriccion(M3);
    M4=restriccion(M4);
 
    Braccio.ServoMovement(20,M1,M2,M3,M4,0,0);  
   delay(1000);
   Serial.println("Correcto"); 
   }

}
int restriccion(int grados){
  if(grados<0){
    grados= grados*-1;
  }
  else if (grados >180){
    grados = grados-180;
  }
  return grados;
}
