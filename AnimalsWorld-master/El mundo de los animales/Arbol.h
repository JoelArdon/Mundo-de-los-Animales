/**
@title Arbol de decision
@author Joel Salas Ardon, Nataly Fernandez Villalobos, Allan Ramirez Chavarria
@date 07/11/2018
*/

#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <fstream> //manejos de archivos
#include <string>
#include<queue>
#include <cstdlib> 
#include <windows.h> 
using namespace std;

/**
@brief Estructura de la cual esta conformada el arbol.
*/
struct nodo {
	string dato;
	struct nodo* left;
	struct nodo* right;
};

class Arbol {
public:
	nodo* root;
	/**
	@brief Constructor sin parametros de la clase Arbol.
	*/
	Arbol();
	/**
	@brief Destructor de la clase Arbol.
	*/
	~Arbol();

	/**
	@brief Funcion que recorre el arbol considerando una respuesta de verdadero o false dada por el usuario.
	@param nodo Nodo actual por el cual va el recorrido.
	@param respuesta Respuesta verdadera o falsa dada por el usuario.
	@return Retorna el apuntado a la direccion de memoria donde se encuentra el nodo hoja de la respuesta final del programa.
	*/
	nodo*& recorreArbol(nodo* &nodo, string respuesta);
	/**
	@brief Funcion para insertar un nuevo nodo.
	@param respuestaFinal Nodo hoja respuesta final del programa.
	@param caracteristica Caracteristica fuerte del nuevo animal.
	@param animal Animal que estaba pensando el usuario y el programa no adivino.
	*/
	void insertar(nodo*& respuestaFinal, string caracteristica, string animal);
	/**
	@brief Funcion que modifica la raiz de un arbol.
	@param nuevo Apuntador a un nodo.
	*/
	void setRoot(nodo* nuevo);
	/**
	@brief Funcion utilizada para guardar datos del arbol.
	@param actual Nodo actual.
	@param arch Nombre del archivo donde guardara.
	*/
	void guardarArbol(nodo*actual, string arch);
	/**
	@brief Funcion auxiliar utilizada para guardar datos del arbol.
	@param actual Nodo actual.
	@param archivo Archivo donde guardara.
	*/
	void guardar(nodo*actual, ofstream& archivo);
	/**
	@brief Funcion para cargar el arbol guardado en un archivo.
	@return Retorna un apuntador a la raiz del arbol.
	*/
	nodo* cargarArbolDeArchivo();
	/**
	@brief Funcion auxiliar utilizada para cargar datos del arbol.
	@param handle Captura de datos.
	@return Retorna un apuntador de tipo NODOPTR a la raíz del árbol.
	*/
	nodo* insertaNodoDesdeArchivo(std::ifstream& handle);
	/**
	@brief Funcion que crea un nuevo nodo.
	@param dato Dato que se almacenara en el nodo.
	@return Retorna un nuevo nodo con el dato recibido por parametro almacenado.
	*/
	nodo* newNodo(string dato);
	/**
	@brief Funcion que muestra las caracteristicas generales del arbol.
	@param raiz del arbol.
	*/
	void caras_generales(nodo* actual);
	/**
	@brief Funcion que obtiene la caracteristica general del arbol apartir de un numero.
	@param raiz del arbol.
	@param numero que corresponde al nivel de la carasterstica
	@return Retorna la carasteristica de ese nivel.
	*/
	string  ObtieneNodoNivel(nodo* &actual, int n);
	/**
	@brief Funcion que busca un nodo apartir del dato que contiene.
	@param raiz del arbol.
	@param dato que contiene
	@return Retorna el nodo que corresponde a ese dato.
	*/
	nodo*& buscaNodo(nodo*&, string);
	/**
	@brief Funcion que cambia los niveles de las carasteristicas generales.
	@param nodo a cambiar.
	@param nodo donde se inserta
	@return Retorna un nuevo nodo con el dato recibido por parametro almacenado.
	*/
	void cambiaOrden(nodo*& cambiar, nodo *&insertar);
	void recorrePreOrden(nodo* actual);
	void destruir(nodo* root);
};

#endif /*ARBOL_H*/