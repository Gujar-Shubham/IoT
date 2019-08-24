#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

#include<FirebaseArduino.h>
#include <Firebase.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>


#include <ESP8266WiFi.h>
#include<FirebaseArduino.h>
#define FIREBASE_HOST "home-automation-1d692.firebaseio.com"                     //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "hUb95AYYfDPducrlso1t48dkS3pPO91ly0dbBIKz"       //Your Firebase Database Secret goes here
#define WIFI_SSID "goldenshark"                                               //your WiFi SSID for which yout NodeMCU connects
#define WIFI_PASSWORD "12345678"                                      //Password of your wifi network 

#define Relay1 16  //D0
#define Relay2 5  //D1
#define Relay3 4  //D2
#define Relay4 0  //D3
#define Relay5 2  //D4
#define Relay6 14  //D5
#define Relay7 12  //D6
#define Relay8 13  //D7
#define Relay9 15 //D8
#define Relay10 3  //D9
int rel1,rel2,rel3,rel4,rel5,rel6,rel7,rel8,rel9,rel10;

void setup() 
{
  Serial.begin(115200);      // Set the baud rate 115200 in Serial Monitor to display debug messages
  pinMode(Relay1,OUTPUT);
  pinMode(Relay2,OUTPUT);
  pinMode(Relay3,OUTPUT);
  pinMode(Relay4,OUTPUT);
  pinMode(Relay5,OUTPUT);
  pinMode(Relay6,OUTPUT);
  pinMode(Relay7,OUTPUT);
  pinMode(Relay8,OUTPUT);
  pinMode(Relay9,OUTPUT);
  pinMode(Relay10,OUTPUT);
  digitalWrite(Relay1,HIGH);
  digitalWrite(Relay2,HIGH);
  digitalWrite(Relay3,HIGH);
  digitalWrite(Relay4,HIGH);
  digitalWrite(Relay5,HIGH);
  digitalWrite(Relay6,HIGH);
  digitalWrite(Relay7,HIGH);
  digitalWrite(Relay8,HIGH);
  digitalWrite(Relay9,HIGH);
  digitalWrite(Relay10,HIGH);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected:");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  
  Firebase.setInt("FB1",0);                     //Here the varialbe"FB1","FB2","FB3" and "FB4" needs to be the one which is used in our Firebase and MIT App Inventor
  Firebase.setInt("FB2",0); 
  Firebase.setInt("FB3",0); 
  Firebase.setInt("FB4",0); 
  Firebase.setInt("FB5",0);                     //Here the varialbe"FB1","FB2","FB3" and "FB4" needs to be the one which is used in our Firebase and MIT App Inventor
  Firebase.setInt("FB6",0); 
  Firebase.setInt("FB7",0); 
  Firebase.setInt("FB8",0); 
  Firebase.setInt("FB9",0);                     //Here the varialbe"FB1","FB2","FB3" and "FB4" needs to be the one which is used in our Firebase and MIT App Inventor
  Firebase.setInt("FB10",0); 
}
void firebasereconnect()
{
  Serial.println("Trying to reconnect");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  }

