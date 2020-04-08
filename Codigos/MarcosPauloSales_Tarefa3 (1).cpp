#include <iostream>
using namespace std;

struct no
{
	int info;
	struct no*prox;
	struct no*ant;
};

struct lista
{
	no*inicio;
	no*fim;
};

typedef struct no*noPtr ;
typedef lista& listaRef;
// Espaco das funcoes
int menu();
bool listaVazia(lista);
int inserir(listaRef);
void remover(listaRef, int *q);
void listar(lista, int *);
int menu();

//Termino do espaco
int main()
{
	lista d;
	d.fim = NULL;
	d.inicio = NULL;

	int op, qtde = 0;
	do
	{
		op = menu();
		switch(op)
		{
		case 1:
			qtde += inserir(d);
			break;
		case 2:
			remover(d, &qtde);
			break;
		case 3:
			listar(d, &qtde);
			break;
		case 0:
			break;
		}
	}
	while(op != 0);
	return 0;
}

bool listaVazia(lista d)
{

	if(d.fim == NULL)
		return true;
	else
		return false;
}

int inserir(listaRef d)
{
	noPtr p = new no ;
	cout << "Digite o elemento para inserir " << endl;
	cin >> p->info;

	if(listaVazia(d))
	{
		d.inicio = p;
		d.fim = p;
		p->prox = p;
	}
	else
	{
	//	p->prox = d.inicio;
		d.fim->prox = p;
		d.inicio = p;
	}

	return 1;
}


void remover(listaRef d, int *q)
{
	int num;
	cout << "DIGITE " << endl;
	cin >> num;
	noPtr p = d.inicio;

	if(!listaVazia(d))
	{
		for(int i = 0; i < *q; i++)
		{
			if(num == p->info)
			{
				if(*q == 1)
				{
					d.inicio = NULL;
					d.fim = NULL;
				}
				else
				{
					if(d.inicio == p)
					{
						d.inicio = p->prox;
						p->prox->ant = d.inicio;
					}
					else if(d.fim == p)
					{
						d.fim = p->ant;
						d.fim->prox = p->prox;
					}
					else
					{
						p->ant ->prox = p->prox;
						p->prox -> ant = p->ant;
					}
					delete(p);
					*q -= 1;
				}
			}
			p = p->prox;
		}
	}
	else
	{
		cout << "VAZIO" << endl;
	}

}


void listar(lista d, int *q)
{
	noPtr p = d.inicio;

	if(!listaVazia(d))
	{
		for(int m = 0 ; m < *q ; m++)
		{
			cout << p-> info << endl;
			p = p->prox;
		}
	}
	else
	{
		cout << "lista Vazia " << endl;
	}
}

int menu()
{
	int op;
	cout << "Digite 1 para inserir " << endl;
	cout << "Digite 2 para remover " << endl;
	cout << "Digite 3 para listar " << endl;
	cout << "Digite 0 para sair " << endl;
	cin >> op;
	return op;
}


