#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

int main(){

    int fat = 1;
    int n = 3;
    int i;
    float soma = 0;
    
    do{
        
        cout << "Informe um numero para calcular o seu Euler: ";
        cin >> n;
        
        while (n < 0 || n > 12){
            
            if (n == -1){
                return 0;
            }
            
            cout << "\nValor invalido, tente novamente. \n";
            cout << "Informe um numero para calcular o seu Euler: ";
            cin >> n;    
        }
        
        float vet[n];
        
        for (i=1; i<=n; i++){
            fat = fat * i;
            vet[i] = fat;
            soma = soma + (1/vet[i]);
        }
        
        
        printf("%.6f \n", soma);
        
        soma = 0;
        fat =1;
        //vet[i] = 0;
    
    }while(n != -1);
    
    return 0;
}

