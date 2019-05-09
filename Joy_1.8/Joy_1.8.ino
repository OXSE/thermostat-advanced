  // include the library code:
#include <LiquidCrystal.h>
#define resistenciaPin 1
#define motorPin 2  
#include <avr/wdt.h>
//#define calibracion A44w
#define numeroMuestras 20

uint16_t muestras[numeroMuestras];
uint8_t j;
double promedioCalibracion;
double factorX = 0.0391006843;
double setpoint = 37.7;
double histeresis = 0.025;
char* variables[]={"time on", "time off", "setpoint",
"histeresis", "beta"};

int k;

unsigned long previousMillis = 0;        // will store last time LED was updated
unsigned long currentMillis = 0;        // will store last time LED was updated
const long interval = 1000;           // interval at which to blink (milliseconds)
int minutos = 0;
int segundos = 0;
int motorState;
int guardarInfo;
int intervalo = 5;
   
// variables para guardar informacion de la configuracion ****************************
// variables auxiliares
int Idigitos_temperatura;
int cuenta;
int contadorDisplay = 300;
int Sdigitos_temperatura;

// 1. Tiempo ON
int tiempoOn = 10; // segundos

// 2. Tiempo OFF
int tiempoOff = 11; // minutos

// 3. Set-Point
int spDec;
int spUni;
int spDms;
int spCtm;
int digitosSP;

// 4. Histeresis
int histeresisUni;
int histeresisDec;
int histeresisCen;
int digitosHisteresis;

// 5. Coeficiente Beta
int betaMillares; 
int betaCentenas;
int betaDecenas;
int betaUnidades;
int digitosBeta;

// ********************************************* VARIABLES EEPROM

// 1. EEPROM TIEMPO OFF
int eepromTiempoOn = 1; 

// 2. EEPROM TIEMPO OFF
int eepromTiempoOff = 2;

// 3. EEPROM SETPOINT
int eepromSetPointDecenas = 3;
int eepromSetPointUnidades = 4;
int eepromSetPointDecimas = 5;
int eepromSetPointCentesimas = 6;

// 4. EEPROM HISTERESIS
int eepromHisteresisUnidades = 7;
int eepromHisteresisDecimas = 8;
int eepromHisteresisCentesimas = 9;

// 5. BETA
int eepromBetaMillares = 20;
int eepromBetaCentenas = 21;
int eepromBetaDecenas = 22;
int eepromBetaUnidades = 23;

// *****************************************************************************
double temperatura;
const int subir = 11;
const int bajar = 12;
const int menu = 13;

int contador = 1;

// El coeficiente beta del termistor (usualmente 3000-4000)
int beta = 3950;

double tMax = 37.80;
double tMin = 37.77;

// inicializamos la libreria LiquidCrystal
const int rs = 8, en = 7, d4 = 6, d5 = 5, d6 = 4, d7 = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //pin real: rs = 14, E = 13, D4 = 12, D5 = 11, D6 = 6, D7 = 2

void setup() {
  
  cuenta = 0;
  // ******************************************************** Watch Dog
  wdt_disable();    // Sumamente importante, para desabilitar el WDT
  // ******************************************************** Watch Dog
  pinMode(resistenciaPin, OUTPUT);
  digitalWrite(resistenciaPin, HIGH);
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, HIGH);
  pinMode(subir, INPUT);
  pinMode(bajar, INPUT);
  pinMode(menu, INPUT);
  lcd.begin(16, 2); 
  bienvenida();
  inicializar();
  // ******************************************************** Watch Dog
  wdt_enable(WDTO_8S); // habilitamos el reloj de arena a 8 segundos
  // ******************************************************** Watch Dog
  j = 0;
}

void loop() {
  digitalWrite(motorPin, !motorState);
  //digitalWrite(motorPin, motorState);
  reloj();
  temperatura = temperaturaC();
  control(temperatura); 
  configuracion();
  // ******************************************************** Watch Dog 
  wdt_reset(); // sino regreso en 8 segundos llama a reset
  // ******************************************************** Watch Dog
}
