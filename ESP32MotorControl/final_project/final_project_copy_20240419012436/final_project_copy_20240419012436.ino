#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL21481KBvI"
#define BLYNK_TEMPLATE_NAME "MVP"
#define BLYNK_AUTH_TOKEN "iskT88R6sXCbKc9y4XiFdzmZPtRej4BU"

const char* ssid = "OnePlus";
const char* password = "12345678";

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <HardwareSerial.h>

HardwareSerial serialTWO(2); // define a Serial for UART1
const int RX = 16;
const int TX = 17;

#define LEFT_A 14
#define LEFT_B 15
#define RIGHT_A 12
#define RIGHT_B 13

void forward();
void backward();
void turnLeft();
void turnRight();
void stop();

char auth[] = BLYNK_AUTH_TOKEN;
int blynkValueV0;
int blynkValueV1;
int blynkValueV2;
int blynkValueV3;

void setup() {
  Serial.begin(9600);
  serialTWO.begin(9600, SERIAL_8N1, RX, TX);

  Blynk.begin(auth, ssid, password);
  pinMode(LEFT_A, OUTPUT);
  pinMode(LEFT_B, OUTPUT);
  pinMode(RIGHT_A, OUTPUT);
  pinMode(RIGHT_B, OUTPUT);
}
BLYNK_WRITE(V0)
{
  blynkValueV0 = param.asInt();
  if(blynkValueV0 == 1)
  {
    forward();
  }
  else
  {
    stop();
  }
}
BLYNK_WRITE(V1)
{
  blynkValueV1 = param.asInt();
  if(blynkValueV1 == 1)
  {
    backward();
  }
  else
  {
    stop();
  }
}
BLYNK_WRITE(V2)
{
  blynkValueV2 = param.asInt();
  if(blynkValueV2 == 1)
  {
    turnRight();
  }
  else
  {
    stop();
  }
}
BLYNK_WRITE(V3)
{
  blynkValueV3 = param.asInt();
  if(blynkValueV3 == 1)
  {
    turnLeft();
  }
  else
  {
    stop();
  }
}
void loop()
{
  // here we could use our serialTWO normally
  uint8_t byteFromSerial;
  char byteChar;
  while (serialTWO.available() > 0) {
  byteFromSerial = serialTWO.read();
  byteChar = (char)byteFromSerial;
  Serial.println(byteChar);
  if (byteChar == 'f') {
    forward();
  }
  if (byteChar == 'r') {
    backward();
  }
  if (byteChar == 'l') {
    turnLeft();
  }
  if (byteChar == 'r') {
    turnRight();
  }
  if (byteChar == 's') {
    stop();
  }
  }
  Blynk.run();
}
void stop(){
  digitalWrite(LEFT_A, LOW);
  digitalWrite(LEFT_B, LOW);
  digitalWrite(RIGHT_A, LOW);
  digitalWrite(RIGHT_B, LOW);
  //delay(200);
}

void backward(){
  digitalWrite(LEFT_A, HIGH);
  digitalWrite(LEFT_B, LOW);
  digitalWrite(RIGHT_A, HIGH);
  digitalWrite(RIGHT_B, LOW);
  delay(50);
  stop();
  delay(10);
}

void forward(){
  digitalWrite(LEFT_A, LOW);
  digitalWrite(LEFT_B, HIGH);
  digitalWrite(RIGHT_A, LOW);
  digitalWrite(RIGHT_B, HIGH);
  delay(50);
  stop();
  delay(10);
}

void turnLeft(){
  digitalWrite(LEFT_A, HIGH);
  digitalWrite(LEFT_B, LOW);
  digitalWrite(RIGHT_A, LOW);
  digitalWrite(RIGHT_B, HIGH);
  delay(50);
  stop();
  delay(10);
}

void turnRight(){
  digitalWrite(LEFT_A, LOW);
  digitalWrite(LEFT_B, HIGH);
  digitalWrite(RIGHT_A, HIGH);
  digitalWrite(RIGHT_B, LOW);
  delay(50);
  stop();
  delay(10);
}
