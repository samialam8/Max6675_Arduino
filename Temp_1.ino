#include "max6675.h" 
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <Adafruit_Sensor.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET);

// Temperature Sensor1
int Tcouple1D0  = 4; // so
int Tcouple1CS  = 5; //cs
int Tcouple1CLK = 6; // sck
float Temp1 = 0; 
MAX6675 thermocouple1(Tcouple1CLK, Tcouple1CS, Tcouple1D0); 


// Temperature Sensor2
int Tcouple2D0  = 7; // so
int Tcouple2CS  = 8; //cs
int Tcouple2CLK = 9; // sck
float Temp2 = 0; 
MAX6675 thermocouple2(Tcouple2CLK, Tcouple2CS, Tcouple2D0); 

void setup()
{
  Serial.begin(9600); 
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  delay(2000);
    display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop()
{
  Temp1 = thermocouple1.readCelsius(); 
  delay(100);
  Temp2 = thermocouple2.readCelsius();
  delay(100);
  //clear display
  display.clearDisplay();
  
  // temperature sensor 1
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temp1: ");
  display.setTextSize(2);
  display.setCursor(38,0);
  display.print(Temp1);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");

// temperature sensor 2
  display.setTextSize(1);
  display.setCursor(0,20);
  display.print("Temp2: ");
  display.setTextSize(2);
  display.setCursor(38,20);
  display.print(Temp2);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");

  display.setTextSize(1);
  display.setCursor(0,57);
  display.print(" Trial 1 ");
 display.display();
  
}
