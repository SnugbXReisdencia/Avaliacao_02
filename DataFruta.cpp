#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <algorithm>

using namespace std;

template <typename T>
void quicksort(vector<T>& arr, int left, int right) {

    if (left < right) {
        int pivot = left;
        for (int i = left + 1; i <= right; ++i) {
            if (arr[i] < arr[left]) {
                ++pivot;
                std::swap(arr[pivot], arr[i]);
            }
        }
        std::swap(arr[left], arr[pivot]);
        quicksort(arr, left, pivot - 1);
        quicksort(arr, pivot + 1, right);
    }
}

// class Data {
// 	int dia, mes, ano;
// 	public:
	
// 	/*
// 	O m�todo abaixo retornar� -1 se d1 � anterior a d2
// 	Retornar� 0 se d1 = d2
// 	Retornar� +1 se d1 � posterior a d2
// 	*/	
// 	static int compara(Data d1, Data d2) { 
// 		return 0;
// 	}
	
// 	Data (int _dia, int _mes, int _ano) {
// 		dia = _dia;
// 		mes = _mes;
// 		ano = _ano;
// 	}
// 	string toString() {
// 		string ret = "";
// 		ret.append(to_string(dia));
// 		ret.append("/");
// 		ret.append(to_string(mes));
// 		ret.append("/");
// 		ret.append(to_string(ano));
// 		return ret;
// 	}
// };
class Lista {
	public:
	virtual void entradaDeDados() =0;
	virtual void mostraMediana() =0;
	virtual void mostraMenor() =0;
	virtual void mostraMaior() =0;
	virtual void listarEmOrdem() =0;
	virtual void listar_N_elementos(int) =0;
	virtual int size() =0;
};

class ListaNomes : public Lista {
	vector<string> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		lista.push_back("Teste3");
		lista.push_back("Teste1");
		lista.push_back("Teste2");
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

	void listarEmOrdem() {
		quicksort<string>(lista, 0, lista.size() - 1);
		listar_N_elementos(lista.size());
	}

	void listar_N_elementos(int n) {
		int tam = lista.size();
		for (int i = 0; i < tam; i++) {
			if (i < n) {
				cout << "Nome " << i + 1 << "ª: " << lista[i] << endl;
			}
		}
	}

	int size() {
		return lista.size();
	}
};

// class ListaDatas  {
// 	vector<Data> lista;
	
// 	public:
		
// 	/*
// 	O m�todo abaixo pergunta ao usu�rios quantos
// 	elementos v�o existir na lista e depois
// 	solicita a digita��o de cada um deles
// 	*/	
// 	void entradaDeDados() {
		
// 	}
	
// 	void mostraMediana() {
// 		cout << "Aqui vai mostrar a mediana da lista de datas" << endl;
// 	}
	
// 	void mostraMenor() {
// 		cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
// 	}
// 	void mostraMaior() {
// 		cout << "aqui vai mostrar a ultima data cronologicamente" << endl;
// 	}
// };
class ListaSalarios : public Lista {
	vector<float> lista;
	
	public:
	
	int size() override {
		return lista.size();
	}

	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override {
		float valor;
		int n;
		cout << "informe a quantidade de salarios que deseja inserir: " << endl;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "informe o valor do salario: " << endl;
			cin >> valor;
			lista.push_back(valor);
		}
	}
			
	void mostraMediana() override {
		float mediana;
		if (lista.size() % 2 == 0) {
			mediana = (lista[(lista.size() - 1) / 2] + lista[(lista.size() - 1) / 2 + 1]) / 2;
		}
		else{
			mediana = lista[(lista.size() - 1) / 2];
		}
		cout << "\tMediana: " << mediana << endl;
	}
	
	void mostraMenor() override {
		float menor = lista[0];
		int tam = lista.size();
		for (int i = 1; i < tam; i++) {
			if (lista[i] < menor) {
				menor = lista[i];
			}			
		}
		cout << "\tMenor salario: " << menor << endl;
	}
	void mostraMaior() override {
		float maior = lista[0];
		int tam = lista.size();
		for (int i = 1; i < tam; i++) {
			if (lista[i] > maior) {
				maior = lista[i];
			}			
		}
		cout << "\tMaior salario: " << maior << endl;
	}

	void listarEmOrdem() override {
		int tam = lista.size();
		quicksort<float>(lista, 0, lista.size() - 1);
		listar_N_elementos(tam);
	}

	void listar_N_elementos(int n) override {
		int tam = lista.size();
		for (int i = 0; i < tam; i++) {
			if (i < n) {
				cout << "\tSalario " << i + 1 << "ª: " << lista[i] << endl;
			}
		}
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
 
 void limpaTela()
{
    cin.clear();

    // Verifica se a variável de ambiente WINDIR está definida (ambiente Windows)
    const char *windir = getenv("WINDIR");

    if (windir != nullptr && strlen(windir) > 0)
    {
        // Se estiver definida, estamos no Windows, então use "cls"
        system("cls");
    }
    else
    {
        // Caso contrário, estamos em um ambiente Unix/Linux, use "clear"
        system("clear");
    }
}

void pause()
{
    cin.ignore();
    cout << "\nPressione a tecla Enter para continuar...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main () {
	limpaTela();
	vector<Lista*>listaDeListas;
	
	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);
	
	// ListaDatas listaDatas;
	// listaDatas.entradaDeDados();
	// listaDeListas.push_back(&listaDatas);
	
	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);

	// ListaIdades listaIdades;
	// listaIdades.entradaDeDados();
	// listaDeListas.push_back(&listaIdades);
	limpaTela();
	cout << "################## Lista de salarios ################## " << endl;
	for(Lista* l : listaDeListas) {
		if(typeid(*l) == typeid(ListaSalarios)) {
			cout << "Tamanho: " << l->size() << endl;
			cout << "Itens: " << endl;
			l->listar_N_elementos(l->size());
			cout << "------------------------------------" << endl;
			cout << "'N' Primeiros da Lista (teste N = 3):" << endl;
			l->listar_N_elementos(3);
			cout << "------------------------------------" << endl;
			cout << "Itens ordenados :" << endl;
			l->listarEmOrdem();
			cout << "------------------------------------" << endl;
			cout << "Dados da lista de salarios: " << endl;
			l->mostraMediana();
			l->mostraMenor();
			l->mostraMaior();
		}
	}
	cout << "+========================================================+" << endl;
}
    

