#include "NoArvoreBinariaAVL.h"



NoArvoreBinariaAVL::NoArvoreBinariaAVL()
{
	this->esq = nullptr;
	this->dir = nullptr;
	this->info = nullptr;
}


NoArvoreBinariaAVL::~NoArvoreBinariaAVL()
{
}
NoArvoreBinariaAVL::NoArvoreBinariaAVL(const NoArvoreBinariaAVL& noBase) throw(char*) {
	this->esq = nullptr;
	this->dir = nullptr;
	this->info = nullptr;
	if (noBase.info != nullptr) {
		this->info = noBase.info;
	}
	if (noBase.getPtrNoFilho(0) != nullptr) {//esq não é nulo
		this->esq = new NoArvoreBinariaAVL(*(noBase.getPtrNoFilho(0)));
	}
	if (noBase.getPtrNoFilho(1) != nullptr) {//dir não é nulo
		this->dir = new NoArvoreBinariaAVL(*(noBase.getPtrNoFilho(1)));
	}
	
}

NoArvoreBinariaAVL* NoArvoreBinariaAVL::getPtrNoFilho(unsigned char indicePtr) const throw(char*) {
	switch (indicePtr)
	{
	case 0:
		return (this->esq);
		break;
	case 1:
		return (this->dir);
		break;
	default:
		throw("Índice maior que 1 em árvore binária !!");
		break;
	}
}
void NoArvoreBinariaAVL::setPtrNoFilho(NoArvoreBinariaAVL* novoNo, unsigned char indFilho) const throw(char*) {
	if (novoNo == nullptr)
		throw("Novo nó é nulo!");
	switch (indFilho) {
	case 0:
		*(this->esq) = *novoNo;
		break;
	case 1:
		*(this->dir) = *novoNo;
		break;
	default:
		throw("Índice maior que 1 em árvore binária !!");
		break;
	}
}
InfoArvoreBinariaAVL*  NoArvoreBinariaAVL::getPtrInfo(unsigned int indInfo) const throw() {
	return this->info;
}
char NoArvoreBinariaAVL::inserirVetorOrdem(InfoArvoreBinariaAVL* info)throw() {
	if (info == nullptr)
		return -1;
	//supondo árvore está ordenada
	
		if ((this->info ) != nullptr) {
			if (*info < *(this->info)) {
				if (this->esq == nullptr) {
					this->esq = new NoArvoreBinariaAVL();
					this->esq->info = info;
					return 1;
				}
				else
					this->esq->inserirVetorOrdem(info);
			}
			if (*info > *(this->info)) {
				if (this->dir == nullptr) {
					this->dir = new NoArvoreBinariaAVL();
					this->dir->info = info;
					return 1;
				}
				else
					this->dir->inserirVetorOrdem(info);

			}
			if (*(this->info) == *info) {
				return 0;
			}
		}
		else {
			this->info = /*new InfoArvoreEnaria(**/info/*)*/;

			return 1;
		}
	
}
char NoArvoreBinariaAVL::removerVetorOrdem(InfoArvoreBinariaAVL* info)throw() {
	if (info == nullptr)
		return -1;
	if (this->isFolha()) {
		if (*info == *(this->info)) {
			this->info = nullptr;
			return 1;
		}
		else
			return 0;
	}
	//se o fluxo de execução chegou aqui, então não é folha
	if (*info == *(this->info)) {
		//tem que achar info pra por no lugar
		*(this->info) = *(acharInfoPorLugar());
	}
	if (*info < *(this->info)) {
		if (this->esq == nullptr)
			return -2;
		else
			this->esq->removerVetorOrdem(info);
	}
	if (*info > *(this->info)) {
		if (this->dir == nullptr)
			return -3;
		else
			this->dir->removerVetorOrdem(info);
	}
}
char NoArvoreBinariaAVL::isCheio() const throw() {
	return this->info != nullptr;
}
char NoArvoreBinariaAVL::isVazio() const throw() {
	return this->info == nullptr;
}
char NoArvoreBinariaAVL::isFolha() const throw() {
	return (this->esq == nullptr && this->dir == nullptr);
}
char NoArvoreBinariaAVL::haInfo(InfoArvoreBinariaAVL*) const throw() {
	NoArvoreBinariaAVL* noRel = (NoArvoreBinariaAVL*)(this);

	while (1) {
		
		if ((noRel->info ) != nullptr) {
			if (*(noRel->info ) == *info) {
				return true;
			}
			if (*(noRel->info) > *info) {
				//ir pro ponteiro de nó i-1
				noRel = (noRel->esq);

			}
			if (*(noRel->info) < *info) {
				noRel = (noRel->dir);
			}

		}
		else {
			return false;
		}
		
	}
}
/*	InfoArvoreBinariaAVL * info;
	NoArvoreBinariaAVL* esq;
	NoArvoreBinariaAVL* dir;*/
