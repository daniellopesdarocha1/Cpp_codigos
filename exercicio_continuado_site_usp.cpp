#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

#define N 100

//busca interativa
int busca ( int x, int n, int v[]){

    int k;
       for (k = n-1; k >= 0; --k) 
          if (v[k] == x) return k;
       return -1; 

}

//busca recursiva
int busca_r (int x, int n, int v[]){
    
   if (n == 0) return -1;
   if (x == v[n-1]) return n-1;
   return busca_r( x, n-1, v);
}

int buscaBinaria( int x, int n, int v[]) {
   int e, m, d;                              
   e = 0; d = n-1;                           
   while (e <= d) {                          
      m = (e + d)/2;                         
      if (v[m] == x) return m;               
      if (v[m] < x) e = m + 1;               
      else d = m - 1;                        
   }                                         
   return -1;                                
}    

int remove ( int k, int n, int v[]){
    
   int j;
   for (j = k+1; j < n; ++j)
      v[j-1] = v[j];
   return n - 1;
}

int remove_r( int k, int n, int v[]){
    
   if (k == n-1) return n - 1;
   else {
      v[k] = v[k+1];
      return remove_r( k+1, n, v); 
   }
}

int insere( int k, int x, int n, int v[]){
    
   int j;
   for (j = n; j > k; --j)  
      v[j] = v[j-1];
   v[k] = x;
   return n + 1;
}

int insere_r( int k, int x, int n, int v[]){
   
   if (k == n)  v[n] = x;
   else {
      v[n] = v[n-1];
      insere_r( k, x, n - 1, v);
   }
   return n+1;
}

// Insertion sort
void insercao( int n, int v[]){
   int i, j, x;
   for (j = 1; j < n; ++j) {
      x = v[j];
      for (i = j-1; i >= 0 && v[i] > x; --i) 
         v[i+1] = v[i];
      v[i+1] = x;
   }
}

// Selection sort
void selecao( int n, int v[]){
   int i, j, min, x;
   for (i = 0; i < n-1; ++i) {
      min = i;
      for (j = i+1; j < n; ++j)
         if (v[j] < v[min])  min = j;
      x = v[i]; v[i] = v[min]; v[min] = x;
   }
}

//Bubble Sort
void bubble( int qtd, int v[]){
  int i;
  int j;
  int aux;
  int k = qtd - 1 ;

  for(i = 0; i < qtd; i++){
     for(j = 0; j < k; j++){ 
		if(v[j] > v[j+1]){
            aux = v[j];
        	v[j] = v[j+1];
        	v[j+1]=aux;
        }
	 }
     k--;
  }
}

void *mallocc( size_t nbytes){
   void *ptr;
   ptr = malloc( nbytes);
   if (ptr == NULL) {
      printf( "Socorro! malloc devolveu NULL!\n");
      exit( EXIT_FAILURE);
   }
   return ptr;
}

//Merge sort
void intercala1( int p, int q, int r, int v[]){
   int i, j, k, *w;
   w = (int *) mallocc( (r-p) * sizeof (int)); // a funcao mallocc funcionou apenas com o typecasting (int *)
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
      intercala1( p, q, r, v);
   }
}


void constroi_heap( int n, int v[]){
   int m, f, t;
   for (m = 1; m < n; ++m) {
      f = m+1;
      while (f > 1 && v[f/2] < v[f]) { 
         t = v[f/2], v[f/2] = v[f], v[f] = t;
         f = f/2;
      }
   }
}

void bottom_up_heapsort( int n, int v[]){
   int m, f, max, t;
   constroi_heap( n, v);
   for (m = n; m > 1; --m) {
      max = v[1];
      f = 2;
      while (f <= m) {
         if (f < m && v[f] < v[f+1]) ++f;
         v[f/2] = v[f];
         f *= 2;
      }
      f = f/2;
      if (f < m) {
         t = v[f], v[f] = v[m], v[m] = t;
         while (f > 1 && v[f/2] < v[f]) { 
            t = v[f], v[f] = v[f/2], v[f/2] = t;
            f = f/2;
         }
      }
      v[m] = max;
   }
}

//QuickSort
int separa( int v[], int p, int r){
   int c = v[p], i = p+1, j = r, t;
   while (i <= j) {
      if (v[i] <= c) ++i;
      else if (c < v[j]) --j; 
      else {
         t = v[i], v[i] = v[j], v[j] = t;
         ++i; --j;
      }
   }
   // agora i == j+1                 
   v[p] = v[j], v[j] = c;
   return j; 
}

void quicksort( int v[], int p, int r){
   int j;                         
   if (p < r) {                   
      j = separa( v, p, r);       
      quicksort( v, p, j-1);      
      quicksort( v, j+1, r);      
   }
}

// A função recebe um vetor v[0..n-1] e inicializa 
// os indices em zero.
void clear(int v[]){

	int i;

	for( i = 0; i < N; i++) {
		v[i] = 0;
	} 
}


int sorteio (int x){
    return rand() % x;   
}

void menu(){
    cout << "\n\nMenu ";
    cout << "\n[1] Busca Iterativa; ";
    cout << "\n[2] Busca Recursiva; ";
    cout << "\n[3] Busca Binaria; ";
    cout << "\n[4] Remocao; ";
    cout << "\n[5] Remocao Recursiva; ";
    cout << "\n[6] Insercao; ";
    cout << "\n[7] Insercao Recursiva; ";
    cout << "\n[8] Ordenacao Insertion sort; ";
    cout << "\n[9] Ordenacao Selection sort. ";
    cout << "\n[10] Ordenacao Bubble sort. ";
    cout << "\n[11] Ordenacao Merge sort. ";
    cout << "\n[12] Ordenacao Heap sort. ";
    cout << "\n[13] Ordenacao Quick sort. ";
    cout << endl;
}

