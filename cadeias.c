/*
 * cadeias.c
 * Exercício sobre cadeias de caracteres.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2024 João Vicente, UFSM
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadeias.h"


/* junta as strings de 'dest' e 'orig' 
	Retorna um novo ponteiro com as duas juntas
*/
char* concatena(const char* dest, const char* orig)
{
	size_t dest_t = strlen(dest);
	size_t orig_t = strlen(orig);
	size_t total;
	char* res = (char*) malloc((total=dest_t+orig_t));

	strcpy(res, dest);
	strcat(res, orig);
	/* TODO faça a função aqui! */
	return  res;
}

/* Recebe um texto 'texto' como entrada e um caractere 'c'
	Retorna um vetor de char* com a quebra das palavras.
*/
char** quebra_palavras(char* texto, char c) 
{
	int count=0;
	char *token, **s;
	char delim[2] = {c, '\0'};
	for (int i=0; 1<strlen(texto);i++){
		if(texto [i] == c && texto [i-1] != c)
			count++;
	}
	s= (char**) calloc(count+1, sizeof(char*));
	token=strtok(texto,delim);
	int i=0;
	while (token !=NULL){
		char* palavra = (char* )malloc (strlen(token)+1*sizeof(char));
		strcpy(palavra, token);
		s[i] = palavra;
		token = strtok(NULL, delim);
		i++;
	}
	return s;		
}
