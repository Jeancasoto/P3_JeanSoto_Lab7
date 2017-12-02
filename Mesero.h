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
    vector <string> platillos;
    public:
    Mesero();
    Mesero(string,string,string,int,string,string,string,double,vector<string>);

};