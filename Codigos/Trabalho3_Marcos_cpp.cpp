#include <iostream>
using namespace std;

struct no
{
	int info;
	struct no* dir;
	struct no* esq;
};
typedef struct no*noPtr;

//using noPtr = no*;
//Espaco das funcoes

void listarPreOrdem(noPtr* p);
void listarPosOrdem(noPtr* p);
void listarEmOrdem(noPtr* p);
noPtr maior(noPtr p);
void remover(noPtr* p, int x);
bool buscar(noPtr p, int x);
void inserir(noPtr* start, int x);
bool arvoreVazia(noPtr start);
int menu1();
int menu2();

// Fim do espaco


int main()
{
	int op1, x, op2;
	noPtr raiz = NULL;
	bool achei;
	int Array[8] = {25, 20, 10, 35, 30, 8, 15, 55};

	do
	{
		op1 = menu1();
		switch(op1)
		{
		case 1:
			//cout << "DIGITE O ELEMENTO QUE QUEIRA INSERIR " << endl;
			//cin >> x;
			for(int i = 0; i < 8; i++)
			{
				x = Array[i];
				inserir(&raiz, x);
			}
			break;
		case 2:
			cout << "DIGITE O ELEMENTO QUE QUEIRA REMOVER " << endl;
			cin >> x;
			remover(&raiz, x);
			break;
		case 3:
			op2 = menu2();
			switch(op2)
			{
			case 1:
				listarEmOrdem(&raiz);
				break;
			case 2:
				listarEmOrdem(&raiz);
				break;
			case 3:
				listarPosOrdem(&raiz);
				break;
			}
			break;
		case 4:
			cout << "DIGITE O ELEMENTO QUE QUEIRA ENCONTRAR " << endl;
			cin >> x;
			achei = buscar(raiz, x);
			if(achei == false)
				cout << "ELEMENTO NAO ENCONTRADO " << endl;
			break;
		case 0:
			break;
		}
	}
	while(op1 != 5);





	return 0;
}
bool arvoreVazia(noPtr start)
{
	return start == NULL;
}

void inserir(noPtr* p, int x)
{

	if(arvoreVazia(*p))
	{
		*p = new no;
		(*p)->dir = NULL;
		(*p)->esq = NULL;
		(*p)->info = x;
		/*
		noPtr p = new no;
		*p->info = x;
		(*p->dir) = NULL;
		((*p)->esq) = NULL;
		*/

		cout << "elemento inserido" << endl; // Aqui que devia ser esse print
	}
	else
	{
		if(x < (*p)->info)
		{
			inserir(&((*p)->esq), x);
		}
		else
		{
			inserir(&((*p)->dir), x);
		}
		//cout << "elemento inserido " << endl; // Vai ficar printando um monte de vezes...
	}
}

bool buscar(noPtr p, int x)
{

	if(arvoreVazia(p))
	{
		cout << "Arvore Vazia " << endl;
		return false;
	}
	else
	{
		if(x == p->info)
		{
			//cout << "O elemento " << (*p)->info << "Foi encontrado " << endl;
			cout << "O elemento " << x << " foi encontrado " << endl; // Sempre opte pelo mais simples...
			return true;
		}
		else if(x < p->info )
		{
			return buscar(p->esq, x);
		}
		else
		{
			return buscar(p->dir, x);
		}
	}
}

void remover(noPtr* p, int x)
{
	noPtr aux = *p;

	if(arvoreVazia(*p))
	{
		cout << "Arvore Vazia " << endl;
	}
	else
	{
		if(aux->info == x)
		{
			if(aux->esq == NULL)
			{
				*p = aux->dir;
			}
			else if(aux->dir == NULL)
			{
				*p = aux->esq;
			}
			else // Os dois não são nulos
			{
				maior(aux->esq)->dir = aux->dir;
				*p = aux->esq;
			}

			delete aux;
			cout << "O elemento foi removido " << endl;
		}
		else if(x < aux->info)
		{
			remover(&(aux->esq), x);
		}
		else
		{
			remover(&(aux->dir), x);
		}
	}
}

noPtr maior(noPtr p)
{
	if(p->dir == NULL)
		return p;
	else
		return maior(p->dir);
}


void listarEmOrdem(noPtr* p)
{
	if(!arvoreVazia(*p))
	{
		listarEmOrdem(&((*p)->esq));
		cout << '\t' << (*p)->info << endl;
		listarEmOrdem(&((*p)->dir));
	}
}

void listarPosOrdem(noPtr* p)
{
	int qtde = 0;
	
	if(!arvoreVazia(*p))
	{
		if((*p)->dir != NULL && (*p)->esq != NULL)
		{
			qtde += 1;
			cout << "O valor curva 2 eh : " << p << endl;
		}
		listarPosOrdem(&((*p)->esq));
		listarPosOrdem(&((*p)->dir));
		cout << '\t' << (*p)->info << endl;
	}

}

void listarPreOrdem(noPtr* p)
{
	if(!arvoreVazia(*p))
	{
		cout << '\t' << (*p)->info << endl;
		listarPreOrdem(&((*p)->esq));
		listarPreOrdem(&((*p)->dir));
	}
}

int menu1()
{
	int op;
	cout << "1: PARA INSERIR " << endl;
	cout << "2: PARA REMOVER " << endl;
	cout << "3: PARA LISTAR TODOS OS NOS " << endl;
	cout << "4: PARA BUSCAR NO  " << endl;
	cout << "5: PARA SAIR " << endl;
	cin >> op;
	return op;
}

int menu2()
{
	int op2;
	cout << "1: PARA EM ORDEM" << endl;
	cout << "2: PARA PRE ORDEM" << endl;
	cout << "3: PARA POS ORDEM" << endl;
	cout << "0: sair" << endl;
	cin >> op2;
	return op2;

}
