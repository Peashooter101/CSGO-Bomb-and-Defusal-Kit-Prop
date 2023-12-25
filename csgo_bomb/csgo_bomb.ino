#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

const byte rows = 4;
const byte cols = 3;
char keys[rows][cols] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[rows] = {8, 9, 10, 11};
byte colPins[cols] = {5, 6, 7};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

LiquidCrystal_I2C lcd(0x27,16,2);
String code = "7355608";
byte steps = 0;
byte beep = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.noBacklight();
}

void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY) {
    Serial.println(key);
    if (beep == 1) beep = 0;
    else processInput(key);
  }
}

void processInput(char input) {
  Serial.println("Processing Input");
  Serial.println(steps);
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
      bombCountdown();
    }
    return;
  }
  steps = 0;
  lcd.clear();
  lcd.noBacklight();
}

void bombCountdown() {
  delay(1000);
  lcd.clear();
  beep = 1;
  for (int i = 0; i < 45; i++) {
    if (beep == 0) return;
    lcd.noBacklight();
    tone(3, 4000, 100);
    delay(500);
    lcd.backlight();
    delay(500);
  }

}