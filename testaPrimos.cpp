#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <thread>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//
//  TestaPrimo.c
//  TestaPrimo
//
//  Created by Ricardo de Carvalho Destro on 12/08/20.
//  Copyright Â© 2020 Ricardo de Carvalho Destro. All rights reserved.
//

#include "TestaPrimo.h"

/* Convencao: EhPrimo = 1 se o numero dado 'e primo */
/*  EhPrimo = 0 se o numero dado nao 'e primo       */


int TestaPrimo1(int n) {
    int EhPrimo = 1, //em princÃ­pio, n Ã© primo
        d=2;
    if (n <= 1)
    EhPrimo = 0;

    while (EhPrimo == 1 && d <= n / 2) {
    if (n % d  == 0)
        EhPrimo = 0;
    d = d + 1;
    }
    return EhPrimo;
}


int TestaPrimo2(int n) {
    
    int EhPrimo = 1, //em princÃ­pio, n Ã© primo
        d=2,
        resto;
    if (n <= 1)
        EhPrimo = 0;

     while (EhPrimo == 1 && d <= n / 2) {
      resto = n % d;
          if (resto == 0)
              EhPrimo = 0;
          d = d + 1;
      }
    return EhPrimo;
}

int TestaPrimo3(int n) {
    
    int EhPrimo,
        d=3;
    if (n <= 1 || (n != 2 && n % 2 == 0))
        EhPrimo = 0;    /* nenhum numero inteiro <= 1 ou par > 2 e' primo */
    else
        EhPrimo = 1;        /* o numero e' primo ate que se prove o contrario */

    while (EhPrimo  && d <= n / 2) {
        if (n % d == 0)
            EhPrimo = 0;
        d = d + 2;        /* testar apenas Ã­mpares*/
    }
    return EhPrimo;
}


int TestaPrimo4(int n) {
    int EhPrimo, //em princÃ­pio, n Ã© primo
        d=3;
    if (n <= 1 || (n != 2 && n % 6 == 1 && n % 6 == 5))
        EhPrimo = 0;    /* nenhum numero inteiro <= 1 ou ~ adjacente a 6 eh primo */
    else
        EhPrimo = 1;
    while (EhPrimo  && d <= n / 2) {
        if (n % d == 0)
            EhPrimo = 0;
        d = d + 2;
        }
    return EhPrimo;
}
int calcula ( int p )
{
	int contador = 0; 
	int sum = 0; 
	int i = 0;
	using namespace std;
	
	if ( p > 5000 )
	{
		for ( i = p; i > 0; i--)
		{
			if( TestaPrimo4(i) == 1 )
			{
				sum = sum + i;
				contador++;
				printf("%d - %d \n", contador, i );
			}
			else if ( contador == 222 )
			{
				printf("\nA soma foi: %d\n", sum);	
				break;
			}	
		}
		clock_t tempo;
    	tempo = clock();
    	
    	printf("Tempo: %f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
	}
}

int main(int argc, char** argv) 
{
	
	//RA: 222160392
	int bbb = 160;
	int ccc = 392;
	int p = bbb * ccc; // 62720
	
	std::thread half1(calcula,p,(p/2));
	half1.join();
	std::thread half2(calcula,((p/2)-1),0);
	half2.join();
	


	
	calcula(p);
}

  

