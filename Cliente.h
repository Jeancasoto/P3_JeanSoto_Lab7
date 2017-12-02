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
    public:
    Cliente();
    Cliente(string,string,string,int,string,string,string,int);
    string getDireccion();
    int getFeedback();

};