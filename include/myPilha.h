/**
* @file
* @brief Definição e implementação de myPilha do namespace edb1
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 14/05/2017
* @date 15/06/2017
* @sa std::stack (http://www.cplusplus.com/reference/stack/stack/)
*/

#ifndef MYPILHA_H
#define MYPILHA_H

#include "natalia.h"

namespace edb1
{
	// Implementações de myPilha

	/**
	* @retval true A pilha está vazia
	* @retval false A pilha \b não está vazia
	*/
	template <typename T >
	bool myPilha<T>::empty()
	{
		return (tamanho == 0);
	}

	/**
	* @return Referência para o tamanho da pilha
	*/
	template <typename T >
	int& myPilha<T>::size()
	{
		return tamanho;
	}

	/**
	* @return Referência para o elemento no topo da pilha
	*/
	template <typename T >
	T& myPilha<T>::top()
	{
		if (empty())
		{
			cerr << "top(): Não há elementos na pilha (tamanho: "<< tamanho << ")." << endl;
			exit(1);
		}
		//else

		return pilha[tamanho-1];
	}

	/**
	* @param element Elemento do tipo T a ser acrescentado ao topo da pilha
	*/
	template <typename T >
	void myPilha<T>::push(const T& element)
	{
		if(tamanho == capacidade)
		{
			cerr << "push(): A capacidade da pilha já foi atingida "
				<< "(tamanho :"<< tamanho << ", capacidade:" << capacidade << ")." << endl;
			exit(1);
		}
		//else

		pilha[tamanho++] = element;	// Acrescenta elemento e depois aumenta o tamanho da pilha
	}

	template <typename T >
	void myPilha<T>::pop()
	{
		if (empty())
		{
			cerr << "pop(): Não pode remover elementos de uma pilha de tamanho '"<< tamanho << "'." << endl;
			exit(1);
		}
		//else

		pilha[(tamanho--)-1].~T();	// Remove elemento e depois diminui o tamanho da pilha
	}
}

#endif