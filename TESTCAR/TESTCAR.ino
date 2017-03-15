#include <AFMotor.h>
// right is zero
// left is pi
// pin 3 read if straight: 1
// pin 5 read left(0) or right(1)
AF_DCMotor motor3(3); //left
AF_DCMotor motor4(4); //right

int angle; //right 0; left 180

void setup(){
Serial.begin(9600);
  motor4.setSpeed(170); //left
  motor3.setSpeed(130); //right
 pinMode(7,OUTPUT);
  pinMode(5,INPUT);
 attachInterrupt(1,straight,RISING);
}

void loop(){  


 angle = digitalRead(5);
  Serial.println("angle");
  
  if (angle == 0){
    Serial.println(angle );

 motor4.setSpeed(170);
    motor4.run(BACKWARD);
    delay(300);
    motor4.run(RELEASE);
    delay(300);
        motor4.run(BACKWARD);
    delay(300);
    motor4.run(RELEASE);
    delay(4000);
    
   
  // digitalWrite(7,HIGH);
  }
  
 else { // the object is right,  right stop, left moves
    Serial.println(angle);
 
    motor3.run(BACKWARD);
    delay(120);
    motor3.run(RELEASE);
   delay(300);
     motor3.run(BACKWARD);
    delay(120);
    motor3.run(RELEASE);
   delay(5000);
   // digitalWrite(7,HIGH);
  }
  


}
void straight () {
  
  Serial.println("S");
  //motor3.setSpeed(40);
  //motor4.setSpeed(44); //left
; 
  motor3.run(BACKWARD);
 delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
  motor4.run(BACKWARD);

 delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
  motor4.run(RELEASE);
  delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
delayMicroseconds(16383); 
  motor3.run(RELEASE);

}