int main(){
    
    srand(time(0));
    
    int i;
    int vet[N];
    int valor;
    int escolha;
    int pos;
    
    //preenche vetor
    for (i=0; i<N; i++){
        vet[i] = sorteio(100);
    }
    
    cout << "O Vetor possui " << N << " elementos. " << endl;
    
    //mostra vetor
    for (i=0; i<N; i++)
        cout << "\nPosicao: " << i << " Valor: " << vet[i];
    
    menu ();
    cout << "\nEscolha uma opcao:  ";
    cin  >> escolha;

    switch (escolha){
        case 1: 
            cout << "\n(Busca Sequencial) ";
            cout << "\nInforme o valor a ser buscado: ";
            cin  >> valor;
            
            cout << "\nO valor foi encontrado na posicao: " << busca (valor, N, vet);
            break;

        case 2:
            cout << "\n(Busca Recursiva) ";
            cout << "\nInforme o valor a ser Buscado: ";
            cin  >> valor;
            
            cout << "\nO valor foi encontrado na posicao: " << busca_r (valor, N, vet);
            break;

        case 3:
            cout << "\n(Busca Binaria) ";
            cout << "\nInforme o valor a ser Buscado: ";
            cin  >> valor;
            
            bubble (N, vet);
            cout << "\nO valor foi encontrado na posicao: " << buscaBinaria(valor, N, vet);
            break;

        case 4:
            cout << "\n(Remocao) ";
            cout << "\nInforme a posicao a ser removida: ";
            cin  >> pos;
            
            cout << "\nValor removido com sucesso! ";
            cout << "\nAgora o Vetor possui " << remove (pos, N, vet) << " elementos. " << endl;
            
            //mostra vetor
            for (i=0; i<N; i++)
                cout << "\nPosicao: " << i << ", Valor: " << vet[i];    
            break;

        case 5:
            cout << "\n(Remocao Recursiva)";
            cout << "\nInforme a posicao a ser removida: ";
            cin  >> pos;
            
            cout << "\nValor removido com sucesso! ";
            cout << "\nAgora o vetor possui " << remove_r (pos, N, vet) << " elementos. " << endl;
            
            //mostra vetor
            for (i=0; i<N-1; i++)
                cout << "\nPosicao: " << i << " Valor: " << vet[i];
            break;

        case 6:
            cout << "\n(Insercao) ";
            cout << "\nInforme a posicao a ser ocupada: ";
            cin  >> pos;
            
            cout << "\nInforme o valor a ser inserido: ";
            cin  >> valor;
            
            cout << "\nValor inserido com sucesso! ";
            cout << "\nAgora o vetor possui " << insere (pos, valor, N, vet) << " elementos. " << endl;
            
            //mostra vetor
            for (i=0; i<N+1; i++)
                cout << "\nPosicao: " << i << " Valor: " << vet[i];
            break;

        case 7:
            cout << "\n(Insercao Recursiva) ";
            cout << "\nInforme a posicao a ser ocupada: ";
            cin  >> pos;
            
            cout << "\nInforme o valor a ser inserido: ";
            cin  >> valor;
            
            cout << "\nValor inserido com sucesso! ";
            cout << "\nAgora o vetor possui " << insere_r (pos, valor, N, vet) << " elementos. " << endl;
            
            //mostra vetor
            for (i=0; i<N+1; i++)
                cout << "\nPosicao: " << i << " Valor: " << vet[i];
            break;

        case 8:
            cout << "\n(Ordenacao Insertion sort)";
            insercao (N, vet);
            
            cout << "\nO Vetor foi organizado com sucesso! " << endl;
            
            //mostra vetor
            for (i=0; i<N; i++)
                cout << "\nPosicao: " << i << " Valor: " << vet[i];
            break;

        case 9:
            cout << "\n(Ordenacao Selection sort)";
            selecao (N, vet);
            
            cout << "\nO Vetor foi organizado com sucesso! " << endl;
            
            //mostra vetor
            for (i=0; i<N; i++)
                cout << "\nPosicao: " << i << " Valor: " << vet[i];
            break;

        case 10:
            cout << "\n(Ordenacao Bubble sort)";
            bubble (N, vet);
            
            cout << "\nO Vetor foi organizado com sucesso! " << endl;
            
            //mostra vetor
            for (i=0; i<N; i++)
                cout << "\nPosicao: " << i << " Valor: " << vet[i];
            break;
 
        case 11:
            cout << "\n(Ordenacao Merge sort)";
            intercala1( 0, N/2, N, vet);
            mergesort ( 0, N, vet);
            
            cout << "\nO Vetor foi organizado com sucesso! " << endl;
            
            //mostra vetor
            for (i=0; i<N; i++)
                cout << "\nPosicao: " << i << " Valor: " << vet[i];
            break;
		
		case 12:
            cout << "\n(Ordenacao Heap Sort)";

            constroi_heap(N, vet);
            bottom_up_heapsort( N, vet);

            
            cout << "\nO Vetor foi organizado com sucesso! " << endl;
            
            //mostra vetor
            for (i=0; i<N; i++)
                cout << "\nPosicao: " << i << " Valor: " << vet[i];
            break;
            
        case 13:
            cout << "\n(Ordenacao Quick Sort)";

            quicksort(vet, 0, N);

            
            cout << "\nO Vetor foi organizado com sucesso! " << endl;
            
            //mostra vetor
            for (i=0; i<N; i++)
                cout << "\nPosicao: " << i << " Valor: " << vet[i];
            break;
        
		default: 
            cout << "\nOpcao Invalida. ";
    }
    
	
	system("Pause");
    return 0;
}
