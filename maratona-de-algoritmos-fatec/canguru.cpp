#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 5

using namespace std;

int main(){
	
	srand(time(0));
	
	int cercado[4][4];
	int i, j;	
	int soma_l0;
	int soma_l1;
	int soma_l2;
	int soma_l3;
	int soma_c0;
	int soma_c1;
	int soma_c2;
	int soma_c3;
	int correto;
	
	int cont = 0;

	while (cont < N){

    	soma_l0 = 0;
    	soma_l1 = 0;
    	soma_l2 = 0;
    	soma_l3 = 0;
    	soma_c0 = 0;
    	soma_c1 = 0;
    	soma_c2 = 0;
    	soma_c3 = 0;
    	correto = 0;
    

    	//preenche automatico
    	for (i=0; i<4; i++)
    		for (j=0; j<4; j++)
    			cercado[i][j] = rand() % 2;

    
    	//soma de linhas	
    	for (j=0; j<4; j++)
    		soma_l0 += cercado[0][j];
    
    	for (j=0; j<4; j++)
    		soma_l1 += cercado[1][j];
    
    	for (j=0; j<4; j++)
    		soma_l2 += cercado[2][j];
    
    	for (j=0; j<4; j++)
    		soma_l3 += cercado[3][j];
    
    
    	//soma de colunas
    	for (i=0; i<4; i++)
    		soma_c0 += cercado[i][0];
    
    	for (i=0; i<4; i++)
    		soma_c1 += cercado[i][1];
    
    	for (i=0; i<4; i++)
    		soma_c2 += cercado[i][2];
    
    	for (i=0; i<4; i++)
    		soma_c3 += cercado[i][3];
    
    
    	//testes	
    	if ((soma_l0 == 2) && (soma_c0 == 2))
    		correto += 1;
    
    	
    	if ((soma_l1 == 2) && (soma_c1 == 2))
    		correto += 1;
    	
    	if ((soma_l2 == 2) && (soma_c2 == 2))
    		correto += 1;
    
    	if ((soma_l3 == 2) && (soma_c3 == 2))
    		correto += 1;
    
    
    	cout << "\n\nCaso " << cont+1 << ": " << endl << endl;	
    
    	//imprime cercado
    	for (i=0; i<4; i++){
    		for (j=0; j<4; j++){
    			cout << " " << cercado[i][j];
    		}
    		cout << endl;
    	}
    
    	/*
    	//Impressao de teste
    	cout << "\nSoma Linha 0: " << soma_l0;
    	cout << "\nSoma Linha 1: " << soma_l1;
    	cout << "\nSoma Linha 2: " << soma_l2;
    	cout << "\nSoma Linha 3: " << soma_l3;
    
    	cout << "\n\nSoma coluna 0: " << soma_c0;
    	cout << "\nSoma coluna 1: " << soma_c1;
    	cout << "\nSoma coluna 2: " << soma_c2;
    	cout << "\nSoma coluna 3: " << soma_c3  << endl;
    	*/
    	
    	//cout << "\n\nCorreto vale: " << correto;
    	if (correto == 4){
    		cout << "\nCorreto \n";
    	}else{
    		cout << "\nNecessario mover canguru \n";
    	}

	cout << "------------------------------";
    	cont += 1;
	
	}

	//system ("Pause");
	return 0;
}

