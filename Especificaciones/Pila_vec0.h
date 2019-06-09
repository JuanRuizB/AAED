#ifndef PILA_VEC0_H
#define PILA_VEC0_H

const int LMAX = 100; // Longitud máxima de una pila

class Pila {
public:
    typedef int tElemento; // por ejemplo
    Pila();
    bool vacia() const;
    bool llena() const; // Requerida por la implementación
    const tElemento& tope() const;
    void pop();
    void push(const tElemento& x);
private:
    tElemento elementos[LMAX]; // vector de elementos
    int tope_; // posición del tope
};


#endif // PILA_VEC0_H