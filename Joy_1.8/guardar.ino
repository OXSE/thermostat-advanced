#include <EEPROM.h>

void guardar(){
  // ********** Preparacion de variables para guardar en memoria EEPROM *********
 
  // 3. SETPOINT
  digitosSP = setpoint * 100;
  spDec = digitosSP/1000;
  spUni = (digitosSP - (spDec * 1000))/100;
  spDms = (digitosSP - (spDec * 1000) - (spUni * 100))/10;
  spCtm = digitosSP - (spDec * 1000) - (spUni * 100) - (spDms * 10);
  
  // 4. HISTERESIS
  digitosHisteresis = histeresis * 100;
  histeresisDec = digitosHisteresis / 10;
  histeresisCen = digitosHisteresis - (histeresisDec * 10);
  
  // 5. BETA
  digitosBeta = beta;
  betaMillares = digitosBeta / 1000;
  betaCentenas = (digitosBeta - (betaMillares * 1000)) / 100;
  betaDecenas = (digitosBeta - (betaMillares * 1000) - (betaCentenas * 100)) / 10;
  betaUnidades = digitosBeta - (betaMillares * 1000) - (betaCentenas * 100) - (betaDecenas * 10);
  
  // **************************                 1. Tiempo ON          ****************************
      EEPROM.write(eepromTiempoOn, tiempoOn);
      
      // **********************                 2. Tiempo Off           ***************************
      EEPROM.write(eepromTiempoOff,tiempoOff);
      
      // **********************                 3. Setpoint           ***************************
      EEPROM.write(eepromSetPointDecenas, spDec);
      EEPROM.write(eepromSetPointUnidades, spUni);
      EEPROM.write(eepromSetPointDecimas, spDms);
      EEPROM.write(eepromSetPointCentesimas, spCtm);
      
      // **********************                 4. Histeresis           ***************************
      EEPROM.write(eepromHisteresisUnidades, histeresisUni);
      EEPROM.write(eepromHisteresisDecimas, histeresisDec);
      EEPROM.write(eepromHisteresisCentesimas, histeresisCen);
      
      // **********************                 5           ***************************
      EEPROM.write(eepromBetaMillares, betaMillares);
      EEPROM.write(eepromBetaCentenas, betaCentenas);
      EEPROM.write(eepromBetaDecenas, betaDecenas);
      EEPROM.write(eepromBetaUnidades, betaUnidades);
      
// *********************************************************************
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Guardado");
      contador = 1;
      delay(1000);
}