void loop() 
{
  if (Firebase.failed())
      {
      Serial.print("setting number failed:");
      Serial.println(Firebase.error());
      firebasereconnect();
      return;
      }
      
  rel1=Firebase.getString("FB1").toInt();  //Reading the value of the varialble Status from the firebase
  rel2=Firebase.getString("FB2").toInt();  //Reading the value of the varialble Status from the firebase
  rel3=Firebase.getString("FB3").toInt();  //Reading the value of the varialble Status from the firebase
  rel4=Firebase.getString("FB4").toInt();  //Reading the value of the varialble Status from the firebase
  rel5=Firebase.getString("FB5").toInt();  //Reading the value of the varialble Status from the firebase
  rel6=Firebase.getString("FB6").toInt();  //Reading the value of the varialble Status from the firebase
  rel7=Firebase.getString("FB7").toInt();  //Reading the value of the varialble Status from the firebase
  rel8=Firebase.getString("FB8").toInt();  //Reading the value of the varialble Status from the firebase
  rel9=Firebase.getString("FB9").toInt();  //Reading the value of the varialble Status from the firebase
  rel10=Firebase.getString("F102").toInt();  //Reading the value of the varialble Status from the firebase
  if(rel1==1)                                                             // If, the Status is 1, turn on the Relay1
     {
      digitalWrite(Relay1,LOW);
      Serial.println("Relay 1 ON");
    }
 if(rel1==0)                                                      // If, the Status is 0, turn Off the Relay1
    {                                      
      digitalWrite(Relay1,HIGH);
      Serial.println("Relay 1 OFF");
    }
if(rel2==1)                                                             // If, the Status is 1, turn on the Relay2
     {
      digitalWrite(Relay2,LOW);
      Serial.println("Relay 2 ON");
    }
 if(rel2==0)                                                      // If, the Status is 0, turn Off the Relay2
    {                                      
      digitalWrite(Relay2,HIGH);
      Serial.println("Relay 2 OFF");
    }
if(rel3==1)                                                             // If, the Status is 1, turn on the Relay3
     {
      digitalWrite(Relay3,LOW);
      Serial.println("Relay 3 ON");
    }
if(rel3==0)                                                      // If, the Status is 0, turn Off the Relay3
    {                                      
      digitalWrite(Relay3,HIGH);
      Serial.println("Relay 3 OFF");
    }
 if(rel4==1)                                                             // If, the Status is 1, turn on the Relay4
     {
      digitalWrite(Relay4,LOW);
      Serial.println("Relay 4 ON");
    }
if(rel4==0)                                                      // If, the Status is 0, turn Off the Relay4
    {                                      
      digitalWrite(Relay4,HIGH);
      Serial.println("Relay 4 OFF");
    }    
if(rel5==1)                                                             // If, the Status is 1, turn on the Relay1
     {
      digitalWrite(Relay5,LOW);
      Serial.println("Relay 5 ON");
    }
 if(rel5==0)                                                      // If, the Status is 0, turn Off the Relay1
    {                                      
      digitalWrite(Relay5,HIGH);
      Serial.println("Relay 5 OFF");
    }
if(rel6==1)                                                             // If, the Status is 1, turn on the Relay2
     {
      digitalWrite(Relay6,LOW);
      Serial.println("Relay 6 ON");
    }
 if(rel6==0)                                                      // If, the Status is 0, turn Off the Relay2
    {                                      
      digitalWrite(Relay6,HIGH);
      Serial.println("Relay 6 OFF");
    }
if(rel7==1)                                                             // If, the Status is 1, turn on the Relay3
     {
      digitalWrite(Relay7,LOW);
      Serial.println("Relay 7 ON");
    }
if(rel7==0)                                                      // If, the Status is 0, turn Off the Relay3
    {                                      
      digitalWrite(Relay7,HIGH);
      Serial.println("Relay 7 OFF");
    }
 if(rel8==1)                                                             // If, the Status is 1, turn on the Relay4
     {
      digitalWrite(Relay8,LOW);
      Serial.println("Relay 8 ON");
    }
if(rel8==0)                                                      // If, the Status is 0, turn Off the Relay4
    {                                      
      digitalWrite(Relay8,HIGH);
      Serial.println("Relay 8 OFF");
if(rel9==1)                                                             // If, the Status is 1, turn on the Relay1
     {
      digitalWrite(Relay9,LOW);
      Serial.println("Relay 9 ON");
    }
 if(rel9==0)                                                      // If, the Status is 0, turn Off the Relay1
    {                                      
      digitalWrite(Relay9,HIGH);
      Serial.println("Relay 9 OFF");
    }
if(rel10==1)                                                             // If, the Status is 1, turn on the Relay2
     {
      digitalWrite(Relay10,LOW);
      Serial.println("Relay 10 ON");
    }
}
}
