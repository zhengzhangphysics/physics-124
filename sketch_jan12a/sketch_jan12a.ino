const int SERVO = 5;
char ch; // for interactive serial control
int level = 23; // 23 is 1.5 ms; 14 is 0.9; 33 is 2.1
void setup()
{
pinMode(SERVO, OUTPUT); // set servo pin for output Serial.begin(9600);
TCCR0B = TCCR0B & 0b11111000 | 0x05; // for 61 Hz analogWrite(SERVO, level); // start centered
}

void loop() {
if (Serial.available()){ // check if incoming serial data
ch = Serial.read(); // read single character
if (ch >='0' && ch <='9'){ // use 10 step range for demo
      level = map(ch-'0',0,9,14,33);    // map 0-9 onto 14-33
      analogWrite(SERVO, level);        // send to servo
      Serial.print("Setting servo level to: ");
      Serial.println(level);
}
}
delay(20); // interactive program, so slow 
}
