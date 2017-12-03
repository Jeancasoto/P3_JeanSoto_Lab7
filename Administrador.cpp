#include <stdlib.h>
#include <iostream>
#include <string>
#include "Usuario.h"
#include "Personal.h"
#include "Administrador.h"
#include <vector>

using namespace std;

Administrador::Administrador(){}

Administrador::~Administrador(){}

Administrador::Administrador(string pNickname, string pPassword, string pNombre, int pEdad, string pId, string pTelefono, string pFecha, double pSueldo, vector <Personal*> pEmpleados, vector <Personal*> pDesempleados) : Personal(pNickname, pPassword, pNombre, pEdad, pId, pTelefono, pFecha, pSueldo){
    nickname=pNickname;
    password=pPassword;
    nombre=pNombre;
    edad=pEdad;
    id=pId;
    telefono=pTelefono;
    fecha=pFecha;
    sueldo=pSueldo;
    empleados=pEmpleados;
    desempleados=pDesempleados;

}

Administrador::Administrador(string pNickname, string pPassword, string pNombre, int pEdad, string pId, string pTelefono, string pFecha, double pSueldo) : Personal(pNickname, pPassword, pNombre, pEdad, pId, pTelefono, pFecha, pSueldo){
    nickname=pNickname;
    password=pPassword;
    nombre=pNombre;
    edad=pEdad;
    id=pId;
    telefono=pTelefono;
    fecha=pFecha;
    sueldo=pSueldo;
    type="A";

}

string Administrador::getType(){
    return type;
}

string Administrador::escritura(){
    string retVal="";
    retVal+=type+";"+nickname+";"+password+";"+nombre+";";
    retVal+=";"+id+";"+telefono+";";
    retVal+="\n";
    
    return retVal;
}