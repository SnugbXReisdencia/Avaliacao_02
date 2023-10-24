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
	virtual void listarEmOrdem() = 0;
	virtual void listar_N_elementos(int) =0;
	virtual int size() =0;
};

class ListaNomes {
	vector<string> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		lista.push_back("Teste");
	}
		
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de strings" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar o primeiro nome alfabeticamente" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar o ultimo nome alfabeticamente" << endl;
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


class ListaIdades : public Lista {
	vector<int> lista;
	
	public:
		
		/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override;
	void mostraMediana() override;
	void mostraMenor() override;
	void mostraMaior() override;
	virtual void listarEmOrdem() override;
	void listar_N_elementos(int) override;
	int size() override;
};

void ListaIdades::entradaDeDados(){
	lista.clear();
	int quantidade;
	cout<<"Quantos elementos vao existir na lista de idades: ";
	cin>>quantidade;
	for(int i = 1; i <= quantidade; i++){
		cout<<"Valor "<<i<<": ";
		int valor;
		cin>>valor;
		lista.push_back(valor);
	}
}

void ListaIdades::mostraMediana(){
	vector<int> listaOrdenada = lista;
	sort(listaOrdenada.begin(), listaOrdenada.end());
	int mediana;
	if(size() % 2 == 0) mediana = (listaOrdenada[size() / 2 - 1] + listaOrdenada[size() / 2]) / 2;
	else mediana = listaOrdenada[size() / 2];
	cout <<"Mediana de idades = " << mediana << endl;
}

void ListaIdades::mostraMenor(){
	int menor = lista[0];
	for(int i = 1; i < size(); i++) 
		if(lista[i] < menor) menor = lista[i];

	cout<<"Menor valor de idade = "<<menor<<endl;
}

void ListaIdades::mostraMaior(){
	int maior = lista[0];
	for(int i = 1; i < size(); i++) 
		if(lista[i] > maior) maior = lista[i];

	cout<<"Maior valor de idade = "<<maior<<endl;
}

void ListaIdades::listarEmOrdem(){
	vector<int> listaOrdenada = lista;
	sort(listaOrdenada.begin(), listaOrdenada.end());
	cout<<"Lista de idades ordenada:"<<endl;
	for(int idade : listaOrdenada) cout<<idade<<endl;
}

void ListaIdades::listar_N_elementos(int n){
	if(n > size()) n = size();
	cout<<"Listando os "<<n<<" primeiros elementos da lista de idades:"<<endl;
	for(int i = 0; i < n; i++) cout<<lista[i]<<endl;
}

int ListaIdades::size(){
	return lista.size();
}
 
int main () {
	vector<Lista*> listaDeListas;
	
	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);
	
	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	
	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);
	
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);
	
	for (Lista* l : listaDeListas) {
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
		l->listarEmOrdem();
		l->listar_N_elementos(5);
	}
	
}
    

