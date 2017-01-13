#ifndef LISTA_H
#define LISTA_H


#include <iostream>

#define MAX 100
using namespace std;


template <class T1>
class Lista
{
public:
	Lista();//inicializa
	bool vacia();//Imprime si la lista esta vacia
	bool llena();//Si esta llena
	void insertar(T1);//Agrega elemento
	void eliminar(int);//Elimina necesitamos nota:posicion (o isbn)
	int primero();//Imprime el primer titulo (pienso en to strign)
	int ultimo();//ultimo (buscar estos metodos^ )
	int anterior(int);
	int siguiente(int);
	int localiza(T1);//retorna posicion
	T1 recupera(int);//Recupera el contenido del nodo Uso quizas de un tostring
	void imprimirlista();
	void anula();//esto podria ser con el destructor (investigar)
	bool repetido(T1);//devuelve V o F si esta repetido
private:
	T1 lista[MAX];
	int ult;
};

template <class T1>
Lista<T1>::Lista()
{
	ult = -1;

}

template <class T1>
bool Lista<T1>::vacia() {
	if (ult == -1)
		return true;
	else
		return false;
}

template <class T1>
bool Lista<T1>::llena() {
	if (ult == MAX - 1)
		return true;
	else
		return false;
}

template <class T1>
void Lista<T1>::insertar(T1 elemento) {
	if (!llena())
		lista[++ult] = elemento;
	else
		cout << "Error..." << endl;
}

template <class T1>
void Lista<T1>::eliminar(int ind) {
	if (!vacia()) {
		if (ind <= ult) {
			for (int i = ind; i < ult; i++) {
				lista[i] = lista[i + 1];
			}
			ult--;
		}
	}
	else
		cout << "Error..." << endl;
}

template <class T1>
int Lista<T1>::primero() {
	if (!vacia())
		return 0;
	return -1;
}

template <class T1>
int Lista<T1>::ultimo() {
	if (!vacia())
		return ult;
    return -1;
}

template <class T1>
int Lista<T1>::anterior(int ind) {
	if (ind <= ult + 1)
		return ind - 1;
	else
		return -1;
}

template <class T1>
int Lista<T1>::siguiente(int ind) {
	if (ind <= ult - 1)
		return ind + 1;
	else
        return -1;
}

template <class T1>
int Lista<T1>::localiza(T1 elemento) {
	bool encontrado=false;
	if(!vacia()){
        for (int i = 0; i <= ult; i++){
            if (lista[i].GetIsbn() == elemento.GetIsbn()) {
                return i;
                encontrado = true;
            }
        }
	}
	if (!encontrado)
		cout << "Error..." << endl;
}

template <class T1>
T1 Lista<T1>::recupera(int ind) {
	if (!vacia()) {
		if (ind <= ult) {
			return lista[ind];
		}
	}
	else
		cout << "Error..." << endl;
}

template <class T1>
void Lista<T1>::imprimirlista() {
	if (!vacia()) {
		for (int i = 0;i <= ult;i++) {
            cout<< recupera(i).toString()<<" Ejemplere: "<<recupera(i).GetEjemplares()<<" Precio: $"<<recupera(i).GetPrecio()<<endl;
		}
	}
	else
		cout << "Error..." << endl;
}

template <class T1>
void Lista<T1>::anula() {
	ult = -1;
}//*///esto podria ser el constructor

template <class T1>
bool Lista<T1>::repetido(T1 elemento)
{
    bool repetido=false;
    if (!vacia())
    {
        for(int i=0; i<=ult; i++)
        {
            if (lista[i].GetIsbn()==elemento.GetIsbn())
            {
                    repetido=true;
            }
        }
        if (repetido)
        {
            return true;
        }
        else return false;
    }
    else return false;
}

#endif // LISTA_H
