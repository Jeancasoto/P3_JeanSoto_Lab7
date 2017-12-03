#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Usuario{

protected:
string nickname;
string password;
string nombre;
int edad;
string id;
string telefono;

public:
Usuario();
Usuario(string,string,string,int,string,string);
string getNickname();
string getPassword();
string getNombre();
int getEdad();
string getId();
string getTelefono();
virtual string getType();
virtual string escritura();


};