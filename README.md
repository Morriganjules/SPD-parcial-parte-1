# Integrantes

 - Luciano Figueroa. 
 - Julian Ferreira.
 -  Federico Palacio.

# Proyecto contador


![Proyecto Parte 1](proyecto%20parte%201.jpg)

## Descripcion

Este proyecto consta de un contador de numeros que va del 0 al 99. El mismo utiliza multiplexacion para poder utilizar dos displays de 7 segmentos. El usuario puede presionar 3 botones, estos son para aumentar o disminuir el conteo, yendo de uno en uno. Tambien el usuario puede presionar un tercer boton para reiniciar el conteo.

## Funcionamiento
Estas  son las funciones pricipales, por su parte printCount() se encarga de la multiplexacion, encendiendo y apagando los displays de 7 segmentos y en la funcion loop(), nos encargamos de recibir la informacion de que boton a sido presionado y de realizar con esa informacion el proceso adecuado (sumar, restar o reiniciar).

```  
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

void printCount(int count){
	prenderDigito(apagados);
  	printDigit(cuenta/10);
  	prenderDigito(decimas);
  	prenderDigito(apagados);
  	printDigit(cuenta - 10*((int)cuenta/10));
    prenderDigito(unidades);
} 
```

## Link del proyecto
[Proyecto tinkecad](https://www.tinkercad.com/things/5iz93c2jmh9-parcial-parte-1-/editel?sharecode=QYWzCuwdfJBvA7Sbo7mJ39WblqAxKO_rH9pPV3BmdcY)
