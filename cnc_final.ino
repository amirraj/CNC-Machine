// Include the Arduino Stepper Library
#include <Stepper.h>
#include <Servo.h> 
#include<Wire.h>
#include<LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd (0x27,2,1,0,4,5,6,7,3, POSITIVE); 
// Create a servo object 
Servo Servo1; 
// Number of steps per output rotation++++++++++++++
const int stepsPerRevolution = 1000;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution,  8,9,10, 11);
Stepper my(stepsPerRevolution,  4,5,6,7);
void setup() {
  // put your setup code here, to run once:
  Servo1.attach(3);
  myStepper.setSpeed(40);
  my.setSpeed(40);

  //initiate lcd
  lcd.begin(16,2);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
     
      if(Serial.available())
  {
     delay(100);
     
     while(Serial.available())
     {
      lcd.clear();
    lcd.write("give input");
        char s = Serial.read();
        lcd.write(s);
        Serial.println(s);
        if(isAlpha(s))
        {
         lcd.clear();
        lcd.write("Got ");
        lcd.write(s);
        delay(3000);
            if(s == 'a')
        {
          lcd.clear();
          lcd.write("Printing A");
          printA();  
          lcd.clear();
        lcd.write("Printing Done");
        delay(3000);
        }
        else
        {
          lcd.clear();
          lcd.write("Sorry");
        delay(3000);
          }
          
          }
        
      }
    }
}

void printA()
{
  Serial.println("Staring from servo");
      Servo1.write(40); 
      delay(500);
      Servo1.write(52); 
      delay(500);
      Serial.println(" A er Vertical Line ");
      myStepper.step(stepsPerRevolution);
      myStepper.step(stepsPerRevolution);
      myStepper.step(stepsPerRevolution);
      myStepper.step(stepsPerRevolution);
      myStepper.step(stepsPerRevolution);
      myStepper.step(stepsPerRevolution);
      delay(500);
      Serial.println("A er horizontal Line");
      my.step(stepsPerRevolution);
      my.step(stepsPerRevolution);
      my.step(stepsPerRevolution);
      delay(500);
        Serial.println("Reverse Vertical Line ");
        myStepper.step(-stepsPerRevolution);
        myStepper.step(-stepsPerRevolution);
        myStepper.step(-stepsPerRevolution);
        myStepper.step(-stepsPerRevolution);
        myStepper.step(-stepsPerRevolution);
        myStepper.step(-stepsPerRevolution);
        Serial.println("Servo Up");
        Servo1.write(40); 
        delay(1000);
        Serial.println("Then going back for mid Line ");
        myStepper.step(stepsPerRevolution);
        myStepper.step(stepsPerRevolution);
        myStepper.step(stepsPerRevolution);
        Serial.println("Pen Down for mid Line");
        Servo1.write(52); 
        delay(500);
        Serial.println("Starting the Mid Line");
        my.step(-stepsPerRevolution);
        my.step(-stepsPerRevolution);
        my.step(-stepsPerRevolution);
        Serial.println("Finished the Mid Line");
        Servo1.write(40); 
        Serial.println("Job Done");
        delay(500);
       
 }
