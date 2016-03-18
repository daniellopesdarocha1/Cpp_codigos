#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Pilha {

	int topo; /* posição elemento topo */
	int capa;
	float *pElem;

};

void criarpilha( struct Pilha *p, int c ){

   p->topo = -1;
   p->capa = c;
   p->pElem = (float*) malloc (c * sizeof(float));

}
int estavazia ( struct Pilha *p ){

   if( p-> topo == -1 )

      return 1;   // true

   else

      return 0;   // false

}

int estacheia ( struct Pilha *p ){

	if (p->topo == p->capa - 1)

		return 1;

	else

		return 0;

}

void empilhar ( struct Pilha *p, float v){

	p->topo++;
	p->pElem [p->topo] = v;

}

float desempilhar ( struct Pilha *p ){

   float aux = p->pElem [p->topo];
   p->topo--;
   return aux;

}

float retornatopo ( struct Pilha *p ){

   return p->pElem [p->topo];

}


void mostra_vetor_soma( struct Pilha *p, float v){

	//p->topo++;
		for (int k=0; k < p-> topo + 1; k++ ){
			cout << p->pElem [k] << endl;
	}

}

void insertionSort ( int n, int v[]){
   
   int i, j, x;
   
   for (j = 1; j < n; ++j) {
      
	  x = v[j];
      
	  for (i = j-1; i >= 0 && v[i] > x; --i) 
         v[i+1] = v[i];
         
   
      v[i+1] = x;
   }
}

int aleatorio(int x){
	return rand()%x;
}

int main(){
	
	srand(time(0));
	
	int M[5][5];
	int i;
	int j;
	int soma_linha_4 = 0;
	int soma_coluna_2 = 0;
	int soma_diagonal_principal = 0;
	int soma_diagonal_secundaria = 0;
	int soma_todos_elementos = 0;
	int vetor_soma[5];
	
	//preenche vetor
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			M[i][j] = aleatorio(100); //recebe numeros aleatórios entre 0 e 100
		}
	}
	
	//Imprime vetor
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			cout << M[i][j] << "\t";
		}
		cout << endl;
	}  
	
	//soma linha 4
	for(j=0; j<5; j++){
		soma_linha_4 +=  M[3][j];
	}
	cout << "\nSoma da Linha 4: " << soma_linha_4;
	
	//soma coluna 2
	for(i=0; i<5; i++){
		soma_coluna_2 +=  M[i][1];
	}
	cout << "\nSoma da Coluna 2: " << soma_coluna_2;
	
	//soma da diagonal principal
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			if (i==j)
				soma_diagonal_principal += M[i][j];
		}
	}	
	cout << "\nSoma da diagonal principal: " << soma_diagonal_principal;
	
	//soma da diagonal secundaria
	int k = 4;
	for(i=0; i<5; i++){
		soma_diagonal_secundaria += M[i][k];
		k--;
	}	
	cout << "\nSoma da diagonal secundaria: " << soma_diagonal_secundaria;
	
	//soma de todos os elementos da matriz
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			soma_todos_elementos += M[i][j];
		}
	}
	
	cout << "\nSoma de todos os elementos: " << soma_todos_elementos << endl;
	
	vetor_soma[0] = soma_linha_4;
	vetor_soma[1] = soma_coluna_2;
	vetor_soma[2] = soma_diagonal_principal;
	vetor_soma[3] = soma_diagonal_secundaria;
	vetor_soma[4] = soma_todos_elementos;
	
	cout << "\nSomas Nao ordenadas: \n";
	for (i=0; i<5; i++)
		cout << vetor_soma[i] << endl;
	
	//ordenação insertionSort
	insertionSort ( 5, vetor_soma);
	
	
	cout << "\nSomas ordenadas: \n";
	for (i=0; i<5; i++)
		cout << vetor_soma[i] << endl;
		
	struct Pilha minhapilha;
	int capacidade, op;
	float valor;
	
	printf( "\nCapacidade da pilha: ");
	scanf( "%d", &capacidade );

	criarpilha (&minhapilha, capacidade);

	while( 1 ){ /* loop infinito */

		printf("\n[1]- empilhar vetor de somas (push)\n");
		printf("[2]- desempilhar topo (POP)\n");
		printf("[3]- Mostrar vetor de somas empilhadas \n");
		printf("[4]- sair\n");
		printf("\nopcao? ");
		scanf("%d", &op);

		switch (op){

			case 1: //push

				if( estacheia( &minhapilha ) == 1 )

					printf("\nPILHA CHEIA! \n");

				else {
					for (i=0; i<5;i++){
						valor = vetor_soma[i];
						empilhar (&minhapilha, valor);
						valor = 0;
					}

				}
				break;

			case 2: //pop
				if ( estavazia(&minhapilha) == 1 )

					printf( "\nPILHA VAZIA! \n" );

				else{

					valor = desempilhar (&minhapilha);
					printf ( "\n%.1f DESEMPILHADO!\n", valor );

				}
				break;

			case 3: // mostrar o vetor
				if ( estavazia (&minhapilha) == 1 )

					printf( "\nPILHA VAZIA!\n" );

				else {
					

					mostra_vetor_soma( &minhapilha, valor);
					

				}
				break;

			case 4: 
				exit(0);

			default: printf( "\nOPCAO INVALIDA! \n" );
		}
	}
		
	cout << endl << endl;	
	system ("Pause");
	return 0;
}