#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int Led = 13; //define LED port
int buttonpin = 3; //define switch port for touch sensor
int  val;//define digital variable val
int positionCounter = 0;
int redpin = 6; //select the pin for the red LED
int greenpin = 5; // select the pin for the green LED
int bluepin = 4; // select the pin for the  blue LED
//bool Touched;

void  setup()
{
  pinMode(Led, OUTPUT); //define LED as an output port
  pinMode(buttonpin, INPUT); //define switch as an output port
  lcd.begin(16, 2); //set up the LCD's number of columns and rows:
  pinMode(redpin, OUTPUT); pinMode(bluepin, OUTPUT); pinMode(greenpin, OUTPUT); Serial.begin(9600); //Set up the LED Button
}


void  loop()
{
  val = digitalRead(buttonpin); //read the value of the digital interface 3 assigned to val
  while (val == HIGH) //when the switch sensor have signal, LED blink
  {
    Touched();
    break;
  }
  while (val == LOW)
  {
    NotTouched();
    break;
  }
}

void Touched() {
  digitalWrite(Led, HIGH);
  analogWrite(6, 0); analogWrite(5, 255); analogWrite(4, 0); //Turn ON LED
  lcd.display();// Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("Hello User!");
  delay(100);
  //lcd.scrollDisplayLeft();
}

void NotTouched() {
  lcd.setCursor(0, 0);
  digitalWrite(Led, LOW);
  analogWrite(6, 255); analogWrite(5, 0); analogWrite(4, 0); //Turn OFF LED
  lcd.noDisplay();
}
