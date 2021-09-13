#define B 3950 // B-коэффициент
#define SERIAL_R 102000 // сопротивление последовательного резистора, 102 кОм
#define THERMISTOR_R 100000 // номинальное сопротивления термистора, 100 кОм
#define NOMINAL_T 25 // номинальная температура (при которой TR = 100 кОм)
#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 9
#include <TimerOne.h>
#include <OneWire.h>
#define FADESPEED 5     // чем выше число, тем медленнее будет fade-эффект

const byte tempPin = A7;

#define FAN_PIN 2

void setup() {
    Serial.begin( 9600 );
    Timer1.initialize(40);   // поставить частоту ШИМ 25 кГц (40 микросекунд)
    pinMode(FAN_PIN, OUTPUT);
    pinMode( tempPin, INPUT );
    Timer1.pwm(FAN_PIN, 400);  // включить вентиляторы на 40%
    pinMode(REDPIN, OUTPUT);
    pinMode(GREENPIN, OUTPUT);
    pinMode(BLUEPIN, OUTPUT);
    delay(2000); 
}

void loop() {
    int r, g, b;
    int t = analogRead( tempPin );
    float tr = 1023.0 / t - 1;
    tr = SERIAL_R / tr;
    //Serial.print("R=");
    //Serial.print(tr);
    Serial.print("t=");

    float steinhart;
    steinhart = tr / THERMISTOR_R; // (R/Ro)
    steinhart = log(steinhart); // ln(R/Ro)
    steinhart /= B; // 1/B * ln(R/Ro)
    steinhart += 1.0 / (NOMINAL_T + 273.15); // + (1/To)
    steinhart = 1.0 / steinhart; // Invert
    steinhart -= 273.15; 
    Serial.println(steinhart);
    int temp=steinhart;
    delay(100);


if(temp < 30 )
    { r=0;g=0;b=0;
      analogWrite(REDPIN, r);
      analogWrite(GREENPIN, g);
      analogWrite(BLUEPIN, b);
      for(b=0;b<256;b++){
      analogWrite(BLUEPIN, b);
      delay(FADESPEED);}
      for(g=0;g<256;g++){
      analogWrite(GREENPIN, g);
      delay(FADESPEED);}
      Timer1.pwm(FAN_PIN, 0);
      Serial.print(" Fan OFF\n");
      delay(100);
      
    }
    else if(temp>=30 && temp<=40)
    {  r=0;g=0;b=0;
      analogWrite(REDPIN, r);
      analogWrite(GREENPIN, g);
      analogWrite(BLUEPIN, b);
      for(b=0;b<256;b++){
      analogWrite(BLUEPIN, b);
      delay(FADESPEED);}
      
      Timer1.pwm(FAN_PIN, 200);
      Serial.print(" Fan Speed: 20%\n");
      delay(100);
      
    } 
    else if(temp>=40 && temp<=50)
    {
      r=0;g=0;b=0;
      analogWrite(REDPIN, r);
      analogWrite(GREENPIN, g);
      analogWrite(BLUEPIN, b);
      for(g=0;g<256;g++){
      analogWrite(GREENPIN, g);
      delay(FADESPEED);}
      
      Timer1.pwm(FAN_PIN, 400);
      Serial.print(" Fan Speed: 40%\n");
      delay(100);
    }
    else if(temp>=50 && temp<=60)
    { r=0;g=0;b=0;
      analogWrite(REDPIN, r);
      analogWrite(GREENPIN, g);
      analogWrite(BLUEPIN, b);
      for(g=0;g<256;g++){
      analogWrite(GREENPIN, g);
      delay(FADESPEED);}
      for(r=0;r<256;r++){
      analogWrite(REDPIN, r);
      delay(FADESPEED);}
      Timer1.pwm(FAN_PIN, 600);
      Serial.print(" Fan Speed: 60%\n"); 
      delay(100);
    }    
    else if(temp>=60 && temp<=80){
      r=0;g=0;b=0;
      analogWrite(REDPIN, r);
      analogWrite(GREENPIN, g);
      analogWrite(BLUEPIN, b);
      for(r=0;r<256;r++){
      analogWrite(REDPIN, r);
      delay(FADESPEED);}
      for(g=0;g<145;g++){
      analogWrite(GREENPIN, g);
      delay(FADESPEED);}
      Timer1.pwm(FAN_PIN, 800);
      Serial.print(" Fan Speed: 80%\n");
      delay(100);
      
    }
    else if(temp>80){
      r=0;g=0;b=0;
      analogWrite(REDPIN, r);
      analogWrite(GREENPIN, g);
      analogWrite(BLUEPIN, b);
      for(r=0;r<256;r++){
      analogWrite(REDPIN, r);
      delay(FADESPEED);}
      Timer1.pwm(FAN_PIN, 1000);
      Serial.print(" Fan Speed: 100%\n");
      delay(100);
    
    } 
  delay(3000);
}
