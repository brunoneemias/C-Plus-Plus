#include <stdio.h> // inclui a biblioteca de entrada e sa�da (print e scanf) 
#include <stdlib.h> // biblioteca do emulador da prompt de comando

struct node // estrutura (n�) onde cria os ponteiros
{
	int info; // aonde vai as informa��es
	struct node *prox; // cria um ponteiro do tipo n�
};

typedef struct node no; // apelida o n�

no *plista; // cria um ponteiro plista que vai sempre apontar para o inicio da lista.
int posicao; // cria uma varivel inteira referente a posi��o 

void menu() // fun��o menu, para interagir com o usu�rio. 
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

void inseririnicio(int elemen) // elemen � referente ao valor escolhido pelo usu�rio para inserir na lista. 
{
     
	no *aux; // cria um ponteiro auxiliar para o n�.
	aux = (no*) malloc(sizeof(no)); // s� vai ser criado  o ponteiro aux se tiver espa�o em n�, aux recebe o endere�o do n� criado.  
	aux->info= elemen; // ponteiro auxiliar aponta para o info do n� que o mesmo ser� igual ao elemento.
	aux->prox = plista; // aux aponta para prox � igual a plista(NULL) ou seja prox aponta para null. 
	plista = aux; // plista recebe o endere�o de aux e agora ele aponta para o mesmo
	aux = NULL; // aux recebe null pois j� foi utilizado. 
}

// inserir elementos no final

void inserirfinal(int elemen) 
{
     
	no *aux; // cria um ponteiro auxiliar para o n�.
	aux = (no*) malloc(sizeof(no)); // s� vai ser criado  o ponteiro aux se tiver espa�o em n�, aux recebe o endere�o do n� criado.  	
		aux->info= elemen; // ponteiro auxiliar aponta para o info do n� que o mesmo ser� igual ao elemento.
		
	if (plista == NULL){ // Se o plista apontar para null, isso significa que nao tem nada na lista. 
		aux->prox = NULL; // aux aponta para prox � igual null ou seja prox aponta para null sendo automaticamente o ultimo elemento da lista. 
		plista = aux; // plista recebe a memoria de aux, plista aponta para o primeiro e unico elemento da lista.
		aux = NULL;
	}else{ 
		no *aux1 = plista; // cria um ponteiro que ir� percorrer a lista a partir do elemento em que plista est� apontando. 
		while(aux1->prox!=NULL){ // enquanto aux1 que aponta para proximo for diferente de null, o aux1 vai percorrer a lista.
			aux1=aux1->prox; // aux1 � igual aux1 que aponta para o proximo. 
		}
		aux->prox=NULL; // aux aponta para o prox o do n� criado que recebe null sendo o ultimo da lista
		aux1->prox=aux; //  o aux1 aponta para o prox do penultimo elemento que recebe o endere�o do ultimo elemento armazenado em aux.  
		aux1 = NULL; // recebe null pois j� foi utilizado. 
	}
		aux = NULL; // aux recebe null pois j� foi utilizado. 
}

// inserir elementos ordenado. 

void inserirmeio(int elemen){
	no* aux1, *aux2, *aux3; // neste caso precisa de 3 auxliares
	aux1 = (no*) malloc(sizeof(no));  // aux1 vai armazenar a nova informa��o
	aux1->info=elemen; // aux1 aponta para info que � igual ao elemen(informa��o digitada pela usu�rio).
	aux2 = plista; // aux2 vai varrer a lista, e para o plista n�o perder a referencia do inicio ele recebe o endere�o de plista.
	aux3 = NULL; // aux3 � o elemento anterior do   novo elemento a ser inserido, recebe nulo pois a posibilidade de nao ser usado caso o elemento seja o 1�
	
	if(aux2 == NULL){ // se o aux2 que ir� varrer a lista for nulo, isso significa que n�o tem nenhum elemento na lista. 
		aux1 ->prox=NULL; // logo o aux1 aponta para o prox que recebe nulo
		plista = aux1; // plista recebe aux1 
	}else{ // se nao for nulo
		while(aux2 != NULL && aux2->info < elemen){ // enquanto o aux 2 for diferente de nulo e a informa��o condita nele for menor que o elemen o la�o continua
 			aux3 = aux2;  // aux3 que faz atroca recebe o aux 2  
			aux2 = aux2->prox;  // aux2 que percorre a lista recebe o proximo da lista
		
		}
		aux1->prox = aux2;  // o elemento novo, vai apontar  o aux2, pois quando sair do la�o sera o pr�ximo elemento. 
		if(aux3 == NULL){  // se o aux3 for nulo, siginifica que o elemento vai ser inserido na primeira posi��o.
			plista = aux1; // o plista vai apontar para o novo elemento, ou seja ele � o primeiro elemento. 
			 
		}else{ // se n�o for nulo 
			aux3->prox = aux1; // o aux3 (que � o elemento anterior) aponta para o proximo e o mesmo vai pontar para o novo elemento inserido. 
		}
	}
	aux1 = NULL; 
	aux2 = NULL;
	aux3 = NULL;

}

// remover inicio da lista 

