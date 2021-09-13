#include <TimerOne.h>           // библиотека таймера
#include <OneWire.h>            // библиотека протокола датчиков
#include <Wire.h>               // библиотека для соединения

#define B 3950 // B-коэффициент
#define SERIAL_R 102000 
#define THERMISTOR_R 100000 
#define NOMINAL_T 25 

const byte tempPin = A7;

#define FAN_PIN 2

void setup() {
    Serial.begin( 9600 );
    Timer1.initialize(40);   // поставить частоту ШИМ 25 кГц (40 микросекунд)
    pinMode(FAN_PIN, OUTPUT);
    pinMode( tempPin, INPUT );
    Timer1.pwm(FAN_PIN, 400);  // включить вентиляторы на 40%
    delay(2000); 
}

void loop(){ 
    int t = analogRead( tempPin );
    float tr = 1023.0 / t - 1;
    tr = SERIAL_R / tr;
    float steinhart;
    steinhart = tr / THERMISTOR_R;
    steinhart = log(steinhart); 
    steinhart /= B; 
    steinhart += 1.0 / (NOMINAL_T + 273.15);
    steinhart = 1.0 / steinhart;
    steinhart -= 273.15;
    Serial.print("t=");   
    Serial.print(steinhart);
    delay(2000);
    int temp = steinhart;  // получаем температуру
/*
if(temp < 30 )
    { 
      analogWrite(pwm,0);
      Serial.print(" Fan OFF\n");
      delay(100);
    }
    else if(temp>=30 && temp<=40)
    {
      analogWrite(pwm, 51);
      Serial.print(" Fan Speed: 20%\n");
      delay(100);
    } 
     else if(temp>=40 && temp<=50)
    {
      analogWrite(pwm, 102);
      Serial.print(" Fan Speed: 40%\n");
      delay(100);
    }
     else if(temp>=50 && temp<=60)
    {
      analogWrite(pwm, 153);
      Serial.print(" Fan Speed: 60%\n"); 
      delay(100);
    }    
    else if(temp>=60 && temp<=80)
    {
      analogWrite(pwm, 204);
      Serial.print(" Fan Speed: 80%\n");
      delay(100);
    }
     else if(temp>80)
    {
      analogWrite(pwm, 255);
      Serial.print(" Fan Speed: 100%\n");
      delay(100);
    } 
  delay(3000);
}*/



if(temp < 30 )
    { 
      Timer1.pwm(FAN_PIN, 0);
      Serial.print(" Fan OFF\n");
      delay(100);
    }
    else if(temp>=30 && temp<=40)
    {
      Timer1.pwm(FAN_PIN, 200);
      Serial.print(" Fan Speed: 20%\n");
      delay(100);
    } 
     else if(temp>=40 && temp<=50)
    {
      Timer1.pwm(FAN_PIN, 400);
      Serial.print(" Fan Speed: 40%\n");
      delay(100);
    }
     else if(temp>=50 && temp<=60)
    {
      Timer1.pwm(FAN_PIN, 600);
      Serial.print(" Fan Speed: 60%\n"); 
      delay(100);
    }    
    else if(temp>=60 && temp<=80)
    {
      Timer1.pwm(FAN_PIN, 800);
      Serial.print(" Fan Speed: 80%\n");
      delay(100);
    }
     else if(temp>80)
    {
      Timer1.pwm(FAN_PIN, 1000);
      Serial.print("Fan Speed: 100%\n");
      delay(100);
    } 
  delay(3000);
}
