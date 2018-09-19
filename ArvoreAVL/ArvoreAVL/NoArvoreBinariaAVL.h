#pragma once
 
#ifndef NOARVOREBINARIAAVL_H_INCLUDED
#define NOARVOREBINARIAAVL_H_INCLUDED
using namespace std;
#include<iostream>
#include "InfoArvoreBinariaAVL.h"
class NoArvoreBinariaAVL
{
public:
	NoArvoreBinariaAVL() throw(char*);
	~NoArvoreBinariaAVL();
	NoArvoreBinariaAVL(const NoArvoreBinariaAVL&) throw(char*);
	friend ostream& operator<< (ostream&, const NoArvoreBinariaAVL&) throw();
	NoArvoreBinariaAVL* getPtrNoFilho(unsigned char) const throw(char*);
	void setPtrNoFilho(NoArvoreBinariaAVL*, unsigned char) const throw(char*);
	InfoArvoreBinariaAVL* getPtrInfo(unsigned int) const throw();
	char inserirVetorOrdem(InfoArvoreBinariaAVL*)throw();
	char removerVetorOrdem(InfoArvoreBinariaAVL*)throw();
	char isCheio() const throw();
	char isVazio() const throw();
	char isFolha() const throw();
	char haInfo(InfoArvoreBinariaAVL*) const throw();
private:
	InfoArvoreBinariaAVL* info;
	NoArvoreBinariaAVL* esq;
	NoArvoreBinariaAVL* dir;
	InfoArvoreBinariaAVL* acharInfoPorLugar() throw(char*);
	char equilibrio;
	InfoArvoreBinariaAVL* menorDosMaiores() throw(char*);
	InfoArvoreBinariaAVL* maiorDosMenores() throw(char*);
};
#endif