/* Receba 10 numeros , remova somente os numeros pares e imprimir de trás para frente " */


#include <iostream>
using namespace std;
#define tam 10

struct no
{
	int info;
	struct  no*prox;
//struct no*ant;
};

typedef struct no*noPtr;

// funcoes
bool listaVazia(noPtr p);
int inserir(noPtr *start, int x );
void listar(noPtr start);
void retirar(noPtr *start, int x);
void retirar2(noPtr *start, int vetor[]);
//void listarPares(noPtr *start);
int menu();
// fim do espaco


int main(int argc, char** argv)
{
	int op;
	noPtr inicio = NULL;
	int x;
	int qtde = 0;
	int j = 0;
	int array[10] = {0};
	int temp = 0;
	int a;

	do
	{
		op = menu();
		switch(op)
		{
		case 1:
			cout << "Digite um numero para inserir " << endl;
			cin >> x;
			if(x % 2 == 0)
			{
				array[j] = x;
				j += 1;
			}
			qtde += inserir(&inicio, x);
			break;
		case 2:
			cout << "Digite um elemento que queira remover " << endl;
			cin >> a;
			retirar(&inicio, a);
			cout << "Elemento removido " << endl;
			break;
		case 3:
			listar(inicio);
			break;
		case 4:
			for(int i = 0; i < 10; i++)
			{
				temp = 0;
				temp = array[i];
				retirar(&inicio, temp);
				cout << "Elemento removido " << i + 1 << endl;
			}
			break;
		case 0:
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


int inserir(noPtr *start, int x )
{
	noPtr p = new no;

	p->info = x;

	if(listaVazia(*start))
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

	return 1;

}

void listar(noPtr start)
{
	noPtr p = start;
	while(p != NULL)
	{
		cout << p->info << endl;
		p = p->prox;
	}
}

void retirar(noPtr *start, int x)
{
	noPtr p = *start;
	
	if(!listaVazia(*start))
	{
		while(p->prox !=NULL)
		{
			if(p->info == x)
			{
				  *start = p->prox;
				  delete(p);
			}
			p = p->prox;
		}
	}
	else
	{
		cout << "ListaVazia " << endl;
	}
	
	
	
}
int menu()
{
	int op;
	cout << "1 INSERIR" << endl;
	cout << "2 REMOVER" << endl;
	cout << "3 LISTAR" << endl;
	cout << "4 REMOVER PARES " << endl;
	cout << "0 SAIR" << endl;
	cin >> op;
	return op; // 1, 2 , 3 ,  0
}
