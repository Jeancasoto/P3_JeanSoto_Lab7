#include "Usuario.h"
#include "Cliente.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

Cliente::Cliente(){}

Cliente::~Cliente(){}

Cliente::Cliente(string pNickname, string pPassword, string pNombre, int pEdad, string pId, string pTelefono, string pDireccion, int pFeedback) : Usuario(pNickname, pPassword, pNombre, pEdad, pId, pTelefono){
    nickname=pNickname;
    password=pPassword;
    nombre=pNombre;
    edad=pEdad;
    id=pId;
    telefono=pTelefono;
    direccion=pDireccion;
    feedback=pFeedback;
    type="C";
}

string Cliente::getDireccion(){
    return direccion;
}

int Cliente::getFeedback(){
    return feedback;
}


string Cliente::getType(){
    return type;
}

string Cliente::escritura(){
    string edadS= to_string(edad);
    string feedbackS= to_string(feedback);
    string retVal="";
    retVal+=type+";"+nickname+";"+password+";"+nombre+";";
    retVal+=edadS;
    retVal+=";"+id+";"+telefono+";"+direccion+";";
    retVal+=feedbackS;
    retVal+="\n";
    
    return retVal;
}

