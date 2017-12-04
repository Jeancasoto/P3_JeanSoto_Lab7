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
void Lavaplatos::setMotivacionN(int x){
    motivacion= motivacion-x;
}

void Lavaplatos::setMotivacionP(int x){
    motivacion= motivacion+x;
}

void Lavaplatos::setSueldo(double d){
    sueldo= sueldo+d;
}

string Lavaplatos::escritura(){
    string edadS= to_string(edad);
    string sueldoS =to_string(sueldo);
    string motivacionS =to_string(motivacion);
    string retVal="";
    retVal+=type+";"+nickname+";"+password+";"+nombre+";";
    retVal+=edadS;
    retVal+=";"+id+";"+telefono+";"+fecha+";"+sueldoS+";"+motivacionS;
    retVal+="\n";
    
    return retVal;
}
