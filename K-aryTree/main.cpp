#include <iostream>
#include "Tree.h"
using namespace std;

int main() {
	int option;
	Tree<int>* tree = nullptr;
	while (true) {
		if (!tree) {
			cout << "1. Kreirajte stablo" << endl // Create tree
				<< "0. Napustite program" << endl // Exit
				<< "Unesite redni broj: "; // Enter number:
			cin >> option;
			switch (option) {
			case 0: {
				return 0;
			}
			case 1: {
				cout << "Unesite red stabla: "; // Enter tree order:
				int order; cin >> order;
				if (order < 2) {
					cout << "\tRed stabla mora biti veci ili jednak 2!" << endl; // Tree order must be >= 2!
					continue;
				}
				tree = new Tree<int>(order);
				break;
			}
 			}
			cout << endl;
		}

		cout << "1. Ubacite brojeve" << endl // Insert numbers
			<< "2. Ispisite stablo" << endl // Write out tree
			<< "3. Sirina stabla" << endl // Tree width
			<< "4. Obrisite stablo" << endl // Delete tree
			<< "0. Napustite program" << endl // Exit
			<< "Unesite redni broj: "; // Enter number:
		cin >> option;

		switch (option) {
		case 0: {
			if (tree) delete tree;
			return 0;
		}
		case 1: {
			int count, value;
			cout << "Unesite broj brojeva za ubacivanje: "; // Enter number count:
			cin >> count; 
			cout << "Unesite brojeve: "; // Enter numbers:
			for (int i = 0; i < count; i++) {
				cin >> value;
				tree->Insert(value);
			}
			break;
		}
		case 2: {
			tree->Print();
			break;
		}
		case 3: {
			cout << "Sirina stabla je: " << tree->Width() << endl; // Tree width is:
			break;
		}
		case 4: {
			delete tree; tree = nullptr;
			break;
		}
		}
		cout << endl;
	}
}