#include <iostream>
using namespace std;


struct no
{
	int info;
	struct no*prox;
};

typedef struct no*noPtr;


//	Espaco das funcoes
bool listaVazia(noPtr *start);
void inserir(noPtr *start);
void listar(noPtr *start, noPtr *start2);
int menu();
int transforma(noPtr *start,noPtr *start2, int A[]);
void insertSort(int A[],int tam);
int contador(noPtr *start, noPtr *start2);
int transVetor(noPtr *start, noPtr *start2, int S[],int tam);

// fim

int main(int argc, char** argv)
{
	noPtr inicio = NULL;
	noPtr inicio2 = NULL;
	int tam = contador(&inicio,&inicio2);
	int A[tam];
	int op;

	do
	{
		op = menu();
		switch(op)
		{
		case 1:
			inserir(&inicio);
			break;
		case 2:
			inserir(&inicio2);
			break;
		case 3:
			listar(&inicio, &inicio2);
			break;
		case 4:
			A[tam] = transVetor(&inicio,&inicio2,A,tam);
			insertSort(A,tam);
			for(int i = 0 ; i< tam ; i++)
			{
				cout << A[i] << endl;
			}
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
	{
		return false;
	}
}

void inserir(noPtr *start)
{
	noPtr p = new no;
	cout << "Mostre o numero que deseja inserir " << endl;
	cin >> p->info;

	if(listaVazia(start))
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
}
// lista 1 = 1,2,3,4
//lista 2 = 5,6,7,8
void listar(noPtr * start, noPtr * start2)
{
	noPtr p = new no;
	p = *start;

	while(p != NULL)
	{
		cout << p->info << endl;
		p = p->prox;
		if(p->prox == NULL)
		{
			cout << p->info << endl;
			p = *start2;
			
			while(p != NULL)
			{
				cout << p->info << endl;
				p = p->prox;

			}
		}
	}
}
int menu()
{
	int op;
	cout << " Digite 1 para inserir na lista 1 " << endl;
	cout << " Digite 2 para inserir na lista 2 " << endl;
	cout << "digite 3 para listar " << endl;
	cout << "Digite 4 para organizar " << endl;
	cin >> op;
	return op;
}
/*
 int transforma(noPtr *start,noPtr *start2, int S[])
{
	noPtr p = new no;
	p = *start;
	
	while(p!=NULL)
	{
		int i = 0 ;
		cout << p->info << endl;
		S[i] = p->info;
		i++;
		p = p->prox;
		if(p->prox == NULL)
		{
			p = *start2;
			while(p!=NULL)
			{
				cout << p->info << endl;
				S[i] = p->info;
				i++;
				p = p->prox;
			}
		}
	}
	return S[0];
}
*/


int contador(noPtr *start, noPtr *start2)
{
	int contador = 0 ;
	noPtr p = new no;
	p = *start;
	while(p!=NULL)
	{
		contador +=1;
		p = p->prox;
	}
	noPtr q = new no;
	q = *start2;
	while(q!=NULL)
	{
		contador +=1;
		q = q->prox;
	}
	return contador;
}

int transVetor(noPtr *start, noPtr *start2, int S[], int tam)
{
	int A[tam];
	int i = 0;
	noPtr p = new no;
	p = *start;
	while(p!=NULL)
	{
		S[i] = p->info;
		i++;
		p= p->prox;
	}
	noPtr q = new no;
	q = *start;
	while(q!=NULL)
	{
		S[i] = q->info;
		i++;
		q = q->prox;
	}
	for(int j = 0 ; j < tam; j++)
	{
		A[j] = S[j];
	}
	
	return *S;
}

void insertSort(int A[], int tam)
{
	int aux, j;

	for(int i = 1 ; i <= tam - 1; i++ )
	{
		aux = A[i];
		j = i - 1;

		while(aux < A[j] && j >= 0)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = aux;
	}
}// fim do insert sort