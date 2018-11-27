#include "ArvoreBinariaAVL.h"


ArvoreBinariaAVL::ArvoreBinariaAVL()
{
	this->raiz = nullptr;
}


ArvoreBinariaAVL::~ArvoreBinariaAVL()
{
	if(this->raiz != nullptr)
		delete raiz;
}
void ArvoreBinariaAVL::inserir( InfoArvoreBinariaAVL* info) throw(char*) {
	
	if (this->raiz == nullptr)
		raiz = new NoArvoreBinariaAVL();
	if ((this->raiz->isVazio())) {
		this->raiz == nullptr;
		raiz = new NoArvoreBinariaAVL();
	}
	this->raiz->inserirVetorOrdem(info);

	this->balancear();
}
void ArvoreBinariaAVL::remover(InfoArvoreBinariaAVL* info) throw(char*) {
	if (this->raiz == nullptr) {
		//árvore está vazia
		throw("Tentativa de remoção em árvore vazia!");
	}
	this->raiz->removerVetorOrdem(info, nullptr);
	if ((this->raiz->isVazio()))
		this->raiz = nullptr;

	this->balancear();
}
char ArvoreBinariaAVL::haInfo(const InfoArvoreBinariaAVL& valor) {
	if (this->raiz == nullptr)
		return 0;
	return this->raiz->haInfo(valor);
}

ostream& operator<< (ostream& os, const ArvoreBinariaAVL& arvore) throw() {
	if (arvore.raiz == nullptr)
		return os << "{  }" << '\n';
	return	os << '{' << *(arvore.raiz) << '}' << '\n';
}


void ArvoreBinariaAVL::balancear() throw(){
	if (this->raiz == nullptr)
		return;
	this->raiz->balancear();
}