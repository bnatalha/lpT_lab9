/**
* @file
* @brief Implementação de myDeque do namespace edb1
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 18/06/2017
* @date 15/06/2017
* @sa std::deque (http://www.cplusplus.com/reference/deque/deque/)
* @sa https://stackoverflow.com/questions/6292332/what-really-is-a-deque-in-stl
* @sa http://en.cppreference.com/w/cpp/container/deque
* @sa https://www.codeproject.com/Articles/5425/An-In-Depth-Study-of-the-STL-Deque-Container
*/

#ifndef MYFILA_H
#define MYFILA_H

#include "natalia.h"

	/**
	* @class myDeque
	* @brief Um deque que usa um array circular alocado dinâmicamente (sem iterator)
	* @tparam T Tipo dos elementos da lista
	*/
	template < typename T >
	class myDeque
	{
		private:
			int capacidade = 50;	/**< Capacidade máxima do deque */
			int ini;	/**< Índice para o inicio do deque */
			int fim;	/**< Índice para o fim do deque */
			T* recipiente;	/**< Onde os elementos do deque serão guardados*/

			void my_reallocator();

		public:
			// Construtor
			myDeque();
			myDeque( const myDeque & orig );
			// Destrutor
			~myDeque();
			// Acesso a elementos
			T& operator[] (int n);
			T& front();
			T& back();
			// Capacidade
			int size();
			bool empty();
			// Modificadores
			void push_sorted( T elem );
			void push_back( const T& elem );
			bool pop_back();
			void push_front( const T& elem );
			bool pop_front();
			void clear();
			// Sobrecarga de operadores
			bool operator== ( myDeque<T> d_direita);
			myDeque<T>& operator= (const myDeque<T>& copy);
			// PARA TESTE: sobrecarga operador <<
			//template <typename foo>
			//friend std::ostream& operator<< (std::ostream& out, const myDeque<foo> copy);
	};

namespace edb1
{
	/**
	* @brief Realoca o container do deque para o dobro de sua capacidade total
	*/
	template <typename T>
	void myDeque<T>::my_reallocator()
	{
		cout << "(dobrando capacidade)";

		// tenta alocar o dobro da capacidade do deque atual
		try{
			T* new_recipiente = new T[capacidade*2];	// cria um novo recipiente com o dobro de capacidade
		}catch (std::bad_alloc& ba)		{
			cout << << "bad_alloc caught: " << ba.what() << endl;
		}
		
		for (int n = 0, i = ini; n < size(); n++)	// atribui ao novo bloco de memoria informações do atual
		{
			new_recipiente[n] = recipiente[i];
			i = ((i+1) % capacidade);
		}

		// fixa indices 
		ini = ( empty()? -1 : 0 );
		fim = size() -1;
		

		delete[] recipiente;	// Deleta bloco de memoria apontado por 'recipiente'
		recipiente = new_recipiente;	// aponta 'recipiente' para o bloco de memoria criado
	}

	// =================================================================================================
	// =========================================== Construtores ========================================
	// =================================================================================================

	/**
	* @brief Constrói um objeto myDeque vazio
	*/
	template <typename T>
	myDeque<T>::myDeque()	: capacidade(4), ini(-1), fim(-1)
	{
		// tenta alocar o Deque.
		try{
			recipiente = new T[capacidade];
		}catch (std::bad_alloc& ba)		{
			cout << << "bad_alloc caught: " << ba.what() << endl;
		}

	}

	/**
	* @brief Constrói um objeto myDeque a partir de outro já existente (cópia)
	* @param objeto myDeque que será usado como referência para ser copiado
	*/
	template <typename T>
	myDeque<T>::myDeque( const myDeque & orig )	: capacidade(orig.capacidade), ini(orig.ini), fim(orig.fim)
	{
		// tenta alocar o Deque com a capacidade do deque 'orig'.
		try{
			recipiente = new T[orig.capacidade];		
		}catch (std::bad_alloc& ba)		{
			cout << << "bad_alloc caught: " << ba.what() << endl;
		}

		// copia os elementos de orig para este deque
		for(i = 0; i < orig.size(); i++) this->recipiente[i] = orig.recipiente[i];
	}

	// =========================================== Destrutor ========================================
	
	/**
	* @brief Destrói um objeto myDeque, destruindo sua 'recipiente'
	*/
	template <typename T>
	myDeque<T>::myDeque()
	{
		delete[] recipiente;
	}

	// =================================================================================================
	// =========================================== Acesso ==============================================
	// =================================================================================================

	/**
	* @return Referência para o elemento na posição 'n' do container 'recipiente'
	*/
	template <typename T>
	T& myDeque<T>::operator[] (int n)
	{
		if(empty())	// Se deque estiver vazio
			throw std::out_of_range ("[EXCEPTION] operator[]: Não há elementos no deque");

		return recipiente[ (ini + n )% capacidade ];
	}

	/**
	* @brief diferença desse pro [] é a esceção caso 'n' seja maior ou igual ao tamanho do deque
	* @return Referência para o elemento na posição 'n' no deque, se existir.
	*
	*/
	template <typename T>
	T& myDeque<T>::at(int n)
	{
		if(empty())	// Se deque estiver vazio
			throw std::out_of_range ("[EXCEPTION] operator[]: Não há elementos no deque");
		if(n => size)	// Se a posição requisitada for maior do que o tamanho do deque
			throw std::out_of_range ("[EXCEPTION] operator[]: posição requisitada > tamanho do deque");

		return recipiente[ (ini + n )% capacidade ];
	}

