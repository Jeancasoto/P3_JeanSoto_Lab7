#include "Usuario.h"
#include "Mesero.h"
#include "Personal.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

Mesero::Mesero(){}

Mesero::~Mesero(){}

Mesero::Mesero(string pNickname, string pPassword, string pNombre, int pEdad, string pId, string pTelefono, string pFecha, double pSueldo, vector<string> pPlatillos) : Personal(pNickname, pPassword, pNombre, pEdad, pId, pTelefono, pFecha, pSueldo){
    nickname=pNickname;
    password=pPassword;
    nombre=pNombre;
    edad=pEdad;
    id=pId;
    telefono=pTelefono;
    fecha=pFecha;
    sueldo=pSueldo;
    platillos=pPlatillos;
    type="M";

}

Mesero::Mesero(string pNickname, string pPassword, string pNombre, int pEdad, string pId, string pTelefono, string pFecha, double pSueldo) : Personal(pNickname, pPassword, pNombre, pEdad, pId, pTelefono, pFecha, pSueldo){
    nickname=pNickname;
    password=pPassword;
    nombre=pNombre;
    edad=pEdad;
    id=pId;
    telefono=pTelefono;
    fecha=pFecha;
    sueldo=pSueldo;
    type="M";

}

string Mesero::getType(){
    return type;
}

string Mesero::escritura(){
    string retVal="";
    retVal+=type+";"+nickname+";"+password+";"+nombre+";";
    retVal+=";"+id+";"+telefono+";";
    retVal+="\n";
    
    return retVal;
}