int subirEstado;
int bajarEstado;
int menuEstado;


void configuracion(){
  subirEstado = digitalRead(subir);
  bajarEstado = digitalRead(bajar);
  menuEstado = digitalRead(menu);
  if((subirEstado == LOW) && (bajarEstado == LOW) && (menuEstado == HIGH)&& (contador < 7)){
     contador = contador + 1;
     delay(200);
   lcd.clear();
   }
   if((contador > 7) || (contador <1)){
    contador = 1;
   }  
   pantalla();
}

  
