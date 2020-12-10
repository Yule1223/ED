
// Yule Zhang

#include <iostream>
#include <fstream>
using namespace std;

#include "queue_eda.h"
#include "horas.h"

template <typename T>
class listaPlus : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void modifica() {
		if (this->nelems >= 2) {
			Nodo* p = this->prim;
			
			bool exist = true;
			if (p->sig->sig == nullptr)
				exist = false;
			while (exist) {
				p->sig = p->sig->sig;
				p = p->sig;
				if (p->sig == nullptr|| p->sig->sig == nullptr)
					exist = false;
			}
			p->sig = nullptr;
			this->ult = p;
		}
	}

	void print() const {
		Nodo* aux = this->prim;
		while (aux != nullptr) {
			cout << aux->elem << ' ';
			aux = aux->sig;
		}
		cout << endl;
	}
};



bool resuelveCaso() {
	int numElem;
	std::cin >> numElem;
	if (numElem == 0)
		return false;

	listaPlus<horas> l;
	horas h;
	for (int i = 0; i < numElem; ++i) {
		cin >> h;
		l.push(h);
	}

	l.modifica();

	l.print();

	return true;
}



int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}