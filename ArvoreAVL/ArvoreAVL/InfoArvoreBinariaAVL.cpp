
#include "InfoArvoreBinariaAVL.h"


InfoArvoreBinariaAVL::InfoArvoreEnaria()
{
}


InfoArvoreBinariaAVL::~InfoArvoreEnaria()
{
}

ostream& operator<< (ostream& os, InfoArvoreBinariaAVL& info) throw() {
	return((info).print(os));
}