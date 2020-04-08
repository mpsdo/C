/*Considere listas encadeadas de valores inteiros e implemente uma função para retornar o número de nós da lista
que possuem o campo info com valores maiores que n.*/
#include <iostream>
using namespace std;
struct no
{
	int info;
	struct no*prox;
};
struct lista
{
	struct no*inicio;
	struct no*fim;
};
typedef struct no*noPtr;

void inserir(noPtr *start);
int listar(noPtr *start);
int listar(noPtr *start);
void listaVazia(noPtr start);
int menu();

int main ()
{
	noPtr inicio = NULL;
	int op,maior = 0;
	do
	{
		op = menu();
		switch(op)
		{
			case 1:
				inserir(&inicio);
				break;
			case 2:
				maior = listar(&inicio);
				cout << "O valor de vezes maiores que n eh : " << maior << endl;
				break;
			case 3:
				break;
		}
		
	}while(op!= 0 && op!= 2);
	
	return 0;

}

bool listaVazia(noPtr *start)
{
	if(start)
	{
		return false;
	}
	else
	{
		return true;
	}

}

void inserir(noPtr *start)
{
	noPtr p = new no;
	cout << "Digite o numero que queira inserir " << endl;
	cin >> p->info;

	if(listaVazia(start))
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


int listar(noPtr *start)
{
	int num, cont = 0;
	cout << "Digite o elemento a ser comparado " << endl;
	cin >> num;

	noPtr p = new no;
	p = *start;

	if(listaVazia(start))
	{
		cout << "Lista Vazia " << endl;
	}
	else
	{
		while(p!= NULL)
		{
			if(num < p->info)
			{
				cont += 1;
			}
			p = p->prox;
		}
	}
	return cont;
}

int menu()
{
	int op;
	cout << "Digite 1 para inserir " <<endl;
	cout << "Digite 2 para listar " <<endl;
    cout << "Digite 0 para sair " <<endl;
    cin >> op;
    
    return op;
    
}

