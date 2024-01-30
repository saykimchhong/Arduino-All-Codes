  #include <LiquidCrystal.h> // LiquidCrystal by Arduino, Adafruit

LiquidCrystal lcd(13,12,11,10,9,8);   //rs,en,d4,d5,d6,d7

void setup()   {
  //put your setup code here,to run once:
  lcd.begin(16,2);

  lcd.print("WELCOME");delay(1000);
  lcd.clear();

}

void loop()  {
  //put your main code here,to run repeatedly:
  int i=0;
  lcd.setCursor(0, 0);
  lcd.print("NUMBERS:");
 for(i=0;i<1000;i++)
  {
    lcd.setCursor(12, 1);
    lcd.print(i);
    delay(2000);
  }


}
  


