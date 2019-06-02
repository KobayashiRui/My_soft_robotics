#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

float press_data;

void setup(){
    //Serial.begin(9600);
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    //Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
    }

    display.display();
    delay(500);
    
}

void loop(){
  press_data = calcpress();
  drawpress(press_data);
}

float calcpress(){
  int val = 0;  // variable to store the value read
  float voltage;
  float val2volt = 5.0/1023.0; //mega 10bit is 1023
  float volt2pres_a = 1000.0/4.5;//4.5 is param
  float volt2pres_b = 191.51/4.5;//185.71 is param
  float pres;
  float press_total;
  float press_aberage;
  for(int i=0; i < 200; i++){
    val = analogRead(A3);  // read the input pin
    voltage = val2volt * val;
    pres = (volt2pres_a * voltage) - volt2pres_b;
    press_total += pres;
    delay(1);
  }
  press_aberage = press_total/200;
  return press_aberage;
}

void drawpress(float press_data) {
  display.clearDisplay();

  display.setTextSize(1.5);             // Normal 1:1 pixel scale
  display.setTextColor(BLACK,WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.print("                     ");
  display.println(F("\n Pressure measurement\n"));

  display.setTextSize(2);             // Draw 2X-scale text
  display.setTextColor(WHITE);
  //display.print(F("0x")); display.println(0xDEADBEEF, HEX);
  display.print(press_data);
  display.setTextSize(1);
  display.println("\n             [kPa]");
  display.display();
  delay(100);
}
