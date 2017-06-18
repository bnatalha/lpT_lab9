#ifndef MY_TESTS_H
#define MY_TESTS_H

#include "natalia.h"

void testar_lista()
{

	edb1::myLista<int> aaa;
	edb1::myLista<int> bbb;
	edb1::myLista<int> ccc;
	edb1::myLista<int> ddd;
	
	// preenchendo listas
	for (int i = 0; i <= 10; ++i)
	{
		aaa.push_back(i);
		if(i != 0 )ddd.push_back(i);
		else ddd.push_back(34);
		if(i%2 == 0) bbb.push_back(i);
	}
	
	ccc = aaa;

	// imprimindo listas
	cout << "aaa: [ ";
	for (auto &e : aaa)
		cout << e << " ";
	cout << "]" << endl;
	cout << "bbb: [ ";
	for (auto &e : bbb)
		cout << e << " ";
	cout << "]" << endl;
	cout << "ccc: [ ";
	for (auto &e : ccc)
		cout << e << " ";
	cout << "]" << endl;
		cout << "ddd: [ ";
	for (auto &e : ddd)
		cout << e << " ";
	cout << "]" << endl;

	// comparando listas
	cout << "aaa e bbb" << (aaa == bbb?" ":" não ") << "são iguais" << endl;
	cout << "aaa e ccc" << (aaa == ccc?" ":" não ") << "são iguais" << endl;
	cout << "aaa e ddd" << (aaa == ddd?" ":" não ") << "são iguais" << endl;	
}

void testar_pilha()
{
	// Criando pilhas
	cout << "Creating stacks A, B..."; 
	edb1::myPilha<int> A;	// capacidade: padrão (2)
	edb1::myPilha<char> B;	// capacidade: padrão (2)
	cout << "Done" << endl;

	// Testes com pilhas vazias
	cout << "A is" << (A.empty()? "":" not") << " empty." << endl;
	cout << "B is" << (B.empty()? "":" not") << " empty." << endl;
	cout << "--" << endl;

	// Testando push
	cout << "Testing push():" << endl;
	int a = 1;
	char b = 'a';

	A.push(a);
	cout << "A's top element is " << A.top() << endl;
	cout << "Current size:" << A.size() << endl;
	A.push(2);
	cout << "A's top element is " << A.top() << endl;
	cout << "Current size:" << A.size() << endl;
//	A.push(3);	// exceeding capacity
//	cout << "A's top element is " << A.top() << endl;
//	cout << "Current size:" << A.size() << endl;

	B.push(b);
	cout << "B's top element is " << B.top() << endl;
	cout << "Current size:" << B.size() << endl;
	B.push('b');
	cout << "B's top element is " << B.top() << endl;
	cout << "Current size:" << B.size() << endl;

	cout << "-" << endl;

	// Testanto Construtor myPilha(myPilha)
	cout << "Creating stacks C from stack A..."; 
	edb1::myPilha<int> C(A);

	// Testando pop
	cout << "Testing pop():" << endl;
	for (int i = 0; i <= C.size(); ++i)
	{
		cout << "C's top element is " << C.top() << endl;
		cout << "Current size:" << C.size() << endl;
		C.pop();
		cout << "popping.." << endl;
	}

	cout << endl;

	// Testando pop
	for (int i = 0; i < 2; ++i)
	{
		cout << "A's top element is " << A.top() << endl;
		cout << "Current size:" << A.size() << endl;
		A.pop();
		cout << "popping.." << endl;
	}
}

void testar_fila()
{
	// Criando opilha vazia
	cout << "Criando fila A (vazia)...";
	edb1::myFila<int> A;
	cout << "Pronto." << endl;

	// Testes com pilhas vazias
	cout << "A.size(): " << A.size() << ";\t";
	cout << "'A'" << (A.empty()? "":" não") << " está vazia." << endl;

	//for (int i = 1; i < 4; i++)
	for (int i = 1; i <3; i++)
	{	
		cout << "A.push(" << i << ");" << endl;
		A.push(i);
		cout << "A.size(): " << A.size() << ";\t";
		cout << "'A'" << (A.empty()? "":" não") << " está vazia." << endl;
		cout << "A.front(): " << A.front() << " e A.back(): " << A.back() << "." << endl;
		cout << "--" << endl;
	}
	cout << endl;

	cout << "Criando fila B de A(1 elemento)...";
	edb1::myFila<int> B(A);
	cout << "Pronto." << endl;

	cout << "B is" << (B.empty()? "":" not") << " empty." << endl;
	cout << "B.front(): " << B.front() << " e B.back(): " << B.back() << "." << endl;
	cout << "B.pop();" << endl;
	B.pop();
	cout << "B.size(): " << B.size() << ";\t";
	cout << "B is" << (B.empty()? "":" not") << " empty." << endl;
	cout << "B.front(): " << B.front() << " e B.back(): " << B.back() << "." << endl << endl;

	for (int i = 1; i < 3; i++)
	{	
		cout << "A.pop();" << endl;
		A.pop();
		cout << "A.size(): " << A.size() << ";\t";
		cout << "A.front(): " << A.front() << " e A.back(): " << A.back() << "." << endl;
		cout << "--" << endl;
	}
	cout << endl;

	for (int i = 7; i < 9; i++)
	{	
		cout << "A.push(" << i << ");" << endl;
		A.push(i);
		cout << "A.size(): " << A.size() << ";\t";
		cout << "'A'" << (A.empty()? "":" não") << " está vazia." << endl;
		cout << "A.front(): " << A.front() << " e A.back(): " << A.back() << "." << endl;
		cout << "--" << endl;
	}
	cout << endl;

	cout << "Criando Fila C de A...";
	edb1::myFila<int> C(A);
	cout << "Pronto." << endl;

	cout << "Limpando A...";
	while (A.empty() == false) A.pop();
	cout << "Pronto." << endl;

	cout << "C is" << (C.empty()? "":" not") << " empty." << endl;
	cout << "C.front(): " << C.front() << " e C.back(): " << C.back() << "." << endl;
	cout << "C.pop();" << endl;
	C.pop();
	cout << "C.size(): " << C.size() << ";\t";
	cout << "C is" << (C.empty()? "":" not") << " empty." << endl;
	cout << "C.front(): " << C.front() << " e C.back(): " << C.back() << "." << endl;
	
}

#endif