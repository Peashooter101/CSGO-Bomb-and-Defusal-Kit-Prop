#include <Keypad.h>

const byte rows = 4;
const byte cols = 3;
char keys[rows][cols] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[rows] = {5, 4, 3, 2};
byte colPins[cols] = {8, 7, 6};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();

  if (key != NO_KEY) {
    Serial.println(key);
  }
}
