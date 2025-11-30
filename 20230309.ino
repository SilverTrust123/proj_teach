
#include <SoftwareSerial.h>//HC-05

#include<Wire.h>//線

#include <Stepper.h>
#define STEPS 2048 

#include <LiquidCrystal.h> //1062A

LiquidCrystal lcd( 2, 4, 8, 12, 7, 13);

SoftwareSerial BT(5, 6); //pin10接到RXD，/pin11接到TXD

int photoresister = A0;

int buttom = 7;

char LEDstatus;

Stepper stepper(STEPS, 3, 10, 9, 11);

void setup() {
  Serial.begin(9600);//雙邊包綠

  BT.begin(9600);

  lcd.begin(16, 2);
 
 stepper.setSpeed(12);


}
void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("123") ;
  lcd.setCursor(0, 1); 
  int sensorValue = analogRead(A0); 
  lcd.print("Analog: ");
  lcd.print(sensorValue);

  Serial.println(sensorValue); 
  delay(50);    
  if (BT.available()) {
    LEDstatus = BT.read();
    Serial.println(LEDstatus);
  }


switch (LEDstatus) {
     case'a':

      stepper.step(2048);
      delay(50);
      stepper.step(0);



     

     break;//(星星重要!)

    case'b':

 
      stepper.step(-2048);
      delay(50);
      stepper.step(0);

     
    break;//(星星重要!)

    case'c':
      
     sensorValue = map(sensorValue ,0,980,0,100);//依現場環境寫參數(星星重要!)
     if( sensorValue < 50 ){

     stepper.step(2048);
     delay(50);
     stepper.step(0);

       }

     else{

     stepper.step(-2048);
     delay(50);
     stepper.step(0);

      
       break;//(星星重要!)

    }

  }
}
    
   
