#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define n 5

struct tipogado{
    int cod;
    double alim;
    double leite;
    int nasc;
    int abate;
};

int sorteio (int x){
    return rand() % x;
}

void mostragado (tipogado m){
    cout << "Código: "                     << m.cod;
    cout << "\n Alimento consumido: "      << m.alim;
    cout << "\n Leite produzido: "         << m.leite;
    cout << "\n Ano de nascimento: "       << m.nasc;
    cout << "\n Abate [1 SIM]/[0 NÃO]: "   << m.abate;
    cout << endl << endl;
}

void menu(){
    cout << "---------------Menu------------------------------";
    cout << "\n[1] - Alimento consumido na semana. ";
    cout << "\n[2] - Leite produzido na semana. ";
    cout << "\n[3] - Alimento consumido após abate. ";
    cout << "\n[4] - Leite produzido após abate. ";
    cout << "\n[5] - Total de gados abatidos. ";
    cout << "\n--------------------------------------------------";
}

int main(){
    
    srand (time(0));
    struct tipogado lista [n];
    int i, ano, somaabate, op;
    double somaleite, somaalim;
    double somaleite2, somaalim2;
    
    
    for (i=0; i<n; i++){
        lista[i].cod   = i+1;
        lista[i].alim  = sorteio(80);
        lista[i].leite = sorteio(100);
        lista[i].nasc  = sorteio(15) + 2000;
        
        ano = 2014 - lista[i].nasc;
            
        if (ano > 5 || lista[i].leite < 40){
            lista[i].abate = 1; //sim
        }else{
            lista[i].abate = 0; //nao
        }
    }
    
    for (i=0; i<n; i++){
        mostragado (lista[i]);
    }
    
    somaleite = 0;
    somaalim  = 0;
    somaleite = 0;
    somaalim2 = 0;
    somaabate = 0;
    
    for (i=0; i<n; i++){
        somaalim  = somaalim  + lista[i].alim;
        somaleite = somaleite + lista[i].leite;
        
        //após abate
        if (lista[i].abate == 1){
            somaalim2  = somaalim2  + lista[i].alim;
            somaleite2 = somaleite2 + lista[i].leite;
        }else{
            somaabate = somaabate + 1;
        }
    }
    
    menu();   
    
    while (op != 6){
        cout << "\n\nEscolha uma das opções acima: ";
        cin  >> op;
        
  
  // SUBSTITUI ESTE BLOCO DE IF ABAIXO UTILIZANDO O "DEFAULT" DO SWITCH.
  
        /*if (op <= 0 || op > 6){
            cout << "\nOpção Inválida.";
        }else{
            cout << "\n\nEscolha uma das opções acima: ";
            cin  >> op;
        }*/
        
  
  //MODO CORRETO PARA IDENTAR O BREAK DENTRO DO CASE.
        switch (op){
            case 1: 
                cout << "\nAlimento consumido na semana: " << somaalim;
                break;
            case 2:
                cout << "\nLeite produzido na semana: " << somaleite;
                break;
            case 3:
                cout << "\nAlimento consumido após abate: " << somaalim2;
                break;
            case 4:
                cout << "\nLeite produzido após abate: " << somaleite2;
                break;
            case 5:
                cout << "\nTotal de gados abatidos: " << somaabate;
                break;
            case 6: 
                cout << "Programa Encerrado. ";
                return 0;
                break;
   default:
    cout << "Erro! " << "Opção Inválida. ";
        }
    }
    
    //system ("Pause");
    return EXIT_SUCCESS;
}
