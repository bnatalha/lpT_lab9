/**
* @file
* @brief Definição do namespace edb1
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 15/06/2017
* @date --
*/

#ifndef NATALIA_H
#define NATALIA_H

#include "header.h"

/**
* @namespace edb1
* @brief Contem definições feitas pelo usuári de algoritmos de ordenação de TAD's estudados na disciplina de Estrutura de Dados.
*/
namespace edb1 
{
	// Algoritmos

	void mySwap( int &a, int &b);

	bool maiorque(int a, int b);
	bool menorque(int a, int b);

	void myBubbleSort (int *v, int ini, int fim);	// crescente
	
	void myInsertSort (int *v, int ini, int fim);	// crescente

	void mySelectionSort (int *v, int ini, int fim);	//
	
	int myQuickSortPartition(int *v, int ini, int fim);
	void myQuickSort (int *v, int ini, int fim);
	
	void mySplitSort (int *v, int ini, int fim);
	void myMergeSort (int *dir, int d_size, int *esq, int e_size, int *v, int fim);

	// TAD's

	/**
	* @class myPilha
	* @brief classe criada para simular a classe std::stack da STL do C++
	* @tparam T Tipo dos elementos da pilha
	*/
	template < typename T >
	class myPilha 
	{
		private:

			static const int capacidade = 50;	/**< Capacidade padrão de todas as pilhas */
			int tamanho;	/**< Quantitade de elementos na pilha */
			T *pilha = NULL;	/**< Arranjo que será alocado dinamicamente para guardar os elementos da pilha */

		public:

			/**
			* @brief Constroi um objeto myPilha sem passar atributos.
			*/
			myPilha()
				: tamanho(0), pilha(new T[capacidade])
			{} // EXTRA!: tratamento de exceção na alocação dinâmica ()

			/**
			* @brief Constroi um objeto myPilha  partir de uma pilha já definida pelo usuário
			* @param my_stack myPilha já existente que será sada pra construir a atual
			*/
			myPilha(const myPilha &my_stack)
				: tamanho(my_stack.tamanho), pilha(new T[capacidade])
			{
				for (int i = 0; i < capacidade; ++i)
				{
					this->pilha[i] = my_stack.pilha[i];	// Copia elementos da pilha passada por argumento para a pilha a ser criada
				}
				
			}

			/**
			* @brief Desaloca 'pilha' após chamar o destrutor de seus respectivos elementos
			*/
			~myPilha()
			{
				delete[] pilha;
			}

			// Metodos

			bool empty();	/**< Verifica se a pilha está vazia */
			int& size();	/**< Retorna uma referência para o tamanho da pilha */
			T& top();	/**< Retorna uma referência para elemento no topo da pilha */
			void push(const T& element);	/**< Acrescenta um elemento no topo da pilha, aumentando o tamanho da pilha */
			void pop();	/**< Remove o elemento do topo da pilha, diminuindo o tamanho da pilha */
	};

	#include "myLista.h"
}

#include "myPilha.h"

#endif