#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <limits>
#include <algorithm>

using namespace std;

template <typename T>
void quicksort(vector<T> &arr, int left, int right)
{

	if (left < right)
	{
		int pivot = left;
		for (int i = left + 1; i <= right; ++i)
		{
			if (arr[i] < arr[left])
			{
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
class Lista
{
public:
	virtual void entradaDeDados() = 0;
	virtual void mostraMediana() = 0;
	virtual void mostraMenor() = 0;
	virtual void mostraMaior() = 0;
	virtual void listarEmOrdem() = 0;
	virtual void listar_N_elementos(int) = 0;
	virtual int size() = 0;
};

class ListaNomes : public Lista
{
	vector<string> lista;

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
	void listarEmOrdem() override;
	void listar_N_elementos(int n) override;

	

	int size()
	{
		return lista.size();
	}
};

class ListaDatas : public Lista
{
	// vector<Data> lista;

public:
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/
	void entradaDeDados()
	{
	}

	void mostraMediana()
	{
		cout << "Aqui vai mostrar a mediana da lista de datas" << endl;
	}

	void mostraMenor()
	{
		cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
	}
	void mostraMaior()
	{
		cout << "aqui vai mostrar a ultima data cronologicamente" << endl;
	}

	void listarEmOrdem() override{}

	void listar_N_elementos(int n) override{}

	int size() override{}
};
class ListaSalarios : public Lista
{
	vector<float> lista;

public:
	int size() override;

	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/
	void entradaDeDados() override;

	void mostraMediana() override;

	void mostraMenor() override;

	void mostraMaior() override;

	void listarEmOrdem() override;

	void listar_N_elementos(int n) override;
};

class ListaIdades : public Lista
{
	vector<int> lista;

public:
	/*
O m�todo abaixo pergunta ao usu�rios quantos
elementos v�o existir na lista e depois
solicita a digita��o de cada um deles
*/
	void entradaDeDados()
	{
	}

	void mostraMediana()
	{
		cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
	}

	void mostraMenor()
	{
		cout << "Aqui vai mostrar a menor das idades" << endl;
	}
	void mostraMaior()
	{
		cout << "aqui vai mostrar a maior das idades" << endl;
	}

	void listarEmOrdem() override{}

	void listar_N_elementos(int n) override{}

	int size() override{}
};

int menuPrincipal();
int menuTipoLista(string);
int menuVisualizarLista(string str);

//// FUNCAO de Utilidade ////
void limpaTela();
void pause();

int main()
{
	vector<Lista *> listaDeListas;
	ListaDatas aux_ListaDatas;
	ListaNomes aux_ListaNomes;
	ListaSalarios aux_ListaSalario;
	ListaIdades aux_ListaIdades;

	int opcao, opc, opc2, aux_Int, aux_Int2;

	do
	{
		opcao = menuPrincipal();
		switch (opcao)
		{
		case 1:
			do
			{
				opc = menuTipoLista("####### Registro de Lista #######");
				switch (opc)
				{
				case 1:
					limpaTela();
					aux_ListaDatas.entradaDeDados();
					listaDeListas.push_back(&aux_ListaDatas);
					cout << "Registro adicionado com sucesso!" << endl;
					pause();
					break;
				case 2:
					limpaTela();
					aux_ListaNomes.entradaDeDados();
					listaDeListas.push_back(&aux_ListaNomes);
					cout << "Registro adicionado com sucesso!" << endl;
					pause();
					break;
				case 3:
					limpaTela();
					aux_ListaSalario.entradaDeDados();
					listaDeListas.push_back(&aux_ListaSalario);
					cout << "Registro adicionado com sucesso!" << endl;
					pause();
					break;
				case 4:
					limpaTela();
					aux_ListaIdades.entradaDeDados();
					listaDeListas.push_back(&aux_ListaIdades);
					cout << "Registro adicionado com sucesso!" << endl;
					pause();
					break;
				case 0:
					break;
				default:
					limpaTela();
					cout << "Opção invalida!" << endl;
					cout << "Escolha uma opção valida !!" << endl;
					pause();
				}
			} while (opc != 0);
			break;
		case 2:
			do
			{
				opc = menuTipoLista(" Visualizar Qual Tipo de Lista ?");
				switch (opc)
				{
				case 1:
					do
					{
						opc2 = menuVisualizarLista("Visualizar Lista de Datas");
						switch (opc2)
						{
						case 1:
							limpaTela();
							cout << "################## Lista de Datas ################## " << endl;
							for (Lista *l : listaDeListas)
							{
								if (typeid(*l) == typeid(ListaDatas))
								{
									cout << "Tamanho da Lista: " << l->size() << endl;
									cout << "Itens ordenados :" << endl;
									l->listarEmOrdem();
									cout << "------------------------------------" << endl;
									cout << "Dados da lista de Datas: " << endl;
									l->mostraMediana();
									l->mostraMenor();
									l->mostraMaior();

									cout << "+========================================================+" << endl;
								}
							}
							pause();
							break;
						case 2:
							limpaTela();
							cout << "################## Lista de Datas ################## " << endl;
							cout << "Informe quantos elementos deseja visualizar: ";
							cin >> aux_Int;
							cout << "Obs: Case a lista não possuir a quantidade de elementos informado, Listara todos os elementos dela." << endl;
							aux_Int2 = 0;
							for (Lista *l : listaDeListas)
							{
								if (typeid(*l) == typeid(ListaDatas))
								{
									if (aux_Int2 < aux_Int)
									{
										cout << "Tamanho da Lista: " << l->size() << endl;
										aux_Int == 1 ? cout << "O primeiro elemento da lista " << aux_Int2 + 1 << "ª: " << endl : cout << "Os primeiros " << aux_Int << " elementos da lista " << aux_Int2 + 1 << "ª:" << endl;
										l->listar_N_elementos(aux_Int);
										cout << "------------------------------------" << endl;
										cout << "Dados da lista de Datas: " << endl;
										l->mostraMediana();
										l->mostraMenor();
										l->mostraMaior();

										cout << "+========================================================+" << endl;
									}
									aux_Int2++;
								}
							}
							pause();
							break;
						case 0:
							break;
						default:
							limpaTela();
							cout << "Opção invalida!" << endl;
							cout << "Escolha uma opção valida !!" << endl;
							pause();
						}
					} while (opc2 != 0);
					break;
				case 2:
					do
					{
						opc2 = menuVisualizarLista("Visualizar Lista de Nomes");
						switch (opc2)
						{
						case 1:
							limpaTela();
							cout << "################## Lista de Nomes ################## " << endl;
							for (Lista *l : listaDeListas)
							{
								if (typeid(*l) == typeid(ListaNomes))
								{
									cout << "Tamanho da Lista: " << l->size() << endl;
									cout << "Itens ordenados :" << endl;
									l->listarEmOrdem();
									cout << "------------------------------------" << endl;
									cout << "Dados da lista de Nomes: " << endl;
									l->mostraMediana();
									l->mostraMenor();
									l->mostraMaior();
								}
							}
							cout << "+========================================================+" << endl;
							pause();
							break;
						case 2:
							limpaTela();
							cout << "################## Lista de Nomes ################## " << endl;
							cout << "Informe quantos elementos deseja visualizar: ";
							cin >> aux_Int;
							cout << "Obs: Case a lista não possuir a quantidade de elementos informado, Listara todos os elementos dela." << endl;
							aux_Int2 = 0;
							for (Lista *l : listaDeListas)
							{
								if (typeid(*l) == typeid(ListaNomes))
								{
									if (aux_Int2 < aux_Int)
									{
										cout << "Tamanho da Lista: " << l->size() << endl;
										aux_Int == 1 ? cout << "O primeiro elemento da lista " << aux_Int2 + 1 << "ª: " << endl : cout << "Os primeiros " << aux_Int << " elementos da lista " << aux_Int2 + 1 << "ª:" << endl;
										l->listar_N_elementos(aux_Int);
										cout << "------------------------------------" << endl;
										cout << "dados da lista de Nomes: " << endl;
										l->mostraMediana();
										l->mostraMenor();
										l->mostraMaior();

										cout << "+========================================================+" << endl;
									}
									aux_Int2++;
								}
							}
							pause();
							break;
						case 0:
							break;
						default:
							limpaTela();
							cout << "Opção invalida!" << endl;
							cout << "Escolha uma opção valida !!" << endl;
							pause();
						}
					} while (opc2 != 0);
					break;
				case 3:
					do
					{
						opc2 = menuVisualizarLista("Visualizar Lista de Salários");
						switch (opc2)
						{
						case 1:
							limpaTela();
							cout << "################## Lista de Salários ################## " << endl;
							for (Lista *l : listaDeListas)
							{
								if (typeid(*l) == typeid(ListaSalarios))
								{
									cout << "Tamanho da Lista: " << l->size() << endl;
									cout << "Itens ordenados :" << endl;
									l->listarEmOrdem();
									cout << "------------------------------------" << endl;
									cout << "dados da lista de Salários: " << endl;
									l->mostraMediana();
									l->mostraMenor();
									l->mostraMaior();

									cout << "+========================================================+" << endl;
								}
							}
							pause();
							break;
						case 2:
							limpaTela();
							cout << "################## Lista de Salários ################## " << endl;
							cout << "Informe quantos elementos deseja visualizar: ";
							cin >> aux_Int;
							cout << "Obs: Case a lista não possuir a quantidade de elementos informado, Listara todos os elementos dela." << endl;
							aux_Int2 = 0;
							for (Lista *l : listaDeListas)
							{
								if (typeid(*l) == typeid(ListaSalarios))
								{
									if (aux_Int2 < aux_Int)
									{
										cout << "Tamanho da Lista: " << l->size() << endl;
										aux_Int == 1 ? cout << "O primeiro elemento da lista " << aux_Int2 + 1 << "ª: " << endl : cout << "Os primeiros " << aux_Int << " elementos da lista " << aux_Int2 + 1 << "ª:" << endl;
										l->listar_N_elementos(aux_Int);
										cout << "------------------------------------" << endl;
										cout << "dados da lista de Salários: " << endl;
										l->mostraMediana();
										l->mostraMenor();
										l->mostraMaior();

										cout << "+========================================================+" << endl;
									}
									aux_Int2++;
								}
							}
							pause();
							break;
						case 0:
							break;
						default:
							limpaTela();
							cout << "Opção invalida!" << endl;
							cout << "Escolha uma opção valida !!" << endl;
							pause();
						}
					} while (opc2 != 0);
					break;
				case 4:
					do
					{
						opc2 = menuVisualizarLista("Visualizar Lista de Idades");
						switch (opc2)
						{
						case 1:
							limpaTela();
							cout << "################## Lista de Idades ################## " << endl;
							for (Lista *l : listaDeListas)
							{
								if (typeid(*l) == typeid(ListaIdades))
								{
									cout << "Tamanho da Lista: " << l->size() << endl;
									cout << "Itens ordenados :" << endl;
									l->listarEmOrdem();
									cout << "------------------------------------" << endl;
									cout << "dados da lista de Idades: " << endl;
									l->mostraMediana();
									l->mostraMenor();
									l->mostraMaior();

									cout << "+========================================================+" << endl;
								}
							}
							pause();
							break;
						case 2:
							limpaTela();
							cout << "################## Lista de Idades ################## " << endl;
							cout << "Informe quantos elementos deseja visualizar: ";
							cin >> aux_Int;
							cout << "Obs: Case a lista não possuir a quantidade de elementos informado, Listara todos os elementos dela." << endl;
							aux_Int2 = 0;
							for (Lista *l : listaDeListas)
							{
								if (typeid(*l) == typeid(ListaIdades))
								{
									if (aux_Int2 < aux_Int)
									{
										cout << "Tamanho da Lista: " << l->size() << endl;
										aux_Int == 1 ? cout << "O primeiro elemento da lista " << aux_Int2 + 1 << "ª: " << endl : cout << "Os primeiros " << aux_Int << " elementos da lista " << aux_Int2 + 1 << "ª:" << endl;
										l->listar_N_elementos(aux_Int);
										cout << "------------------------------------" << endl;
										cout << "dados da lista de Idades: " << endl;
										l->mostraMediana();
										l->mostraMenor();
										l->mostraMaior();

										cout << "+========================================================+" << endl;
									}
									aux_Int2++;
								}
							}
							pause();
							break;
						case 0:
							break;
						default:
							limpaTela();
							cout << "Opção invalida!" << endl;
							cout << "Escolha uma opção valida !!" << endl;
							pause();
						}
					} while (opc2 != 0);
					break;
				case 0:
					break;
				default:
					limpaTela();
					cout << "Opção invalida!" << endl;
					cout << "Escolha uma opção valida !!" << endl;
					pause();
				}
			} while (opc != 0);
			break;
		case 0:
			break;
		default:
			limpaTela();
			cout << "Opção invalida!" << endl;
			cout << "Escolha uma opção valida !!" << endl;
			pause();
		}
	} while (opcao != 0);
	return 0;
}

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

int menuPrincipal()
{
	int opcao, n = 0;
	limpaTela();
	do
	{
		if (n != 0)
		{
			limpaTela();
			cout << "Opçao invalida!" << endl;
			cout << "Escolha uma opcao valida !!" << endl;
		}
		cout << "\n########################################" << endl;
		cout << "######## BEM VINDO A DATA FRUTA ########" << endl;
		cout << "########################################\n"
			 << endl;

		cout << "1 - Registrar Lista" << endl;
		cout << "2 - Visualizar Lista" << endl;
		cout << "0 - Sair" << endl;

		cout << "Escolha uma opção: ";
		cin >> opcao;
		n++;

	} while (opcao < 0 || opcao > 2);
	return opcao;
}

int menuTipoLista(string str)
{
	int opcao, n = 0;
	limpaTela();
	do
	{
		cout << str << endl;
		if (n != 0)
		{
			limpaTela();
			cout << "Opçao invalida!" << endl;
			cout << "Escolha uma opcao valida !!" << endl;
		}
		cout << "1 - Lista de Datas" << endl;
		cout << "2 - Lista de Nomes" << endl;
		cout << "3 - Lista de Salários" << endl;
		cout << "4 - Lista de Idades" << endl;
		cout << "0 - Voltar" << endl;

		cout << "Escolha uma opção: ";
		cin >> opcao;
		n++;

	} while (opcao < 0 || opcao > 4);
	return opcao;
}

int menuVisualizarLista(string str)
{
	int opcao, n = 0;
	limpaTela();
	cout << str << endl;
	do
	{
		if (n != 0)
		{
			limpaTela();
			cout << "Opçao invalida!" << endl;
			cout << "Escolha uma opcao valida !!" << endl;
		}
		cout << "1 - Visualizar Lista em Ordenada" << endl;
		cout << "2 - Visualizar 'N' Primeiros da Lista" << endl;
		cout << "0 - Voltar" << endl;

		cout << "Escolha uma opcao: ";
		cin >> opcao;
		n++;

	} while (opcao < 0 || opcao > 2);
	return opcao;
}

///////////////////////////////////////////////////////////////////
/////// IMPLEMENTACAO DOS METODOS DA CLASSE ListaSalarios /////////
///////////////////////////////////////////////////////////////////
void ListaSalarios::entradaDeDados()
{
	float valor;
	int n;
	cout << "informe a quantidade de salarios que deseja inserir: " << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "informe o valor do salario: " << endl;
		cin >> valor;
		lista.push_back(valor);
	}
}

void ListaSalarios::mostraMediana()
{
	float mediana;
	if (lista.size() % 2 == 0)
	{
		mediana = (lista[(lista.size() - 1) / 2] + lista[(lista.size() - 1) / 2 + 1]) / 2;
	}
	else
	{
		mediana = lista[(lista.size() - 1) / 2];
	}
	cout << "\tMediana: " << mediana << endl;
}

void ListaSalarios::mostraMenor()
{
	float menor = lista[0];
	int tam = lista.size();
	for (int i = 1; i < tam; i++)
	{
		if (lista[i] < menor)
		{
			menor = lista[i];
		}
	}
	cout << "\tMenor salario: " << menor << endl;
}

void ListaSalarios::mostraMaior()
{
	float maior = lista[0];
	int tam = lista.size();
	for (int i = 1; i < tam; i++)
	{
		if (lista[i] > maior)
		{
			maior = lista[i];
		}
	}
	cout << "\tMaior salario: " << maior << endl;
}

void ListaSalarios::listarEmOrdem()
{
	int tam = lista.size();
	quicksort<float>(lista, 0, lista.size() - 1);
	listar_N_elementos(tam);
}

void ListaSalarios::listar_N_elementos(int n)
{
	int tam = lista.size();
	for (int i = 0; i < tam; i++)
	{
		if (i < n)
		{
			cout << "\tSalario " << i + 1 << "ª: " << lista[i] << endl;
		}
	}
}

int ListaSalarios::size()
{
	return lista.size();
}
///////////////////////////////////////////////////////////////////
///// FINAL IMPLEMENTACAO DOS METODOS DA CLASSE ListaSalarios /////
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/////// IMPLEMENTACAO DOS METODOS DA CLASSE ListaNomes /////////
///////////////////////////////////////////////////////////////////
void ListaNomes::entradaDeDados() {
		cout << "Quantos nomes deseja inserir?" << endl;
		int num;
		cin >> num;
		for (int i = 0; i < num; i++) {
			string nome;
			cout << "Digite o " << i+1 << " nome: " << endl; cin >> nome;
			lista.push_back(nome);
		}
	}
		
	void ListaNomes::mostraMediana() {
		if(lista.empty()) {
			cout << "A lista esta vazia. Nao ha mediana a ser mostrada." << endl;
			return;
		}		
		int media=0;
		int tamanho = lista.size();
		if (tamanho % 2 == 0) {
			media = tamanho / 2 - 1;
			cout << " " <<  media;
			cout << "A mediana e " << lista[media] << endl;
		}
		else {
			media = tamanho / 2;
			cout << "A mediana e " << lista[media] << endl;			
		}
	}
	
	void ListaNomes::mostraMenor() {
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
	void ListaNomes::mostraMaior() {
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



	void ListaNomes::listarEmOrdem()  {
		sort(lista.begin(), lista.end());
		for (const string& nome : lista) {
			cout << nome << endl;
		}
	}

	void ListaNomes::listar_N_elementos(int n)
	{
		int tam = lista.size();
		for (int i = 0; i < tam; i++)
		{
			if (i < n)
			{
				cout << "Nome " << i + 1 << "ª: " << lista[i] << endl;
			}
		}
	}
///////////////////////////////////////////////////////////////////
///// FINAL IMPLEMENTACAO DOS METODOS DA CLASSE ListaNomes /////
///////////////////////////////////////////////////////////////////