#include<iostream>
using std::ostream;
using std::cout;

// ################################
// ##### Definições do Pedido #####
// ################################

struct Pedido
{

	enum ID { copo_dagua, biscoito, prato_feito};
	operator double();

	Pedido* prox;
	ID id;
};

using ITEM = Pedido::ID;

Pedido::operator double()   // Qual o preço de cada item do enum?
{

	switch( this->id )
	{

	case ITEM::copo_dagua:
		return 2.5;

	case ITEM::biscoito:
		return 5.0;

	case ITEM::prato_feito:
		return 18.5;
	};

	return -1;
}   // Error case


ostream& operator<<( ostream& out, const Pedido& p)     // To string do C++ -- Para Pedido
{

	switch( p.id )
	{

	case ITEM::copo_dagua:
		out << "copo d'água";
		break;

	case ITEM::biscoito:
		out << "biscoito";
		break;

	case ITEM::prato_feito:
		out << "prato feito";
		break;
	};

	return out;
}

// ################################
// ##### Definições do Cliente ####
// ################################

struct Cliente
{

	Cliente* prox;  // Proximo cliente da fila
	Pedido* HEAD;   // Ponteiro de inicio da lista de pedidos
	int id;

	Cliente( int _id) : prox(NULL), HEAD(NULL), id(_id) {}

	~Cliente(void)
	{

		Pedido * AUX = HEAD;
		Pedido * DOWN;

		while(AUX != NULL)
		{
			DOWN = AUX;
			AUX = AUX->prox;
			delete DOWN;
		}
		// TODO -- Tem que destruir a lista de pedidos desse cliente
	}

	void adicionar_pedido( Pedido::ID item)
	{

		Pedido * no = new Pedido;
		no -> id = item;

		if(HEAD != NULL)
		{
			no -> prox = HEAD;
			HEAD = no;
		}
		else
		{
			HEAD = no;
			no -> prox = NULL;
		}
		// TODO -- Como se adiciona um Pedido na lista desse cliente?
	}

	double total_pedido(void)
	{

		Pedido* temp = HEAD;
		HEAD = NULL; // Nao vai ter mais lista, a lista será apagada.

		double sum = 0;

		while(temp != NULL)
		{
			sum += *temp;

			pedido * aux = temp;


			temp = temp->prox;

			delete aux; // No momento que aponta, deleta.
		}
		// TODO -- Como se calcula o valor total de pedidos de um cliente?

		return sum;
	}
};


// ################################
// ##### Definições do Cliente ####
// ################################


struct Restaurante
{

	Cliente* HEAD;  // Ponteiro de inicio da lista de clientes
	Cliente* TAIL;  // Ponteiro pro final da lista de clientes

	double total_faturado;

	Restaurante(void) : HEAD(NULL), TAIL(NULL), total_faturado(0) {}

	~Restaurante()
	{

		Cliente* AUX = HEAD;
		Cliente * DOWN;

		while(AUX != NULL)
		{
			DOWN = AUX;
			AUX = AUX->prox;
			delete DOWN;
		}


		// TODO -- Tem que destruir a lista de clientes
	}

	void adicionar_cliente( int id)     // Adiciona um novo cliente no final da lista (fila) de clientes
	{

		Cliente* temp = new Cliente(id);

		if( HEAD == NULL )
		{

			HEAD = temp;
			TAIL = temp;

		}
		else
		{

			TAIL->prox = temp;
			TAIL = temp;
		}
	}

	void retirar_cliente( int id)
	{

		Cliente* temp = HEAD;
		Cliente* aux = HEAD;

		while( temp != NULL && temp->id != id )
		{

			aux = temp;
			temp = temp->prox;
		}

		if( temp != NULL )
		{

			if( temp == HEAD )
				HEAD = temp->prox;

			else if( temp == TAIL )
			{

				aux->prox = NULL;
				TAIL = aux;

			}
			else
				aux->next = temp->next;
		}

		if( temp != NULL )
		{

			total_faturado += temp->total_pedido();
			delete temp;
		}

		// TODO -- retira um cliente da lista de clientes, mas calcula o quanto ele consumiu e soma isso em 'total_faturado'
	}

	void mostrar_pedidos_cliente( int id)
	{

		Cliente* temp = HEAD;

		while( temp != NULL && temp->id != id )
		{

			temp = temp->prox;
		}
		if(temp != NULL)
		{
			Pedido * pedidos = temp-> HEAD;

			while(pedidos != NULL)
			{
				cout << " \t" << *pedidos << endl;
				pedidos = pedidos -> prox;
			}
		}
		else
		{
			cout << "Cliente não encontrado \n";
		}

		// TODO -- acha o cliente e faz: "cout << cliente"
	}

	void listar_clientes(void)
	{

		Cliente* temp = HEAD;

		while(clientes != NULL)
		{
			cout << clientes -> id << endl;
			clientes = clientes ->prox;
		}

	}

	// TODO -- lista todos os clientes da lista de clientes
}

void fechar(void)
{

	cliente* temp = HEAD;
	while(clientes != NULL)
	{
		total_faturado += cliente -> total_pedido();
		clientes = clientes ->prox;
	}
	// TODO -- retira todos os clientes um a um somando os custos de 'total_pedido' de cada nó. Depois mostra o faturamento total deste restaurante
}
};


// ################################
// ############# main #############
// ################################

int menu()
{
	int op;
	cout << "Digite  1 para inserir cliente \n";
	cout << "Digite 2 para inserir produto \n";
	cout << "Digite 3 Retirar cliente ( Pagar conta ) " << endl;
	cout << "Digite 4 listar clientes" << endl;
	cout << "Digite 5 listar produtos dos clientes" << endl;
	cout << "Digite 6 Fechar restaurante" << endl;
	cout << "Digite 7 para somar valor total " << endl;
	cout << "Digite 0 para sair" << endl;
	cin >> op;
	return op;

}


int main()
{

	Restaurante rest;

	int ok;
	do
	{
		ok = menu();
		switch(ok)
		{
		case 1:
			void adicionar_cliente( int id);
			break;
		case 2:
			void adicionar_pedido( Pedido::ID item);
			break;
		case 3:
			void retirar_cliente( int id)
			break;
		case 4:
			void listar_clientes(void);
			break;
		case 5:
			void mostrar_pedidos_cliente( int id);
			break;
		case 6:
			void fechar(void);
			break;
		case 7:
			double total_pedido(void);
			break;
		case 0:
			break;
		}
	}
	while(ok != NULL);

	// TODO -- Fazer o loop principal do programa

	rest.fechar();

	return 0;
}
