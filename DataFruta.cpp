#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Data {
	private:
		int dia, mes, ano;
	public:
	
	/*
	O m�todo abaixo retornar� -1 se d1 � anterior a d2
	Retornar� 0 se d1 = d2
	Retornar� +1 se d1 � posterior a d2
	*/	
	static int compara(Data d1, Data d2);
 
	static void retorno_comparacao(Data d1, Data d2);
	
	Data (){dia=0; mes=0; ano=0;}
	Data (int _dia, int _mes, int _ano) {dia = _dia;mes = _mes;ano = _ano;}
	
	int getDia(){return dia;}
    void setDia(int _dia){dia = _dia;}

	int getMes(){return mes;}
    void setMes(int _mes){mes = _mes;}

    int getAno(){return ano;}
    void setAno(int _ano){ano = _ano;}

	bool valida_data();	

	string toString() {
		string ret = "";
		string str_dia = to_string(dia);
		string str_mes = to_string(mes);
		ret.append(str_dia.size() == 1 ? "0"+str_dia : str_dia);
		ret.append("/");
		ret.append(str_mes.size() == 1 ? "0"+str_mes : str_mes);
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
	virtual void  listarEmOrdem() =0;
	virtual void listar_N_elementos(int) = 0;
	virtual ~Lista() {}
};

class ListaDatas: public Lista {
	private:
		vector<Data> lista;
	
	public:
		
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override;

    vector<Data> getLista() const {
        return lista;
    }

    void setLista(const vector<Data>& newLista) {
        lista = newLista;
    }
	
	void ordenacao();
	void mostraMediana() override;
	void mostraMenor() override;
	void mostraMaior() override;
	void listarEmOrdem() override;
	void listar_N_elementos(int n) override;
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

	
	// ListaNomes listaNomes;
	// listaNomes.entradaDeDados();
	// listaDeListas.push_back(&listaNomes);
	
	Data data(12,11,1999);
	Data data2(10,12,1990);
	// Data::retorno_comparacao(data, data2);

	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);

	listaDatas.mostraMenor();
	listaDatas.mostraMaior();
	listaDatas.mostraMediana();
	listaDatas.listarEmOrdem();
	listaDatas.listar_N_elementos(2);


	
	// ListaSalarios listaSalarios;
	// listaSalarios.entradaDeDados();
	// listaDeListas.push_back(&listaSalarios);
	
	// ListaIdades listaIdades;
	// listaIdades.entradaDeDados();
	// listaDeListas.push_back(&listaIdades);
	
	
	// for (Lista* l : listaDeListas) {
	// 	l->mostraMediana();
	// 	l->mostraMenor();
	// 	l->mostraMaior();
	// }
	
}
void ListaDatas::entradaDeDados(){
	Data data;
	int dia, mes, ano;
	int numElementos;

	do{
		cout << "Quantos elementos na lista? ";
		cin >> numElementos;

	}while(numElementos <= 0);

	for(int i = 0; i <numElementos; i++){
		cout << "Data " << i+1 <<" :"<< endl;

		cout << "digite o dia (00)" << endl;
		cin >> dia;

		cout << "digite o mes (00)" << endl;
		cin >> mes;

		cout << "digite o ano (0000)" << endl;
		cin >> ano;
	
		data.setDia(dia);
		data.setMes(mes);
		data.setAno(ano);

		if(!data.valida_data()){
			cout << "Data invalida, digite novamento." << endl;
			i--;
		}else{
			lista.push_back(data);
		}
	}
};

