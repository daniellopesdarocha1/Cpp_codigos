#include <iostream>
#include <stdio.h>
#include <cmath>
#include <windows.h>

using namespace std;

int main(){

    float s;
    float n;
    int i;
    float area;
    float soma;
    
    cout << "Digite o lado: ";
 	cin >> s;
 	while (s < 0 || s > 100){
 	    cout << "\nValor invalido, tente novamente. \n";
 	    cout << "Digite o lado: ";
 	    cin >> s;
 	}
 	
 	cout << "Digite o nivel: ";
 	cin >> n;
 	while (n < 0 || n > 16){
 	    cout << "\nValor invalido, tente novamente. \n";
 	    cout << "Digite o nivel: ";
 	    cin >> n;
 	}
 	
 	if (s == 0 && n ==0){
 		return 0;
 	}
 	
 	area = ((s / (2 * 1.732050807568877)) * (s/2));
 	soma = area;
 	
 	for(i=1; i<=n; i++){
 		s = s/3;
 		area = (s * 3 * (pow(4,n-1)));
 		soma += area;
 	}
 	
 	printf ("%.8f", soma);
    
    cout << endl;
    system ("Pause");
    return 0;
}
