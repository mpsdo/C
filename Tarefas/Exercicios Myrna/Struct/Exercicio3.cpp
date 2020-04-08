/*Implemente uma função que receba duas listas encadeadas de valores inteiros e retorne a lista resultante da
concatenação das duas listas recebidas como parâmetros, isto é, após a concatenação, o último elemento da
primeira lista deve apontar para o primeiro elemento da segunda lista. */


#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct no
{
	int info;
	struct no*prox;
};
/*
struct no2
{
	int info;
	struct no2*prox;
};
*/
typedef struct no*noPtr;
//typedef struct no2*noPdf;

//Espaco das funcoes

bool listaVazia(noPtr start);
void inserir(noPtr *start);
void concatenar(noPtr *lista1, noPtr *lista2);
int menu();

//Fim

int main(int argc, char** argv)
{
	noPtr inicio = NULL;
	noPtr inicio2 = NULL;
	int op;
	do
	{
		op = menu();
		switch(op)
		{
		case 1:
			inserir(&inicio);
			break;
		case 2:
			inserir(&inicio2);
			break;
		case 3:
			concatenar(&inicio, &inicio2);
			break;
		case 0:
			break;
		}

	}
	while(op != 0 && op != 3);

	return 0;
}

bool listaVazia(noPtr start)
{
	if(start)
		return false;
	else
	{
		return true;
	}
}
void inserir(noPtr *start)
{
	noPtr p = new no;

	cout << "Digite o elemento que queira inserir na lista 1: " << endl;
	cin >> p->info;

	if(listaVazia(*start))
	{
		*start = p;
		p->prox = NULL;
	}
	else
	{
		noPtr aux = new no;
		aux = *start;
		*start = p;
		p->prox = aux;
		cout << "Elemento adicionado na lista" << endl;
	}
}
/*
void inserirLista2(noPtr *start)
{
	noPtr p = new no;
	p = *start;

	cout << "Digite o elemento que queira inserir na lista 1: " << endl;
	cin >> p->info;

	if(listaVazia(start))
	{
		start = p;
		p->prox = NULL;
	}
	else
	{
		noPtr aux = new no;
		aux = *start;
		*start = p;
		p->prox = aux;
		cout << "Elemento adicionado na lista 1 " << endl;
	}
}
*/
void concatenar(noPtr *lista1, noPtr *lista2)
{
	noPtr p = new no;
	p = *lista1;

	while(p != NULL)
	{
		cout << p->info << endl;

		if(p->prox == NULL)
		{
			p->prox = *lista2;
			p = p->prox;
			while(p != NULL)
			{
				cout << p->info << endl;
				p = p->prox;
			}
		}
		if(p != NULL)
			p = p->prox;
	}

}

int menu()
{
	int op;
	cout << "Digite 1 para inserir na lista 1 " << endl;
	cout << "Digite 2 para inserir na lista 2 " << endl;
	cout << "Digite 3 para concatenar e listar tudo " << endl;
	cout << " digite 0 para sair " << endl;
	cin >> op;
	return op;

}
