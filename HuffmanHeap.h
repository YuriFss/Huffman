/*////////////INFO////////////////////////////
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

#ifndef HUFFMANHEAP_H_
#define HUFFMANHEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HuffmanHash.h"
#include "HuffmanTree.h"
#include "types.h"

#define num_prime 257

////////////////////HEADER/////////////////////

void swap(Huff_node **x, Huff_node **y);
/* TROCA DOIS NOS DE HUFFMAN */

Huff_heap* create_heap();
/*CRIA A HEAP E RETORNA O PONTEIRO */

int get_parent_index(Huff_heap *heap, int i);
/*PEGA O INDICE DO PARENTE NA HEAP */

int get_left_index(Huff_heap *heap, int i);
/*PEGA O INDICE DA ESQUERDA NA HEAP */

int get_right_index(Huff_heap *heap, int i);
/*PEGA O INDICE DA DIREITA NA HEAP */

Huff_node *item_of(Huff_heap *heap, int i);
/*RETORNA O ITEM DA HEAP, NA POSICAO I */

void min_heapify(Huff_heap *heap, int i);
/* RESTAURA AS PROPRIEDADES DA MIN-HEAP */

void enqueue_heap(Huff_heap *heap, void *item, int freq, Huff_node *down_left, Huff_node *down_right);
/* ADICIONA UM NO DE HUFFMAN A HEAP */

Huff_node *dequeue_heap(Huff_heap *heap);
/* REMOVE UM NO DE HUFFMAN DA HEAP */

void print_heap(Huff_heap *heap, int size);
/* PRINTA A HEAP ATE O SEU TAMANHO */

////////////////////END OF H FILE/////////////////

#endif /* HUFFMANHEAP_H_ */
