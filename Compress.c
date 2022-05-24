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
#include "Compress.h"
#include "Decompress.h"
#include "types.h"




int number_of_bits (Huff_hash *ht)
{
	int bits = 0;
	int i;
	for(i = 0; i < 256; i++)
	    if(ht->table[i]->freq != 0) 
	    	bits += (ht->table[i]->bits * ht->table[i]->freq);

	    return bits;
}

int number_of_bytes(double bits){ return ceil(bits/8); }


#define num_prime 257



void create_header(int trash_size, int tree_size, Huff_node *tree, FILE* out)
{
	//printf("TRASH SIZE: %d | TREE SIZE: %d\n.", trash_size, tree_size);
	unsigned char* bytes = (unsigned char*)malloc(2 * sizeof(unsigned char));
	bytes[0] = trash_size << 5 | tree_size >> 8;   //trash_size esta representado no inicio do byte, importante joga-lo para os 3 primeiros, destacar >>8 em tree_size para add ao primeiro byte do arquivo trechos que formam o size_tree
	bytes[1] = tree_size;                          //salva as 8 primeiras posicoes do tree_size

	fputc(bytes[0], out);
	fputc(bytes[1], out);
	print_pre_order_file(tree, out);  //printa arvore no arquivo
}

void compress_menu(char filename[], char outputname[])
{
	system("clear");
	printf("\nInsert the name of the file to be compressed:\n");
	scanf("%s", filename);
	printf("\nInsert the compressed file name:\n");
	scanf("%s", outputname);
	printf("\n");
}

void test ()
{
	system("clear");
	printf("Do you want to decompress the generated file? 1 - Yes | 2 - No\n");
	int option;
	scanf("%d", &option);
	if (option == 1) decompress();
	else
	{
		system("clear");
		printf("\nDone.\n\n");
		return;
	}
}


void compress()
{
	
	
	FILE *in;
	FILE *out;

	char filename[100] = "";
	char outputname[100] = "";
	compress_menu(filename,outputname);

	in = fopen(filename, "rb");
	if (in == NULL)
	{
		printf("\n%s\" not Found!\n", filename);
		printf("\nPress any key to restart the process.\n");
		getchar();
		getchar();
		compress();
		return;
	}
	
	out = fopen(outputname, "wb");



	int i, size;
	unsigned char s;
	unsigned int shift_bit = 0;
	long long int freq[256] = {0}; 
	
	while (fscanf(in, "%c",&s) != EOF) 
		freq[s]++;    //CRIA ARRAY DE FREQUENCIAS
	fclose(in);
	
	Huff_heap *heap = create_heap();//CRIA A HEAP
	Huff_hash *ht = create_hash_table();//CRIA A HASH

	for(i = 0; i < 256; i++)
	{
		if(freq[i] != 0)
		{
			enqueue_heap(heap, &i, freq[i], NULL, NULL);
		}
		ht->table[i]->freq = freq[i];
	}
	
	i = 0;
	Huff_node *raiz;
	raiz = create_tree(heap);
	
	create_encoding(raiz, ht, shift_bit, 0);

	int bits = number_of_bits(ht);
	int bytes = number_of_bytes(bits);
	int trash = (bytes*8) - bits; //proximo a bits, porem a diferenca me da o lixo
	
	int size_of_tree = tree_size(raiz);
	if (freq[92] > 0) size_of_tree++;
	if (freq[42] > 0) size_of_tree++;

	create_header(trash, size_of_tree, raiz, out);//CALCULAR LIXO//E TAMANHO DA ARVORE

	in = fopen(filename, "rb");

	int control = 0;
	int empty_bits = 8;

	unsigned int char_byte; //byte do caracter na arvore
	unsigned char aux = 0;

	//COMPRESS
	while (fscanf(in, "%c", &s) != EOF)
	{
		control = ht -> table[s] -> bits;  //caracter s me mostra a qual estou me referindo na hash
		empty_bits = empty_bits - control;
		char_byte = ht -> table[s] -> shift_bit;
		
		if(empty_bits <= 0)
		{
			aux |= (char_byte >> abs(empty_bits));
			fputc(aux, out);
			empty_bits =  8 + empty_bits;
			aux = 0;
			
			while(empty_bits < 0)
			{
				aux |= (char_byte >> abs(empty_bits));
				fputc(aux, out);
				empty_bits =  8 + empty_bits;
				aux = 0;
			}
			aux |= (char_byte << empty_bits);
		}
		
		else aux |= (char_byte << empty_bits);
	
	}
	if(trash != 0)fputc(aux, out);
	fclose(in);
	fclose(out);
	test();
}