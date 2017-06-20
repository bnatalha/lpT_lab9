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
	* @brief Um deque que usa um array circular alocado dinâmicamente
	* @tparam T Tipo dos elementos da lista
	*/
	template < typename T >
	class myDeque
	{
		private:
			int capacidade = 50;	/**< Capacidade máxima do deque */
			int ini;	/**< Índice para o inicio do deque */
			int fim;	/**< Índice para o fim do deque */
			T* fila;	/**< Onde os elementos do deque serão guardados*/

		public:
			/**
			* @class const_iterator
			* @brief iterator constante de myDeque
			* @sa const no fim da assinatura (https://stackoverflow.com/questions/1549869/)
			*/
			class const_iterator
			{
				public:
					// Construtor
					const_iterator();

					// Acesso
					const T& operator*() const;

					// Movimentação
					const_iterator& operator++ ();	// pré-incrementação
					const_iterator operator++ (int);	// pós-incrementação
					const_iterator& operator-- ();	// pré-decrementação
					const_iterator operator-- (int);	// pós-decrementação

					// Comparação
					bool operator==( const const_iterator & it_direita ) const;
					bool operator!=( const const_iterator & it_direita ) const;

				protected:
					// Construtor
					const_iterator( T *ponteiro )
						: atual (ponteiro)
					{} 

					// Atributos
					T * atual;	/**< Ponteiro para um elemento do deque */

					// Permissão
					friend class myDeque<T>;
			};

			/**
			* @class iterator
			* @brief iterator "modificável" de myDeque
			* @sa const no fim da assinatura (https://stackoverflow.com/questions/1549869/)
			*/
			class iterator : public const_iterator
			{
				public:
					// Construtor
					iterator()
						: const_iterator()
					{}

					// Acesso ao conteudo do iterator
					const T& operator*() const;
					T& operator*();

					// Movimentação
					iterator& operator++ ();	// pré-incrementação
					iterator operator++ (int);	// pós-incrementação
					iterator& operator-- ();	// pré-decrementação
					iterator operator-- (int);	// pós-decrementação
						
					// Atribuição
					iterator & operator= ( const iterator& it_direita );

				protected:
					// Construtor
					iterator ( T *ponteiro)
						: const_iterator(ponteiro)
					{}

					// Permissão
					friend class myDeque<T>;	
			};

			// Construtor
			myDeque();
			myDeque( const myDeque & orig );
			// Destrutor
			~myDeque();
			// Iterator
			const_iterator begin() const;
			iterator begin();
			const_iterator end() const;
			iterator end();
			// Acesso a elementos
			T& operator[] (int n);
			T& front();
			T& back();
			// Capacidade
			int size();
			bool empty();
			// Modificadores
			//void push_sorted(const T& elem );
			void push_sorted( T elem );
			void push_back( const T& elem );	// bool se tiver como checar se pode ser alocado ou não
			bool pop_back();
			void push_front( const T& elem );
			bool pop_front();
			void clear();
			void erase( iterator &it );
			//insert()	iterator
			// Operações
			void remove(const T& val);
			void unique();
			// > Auxiliares dos modificadores
			bool exist(const T& elem);
			//sort();
			// Sobrecarga de operadores
			bool operator== ( myDeque<T> d_direita);
			bool operator!= ( myDeque<T> d_direita);
			myDeque<T>& operator= (const myDeque<T>& copy);
			// PARA TESTE: sobrecarga operador <<
			//template <typename foo>
			//friend std::ostream& operator<< (std::ostream& out, const myDeque<foo> copy);
	};

namespace edb1
{
	// =================================================================================================
	// =========================================== Construtores ========================================
	// =================================================================================================

	/**
	* @brief Constrói um objeto myDeque vazio
	*/
	template <typename T>
	myDeque<T>::myDeque()	: ini(-1), fim(-1)
	{
		// tenta alocar o Deque.
		try{
			fila = new T[capacidade];
		}		
		catch( exception &e)
		{
			cerr << e.what() << endl;
		}

	}

	/**
	* @brief Constrói um objeto myDeque a partir de outro já existente (cópia)
	* @param objeto myDeque que será usado como referência para ser copiado
	*/
	template <typename T>
	myDeque<T>::myDeque( const myDeque & orig )	: ini(orig.ini), fim(orig.fim)
	{
		// tenta alocar o Deque com a capacidade do deque 'orig'.
		try{
			fila = new T[orig.capacidade];
		}		
		catch( exception &e)
		{
			cerr << e.what() << endl;
		}

		// copia os elementos de orig para este deque
		for(i = 0; i < orig.size(); i++) this->fila[i] = orig.fila[i];
	}

	// =========================================== Destrutor ========================================
	
	/**
	* @brief Destrói um objeto myDeque, destruindo sua 'fila'
	*/
	template <typename T>
	myDeque<T>::myDeque()
	{
		delete[] fila;
	}

	// =================================================================================================
	// =========================================== Iterator ============================================
	// =================================================================================================

	//

	// =================================================================================================
	// =========================================== Acesso ==============================================
	// =================================================================================================

	/**
	* @return Referência para o elemento na posição 'n' do container 'fila'
	*/
	template <typename T>
	T& myDeque<T>::operator[] (int n)
	{
		if(empty())	// Se deque estiver vazio
			throw std::out_of_range ("[EXCEPTION] operator[]: Não há elementos no deque");

		return fila[ (ini + n )% capacidade ];
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

		return fila[ (ini + n )% capacidade ];
	}

	/**
	* @return Referência para o elemento no início da fila, se existir.
	*/
	template <typename T>
	T& myDeque<T>::front()
	{
		if(empty())	// Se deque estiver vazio, chamar exceção
			throw std::out_of_range ("[EXCEPTION] front(): Não há elementos no deque");

		return fila[ini];
	}

	/**
	* @return Referência para o elemento no fim da fila,  se existir.
	*/
	template <typename T >
	T& myFila<T>::back()
	{
		if (empty())	// Se deque estiver vazio, chamar exceção
			throw std::out_of_range ("[EXCEPTION] back(): Não há elementos na fila");
		
		return fila[fim];
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
				if( fila[i] != d_direita.fila[dir_i] ) return false;	// achou elementos diferentes
				
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