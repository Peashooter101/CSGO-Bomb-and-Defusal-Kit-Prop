#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
String code = "7355608";
byte steps = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  lcd.init();
  lcd.clear();         
  lcd.noBacklight();
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() == 0) { }
  processInput(Serial.readString().charAt(0));
}

void processInput(char input) {
  if (steps == 0) {
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("*******");
    steps++;
    return;
  }
  if (code.charAt(steps - 1) == input) {
    String displayCode = "";
    int i = 0;
    while (i < (7-steps)) {
      displayCode = displayCode + "*";
      i++;
    }
    i = 0;
    while (i < steps) {
      displayCode = displayCode + code.charAt(i);
      i++;
    }
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print(displayCode);
    steps++;
    if (steps == 8) {
      lcd.setCursor(2,1);
      lcd.print("Bomb Planted");
    }
    return;
  }
  steps = 0;
  lcd.clear();
  lcd.noBacklight();
}
