#include <TimerOne.h>
const int IN1=27;
const int IN2=28;
const int ENA=22;
const int IN3=26;
const int IN4=25;
const int ENB=23;
volatile double Count = 0;
long c;
double rpm;
double i;
unsigned long time1;
unsigned long startMillis;


double kp = .07;
double ki = .05;
double kd = .03;
 
unsigned long currentTime, previousTime = 0;
double elapsedTime;
double error;
double lastError;
double input;
double out;
double Setpoint;
double cumError, rateError;
//long rpm;

void setup(){
        startMillis = millis();  
        Setpoint = 200;   
        pinMode(IN1, OUTPUT);
        pinMode(IN2, OUTPUT);
        pinMode(ENA, OUTPUT);
        pinMode(IN4, OUTPUT);
        pinMode(IN3, OUTPUT);
        pinMode(ENB, OUTPUT);
      
        pinMode(3, INPUT);
        pinMode(2, INPUT);
        attachInterrupt(digitalPinToInterrupt(3), leftEncoderEvent, CHANGE);
        Timer1.initialize(100000); 
        Timer1.attachInterrupt(isr); 
        Serial.begin(9600);
        //Motor2_Forward(100);
        //delay(500)  ;              
}    

void loop(){
  
     digitalWrite(IN4,HIGH);
     digitalWrite(IN3,LOW);
         
        
        
   }
void isr()        // interrupt service routine - tick every 0.1sec
{ 
       Serial.println(rpm);
       rpm = 60.0*(Count/90)/0.1;  //calculate motor speed, unit is rpm
       Count=0;
            
        error = Setpoint - rpm; 
        cumError += error; //* elapsedTime;                
        rateError = (error - lastError);///elapsedTime;                                  
        double out = kp*error + ki*cumError + kd*rateError; 
        analogWrite(ENB,out); 
        Serial.println(out);
        lastError = error;                             
        previousTime = currentTime;                        
 
        //return out;
                                               
}

void leftEncoderEvent() {
  if (digitalRead(3) == HIGH) {
    if (digitalRead(2) == LOW) {
      Count++;
    } 
    else if(digitalRead(2) == HIGH) {
      Count--;
    }}}
  
void Motor2_Forward(int Speed)
{
     digitalWrite(IN4,HIGH);
     digitalWrite(IN3,LOW);
     analogWrite(ENB,Speed);
}
