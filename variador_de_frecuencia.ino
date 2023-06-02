#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pin1 = 7;
const int pin2 = 8;
const int pin3 = 9;
const int start = 11;
const int subir = 10;
const int bajar = 12;
const int buzzer = 13;

int val = 0;

void setup() {

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(start, INPUT);
  pinMode(subir, INPUT);
  pinMode(bajar, INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Epsilon A.E");
  lcd.setCursor(0, 1);
  lcd.print("0414-7283876");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Control de");
  lcd.setCursor(0, 1);
  lcd.print("   Velocidad");
  delay(2000);
  lcd.clear();
}

void loop() {

  if (digitalRead(subir) == HIGH) {
    val++;
    while (digitalRead(subir) == HIGH) {
      tone(buzzer, 3000);
    }
    noTone(buzzer);
  }
  if (digitalRead(bajar) == HIGH) {
    val--;
    while (digitalRead(bajar) == HIGH) {
      tone(buzzer, 3000);
    }
    noTone(buzzer);
  }
  if (val > 7) {
    val = 7;
  } else if (val < 0) {
    val = 0;
  }
  Serial.println(val);
  showVel(val);

  if (digitalRead(start) == HIGH) {
    Vels(val);
    tone(buzzer, 3000);
    delay(1000);
    noTone(buzzer);
  }
}

void showVel(int x) {

  switch (x) {

    case 0:
      lcd.setCursor(0, 0);
      lcd.print("  Velocidad: 0"  );
      lcd.print("        ");
      break;

    case 1:
      lcd.setCursor(0, 0);
      lcd.print("  Velocidad: 1  ");
      break;

    case 2:
      lcd.setCursor(0, 0);
      lcd.print("  Velocidad: 2  ");
      break;

    case 3:
      lcd.setCursor(0, 0);
      lcd.print("  Velocidad: 3  ");
      break;

    case 4:
      lcd.setCursor(0, 0);
      lcd.print("  Velocidad: 4  ");
      break;

    case 5:
      lcd.setCursor(0, 0);
      lcd.print("  Velocidad: 5  ");
      break;

    case 6:
      lcd.setCursor(0, 0);
      lcd.print("  Velocidad: 6  ");
      break;

    case 7:
      lcd.setCursor(0, 0);
      lcd.print("  Velocidad: 7  ");
      break;
  }
}

void Vels(int y) {

  if (y == 0) {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
  }

  else if (y == 1) {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
  }

  else if (y == 2) {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, LOW);
  }

  else if (y == 3) {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
  }

  else if (y == 4) {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, LOW);
  }

  else if (y == 5) {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
  }

  else if (y == 6) {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);
  }

  else if (y == 7) {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);
  }
}
