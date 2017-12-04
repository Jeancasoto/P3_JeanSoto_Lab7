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

Administrador::Administrador(string pNickname, string pPassword, string pNombre, int pEdad, string pId, string pTelefono, string pFecha, double pSueldo, int pEmpleados, int pDesempleados) : Personal(pNickname, pPassword, pNombre, pEdad, pId, pTelefono, pFecha, pSueldo){
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
    type="A";

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
    string edadS= to_string(edad);
    string sueldoS =to_string(sueldo);
    string empleadosS=to_string(empleados);
    string desempleadosS=to_string(desempleados);
    string retVal="";
    retVal+=type+";"+nickname+";"+password+";"+nombre+";";
    retVal+=edadS;
    retVal+=";"+id+";"+telefono+";"+fecha+";"+sueldoS+";"+empleadosS+";"+desempleadosS;
    retVal+="\n";
    
    return retVal;
}

int Administrador::getEmpleados(){
    return empleados;
}

int Administrador::getDesempleados(){
    return desempleados;
}

void Administrador::setEmpleados(int x){
        empleados+=x;
}

void Administrador::setDesempleados(int y){
        empleados+=y;
}