InfoArvoreBinariaAVL* NoArvoreBinariaAVL::acharInfoPorLugar() throw(char*) {
	
	InfoArvoreBinariaAVL* infoTrocarFilho = nullptr;
	if (this->esq == nullptr) {
		infoTrocarFilho = menorDosMaiores();
	}
	else {
		infoTrocarFilho = maiorDosMenores();
	}
	return infoTrocarFilho;
}
InfoArvoreBinariaAVL* NoArvoreBinariaAVL::menorDosMaiores() throw(char*) {
	NoArvoreBinariaAVL* noAnt = (NoArvoreBinariaAVL*)this;
	NoArvoreBinariaAVL* noRel = (NoArvoreBinariaAVL*)this->dir;
	NoArvoreBinariaAVL* noAchado;
	while (noRel->esq != nullptr) {
		noAnt = noRel;
		noRel = noRel->esq;
	}
	if (noRel->dir == nullptr) {
		noAchado = new NoArvoreBinariaAVL(*noRel);
		noRel->info = nullptr;
		noAnt->esq = noRel = nullptr;
		return noAchado->info;
	}
	else {
		noAchado = new NoArvoreBinariaAVL(*noRel);
		noAnt->esq = noRel->dir;
		noRel->info = nullptr;
		noRel = nullptr;
		return noAchado->info;
	}
}
InfoArvoreBinariaAVL* NoArvoreBinariaAVL::maiorDosMenores() throw(char*) {
	NoArvoreBinariaAVL* noAnt = (NoArvoreBinariaAVL*)this;
	NoArvoreBinariaAVL* noRel = (NoArvoreBinariaAVL*)this->esq;
	NoArvoreBinariaAVL* noAchado;
	while (noRel->dir != nullptr) {
		noAnt = noRel;
		noRel = noRel->dir;
	}
	if (noRel->esq == nullptr) {
		noAchado = new NoArvoreBinariaAVL(*noRel);
		noRel->info = nullptr;
		noAnt->dir = noRel = nullptr;
		return noAchado->info;
	}
	else {
		noAchado = new NoArvoreBinariaAVL(*noRel);
		noAnt->dir = noRel->esq;
		noRel->info = nullptr;
		noRel = nullptr;
		return noAchado->info;
	}
}
ostream& operator<< (ostream& os, const NoArvoreBinariaAVL& no) throw() {
	int indicePtr = 0;
	int indiceInfo = 0;

	

	if (no.getPtrNoFilho(0) != nullptr) {
		os << '(' << *(no.getPtrNoFilho(0)) << ')';
	}
	else {
		os << "(  ||  )";
	}
		
	if (no.getPtrInfo(0) != nullptr) {
		InfoArvoreBinariaAVL* info = (no.getPtrInfo(0));
		os << "  " << (*(info)) << "  ";
	}
	else {
		os << "  **  ";
	}
	
	
	if (no.getPtrNoFilho(1) != nullptr) {
		os << '(' << *(no.getPtrNoFilho(1)) << ')';
	}
	else {
		os << "(  ||  )";
	}
	return os;
}
