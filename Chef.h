#pragma once 
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Usuario.h"
#include "Personal.h"

using namespace std;

class Chef : public Personal {
    private:
    string platilloFav;
    int gritar;
    int adular;
    string type;
    public:
    Chef();
    Chef(string,string,string,int,string,string,string,double,string);
    string getPlatilloFav();
    int getGritar();
    int getAdular();
    virtual string getType();

    
};