//this code is developed by Abhijith S Pillai || 2020
//this is experiment of me to how to make a obstacle avoiding rover using Arduno 

#include <NewPing.h>
#include <Servo.h>

Servo myservo;

#define TRIGGER_PIN  10
 
#define ECHO_PIN     13
  
#define MAX_DISTANCE 200

#define motor1Forward 2

#define motor1BackWord 3

#define motor2Forward 5

#define motor2backword 4

int distance;
int pos = 0;
int left = false;
int right = false;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
  Serial.begin(115200);
  
  myservo.attach(9);

  pinMode(motor1Forward,OUTPUT);
  pinMode(motor1BackWord,OUTPUT);
  pinMode(motor2Forward,OUTPUT);
  pinMode(motor2backword,OUTPUT);

  digitalWrite(motor1Forward,LOW);
  digitalWrite(motor1BackWord,LOW);
  digitalWrite(motor2Forward,LOW);
  digitalWrite(motor2backword,LOW);

}

void loop() {
  delay(50);
  myservo.write(90); 
  delay(1000);       
  distance = sonar.ping_cm();

  if(distance > 40)
  {
    Serial.print("engine forward");
    Serial.println(distance);

      digitalWrite(motor1Forward,HIGH);
      digitalWrite(motor2Forward,HIGH);
      digitalWrite(motor1BackWord,LOW);
      digitalWrite(motor2backword,LOW);
      left = false;
      right = false;
  }
  else
  {
    digitalWrite(motor1Forward,LOW);
    digitalWrite(motor1BackWord,LOW);
    digitalWrite(motor2Forward,LOW);
    digitalWrite(motor2backword,LOW);
    delay(50);
    myservo.write(0); 
    delay(1000);       
    distance = sonar.ping_cm();
    
      if(distance > 40)
      {
        Serial.print("engine right");
        Serial.println(distance);
              if(right)
              {
                digitalWrite(motor1Forward,HIGH);
                digitalWrite(motor2Forward,HIGH);
                digitalWrite(motor1BackWord,LOW);
                digitalWrite(motor2backword,LOW);
              }
              else
              {
                delay(1000);
                  digitalWrite(motor2Forward,HIGH);
                  digitalWrite(motor1Forward,LOW);
                  digitalWrite(motor1BackWord,LOW);
                  digitalWrite(motor2backword,LOW);
                  delay(50);
                  myservo.write(90); 
                  delay(2000);
                  right = true;
                  left = false;
              }
      }
      else
      {
        digitalWrite(motor1Forward,LOW);
        digitalWrite(motor1BackWord,LOW);
        digitalWrite(motor2Forward,LOW);
        digitalWrite(motor2backword,LOW);

        delay(50);
        myservo.write(180); 
        delay(1000);       
        distance = sonar.ping_cm();

          if(distance > 40 )
          {
            Serial.print("engine left");
            Serial.println(distance);
                  if(left)
                  {
                    digitalWrite(motor1Forward,HIGH);
                    digitalWrite(motor2Forward,HIGH);
                    digitalWrite(motor1BackWord,LOW);
                    digitalWrite(motor2backword,LOW);
                  }
                  else
                  {
                    digitalWrite(motor1Forward,HIGH);
                    digitalWrite(motor2Forward,LOW);
                    digitalWrite(motor1BackWord,LOW);
                    digitalWrite(motor2backword,LOW);
                    delay(50);
                     myservo.write(90); 
                     delay(2000);
                     left = true;
                     right = false;
                  }
          }
          else
          {
            myservo.write(0);

              Serial.print("backword");
              Serial.println(distance);
                digitalWrite(motor1BackWord,HIGH);
                digitalWrite(motor2backword,HIGH);
                digitalWrite(motor1Forward,LOW);
                digitalWrite(motor2Forward,LOW);
                delay(4000);
                digitalWrite(motor1BackWord,HIGH);
                digitalWrite(motor2backword,LOW);
                delay(4000);
          }
      }
  }

  
}