	/**
	* @return Referência para o elemento no início da recipiente, se existir.
	*/
	template <typename T>
	T& myDeque<T>::front()
	{
		if(empty())	// Se deque estiver vazio, chamar exceção
			throw std::out_of_range ("[EXCEPTION] front(): Não há elementos no deque");

		return recipiente[ini];
	}

	/**
	* @return Referência para o elemento no fim da recipiente,  se existir.
	*/
	template <typename T >
	T& myFila<T>::back()
	{
		if (empty())	// Se deque estiver vazio, chamar exceção
			throw std::out_of_range ("[EXCEPTION] back(): Não há elementos na recipiente");
		
		return recipiente[fim];
	}

	// =================================================================================================
	// ======================================== Capacidade =============================================
	// =================================================================================================


	/**
	* @retval true A deque está vazio
	* @retval false A deque \b não está vazio
	*/
	template <typename T >
	bool myDeque<T>::empty()
	{
		return (size() == 0);
	}

	/**
	* @return Referência para o tamanho da deque
	*/
	template <typename T >
	int myDeque<T>::size()
	{
		if (ini == -1) return 0;
		else if(ini == fim ) return 1;
		else if(ini < fim) return ((fim-ini)+1);
		//else if (ini > fim)
		return ( (fim + (capacidade - ini) )+ 1);
	}

	// =================================================================================================
	// ======================================= Modificadores ===========================================
	// =================================================================================================

	/**
	* @brief Acrescenta um elemento no final do Deque
	* @param element Elemento do tipo T a ser acrescentado na frente da fila
	*/
	template <typename T>
	void myDeque<T>::push_back( const T& elem )
	{	
		if(size() == capacidade)	
			my_reallocator();	// Realocar o tamanho do container do Deque quando atingir a capacidade maxima inicial
		
		if (empty())	// se for o primeiro elemento a entrar na 'recipiente'
			ini++;	// coloca 'ini' para apontar

		fim = (fim+1)%capacidade;	// avança indice 'fim'
		recipiente[fim] = element;	// Acrescenta elemento e depois aumenta o tamanho da 'recipiente'
	}
	/**
	* @brief Remove o elemento no fim do Deque
	*/
	template <typename T>
	void myDeque<T>::pop_back()
	{
		if (empty())
			throw std::length_error ("[EXCEPTION] pop_back(): Não pode remover elementos de um deque vazio");
		

		recipiente[fim].~T();	// destrói elemento do fim

		if (size() == 1)	// se só existir um elemento no 'recipiente' antes do pop()
		{
			ini = -1;	// fixa índices para fora da 'recipiente'
			fim = -1;
		}
		else
			fim = (fim-1)%capacidade;	// retrocede indice 'fim'
		
	}

	/**
	* @brief Acrescenta um elemento no início do Deque
	* @param element Elemento do tipo T a ser acrescentado na frente da 'recipiente'
	*/
	template <typename T>
	void myDeque<T>::push_front( const T& elem );
	{	
		if(size() == capacidade)	
			my_reallocator();	// Realocar o tamanho do container do Deque quando atingir a capacidade maxima inicial
		
		if (empty())	// se for o primeiro elemento a entrar na 'recipiente'
			fim++;	// coloca 'fim' para apontar

		ini = (ini-1)%capacidade;	// retrocede indice 'ini'
		recipiente[ini] = element;	// Acrescenta elemento e depois aumenta o tamanho da 'recipiente'
	}

	/**
	* @brief Remove o elemento no início do Deque
	*/
	template <typename T>
	void myDeque<T>::pop_front();
	{
		if (empty())
			throw std::length_error ("[EXCEPTION] pop_front(): Não pode remover elementos de um deque vazio");
		

		recipiente[ini].~T();	// destrói elemento do ini

		if (size() == 1)	// se só existir um elemento no 'recipiente' antes do pop()
		{
			ini = -1;	// fixa índices para fora da 'recipiente'
			fim = -1;
		}
		else
			ini = (ini+1)%capacidade;	// avança indice 'ini'
		
	}

	/**
	* @brief Remove todos os elementos do Deque
	*/
	template <typename T>
	void myDeque<T>::clear()
	{
		while (empty() == false) pop_back();

	}


	// =================================================================================================
	// ================================== Sobrecarga de operadores =====================================
	// =================================================================================================

	/**
	* @brief Sobrecarga do operador '=='
	* @param orig Objeto myDeque que será comparado
	* @return 'true' se forem iguais, 'false' caso contrário
	*/
	template <typename T>
	bool myDeque<T>::operator== ( myDeque<T> d_direita)
	{
		if(size() == d_direita)
		{
			// cria indices para comparação
			int i = ini, dir_i = d_direita.ini;

			// checa cada elemento das listas, se estão na mesma ordem.
			for(auto count = 0; count < size(); count++ )
			{
				if( recipiente[i] != d_direita.recipiente[dir_i] ) return false;	// achou elementos diferentes
				
				// incrementa indices
				i = (i+1)%capacidade;
				dir_i = (dir_i+1)%d_direita.capacidade;
			}
			return true;	// não achou nenhum elemento diferente
		}
		return false;	// tamanhos diferentes
	}

	/**
	* @brief Sobrecarga do operador '='
	* @param orig Objeto myDeque a ser copiado
	*/
	template <typename T>
	myDeque<T>& myDeque<T>::operator= (const myDeque<T>& orig)
	{
		if( (*this == orig) == false ) // Se os deques não forem iguais
		{
		//	while (empty() == false)pop_back();	// Se o Deque não estiver vazio, o torna vazio

	/*!*/	this->(orig)	// Chama o construtor cópia com origem
		}

		return *this;
	}
;}

#endif