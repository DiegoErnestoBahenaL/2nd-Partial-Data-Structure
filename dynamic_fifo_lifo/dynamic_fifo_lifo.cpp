//Created by Diego Ernesto Bahena López  5B1 18100022
//This program contains how fifo & lifo works

#include <iostream>
using namespace std;

//this class contains the methods and variables to use the fifo & lifo structure
class fifo_lifo
{

public:

	fifo_lifo* fifo(fifo_lifo*, fifo_lifo*, int);
	void  lifo(fifo_lifo*, fifo_lifo*, int);
	void insert( fifo_lifo*, fifo_lifo*, int);
	void show();
	int age;
	char name[30];
	fifo_lifo* Next;

};





//The method insert adds 1 element to the array and if the array is full, gives a message
 void fifo_lifo::insert( fifo_lifo * Beginning,fifo_lifo * Cursor, int counter) {

	 if (counter == 0) {  

		cout << "Ingresa el nombre" << endl;
		cin.ignore();
		cin.getline( Beginning->name, 30, '\n');

		cout << "Ingresa la edad" << endl;
		cin >>Beginning->age;
		Beginning->Next = NULL;

	 }
	 else {	

		fifo_lifo* Temp = new fifo_lifo;

		cout << "Ingresa el nombre" << endl;
		cin.ignore();
		cin.getline(Temp->name, 30, '\n');

		cout << "Ingresa la edad" << endl;
		cin >> Temp->age;
		Temp->Next = NULL;
		
		Cursor = Beginning;

		while (Cursor->Next != NULL) {

			Cursor = Cursor->Next;

		}

		Cursor->Next = Temp;


	 }
	

}

//the method show prints the array, and if the array is empty, sends a message
void fifo_lifo::show(fifo_lifo* Beginning, fifo_lifo*, int) {
	

}



//lifo just takes the last element and change it for 0
void fifo_lifo::lifo(fifo_lifo* Beginning, fifo_lifo* Cursor, int counter) {

	Cursor = Beginning;
	int marker = 1;

	while (Cursor->Next != NULL) {
		
		if (marker == counter - 1) {
			
			fifo_lifo* Temp = new fifo_lifo;

			Temp = Cursor->Next;
			Cursor->Next = NULL;
			Cursor = Temp;
		}
		else {
			Cursor = Cursor->Next;
		}
		marker;
	}
	delete Cursor;//Borramos cursor que es la ultima "posicion"
}








//fifo structure makes the array move to a new position where the first element is deleted
fifo_lifo* fifo_lifo::fifo() {
	

}



int main() {

	
;
	int option, counter= 0;
	fifo_lifo * Beginning = new fifo_lifo;
	fifo_lifo* Cursor = new fifo_lifo;

	//infinite loop to always send the menu
	while (1 == 1) {

		system("cls");
		cout << "1. Insertar\n2. Eliminar(FIFO)\n3. Eliminar (LIFO)\n4. Mostrar\n5. Salir\n";
		cin >> option;

		switch (option) {

		case 1:

			Beginning->insert(Beginning, Cursor, counter);
			counter++;
			break;

		case 2:
		

		break;

		case 3: 
			if (counter == 0) {

				cout << "Todavía no hay ningún elemento que eliminar" << endl;
			}
			else {

				Beginning->lifo(Beginning, Cursor, counter);
				counter--;
			}
		

			  break;

		case 4: 

			

		

			  break;

		case 5:

			return 0;



		}

	}


	return 0;
}


