#include "Arbol.h"



Arbol::Arbol() {
	root = nullptr;
}

Arbol::~Arbol() {
	destruir(root);
}

void Arbol::insertar(nodo* &respuestaFinal, string caracteristica, string animal) {
	nodo* aux = respuestaFinal;
	nodo* nodoCaracteristica = newNodo(caracteristica);
	nodo* nodoAnimal = newNodo(animal);

	respuestaFinal = nodoCaracteristica;

	nodoCaracteristica->left = aux;
	nodoCaracteristica->right = nodoAnimal;
}

void Arbol::guardarArbol(nodo* actual, string arch) {
	std::string filename;
	filename = arch;
	std::ofstream archivo(filename, std::ios::out);
	guardar(root, archivo);
	archivo << "$" << endl;
	archivo.close();
}

nodo* Arbol::cargarArbolDeArchivo() {
	std::string filename;
	std::ifstream handle("animales.txt", std::ios::in);
	if (!handle) {
		return nullptr;
	}
	nodo* tmp = insertaNodoDesdeArchivo(handle);
	handle.close();
	return tmp;
}

/*Función Auxiliar para crear un árbol binario tipo char desde el archivo manejado por "handle"
  La función retorna un apuntador de tipo NODOPTR a la raíz del árbol*/
nodo* Arbol::insertaNodoDesdeArchivo(std::ifstream& handle) {
	string c;
	nodo* tmp;
	getline(handle, c);
	if (c == "$")
		return nullptr;
	tmp = new nodo();
	tmp->dato = c;
	tmp->left = insertaNodoDesdeArchivo(handle);
	tmp->right = insertaNodoDesdeArchivo(handle);
	return tmp;
}

void Arbol::guardar(nodo* actual, ofstream& archivo) {
	if (actual != nullptr) {

		archivo << actual->dato << endl;
		guardar(actual->left, archivo);
		archivo << "$" << endl;
		guardar(actual->right, archivo);
	}
}

void Arbol::setRoot(nodo * nuevo) {
	root = nuevo;
}

nodo*& Arbol::recorreArbol(nodo *& nodo, string respuesta) {
	if (nodo->left == nullptr && nodo->right == nullptr) {
		return  nodo;
	}

	cout << "Su animal es un/a: " << nodo->dato << "? (s = SI / cualquier otro caracter = NO)" << endl;
	cin >> respuesta;


	if (respuesta == "S" || respuesta == "s") {
		return recorreArbol(nodo->right, respuesta);
	}
	else
		return recorreArbol(nodo->left, respuesta);
}

void Arbol::recorrePreOrden(nodo* actual) {
	if (actual != nullptr) {
		cout << actual->dato << endl;
		recorrePreOrden(actual->left);
		recorrePreOrden(actual->right);
	}
}

void Arbol::destruir(nodo* actual){
	if (actual != nullptr) {
		destruir(actual->left);
		destruir(actual->right);
		delete actual;
	}
}

nodo* Arbol::newNodo(string dato) {
	nodo* tmp = new nodo();
	tmp->dato = dato;
	tmp->right = tmp->left = nullptr;
	return tmp;
}

void Arbol::caras_generales(nodo* actual) {
	queue<nodo*> Cola;
	nodo* tmp;
	int cont = 0;
	if (!actual)
		return;

	Cola.push(actual);
	while (!Cola.empty()) {
		tmp = Cola.front();
		Cola.pop();
		if (tmp->left != nullptr&&tmp->right != nullptr) {
			cont++;
			std::cout << "Nivel " << cont << " " << tmp->dato << endl;
			if (tmp->left)
				Cola.push(tmp->left);
		}
	}
}

string Arbol::ObtieneNodoNivel(nodo*& actual, int n) {
	queue<nodo*> Cola;
	nodo* tmp;
	int cont = 0;
	if (!actual)
		return nullptr;


	Cola.push(actual);
	while (!Cola.empty()) {
		tmp = Cola.front();
		Cola.pop();
		if (tmp->left != nullptr&&tmp->right != nullptr) {
			cont++;
			if (cont == n)
				return tmp->dato;
			if (tmp->left)
				Cola.push(tmp->left);

		}
	}
}

void Arbol::cambiaOrden(nodo*& cambiar, nodo*& insertar) {
	nodo* aux = cambiar;
	cambiar = cambiar->left;
	nodo* aux2 = insertar->left;
	insertar->left = aux;
	insertar->left->left = aux2;
}

nodo*& Arbol::buscaNodo(nodo*& actual, string dato) {
	if (actual != nullptr) {
		if (actual->dato == dato)
			return actual;
		else {
			return buscaNodo(actual->left, dato);
			return buscaNodo(actual->right, dato);
		}
	}
}



