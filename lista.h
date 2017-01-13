/** Autor: Alejandro Ponce.
 *  Grado: Estudiante de ing. en Computacion
 *  Archivo: "lista.h"
 *  Descripcion: Lista estatica con template.
 *               Esta es capaz de manejar cualquier dato modificando un poco el codigo
 *               Prestar atencion a la funcion "repetido" y en "toString()" !
 */
#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

template <class T1>
class Lista
{
public:
	Lista();
	bool vacia(); // importante
	bool llena();
	void insertar(T1); // importante
	void eliminar(int); //importante
	int primero();
	int ultimo();
	int anterior(int);
	int siguiente(int);
	int localiza(T1); // importante
	T1& recupera(int); // importante
	void imprimirlista(); //importante
	void anula();
	bool repetido(T1); // importante
	void insertion_sort(); // Metodos de orenamiento
	void selection_sort(); // """"
	void bubble_sort(); // """"
	void my_swap(int,int); /// """
	const static int MAX = 100;

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
    {
        if (!repetido(elemento))
        {
            lista[++ult] = elemento;
        }
        else
            cout << "elemento repetido" << endl;
    }
	else
		cout << "lista llena!" << endl;
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
            if (lista[i] == elemento) {
                return i;
                encontrado = true;
                break;
            }
        }
        if (!encontrado)
            return -1;
	}
	return-1;

}

template <class T1>
T1& Lista<T1>::recupera(int ind) {
	T1 nulo;
	if (!vacia()) {
		if (ind <= ult && ind!= -1) {
			return lista[ind];
		}
		else
        {
            cout<< "elemento no existente" << endl;
            return nulo;
        }
	}
	else
    {
        cout << "lista vacia!" << endl;
        return nulo;
    }
}

template <class T1>
void Lista<T1>::imprimirlista() {
	if (!vacia()) {
		for (int i = 0;i <= ult;i++) {
            cout << recupera(i).toString() << endl;
		}
	}
}

template <class T1>
void Lista<T1>::anula() {
	ult = -1;
}//*///esto podria ser el constructor

template <class T1>
bool Lista<T1>::repetido(T1 elemento)
{
    if (!vacia())
    {
        bool rep = false;
        for(int i=0; i<=ult; i++)
        {
            if (lista[i]==elemento)
            {
                rep = true;
                return true;
            }
        }
        if(!rep)
            return false;
    }
    else return false;
}

template <class T1>
void Lista<T1>::my_swap(int i, int j)
{
    T1 temp = lista[i];
    lista[i]=lista[j];
    lista[j]=temp;
}

template <class T1>
void Lista<T1>::bubble_sort()
{
    if(!vacia())
    {
        for (int j=0; j<ult; j++)
        {
            for (int i=ult; i>j; i--)
            {
                if( lista[i] > lista[i-1] )
                    my_swap(i,i-1);
            }
        }

    }
    else
        cout << "Lista vacia!" << endl;
}

template <class T1>
void Lista<T1>::selection_sort()
{
    if( !vacia() )
    {
        T1 tmp;
        int ind;
        for (int j=0; j<=ult; j++)
        {
            tmp = lista[j];
            ind = j;
            for (int i = j+1; i<=ult; i++)
            {
                if (lista [i] > tmp )
                {
                    tmp = lista[i];
                    ind = i;
                }
            }
            my_swap(ind,j);
        }
    }
    else
        cout << "Lista vacia!" << endl;
}

template <class T1>
void Lista<T1>::insertion_sort()
{
    if( !vacia() )
    {
        int j;
        T1 tmp;
        for(int i=1;i<=ult; i++)
        {
            tmp = lista[i];
            j=i-1;
            while( (lista[j]<tmp) && (j>=0) )
            {
                my_swap(j+1,j);
                j--;
            }
            lista[j+1]=tmp;
        }
    }
    else
        cout << "Lista vacia!" << endl;
}
#endif // LISTA_H
