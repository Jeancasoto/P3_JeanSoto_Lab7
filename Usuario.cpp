#include "Usuario.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

Usuario::Usuario(){}

Usuario::Usuario(string pNickname, string pPassword, string pNombre, int pEdad, string pId, string pTelefono){
    nickname=pNickname;
    password=pPassword;
    nombre=pNombre;
    edad=pEdad;
    id=pId;
    telefono=pTelefono;
}

string Usuario::getNickname(){
    return nickname;
}

string Usuario::getPassword(){
    return password;
}

string Usuario::getNombre(){
    return nombre;
}

int Usuario::getEdad(){
    return edad;
}

string Usuario::getId(){
    return id;
}

string Usuario::getTelefono(){
    return telefono;
}

string Usuario::getType(){
    return "UNDEFINED";
}

string Usuario::escritura(){
    string retVal="";
    // retVal+=type+";"+nickname+";"+password+";"+nombre+";";
    // retVal+=edad;
    // retVal+=";"+id+";"+telefono+";"+direccion+";";
    // retVal+=feedback;
    // retVal+="\n";
    
    return retVal;
}