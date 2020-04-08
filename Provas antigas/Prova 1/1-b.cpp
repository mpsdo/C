#include <iostream>
using namespace std;

struct no
{
	int info;
	struct no*prox;
};
typedef struct no*noPtr;

void listar(noPtr *start, noPtr *start2);
void inserir(noPtr *start);
void inserir2(noPtr *start2);
int menu();
bool listaVazia2(noPtr *start2);
bool listaVazia(noPtr *start);


int main()
{
	noPtr inicio = NULL;
	noPtr inicio2 = NULL;
	int op;
	int op2;


	do
	{
		op = menu();
		switch(op)
		{
		case 1:
			cout << "Digite 1 para lista 1  \t Digite 2 para lista 2 " << endl;
			cin >> op2;
			if(op2 == 1)
			{
				inserir(&inicio);
				break;
			}
			if(op2 == 2 )
			{
				inserir2(&inicio2);
				break;
			}
			else
			{
				cout << " Numero invalido " << endl;
				break;
			}
		case 2:
			listar(&inicio, &inicio2);
			break;
		case 0:
			break;
		}

	}
	while(op != 0);


	return 0;
}

bool listaVazia(noPtr *start)
{
	//noPtr p = new no;
	if(*start == NULL)
		return true;
	else
	{
		return false;
	}

}
bool listaVazia2(noPtr *start2)
{
	if(*start2 == NULL)
		return true;
	else
	{
		return false;
	}

}
void listar(noPtr *start, noPtr *start2)
{
	noPtr p = new no;

	p = *start;
	while(p != NULL)
	{
		cout << p->info << endl;
		if(p->prox == NULL)
		{
			p = *start2;
		}
	}


}
void inserir(noPtr *start)
{
	noPtr p = new no;
	cout << "Digite o numero que queira inserir " << endl;
	cin >> p->info;

	if(*start == NULL)
	{
		*start = p;
		p->prox = NULL;
	}
	else
	{
		noPtr aux = new no;
		aux = *start;
		*start = p ;
		p->prox = aux;
	}
}
void inserir2(noPtr *start2)
{
	noPtr p = new no;
	cout << "Digite o numero que queira inserir " << endl;
	cin >> p->info;


	if(*start2 == NULL)
	{
		*start2 = p;
		p->prox = NULL;
	}
	else
	{
		noPtr aux2 = new no;
		aux2 = *start2;
		*start2 = p ;
		p->prox = aux2;
	}
}
int menu()
{
	int op;
	cout << "Digite 1 para inserir " << endl;
	cout << "Digite 2 para listar " << endl;
	cin >> op;
	return op;
}
