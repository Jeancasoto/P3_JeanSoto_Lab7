#pragma once 
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Usuario.h"
#include "Personal.h"

using namespace std;

class Lavaplatos : public Personal{
    protected:
    int motivacion;
    string type;
    public:
    virtual~Lavaplatos();
    Lavaplatos();
    Lavaplatos(string,string,string,int,string,string,string,double,int);
    int getMotivacion();
    void setMotivacionP(int);
    void setSueldo(double);
    void setMotivacionN(int);
    virtual string getType();
    virtual string escritura();
};