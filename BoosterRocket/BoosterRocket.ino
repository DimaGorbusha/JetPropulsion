#include <LoRa.h>

// by Dmitriy Gorbunov
// Last Update December 14th 2022

//----definitions----
#define DIO0_RF 5
#define RST_RF 6
#define LED 7
#define NSS_RF 8
#define CS_SD 9
#define SCK 10
#define MISO 11
#define MOSI 12
#define BTN_1 13
#define BTN_2 14
#define BTN_3 15
#define Zummer 16
#define SDA 35
#define SCL 34
#define Check 33
#define Servo_1 32
#define Servo_2 31
// #define SPI ## Use if overwrite default LoRa SPI

void LoRaInit(){
  // LoRa.setSPI(SPI); Use if overwrite default LoRa SPI
  LoRa.begin(433E6);
  LoRa.setPins(NSS_RF, RST_RF, DIO0_RF);
}

void LoRaWrite(char package){
  LoRa.beginPacket();
  LoRa.write(package);
  if (LoRa.endPacket()){
    Serial.println("Successful transmission");
  }else{
    Serial.println("Transmission failed");
  }
}

char createPackage(String TeamID, int Time, double Altitude, double Voltage, double A, byte StartPoint, byte ApogeePoint, byte SatPoint, byte LandingPoint){
  String buffer = String(TeamID) + ";" + String(Time) + ";" + String(Altitude) + ";" + String(Voltage) + ";" + String(A) + ";" + String(StartPoint) + ";" + String(ApogeePoint) + ";" + String(SatPoint) + ";" + String(LandingPoint);
  char package[] = {};
  buffer.toCharArray(package, buffer.length());
  return package;
}

void setup(){

}

void loop(){

}