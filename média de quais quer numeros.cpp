// Exercício usando o malloc() e  free()

// Crie um programa que calcula  a média de uma quantidade qualquer (informada pelo usuário) de números. 

#include <stdio.h> // inclui biblioteca de entrada e saída ( print e scanf) 
#include <stdlib.h> // Inclui biblioteca que interage com o prompt. 



int *aloca(int num) // função aloca, que vai alocar a quantidade e memoria necessária para o programa. 
{
 int count, // cria uma variavel to tipo inteiro para contar no for logo abaixo. 
  *numbers; // cria um ponteiro do tipo inteiro 
 
 numbers = (int *)malloc(num*sizeof(int)); // o ponteiro recebe o espaço de memória de acordo com o que foi armazenado em num. 
 
 for(count=0 ; count < num ; count++) // laço para, que adiciona o número digitado no vetor
 {
  printf("Numero [%d]: ", count+1); // mostra na tela 
  scanf("%d", &numbers[count]); // lê  o número digitado
 }
 
 return numbers; // retorna para numbers 
}

float media(int *numbers, int num) // função média. 
{
 float media=0.0; // media recebe 0
 int count; // variavel inteira que vai auxiliar o for.
 
 for(count=0 ; count<num ; count++) // laço for que vai calcular a média dos números digitados
  media += numbers[count]; // não entendi
 
 return media/num; // retorna média/num 
}

void exibe(int *numbers, int num) // função exibe os números e a média entre eles. 
{
 int count;
 
 for(count=0 ; count < num ; count++)
  printf("%3d", numbers[count]);
}

int main(void)
{
 int num=1,
  *numeros;
 
 while(num)
 {
  printf("Media de quantos numeros [0 para sair]: ");
  scanf("%d", &num);
  
  if(num > 0)
  {
   numeros = aloca(num);
   exibe(numeros,num);
   printf("\nA media destes numeros eh: %.2f\n", media(numeros, num) );
   free(numeros);
  }
 }

 return 0;
}







