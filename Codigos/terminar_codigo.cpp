/*Questão 1 (2.0) Sendo I1 e I2 ponteiros para duas listas duplamente encadeadas
 de números inteiros, implemente as seguintes funções:
 A. SOMA (apresentar a soma total dos elementos das listas);
 B. MAIOR (informar a lista que possui mais elementos). */

#include <iostream>
using namespace std;

struct no
{
	int info;
	struct no* prox;
	struct no*ant;
};

struct lista
{
	no*inicio;
	no*fim;
};


typedef lista& listaRef;
typedef struct no* noPtr;

//Espaco
bool listaVazia(listaRef d);
int inserir(listaRef d);
void listar(listaRef d);
void remover(listaRef d, int *q);
int menu();
// FIm do espaco


int main(int argc, char** argv)
{
	lista d;
	d.inicio = NULL;
	d.fim = NULL;
	int qtde;

	int op;
	int valor;

	do
	{
		op = menu();
		switch(op)
		{
		case 1:
			qtde += inserir(d);
			break;
		case 2:
			listar(d);
			break;
		case 3:
			cout << "Digite o valor que queira remover, caso exista " << endl;
			cin >> valor;
			remover(d,&qtde);
			break;
		case 0:
			break;
		}
	}
	while(op != 0);

	return 0;
}

bool listaVazia(listaRef d)
{
	if(d.inicio == NULL)
		return true;
	else
	{
		return false;
	}
}

int inserir(lista d)
{
	int valor;
	
	cout << "Digite o valor que queira inserir " << endl;
	cin >> valor;

	noPtr p = new no;
	p->info = valor ;

	if(listaVazia(d))
	{
		d.inicio = p;
		d.fim = p;
		p->prox = NULL;
		p->ant = NULL;
	}
	else
	{
		noPtr aux = d.inicio;
        d.inicio = p;
		p->prox = aux;
		p->prox -> ant = p;
		p->ant = NULL;
		d.fim = p;
	}
	cout << "Elemento adicionado " << endl;
	return 1;
}

void listarPilha(listaRef d)
{
	noPtr p = new no;
	p = d.fim;

	if(!listaVazia(d))
	{
		if(d.inicio == d.fim)
		{
			cout << p->info;
		}
		else
		{
			while(p != NULL)
			{
				cout << p->info << endl;
				p = p->prox;
			}
		}
	}
	else
	{
		cout << " Lista Totalmente vazia " << endl;
	}
}

void remover(listaRef d, int *q)
{
	int valor;
	
	cout << "Digite algo pare remover " << endl;
	cin >> valor;
	
	
	noPtr p = new no;
	p = d.inicio;

	if(listaVazia(d))
	{
		cout << "Lista Vazia , nao eh possivel retirar o nada " << endl;
	}
	else
	{
		for(int i = 0; i < *q; i++)
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
					d.inicio = p->ant;
					p->ant ->prox = d.inicio;
				}
				else if (d.fim == p)
				{
					p->prox-> ant = p->ant;
					p->ant->prox = p->prox;
				}
				delete(p);
				p = p->prox;
				*q -= 1;
			}
		}
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
