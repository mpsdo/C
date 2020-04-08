/*Considere listas de valores inteiros e implemente uma função que receba como parâmetro uma lista encadeada e
um valor inteiro n, retire da lista todas as ocorrências de n e retorne a lista resultante. */


#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct no
{
	int info;
	struct no*prox;
};

typedef struct no*noPtr;


bool listaVazia(noPtr start);
void listar(noPtr start);
void inserir(noPtr *start);
void remover(noPtr *start);
int menu();

int main()
{
	noPtr inicio = NULL;
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
				listar(inicio);
				break;
			case 3:
				remover(&inicio);
				cout << "Elemento removido " << endl;
				break;
			case 0:
				break;				
		}
	}while(op!= 0);
	
	
	
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

void listar(noPtr start)
{
	noPtr p = new no;
	p = start;

	while(p != NULL)
	{
		cout << p->info << endl;
		p = p->prox;
	}
}

void inserir(noPtr *start)
{
	noPtr p = new no;
	cout << "Digite o elemento que queira inserir " << endl;
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
		cout << "Elemento adicionado " << endl;
	}
}

void remover(noPtr *start)
{
	noPtr p = new no;
	p = *start;
	int num;
	cout << "Digite o elemento que queira remover " << endl;
	cin >> num;

	if(listaVazia(*start))
	{
		while(p != NULL)
		{
			if(num == p->info)
			{
				*start = p->prox;
				delete(p);
			}
			p = p->prox;
		}
	}
	else
	{
		cout << "Lista Vazia " << endl;
	}
}
int menu()
{
	int op;
	cout << "Digite 1 para inserir na lista 1 " << endl;
	cout << "Digite 2 para listar" << endl;
	cout << "Digite 3 para remover " << endl;
	cout << " digite 0 para sair " << endl;
	cin >> op;
	return op;

}