#ifndef COLA_H_
#define COLA_H_
#include <cassert>

template <typename T> class Cola
{
public:

    ///Constructor
    explicit Cola(unsigned TamaMax);
    ///Constructor de copia
    Cola(const Cola<T>& C);
    ///Sobrecarga de operador '='
    Cola<T>& operator =(const Cola<T>& C);
    ///Vacia
    bool vacia() const;
    ///Llena
    bool llena() const;
    ///Frente
    const T& frente() const;
    ///Pop
    void pop();
    ///Push
    void push(const T& x);
    ///Destructor
    ~Cola();

private:

    T *elementos;   ///Vector de elementos
    int Lmax;       ///Tamaño del vector
    int fin;        ///Posición del último elemento
}

template <typename T>
inline Cola<T>::Cola(unsigned TamaMax) :
    elementos(new T[TamaMax]),
    Lmax(TamaMax),
    fin(-1);
{}

template <typename T>
Cola<T>&::Cola(const Cola<T>& C) :
    elementos(new T[C.Lmax]),
    Lmax(C.Lmax),
    fin(C.fin)
{
    for(int i = 0; i < fin; i++)
    {
        elementos[i] = C.elementos[i]; ///copiar los elementos en el nuevo vector
    }
}

template <typename T>
Cola<T>& Cola<T>::operator =(const Cola<T>& C)
{
    if(this != &C) ///evitar autoasignacion
    {
        ///destruir el vector y crear uno nuevo si hace falta
        if(Lmax != C.Lmax)
        {
            delete [] elementos;
            Lmax = C.Lmax;
            elementos = new T[Lmax];
        }
        ///copiar el vector
        fin = C.fin;
        for(int i = 0; i < fin; i++)
        {
            elementos[i] = C.elementos[i];
        }
    }
    return *this;
}

template <typename T>
inline bool Cola<T>::vacia() const
{
    return (fin == -1);
}

template <typename T>
inline bool Cola<T>::llena() const
{
    return (fin == Lmax - 1);
}

template <typename T>
inline const <T>& Cola<T>:: frente() const
{
    assert(!Vacia());

    return elementos[0];
}

template <typename T>
void Cola<T>::pop()
{
    assert(!vacia());
    for(int i = 0; i < fin; i++)
    {
        elementos[i] = elementos[i+1];
    }
    fin--;
}

template <typename T>
inline void Cola<T>::push(const T& x)
{
    assert(!vacia());
    fin++;
    elementos[fin] = x;
}

template <typename T>
inline Cola<T>::~Cola()
{
    delete [] elementos;
}

#endif // COLA_VEC_H(2)_H_INCLUDED
