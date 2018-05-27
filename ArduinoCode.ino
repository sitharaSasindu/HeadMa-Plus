#include <SoftwareSerial.h> // use the software uart
SoftwareSerial bluetooth(2, 4); // RX, TX

#define motor1 3
#define motor2 5
#define motor3 6
#define motor4 9
#define motor5 10
#define motor6 11

void setup() { 
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(motor5, OUTPUT);
  pinMode(motor6, OUTPUT);
  bluetooth.begin(115200); // start the bluetooth uart at 9600 which is its default
  Serial.begin(9600);
  delay(200); // wait for voltage stabilize
  bluetooth.print("AT+UART"); // place your name in here to configure the bluetooth name.
                                       // will require reboot for settings to take affect. 
  delay(3000); // wait for settings to take affect. 
}

void loop() {
  if (bluetooth.available()) { // check if anything in UART buffer
    
    char val = bluetooth.read();
    Serial.println(val);
    if(val == '1'){ // did we receive this character?
       pattern1();
    }else if(val == '2'){
      pattern2();
    }else if(val == '3'){
      pattern3();
    }
    else if(val == '4'){
      pattern4();
    }
    else if(val == '5'){
      pattern5();
    }
    else if(val == '6'){
      patternOff();
  }
}
}

void pattern1(){
  analogWrite(motor1, 50);
  analogWrite(motor2, 50);
  analogWrite(motor3, 50);
  analogWrite(motor4, 50);
  analogWrite(motor5, 50);
  analogWrite(motor6, 50);
}

void pattern2(){
  analogWrite(motor1, 20);
  analogWrite(motor2, 20);
  analogWrite(motor3, 20);
  analogWrite(motor4, 20);
  analogWrite(motor5, 20);
  analogWrite(motor6, 20);
}

void pattern3(){
  for(int i=5; i<100; i++){
  analogWrite(motor1, 100);
  analogWrite(motor2, 100);
  analogWrite(motor3, 100);
  analogWrite(motor4, 100);
  analogWrite(motor5, 100);
  analogWrite(motor6, 100);

  }}


void pattern4 (){
  for(int x = 5; x < 150; x++){
  analogWrite(motor1, x);
  delay(10);
  analogWrite(motor2, x);
  analogWrite(motor3, x);
  delay(10);
  analogWrite(motor4, x);
  analogWrite(motor5, x);
  delay(10);
  analogWrite(motor6, x);
  }
}

void pattern5(){
  int x=10;
  analogWrite(motor1, x);
  analogWrite(motor2, x);
  analogWrite(motor3, x);
  analogWrite(motor4, x);
  analogWrite(motor5, x);
  analogWrite(motor6, x);
  
}

void patternOff(){
  analogWrite(motor1, 0);
  analogWrite(motor2, 0);
  analogWrite(motor3, 0);
  analogWrite(motor4, 0);
  analogWrite(motor5, 0);
  analogWrite(motor6, 0);
}
