#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Usuario.h"

using namespace std;

class Cliente : public Usuario{
    protected:
    string direccion;
    int feedback;
    string type;
    public:
    Cliente();
    Cliente(string,string,string,int,string,string,string,int);
    string getDireccion();
    int getFeedback();
    virtual string getType();
    virtual string escritura();


};