#include <stdio.h> // inclui a biblioteca de entrada e saída (print e scanf) 
#include <stdlib.h> // biblioteca do emulador da prompt de comando

struct node // estrutura (nó) onde cria os ponteiros
{
	int info; // aonde vai as informações
	struct node *prox; // cria um ponteiro do tipo nó
};

typedef struct node no; // apelida o nó

no *plista; // cria um ponteiro plista que vai sempre apontar para o inicio da lista.
int posicao; // cria uma varivel inteira referente a posição 

void menu() // função menu, para interagir com o usuário. 
{
     bool teste; // teste booleano (nem usa). 
     
    printf("\n\t\t\t\tListas encadeadas\n\n");
	printf("1. Inserir no Inicio\n");
	printf("2. Inserir no Final\n");
	printf("3. Inserir Ordenado\n");
	printf("4. Mostrar a Lista\n");
	printf("5. Remover do Inicio\n");
    printf("6. Remover do Final\n");
  	printf("7. Remover Elemento Especifico\n");
	printf("8. Buscar Elemento \n");
	printf("9. Sair\n");    
}

// inserir elementos no inicio

void inseririnicio(int elemen) // elemen é referente ao valor escolhido pelo usuário para inserir na lista. 
{
     
	no *aux; // cria um ponteiro auxiliar para o nó.
	aux = (no*) malloc(sizeof(no)); // só vai ser criado  o ponteiro aux se tiver espaço em nó, aux recebe o endereço do nó criado.  
	aux->info= elemen; // ponteiro auxiliar aponta para o info do nó que o mesmo será igual ao elemento.
	aux->prox = plista; // aux aponta para prox é igual a plista(NULL) ou seja prox aponta para null. 
	plista = aux; // plista recebe o endereço de aux e agora ele aponta para o mesmo
	aux = NULL; // aux recebe null pois já foi utilizado. 
}

// inserir elementos no final

void inserirfinal(int elemen) 
{
     
	no *aux; // cria um ponteiro auxiliar para o nó.
	aux = (no*) malloc(sizeof(no)); // só vai ser criado  o ponteiro aux se tiver espaço em nó, aux recebe o endereço do nó criado.  	
		aux->info= elemen; // ponteiro auxiliar aponta para o info do nó que o mesmo será igual ao elemento.
		
	if (plista == NULL){ // Se o plista apontar para null, isso significa que nao tem nada na lista. 
		aux->prox = NULL; // aux aponta para prox é igual null ou seja prox aponta para null sendo automaticamente o ultimo elemento da lista. 
		plista = aux; // plista recebe a memoria de aux, plista aponta para o primeiro e unico elemento da lista.
		aux = NULL;
	}else{ 
		no *aux1 = plista; // cria um ponteiro que irá percorrer a lista a partir do elemento em que plista está apontando. 
		while(aux1->prox!=NULL){ // enquanto aux1 que aponta para proximo for diferente de null, o aux1 vai percorrer a lista.
			aux1=aux1->prox; // aux1 é igual aux1 que aponta para o proximo. 
		}
		aux->prox=NULL; // aux aponta para o prox o do nó criado que recebe null sendo o ultimo da lista
		aux1->prox=aux; //  o aux1 aponta para o prox do penultimo elemento que recebe o endereço do ultimo elemento armazenado em aux.  
		aux1 = NULL; // recebe null pois já foi utilizado. 
	}
		aux = NULL; // aux recebe null pois já foi utilizado. 
}

// inserir elementos ordenado. 

void inserirmeio(int elemen){
	no* aux1, *aux2, *aux3; // neste caso precisa de 3 auxliares
	aux1 = (no*) malloc(sizeof(no));  // aux1 vai armazenar a nova informação
	aux1->info=elemen; // aux1 aponta para info que é igual ao elemen(informação digitada pela usuário).
	aux2 = plista; // aux2 vai varrer a lista, e para o plista não perder a referencia do inicio ele recebe o endereço de plista.
	aux3 = NULL; // aux3 é o elemento anterior do   novo elemento a ser inserido, recebe nulo pois a posibilidade de nao ser usado caso o elemento seja o 1º
	
	if(aux2 == NULL){ // se o aux2 que irá varrer a lista for nulo, isso significa que não tem nenhum elemento na lista. 
		aux1 ->prox=NULL; // logo o aux1 aponta para o prox que recebe nulo
		plista = aux1; // plista recebe aux1 
	}else{ // se nao for nulo
		while(aux2 != NULL && aux2->info < elemen){ // enquanto o aux 2 for diferente de nulo e a informação condita nele for menor que o elemen o laço continua
 			aux3 = aux2;  // aux3 que faz atroca recebe o aux 2  
			aux2 = aux2->prox;  // aux2 que percorre a lista recebe o proximo da lista
		
		}
		aux1->prox = aux2;  // o elemento novo, vai apontar  o aux2, pois quando sair do laço sera o próximo elemento. 
		if(aux3 == NULL){  // se o aux3 for nulo, siginifica que o elemento vai ser inserido na primeira posição.
			plista = aux1; // o plista vai apontar para o novo elemento, ou seja ele é o primeiro elemento. 
			 
		}else{ // se não for nulo 
			aux3->prox = aux1; // o aux3 (que é o elemento anterior) aponta para o proximo e o mesmo vai pontar para o novo elemento inserido. 
		}
	}
	aux1 = NULL; 
	aux2 = NULL;
	aux3 = NULL;

}

// remover inicio da lista 

