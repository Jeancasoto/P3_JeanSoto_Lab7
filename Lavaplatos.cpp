#include "Usuario.h"
#include "Lavaplatos.h"
#include "Personal.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

Lavaplatos::Lavaplatos(){}

Lavaplatos::~Lavaplatos(){}

Lavaplatos::Lavaplatos(string pNickname, string pPassword, string pNombre, int pEdad, string pId, string pTelefono, string pFecha, double pSueldo, int pMotivacion) : Personal(pNickname, pPassword, pNombre, pEdad, pId, pTelefono, pFecha, pSueldo){
    nickname=pNickname;
    password=pPassword;
    nombre=pNombre;
    edad=pEdad;
    id=pId;
    telefono=pTelefono;
    fecha=pFecha;
    sueldo=pSueldo;
    motivacion=50;
    type="L";

}

int Lavaplatos::getMotivacion(){
    return motivacion;
}
string Lavaplatos::getType(){
    return type;
}

string Lavaplatos::escritura(){
    string retVal="";
    retVal+=type+";"+nickname+";"+password+";"+nombre+";";
    retVal+=";"+id+";"+telefono+";";
    retVal+="\n";
    
    return retVal;
}
