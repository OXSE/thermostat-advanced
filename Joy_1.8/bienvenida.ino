
void bienvenida(){
  lcd.setCursor(0, 0);
  lcd.print("Bienvenido");
  lcd.setCursor(0, 1);
  lcd.print("al Termostato");
  delay(600);
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Joy 1.9");
  lcd.setCursor(0, 1);
  lcd.print("de LAOTEC");
  delay(600);
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Hecho en Mexico");
  delay(600);
  lcd.clear();
}

