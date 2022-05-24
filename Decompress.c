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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "HuffmanHash.h"
#include "HuffmanHeap.h"
#include "HuffmanTree.h"
#include "Decompress.h"
#include "Compress.h"
#include "types.h"



int is_bit_i_set(unsigned char byte, int i){ return (byte & (1 << i)); }

long long int FileSize(FILE *in)
{
	long long int bytes;
	if (in != NULL)
	{
		fseek(in, 0, SEEK_END);
		bytes = ftell(in);
	}
	return bytes;
}


void decompress_menu(char filename[], char outputname[])
{
	system("clear");
	printf("\nInsert the file name to be decompressed:\n");
	scanf("%s", filename);

	printf("\nInsert the output file name:\n");
	scanf("%s", outputname);
	printf("\n");
}

void decompress()
{
	
	FILE *in;
	FILE *out;
	char filename[100] = "";
	char outputname[100] = "";
	
	decompress_menu(filename,outputname);

	in = fopen(filename, "rb");

	if (in == NULL)
	{
		printf("\n%s\"File not Found!\n", filename);

		printf("\nPress any key to restart the process.\n");
		getchar();
		getchar();
		decompress();
		return;
	}

	
	out = fopen(outputname, "wb");



	char s;
	long long int  bytes = FileSize(in);

	fclose(in);

	in = fopen(filename, "rb");

	unsigned char a, b, trash;
    fscanf(in, "%c%c", &a, &b);
    trash = a>>5;
    a = a<<3;  //retiro o lixo
    a = a>>3;  //deixa 0  no lugar do lixo
    short int tam_arv = a;
    tam_arv = tam_arv<<8;  //abro espaco para o b ser somado
    tam_arv |= b;

    bytes = bytes - (tam_arv + 2);  //os bytes da arvore mais os dois do comeco

	Huff_node* raiz;
	
	raiz = create_tree_from_preorder(in);

	///////////////

	

	int i, j;

	Huff_node* aux =  raiz;

	for(i = 1; i <= bytes; i++)                   //roda byte a byte
	{
		fscanf(in, "%c", &s);                     //continua leitura de onde parou
		for(j = 7; j >= 0; j--)                   //roda bit a bit
		{
			if(j == (trash - 1) && (i == bytes)) break;  //trash - 1, indica a posiçao do byte onde inicia-se o lixo, e se esta no ultimo byte
			if(is_bit_i_set(s, j)) raiz = raiz -> down_right;       //percorre a arvore para salvar os itens originais
			else raiz = raiz -> down_left;                          //percorre a arvore para salvar os itens originais

			if(raiz -> down_right == NULL && raiz -> down_left == NULL)
			{
				fputc(*(unsigned char*)raiz -> item, out);
				raiz = aux;
			}
		}
	}

	
	system("clear");
	
	printf("\nDone.\n\n");
	return;
}