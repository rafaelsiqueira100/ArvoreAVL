#include "InfoArvoreBinariaAVL.h"


InfoArvoreBinariaAVL::InfoArvoreBinariaAVL()
{
}


InfoArvoreBinariaAVL::~InfoArvoreBinariaAVL()
{
}

ostream& operator<< (ostream& os, InfoArvoreBinariaAVL& info) throw() {
	return((info).print(os));
}