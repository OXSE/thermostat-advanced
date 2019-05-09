void pantalla(){

   if (contador == 1){
  lcd.setCursor(0, 0);
  lcd.print(temperatura);lcd.print((char)223);lcd.print('C');
  lcd.print(" SP=");lcd.print(setpoint);
  lcd.setCursor(0, 1);
  lcd.print("Volteo ");
  if(motorState == LOW){
    lcd.print("A ");
    }else{
     lcd.print("E ");
  }
  lcd.print(minutos);lcd.print(':');lcd.print(segundos);
      }

   //**************** 4 Ajustar tiempo encendido en segundos***************************
   if(contador == 2){
    lcd.setCursor(0, 0);
    lcd.print("Ajustes ");
    lcd.print(contador - 1);
    lcd.print(" de 5 ");
    lcd.setCursor(0, 1);
    lcd.print("Tiempo On ");
    lcd.print(tiempoOn);
    lcd.print(" s");
    if((subirEstado == HIGH) && (bajarEstado == LOW) && (menuEstado == LOW)){
      tiempoOn = tiempoOn + 1;
       if(tiempoOn >= 60){
      tiempoOn = 0;
      lcd.clear();
   }
      delay(150);
   }

    if((subirEstado == LOW) && (bajarEstado == HIGH) && (menuEstado == LOW)){
      tiempoOn = tiempoOn - 1;
       if(tiempoOn <= 0){
      tiempoOn = 59;
      lcd.clear();
   }
   delay(150);
  }
 }
 // ***************** 5 Ajustar Tiempo Apagado en Minutos ***********************************
   if(contador == 3){
    lcd.setCursor(0, 0);
    lcd.print("Ajustes ");
    lcd.print(contador - 1);
    lcd.print(" de 5 ");
    lcd.setCursor(0, 1);
    lcd.print("Tiempo Off ");
    lcd.print(tiempoOff);
    lcd.print(" m");

    if((subirEstado == HIGH) && (bajarEstado == LOW) && (menuEstado == LOW)){
      tiempoOff = tiempoOff + 1;
       if(tiempoOff >= 256){
      tiempoOff = 0;
      lcd.clear();
   }
      delay(150);
   }

    if((subirEstado == LOW) && (bajarEstado == HIGH) && (menuEstado == LOW)){
      tiempoOff = tiempoOff - 1;
       if(tiempoOff <= 0){
      tiempoOff = 255;
      lcd.clear();
   }
      delay(150);
   }
}

// ******************** set point ********************************************
 if(contador == 4){
    lcd.setCursor(0, 0);
    lcd.print("Ajustes ");
    lcd.print(contador - 1);
    lcd.print(" de 5 ");
    lcd.setCursor(0, 1);
    lcd.print("SP = ");
    lcd.print(setpoint);
    lcd.print(" C");

    if((subirEstado == HIGH) && (bajarEstado == LOW) && (menuEstado == LOW)){
      setpoint = setpoint + 0.01;
       if(setpoint > 41){
      setpoint = 19;
      lcd.clear();
   }
      delay(150);
   }

    if((subirEstado == LOW) && (bajarEstado == HIGH) && (menuEstado == LOW)){
      setpoint = setpoint - 0.01;
       if(setpoint < 19){
      setpoint = 41;
      lcd.clear();
   }
      delay(50);
   }
}
//*********************            Histeresis          *********************************
if(contador == 5){
    lcd.setCursor(0, 0);
    lcd.print("Ajustes ");
    lcd.print(contador - 1);
    lcd.print(" de 5 ");
    lcd.setCursor(0, 1);
    lcd.print("Histeresis:");
    lcd.print(histeresis);

    if((subirEstado == HIGH) && (bajarEstado == LOW) && (menuEstado == LOW)){
      histeresis = histeresis + 0.01;
       if(histeresis > 0.1){
      histeresis = 0.01;
      lcd.clear();
   }
      delay(150);
   }

    if((subirEstado == LOW) && (bajarEstado == HIGH) && (menuEstado == LOW)){
      histeresis = histeresis - 0.01;
       if(histeresis < 0.01){
      histeresis = 0.1;
      lcd.clear();
   }
      delay(150);
   }
}

//**************************         coeficiente Beta         ***********************
if(contador == 6){
    lcd.setCursor(0, 0);
    lcd.print("Ajustes ");
    lcd.print(contador - 1);
    lcd.print(" de 5 ");
    lcd.setCursor(0, 1);
    lcd.print("beta = ");
    lcd.print(beta);

    if((subirEstado == HIGH) && (bajarEstado == LOW) && (menuEstado == LOW)){
      beta = beta + 10;
       if(beta > 5000){
      beta = 2500;
      lcd.clear();
   }
      delay(150);
   }

    if((subirEstado == LOW) && (bajarEstado == HIGH) && (menuEstado == LOW)){
      beta = beta - 10;
       if(beta < 2500){
      beta = 5000;
      lcd.clear();
   }
      delay(150);
   }
}
// ******************** Algoritmo Para guardar la información *****************************
 if(contador == 7){
  menuEstado = LOW;
  lcd.setCursor(0, 0);
    lcd.print("Guardar?");
    lcd.setCursor(0, 1);
    lcd.print("SI / NO ");
  subirEstado = digitalRead(subir);
  bajarEstado = digitalRead(bajar);
  menuEstado = digitalRead(menu);
  if((subirEstado == LOW) && (bajarEstado == HIGH) && (menuEstado == LOW )){
    lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("No se Guardo");
  delay(600);
  lcd.clear();
      contador = 1;
      }
  if((subirEstado == LOW) && (bajarEstado == LOW) && (menuEstado == LOW )){
      guardarInfo = 0;
      }
      
  if((subirEstado == HIGH) && (bajarEstado == LOW) && (menuEstado == LOW )){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Guardando");
      lcd.setCursor(0, 1);
      lcd.print(guardarInfo + 1);
      lcd.print('/');
      lcd.print(intervalo);
      lcd.print(' ');
      lcd.print(variables[guardarInfo]);
      guardarInfo = guardarInfo + 1;
      delay(250);
      if(guardarInfo == intervalo){
        guardar();
      }
     }
 }
// ***********************************************************************************
}

