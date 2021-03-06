#pragma once

#ifndef MINHAINFO_H_INCLUDED
#define MINHAINFO_H_INCLUDED
#include "InfoArvoreBinariaAVL.h"
#include <iostream>
using namespace std;
class MinhaInfo : public InfoArvoreBinariaAVL
{
public:
	MinhaInfo();
	MinhaInfo(int);
	MinhaInfo(const InfoArvoreBinariaAVL&) throw();
	friend ostream& operator<< (ostream&, const MinhaInfo&) throw();
	int getValor() const throw();
	void setValor(int) throw();
	char operator<(const InfoArvoreBinariaAVL&)const throw() ;
	char operator>(const InfoArvoreBinariaAVL&)const throw() ;
	char operator==(const InfoArvoreBinariaAVL&)const throw();
	char operator<=(const InfoArvoreBinariaAVL&)const throw();
	char operator>=(const InfoArvoreBinariaAVL&)const throw();
	InfoArvoreBinariaAVL& operator=(const InfoArvoreBinariaAVL&)throw();
	ostream& print(ostream&) const throw() ;
	
private:
	int valor;
	
};
#endif

