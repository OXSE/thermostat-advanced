void reloj(){
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;   
    // ******************************************************** Watch Dog 
  wdt_reset(); // sino regreso en 8 segundos llama a reset
 // ******************************************************** Watch Dog
    segundos = segundos + 1;
  }
  if(segundos == 60){
    segundos = 0;
    minutos = minutos + 1;
  }
  if(motorState == LOW){
      if(minutos == tiempoOff){
        minutos = 0;
        segundos = 0;
        motorState = HIGH;
        lcd.clear();
      }
    }  

  if (motorState == HIGH){
      if(segundos == tiempoOn){
        motorState = LOW;
        segundos = 0;
        minutos = 0;
        lcd.clear();
      }
    } 
  // ******************************************************** Watch Dog 
  wdt_reset(); // sino regreso en 8 segundos llama a reset
 // ******************************************************** Watch Dog
 }
