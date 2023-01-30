#include <stdio.h>
#include <stdlib.h>

int main () {
	int A ; // Declaração da variavel A como inteiro
	printf("Digite sua idade(somente numeros): "); // Pergunta ao usuário sua idade. 
		scanf("%d", &A); // Lê e atrbui o valor digitado pelo usuário no espaço de  memória da variável A. 
	printf("A idade digitada foi: %d", A); // Mostra na tela o valor digitado
	return 0 // retorna 0 para o programa, indicando que o programa rodou de forma correta. 
}
