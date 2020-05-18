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
	void show(fifo_lifo*, fifo_lifo*, int);
	int age;
	char name[30];
	fifo_lifo* Next;

};





//this is the function where we will add the data to our "array"
 void fifo_lifo::insert( fifo_lifo * Beginning,fifo_lifo * Cursor, int counter) {

	 //The variable counter is a flag to know if the elements introduced are the first introduced in the array
	 if (counter == 0) {  


		 //the elements are assigned to the pointer Beginning; Beginning is literally, the beginning of the array
		cout << "Ingresa el nombre" << endl;
		cin.ignore();
		cin.getline( Beginning->name, 30, '\n');

		cout << "Ingresa la edad" << endl;
		cin >>Beginning->age;

		//we must be sure of don't skip this code line, where the pointer Next isn't pointing to an address right now
		Beginning->Next = NULL;

	 }
	 else {	


		 // starting in the second group of elements to our array, we add them to the pointer Temp
		fifo_lifo* Temp = new fifo_lifo;

		cout << "Ingresa el nombre" << endl;
		cin.ignore();
		cin.getline(Temp->name, 30, '\n');

		cout << "Ingresa la edad" << endl;
		cin >> Temp->age;
		Temp->Next = NULL;
		
		Cursor = Beginning;


		//this cycle is like we use a for with the ++ increment
		while (Cursor->Next != NULL) {

			Cursor = Cursor->Next;

		}

		Cursor->Next = Temp;


	 }
	

}


void fifo_lifo::show(fifo_lifo* Beginning, fifo_lifo* Cursor, int counter) {
	

	//if there is only one group of elements, we know that elements are in the ponter beginning

	if (counter == 1) {


		//Cursor will be equal to beginning
		Cursor = Beginning;
		cout << Cursor->name <<'\t'<< Cursor->age << endl;
	}
	//starting in the second group of elements to our array, we print the elements in Beginning, but also in the rest of the array
	else {

		Cursor = Beginning;
		cout << Cursor->name <<'\t' << Cursor->age << endl;
		Cursor = Cursor->Next;

		//the cylce ++, if we think statically (like the teacher said in the pdf :) )
		while (Cursor->Next != NULL) {

			cout << Cursor->name <<'\t'<< Cursor->age << endl;
			Cursor = Cursor-> Next;
		}
		cout << Cursor->name << '\t' << Cursor->age << endl;
	}


	system("Pause");

}



//the last in first out function
void fifo_lifo::lifo(fifo_lifo* Beginning, fifo_lifo* Cursor, int counter) {

	//we need the cursor to point the beginning of the array
	Cursor = Beginning;
	//an extra flag to know more exactly the positons of each element
	int marker = 1;

	while (Cursor->Next != NULL) {
		
		if (marker == counter-1) {
			
			fifo_lifo* Temp = new fifo_lifo;

			Temp = Cursor->Next;
			Cursor->Next = NULL;
			Cursor = Temp;
		}
		else {
			Cursor = Cursor->Next;
		}
		marker++;
	}

	//now we delete the content of cursor, because it was the last element
	delete Cursor; 
}




//the first in first out function
fifo_lifo* fifo_lifo::fifo(fifo_lifo* Beginning , fifo_lifo* Cursor, int counter ) {
	
	//we save memory for temp
	fifo_lifo* Temp = new fifo_lifo;


	//point it to the beginning of the array
	Temp = Beginning;
	//move the pointer beginning
	Beginning = Beginning->Next;
	

	//now beginning is the second element & we delete the first (Temp)
	delete Temp;
	
	
	return Beginning;

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

			//we need this flag to know how many elements exists
			counter++;
			break;

		case 2:

			if (counter == 0) {

				cout << "Todavía no hay ningún elemento que eliminar" << endl;
				system("Pause");
			}
			else {

				Beginning = Beginning->fifo(Beginning, Cursor, counter);
				counter--;
			}

		break;

		case 3: 
			if (counter == 0) {

				cout << "Todavía no hay ningún elemento que eliminar" << endl;
				system("Pause");
			}
			else {

				Beginning->lifo(Beginning, Cursor, counter);
				counter--;
			}
		

			  break;

		case 4: 
				cout << "\n";

				if (counter == 0) {
					cout <<"Todavía no hay nada que mostrar"<<endl;
					system("Pause");
				}

				else {
					Beginning->show (Beginning, Cursor, counter);
				}
				break;



		case 5:

			return 0;



		}

	}


	return 0;
}


