#include <stdio.h>
#include <stdlib.h>

int main () {
	int A ; // Declara��o da variavel A como inteiro
	printf("Digite sua idade(somente numeros): "); // Pergunta ao usu�rio sua idade. 
		scanf("%d", &A); // L� e atrbui o valor digitado pelo usu�rio no espa�o de  mem�ria da vari�vel A. 
	printf("A idade digitada foi: %d", A); // Mostra na tela o valor digitado
	return 0 // retorna 0 para o programa, indicando que o programa rodou de forma correta. 
}
