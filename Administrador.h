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
    public:
    Administrador();
    Administrador(string,string,string,int,string,string,string,double,vector<Personal*>,vector<Personal*>);
    
};