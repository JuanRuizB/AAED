#ifndef TAD_LISTA_H_INCLUDED
#define TAD_LISTA_H_INCLUDED
#include <cassert>

template <typename T>
class Lista
{

public:
    //posición de un elemento
    typedef int posicion;

    //constructor
    explicit Lista(size_t TamaMax);

    //constructor de copia
    Lista(const Lista<T>& L);

    //asignacion
    Lista<T>& operator =(const Lista<T>& L);

    //insertar un elemento en la lista
    void insertar(const T& x, posicion p);

    //elimina un elemento de la lista
    void eliminar(posicion p);

    //elemento que ocupa la posición p
    const T& elemento(posicion p) const;

    //posición de la primera ocurrencia de x en la lista
    posicion buscar(const T& x) const;

    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const;

    //Destructor
    ~Lista();

private:
    T *elementos;   //vector de elementos.
    int Lmax;       //tamaño del vector.
    int n;          //longitud de la lista en un momento dado.

};  

template <typename T>
inline Lista<T>&::Lista(size_t TamaMax):
    elementos(new (T[TamaMax])),
    Lmax(TamaMax),
    n(0)
{}

template <typename T>
Lista<T>::Lista(const Lista<T>& L):
    elementos(new (T[L.TamaMax])),
    Lmax(L.Lmax),
    n(L.n)
{
    //por qué poner "Lista<T>::posicion p", y no "posicion p"
    for(Lista<T>::posicion p = 0; p < n; p++)
    {
        elementos[p] = L.elementos[p];
    }
}

template <typename T>
Lista<T>& Lista<T>::operator =(const Lista<T>& L)
{
    if(this != &L) //evitar la autoasignación
    //destruir el vector y crear uno nuevo si es necesario
    {
        if(Lmax != L.Lmax)
        {
            delete[] elementos;
            Lmax = L.Lmax;
            elementos = new T[Lmax];
        }
        //copiar el vector
        n = L.n;
        for(Lista<T>::posicion p = 0; p < n; p++)
            elementos[p] = L.elementos[p];
    }
    return *this;
}

template <typename T>
void Lista<T>::insertar(const T& x, Lista<T>::posicion p)
{
    assert(p > 0 && p < Lmax);  //Posición válida
    assert(n < Lmax);           //Lista no llena
    for(Lista<T>::posicion q = n; q > p; q--)
        elementos[q] = elementos[q-1];
    elementos[p] = x;
    n++;
}

template <typename T>
void Lista<T>::eliminar(Lista<T>::posicion p)
{
    assert(p > 0 && p < Lmax);
    for(Lista<T>::posicion q = p; q < (n - 1); q++)
        elementos[q] = elementos[q+1];
    n--;
}

template <typename T>
const T& Lista<T>::elemento(Lista<T>::posicion p) const
{
    assert(p > 0 && p < Lmax);
    return elementos[p];
}

template <typename T>
Lista<T>::posicion Lista<T>::buscar(const T& x) const
{
    Lista<T>::posicion i = 0;
    bool found = false;

    while(q < n && !found)
        if(elementos[i] == x)
            found = true;
        else i++;
    return i;
}

template <typename T>
inline Lista<T>::posicion Lista<T>::siguiente(Lista<T>::posicion p) const
{
    assert(p > 0 && p < Lmax);  //posición válida
    return p+1;
}

template <typename T>
inline Lista<T>::posicion Lista<T>::anterior(Lista<T>::posicion p) const
{
    assert(p > 0 && p < Lmax);  //posición válida
    return p-1;
}

template <typename T>
inline Lista<T>::posicion Lista<T>::primera() const
{
    return 0;
}

template <typename T>
inline Lista<T>::posicion Lista<T>::fin() const
{
    return n;
}

template <typename T>
inline Lista<T>::~Lista()
{
    delete[] elementos;
}

#endif // TAD_LISTA_H_INCLUDED
