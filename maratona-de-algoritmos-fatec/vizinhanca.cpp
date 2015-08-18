#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

	int l = 3;
	int c = 3; 
	int i, j;
	char lotes[l][c];
	int achou = 0;
	

	cout << "Informe a qtd de linhas: ";
	cin >> l;

	cout << "Informe a qtd de colunas: ";
	cin >> c;

	//validacao
	if (((l <= 0 )||(l > 1000)) && ((c <= 0)||(c > 1000))){
		cout << "\nValores invalidos! \nTente Novamente. \n";

		cout << "Informe a qtd de linhas: ";
			cin >> l;

		cout << "\nInforme a qtd de colunas: ";
			cin >> c;
	}
	
/*	
	//teste para preencher lotes automaticamente
	for (i=0; i<l; i++){
		for (j=0; j<c; j++){
			lotes[i][j] = 'a';
		}
	}

*/

	
	//preenche manual
	cout << "\nInsira os moradores nos lotes: \n";	
	for (i=0; i<l; i++){
		for (j=0; j<c; j++){
			cin >> lotes[i][j];
		}
	}


	//mostra lotes
	cout << endl << "Lotes: " << endl;
	for (i=0; i<l; i++){
		for (j=0; j<c; j++){
			cout << lotes[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
	
	//Primeira verificação (a com b)
	for (i=0; i<l; i++){
		for (j=0; j<c; j++){
		    if (lotes[i][j]=='a'){
		            if ((lotes[i][j+1]=='b') || (lotes[i][j-1]=='b')){
		                achou =+ 1;
		            }
		    }
		}
	}
	
	//Segunda verificação (a com d)
		for (i=0; i<l; i++){
		for (j=0; j<c; j++){
		    if (lotes[i][j]=='a'){
		            if ((lotes[i][j+1]=='d') || (lotes[i][j-1]=='d')){
		                achou =+ 1;
		            }
		    }
		}
	}
	
	//Terceira verificação (b com a)
	for (i=0; i<l; i++){
		for (j=0; j<c; j++){
		    if (lotes[i][j]=='b'){
		            if ((lotes[i][j+1]=='a') || (lotes[i][j-1]=='a')){
		                achou =+ 1;
		            }
		    }
		}
	}
	
	//Quarta verificação (b com c)
	for (i=0; i<l; i++){
		for (j=0; j<c; j++){
		    if (lotes[i][j]=='b'){
		            if ((lotes[i][j+1]=='c') || (lotes[i][j-1]=='c')){
		                achou =+ 1;
		            }
		    }
		}
	}
	
	//Quinta verificação (d com a)
	for (i=0; i<l; i++){
		for (j=0; j<c; j++){
		    if (lotes[i][j]=='d'){
		            if ((lotes[i][j+1]=='a') || (lotes[i][j-1]=='a')){
		                achou =+ 1;
		            }
		    }
		}
	}
	
	if (achou == 0){
	    cout << 'V';
	}else{
	    cout << 'F';
	}
	
		                
	//system ("Pause");
	return 0;
}
