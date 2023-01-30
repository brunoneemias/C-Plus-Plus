// NOME BRUNO NEEMIAS ALVES MOTA 
#include <stdio.h> // inclui entradas e saídas

float  num1, num2; // cria duas variaveis do tipo flutuante (Real).
char operacao; // Cria uma variavel do tipo char.

int main(){

printf(" ====== C A L C U L A D O R A ====== \n\n\n"); // Mostra na tela 

printf(" Escolha uma operacao [+, -, *, /]:  "); // Pergunta ao usuário a operação desejada; 
	scanf("%c", &operacao); // atribui o comando digitado pelo usuário 

printf("Digite o primeiro numero:"); // Pergunta ao usuário o primeiro número
	scanf("%f", &num1);// atribui o valor digitado para num1
	
printf("Digite o segundo numero: ");// Pergunta ao usuário o segundo número
	scanf("%f", &num2);	 // Atribui o valor digitado para num2 

switch(operacao){
	case '+': 
			printf("%.2f + %.2f = %.2f", num1, num2, num1+num2); // %.2f significa que terá dois números decimais após a virgula. 
			break;
	case '-':
			printf("%.2f - %.2f = %.2f", num1, num2, num1 - num2); 
			break;
	case '*': 
			printf("%.2f * %.2f = %.2f", num1, num2, num1 * num2); 
			break;
	case '/': 
			printf("%.2f / %.2f = %.2f", num1, num2, num1 / num2);
			break;
				}
		}
