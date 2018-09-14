#pragma once
using namespace std;
#include<iostream>
class ArvoreBinariaAVL
{
public:
	ArvoreBinariaAVL();
	~ArvoreBinariaAVL();
	void inserir() throw(char*);
	void remover() throw(char*);
	friend ostream& operator<< (ostream&, const ArvoreBinariaAVL&) throw();
	char haInfo()

};

