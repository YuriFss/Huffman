/*////////////INFO//////////////////////
 *
* # Projeto-P2-Huffman
	Projeto para Estrutura de Dados (Huffman);
	Universidade Federal de Alagoas - Instituto de Computação;
	ECOM-008/COMP208 - Estrutura de Dados.

	
	Darlysson Olímpio Nascimento - don@ic.ufal.br;
	Felipe Pimentel de Cerqueira - fpc@ic.ufal.br;
	Yuri Fernandes Souza Silva	 - yfss@ic.ufal.br;
	

	Inicio em:
	11 de Março de 2019, Maceió - AL, Brasil
*/

/////////////START OF C FILE///////////////////

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "HuffmanHash.h"
#include "HuffmanHeap.h"
#include "HuffmanTree.h"
#include "Compress.h"
#include "Decompress.h"
#include "types.h"


void presentation()
{
	printf("\n\n\n");
	printf("                                 | | | |_   _ / _|/ _|_ __ ___   __ _ _ __\n");
	printf("                                 | |_| | | | | |_| |_| '_ ` _ \\ / _` | '_ \\\n"); 	
	printf("                                 |  _  | |_| |  _|  _| | | | | | (_| | | | | \n");
	printf("                                 |_| |_|\\__,_|_| |_| |_| |_| |_|\\__,_|_| |_|\n");
	
	
	printf("                             ------------- Press any key to start -------------\n\n\n");
	printf("                                               Developed by:\n");
	printf("  Darlysson Olimpio Nascimento | Felipe Pimentel de Cerqueira | Yuri Fernandes Souza Silva \n");
	getchar();
}

int main ()
{
	presentation();
	system("clear");
	int c;
	int menu;
	printf("Press '1' to compress, Or press '2' to decompress.\n");
	scanf("%d", &menu);

	if(menu == 1) compress();
	else if(menu == 2) decompress();
	else printf("Invalid option! Run the program again.\n");

	return 0;
}
