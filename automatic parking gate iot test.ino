
#define ir_sensor 13
#define servo 15
#define Screenwidth 128
#define screenheight 32
#define oledreset -1
#include<Wire.h>
#include<Adafruit_SSD1306.h>
#include<ESP32Servo.h>
Servo myservo;

Adafruit_SSD1306 display(Screenwidth,screenheight,&Wire,oledreset);
void setup() {
  Serial.begin(115200);
  Wire.begin(21,22);
  if (!display.begin(SSD1306_SWITCHCAPVCC,0x3C))
  {
    Serial.println("OLED not found .check wiring!");
    for(;;);
    }
  pinMode(ir_sensor,INPUT);
  myservo.attach(servo,500,3000);
  
  // put your setup code here, to run once:
 
}

void loop() {
  // put your main code here, to run repeatedly:
int SensorValue=digitalRead(ir_sensor);
if (SensorValue==LOW)
{
  display.clearDisplay();
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);
display.setCursor(10,0);
display.println("object detected!");
Serial.println("Object detected");
display.display();
delay(100);
for(int pos=0;pos<0;pos++)
{
  myservo.write(pos);
  delay(100);
}
delay(500);
display.clearDisplay();
display.display();
for (int pos=90;pos>0;pos--)
{
  myservo.write(pos);
  delay(15);
}

}
else
{
  display.clearDisplay();
  display.display();
}
delay(500);
}
