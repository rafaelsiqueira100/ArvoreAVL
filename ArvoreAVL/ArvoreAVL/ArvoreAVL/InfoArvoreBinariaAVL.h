#pragma once
#ifndef INFOARVOREBinariaAVL_H_INCLUDED
#define INFOARVOREBinariaAVL_H_INCLUDED
#include <iostream>
using namespace std;
class InfoArvoreBinariaAVL
{
public:
	InfoArvoreBinariaAVL();
	~InfoArvoreBinariaAVL();
	//InfoArvoreBinariaAVL(const InfoArvoreBinariaAVL&) throw();
	friend ostream& operator<< (ostream&, InfoArvoreBinariaAVL&) throw();
	virtual char operator<(const InfoArvoreBinariaAVL&)const throw() = 0;
	virtual char operator>(const InfoArvoreBinariaAVL&)const throw() = 0;
	virtual char operator==(const InfoArvoreBinariaAVL&)const throw() = 0;
	virtual char operator<=(const InfoArvoreBinariaAVL&)const throw() = 0;
	virtual char operator>=(const InfoArvoreBinariaAVL&)const throw() = 0;
	virtual void operator=(const InfoArvoreBinariaAVL&)throw() = 0;
	virtual ostream& print(ostream&)const throw() = 0;

};
#endif
