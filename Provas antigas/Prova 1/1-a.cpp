// Faça uma função que percorra a lista simplesmente encadeada, mostre o somatório dos nós e o nó que possui o maior valor. Usando o exemplo abaixo, seriam mostrados
// Os valores 21 e 9 respectivamente


#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct no
{
	int info;
	struct no*prox;
};
typedef struct no*noPtr;

//		FUNCAO
bool listaVazia(noPtr *start);
void maiorNo(noPtr *start);
void inserir(noPtr *start);
int menu();
// 		FIM

int main()
{
	noPtr inicio = NULL;
	int op;
	do
	{
		op = menu();
		switch(op)
		{
		case 1:
			inserir(&inicio);
			cout << "Elemento inserido " << endl;
			break;
		case 2:
			maiorNo(&inicio);
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
	if(*start == NULL)
		return true;
	else
		return false;
}

void maiorNo(noPtr *start)
{
	noPtr p = new no;
	p = *start;
	int maior = 0;
	int soma=0;
	
	while(p != NULL)
	{
		if(maior < p->info)
		{
			maior = p->info;
		}
			soma+=p->info;		
		p = p->prox;
	}

cout << " os nos maiores sao " << maior  << " & " << soma<< endl;

}



void inserir(noPtr *start)
{
	noPtr p = new no;
	cout << " Digite um numero para inserir " << endl;
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
	}
}

int menu()
{
	int op;
	cout << "Digite 1 para inserir " << endl;
	cout << "Digite 2 para listar e escolher os maiores nós " << endl;
	cin >> op;
	return op;
}
