// Exceptions.h
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
using namespace std;

class StocInsuficientException : public exception {
public:
    const char* what() const noexcept override {
        return "Eroare: Produsul nu mai este in stoc!";
    }
};

class ComandaGoalaException : public exception {
public:
    const char* what() const noexcept override {
        return "Eroare: Comanda este goala!";
    }
};

class OptiuneInvalidaException : public exception {
public:
    const char* what() const noexcept override {
        return "Eroare: Optiune invalida!";
    }
};

class IDInvalidException : public exception {
public:
    const char* what() const noexcept override {
        return "Eroare: ID-ul comenzii nu exista!";
    }
};

#endif