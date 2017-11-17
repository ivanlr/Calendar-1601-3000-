/************************************
* NOMBRE: #Ivan#
* PRIMER APELLIDO: #Lopez#
* SEGUNDO APELLIDO: #Ripoll#
* EMAIL: #ivanlrojales@gmail.com#
*************************************/
#include <stdio.h>

int anyo_bisiesto(int i)
{
	if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
	    {return 1;}
    else
        {return 0;}
}




/**
 * Esta función devuelve qué día fue el 1 de enero del año anyo.
 * Para lunes devuelve 0.
 * Para martes devuelve 1.
 * Para miércoles devuelve 2.
 * Para jueves devuelve 3.
 * Para viernes devuelve 4.
 * Para sábado devuelve 5.
 * Para domingo devuelve 6.
 */

int uno_enero_anyo(int anyo)
{
	int dias = 0;
  int j = 1601;
  while(j<anyo){
		if (anyo_bisiesto(j))
		   {
		     dias = dias +2;
		   }
		else
		   {
		     dias = dias+1;
       }
       j++;
	}

	return (dias % 7);
}

int dias_que_tiene_mes(int mes, int anyo)
{
	switch(mes)
	{
		// Meses con 31 dias.
		case 0:
		case 2:
		case 4:
		case 6:
		case 7:
		case 9:
		case 11:
			return 31;
			break;

		// Caso especial de febrero.
		case 1:
			if(anyo_bisiesto(anyo))
				{return 29;}
			else
				{return 28;}
				break;

		// Resto de meses: los que tienen 30 dias.
		default:
      return 30;
	}
}

/*
 * Devuelve el dia (de 0 -lunes- a 6 -domingo-) en que comienza el mes mes en
 * el anyo anyo, sabiendo que el dia 1 de enero del anyo anyo fue comienzo.Y teniendo en cuenta que si un mes
 * empieza en el dia_mes 2 -miercoles-, si hacemos la operacion (dia_mes + dias_del_mes)%7 te da el dia en que
 * comienza el mes siguiente.
 */
int dia_comienzo_mes(int comienzo, int mes, int anyo)
{
  int dia_mes = comienzo;
	int dias_del_mes;

  for (int i = 0; i < mes; i++)
  {
		dias_del_mes = dias_que_tiene_mes(i, anyo);
		dia_mes = (dia_mes+dias_del_mes)% 7;
	}

	return dia_mes;
}
void escribir_mes(int mes)
{
  switch(mes)
  {
    case 0:printf("ENERO                  ");break;
    case 1:printf("FEBRERO                ");break;
		case 2:printf("MARZO                  ");break;
		case 3:printf("ABRIL                  ");break;
		case 4:printf("MAYO                   ");break;
		case 5:printf("JUNIO                  ");break;
		case 6:printf("JULIO                  ");break;
		case 7:printf("AGOSTO                 ");break;
		case 8:printf("SEPTIEMBRE             ");break;
		case 9:printf("OCTUBRE                ");break;
		case 10:printf("NOVIEMBRE              ");break;
		case 11:printf("DICIEMBRE              ");break;
  }
}
//Pinta el calendario.
void pintar_calendario(int anyo, int mes, int dia_comienzo, int dias_del_mes)
{
  //Como hay que dejar un espacio a la izquierda en cada linea, lo dejamos en esta parte que será fija.
  printf("");escribir_mes(mes);printf("%d\n",anyo);
  printf("===========================\n");
  printf("LU  MA  MI  JU  VI | SA  DO\n");
  printf("===========================\n");
  printf(" ");

  //Pintamos los puntos hasta llegar al dia de comienzo del mes.
  for(int k = 0; k < dia_comienzo; k++)
  {
    // Si el dia en cuestion, es el cuarto, pintamos la |.
    if(k==4)
    {
      printf(". |  ");
    }else{
    printf(".   ");}
  }

  for(int i = 0; i< dias_del_mes; i++)
  {
    //Si el numero del dia a pintar, i+1,  es menor que nueve dejamos un espacio en blanco más que si no lo fuera.
    if(i+1<9)
    {
      //Si el numero de dia a pintar mas el dia de comienzo es igual a 4, o el mismo dia de la siguiente semana, 4+7, 4+7+7, 4+7+7+7, 4+7+7+7+7,
      // entonces pintamos la |.
      if((i+dia_comienzo)==4 || (i+dia_comienzo)==11 || (i+dia_comienzo)==18 || (i+dia_comienzo)==25 || (i+dia_comienzo)==32)
      {
        printf("%d |  ", i+1);
      }else{
      printf("%d   ", i+1);}
      //Si hemos pintado 7 dias, incluyendo los puntos, entonces hacemos un salto de linea.
      if((i+dia_comienzo+1)%7==0)
      {
        printf("\n ");
      }
    }
    ////Si el numero del dia a pintar, i+1,  es mayor o igual que nueve dejamos un espacio en blanco menos que si no lo fuera.
    else
    {
      if((i+dia_comienzo)==4 || (i+dia_comienzo)==11 || (i+dia_comienzo)==18 || (i+dia_comienzo)==25 || (i+dia_comienzo)==32)
      {
        printf("%d | ", i+1);
      }else{
      printf("%d  ", i+1);}
      if((i+dia_comienzo+1)%7==0)
      {
        printf("\n");
      }
    }
  }
  //Pintamos los puntos en los dias que sobren para acabar el mes.
  //Si el mes ocupa 5 semanas. Y ademas vemos que el mes no sea febrero y comience por lunes, porque ocuparía 4 semanas.
  if(dia_comienzo+dias_del_mes<=35 && (dia_comienzo!=0 || dias_del_mes!=28)){
    for(int j = 0; j < (35-dia_comienzo - dias_del_mes); j++)
    {
      if(j==(35-dia_comienzo - dias_del_mes-3))
      {
        printf(" . | ");
      }else
      {
        printf(" .  ");
      }
    }
  }
  //Si el mes ocupa 6 semanas y no 4.
  else if(dia_comienzo+dias_del_mes<=42 && (dia_comienzo!=0 || dias_del_mes!=28))
  {
    for(int j = 0; j < (42-dia_comienzo - dias_del_mes); j++)
    {
      if(j==(42-dia_comienzo - dias_del_mes-3))
      {
        printf(" . | ");
      }
      else
      {
        printf(" .  ");
      }
    }
  }
}
int main()
{
  int anyo;
  int mes;
  int dia;

  printf ("¿Mes (1..12)?");
  scanf ("%d", &mes);
  if(mes<1 || mes>12)
  {
    return -1;
  }
  mes--;
  printf ("¿Año (1601..3000)?");
  scanf ("%d", &anyo);
  if(anyo<1601 || anyo>3000)
  {
    return -1;
  }

  dia = uno_enero_anyo(anyo);
  pintar_calendario(anyo, mes, dia_comienzo_mes(dia, mes, anyo), dias_que_tiene_mes(mes, anyo));

  return 0;
}
