#include <Servo.h>
#include<LiquidCrystal.h>

Servo hitec;   // instantiate a servo
int deg;   // where is servo (in degrees)
int minDistance;// count how many objects are found
int minDeg;
int curDistance;
int sig;

//pin 2: straight interrupt 
//pin3: direction
void setup(){

 // attach the servo input pin to pin 11
 hitec.attach(11,650,2281);   

 // set up the laser
 pinMode (2, OUTPUT);

 
 // set up  the ultrasonic sensors
  pinMode(7,INPUT);
  pinMode(12,OUTPUT);



  Serial.begin(9600);
// INDICATES THE CAR FINISHE ONE SINGLE ADJUSTMENT

 }
  
 void loop(){

//digitalWrite(2,LOW);
// turn the laser on 
// will be replaced by an interrupt

// lcd.setCursor(0,1);
 
 minDistance = 9000;
// spin the servo by 5 degrees
for ( deg =0; deg<= 180; deg = deg+5)
{
  
  digitalWrite(12,HIGH);
  delayMicroseconds(10);
  digitalWrite(12,LOW);
  curDistance = pulseIn(7,HIGH);


  if (minDistance >= curDistance){
  minDistance = curDistance;
  minDeg = deg;
 // delay(150);
  }


    hitec.write(deg);
    //delay(50);    

} 
   

delay(500);
hitec.write(minDeg);
digitalWrite(2,HIGH);
delay(900);
/*lcd.setCursor(0,1);
lcd.print("@");
lcd.print(minDeg);
lcd.print(" , ");
lcd.print(minDistance*0.034/2);
lcd.print("cm");
*/
/*if(minDeg > 95) { // ob is left
  digitalWrite(3,0);
}
else if(minDeg < 85) { // ob is right
  digitalWrite(3,1);
}
else {
  digitalWrite(2,1);
}
// DELAY 5 SECOND
delay(3000);
/*while(digitalRead(7) == 1) {
  if(minDeg < 85) {
    minDeg = minDeg +1;
   hitec.write(minDeg); 
  }
   else if(minDeg > 95) {
    minDeg = minDeg -1;
   hitec.write(minDeg); 
  }*/
//
Serial.print(minDeg);
//digitalWrite(7,LOW);
digitalWrite(2,LOW);
/*lcd.setCursor(0,1);
lcd.print("                ");
*/
 }
 
