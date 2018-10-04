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
	for (int i = 0; i < tamanhoVetor; i++) {
		MinhaInfo info(vetor[i]);
		MinhaInfo* minhaInfo = new MinhaInfo(info);
		
		cout << '\n';
		arvore.inserir((InfoArvoreBinariaAVL*)minhaInfo);
		cout << arvore;

		cout << '\n';
	}
	const int vetHa[tamanhoVetor] = { 22,	17,	9,	7,	25,	24,	20,	12,	21,	26,	25,	22,	22,	12,	16 };
	for (int k = 0; k < tamanhoVetor; k++) {
		MinhaInfo* infoSelecionar = new MinhaInfo(vetHa[k]);
		cout << '\n';
		cout << "Existe o valor ";
		cout << *infoSelecionar;
		cout << " na arvore?R=";
		if (arvore.haInfo(infoSelecionar)) {
			cout << 'S';
		}
		else {
			cout << 'N';
		}
		
		cout << '\n';
	}
	const int vetInd[tamanhoVetor] = {4,1,8,6,14,7,9,2,12,11,5,13,0,10,3};
	for (int j = 0; j < tamanhoVetor; j++) {
		MinhaInfo* minhaInfo = new MinhaInfo(vetor[vetInd[j]]);
		cout << '\n';
		arvore.remover((InfoArvoreBinariaAVL*)minhaInfo);
		cout << arvore;

		cout << '\n';
	}
	for (int i = 0; i < tamanhoVetor; i++) {
		MinhaInfo info(vetor[i]);
		MinhaInfo* minhaInfo = new MinhaInfo(info);

		cout << '\n';
		arvore.inserir((InfoArvoreBinariaAVL*)minhaInfo);
		cout << arvore;

		cout << '\n';
	}
	cin >> x;
	return 0;
}

