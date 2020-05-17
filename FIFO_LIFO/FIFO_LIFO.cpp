//Created by Diego Ernesto Bahena López  5B1 18100022
//This program contains how fifo & lifo works

#include <iostream>
using namespace std;

//this class contains the methods and variables to use the fifo & lifo structure
class fifo_lifo
{

public:
	 fifo_lifo();
	~fifo_lifo();
	void fifo();
	void  lifo();
	void insert();
	void show();

private:
	char name[30];
	int age;

};


//structure out of the class "Person" contains name, age and the pointer

struct Person {

	char name[30];
	int age;
	Person* Next;

};










//distroyer of the class that fills  again the array's spaces with 0's (only the used ones)
fifo_lifo::~fifo_lifo()
{
	
}


//The method insert adds 1 element to the array and if the array is full, gives a message
void fifo_lifo::insert() {
	
	
		
	
}

//the method show prints the array, and if the array is empty, sends a message
void fifo_lifo::show() {
	cout << "Ingrese el nombre" << endl;
	cin.ignore();
	cin.getline(name, 30, '\n');
	cout << "Ingresa la edad" << endl;
	cin >> age;
}

void fifo_lifo::fifo() {


}


void fifo_lifo::lifo() {




}

int main() {

	//we must invocate our object out of the loop in order to save the content of the variable marker
    fifo_lifo object;
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





