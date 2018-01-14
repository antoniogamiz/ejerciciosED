#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include "bintree.h"
#include <stack>
#include <list>
using namespace std;

/*================FUNCIONES PARA MOSTRAR EL ÁRBOL================*/

void escribir_esquema_arbol(ostream& ss,
					  const bintree<int>& a,
		    		  bintree<int>::node n,
					  string& pre){
	if (n.null()){
	    ss << pre << "-- x" << endl;
	} else {
	    ss << pre << "-- " << (*n) << endl;
	    if ( !n.right().null() || !n.left().null()) {// Si no es una hoja
			pre += "   |";
	    	escribir_esquema_arbol(ss,a, n.right(), pre);
	     	pre.replace(pre.size()-4, 4, "    ");
	      	escribir_esquema_arbol (ss,a, n.left(), pre);
	      	pre.erase(pre.size()-4, 4);
	    }
  	}
}

void escribir_arbol_completo(bintree<int> arbol){
	string pre = "";
	escribir_esquema_arbol(cout, arbol, arbol.root(),pre);
}

/*================MOSTRAR CAMINOS================*/

void mostrar_caminos(list<vector<int> >& caminos){
	int k=0;
	for(list<vector<int> >::iterator i=caminos.begin(); i != caminos.end(); i++){
		cout << "Camino: " << k++ << "   "; 
		for(int j=0; j < (*i).size(); j++){
			cout << (*i)[j] << "---";
		}
		cout << endl;
	}
}

/*================SOLUCION================*/

void calcular_caminos_recursivo(int k, list<vector<int> >& all_paths, bintree<int>::node n, vector<int> currently_path, bool is_path){
	if( !n.null() ){
		currently_path.push_back((*n));
		if( is_path || (*n) == k ){
			if( !n.left().null() )
				calcular_caminos_recursivo(k, all_paths, n.left(), currently_path, true);
			if( !n.right().null() )
				calcular_caminos_recursivo(k, all_paths, n.right(), currently_path, true);
		}else{
					calcular_caminos_recursivo(k, all_paths, n.left(), currently_path, false);
					calcular_caminos_recursivo(k, all_paths, n.right(), currently_path, false);								
			}

		if( n.left().null() && n.right().null() ){
			if( is_path || (*n) == k ){
				all_paths.push_back(currently_path);
			}
		}
	}
}

void calcular_caminos(int k, list<vector<int> >& caminos, bintree<int>& arbol){
	vector<int> path;
	calcular_caminos_recursivo(k, caminos, arbol.root(), path, false);
}

int main(int argc, char * argv[]){
	//Creamos un árbol de ejemplo a lo bruto.
	bintree<int> arbol(1);
	arbol.insert_left(arbol.root(), 2);
	arbol.insert_right(arbol.root(), 3);
	arbol.insert_left(arbol.root().left(), 3);
	arbol.insert_right(arbol.root().left(), 4);
	arbol.insert_left(arbol.root().right(), 4);
	arbol.insert_right(arbol.root().right(), 5);
	arbol.insert_left(arbol.root().left().left(), 4);

	escribir_arbol_completo(arbol);

	list<vector<int> > caminos;

	cout << "CAMINOS DEL 3" << endl;
	calcular_caminos(3, caminos, arbol);
	mostrar_caminos(caminos);
	caminos.clear();

	cout << "CAMINOS DEL 4" << endl;
	calcular_caminos(4, caminos, arbol);
	mostrar_caminos(caminos);
	caminos.clear();

	cout << "CAMINOS DEL 1" << endl;
	calcular_caminos(1, caminos, arbol);
	mostrar_caminos(caminos);
	caminos.clear();

}
