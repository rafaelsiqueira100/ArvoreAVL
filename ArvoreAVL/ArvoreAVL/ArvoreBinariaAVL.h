#pragma once
using namespace std;
#include<iostream>
#include "NoArvoreBinariaAVL.h"
#include "InfoArvoreBinariaAVL.h"
#ifndef ARVOREBINARIAAVL_H_INCLUDED
#define ARVOREBINARIAAVL_H_INCLUDED
class ArvoreBinariaAVL
{
public:
	ArvoreBinariaAVL();
	~ArvoreBinariaAVL();
	void inserir(InfoArvoreBinariaAVL*) throw(char*);
	void remover(InfoArvoreBinariaAVL*) throw(char*);
	friend ostream& operator<< (ostream&, const ArvoreBinariaAVL&) throw();
	char haInfo(InfoArvoreBinariaAVL*);
	
private:
	NoArvoreBinariaAVL* raiz;
	void balancear() throw();
};
#endif