
// ALİCİ
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
const byte address[6] = "00001";

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
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
}
void loop() {
  radio.startListening();
  while (!radio.available());
  radio.read(&buttonState, sizeof(buttonState));
  Serial.println(buttonState);

  if (buttonState == 9) {
    digitalWrite(led3, LOW);
  }
  else  if (buttonState == 8) {
    digitalWrite(led3, HIGH);
    delay(1000);
  }
}
