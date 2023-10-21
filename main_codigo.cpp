// C++ code
//
#define A 10
#define B 11
#define C 5
#define D 6
#define E 7
#define F 9
#define G 8
#define buttonUp 2
#define buttonDown 3
#define buttonReset 4
#define unidades A4
#define decimas A5
#define apagados 0
int cuenta = 0;
int subePrevia = 1;
int bajaPrevia = 1;
int resetPrevia = 1;

//Se setean los outputs e inputs de los botones y de los displays de 7 segmentos
void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
  pinMode(buttonReset, INPUT_PULLUP);
  pinMode(unidades, OUTPUT);
  pinMode(decimas, OUTPUT);
  digitalWrite(unidades, 0);
  digitalWrite(decimas, 0);
}

//Dependiendo el valor que devuelva la funcion keypressed(), se sumara o restara o reiniciara el contador.
void loop()
{
  
  int pressed = keyPressed();
  
  if(pressed == buttonUp){
  	cuenta++;
    if(cuenta > 99){
    	cuenta = 0;
    }
  }
  else if(pressed == buttonDown){
  	cuenta--;
    if(cuenta < 0){
    	cuenta = 99;
    }
  }
  else if(pressed == buttonReset){
  	cuenta = 0;
  }
  
  printCount(cuenta);
}

//Esta funcion se encarga de la multiplexacion, encendiendo y apagando los leds de 7 segmentos, yendo primero por el de decimas y luego por el de unidades.
void printCount(int count){
	prenderDigito(apagados);
  	printDigit(cuenta/10);
  	prenderDigito(decimas);
  	prenderDigito(apagados);
  	printDigit(cuenta - 10*((int)cuenta/10));
    prenderDigito(unidades);
}

//Se encarga de decidir que led de 7 segmentos se va a encender
void prenderDigito(int digito){
  if(digito == unidades){
  	digitalWrite(unidades, LOW);
    digitalWrite(decimas, HIGH);
    delay(10);
  }
   else if(digito == decimas){
  	digitalWrite(decimas, LOW);
    digitalWrite(unidades, HIGH);
    delay(10);
  }
   else
   {
  	digitalWrite(unidades, HIGH);
    digitalWrite(decimas, HIGH);
  }
}

//Lee los valores que devuelven los botones y devuelve dependiendo si alguno fue pulsado o no el valor que fue presionado.
int keyPressed(void){
  int sube = digitalRead(buttonUp);
  int baja = digitalRead(buttonDown);
  int reset = digitalRead(buttonReset);
  
  if(sube){
  	subePrevia = 1;
  }
  if(baja){
  	bajaPrevia = 1;
  }
  if(reset){
  	resetPrevia = 1;
  }
  
  if(sube == 0 && sube != subePrevia){
  	subePrevia = sube;
    return buttonUp;
  }
  if(baja == 0 && baja != bajaPrevia){
  	bajaPrevia = baja;
    return buttonDown;
  }
  if(reset == 0 && reset != resetPrevia){
  	resetPrevia = reset;
    return buttonReset;
  }
  return 0;
}

//Apartir del numero que le llega por parametro se encarga de llamar a la funcion correspondiente.

void printDigit(int numero){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  
  switch(numero){
  	case 0:
    	show0();
    	break;
    case 1:
    	show1();
    	break;
    case 2:
    	show2();
    	break;
    case 3:
    	show3();
    	break;
    case 4:
    	show4();
    	break;
    case 5:
    	show5();
    	break;
    case 6:
    	show6();
    	break;
    case 7:
    	show7();
    	break;
    case 8:
    	show8();
    	break;
    case 9:
    	show9();
    	break;
  }
}

//Aca se encuentran las funciones para poder encender los leds correctos y mostrar los numeros correspodientes

void show0(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void show1(){
  digitalWrite(A, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  
}

void show2(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(G, HIGH);
  
  digitalWrite(C, LOW);
  digitalWrite(F, LOW);
}
void show3(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(G, HIGH);
  
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
}
void show4(){
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(F, HIGH);
  
  digitalWrite(A, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
}
void show5(){
  digitalWrite(A, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(F, HIGH);
  
  digitalWrite(B, LOW);
  digitalWrite(E, LOW);
}
void show6(){
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(G, HIGH);
  
  digitalWrite(B, LOW);
}
void show7(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}
void show8(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void show9(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  
  digitalWrite(E, LOW);
}
