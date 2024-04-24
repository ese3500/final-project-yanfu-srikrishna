#include <HardwareSerial.h>

HardwareSerial MySerial(2); // define a Serial for UART1
const int MySerialRX = 16;
const int MySerialTX = 17;

void setup()
{
// initialize the Serial to the pins
Serial.begin(9600);
MySerial.begin(9600, SERIAL_8N1, MySerialRX, MySerialTX);
}

void loop()
{
// here we could use our MySerial normally
while (MySerial.available() > 0) {
uint8_t byteFromSerial = MySerial.read();
Serial.println((char) byteFromSerial);
}
// MySerial.write(...);
}