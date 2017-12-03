#include "Usuario.h"
#include "Personal.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

Personal::Personal(){}

Personal::~Personal(){}

Personal::Personal(string pNickname, string pPassword, string pNombre, int pEdad, string pId, string pTelefono, string pFecha, double pSueldo) : Usuario(pNickname, pPassword, pNombre, pEdad, pId, pTelefono){
    nickname=pNickname;
    password=pPassword;
    nombre=pNombre;
    edad=pEdad;
    id=pId;
    telefono=pTelefono;
    fecha=pFecha;
    sueldo=pSueldo;
    type="P";
}

string Personal::getFecha(){
    return fecha;
}

double Personal::getSueldo(){
    return sueldo;
}

string Personal::getType(){
    return "A";
}

string Personal::escritura(){
    string retVal="";
    retVal+=type+";"+nickname+";"+password+";"+nombre+";";
    retVal+=";"+id+";"+telefono+";";
    retVal+="\n";
    
    return retVal;
}