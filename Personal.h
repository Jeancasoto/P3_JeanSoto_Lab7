#pragma once 
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Usuario.h"

using namespace std;

class Personal : public Usuario{
    protected:
    string fecha;
    double sueldo;
    string type;
    public:
    Personal();
    virtual~Personal();
    Personal(string,string,string,int,string,string,string,double);
    string getFecha();
    double getSueldo();
    virtual string getType();
    virtual string escritura();
};