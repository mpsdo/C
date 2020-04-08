/*Questão 3 (3.0) Implemente as seguintes funções de uma árvore binária
 de busca:
  A. Inserir na árvore.
  B. Mostrar os nós folhas da árvore.
  C. Mostrar todos os nós da árvore (informe a ordem escolhida: em ordem, pós-ordem ou préordem). */

#include <iostream>
using namespace std;

struct no
{
	int info;
	struct no*dir;
	struct no*esq;
};

typedef struct no*noPtr;

// inicio dos codigos

void inserir(noPtr *p, int x);
int menu();
bool arvoreVazia(noPtr p);

// fim dos codigos



int main()
{
	noPtr raiz = NULL;
	int x = 0;
	int op;
	bool achei = false;
	//int op2;

	do
	{
		op = menu();
		switch(op)
		{
		case 1:
			cout << "Digite o valor que queira adicionar " << endl;
			cin >> x;
			inserir(&raiz, x);
			break;
		case 2:
			cout << "digite o elemento que queira encontrar  " << endl;
			cin >> num;

			achei = buscar(raiz, x);

			if(achei == true)
			{
				cout << "Elemento encontrado " << endl;
			}
			else
			{
				cout << "Elemento nao encontrado " << endl;
			}
			break;
		case 3:
			cout << "Digite o elemento que queira remover " << endl;
			cin >> x;
			remover(&raiz, x);
			break;
		case 0:
			break;
		}
	}
	while(op != 0);

	return 0;
}

bool arvoreVazia(noPtr raiz)
{
	return raiz == NULL;
}

void inserir(noPtr *p, int x)
{

	if(arvoreVazia(*p))
	{
		*p = new no;
		(*p)->dir = NULL;
		(*p)->esq = NULL;
		(*p)->info = x;
		cout << "Elemento adicionado " << endl;
	}
	else
	{
		if((*p)->info < x)
		{
			inserir(&((*p)->dir), x);
		}
		else
		{
			inserir(&((*p)->esq), x);
		}
	}
}

bool buscar(noPtr p, int x)
{
	if(arvoreVazia(p))
	{
		return false;
		cout << "Arvore vazia" << endl;
	}
	else
	{
		if(x == p->info)
		{
			return true;
			cout << "ELemento encontrado " << endl;
		}
		else
		{
			if(x < p->info)
			{
				buscar(p->esq, x);
			}
			else
			{
				buscar(p->dir, x);
			}
		}
	}
}

void remover(noPtr *p, int x)
{
	noPtr aux = *p;
	if(arvoreVazia(*p))
	{
		cout << "Arvore Vazia " << endl;
	}
	else
	{
		if( x == aux->info)
		{
			if(aux->esq == NULL)
			{
				*p = aux->dir;
			}
			else if(aux->dir == NULL)
			{
				*p = aux->esq;
			}
			else
			{
				// os dois nao sao nulos
				maior(aux->esq)->dir = aux->dir;
				*p = aux->esq;
			}
			delete aux;
			cout << "Elemento removido " << endl;
		}
		else if (x < aux->info)
		{
			remover(&((*p)->esq),x);
		}
		else
		{
			remover(&((*p)->dir),x);
		}



	}



}

noPtr maior(noPtr p)
{
	if(p->dir == NULL)
	{
		return p;
	}
	else
	{
		return maior(p->dir);
	}
}

int menu()
{
	int op;
	cout << "1: PARA INSERIR " << endl;
	cin >> op;
	return op;
}
