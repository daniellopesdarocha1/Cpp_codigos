#include <iostream>
#include <cstdlib>

using namespace std;

struct tipoProduto{
	
	int q; //quantidade do produto especifico
	float v; // valor do produto especifico
		
};


int main() {
	int n; // n de casos teste a serem processados
	int i;
	int p; // qtd total de produtos
	float d; // dinheiro entregue pelo cliente 
	int cont = 0;
	float total;
	float troco;
	
	cout << "Quantos casos de teste serao processados? ";
	cin >> n;
	
	while (cont < n){
		
		total = 0;
		troco = 0;
		d = 0;
		
		cout << "\n"<<cont+1 << "o Cliente\n\n"; 
		
		cout << "\nInforme a quantidade total de produtos comprados: ";
		cin >> p; // maior que 0 e menor que 50
		
		if ((p < 0) || (p > 50)){
			cout << "\nValor invalido, Tente Novamente. \n";
			cout << "\nInforme a quantidade de produtos comprados: ";
			cin >> p;
		}
		
		struct tipoProduto lista[p];
		
		
		
		for (i=0; i<p; i++){
			
			cout << "\nQtd do produto especifico " << i+1 << ": ";
			cin >> lista[i].q; // maior que 0 e menor que 100
			
			if ((lista[i].q) < 0 || (lista[i].q > 100)){
				cout << "\nValor invalido, Tente Novamente. \n";
				
				cout << "\nQtd do produto especifico " << i+1 << ": ";
				cin >> lista[i].q; 
			}
			
					
			cout << "\nPreco do produto " << i+1 << ": ";
			cin >> lista[i].v; // maior que 0 e menor que 1000

			if ((lista[i].v < 0) || (lista[i].v > 1000)){
				cout << "\nValor invalido, Tente Novamente. \n";
				
				cout << "\nPreco do produto " << i+1 << ": ";
				cin >> lista[i].v; 
			}
			
			total =  total + (lista[i].q * lista[i].v);
			
		}
		
		cout << "\nInforme a quantidade de dinheiro fornecida pelo cliente: ";
		cin >> d;
		
	
		//calcular troco
		if (d < total){
			cout << "\n\nDINHEIRO INSULFICIENTE\n\n";
		}else{
			troco = d - total;
			cout << "\n\nTroco para o cliente: " << troco << endl;		
		}
		
		cout << "\n\n-----------------------------------------------------------\n\n";			
		cont += 1;
		
	}
	
	system ("Pause");
	return 0;
}
