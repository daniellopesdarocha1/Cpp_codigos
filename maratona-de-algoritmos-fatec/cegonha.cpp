#include <cstdlib>
#include <iostream>
#include <cmath>

//Autores: Maisa e Daniel
//Data de início: 27-02-2015 
//Ultima atualização: 01-03-2015

using namespace std;

/*
n = qtd de gestantes
h = altura
o = peso anterior
a = peso atual

IMC =  peso / altura ²
*/

struct tipoGestante {
  
    float h;
    float o;
    float a;
    float imco;
    float imca;
    float ganhoDePeso;
};


int main(){
   
   int i;
   int n;
   
   cout << "Quantas gestantes serao avaliadas? ";
   cin  >> n;
   
   cout << endl; 
   
   tipoGestante lista[n];
   
   for (i=0; i<n; i++){
       
       cout << i+1 << "a Gestante: " << endl;
       cout << "Informe a altura: ";
       cin  >> lista[i].h;
       
       cout << "Informe o peso anterior: ";
       cin  >> lista[i].o;
       
       lista[i].imco = lista[i].o / pow(lista[i].h, 2);
       
       
       cout << "Informe o peso atual: ";
       cin  >> lista[i].a;
       
       lista[i].imca = lista[i].a / pow(lista[i].h, 2);
       
       lista[i].ganhoDePeso = lista[i].a - lista[i].o;
       
       cout << endl;

   }
   
   for (i=0; i<n; i++){
       
       cout << i+1 << "a Gestante: ";
       cout << "\nIMC anterior: " << lista[i].imco;
       cout << "\nIMC atual: " << lista[i].imca;
       cout << "\nGanho de Peso: " << lista[i].ganhoDePeso;
       
       if (lista[i].imca < 18.5){
           if (lista[i].ganhoDePeso >= 12.5 && lista[i].ganhoDePeso <= 18){
                cout << "\nGANHO NORMAL " << endl;
                }else if (lista[i].ganhoDePeso < 12.5){
                    cout << "\nGANHO INSUFICIENTE " << endl;
                }else{
                    cout << "\nGANHO EXAGERADO " << endl;
                }
       }
       
       if (lista[i].imca >= 18.5 && lista[i].imca < 25 ){
           if (lista[i].ganhoDePeso >= 11 && lista[i].ganhoDePeso <= 16){
                cout << "\nGANHO NORMAL " << endl;
                }else if (lista[i].ganhoDePeso < 11){
                    cout << "\nGANHO INSUFICIENTE " << endl;
                }else{
                    cout << "\nGANHO EXAGERADO " << endl;
                }
       }
       
       if (lista[i].imca >= 25 && lista[i].imca < 30 ){
           if (lista[i].ganhoDePeso >= 7 && lista[i].ganhoDePeso <= 11.5){
                cout << "\nGANHO NORMAL " << endl;
                }else if (lista[i].ganhoDePeso < 7){
                    cout << "\nGANHO INSUFICIENTE " << endl;
                }else{
                    cout << "\nGANHO EXAGERADO " << endl;
                }
       }
       
       if (lista[i].imca >= 30){
           if (lista[i].ganhoDePeso >= 5 && lista[i].ganhoDePeso <= 9){
                cout << "\nGANHO NORMAL " << endl;
                }else if (lista[i].ganhoDePeso < 5){
                    cout << "\nGANHO INSUFICIENTE " << endl;
                }else{
                    cout << "\nGANHO EXAGERADO " << endl;
                }
       }
       
       cout << endl;
   }
 
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
