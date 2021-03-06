#include "NoArvoreBinariaAVL.h"
#include <math.h>


NoArvoreBinariaAVL::NoArvoreBinariaAVL()
{
	this->esq = nullptr;
	this->dir = nullptr;
	this->info = nullptr;
}


NoArvoreBinariaAVL::~NoArvoreBinariaAVL()
{
	if(this->info != nullptr)
		delete info;
	if(this->esq != nullptr)
		delete esq;
	if(this->dir != nullptr)
		delete dir;

}
NoArvoreBinariaAVL::NoArvoreBinariaAVL(const NoArvoreBinariaAVL& noBase) throw(char*) {
	this->esq = nullptr;
	this->dir = nullptr;
	this->info = nullptr;
	this->equilibrio = 0;
	
	this->equilibrio = noBase.getEquilibrio();
	if (noBase.info != nullptr) {
		this->info = noBase.info;
	}
	if (noBase.getPtrNoFilho(0) != nullptr) {//esq n�o � nulo
		this->esq = new NoArvoreBinariaAVL(*(noBase.getPtrNoFilho(0)));
	}
	if (noBase.getPtrNoFilho(1) != nullptr) {//dir n�o � nulo
		this->dir = new NoArvoreBinariaAVL(*(noBase.getPtrNoFilho(1)));
	}
	//balancear();
	
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
		throw("�ndice maior que 1 em �rvore bin�ria !!");
		break;
	}
}
void NoArvoreBinariaAVL::setPtrNoFilho(NoArvoreBinariaAVL* novoNo, unsigned char indFilho) throw(char*) {
	if (novoNo == nullptr)
		throw("Novo n� � nulo!");
	switch (indFilho) {
	case 0:
		if (this->esq == nullptr)
			this->esq = new NoArvoreBinariaAVL(*novoNo);
		else
			*(this->esq) = *novoNo;
		//balancear();
		break;
	case 1:
		if(this->dir == nullptr)
			this->dir = new NoArvoreBinariaAVL(*novoNo);
		else
			*(this->dir) = *novoNo;
		//balancear();
		break;
	default:
		throw("�ndice maior que 1 em �rvore bin�ria !!");
		break;
	}
}
InfoArvoreBinariaAVL*  NoArvoreBinariaAVL::getPtrInfo(unsigned int indInfo) const throw() {
	return this->info;
}
char NoArvoreBinariaAVL::inserirVetorOrdem(InfoArvoreBinariaAVL* info)throw() {
	//InfoArvoreBinariaAVL* info = (InfoArvoreBinariaAVL*) &valor;
	if (info == nullptr)
		return -1;
	//supondo �rvore est� ordenada
	
		if ((this->info ) != nullptr) {
			if (*info < *(this->info)) {
				if (this->esq == nullptr) {
					this->esq = new NoArvoreBinariaAVL();
					this->esq->info = info;
					balancear();
					return 1;
				}
				else
					this->esq->inserirVetorOrdem(info);
			}
			if (*info > *(this->info)) {
				if (this->dir == nullptr) {
					this->dir = new NoArvoreBinariaAVL();
					this->dir->info =info;
					balancear();
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
			this->info = info;
			balancear();
			return 1;
		}
	
}
char NoArvoreBinariaAVL::removerVetorOrdem(InfoArvoreBinariaAVL* info,NoArvoreBinariaAVL* ant)throw() {
	if (info == nullptr) 
		return -1;
	
	if (this->isFolha()) {
		if (*info == *(this->info)) {
			this->info = nullptr;
			/*NoArvoreBinariaAVL* no = this;
			no = nullptr;*/
			if (ant != nullptr) {
				if (*info > *(ant->info)) {
					(ant)->dir = nullptr;
				}
				if (*info < *(ant->info)) {
					(ant)->esq = nullptr;
				}
			}
			else {
				//�rvore est� vazia
				this->info = nullptr;
			}
				
			//balancear();
			return 1;
		}
		else {
			balancear();
			return 0;
		}
	}
	//se o fluxo de execu��o chegou aqui, ent�o n�o � folha
	if (*info == *(this->info)) {
		//tem que achar info pra por no lugar
		*(this->info) = *(acharInfoPorLugar());
		return 2;
	}
	if (*info < *(this->info)) {
		if (this->esq == nullptr) {
			balancear();
			return -2;
		}
		else
			this->esq->removerVetorOrdem(info, this);
	}
	if (*info > *(this->info)) {
		if (this->dir == nullptr) {
			balancear();
			return -3;
		}
		else
			this->dir->removerVetorOrdem(info, this);
	}
	
}
char NoArvoreBinariaAVL::isCheio() const throw() {
	return this->info != nullptr;
}
char NoArvoreBinariaAVL::isVazio() const throw() {
	return (this->info) == nullptr;
}
char NoArvoreBinariaAVL::isFolha() const throw() {
	
	return (this->esq == nullptr && this->dir == nullptr);
}
char NoArvoreBinariaAVL::haInfo(const InfoArvoreBinariaAVL& valor) const throw() {
	InfoArvoreBinariaAVL* info = (InfoArvoreBinariaAVL*)(&valor);
	NoArvoreBinariaAVL* noRel = (NoArvoreBinariaAVL*)(this);

loop:while (1) {
		if (noRel == nullptr)
			return 0;
		if ((noRel->info ) != nullptr) {
			if (*(noRel->info ) == *info) {
				return true;
			}
			if (*(noRel->info) > *info) {
				//ir pro ponteiro de n� i-1
				noRel = (noRel->esq);
				goto loop;
			}
			if (*(noRel->info) < *info) {
				noRel = (noRel->dir);
				goto loop;
			}

		}
		else {
			return 0;
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
	char passou = 0;
	while (noRel->esq != nullptr) {
		passou = 1;
		noAnt = noRel;
		noRel = noRel->esq;
	}
	if (noRel->dir == nullptr) {
		noAchado = new NoArvoreBinariaAVL(*noRel);
		noRel->info = nullptr;
		if(passou)
			noAnt->esq = noRel = nullptr;
		else
			noAnt->dir = noRel = nullptr;
		return noAchado->info;
	}
	else {
		noAchado = new NoArvoreBinariaAVL(*noRel);
		noAnt->dir = noRel->dir;
		noRel->info = nullptr;
		noRel = nullptr;
		return noAchado->info;
	}
}
InfoArvoreBinariaAVL* NoArvoreBinariaAVL::maiorDosMenores() throw(char*) {
	NoArvoreBinariaAVL* noAnt = (NoArvoreBinariaAVL*)this;
	NoArvoreBinariaAVL* noRel = (NoArvoreBinariaAVL*)this->esq;
	NoArvoreBinariaAVL* noAchado;
	char passou = 0;
	while (noRel->dir != nullptr) {
		passou = 1;
		noAnt = noRel;
		noRel = noRel->dir;
	}
	if (noRel->esq == nullptr) {
		noAchado = new NoArvoreBinariaAVL(*noRel);
		noRel->info = nullptr;
		if(passou)
			noAnt->dir = noRel = nullptr;
		else
			noAnt->esq = noRel = nullptr;
		return noAchado->info;
	}
	else {
		noAchado = new NoArvoreBinariaAVL(*noRel);
		noAnt->esq = noRel->esq;
		noRel->info = nullptr;
		noRel = nullptr;
		return noAchado->info;
	}
}
ostream& operator<< (ostream& os, const NoArvoreBinariaAVL& no) throw() {
	int indicePtr = 0;
	int indiceInfo = 0;


	if (no.getPtrInfo(0) != nullptr) {
		InfoArvoreBinariaAVL* info = (no.getPtrInfo(0));
		os << "  " << (*(info)) << "  ";
	}
	else {
		os << "  **  ";
	}


	os << '[';
	if (no.getPtrNoFilho(0) != nullptr) {
		os << '(' << *(no.getPtrNoFilho(0)) << ')';
	}
	else {
		os << "";
	}
	os << " , ";
	
	if (no.getPtrNoFilho(1) != nullptr) {
		os << '(' << *(no.getPtrNoFilho(1)) << ')';
	}
	else {
		os << "";
	}
	os << ']';
	/*
	if (no.getPtrInfo(0) != nullptr) {
		InfoArvoreBinariaAVL* info = (no.getPtrInfo(0));
		os << "  " << (*(info)) << "  ";
	}
	else {
		os << "  **  ";
	}
	os << '\n';
	os << "|       \ \n";
	os << "V        _/";
	os << '\n';
	if (no.getPtrNoFilho(0) != nullptr) {
		
		os << '(' << *(no.getPtrNoFilho(0)) << ')';
	}
	else {
		os << "(  ||  )";
	}
	os << "        ";
	if (no.getPtrNoFilho(1) != nullptr) {
		os << '(' << *(no.getPtrNoFilho(1)) << ')';
	}
	else {
		os << "(  ||  )";
	}*/
	return os;
}
char NoArvoreBinariaAVL::calcularEquilibrio() throw() {
	char niveisEsq(0), niveisDir(0);
	if (this->isFolha()) {
		this->equilibrio = 0;
	}
	if (this->esq == nullptr) {
		this->equilibrio = this->getNiveis();
	}
	if (this->dir == nullptr) {
		this->equilibrio = -(this->getNiveis());
	}
	if (this->esq != nullptr && this->dir != nullptr) {
		equilibrio = this->dir->getNiveis() - this->esq->getNiveis();
	}
	return this->equilibrio;
}
char NoArvoreBinariaAVL::getNiveis()const throw() {
	if (this->isFolha())
		return 0;
	if (this->esq == nullptr && this->dir != nullptr)
		return this->dir->getNiveis() + 1;
	if (this->dir == nullptr && this->esq != nullptr)
		return this->esq->getNiveis() + 1;
	char niveisEsq(0), niveisDir(0);
	if(this->esq != nullptr && this->esq != (NoArvoreBinariaAVL*)0xdddddddddddddddd)
		niveisEsq = this->esq->getNiveis();
	if(this->dir != nullptr && this->dir != (NoArvoreBinariaAVL*)0xdddddddddddddddd)
		niveisDir = this->dir->getNiveis();
	return niveisEsq > niveisDir ? niveisEsq + 1 : niveisDir + 1;
}
char NoArvoreBinariaAVL::getEquilibrio() const throw() {
	return this->equilibrio;
}
void NoArvoreBinariaAVL::balancear() throw() {
	this->calcularEquilibrio();
	if (this->equilibrio <= 1 && this->equilibrio >= -1) {
		if (this->esq != nullptr)
			this->esq->balancear();
		if (this->dir != nullptr)
			this->dir->balancear();
	}
	if (this->equilibrio > 1) {
		if (this->dir->getEquilibrio() < 0)
			rotacaoDuplaEsquerda();
		else
			rotacaoEsquerda();
		if (this->esq != nullptr)
			this->esq->balancear();
		if (this->dir != nullptr)
			this->dir->balancear();
	}
	if (this->equilibrio < -1) {
		if (this->esq->getEquilibrio() > 0)
			rotacaoDuplaDireita();
		else
			rotacaoDireita();
		if (this->esq != nullptr)
			this->esq->balancear();
		if (this->dir != nullptr)
			this->dir->balancear();

	}
	if (this->esq != nullptr)
		this->esq->balancear();
	if (this->dir != nullptr)
		this->dir->balancear();
	this->calcularEquilibrio();
}
void NoArvoreBinariaAVL::rotacaoEsquerda() throw() {
	NoArvoreBinariaAVL* novaRaiz = new NoArvoreBinariaAVL(*(this->dir));
	novaRaiz->setPtrNoFilho(new NoArvoreBinariaAVL(*this), 0);

	novaRaiz->esq->dir = this->dir->esq;
	this->dir->esq = nullptr;
	this->dir = novaRaiz->dir;
	this->esq = novaRaiz->esq;
	this->info = novaRaiz->info;
	//delete novaRaiz;
	this->calcularEquilibrio();

}
void NoArvoreBinariaAVL::rotacaoDireita() throw(){
	NoArvoreBinariaAVL* novaRaiz = new NoArvoreBinariaAVL(*(this->esq));
	novaRaiz->setPtrNoFilho(new NoArvoreBinariaAVL(*this), 1);
	novaRaiz->dir->esq = this->esq->dir;
	this->esq->dir = nullptr;
	this->dir = novaRaiz->dir;
	this->esq = novaRaiz->esq;
	this->info = novaRaiz->info;
	//delete novaRaiz;

	this->calcularEquilibrio();
}
void NoArvoreBinariaAVL::rotacaoDuplaEsquerda() throw(){
	this->dir->rotacaoDireita();
	this->rotacaoEsquerda();

}
void NoArvoreBinariaAVL::rotacaoDuplaDireita() throw(){
	this->esq->rotacaoEsquerda();
	this->rotacaoDireita();
}