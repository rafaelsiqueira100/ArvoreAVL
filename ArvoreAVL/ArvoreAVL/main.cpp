// ArvoreAVL.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "ArvoreBinariaAVL.h"
#include "MinhaInfo.h"
int main()
{
	char x;
	ArvoreBinariaAVL arvore;
	
	const int tamanhoVetor = 15;
	const int vetor[tamanhoVetor] = { 12,39,16,93,65,25,24,14,72,
		31,21,27,83,44,97};
	MinhaInfo* minhaInfo;
	for (int i = 0; i < tamanhoVetor; i++) {
		//MinhaInfo info ();
		minhaInfo = new MinhaInfo(vetor[i]);
		cout << '\n';
		arvore.inserir(minhaInfo);
		cout << arvore;

		cout << '\n';
		//delete minhaInfo;
	}
	//delete minhaInfo;
	const int vetHa[tamanhoVetor] = { 22,	17,	9,	7,	25,	24,	20,	12,	21,	26,	61,49,97	,47	,	16 };
	MinhaInfo* infoSelecionar;
	for (int k = 0; k < tamanhoVetor; k++) {
		infoSelecionar = new MinhaInfo(vetHa[k]);
		cout << '\n';
		cout << "Existe o valor ";
		cout << *infoSelecionar;
		cout << " na arvore?R=";
		if (arvore.haInfo(*infoSelecionar)) {
			cout << 'S';
		}
		else {
			cout << 'N';
		}
		
		cout << '\n';
		//delete infoSelecionar;
	}
	cout << arvore;
	const int vetInd[tamanhoVetor] = {4,1,8,6,14,7,9,2,12,11,5,13,0,10,3};
	MinhaInfo* infoRemover;
	for (int j = 0; j < tamanhoVetor; j++) {
		infoRemover = new MinhaInfo(vetor[vetInd[j]]);
		cout << '\n';
		arvore.remover(infoRemover);
		cout << arvore;

		cout << '\n';
	}
	cout << arvore;
	MinhaInfo* infoInserir;
	for (int i = 0; i < tamanhoVetor; i++) {
		//MinhaInfo info(vetor[i]);
		infoInserir = new MinhaInfo(vetor[i]);

		cout << '\n';
		arvore.inserir(infoInserir);
		cout << arvore;

		cout << '\n';
		//delete minhaInfo;
	}
	delete minhaInfo;
	delete infoRemover;
	delete infoSelecionar;
	delete infoInserir;
	cin >> x;
	return 0;
}

