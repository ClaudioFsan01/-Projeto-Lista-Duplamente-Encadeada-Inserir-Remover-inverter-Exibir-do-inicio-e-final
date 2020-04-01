#include<stdio.h>
#include<stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//declaração de constantes
#define TRUE 1
#define FALSE 0

//declaração de tipos
typedef struct No {
	int valor;
	struct NO* ant;
	struct No* prox;
} TNo;

typedef TNo* TLista;

/*
A fun??o retornar? o n?mero de remo??es realizadas.
{
	TLista aux, aux1, aux2;
	int cont = 0;
	
	//removendo ocorr?ncias do 'numero' no in?cio da lista
	//while ((*L != NULL) && ((*L)->valor == numero))
	while ((*L) && ((*L)->valor == numero))
	{
		aux = *L;
		*L = aux->prox; //ou *L = (*L)->prox;
		free (aux);
		cont++;
	}
	
	//se ainda houver elementos
	if (*L)
	{
		aux2 = *L; // aux2 aponta struc guarda o 30
		aux1 = (*L)->prox; //ou aux1 = aux2->prox;      // struct aux1 aponta struc guarda o 15
		
		while (aux1) // aux1 != NULL
		{
			if (aux1->valor != numero)
			{
				aux2 = aux2->prox; //ou aux2 = aux1;    // aux2 aponta struc guarda o 30
				aux1 = aux1->prox;
			}
			else
			{
				aux2->prox = aux1->prox;
				free (aux1);
				cont++;
				aux1 = aux2->prox;
			}
		}
	}	
	
	return cont;
}
*/

int removerDuplaEncadeada(TLista *L, TLista *U, int numero)
{
	TLista aux , aux1, aux2, aux3;
       // aux1 aponta para o 1° elemento 
	 
	
	if(!*L) // ou if(!aux1)
	{
		return FALSE;
	}
	else
	{
		while(((*L)->valor == numero) && (*L) ) // removendo no inicio da lista
		{ 
		  aux = *L;
		  *L =  (*L)->prox; // *L aponta para o 2° elemento q passará a ser o 1°
		  if((*L)==NULL)
		  {		  
		  	*U = NULL;
		  }
		  (*L)->ant = NULL;  // o ponteiro ant do struct q passará a ser o 1° elemento aponta para NULL		  	   
		  free(aux);
		  		  
		}
		if (*L) // se ainda houver elementos
		{
		 	aux2 = *L; // aux2 aponta para o 1° elemento
			aux1 = aux2->prox ; // aux1 aponta para o 2° elemento
		 	while(aux1) // ou (aux2 != NULL)
		 	{
		 		if(aux1->valor != numero)
		 		{
		 			 aux2 = aux1; // aux2 aponta para quem aux1 apontava
					aux1 = aux1->prox;  // aux1 aponta para o proximo elemento				
		 			
				}
				else
				{
					aux = aux1; // aux recebe o elemento q sera removido
				   aux2->prox = aux1->prox; // 	
				   
				   if(aux2->prox != NULL)
				   {
				   	 aux3 = aux2->prox;				    
				     aux3->ant = aux2;
				     
					 while(aux3 != NULL)
					 {
					 	if(aux3->prox == NULL)
					 	{
					 		*U = aux3;
						}
					 	aux3 = aux3->prox;
					 }
					 
					 
				   }
				   else
				   {
				    *U = aux2;
				   }  		    
				   						
					
					free(aux);				  
		 	        
				}
		 	
			}		 	
		 	
		}
		return TRUE;
	}
	
	
}

