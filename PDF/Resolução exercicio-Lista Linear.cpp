#include <iostream>

#define T 5

using namespace std;

int inserir(int[], int);
int retirar(int [], int, int);
void imprimir(int [], int);
int menu();
void fazListaVazia(int[]);
bool listaVazia(int[]);

main()
{

	int valor, op, posLivre = 0, A[T];

	fazListaVazia(A);

	do
	{
		op = menu();
		switch(op)
		{
			case 1: posLivre = inserir(A, posLivre); break;
			case 2: cout << "\nEntre com o valor a ser retirado: ";
					cin >> valor;
					posLivre = retirar(A, valor, posLivre); break;
			case 3: imprimir(A, posLivre); break;
		}
	}while (op != 0);
}

int menu()
{
	int op;

	cout << "\n\nMenu de opcoes\n\n"
		 << "1: Inserir elemento no ultima posicao da Lista\n"
		 << "2: Retirar elemento da Lista\n"
		 << "3: Imprimir elementos da Lista\n"
		 << "0: Sair\n\n"
		 << "Escolha uma das opcoes: ";
	cin >> op;

	return op;
}

void fazListaVazia(int A[])
{
	for (int i = 0; i < T; i++)
		A[i] = 0;
}

bool listaVazia (int A[])
{
	if (!A[0])
		return true;
	else
		return false;
}

int inserir(int A[], int p)
{
	if (p >= T)
		cout << "\n\nLista Cheia!\n";
	else
	{
		cout << "\n\nInforme o numero a ser colocado na Lista: ";
		cin >> A[p];
		p++;
	}
	return p;
}

int retirar(int A[], int x, int pos)
{
	int p = 0;
	bool achei = false;

	if (listaVazia(A))
		cout << "\n\nA lista esta vazia.\n";
	else
	{
		while (achei == false && p < T)
		{
			if (A[p] == x)
				achei = true;
			else
				p++;
		}
		if (achei)
		{
			for (int i = p; i < pos; i++)
			{
				A[i] = A[i+1];
			}
			pos--;
		}
		else
			cout <<"\n\nElemento nao encontrado.";
	}
	return pos;
}

void imprimir(int A[], int p)
{
	if (listaVazia(A))
		cout << "\n\nA lista esta vazia.\n";
	else
	{
		cout << "\n\nElementos da Lista\n\n";
		for(int i = 0; i < p; i++)
			cout << A[i] << "\t";
	}
}