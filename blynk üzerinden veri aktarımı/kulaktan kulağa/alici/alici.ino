
//ORTA ALİCİ
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define led1 D1
#define led3 D0
#define led4 D3
#define led2 D8
int deneme =0;
int buttonState = 0;

RF24 radio(D4,D2); // CE, CSN
const byte address[][6] = {"00002","00001"};

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);  
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);  
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  radio.begin();
  radio.openReadingPipe(0, address[0]);
  radio.openWritingPipe(address[1]);
  radio.setPALevel(RF24_PA_MIN);
}
void loop() {
  radio.startListening();
  while (!radio.available());
  radio.read(&buttonState, sizeof(buttonState));
  Serial.println(buttonState);

  if (buttonState == 1) {
    digitalWrite(led1, LOW);
  }
  else  if (buttonState == 0) {
    digitalWrite(led1, HIGH);
  }
  else if (buttonState == 3) {
    digitalWrite(led2, LOW);
  }
  else  if (buttonState == 2) {
    digitalWrite(led2, HIGH);
  }
  else  if (buttonState == 5) {
    digitalWrite(led3, LOW);
  }
  else  if (buttonState == 4) {
    digitalWrite(led3, HIGH);
    delay(1000);
  }  else  if (buttonState == 7) {
    digitalWrite(led4, LOW);
  }
  else  if (buttonState == 6) {
    digitalWrite(led4, HIGH);
  }
  else if(buttonState == 9) {
  radio.stopListening();
  deneme=buttonState;
  radio.write(&deneme, sizeof(deneme));
  }
  else if(buttonState == 8) {
  radio.stopListening();
  deneme=buttonState;
  radio.write(&deneme, sizeof(deneme));
  }
}
