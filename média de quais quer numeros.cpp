// Exerc�cio usando o malloc() e  free()

// Crie um programa que calcula  a m�dia de uma quantidade qualquer (informada pelo usu�rio) de n�meros. 

#include <stdio.h> // inclui biblioteca de entrada e sa�da ( print e scanf) 
#include <stdlib.h> // Inclui biblioteca que interage com o prompt. 



int *aloca(int num) // fun��o aloca, que vai alocar a quantidade e memoria necess�ria para o programa. 
{
 int count, // cria uma variavel to tipo inteiro para contar no for logo abaixo. 
  *numbers; // cria um ponteiro do tipo inteiro 
 
 numbers = (int *)malloc(num*sizeof(int)); // o ponteiro recebe o espa�o de mem�ria de acordo com o que foi armazenado em num. 
 
 for(count=0 ; count < num ; count++) // la�o para, que adiciona o n�mero digitado no vetor
 {
  printf("Numero [%d]: ", count+1); // mostra na tela 
  scanf("%d", &numbers[count]); // l�  o n�mero digitado
 }
 
 return numbers; // retorna para numbers 
}

float media(int *numbers, int num) // fun��o m�dia. 
{
 float media=0.0; // media recebe 0
 int count; // variavel inteira que vai auxiliar o for.
 
 for(count=0 ; count<num ; count++) // la�o for que vai calcular a m�dia dos n�meros digitados
  media += numbers[count]; // n�o entendi
 
 return media/num; // retorna m�dia/num 
}

void exibe(int *numbers, int num) // fun��o exibe os n�meros e a m�dia entre eles. 
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







