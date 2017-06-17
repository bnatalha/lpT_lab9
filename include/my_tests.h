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

#endif