void removerinicio(){
	no* aux; //cria um aux no nó 
	aux = plista; // aux recebe o endereço armazenado em plista
	if(plista == NULL){ // se plista igual a nulo
		printf("\n nao tem elementos na lista \n"); // printa que não tem elementos na lista. 
		return ; 
	}else{ // se não
	plista = plista -> prox; // plista vai apontar para o próximo da lista
	aux -> prox = NULL; // e o ponteiro aux vai apontar para o nulo, removendo o elemento do inicio da lista. 
	 
	}
	aux = NULL; // aux recebe nulo
}

// Remover fim 

void removerfim(){
	no*aux1, *aux2;  // cria dois ponteiros auxiliar. 
	aux1 = plista; // aux1 vai varrer o código para achar o último elemento. 
	aux2 = NULL; // aux 2 só vai ser usado se a lista estiver com elementos. 
	if(aux1 == NULL){ 
		printf("\n nao tem elementos na lista \n"); 
		return ;  
	}else{  
		while(aux1->prox != NULL){ // enquanto o aux1 for diferente de nulo
			aux2 = aux1; // aux2 vai receber o anterior se estiver mais de um elemento na lista. 
			aux1 = aux1 -> prox;  // aux1 recebe o ultimo elemento 
		}
	if(aux2 == NULL){ // se aux2 for igual a null significa que na lista só tinha um elemento e o aux 2 não foi usado. 
		plista=NULL; // plista recebe null e fica vazia. 
	}else{ // se não
			aux2 -> prox = NULL;  // aux2 que é o penultimo elemento da lista aponta para nulo e remove o ultimo elemento. 
	}
}
}

// remover elemento especifico
void  removermeio(int elemen){ 
	no *aux1, *aux2, *aux3; // cria 3 ponteiros auxiliares
	aux1 = plista; // aux1 vai ser o ponteiro utilizado para percorrer a lista.
	aux2 = NULL; // vai guardar o elemento anterior
	aux3 = NULL; // vai guardar o próximo elemento. 
	if(aux1 == NULL){  
		printf("\n nao tem elementos na lista \n"); 
		return ;  
	}else{ 
		while(aux1->info != elemen && aux1 -> prox != NULL){ // enquanto info for diferente de elemen e o prox for diferente de nulo o laço continua. 
			aux2 = aux1; // aux armazena o próximo 
			aux1 = aux1 -> prox; // INCREMENTA +1 NO AUX
		}
		if(aux1 -> info != elemen){ // se após sair do laço o aux ainda for diferente de info
			printf("\n elemento nao esta na lista \n"); // nao esse elemento na lista
		}else{ // se nao
				if(aux1 -> prox == NULL && aux2 == NULL){ // se o prox é igual a nulo e o aux2 for não foi usado
					plista = NULL;  // plista é igual a null porque só tinha esse elemento na lista 
				}else{
						if(aux2 != NULL){
					aux3 = aux1 -> prox; 
					aux2 -> prox = aux3; 
				}
			
		}
	}
}
}

int buscarelemento(int elemen) // buscar elemento digitado pelo usuário
{
posicao=0; // posição recebe 0 
no *aux; // cria um ponteiro auxiliar no nó. 
for (aux=plista; aux!=NULL; aux = aux->prox) // para aux igual a plista até aux diferente de nulo, aux recebe o proximo da lista.  
{
   posicao++; // posição incrementa +1 
   if (aux->info == elemen) // se a informação em que aux aponta for igual elemen.
        return posicao; // retorna em que posição está o elemento. 
}
return 0; // retorna para o case. 
}





//Mostrando os elementos da lista:

void mostrarlista() // mostra todos os elementos da lista.
{
no *aux; // cria um ponteiro no nó
if(plista != NULL)// se a lista não tiver vazia
{
	aux = plista; // aux recebe lista
	do{ // faz enquanto 
		printf("\n %i \n",aux->info);
		aux = aux->prox; // aux recebe o próximo da lista. 

}
    while (aux != NULL);// o laço continua até enquanto o aux for diferente de nulo 
}    
}


int main() // principal
{
	int escolha; int numero; // cria as variaveis escolha e numero do tipo inteiro
	plista = NULL; // plista recebe null 
	
    menu(); // mostra o menu para o usuário
	
    do { // faça 
	    printf("\nInsira a escolha: ");
		scanf("%i",&escolha);
		
	   switch (escolha) { // interruptor(Escolha caso)
                  case 1: // caso o usuário digite 1 
                       printf("\n Digite um numero :"); 
                       scanf("%i",&numero);
                       inseririnicio(numero); // chama a função inicio. 
                       break; // para
                  case 2: 
                       printf("\n Digite um numero :");
                       scanf("%i",&numero);
                       inserirfinal(numero);
                       break; 
                  case 3:
                       printf("\n Digite um numero :");
                       scanf("%i",&numero);
                       inserirmeio(numero);
                       break; 
                  case 4:
                       mostrarlista();
                       break;
                   case 5:
                       removerinicio();
                       break;  
                  case 6:
                       removerfim();
                       break; 
                  case 7:
                       printf("\n Digite um numero :");
                       scanf("%i",&numero);
                       removermeio(numero); 
                        break; 
                  case 8:
                       printf("\n Digite um numero :");
                       scanf("%i",&numero);
            
                       	if (buscarelemento(numero)==0) // se o buscar elemento retornar 0 
                            printf("\n Nao Achou "); // printa que nao achou
                    	else // se nao 
                            printf("\n Achou na posicao %i", posicao); // printa que achou no valo dentro da posição.   
                       printf("\n");   
                       break;
                  case 9: // caso 9 
                       break;       //para o programa.                   
                  default: // por padrão, quando digitar qualquer valor acima de 9 
                          puts("Opcao invalida.");   // printa isso 
                          break;
           }
           menu(); // volta para o menu
		
    } while (escolha != 9); // enquanto escolha for diferente de 9	, quando for 9 ele sai do programa
	
	
	return(0); // retorna 0 
}

