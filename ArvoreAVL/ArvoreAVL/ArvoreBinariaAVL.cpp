#include "stdafx.h"
#include "ArvoreBinariaAVL.h"


ArvoreBinariaAVL::ArvoreBinariaAVL()
{
	this->raiz = nullptr;
}


ArvoreBinariaAVL::~ArvoreBinariaAVL()
{
}
void ArvoreBinariaAVL::inserir(InfoArvoreBinariaAVL* info) throw(char*) {
	if (this->raiz == nullptr)
		raiz = new NoArvoreBinariaAVL();
	this->raiz->inserirVetorOrdem(info);

}
void ArvoreBinariaAVL::remover(InfoArvoreBinariaAVL* info) throw(char*) {
	if (this->raiz == nullptr) {
		//�rvore est� vazia
		throw("Tentativa de remo��o em �rvore vazia!");
	}
	this->raiz->removerVetorOrdem(info);
	if (this->raiz->isVazio())
		this->raiz == nullptr;
}
char ArvoreBinariaAVL::haInfo(InfoArvoreBinariaAVL* info) {
	if (this->raiz == nullptr)
		return 0;
	return this->raiz->haInfo(info);
}

ostream& operator<< (ostream& os, const ArvoreBinariaAVL& arvore) throw() {
	if (arvore.raiz == nullptr)
		return os << "{  }" << '\n';
	return	os << '{' << *(arvore.raiz) << '}' << '\n';
}