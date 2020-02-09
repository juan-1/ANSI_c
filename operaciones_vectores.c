/*programa 1; Lenguajes de programacion*/
/*Programa para hacer operaciones con DOS vectores */
#include<stdio.h> // salida y entrada estandar
#include <stdlib.h>// para manejo de memoria dinamica 
#include <math.h> //para la funcion sqrt, pow, acos
#define tam 10    //tamano de componentes del vector

main()//funcion principal
{
 	  int conta, dimension;// declaracion de variables enteras
 	  float escalar;//escalar por el cual seran multiplicados los vectores
      
      puts("\n\t\tPrograma que hace operaciones entre dos vectores");//informacion de lo que hace el programa
      printf("\n\nIngresa la dimension de los vectores: ");//solicita la dimension de los vectores
      scanf("%d", &dimension);//se obtiene la dimension de los vectores dada por el usuario

      float *vector1[dimension]; //apuntador para almacenar las componentes del vector 1
      float *vector2[dimension];// apuntador para almacenar las componentes del vector 2
      float *componente;//apuntador para obtener la componente de un vector 
      
    for(conta = 0; conta < dimension; conta++)
	{
		printf("\ningresa la componente: %d del vector 1:  ", conta+1);//solicita las componentes del vector 1
		componente=(float*) malloc(tam);//se reserva memoria para la componente
		if (componente == NULL)//si regresa NULO el apuntador es porque no hay espacio en memoria
		{
  		   puts("\nLO SIENTO, MEMORIA INSUFICIENTE...!");//mensaje al usuario 
  		   exit(0);//termina la ejecucion del programa
  		   getchar();//mantiene en espera la consola
  		}
		scanf("%f", componente);//se obtiene la componente del vector dada por el usuario
		vector1[conta] = componente;//se almacena la componente en el vector
	}

	for(conta = 0; conta < dimension; conta++)
	{
		printf("\ningresa la componente: %d del vector 2:  ", conta+1);//solicita las componentes del vector 2
		componente=(float*) malloc(tam);
		if (componente == NULL)//si regresa NULO el apuntador es porque no hay espacio en memoria
		{
  		   puts("\nLO SIENTO, MEMORIA INSUFICIENTE...!");//mensaje al usuario 
  		   exit(0);//termina la ejecucion del programa
  		   getchar();//mantiene en espera la consola
  		}
		scanf("%f", componente);//se obtiene la componente del vector dada por el usuario
		vector2[conta] = componente;//se almacena la componente en el vector
	}
	
	printf("\nIngresa un escalar para multiplicar los vectores: ");// se solicita un escalar al usuario
	scanf("%f", &escalar);//se gusarda el valor dado
	
	puts("\nlos datos ingresados en el vector 1 son: \n");//se muestran los datos ingresados por el usuario para el vector 1
	printf("(");
	for(conta = 0; conta < dimension; conta++)
	{
		printf("%f", *vector1[conta]);
		if(conta < dimension-1)
		{
	 	 		 printf(",");
	 	}
	}
	puts(")");
	puts("\nlos datos ingresados en el vector 2 son: \n");//se muestran los datos ingresados por el usuario para el vector 2
	printf("(");
	for(conta = 0; conta < dimension; conta++)
	{
		printf("%f", *vector2[conta]);
		if(conta < dimension-1)
		{
	 	 		 printf(",");
	 	}
	}
	puts(")");
	
	//suma
	
	puts("\n\nEl vector suma es: \n");//se muestra el vector resultante de la suma de ambos vectores
	printf("(");
	for(conta = 0; conta < dimension; conta++)
	{
		printf("%f", *vector1[conta]+*vector2[conta]);
		if(conta < dimension-1)
		{
	 	 		 printf(",");
	 	}
	}
	puts(")");
	
	//Resta
	
	puts("\n\nEl vector resta es: \n");//se muestra el vector resultante de la resta de ambos vectores
	printf("(");
	for(conta = 0; conta < dimension; conta++)
	{
		printf("%f", *vector1[conta]-*vector2[conta]);
		if(conta < dimension-1)
		{
	 	 		 printf(",");
	 	}
	}
	puts(")");
	
	//multiplicacion por un escalar
	
	printf("\n\nEl vector 1 multiplicado por el escalar %f  es: \n\n", escalar);//se muestra al vector 1 multiplicado por el escalar
	printf("(");
	for(conta = 0; conta < dimension; conta++)
	{
		printf("%f", *vector1[conta]*escalar);
		if(conta < dimension-1)
		{
	 	 		 printf(",");
	 	}
	}
	puts(")");
	
	printf("\n\nEl vector 2 multiplicado por el escalar %f  es: \n\n", escalar);//se muestra al vector 2 multiplicado por el escalar
	printf("(");
	for(conta = 0; conta < dimension; conta++)
	{
		printf("%f", *vector2[conta]*escalar);
		if(conta < dimension-1)
		{
	 	 		 printf(",");
	 	}
	}
	puts(")");
	
	
	//Modulo de los vectores
	
	float suma1=0, modulo1, suma2=0, modulo2;// declaracion de variables flotantes
	
	for(conta = 0; conta < dimension; conta++)
	{
 	    suma1 = suma1 + pow(*vector1[conta], 2);//la suma de los cuadrados de las componentes del vector 1
	}
	
	modulo1 = sqrt(suma1);// se obtiene la raiz cuadrada de la suma de los cuadrados de las componentes del vector 1
	
	for(conta = 0; conta < dimension; conta++)
	{
 	    suma2 = suma2 + pow(*vector2[conta], 2);//la suma de los cudrados de las componentes del vector 2
	}
	
	modulo2 = sqrt(suma2);// se obtiene la raiz cuadrada de la suma de los cuadrados de las componentes del vector 2
	
	printf("\n\nNorma del vector 1: %f  \tNorma del vector 2: %f \n", modulo1, modulo2);//se muestra la norma de ambos vectores
	
	//Una forma de obtener el angulo entre dos vectores 
	
	// cos(x) = a punto b / norma(a) * norma(b)
	
	
	//producto punto
	

	float punto, sumapunto=0;//declaracion de variables flotantes
	
	for(conta = 0; conta < dimension; conta++)
	{
 	   punto = *vector1[conta] * *vector2[conta];// se multiplican las componentes de los vectores
 	   sumapunto = sumapunto + punto;//se suma el resultado de la multiplicacion entre componente a componente
 	   
	}
	
	
	//printf("\nEl producto punto es: %f", sumapunto);
	
	
	// Angulo entre vectores
	
	float angulo,  ang;//declaracion de variables flotantes
	
	ang = sumapunto / (modulo1 * modulo2);
	
	//printf("\n ang es: %f", ang);
	
	angulo = acos(ang); // funcion para obtener el angulo cuyo coseno de un numero 
	//el resultado lo entriega en RADIANES!! 
	
	printf("\n\nEl angulo entre los vectores es: %f GRADOS\n", angulo*57.29577951);
	
	// angulo se multiplica por 57.2957.. para mostrar el resultado en GRADOS!!
	
	
	
	free(vector1);//libera la memoria del apuntador vector1
	free(vector2);//libera la memoria del apuntador vector2
	free(componente);//libera la memoria del apuntador componente
	getchar();//cacha el enter del teclado
	getchar();//mantiene en espera la consola
	
	/*Programa realizado por: Juan Flores*/	  
}
