/* Marcos Paulo Sales de Oliveira / 1621906BCC
1. Fazer o chin�s do c�digo dispon�vel no slide da Lista Circular e verificar se ao fazer a inclus�o e a remo��o de um n� a lista se mant�m circular.

1.1 Acertar a redund�ncia do c�digo (em rela��o a vari�vel que verifica a quantidade de n�s na lista). (feito)

2. Mandar o chin�s (pode ser foto) e o c�digo correto (implementando uma lista circular. Inserir n� e Retirar n�). (Feito)

Colocar seu nome nos arquivos. Ex. Aluno_Sobrenome_ListaCircular.cpp (ou c) e Aluno_Sobrenome_ListaCircular.pdf (ou docx). (Feito)
*/
#include <iostream>
using namespace std;
struct no
{
	int info;
	struct no *prox;
};
typedef struct no *noPtr;
//Espaco das funcoes
int insere (noPtr * i, int * q);
void retira (noPtr * i, int * q);
void listar(noPtr i, int q);
bool listaVazia(noPtr *i);
int menu();
// Termino do espa�o
int main()
{
	int op, qtde = 0;
	noPtr inicio = NULL;
	noPtr *i = inicio;
	do
	{
		op = menu();
		switch (op)
		{
		case 1:
			qtde = insere(&inicio, &qtde); //redund�ncia
			cout << "\nA lista possui " << qtde << " no(s).\n\n";
			break;
		case 2:
			retira(&inicio, &qtde);
			break;
		case 3:
			listar(inicio, qtde);
			break;
		}
	}
	while (op != 0);
	
	return 0;
}

int insere (noPtr * i, int * q)   //� uma lista circular??? Como fazer?
{
	noPtr p = new no;
	cout << "\nDigite o valor do elemento: ";
	cin >> p->info;

	*q = 0;
	noPtr end = *i;
	
	if (listaVazia(i))
	{
		*i = p;
		p->prox = end;
	}
	else
	{
		noPtr aux = *i;
		*i = p;
		p->prox = aux;
	}
	if(*i != NULL)
	{
		while(p != end)
		{
			*q += 1; // redundancia
			p = p->prox;
		}
	}
	else
	{
		cout << "Lista Vazia " << endl;
		*q=0;
	}
	return *q;

}

void retira (noPtr * i, int * q)   //Mant�m a lista circular??? O que fazer?
{
	noPtr p = *i;
	if (!listaVazia(i))
	{
		if (*q == 1)
		{
			*i = NULL;
		}
		else
			*i = p->prox; //*i = (*i)->prox
		delete(p);
		cout << "\nO elemento foi retirado da lista!\n";
		*q = *q - 1;
	}
	else cout << "\n\nLista Vazia!\n";
}

void listar(noPtr *inicio, int q)
{
	if (!listaVazia(*inicio))
	{
		for (int j = 0; j < q; j++)
		{
			cout << inicio->info << "\t";
			inicio = inicio->prox;
		}
	}
	else
		cout << "\n\nLista vazia!";
}

bool listaVazia(noPtr *inicio)
{
	if(*inicio == NULL)
	{
		return true;
	}
	else
		return false;
}

int menu()
{
	int op;
	cout << "Digite 1 para inserir " << endl;
	cout << "Digite 2 para retirar" << endl;
	cout << "Digite 3 para listar " << endl;
	cout << "Digite 0 para sair" << endl;
	cin >> op;
	return op;
}