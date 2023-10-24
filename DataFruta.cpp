#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Data {
	int dia, mes, ano;
	public:
	
	/*
	O m�todo abaixo retornar� -1 se d1 � anterior a d2
	Retornar� 0 se d1 = d2
	Retornar� +1 se d1 � posterior a d2
	*/	
	static int compara(Data d1, Data d2) { 
		return 0;
	}
	
	Data (int _dia, int _mes, int _ano) {
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}
	string toString() {
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};

class Lista {
	public:
	virtual void entradaDeDados() =0;
	virtual void mostraMediana() =0;
	virtual void mostraMenor() =0;
	virtual void mostraMaior() =0;
	virtual void listarEmOrdem() =0;
};

class ListaNomes : public Lista {
	vector<string> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override {
		cout << "Quantos nomes deseja inserir?" << endl;
		int num;
		cin >> num;
		for (int i = 0; i < num; i++) {
			string nome;
			cout << "Digite o " << i+1 << " nome: " << endl; cin >> nome;
			lista.push_back(nome);
		}
	}
		
	void mostraMediana() override {
		if(lista.empty()) {
			cout << "A lista esta vazia. Nao ha mediana a ser mostrada." << endl;
			return;
		}		
		string nomeMediana;
		int media=0;
		int tamanho = lista.size();
		if (tamanho % 2 == 0) {
			media = tamanho / 2 - 1;
			cout << "A mediana e " <<  media;
			cout << " com o nome  " << lista[media] << endl;
		}
		else {
			media = tamanho / 2;
			cout << "A mediana e " <<  media ;
			cout << " com o nome  " << lista[media] << endl;			
		}
	}
	
	void mostraMenor() override {
		if (lista.empty()) {
			cout << "A lista esta vazia. Nao ha nome a ser mostrado." << endl;
			return;
		}
		string menorNome = lista[0];
		for (const string& nome : lista) {
			if (nome < menorNome) {
				menorNome = nome;
			}
		}
		cout << "O Menor nome alfabeticamente e: " << menorNome << endl;

	
	}
	void mostraMaior() override {
		if (lista.empty()) {
        cout << "A lista esta vazia. Nao ha nome a ser mostrado." << endl;
        return;
		}
		string maiorNome = lista[0];
		for (const string& nome : lista) {
			if (nome > maiorNome) {
				maiorNome = nome;
			}
		}
		cout << "O Maior nome alfabeticamente e: " << maiorNome << endl;
	}

	void listarEmOrdem() override {
		sort(lista.begin(), lista.end());
		for (const string& nome : lista) {
			cout << nome << endl;
		}
	}
};

class ListaDatas  {
	vector<Data> lista;
	
	public:
		
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		
	}
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de datas" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a ultima data cronologicamente" << endl;
	}
};

class ListaSalarios  {
	vector<float> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		
	}
			
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de salarios" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar o menor dos salarios" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar o maior dos salarios" << endl;
	}
};


class ListaIdades  {
	vector<int> lista;
	
	public:
		
		/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		
	}
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a menor das idades" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a maior das idades" << endl;
	}
};
 
int main () {
	vector<Lista*> listaDeListas;
	
	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);

	

	
	
	// ListaDatas listaDatas;
	// listaDatas.entradaDeDados();
	// listaDeListas.push_back(&listaDatas);
	
	// ListaSalarios listaSalarios;
	// listaSalarios.entradaDeDados();
	// listaDeListas.push_back(&listaSalarios);
	
	// ListaIdades listaIdades;
	// listaIdades.entradaDeDados();
	// listaDeListas.push_back(&listaIdades);
	
	for (Lista* l : listaDeListas) {
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
	
}
    

