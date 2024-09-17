#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
extern LiquidCrystal_I2C lcd;
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte eyesOpen[8] = {
	0b00000,
	0b01110,
	0b11101,
	0b11111,
	0b10111,
	0b11011,
	0b01110,
	0b00000
};

byte eyesWideOpen[8] = {
	0b00000,
	0b01110,
	0b10001,
	0b10001,
	0b10101,
	0b10001,
	0b10001,
	0b01110
};

byte eyesClose[8] = {
	0b00000,
	0b00000,
	0b01110,
	0b10001,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};
byte angryLeftEye[8] = {
	0b00000,
	0b10000,
	0b11000,
	0b11100,
	0b10110,
	0b11011,
	0b01110,
	0b00000
};
byte angryRightEye[8] = {
	0b00000,
	0b00001,
	0b00011,
	0b00111,
	0b01111,
	0b11011,
	0b01110,
	0b00000
};
byte lipOpen[8] = {
	0b00000,
	0b11111,
	0b10001,
	0b10001,
	0b10001,
	0b10001,
	0b01110,
	0b00000
};
byte lipSmile[8] = {
	0b00000,
	0b10001,
	0b01110,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};
byte lipSad[8] = {
	0b00000,
	0b00000,
	0b01110,
	0b10001,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};

byte narges[8] = {
	0b00000,
	0b01110,
	0b11111,
	0b10001,
	0b10001,
	0b11011,
	0b01110,
	0b00000
};

void happy() {
  lcd.createChar(0, eyesClose);
  lcd.createChar(1, lipSmile);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.print("   ");
  lcd.write(byte(0));
  lcd.setCursor(6,1);
  lcd.print("  ");
  lcd.write(byte(1));
  lcd.print("  ");
}
void cry() {
  lcd.setCursor(6,0);
  lcd.print("T   T");
  lcd.setCursor(6,1);
  lcd.print("  ^  ");
}
void sad() {
  lcd.createChar(0, lipSad);
  lcd.setCursor(6,0);
  lcd.print("-   -");
  lcd.setCursor(6,1);
  lcd.print("  ");
  lcd.write(byte(0));
  lcd.print("  ");
}

void mad() {
  lcd.createChar(0, angryLeftEye);
  lcd.createChar(1, angryRightEye);
  lcd.setCursor(6,0);
  lcd.write(byte(0)); 
  lcd.print("   ");
  lcd.write(byte(1));
  lcd.setCursor(6,1);
  lcd.print("  -  ");
}

void cute() {
  lcd.createChar(0, eyesOpen);
  lcd.createChar(1, lipOpen);
  lcd.setCursor(6,0);
  lcd.write(byte(0)); 
  lcd.print("   ");
  lcd.write(byte(0)); 
  lcd.setCursor(6,1);
  lcd.print("  ");
  lcd.write(byte(1));  
  lcd.print("  ");
}

void shock() {
  lcd.createChar(0,eyesWideOpen);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.print("   ");
  lcd.write(byte(0));
  lcd.setCursor(6,1);
  lcd.print("  -  ");
}
void wink() {
  lcd.setCursor(6,0);
  lcd.print(">   -");
  lcd.setCursor(6,1);
  lcd.print("  V  ");
}

void happyAnimated() {
  lcd.createChar(0, lipSmile);

  lcd.setCursor(5,0);
  lcd.print("O   O  ");
  lcd.setCursor(6,1);
  lcd.print("  ");
  lcd.write(byte(0));  
  lcd.print("  ");
  delay(500);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("-   -  ");
  lcd.setCursor(6,1);
  lcd.print("  ");
  lcd.write(byte(0));  
  lcd.print("  ");
  delay(100);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print(" -   - ");
  lcd.setCursor(6,1);
  lcd.print("  ");
  lcd.write(byte(0));  
  lcd.print("  ");
  delay(100);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print(" O   O ");
  lcd.setCursor(6,1);
  lcd.print("  ");
  lcd.write(byte(0));  
  lcd.print("  ");
  delay(1000);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print(" -   - ");
  lcd.setCursor(6,1);
  lcd.print("  ");
  lcd.write(byte(0));  
  lcd.print("  ");
  delay(100);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("  -   -");
  lcd.setCursor(6,1);
  lcd.print("  ");
  lcd.write(byte(0));  
  lcd.print("  ");
  delay(100);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("  O   O");
  lcd.setCursor(6,1);
  lcd.print("  ");
  lcd.write(byte(0));  
  lcd.print("  ");
  delay(500);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("  -   -");
  lcd.setCursor(6,1);
  lcd.print("  ");
  lcd.write(byte(0));  
  lcd.print("  ");
  delay(100);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print(" -   - ");
  lcd.setCursor(6,1);
  lcd.print("  ");
  lcd.write(byte(0));  
  lcd.print("  ");
  delay(100);
  lcd.setCursor(5,0);
  lcd.print(" O   O ");
  lcd.setCursor(6,1);
  lcd.print("  ");
  lcd.write(byte(0));  
  lcd.print("  ");
  delay(1000);
  lcd.setCursor(5,0);
  lcd.print(" -   - ");
  lcd.setCursor(6,1);
  lcd.print("  ");
  lcd.write(byte(0));  
  lcd.print("  ");
  lcd.clear();
  delay(100);
  lcd.setCursor(5,0);
  lcd.print("-   -  ");
  lcd.setCursor(6,1);
  lcd.print("  ");
  lcd.write(byte(0));  
  lcd.print("  ");
  delay(100);
  lcd.clear();
}

void nargesFACES() {
  lcd.createChar(0, narges);
  lcd.createChar(1, lipSmile);
  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.print("   ");
  lcd.write(byte(0));
  lcd.setCursor(6, 1);
  lcd.print("  ");
  lcd.write(byte(1));  
  lcd.print("  ");
}