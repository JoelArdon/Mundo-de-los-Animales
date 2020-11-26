#include "Arbol.h"

bool validaContinuidadPrograma();
void mostrarMenu();

int main() {
	Arbol *ar = new Arbol();
	ar->setRoot(ar->cargarArbolDeArchivo());

	/*Variables que almacenaran nuevos datos para el aprendizaje del arbol*/
	string carasteristica = "", animalnuevo = "";
	
	/*Variables para la continuidad del programa */
	bool seguirJugando = false, validar = false;
	int respuestaMenu = 0, nodoc = 1 , nodoin = 0;
	char nodocambiar = ' ';
	string respuesta = "0";

	do {
		mostrarMenu();
		do {
			validar = false;
			cout << "Su respuesta: ";
			cin >> respuestaMenu;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Error: La respuesta no es digito." << endl << endl;
				mostrarMenu();
				validar = true;
			}
		} while (validar);
		
		system("cls");

		switch (respuestaMenu) {
		case 1: {
			nodo *&ultimaResp = ar->recorreArbol(ar->root, respuesta);
			cout << endl;
			cout << "Su animal es un/a: " << ultimaResp->dato << "? (s = SI / cualquier otro caracter = NO)" << endl;
			cin.clear();
			cin.ignore();
			getline(cin, respuesta);
			if (respuesta == "S" || respuesta == "s") {
				system("cls");
				cout << "He ganado!" << endl << endl;
				seguirJugando = validaContinuidadPrograma();
				system("cls");
			}
			else {
				system("cls");
				cout << "He perdido, ayudame a mejorar!" << endl << endl;
				cout << "Favor digite una carasteristica FUERTE del animal que estaba pensando: ";
				std::getline(cin, carasteristica);
				cout << endl;
				cout << "Favor ahora digite cual es el animal que estaba pensando: ";
				std::getline(cin, animalnuevo);
				cout << endl;
				ar->insertar(ultimaResp, carasteristica, animalnuevo);
				system("cls");
				cout << "Gracias por ayudarme a aprender mas!" << endl;
				seguirJugando = validaContinuidadPrograma();
				system("cls");
			}
			break;
		}
		case 2: {
			cout << "Niveles: " << endl << endl;
			ar->caras_generales(ar->root);
			cout << endl;
			do {
				validar = false;
				
				cout << "Digite el NUMERO un nivel (caracteristica general) que desea cambiar: ";
				cin >> nodoc;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "No es digito" << endl;
					validar = true;

				}
				if (nodoc > 6 || nodoc < 0) {
					cout << "Inserte un numero valido" << endl;
					validar = true;
				}
				
			} while (validar);
			
			do {
				validar = false;

				cout << "Digite el NUMERO del nivel (caracteristica general) con el cual quiere intercambiarlo: ";
				cin >> nodoin;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();

					cout << "No es digito" << endl;
					validar = true;

				}
				if (nodoin > 6 || nodoin < 0) {
					cout << "Inserte un numero valido" << endl;
					validar = true;
				}

			} while (validar);

			
			if (nodoin <= nodoc&&nodoin!=1) {
				nodoin--;
			}
			
				system("cls");
				ar->caras_generales(ar->root);
				cout << endl;
				ar->cambiaOrden(ar->buscaNodo(ar->root, ar->ObtieneNodoNivel(ar->root, nodoc)),
					ar->buscaNodo(ar->root, ar->ObtieneNodoNivel(ar->root, nodoin)));
				cout << "Se cambio el orden exitosamente. Nuevo orden:" << endl << endl;
				ar->caras_generales(ar->root);
				cout << endl;

			seguirJugando = validaContinuidadPrograma();
			system("cls");
			break;
		}
		case 3: {
			cout << "Niveles:" << endl << endl;
			ar->caras_generales(ar->root);
			cout << endl;
			seguirJugando = validaContinuidadPrograma();
			system("cls");
			break;
		}
		default: {
			cout << "Error: Favor digite una respuesta valida." << endl << endl;
			seguirJugando = true;
			break;
		}
		}
	} while (seguirJugando);

	ar->guardarArbol(ar->root, "animales.txt");
	return 0;
}

bool validaContinuidadPrograma() {
	bool validar;
	bool seguirJugando;
	do {
		validar = false;

		cout << "Digite 1 para volver al menu principal o 0 para salir del programa: ";
		cin >> seguirJugando;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			system("cls");
			cout << "Error: No es digito valido." << endl << endl;
			validar = true;
		}

	} while (validar);
	return seguirJugando;
}

void mostrarMenu() {
	cout << "[1] Jugar" << endl;
	cout << "[2] Cambiar caracteristicas generales de nivel" << endl;
	cout << "[3] Mostrar los niveles del arbol" << endl << endl;
}