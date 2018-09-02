#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#define base 2



int cambiobin(int numero, int *contaf);//prototipos de funciones

int complemento1(int *apunta, int conta2);

int complemento2(int *apunta, int conta2);

int bindecimal(char *binario, int elemento);

int main(int argc, char *argv[])

{

	int numerodecimal, *apunta, contaf=0, conta, *complementouno, *complementodos, nbits;

	char caso, caso2;

	printf("\n\nPrograma que convierte de decimal a binario, saca los complementos y viceversa\n\n");

	printf("\n\t1 ==> Para pasar de decimal a binario y sacar sus complementos\n");

	printf("\n\t2 ==> Para pasar de binario a decimal\n");

	printf("\nSelecciona una opcion: ");

	scanf("%c", &caso);

	switch (caso)

	{

		case '1':

		printf("\nIngresa el numero a convertir a binario: ");

		scanf("%d", &numerodecimal);

		while(numerodecimal < 0)

		{

			puts("\nEl numero debe ser positivo");

			printf("\nIntroduce el numero a convertir: ");

			scanf("%d", &numerodecimal);

		}

		apunta=cambiobin(numerodecimal, &contaf);

		printf("\nEl numero en binario es: ");

		for(conta=0; conta < contaf; conta++)

		{

		   printf("%d", apunta[conta]);

		}

		complementouno=complemento1(apunta, contaf);

		printf("\nEl numero en complemento a uno es: ");

		for(conta=0; conta < contaf; conta++)

		{

		   printf("%d", complementouno[conta]);

		}

		complementodos=complemento2(apunta, contaf);

		printf("\nEl numero en complemento a dos es: ");

		for(conta=0; conta < contaf; conta++)

		{

		   printf("%d", complementodos[conta]);

		}

		break;

		case '2':

		printf("\n\t1 ==> Para pasar de binario a decimal\n");

		printf("\n\t2 ==> Para pasar de binario en complemento a uno a decimal\n");

		printf("\n\t3 ==> Para pasar de binario en complemento a dos a decimal\n");

		printf("\nSelecciona una opcion: ");

		getchar();

		scanf("%c", &caso2);

		getchar();

		printf("\nDe cuantos bits es tu numero: ");

		scanf("%d", &nbits);

		switch (caso2)

		{

			int elementos, decimal = 0;

			char *cadena;

			double binario;

			case '1':

			if(cadena==NULL)

			{

				puts("\nMemoria insuficiente");

				getchar();

				getchar();

				exit(0);

			}

			printf("\ningresa el numero en binario: ");

			scanf("%lf", &binario);

			cadena=(char*)malloc(nbits*sizeof(char));

 			sprintf(cadena,"%1.0f",binario);

			elementos = strlen(cadena); 

			decimal=bindecimal(cadena, elementos);

			printf("\nEl %.0lf en decimal es: %d", binario,decimal);

			break;

			case '2':

			printf("\ningresa el numero binario en complemento a uno: ");

			scanf("%lf", &binario);

			cadena=(char*)malloc(nbits*sizeof(char));

 			sprintf(cadena,"%1.0f",binario);

			elementos = strlen(cadena); 

			decimal=bindecimal(cadena, elementos);

			printf("\nEl %.0lf en decimal es: %d", binario,decimal);

			break;

		}

		break;

	}

	getchar();

	getchar();

}

int cambiobin(int numero, int *contaf)

{

	int residuo, *binario=NULL, *resultado=NULL, conta=0, tamano, contador, conta2=0;



	if (numero == 0)

	{

		//puts("\nEl numero en binario es: 0");

		resultado= (int*) malloc(sizeof(int));

		resultado[conta2]=0;

		conta2++;

	}

	else

	{

		//num=numero;

		contador=numero;

		while(contador > 0)

		{

			contador=contador/2;

			conta++;

		}

		tamano=conta;

		conta=0;

		binario= (int*) malloc(tamano*sizeof(int));

		resultado= (int*) malloc(tamano*sizeof(int));

		if(binario==NULL || resultado==NULL)

		{

			puts("\nmemoria insuficiente...!");

			getchar();

			getchar();

			exit(0);

		}

		while(numero > 0)

		{

			residuo=numero % base;

			binario[conta]=residuo;

			conta++;

			numero=numero/base;

		}

		//printf("el cambio de %d a base %d es: ", numero, base);

		for(conta=conta-1; conta >= 0; conta--)

		{

		  //printf("%d", binario[conta]);

		 resultado[conta2]=binario[conta];

		 conta2++;

		}

		//*contaf=conta2;

		  /*for(conta=0; conta < conta2; conta++)

		  {

		   	printf("%d", resultado[conta]);

		  }*/

	 	  //printf("\nRESULTADO TIENE: %d", resultado[0]);

	}

	*contaf=conta2;

	return (resultado);

}

int complemento1(int *apunta, int conta2)

{

	int conta, *complemento1;

	complemento1= (int*) malloc(conta2*sizeof(int));

	if(complemento1==NULL)

	{

		puts("\nMemoria insuficiente...!");

		getchar();

		getchar();

		exit(0);

	}

	for(conta=0; conta < conta2; conta++)

	{

	   if(apunta[conta] == 1)

	   {

	   	complemento1[conta]=0;

	   }

	   else

	   {

	   	complemento1[conta]=1;

	   }

	}

	return (complemento1);

}

int complemento2(int *apunta, int conta2)

{

	int conta=0, *complemento2,primeruno=0;

	complemento2= (int*) malloc(conta2*sizeof(int));

	if(complemento2==NULL)

	{

		puts("\nMemoria insuficiente...!");

		getchar();

		getchar();

		exit(0);

	}

	conta=conta2-1;

	for(conta2=conta2-1; conta2 >= 0; conta2--)

	{

	   if(primeruno == 0)

	   {

		   if(apunta[conta2] == 0)

		   {

		   	complemento2[conta]=0;

		   	conta--;

		   }

		   else

		   {

		   	complemento2[conta]=1;

		   	conta--;

		   	primeruno++;

		   }

		}

		else

		{

			if(apunta[conta2] == 1)

		   {

		   	complemento2[conta]=0;

		   	conta--;

		   }

		   else

		   {

		   	complemento2[conta]=1;

		   	conta--;

		   }

		}

	}

	return(complemento2);

}

int bindecimal(char *binario, int elemento)

{

	int decimal = 0, operando = 1;

	for(--elemento; elemento >= 0; elemento-- ){

		if( binario[elemento] == '1' ){

			decimal += operando; 

		}

		operando *= 2;

	}

	return(decimal);

}
