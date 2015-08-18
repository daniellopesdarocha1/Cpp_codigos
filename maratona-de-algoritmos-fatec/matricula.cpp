//Problema C - Matricula
//início 17-02-2015  14:34
//ultima atualização 22-02-2015

#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

#define N 3

struct tipoAluno{
	
	double total;
	char nome[30];
	char proximidade[2];
	int renda;
	char bolsaFamilia[2];
	char irmaoMatriculado[2];
	char maeTrabalha[2];
};

void imprimeAluno(struct tipoAluno m){
	cout << "\nNome: "              << m.nome;
	cout << "\nProximidade: "       << m.proximidade;
	cout << "\nRenda: "             << m.renda;
	cout << "\nBolsa Familia: "     << m.bolsaFamilia;
	cout << "\nIrmao matriculado: " << m.irmaoMatriculado;
	cout << "\nMae Trabalha: "      << m.maeTrabalha;
	cout << "\nTotal: "             << m.total;
	cout << endl;
}

//ordena decrescente
void insertionSortTotal (struct tipoAluno *v, int n){
	int i, j;
	struct tipoAluno aux;
	for (i=1; i < n; i++){
		aux = v[i];
		for (j=i; (j>0) && (aux.total > v[j-1].total); j--) //mudar sinal < decres, > cres
			v[j] = v[j-1];
		
		v[j] = aux;
	}
}

int main() {
	
	tipoAluno lista[N];
	int i;
	
	for (i=0; i<N; i++){
		lista[i].total = 500000;
		
		cout << "Nome: ";
		cin  >> lista[i].nome;
		
		cout << "Mora Proximo? ";
		cin  >> lista[i].proximidade;
		
		cout << "Renda: ";
		cin  >> lista[i].renda;
		
		while (lista[i].renda < 0 || lista[i].renda > 10000){
			 cout << "Renda invalida, favor inserir outro valor: ";
			 cin  >> lista[i].renda; 
		}

		cout << "Recebe Bolsa Familia? ";
		cin  >> lista[i].bolsaFamilia;
		
		cout << "Possui irmao nesta escola? ";
		cin  >> lista[i].irmaoMatriculado;
				
		cout << "A mae trabalha fora? ";
		cin  >> lista[i].maeTrabalha;
		
			
		if (strcmp(lista[i].proximidade, "s") == 0 )      lista[i].total += 40000;
		lista[i].total =                    			  lista[i].total - lista[i].renda; 
		if (strcmp(lista[i].bolsaFamilia, "s") == 0 )     lista[i].total += 0.5;
		if (strcmp(lista[i].irmaoMatriculado, "s") == 0 ) lista[i].total += 0.2;
		if (strcmp(lista[i].maeTrabalha, "s") == 0 )      lista[i].total += 0.1;

		
		cout << endl;
	}
	
	//for (i=0; i<N; i++)
	//	imprimeAluno (lista[i]);
		
	insertionSortTotal(lista,N);
	
	cout << endl;
	for (i=0; i<N; i++){
		cout << i+1 << " - " << lista[i].nome << endl;
	}
	
	system ("Pause");	
	return 0;
}
