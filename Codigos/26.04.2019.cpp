
// Percorrer a lista, somando os nós e mostre o resultado]
// complexidade de pior caso das funcoes a e b

#include <iostream>
using namespace std;


struct no
{
	int info;
	struct no*prox;
};

typedef struct no* noPtr;

bool listaVazia(noPtr p);
void inserir(noPtr *start, int x);
void listar(noPtr *start, noPtr *start2);
int menu();
int listarSoma(noPtr *start, noPtr *start2);


int main()
{
	noPtr inicio1 = NULL;
	noPtr inicio2 = NULL;

	int op = 0;
	int vlr;
	int x = 0;
	int somatorio = 0;

	do
	{
		op = menu();
		switch(op)
		{
		case 1:
			cout << "Deseja inserir na lista 1 ou na lista 2 " << endl;
			cin >> vlr;
			cout << endl;
			cout << "Digite o numero que queira inserir " << endl;
			cin >> x;
			if(vlr == 1 )
			{
				inserir(&inicio1, x);
			}
			else if(vlr == 2)
			{
				inserir(&inicio2, x);
			}
			break;
		case 2:
			listar(&inicio1, &inicio2);
			break;
		case 3:
			somatorio = listarSoma(&inicio1, &inicio2);
			cout << "A soma eh " << somatorio << endl;
			break;
		}
	}
	while(op != 0);



	return 0;
}

bool listaVazia(noPtr p)
{
	if(p == NULL)
		return true;
	else
	{
		return false;
	}
}

void inserir(noPtr *start, int x)
{
	noPtr p = new no;
	p ->info = x;

	if(listaVazia(*start))
	{
		*start = p;
		p->prox = NULL;
		cout << "Elemento inserido " << endl;
	}
	else
	{
		noPtr aux = *start;
		*start = p;
		p->prox = aux;
		cout << "Elemento inserido " << endl;
	}
}

void listar(noPtr *start, noPtr *start2)
{
	noPtr p = *start;

	while(p != NULL)
	{
		cout << p->info << endl;
		p = p->prox;
	}
	p = *start2;
	while(p != NULL)
	{
		cout << p->info << endl;
		p = p->prox;
	}
}

int listarSoma(noPtr *start, noPtr *start2)
{
	noPtr p = *start;
	int somatorio = 0;

	while(p != NULL)
	{
		somatorio += p->info;
		p = p->prox;
	}
	p = *start2;
	while(p != NULL)
	{
		somatorio+= p->info;
		p = p->prox;
	}
	return somatorio;
}


int menu()
{
	int op;
	cout << "1: PARA INSERIR " << endl;
	cout << "2: PARA listar " << endl;
	cout << "3: PARA para somar " << endl;
	cin >> op;
	return op;
}
