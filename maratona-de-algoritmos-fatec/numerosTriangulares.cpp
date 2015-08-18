
//F_Números Triangulares

#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

int main(){

    int N = 1;
    int numero_triangular;
    
    while(N!=0){
                 
             cin >> N;
             cout << endl;
             
             if (N<0 || N>=45000){
                     cout << endl << "Valor Invalido! Tente Novamente." << endl;
                     cout << "Informe o numero: ";
                     cin >> N;
             }
             
             numero_triangular = (N*(N+1))/2;
             
             cout << numero_triangular << endl << endl;
	
    }
    
    	                
	system ("Pause");
	return 0;
}

