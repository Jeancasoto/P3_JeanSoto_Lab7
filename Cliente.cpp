#include "Usuario.h"
#include "Cliente.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

Cliente::Cliente(){}

Cliente::Cliente(string pNickname, string pPassword, string pNombre, int pEdad, string pId, string pTelefono, string pDireccion, int pFeedback) : Usuario(pNickname, pPassword, pNombre, pEdad, pId, pTelefono){
    nickname=pNickname;
    password=pPassword;
    nombre=pNombre;
    edad=pEdad;
    id=pId;
    telefono=pTelefono;
    direccion=pDireccion;
    feedback=pFeedback;
}

string Cliente::getDireccion(){
    return direccion;
}

int Cliente::getFeedback(){
    return feedback;
}
