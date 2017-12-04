#pragma once 
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "Usuario.h"
#include "Personal.h"

using namespace std;

class Mesero : public Personal{
    protected:
    int platillos;
    public:
    virtual~Mesero();
    Mesero();
    Mesero(string,string,string,int,string,string,string,double);
    Mesero(string,string,string,int,string,string,string,double,int);
    int getPlatillos();
    void setPlatillos(int);
    virtual string getType();
    virtual string escritura();
};