#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,20,2);
String intro = "MSSV :   1653020058    ";
void setup() 
{
  Serial.begin(9600);
  dht.begin();
  lcd.init();  
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("SV: DangGiaHan");
  for (int i=0; i<intro.length()-16; i++){
    for (int j=0; j<=16; j++){
      lcd.setCursor(j,1);
      lcd.print(intro[i+j]);
    }
      delay(250);
  }
  
  delay(5000);
  lcd.clear();
}

void loop() 
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  lcd.setCursor(0,0);
  lcd.print("NhietDo: ");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C ");
  lcd.setCursor(0,1);
  lcd.print("DoAm: ");
  lcd.print(h);
  lcd.print(" %");
  delay(5000);
  lcd.clear();
  text_GiaHan(); 
  delay(1000);
  lcd.clear();
}
void text_GiaHan()
{
  lcd.setCursor(0, 0);
  lcd.print("SV: DangGiaHan");
  lcd.setCursor(0, 1);
  lcd.print("MSSV: 1653020058");
  }
