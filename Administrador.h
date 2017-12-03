#pragma once 
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Usuario.h"
#include "Personal.h"
#include <vector>

using namespace std;

class Administrador : public Personal{
    protected:
    vector <Personal*> empleados;
    vector <Personal*> desempleados;
    string type;
    public:
    virtual~Administrador();
    Administrador();
    Administrador(string,string,string,int,string,string,string,double);
    Administrador(string,string,string,int,string,string,string,double,vector<Personal*>,vector<Personal*>);
    virtual string getType();
    virtual string escritura();
    
};