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

/////////////START OF H FILE///////////////////

#ifndef HUFFMANHASH_H_
#define HUFFMANHASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HuffmanHeap.h"
#include "HuffmanTree.h"
#include "types.h"

#define num_prime 257

////////////////////HEADER/////////////////////

Hash_data *new_index();
/* ALOCA ESPACO PARA UM NOVO INDICE DA HASH*/

Huff_hash *create_hash_table();
/* CRIA UMA NOVA HASH-TABLE*/

Hash_data *create_data(Hash_data *local, void *item, unsigned int shift_bit, int level);
/* CRIA O CONJUNTO DE DADOS DA HASH*/

void put_hash(Huff_hash *ht, void *item, unsigned int shift_bit, int level);
/* USA A CREATE_DATA PARA CRIAR O CONJUNTO DE DADOS, E OS INSERE NA HASH*/

void print_hash(Huff_hash *ht);
/* PRINTA A HASH */

////////////////////END OF H FILE/////////////////

#endif /* HUFFMANHASH_H_ */
