#include <iostream>
using namespace std;

class Lifo_Fifo
{
private:
	int datos[20];
	int cantidadDatos;
public:
	Lifo_Fifo(int);
	~Lifo_Fifo(void);
	void Lifo(void);
	void Fifo(void);
	void Insertar(int);
	void Mostrar(void);
};


Lifo_Fifo::Lifo_Fifo(int a)
{
	Lifo_Fifo::cantidadDatos = 0;
	for (int i = 0; i < 20; i++)
	{
		Lifo_Fifo::datos[i] = 0;
	}

}

Lifo_Fifo::~Lifo_Fifo()
{
	for (int i = 0; i < cantidadDatos; i++) {

		datos[i] = 0;
	}
	
}



void Lifo_Fifo::Insertar(int datoInsertar) {
	datos[cantidadDatos] = datoInsertar;
	cantidadDatos++;
}
void Lifo_Fifo::Fifo(void) {
	if (cantidadDatos < 1) {
		cout << "No hay ningun dato que eliminar" << endl;
	}
	else
	{
		for (int i = 0; i < cantidadDatos; i++) {
			datos[i] = datos[i + 1];//recorre todos los datos existenes un numero asi eliminando el primero
		}
		cantidadDatos--;
	}

}
void Lifo_Fifo::Lifo(void) {
	if (cantidadDatos < 1) {
		cout << "No hay ningun dato que eliminar" << endl;
	}
	else
	{
		datos[cantidadDatos] = 0;//elimina el ultimo dato poniendolo en su valor inicial
		cantidadDatos--;//Disminuye en la cantidad de datos el numero que se a eliminado
	}
}
void Lifo_Fifo::Mostrar(void) {
	if (cantidadDatos > 0) {//revisa si existen datos que mostrar
		cout << "[";
		for (int i = 0; i < cantidadDatos; i++) {//Recorre la cantidad de datos para mostrarlos
			cout << "  " << datos[i] << "  ";
		}
		cout << "]" << endl;
	}
	else
	{
		cout << "No hay datos para mostrar" << endl;
	}

}


int main() {
	
	int option;
	bool initiate = true;
	while (1 == 1) {
		system("cls");
		cout << "1. Insertar\n2. Eliminar(FIFO)\n3. Eliminar (LIFO)\n4. Mostrar\n5. Salir\n";
		cin >> option;
		Lifo_Fifo object(0);
		switch (option) {

		case 1: {
			int number;
			cout << "ingresa el numero a insertar" << endl;
			cin >> number;
			object.Insertar(number);
			
		}
			system("pause");
			break;

		case 2: 

			break;

		case 3:

			break;

		case 4: {

			object.Mostrar();
			system("pause");

		}

			break;

		case 5:

			return 0;





		}

	}





	return 0;
}


