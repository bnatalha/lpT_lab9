/**
* @file
* @brief Definição e implementação de myFila do namespace edb1
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 14/05/2017
* @date 15/06/2017
* @sa std::stack (http://www.cplusplus.com/reference/stack/stack/)
*/

#ifndef MYFILA_H
#define MYFILA_H

#include "natalia.h"

namespace edb1
{
	// Implementações de myFila

	/**
	* @retval true A fila está vazia
	* @retval false A fila \b não está vazia
	*/
	template <typename T >
	bool myFila<T>::empty()
	{
		return (size() == 0);
	}

	/**
	* @return Referência para o tamanho da fila
	*/
	template <typename T >
	int myFila<T>::size()
	{
		if (ini == -1) return 0;
		else if(ini == fim ) return 1;
		else if(ini < fim) return ((fim-ini)+1);
		//else if (ini > fim)
		return ( (fim + (capacidade - ini) )+ 1);
		cout << 'a' << endl;
	}

	/**
	* @return Referência para o elemento na frente da fila
	*/
	template <typename T >
	T& myFila<T>::front()
	{
		if (empty())
		{
			cerr << "front(): Não há elementos na fila (tamanho: "<< size() << ")." << endl;
			exit(1);
		}
		//else

		return fila[ini];
	}

	/**
	* @return Referência para o elemento no fim da fila
	*/
	template <typename T >
	T& myFila<T>::back()
	{
		if (empty())
		{
			cerr << "back(): Não há elementos na fila (tamanho: "<< size() << ")." << endl;
			exit(1);
		}
		//else

		return fila[fim];
	}

	/**
	* @param element Elemento do tipo T a ser acrescentado na frente da fila
	*/
	template <typename T >
	void myFila<T>::push(const T& element)
	{
		if(size() == capacidade)
		{
			cerr << "push(): A capacidade da fila já foi atingida."
				<< "(tamanho :"<< size() << ", capacidade:" << capacidade << ")." << endl;
			exit(1);
		}
		//else
		if (empty())
			ini++;
		fim = (fim+1)%capacidade;	// avança indice 'fim'
		fila[fim] = element;	// Acrescenta elemento e depois aumenta o tamanho da fila
		//cout << fila[fim] << endl;
	}

	template <typename T >
	void myFila<T>::pop()
	{
		if (empty())
		{
			cerr << "pop(): Não pode remover elementos de uma fila de tamanho '"<< size() << "'." << endl;
			exit(1);
		}
		//else

		fila[ini].~T();	// Remove elemento da frente

		if (size() == 1)	// se só existir um elemento na fila antes do pop()
		{
			ini = -1;	// fixa índices para fora da fila
			fim = -1;
		}
		else
			ini = (ini+1)%capacidade;	// avança indice 'ini'
		
	}
}

#endif