//ALUNOS: BRUNO NEEMIAS ALVES MOTA R.A 149905711463
//        PAULO HENRIQUE V. SILVA  R.A 148697511463
//        IGOR LONGARINE VECCHI   R.A 148665311463
//        LEANDRO SAMPAIO         R.A 150992411463

			
#include <stdio.h> 
#include <stdlib.h> 
#include <strings.h>  
#include <conio.h>

struct node 
{
	char alunos[30];  
	struct node *prox; 
	struct node *ant; 
};

typedef struct node no; 

no *plista; 
int posicao; 

void menu() 
{     
    printf("\n\t\tCURSO DE TECNOLOGIA\n\n"); 
    printf("\nCADASTRO DE ALUNOS: \n\n");
	printf("1. Inserir Aluno com deficiencia \n");  
	printf("2. Inserir Aluno sem deficiencia  \n"); 
	printf("3. Remover Aluno da lista\n");   
	printf("4. Buscar Aluno na lista\n");  
    printf("5. Mostra lista de alunos\n");
  	printf("6. Sair\n");   
}

// INSERIR ALUNO COM DEFICIENCIA 

void inserir_alunopcd(char elemen[]) 
{ 
	no *aux; 
	aux = (no*) malloc(sizeof(no));
	strcpy(aux->alunos, elemen);  
	
	if (plista == NULL) 
    {
               plista = aux;
               plista->prox = NULL; 
               plista->ant = NULL; 
    }
    else 
    {
        plista->ant = aux; 
        aux->prox = plista; 
        plista = aux; 
        plista->ant = NULL; 
    }
}

// INSERIR ALUNO SEM DEFICIENCIA
void inserir_aluno(char *elemen) 
{
     
	no *aux, *aux2; 
	aux = (no*) malloc(sizeof(no));  
	strcpy(aux->alunos, elemen); 
	aux->prox = NULL;  
	if (plista==NULL)  
	{
        plista=aux; 
        plista->ant = NULL; 
    }
    else  
    {
        aux2=plista; 
        while (aux2->prox != NULL)  
        {
             aux2=aux2->prox;  
        } 
        aux2->prox = aux; 
        aux->ant = aux2; 
        aux2 = NULL; 
    }    
	aux=NULL; 
}

// REMOVER ALUNO DA  LISTA     

void removeraluno(char elemen[]) 
{
	 no *aux1, *aux2, *aux3; 
     aux1=plista; 
     aux2=NULL; 
     aux3=NULL;
     
     if (plista==NULL) 
     {
        printf("    Lista Vazia"); 
     }else{
         while (aux1->prox!=NULL && strcmp (aux1->alunos, elemen)) 
     {
	 
               aux2=aux1; 
               aux1=aux1->prox;
			  
         }
         
         if(strcmp(aux1 -> alunos, elemen)){
         	printf("\n não existe esse elemento na lista");
         }else{ 
         	if( aux1 -> prox == NULL && aux2 == NULL){ 
         			plista = NULL; 
			}else{ 
			 	if(aux1 -> prox == NULL && aux2->prox != NULL){ 
			 			aux2 -> prox = NULL; 
			 	}else{
			 		if(aux1 -> prox != NULL && aux2== NULL){
						plista=plista->prox;
         				plista->ant=NULL;
         			}else{
					 
			 		if(aux1 -> prox != NULL && aux2->prox!=NULL){
			 			aux3 = aux1 -> prox; 
						aux3 -> ant = aux2; 
						aux2 -> prox = aux3;					 			  
						}					 
				 	}
				 }
			}
		}
	}
}




//BUSCAR ALUNO NA LISTA 

int buscar_aluno(char elemen[]) 
{
posicao=0; 
no *aux; 
for (aux=plista; aux!=NULL; aux = aux->prox) 
{
   posicao++; 
   if(strcmp(aux -> alunos, elemen)){ 
        
}else{
		return posicao; 
}
}
		 
return 0; 

}

//Mostrar alunos da lista

void mostrar_alunos() 
{
no *aux; 
if(plista != NULL) 
{
	aux = plista;
	do{ 
		printf("\n %s \n",aux->alunos); 
		aux = aux->prox; 

}
     while (aux != NULL); 
}    
}



int main()  
{
	 
	int escolha; char nome[30]; 
	plista = NULL; 

    menu(); 
	
    do { 
	    printf("\nInsira a escolha: "); 
		scanf("%i",&escolha); 
		
	   switch (escolha) { 
                  case 1: 
                       printf("\n Digite o nome do aluno :");
                       scanf("%s",nome);
                       inserir_alunopcd(nome);
                       system("cls"); 
                       break;
                  case 2: 
                       printf("\n Digite o nome do aluno :");
                       scanf("%s",nome);
                       inserir_aluno(nome);
                       system("cls");
                       break;
                  case 3: 
                       printf("\n Digite o nome do aluno :");
                       scanf("%s",nome);
                       removeraluno(nome);
                       system("cls");
                        break;
                  case 4:
                       printf("\n Digite o nome do aluno: ");
                       scanf("%s",nome);
            
                       	if (buscar_aluno(nome)==0)
                            printf("\n Nao Achou ");
                    	else
                            printf("\n Achou na posicao %i", posicao);   
                       printf("\n");   
                       break;                      
                  case 5:
                       mostrar_alunos();
					   break; 
                  case 6:
                  		system("cls");
                       break;                        
                  default:
                          puts("Opcao invalida.");
                          break;
           }
           menu();
		
    } while (escolha != 6); 	
	
	
	return(0);
}

