#include "Usuario.h"
#include "Chef.h"
#include "Personal.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

Chef::Chef(){}

Chef::Chef(string pNickname, string pPassword, string pNombre, int pEdad, string pId, string pTelefono, string pFecha, double pSueldo, string pPlatilloFav) : Personal(pNickname, pPassword, pNombre, pEdad, pId, pTelefono, pFecha, pSueldo){
    nickname=pNickname;
    password=pPassword;
    nombre=pNombre;
    edad=pEdad;
    id=pId;
    telefono=pTelefono;
    fecha=pFecha;
    sueldo=pSueldo;
    gritar=50;
    adular=50;

}

string Chef::getPlatilloFav(){
    return platilloFav;
}

int Chef::getGritar(){
    return gritar;
}

int Chef::getAdular(){
    return adular;
}