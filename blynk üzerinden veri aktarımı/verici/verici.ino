//verici
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_AUTH_TOKEN "5_aIAECSRfCyr1iu1x5QeJU-5GbrTyVA"
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "EV"; //internet adınızı yazın       
char pass[] = "mustafa1969"; //internet şifrenizi yazın   
int deger =0;
int deger1=0;
int deger2=0;
int deger3=0;

BLYNK_WRITE(V0){
    int pinValue = param.asInt();
    deger= param.asInt();
      analogWrite(D0,param.asInt());
      Serial.print("V0 Slider");
      Serial.println(pinValue);
}
BLYNK_WRITE(V1){
    int pinValue = param.asInt();
    deger1= param.asInt();
      analogWrite(D1,param.asInt());
      Serial.print("V0 Slider");
      Serial.println(pinValue);
}
BLYNK_WRITE(V2){
    int pinValue = param.asInt();
    deger2= param.asInt();
      analogWrite(D1,param.asInt());
      Serial.print("V0 Slider");
      Serial.println(pinValue);
}
BLYNK_WRITE(V3){
    int pinValue = param.asInt();
    deger3= param.asInt();
      analogWrite(D1,param.asInt());
      Serial.print("V0 Slider");
      Serial.println(pinValue);
}

/*#define buttonPin1 D1
#define buttonPin2 D3*/

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

RF24 radio(D4,D2); // CE, CSN

const byte address[6] = "00002";

void setup() {
  /*pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);*/
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
      Blynk.begin (auth, ssid, pass, "blynk.cloud", 80);
}
void loop() {
  /*buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);*/
  buttonState1=deger;
  buttonState2=deger1;
  buttonState3=deger2;
  buttonState4=deger3;
  
  if (buttonState1 == 1)
  {
    buttonState1 = 1;
  }
  else  if (buttonState1 == 0)
  {
    buttonState1 = 0;
  }
  if (buttonState2 == 1)
  {
    buttonState2 = 3;
  }
  else  if (buttonState2 == 0)
  {
    buttonState2 = 2;
  }
    if (buttonState3 == 1)
  {
    buttonState3 = 5;
  }
  else  if (buttonState3 == 0)
  {
    buttonState3 = 4;
  }
   if (buttonState4 == 1)
  {
    buttonState4 = 7;
  }
  else  if (buttonState4 == 0)
  {
    buttonState4 = 6;
  }
  
 /* Serial.print(buttonState1);
  Serial.print("\t");
  Serial.print(buttonState2);
  Serial.print("\t");
  Serial.print(buttonState3);
  Serial.print("\t");
  Serial.println(buttonState4);*/
  radio.write(&buttonState1, sizeof(buttonState1));
  radio.write(&buttonState2, sizeof(buttonState2));
  radio.write(&buttonState3, sizeof(buttonState3));
  radio.write(&buttonState4, sizeof(buttonState4));
    Blynk.run(); 
}
