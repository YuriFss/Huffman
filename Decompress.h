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


#ifndef DECOMPRESS_H_
#define DECOMPRESS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "HuffmanHash.h"
#include "HuffmanHeap.h"
#include "HuffmanTree.h"
#include "Compress.h"
#include "types.h"

void decompress_menu(char filename[], char outputname[]);

void decompress();
/* TODO O ALGORITMO DE DESCOMPRESSÃO DE HUFFMAN
 * PEGAMOS O LIXO E O TAMANHO DA ARVORE, EM SEGUIDA
 * CRIAMOS A ARVORE A PARTIR DE SUA PREORDEM.
 * ENTAO PEGAMOS CADA BYTE E VERIFICAMOS SE SEUS BITS ESTAO SETADOS,
 * SE SIM, NAVEGO NA ARVORE DE HUFFMAN PARA A DIREITA, SE NAO
 * NAVEGO NA ARVORE PARA A ESQUERDA.
 * ASSIM QUE CHEGAR EM UMA FOLHA PRINTO O CARACTER QUE ELA CONTEM NO ARQUIVO DE SAIDA.
 */


int is_bit_i_set(unsigned char byte, int i);
/* VERIFICA SE O BIT I, ESTÁ SETADO. */


#endif /* DECOMPRESS_H_ */