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
	void setPtrNoFilho(NoArvoreBinariaAVL*, unsigned char) throw(char*);
	InfoArvoreBinariaAVL* getPtrInfo(unsigned int) const throw();
	char inserirVetorOrdem(InfoArvoreBinariaAVL*)throw();
	char removerVetorOrdem(InfoArvoreBinariaAVL*)throw();
	char isCheio() const throw();
	char isVazio() const throw();
	char isFolha() const throw();
	char haInfo(InfoArvoreBinariaAVL*) const throw();
	char getEquilibrio() const throw();
	char getNiveis() const throw();
	void balancear() throw();
	void rotacaoEsquerda() throw();
	void rotacaoDireita() throw();
private:
	InfoArvoreBinariaAVL* info;
	NoArvoreBinariaAVL* esq;
	NoArvoreBinariaAVL* dir;
	InfoArvoreBinariaAVL* acharInfoPorLugar() throw(char*);
	char equilibrio;
	char calcularEquilibrio() throw();
	InfoArvoreBinariaAVL* menorDosMaiores() throw(char*);
	InfoArvoreBinariaAVL* maiorDosMenores() throw(char*);
	
	void rotacaoDuplaEsquerda() throw();
	void rotacaoDuplaDireita() throw();

};
#endif