bool Data::valida_data(){
	if((getDia() >= 1 && getDia() <= 30 ) && (getMes() == 4||getMes() == 6 || getMes() ==9 || getMes() ==7 || getMes() ==11)){

	}
	else if((getDia() >= 1 && getDia() <= 31 ) && (getMes() == 1||getMes() == 3 || getMes() ==5 || getMes() ==7 || getMes() ==8 || getMes() ==10 || getMes() ==12)){

	}
	else if((getDia() >= 1 && getDia() <= 28 ) && (getMes() == 2)){

	}
	else if(getDia() >= 29 && getMes() == 2 && (getAno() % 400 == 0 || getAno() % 4 == 0 && getAno() % 100 !=0)){

	}else{
		return false;
	}
		
	return true;

}

int Data::compara(Data d1, Data d2) {
	if (d1.ano < d2.ano){
		return -1;
	}else if (d1.ano > d2.ano){
		return 1;
	}else {
		if (d1.mes < d2.mes){
			return -1;
		}else if (d1.mes > d2.mes){
			return 1;
		}else {
			if (d1.dia < d2.dia)
				return -1;
			else if (d1.dia > d2.dia)
				return 1;
			else
				return 0; 
		}
	}
}

void Data::retorno_comparacao(Data d1, Data d2){
	int resultado = Data::compara(d1,d2);

    if (resultado == -1)
        cout << "A primeira data e menor que a segunda data." << endl;
    else if (resultado == 1)
        cout << "A primeira data e maior que a segunda data." << endl;
    else
        cout << "As datas sao iguais." << endl;
}

void ListaDatas::ordenacao(){
	int n = lista.size();
    Data aux;

    for (int i = 0; i < n - 1; i++) {
        int indiceMenor = i;
        for (int j = i + 1; j < n; j++) {
            // Comparação de datas
            if (lista[j].getAno() < lista[indiceMenor].getAno() ||
                (lista[j].getAno() == lista[indiceMenor].getAno() &&
                 (lista[j].getMes() < lista[indiceMenor].getMes() ||
                  (lista[j].getMes() == lista[indiceMenor].getMes() &&
                   lista[j].getDia() < lista[indiceMenor].getDia())))) {
                indiceMenor = j;
            }
        }

        if (indiceMenor != i) {
            aux = lista[i];
            lista[i] = lista[indiceMenor];
            lista[indiceMenor] = aux;
        }
    }	
}

void ListaDatas::mostraMediana(){
	int tam = lista.size();
	this->ordenacao();
	
	if(tam %2 ==0){
		cout <<"Data Mediana: "<< lista[(tam/2)-1].toString() << endl;
	}else{
		cout <<"Data Mediana: "<< lista[(tam/2)].toString() << endl;
	}
	
}

void ListaDatas::mostraMenor() {
	Data menorData = lista[0];
	for(Data data : lista){
		if(data.getAno() < menorData.getAno() || (data.getAno() == menorData.getAno() && 
			(data.getMes() < menorData.getMes() || data.getMes() == menorData.getMes() && data.getDia() < menorData.getDia()))){
			menorData = data;
		}
	}
	cout <<"Data Menor: "<< menorData.toString() << endl;
}
void ListaDatas::mostraMaior() {
	Data maiorData = lista[0];
	for(Data data : lista){
		if(data.getAno() > maiorData.getAno() || (data.getAno() == maiorData.getAno() && 
			(data.getMes() > maiorData.getMes() || data.getMes() == maiorData.getMes() && data.getDia() > maiorData.getDia()))){
			maiorData = data;
		}
	}
	cout <<"Data Maior: "<< maiorData.toString() << endl;

}

void ListaDatas::listarEmOrdem(){
	int tam = lista.size();
	this->ordenacao();
	cout<<" Lista Datas Ordenada:" << endl;
	for(int i = 0; i < tam; i++){
		cout << lista[i].toString() << endl;
	}
	cout << endl;

}

void ListaDatas::listar_N_elementos(int n) {
	cout<<" Lista de Datas" << endl;
	if (n < 0 || n > lista.size()) {
        cout << "Numero invalido de elementos a serem listados." << endl;
        return;
    }
	for (int i = 0; i < n; i++) {
		cout << lista[i].toString() << endl;
	}
}