//Ordenação comum


#include <iostream>
using namespace std;


void selecao(int vet[], int n)
{
	int menor, aux = 0;

	for(int i = 0; i < n -1 ; i++)
	{
		for(int j = i + 1; i < n ; i++)
		{
			if (vet[i] > vet[j])
			{
				menor = j;
			}

		}
		if( i != menor)
		{
			aux = vet[i];
			vet [i] = vet[menor];
			vet[menor] = aux;
		}
	}

}

int main()
{
	int n = 10;
	int vetor[n];

	for(int i = 0 ; i < n ; i++)
	{
		cout << "Digite o elemento " << i + 1 << " aqui " << endl;
		cin >> vetor[i];
	}

	selecao(vetor, n);
	
	for(int i = 0 ; i< n ; i++)
	{
		cout << vetor [i] << endl;
	}

	return 0;
}
