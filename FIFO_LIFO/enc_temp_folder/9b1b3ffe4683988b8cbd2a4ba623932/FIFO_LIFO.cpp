//Created by Diego Ernesto Bahena López  5B1 18100022
//This program contains how fifo & lifo works

#include <iostream>
using namespace std;

class fifo_lifo
{

public:
	fifo_lifo(int);
	~fifo_lifo();
	void fifo();
	void  lifo();
	void insert();
	void show();

private:
	int array[20], marker, number;
};


fifo_lifo::fifo_lifo(int initiate)
{
	fifo_lifo::marker = 0;
	for (int i = 0; i < 20; i++)
	{
		fifo_lifo::array[i] = 0;
	}

}
fifo_lifo::~fifo_lifo()
{
	for (int i = 0; i < marker; i++) {
		array[i] = 0;
	}
	cout << "objeto destruido" << endl;
}



void fifo_lifo::insert() {
	if (marker > 19) {
		cout << "El arreglo esta lleno" << endl;
	}
	else {
		cout << "ingresa el numero a insertar" << endl;
		cin >> number;
		array[marker] = number;
		marker++;
	}
}


void fifo_lifo::show() {
	if (marker > 0) {
		
		for (int i = 0; i < marker; i++) {
			cout  << array[i] ;
		}
		cout << "\n";
	}
	else
	{
		cout << "El arreglo esta vacio" << endl;
	}

}
void fifo_lifo::fifo() {
	if (marker < 1) {
		cout << "El arreglo esta vacio" << endl;
	}
	else
	{
		for (int i = 0; i < marker; i++) {
			array[i] = array[i + 1];
		}
		marker--;
	}

}
void fifo_lifo::lifo() {
	if (marker < 1) {
		cout << "El arreglo esta vacio" << endl;
	}
	else
	{
		array[marker] = 0;
		marker--;
	}
}

int main() {


    fifo_lifo object(0);
	int option;
	bool initiate = true;
	while (1 == 1) {
		system("cls");
		cout << "1. Insertar\n2. Eliminar(FIFO)\n3. Eliminar (LIFO)\n4. Mostrar\n5. Salir\n";
		cin >> option;
		
		switch (option) {

		case 1: {
			
			object.insert();

		}
			  system("pause");
			  break;

		case 2:
		{
			object.fifo();
		}

			break;

		case 3: {

			object.lifo();
		}

			break;

		case 4: {

			object.show();
			system("pause");

		}

			  break;

		case 5:

			return 0;



		}

	}


	return 0;
}