void removerinicio(){
	no* aux; //cria um aux no n� 
	aux = plista; // aux recebe o endere�o armazenado em plista
	if(plista == NULL){ // se plista igual a nulo
		printf("\n nao tem elementos na lista \n"); // printa que n�o tem elementos na lista. 
		return ; 
	}else{ // se n�o
	plista = plista -> prox; // plista vai apontar para o pr�ximo da lista
	aux -> prox = NULL; // e o ponteiro aux vai apontar para o nulo, removendo o elemento do inicio da lista. 
	 
	}
	aux = NULL; // aux recebe nulo
}

// Remover fim 

void removerfim(){
	no*aux1, *aux2;  // cria dois ponteiros auxiliar. 
	aux1 = plista; // aux1 vai varrer o c�digo para achar o �ltimo elemento. 
	aux2 = NULL; // aux 2 s� vai ser usado se a lista estiver com elementos. 
	if(aux1 == NULL){ 
		printf("\n nao tem elementos na lista \n"); 
		return ;  
	}else{  
		while(aux1->prox != NULL){ // enquanto o aux1 for diferente de nulo
			aux2 = aux1; // aux2 vai receber o anterior se estiver mais de um elemento na lista. 
			aux1 = aux1 -> prox;  // aux1 recebe o ultimo elemento 
		}
	if(aux2 == NULL){ // se aux2 for igual a null significa que na lista s� tinha um elemento e o aux 2 n�o foi usado. 
		plista=NULL; // plista recebe null e fica vazia. 
	}else{ // se n�o
			aux2 -> prox = NULL;  // aux2 que � o penultimo elemento da lista aponta para nulo e remove o ultimo elemento. 
	}
}
}

// remover elemento especifico
void  removermeio(int elemen){ 
	no *aux1, *aux2, *aux3; // cria 3 ponteiros auxiliares
	aux1 = plista; // aux1 vai ser o ponteiro utilizado para percorrer a lista.
	aux2 = NULL; // vai guardar o elemento anterior
	aux3 = NULL; // vai guardar o pr�ximo elemento. 
	if(aux1 == NULL){  
		printf("\n nao tem elementos na lista \n"); 
		return ;  
	}else{ 
		while(aux1->info != elemen && aux1 -> prox != NULL){ // enquanto info for diferente de elemen e o prox for diferente de nulo o la�o continua. 
			aux2 = aux1; // aux armazena o pr�ximo 
			aux1 = aux1 -> prox; // INCREMENTA +1 NO AUX
		}
		if(aux1 -> info != elemen){ // se ap�s sair do la�o o aux ainda for diferente de info
			printf("\n elemento nao esta na lista \n"); // nao esse elemento na lista
		}else{ // se nao
				if(aux1 -> prox == NULL && aux2 == NULL){ // se o prox � igual a nulo e o aux2 for n�o foi usado
					plista = NULL;  // plista � igual a null porque s� tinha esse elemento na lista 
				}else{
						if(aux2 != NULL){
					aux3 = aux1 -> prox; 
					aux2 -> prox = aux3; 
				}
			
		}
	}
}
}

int buscarelemento(int elemen) // buscar elemento digitado pelo usu�rio
{
posicao=0; // posi��o recebe 0 
no *aux; // cria um ponteiro auxiliar no n�. 
for (aux=plista; aux!=NULL; aux = aux->prox) // para aux igual a plista at� aux diferente de nulo, aux recebe o proximo da lista.  
{
   posicao++; // posi��o incrementa +1 
   if (aux->info == elemen) // se a informa��o em que aux aponta for igual elemen.
        return posicao; // retorna em que posi��o est� o elemento. 
}
return 0; // retorna para o case. 
}





//Mostrando os elementos da lista:

void mostrarlista() // mostra todos os elementos da lista.
{
no *aux; // cria um ponteiro no n�
if(plista != NULL)// se a lista n�o tiver vazia
{
	aux = plista; // aux recebe lista
	do{ // faz enquanto 
		printf("\n %i \n",aux->info);
		aux = aux->prox; // aux recebe o pr�ximo da lista. 

}
    while (aux != NULL);// o la�o continua at� enquanto o aux for diferente de nulo 
}    
}


int main() // principal
{
	int escolha; int numero; // cria as variaveis escolha e numero do tipo inteiro
	plista = NULL; // plista recebe null 
	
    menu(); // mostra o menu para o usu�rio
	
    do { // fa�a 
	    printf("\nInsira a escolha: ");
		scanf("%i",&escolha);
		
	   switch (escolha) { // interruptor(Escolha caso)
                  case 1: // caso o usu�rio digite 1 
                       printf("\n Digite um numero :"); 
                       scanf("%i",&numero);
                       inseririnicio(numero); // chama a fun��o inicio. 
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
                            printf("\n Achou na posicao %i", posicao); // printa que achou no valo dentro da posi��o.   
                       printf("\n");   
                       break;
                  case 9: // caso 9 
                       break;       //para o programa.                   
                  default: // por padr�o, quando digitar qualquer valor acima de 9 
                          puts("Opcao invalida.");   // printa isso 
                          break;
           }
           menu(); // volta para o menu
		
    } while (escolha != 9); // enquanto escolha for diferente de 9	, quando for 9 ele sai do programa
	
	
	return(0); // retorna 0 
}

