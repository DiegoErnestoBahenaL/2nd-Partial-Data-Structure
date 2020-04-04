//Created by Diego Ernesto Bahena López  5B1 18100022
//This program contains how fifo & lifo works

#include <iostream>
using namespace std;

//this class contains the methods and variables to use the fifo & lifo structure
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

//builder of the class that fills the array with 0's
fifo_lifo::fifo_lifo(int initiate)
{
	fifo_lifo::marker = 0;
	for (int i = 0; i < 20; i++)
	{
		fifo_lifo::array[i] = 0;
	}

}
//distroyer of the class that fills  again the array's spaces with 0's (only the used ones)
fifo_lifo::~fifo_lifo()
{
	for (int i = 0; i < marker; i++) {
		array[i] = 0;
	}
	cout << "objeto destruido" << endl;
}


//The method insert adds 1 element to the array and if the array is full, gives a message
void fifo_lifo::insert() {
	if (marker > 19) {
		cout << "El arreglo esta lleno" << endl;
	}
	else {
		cout << "ingresa el numero a insertar" << endl;
		cin >> number;
		array[marker] = number;
		//marker will grow through the execution of the program
		marker++; 
	}
}

//the method show prints the array, and if the array is empty, sends a message
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

//fifo structure makes the array move to a new position where the first element is deleted
void fifo_lifo::fifo() {
	if (marker < 1) {
		cout << "El arreglo esta vacio" << endl;
	}
	else
	{
		for (int i = 0; i < marker; i++) {
			array[i] = array[i + 1];
		}
		//marker is less because the number of elements in the array decrease
		marker--;
	}

}

//lifo just takes the last element and change it for 0
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

	//we must invocate our object out of the loop in order to save the content of the variable marker
    fifo_lifo object(0);
	int option;
	bool initiate = true;

	//infinite loop to always send the menu
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
			system("pause");

		}

			break;

		case 3: {

			object.lifo();
			system("pause");

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





