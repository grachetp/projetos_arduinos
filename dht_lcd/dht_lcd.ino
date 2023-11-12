//DHT11 + LCD

#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte a[8]= {B00110,B01001,B00110,B00000,B00000,B00000,B00000,B00000,}; 
 
void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  Serial.begin(9600);
  dht.begin();
  lcd.clear();

}
 
void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  

  //°C

  if (isnan(t) || isnan(h)) 
  {
     lcd.setCursor(0, 0);
     lcd.print("Failed DHT");
     Serial.println("Failed to read from DHT");
  } 
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("Temp:");
    lcd.setCursor(12, 0);
    lcd.createChar(1, a);
    lcd.setCursor(12,0); 
    lcd.write(1);
    lcd.setCursor(13,0); 
    lcd.write("C");

    lcd.setCursor(0, 1);
    lcd.print("Humid:");
    lcd.setCursor(7, 0);
    lcd.print(t);
    lcd.setCursor(7, 1);
    lcd.print(h);
    lcd.setCursor(12, 1);
    lcd.print("%");
  }
  delay(1000);
  lcd.clear();
}