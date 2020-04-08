
/*Implemente uma função que tenha como valor de retorno o comprimento de uma lista encadeada, isto é, que
calcule o número de nós de uma lista. */
#include <iostream>
using namespace std;

struct no
{
	int info;
	struct no*prox;
};
typedef struct no*noPtr;

int cont(noPtr inicio);
bool listaVazia(noPtr inicio);
int menu();
int inserir(noPtr *alfa);

int main()
{
	noPtr inicio = NULL;
	int op;
	int valor;
	do
	{
		op = menu();
		switch(op)
		{
		case 1:
			inserir(&inicio);
			break;
		case 2:
			valor = cont(inicio);
			cout << "O valor dos quadrados eh " << valor << endl;
			break;
		case 0:
			break;
		}

	}
	while(op != 0 && op != 2);

	return 0;
}

bool listaVazia(noPtr inicio)
{
	if(inicio)
		return false;
	else
		return true;
}

int cont(noPtr inicio)
{
	int aux = 0;
	noPtr p = new no;
	p = inicio;
	if(p == NULL)
		return 0;
	else
	{
		while(p != NULL)
		{
			aux ++;
			p = p->prox;
		}
	}
	return aux;
}

int inserir(noPtr *alfa)
{
	noPtr p = new no;
	cout << "Digite o elemento para inserir " << endl;
	cin >> p->info;
	noPtr aux;
	int tmp;

	if(listaVazia(*alfa))
	{
		*alfa = p;
		p->prox = NULL;
		tmp++;
	}
	else
	{
		aux = *alfa;
		*alfa = p;
		p->prox = aux;
		cout << "elemento adicionado " << endl;
		tmp++;
	}
	return tmp;
}

int menu()
{
	int op;
	cout << "Digite 1 para inserir " << endl;
	cout << "Digite 2 para  contar o numeoro de quadrados " << endl;
	cin >> op;
	return op;
}
