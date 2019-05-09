void inicializar(){
   // ************************   Leer variables de la eeprom *********************************
  tiempoOn = EEPROM.read(eepromTiempoOn);
  tiempoOff = EEPROM.read(eepromTiempoOff);
  
  spDec = EEPROM.read(eepromSetPointDecenas);
  spUni = EEPROM.read(eepromSetPointUnidades);
  spDms = EEPROM.read(eepromSetPointDecimas);
  spCtm = EEPROM.read(eepromSetPointCentesimas);

  histeresisDec = EEPROM.read(eepromHisteresisDecimas);
  histeresisCen = EEPROM.read(eepromHisteresisCentesimas);

  betaMillares = EEPROM.read(eepromBetaMillares);
  betaCentenas = EEPROM.read(eepromBetaCentenas);
  betaDecenas= EEPROM.read(eepromBetaDecenas);
  betaUnidades = EEPROM.read(eepromBetaUnidades);
  
  // ******************** INICIALIZAR VARIABLES *****************************
  // 3. SETPOINT
  setpoint = (spDec* 10) + spUni + (spDms * 0.1) + (spCtm * 0.01);

  // 4. HISTERESIS
  histeresis = (histeresisDec * 0.1) + (histeresisCen * 0.01);
  
  // 5. BETA
  beta = (betaMillares * 1000) + (betaCentenas * 100) + (betaDecenas * 10) + betaUnidades;
 }

