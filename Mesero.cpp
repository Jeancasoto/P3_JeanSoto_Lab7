#include "Usuario.h"
#include "Mesero.h"
#include "Personal.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

Mesero::Mesero(){}

Mesero::~Mesero(){}

Mesero::Mesero(string pNickname, string pPassword, string pNombre, int pEdad, string pId, string pTelefono, string pFecha, double pSueldo, int pPlatillos) : Personal(pNickname, pPassword, pNombre, pEdad, pId, pTelefono, pFecha, pSueldo){
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

int Mesero::getPlatillos(){
    return platillos;
}
string Mesero::getType(){
    return type;
}

void Mesero::setPlatillos(int p){
    platillos=platillos-p;
}

string Mesero::escritura(){
    string edadS= to_string(edad);
    string sueldoS =to_string(sueldo);
    string platillosS =to_string(platillos);
    string retVal="";
    retVal+=type+";"+nickname+";"+password+";"+nombre+";";
    retVal+=edadS;
    retVal+=";"+id+";"+telefono+";"+fecha+";"+sueldoS+";"+platillosS;
    retVal+="\n";
    
    return retVal;
}