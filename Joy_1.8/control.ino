
int control(double tempe){
   tMax = setpoint + histeresis;
   tMin = setpoint - histeresis;
   
  //***********************************************
  if(tempe > tMax){
    lcd.noDisplay();
    //digitalWrite(resistenciaPin, LOW);
    digitalWrite(resistenciaPin, HIGH);
    lcd.display();
  }
  if(tempe < tMin){
    lcd.noDisplay();
    //digitalWrite(resistenciaPin, HIGH);
    digitalWrite(resistenciaPin, LOW);
    lcd.display();
  }
  // **********************************************************
}

