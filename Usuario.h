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
virtual~Usuario();
Usuario(string,string,string,int,string,string);
string getNickname();
string getPassword();
string getNombre();
int getEdad();
string getId();
string getTelefono();
virtual string getType();
virtual string escritura();
friend class Usuario;
friend class Chef;
friend class Lavaplatos;
friend class Mesero;
friend class Administrador;
friend class Personal;
friend class Cliente;



};