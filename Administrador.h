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
    int empleados;
    int desempleados;
    string type;
    public:
    virtual~Administrador();
    Administrador();
    Administrador(string,string,string,int,string,string,string,double);
    Administrador(string,string,string,int,string,string,string,double,int,int);
    virtual string getType();
    virtual string escritura();
    int getEmpleados();
    int getDesempleados();
    void setEmpleados(int);
    void setDesempleados(int);
    
};