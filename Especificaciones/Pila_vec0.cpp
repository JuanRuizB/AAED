#include <cassert>
#include "pilavec0.h"

Pila::Pila() : tope_(-1)
{}

bool Pila::vacia() const
{
    return (tope_ == -1);
}

bool Pila::llena() const
{
    return (tope_ == LMAX - 1);
}

const Pila::tElemento& Pila::tope() const
{
    assert(!vacia());
    return elementos[tope_];
}

void Pila::pop()
{
    assert(!vacia());
    --tope_;
}

void Pila::push(const tElemento& x)
{
    assert(!llena());
    ++tope_;
    elementos[tope_] = x;
}

