/*
Faça um programa que crie um array de 50 elementos inteiros.
Depois implemente as funções:
– FazListaVazia(Lista) : faz a lista ficar vazia.
– Insere(x, Lista) : insere x após o último item da lista.
– Retira(Lista, x)
• Retira o item x que está na lista (fazendo o deslocamentos dos itens sucessivos
ao valor a ser retirado).
*/



#include <iostream>
using namespace std;

struct no
{
	int info;
	struct no*prox;
	struct no*ant;
};

typedef struct no*noPtr;

int main(int argc, char** argv)
{
	int op;
	
	noPtr inicio = NULL;
//int vetor[50]; Pra que isso ?

	do
	{
		op = menu();
		switch(op)
		{
		case 1:
			cout << "Digite o valor que queira inserir " << endl;
			cin >> valor;
			inserir(&inicio, x);
			break;
		case 2:
			cout << "Digite o elemento que queira remover " << endl;
			cin >> valor;

			break;
		case 3:
			break;


		}
	}
	while(op != 0);



	return 0;
}

bool listaVazia(noPtr *p)
{
	if(p == NULL)
		return true;
	else
	{
		return false;
	}
}

int inserir(noPtr *start , int x)
{
	noPtr p = new no;
	p->info = x;

	if(listaVazia(p))
	{
		*start = p;
		p->prox = NULL;
	}
	else
	{
		noPtr aux = *start;
		*start = p;
		p->prox = aux;
	}

	cout << "Elemento adicionado " << endl;
}

void remover(noPtr *p , int x)
{
	noPtr p = *start;
	noPtr aux = new no;
	int contador = 0;

	if(!listaVazia(p))
	{
		while(p != NULL)
		{
			contador += 1;
			aux = p;
			if(contador == 1)
			{
				if(p->info == x)
				{
					*start = NULL;
					cout << "elemento removido " << endl;
				}
			}
			else if(p->info == x)
			{
				*start = p->prox;
				delete(p);
			}
			p = p->prox;
		}
	}
}

void imprimir(noPtr *start)
{
	noPtr p = *start;
	while(p!=NULL)
	{
		cout << p->info << endl;
	}
}