int inserirDupla(TLista *L, TLista *U, int numero)
{//inserindo no inicio da lista duplamente encadeada  
	TLista aux = (TLista) malloc(sizeof(TNo));
	
	if(aux==NULL)
	{
		return FALSE;
	}
	else
	{
		aux->valor = numero;
		
		if(*L==NULL) // no caso de lista vazia 
		{
			aux->ant=NULL;
			aux->prox = NULL;
			*L = aux; // *L aponta para o primeiro(ultimo struct inserido)
			*U= aux; // *U aponta para o ultimo (primeiro struct inserid)
		}
		else
		{
			aux->prox = *L; // prox do novo elemento aponta para o 1° elemento da lista(ultimo struct inserido)
			aux->ant = NULL; // ant do novo elemento aponta sempre para NULL
		    (*L)->ant = aux; // ant do 1° elemento (ultimo struct inserido) aponta para o novo elemento
			*L = aux;	// *L aponta para o primeiro(ultimo struct inserido)
			
		}
		
		return TRUE;
	}
	
}
 
 void exibirInicio(TLista L)
{
  TLista aux = L;
  
  if(!L) // if(L==NULL)
  {
   printf(" Lista vazia ! \n");
  }
  else  
  {
     printf(" Lista !");

    while(aux) // while (aux != NULL)
    {
         
    printf("%d ", aux->valor);

    aux = aux->prox;
    }


  }
  
  
}

 void exibirFinal(TLista U)
{
  TLista aux = U;
  
  if(!U) // if(U==NULL)
  {
   printf(" Lista vazia ! \n");
  }
  else  
  {
     printf(" Lista !");

    while(aux) // while (aux != NULL)
    {
         
    printf("%d ", aux->valor);

    aux = aux->ant;
    }


  }  
  
}

int inverterDuplaEncadeada(TLista L, TLista U)
{
	TLista aux1=L, aux2=U;
	int num1, cont=0, div=0;
	
	if(!aux1)
	{
	return FALSE;
	}
	else
	{
		
		do
		{
			cont++;
			aux1 = aux1->prox;
			
		}while(aux1);
		
	
		div = (cont/2);	
		do
		{		
			if(aux1->valor != aux2->valor)
			{
		     num1 = aux1->valor; // guardando o valor do 1° elemento(ultimo struct inserido) em uma auxiliar
		     aux1->valor = aux2->valor; //  guardando o valor do ultimo elemento (primeiro struct inserido) na variavel valor do 1° elemento(ultimo struct inserido)
		     aux2->valor = num1; //  guardando o valor do 1° elemento(ultimo struct inserido) ,q estava na auxiliar num1, no ultimo elemento (primeiro struct inserido)
		     				
			}
		 
		aux1 = aux1->prox;
		aux2 = aux2->ant;
		
		 cont--;			
		}while(div<cont); // 
		
		return TRUE; 
	}
		
	
}

int menu()
{int op;

printf("-------------------------");
 printf("\n Informe a opção desejada ! \n");
   printf("-------------------------");
    printf("\n(1)- Inserir na lista duplamente encadeada \n"
            "(2)- Exibir \n"
            "(3)- Sair \n"
            "(4)-Buscar \n"
            "(5)-Alterar \n"
			"(6)-Andar na lista \n"
     "(7)- Remover elemento da lista duplamente encadeada\n"
      " (9)- verificar elementos comuns na F1 e F2\n"
      "(10)- desenfilar fora do intervalo \n"
	  "(11)- inverter lista duplamente encadeada \n");    
       scanf("%d", &op);


	return op;
}

int main(void) {
	
	TLista L= NULL, U=NULL;
	int op, num;
	
	
	do{
		op = menu();
		
		switch(op)
		{
			
			case 1:
				
				printf(" Insira o número : \n");
				scanf("%d", &num);
				
				if(inserirDupla(&L, &U, num)==TRUE)
				{
					printf(" Elemento inserido \n");
				}
				else
				{
						printf(" Elemento não inserido \n");
				}
				break;
				
				case 2:
					printf(" Exibir (1)- do inicio ou (2)- do final \n ");
					scanf("%d", &num);
					if(num==1)
					{
						 exibirInicio(L);
					}
					else
					{
						exibirFinal(U);
					}
					break;
					
					case 3:
						 	printf(" Encerrado \n");
						break;
						
						case 7:
							
								printf(" Insira o número que será removido : \n");
				                scanf("%d", &num);
				                
				                if(removerDuplaEncadeada(&L, &U, num))
								{
				                	printf(" Elemento removido \n");
								}
								else
								{
										printf(" Elemento não removido ou erro \n");
								}
												 
							
							break;
						
						case 11:
							
							if (inverterDuplaEncadeada(L, U)==TRUE)
							{
								printf("Lista duplamente encadeada invertida ! \n");
							}
							else
							{
								printf(" Erro ou lista vazia ! \n");
							}
							break;							
							
						default:
								printf(" Opção invalida ! \n");
							break;
		}
		
		
	}while(op!=3);
	
	
	return 0;
}



