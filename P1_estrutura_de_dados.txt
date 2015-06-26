#include <iostream>
#include <cstdlib>

#define n 10

using namespace std;

void intercala( int p, int q, int r, int v[]) {
   int i, j, k, *w;
   w = (int *)malloc((r-p) * sizeof (int));
   i = p; j = q;
   k = 0;

   while (i < q && j < r) {
      if (v[i] <= v[j])  w[k++] = v[i++];
      else  w[k++] = v[j++];
   }
   while (i < q)  w[k++] = v[i++];
   while (j < r)  w[k++] = v[j++];
   for (i = p; i < r; ++i)  v[i] = w[i-p];
   free( w);
}

void mergesort( int p, int r, int v[]){
   if (p < r-1) {
      int q = (p + r)/2;
      mergesort( p, q, v);
      mergesort( q, r, v);
      intercala( p, q, r, v);
   }
}

struct Fila {

	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens; 

};

void criarFila( struct Fila *f, int c ) { 

	f->capacidade = c;
	f->dados = (float*) malloc (f->capacidade * sizeof(float));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0; 

}

void inserir(struct Fila *f, int v) {

	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido

}

int remover( struct Fila *f ) { // pega o item do começo da fila

	int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro

	if(f->primeiro == f->capacidade)
		f->primeiro = 0;

	f->nItens--;  // um item retirado
	return temp;

}

int estaVazia( struct Fila *f ) { // retorna verdadeiro se a fila está vazia

	return (f->nItens==0);

}

int estaCheia( struct Fila *f ) { // retorna verdadeiro se a fila está cheia

	return (f->nItens == f->capacidade);
}

void mostrarFila(struct Fila *f){

	int cont, i;

	for ( cont=0, i= f->primeiro+1; cont < f->nItens-1; cont++){//linha alterada

		cout << "  " << f->dados[i++];

		if (i == f->capacidade)
			i=0;

	}
	
	cout << "\n\n";

}

int main() {
	
	int i;
	int vetorA[n] = {10, 30, 50, 60, 80, 90, 100, 20, 40, 70};
	int vetorB[n];
	
	for (i=0; i<n; i++)
		vetorB[i] = vetorA[i] / 5;
		
	cout << "Vetor A: ";
	for (i=0; i<n; i++)
		cout << vetorA[i] << " ";
		
	cout << endl;
		
	cout << "\nVetor B: ";
	for (i=0; i<n; i++)
		cout << vetorB[i] << " ";
	
	cout << endl;
		
	intercala(0, n/2, n, vetorB);
	mergesort(0, n, vetorB);
	
	cout << "\nVetor B Ordenado crescente mergesort: ";
	for (i=0; i<n; i++)
		cout << vetorB[i] << " ";
		
	int opcao;
	float valor;
	struct Fila umaFila;

	// cria a fila
	cout << "\n\nCapacidade da fila:  " << n;

	criarFila(&umaFila, n);

	// apresenta menu
	while( 1 ){

		cout << "\n1 - Inserir vetor B\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpcao? ";
		cin >> opcao;

		switch(opcao){

			case 0: exit(0);

			case 1: // insere vetor b
				if (estaCheia(&umaFila)){

					cout << "\nFila Cheia!!!\n\n";

				}
				else {
					
					cout << "\nVetor B inserido com sucesso! \n";
					for (i=n; i>=0; i--){
	
						valor = vetorB[i];
						inserir(&umaFila,valor);
						valor = 0;
					}
				
				}

				break;

			case 2: // remove elemento
				if (estaVazia(&umaFila)){

					cout << "\nFila vazia!!!\n\n";

				}
				else {

					valor = remover(&umaFila);
					cout << valor << " removido com sucesso\n\n"; 

				}
				break;

			case 3: // mostrar fila
				if (estaVazia(&umaFila)){

					cout << "\nFila vazia!!!\n\n";

				}
				else {

					cout << "\nConteudo da fila => ";
					mostrarFila(&umaFila);

				}
				break;

				default:
					cout << "\nOpcao Invalida\n\n";

		}
	}
	
	
	cout << endl << endl;
	system ("Pause");
	return 0;
}