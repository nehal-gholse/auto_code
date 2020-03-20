#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <SPI.h>
#include <WiFi.h>
#include <BlynkSimpleEnergiaWiFi.h>
#include <Wire.h>




int j=-1;
int a[100];
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "pFWcl56amYvxqQhfCK75-2MgXiouuX4p";

// Your WiFi credentials
char ssid[] = "nehal";
char pass[] = "nehalkawifi";        // Set to "" for open networks


void setup() {
  // put your setup code here, to run once:
//Open a serial terminal with the PC
  Serial.begin(9600);   
  //Set up a blynk connection with your WiFi credentials
  Blynk.begin(auth, ssid, pass); 
  pinMode(5,OUTPUT);
  digitalWrite(5,LOW);
  pinMode(6,OUTPUT);
  digitalWrite(6,LOW);
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
}
  
BLYNK_WRITE(V1)
{
  //Print to the terminal
  BLYNK_LOG("Got a value: %s", param.asStr());
  
  
  int i = param.asInt(); 
  if(i == 1)
  {
    digitalWrite(5,HIGH);
    j=j+1;
    a[j]= 8;  //8 is for forward
  }
  else if(i == 0)
  {
    digitalWrite(5, LOW);
  }
}
BLYNK_WRITE(V5)
{
  //Print to the terminal
  BLYNK_LOG("Got a value: %s", param.asStr());
  
  
  int i = param.asInt(); 
  if(i == 1)
  {
    digitalWrite(6,HIGH);
    j=j+1;
    a[j]= 2;  //2 is for reverse
  }
  else if(i == 0)
  {
    digitalWrite(6, LOW);
  }
}
BLYNK_WRITE(V2)
{
  //Print to the terminal
  BLYNK_LOG("Got a value: %s", param.asStr());
  
  
  int i = param.asInt(); 
  if(i == 1)
  {
    digitalWrite(7,HIGH);
    j=j+1;
    a[j]= 9; //9 is for forward for second motor
  }
  else if(i == 0)
  {
    digitalWrite(7, LOW);
  }
}
BLYNK_WRITE(V3)
{
  //Print to the terminal
  BLYNK_LOG("Got a value: %s", param.asStr());
  
  
  int i = param.asInt(); 
  if(i == 1)
  {
    digitalWrite(8,HIGH);
    j=j+1;
    a[j]= 3; //3 reverse for seocnd motor
  }
  else if(i == 0)
  {
    digitalWrite(8, LOW);
  }
}
BLYNK_WRITE(V4)
{
  //Print to the terminal
  BLYNK_LOG("Got a value: %s", param.asStr());
  
  
  int i = param.asInt(); 
  if(i == 1)
  {
   auto1();
  }
}
void auto1()
{
  for(j=0;j<100;j++)
  {
    if(a[j]==8)
    {
      digitalWrite(5,HIGH);
    }
    if(a[j]==2)
    {
      digitalWrite(6,HIGH);
    }
    if(a[j]==9)
    {
      digitalWrite(7,HIGH);
    }
    if(a[j]==3)
    {
      digitalWrite(8,HIGH);
    }
  }
}

 
void loop() {
  // put your main code here, to run repeatedly: 
  Blynk.run();
}
