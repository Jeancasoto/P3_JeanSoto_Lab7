#include <stdlib.h>
#include <iostream>
#include <string>
#include "Usuario.h"
#include "Cliente.h"
#include "Usuario.h"
#include "Chef.h"
#include "Lavaplatos.h"
#include "Administrador.h"
#include "Personal.h"
#include "Mesero.h"
#include <fstream>
#include <cstdlib>

//vector<Usuario*> cargarVector();
void imprimirVector(vector<Usuario*>);
int calificacion(vector<Usuario*>);
void imprimirPosibles_empleados(vector<Usuario*>);
double promedioSueldo(vector<Usuario*>);
void sueldo_Alto(vector<Usuario*>);
void sueldo_Bajo(vector<Usuario*>);

using namespace std;


int main(int argc, char const *argv[]){
    char resp='s';
    vector <Usuario*> usuarios; 
    cout << "|||| ⚔︎Bienvenido a nuestro restaurante⚔︎ ||||"<< endl;
    cout << "    ⍼ ⚙︎⚙︎⚙︎LA ESQUINA DEL VIKINGO⚙︎⚙︎⚙︎ ⍼"<< endl<<endl;
    while(resp=='s' || resp=='S'){
        //ofstream file("Datos.txt");
        //cout << "El archivo debio crearse exitosamente"<<endl;
        MenuPrincipal:
        char mp;
        cout<<"☛ a)LOGIN\n☛ b)CREATE ACCOUNT\n☛ c)LOGIN AS ADMIN\n☛ d)EXIT\n"<<endl;
        cin>>mp;//cin>>menuprincipal
        switch (mp){
            case  'a':{
                string nickname="";
                string password="";
                cout << "Ingrese nickname de usuario"<<endl;
                cin>>nickname;
                cout << "Ingrese password de usuario"<<endl;
                cin>>password;
                
                for(int i = 0; i < usuarios.size(); i++){
                  if(usuarios[i]->getNickname()==nickname){
                      if(usuarios[i]->getPassword()==password){
                          if(usuarios[i]->getType()=="C"){
                            MenuCliente:
                            cout << "➤➤➤➤➤INICIO DE SESION EXITOSO ✔ "<<endl;
                            char accion;
                            cout<< "a)Ver calificacion del restaurante ★ \nb)Salir"<<endl;
                            cin >>accion;
                            switch (accion){
                            case  'a':{
                                int estrellas=0;
                                cout<< "La calificacion promedio del restaurante es: "<<endl;
                                estrellas=calificacion(usuarios);
                                for(int i = 0; i < estrellas; i++){
                                    cout<<"★";
                                }
                                cout<<endl;
                            }
                                break;
                            case  'b':{
                                goto MenuPrincipal;
                            }
                                break;
                                //fin case 'b'
                            default:
                                cout << " ✖︎ La accion que intento no esta contemplada dentro del menu "<<endl;
                                goto MenuCliente;
                                break;
                            }

                          }else{
                              cout << " ✖︎ Algo ocurrio y no se pudo inciar sesion\nAsegurese de iniciar sesion donde corresponde\nasegurese de introducir los datos correctamente"<<endl;
                          }
                      }
                  }

                }
            }
            break;
            //fin case 'a' de menu principal
            case  'b':{
                Agregar:
                char ag;
                cout << "a)Agregar Cliente\nb)Agregar Personal administrativo\n"<<endl;
                cin >>ag;
                switch (ag){
                case 'a':{
                    try{
                        string nickname;
                        string password;
                        string nombre;
                        string edadS;
                        string id;
                        string telefono;
                        string direccion;
                        string feedbackS;
                        int edad;
                        int feedback;
                        cout << "Ingrese su nickname"<<endl;
                        cin>> nickname;
                        cout << "Ingrese su password"<<endl;
                        cin>> password;
                        cout << "Ingrese su nombre"<<endl;
                        getline (cin,nombre);
                        getline (cin,nombre);
                        cout << "Ingrese su edad"<<endl;
                        cin>>edadS;
                        edad=stoi(edadS);
                        if(edad<18 ){
                            throw 99;
                        }
                        if(edad<18){
                            cout<<"Debe tener una edad superior a 18"<<endl;
                            goto MenuPrincipal;

                        }
                        cout << "Ingrese su ID"<<endl;
                        cin>> id;
                        cout << "Ingrese su numero de telefono"<<endl;
                        cin>>telefono;
                        cout << "Ingrese su direccion"<<endl;
                        getline(cin,direccion);
                        getline(cin,direccion);
                        cout << "Ingrese su feedback"<<endl;
                        cin>>feedbackS;
                        feedback=stoi(feedbackS);
                        while(feedback>5){
                            cout<<"Su rating al restaurante debe ser entre 1 - 5 "<<endl;
                            cin>>feedbackS;
                            feedback=stoi(feedbackS);
                        }
                        Usuario* cliente =new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback); 
                        fstream file;
                        //clientes.push_back(new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback));
                        usuarios.push_back(new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback));
                        file.open ("Datos.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                        file << cliente->escritura();
                        cout << "Agrego Cliente exitosamente"<<endl;
                        file.close();
                        
                    }
                    catch (std::invalid_argument){
                        cout << " ✖︎ Querido usuario, no quiera arruinarme el programa, ingreso un dato incorrecto"<<endl;
                    }

                }
                break;
                //fin case 'a' de switch agregar
                case 'b':{
                    Personal:
                    char personal;
                    //cout << "a)Agregar Administrador\nb)Agregar Chef\nc)Agregar Lavaplatos\nd)Agregar Mesero\n"<<endl;
                    cout << "a)Agregar Administrador"<<endl;

                    cin>>personal;
                    if(personal=='b' || personal=='c' || personal=='d'){
                        goto NOENCONTRO;
                    }
                    switch (personal){
                    case 'a':{
                        string nickname;
                        string password;
                        string nombre;
                        string edadS;
                        string id;
                        string telefono;
                        string direccion;
                        string sueldoS;
                        string fecha;
                        int edad;
                        double sueldo;
                        cout << "Ingrese su nickname"<<endl;
                        cin>> nickname;
                        cout << "Ingrese su password"<<endl;
                        cin>> password;
                        cout << "Ingrese su nombre"<<endl;
                        getline (cin,nombre);
                        getline (cin,nombre);
                        cout << "Ingrese su edad"<<endl;
                        cin>>edadS;
                        edad=stoi(edadS);
                        if(edad<18 ){
                            throw 99;
                        }
                        if(edad<18){
                            cout<<"Debe tener una edad superior a 18"<<endl;
                            goto MenuPrincipal;

                        }
                        cout << "Ingrese su ID"<<endl;
                        cin>> id;
                        cout << "Ingrese su numero de telefono"<<endl;
                        cin>>telefono;
                        cout << "Ingrese el ano en el que fue contratado"<<endl;
                        cin>>fecha;
                        cout << "Ingrese sueldo"<<endl;
                        cin>>sueldoS;
                        sueldo=stod(sueldoS);


                        Usuario* admin =new Administrador(nickname,password,nombre,edad,id,telefono,fecha,sueldo); 
                        fstream file;
                        //clientes.push_back(new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback));
                        usuarios.push_back(new Administrador(nickname,password,nombre,edad,id,telefono,fecha,sueldo,0,0));
                        file.open ("Datos.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                        file << admin->escritura();
                        cout << "Agrego Administrador exitosamente"<<endl;
                        file.close();
                        cout << "Le hacemos saber que como administrador , usted puede realizar varias tareas\n como agregar personal o despedir el mismo, ver los salarios de los empleados\nentre otras diversas funciones como administrador, cuando haga login\npodra ver mas a detalle lo que aqui le notificamos"<<endl;


                    }
                    break;
                    //fin case 'a' de agregar personal
                    case 'b':{
                        CHEF:
                        cout << "┼┼┼┼┼AGREGANDO CHEF┼┼┼┼┼"<<endl;
                        string nickname;
                        string password;
                        string nombre;
                        string edadS;
                        string id;
                        string telefono;
                        string direccion;
                        string sueldoS;
                        string fecha;
                        string platillo;
                        int edad;
                        double sueldo;
                        cout << "Ingrese su nickname"<<endl;
                        cin>> nickname;
                        cout << "Ingrese su password"<<endl;
                        cin>> password;
                        cout << "Ingrese su nombre"<<endl;
                        getline (cin,nombre);
                        getline (cin,nombre);
                        cout << "Ingrese su edad"<<endl;
                        cin>>edadS;
                        edad=stoi(edadS);
                        if(edad<18 ){
                            throw 99;
                        }
                        if(edad<18){
                            cout<<"Debe tener una edad superior a 18"<<endl;
                            goto MenuPrincipal;

                        }
                        cout << "Ingrese su ID"<<endl;
                        cin>> id;
                        cout << "Ingrese su numero de telefono"<<endl;
                        cin>>telefono;
                        cout << "Ingrese el ano en el que fue contratado"<<endl;
                        cin>>fecha;
                        cout << "Ingrese sueldo"<<endl;
                        cin>>sueldoS;
                        sueldo=stod(sueldoS);
                        cout << "Ingrese platillo favorito del chef"<<endl;
                        cin>>platillo;
                        


                        Usuario* chef =new Chef(nickname,password,nombre,edad,id,telefono,fecha,sueldo,platillo); 
                        fstream file;
                        //clientes.push_back(new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback));
                        usuarios.push_back(new Chef(nickname,password,nombre,edad,id,telefono,fecha,sueldo,platillo));
                        file.open ("Datos.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                        file << chef->escritura();
                        cout << "Agrego Chef exitosamente"<<endl;
                        cout<<"Le hacemos saber que como chef del restaurante queda bajo su servicio\nlos lavaplatos a los cuales puede adularles por un buen\ntrabajo, o bien reganarlos si no se desenpenan de la forma correcta "<<endl;
                        file.close();
                        //goto ADMINISTRADOR;

                    }
                    break;
                    //fin case 'b' de agregar personal
                    case 'c':{
                        LAVAPLATOS:
                        cout << "┼┼┼┼┼AGREGANDO LAVAPLATOS┼┼┼┼┼"<<endl;
                        string nickname;
                        string password;
                        string nombre;
                        string edadS;
                        string id;
                        string telefono;
                        string direccion;
                        string sueldoS;
                        string fecha;
                        string platillo;
                        int edad;
                        double sueldo;
                        cout << "Ingrese su nickname"<<endl;
                        cin>> nickname;
                        cout << "Ingrese su password"<<endl;
                        cin>> password;
                        cout << "Ingrese su nombre"<<endl;
                        getline (cin,nombre);
                        getline (cin,nombre);
                        cout << "Ingrese su edad"<<endl;
                        cin>>edadS;
                        edad=stoi(edadS);
                        if(edad<18 ){
                            throw 99;
                        }
                        if(edad<18){
                            cout<<"Debe tener una edad superior a 18"<<endl;
                            goto MenuPrincipal;

                        }
                        cout << "Ingrese su ID"<<endl;
                        cin>> id;
                        cout << "Ingrese su numero de telefono"<<endl;
                        cin>>telefono;
                        cout << "Ingrese el ano en el que fue contratado"<<endl;
                        cin>>fecha;
                        cout << "Ingrese sueldo"<<endl;
                        cin>>sueldoS;
                        sueldo=stod(sueldoS);
                        


                        //Usuario* cliente =new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback); 
                        fstream file;
                        //clientes.push_back(new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback));
                        usuarios.push_back(new Lavaplatos(nickname,password,nombre,edad,id,telefono,fecha,sueldo,50));
                        file.open ("Datos.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                        //file << cliente->escritura();
                        cout << "Agrego Lavaplatos exitosamente"<<endl;
                        cout << "Le hacemos saber que como lavaplatos del restaurante usted tiene un nivel\nde motivacion dependiendo en que nivel esta, puede \npedir un aumento o renunciar a su trabajo, su motivacion depende\n de las adulaciones o reganos del chef segun la forma e\n la que se desempena en el trabajo"<<endl;
                        file.close();
                        //goto ADMINISTRADOR;
                    }
                    break;
                    //fin case 'c' de agregar personal
                    case 'd':{
                        MESERO:
                        cout << "┼┼┼┼┼AGREGANDO MESERO┼┼┼┼┼"<<endl;
                        string nickname;
                        string password;
                        string nombre;
                        string edadS;
                        string id;
                        string telefono;
                        string direccion;
                        string sueldoS;
                        string fecha;
                        string platillo;
                        int edad;
                        double sueldo;
                        cout << "Ingrese su nickname"<<endl;
                        cin>> nickname;
                        cout << "Ingrese su password"<<endl;
                        cin>> password;
                        cout << "Ingrese su nombre"<<endl;
                        getline (cin,nombre);
                        getline (cin,nombre);
                        cout << "Ingrese su edad"<<endl;
                        cin>>edadS;
                        edad=stoi(edadS);
                        if(edad<18 ){
                            throw 99;
                        }
                        if(edad<18){
                            cout<<"Debe tener una edad superior a 18"<<endl;
                            goto MenuPrincipal;

                        }
                        cout << "Ingrese su ID"<<endl;
                        cin>> id;
                        cout << "Ingrese su numero de telefono"<<endl;
                        cin>>telefono;
                        cout << "Ingrese el ano en el que fue contratado"<<endl;
                        cin>>fecha;
                        cout << "Ingrese sueldo"<<endl;
                        cin>>sueldoS;
                        sueldo=stod(sueldoS);
                        


                        //Usuario* cliente =new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback); 
                        fstream file;
                        //clientes.push_back(new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback));
                        usuarios.push_back(new Mesero(nickname,password,nombre,edad,id,telefono,fecha,sueldo));
                        file.open ("Datos.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                        //file << cliente->escritura();
                        cout << "Agrego Mesero exitosamente"<<endl;
                        cout << "Le hacemos saber que como mesero de nuestro restaurante , usted tendra una lista\nde platillos por entregar, usted puede decidir\nsi entregarlos todos o uno por uno"<<endl;
                        file.close();
                        //goto ADMINISTRADOR;

                    }
                    break;
                    //fin case 'd' de agregar personal
                    default:
                    NOENCONTRO:
                    cout << "La accion que intento no esta contemplada dentro del menu "<<endl;
                    goto Personal;
                        break;
                    }

                }
                break;
                //fin case 'b' de agregar
                default:
                 cout << "La accion que intento no esta contemplada dentro del menu "<<endl;
                 goto Agregar;
                    break;
                }//fin switch agregar

            }
            break;
            //fin case 'b' de menu principal
            case  'c':{
                string nickname="";
                string password="";
                cout << "Ingrese nickname de usuario"<<endl;
                cin>>nickname;
                cout << "Ingrese password de usuario"<<endl;
                cin>>password;
                
                for(int i = 0; i < usuarios.size(); i++){
                  if(usuarios[i]->getNickname()==nickname){
                      if(usuarios[i]->getPassword()==password){
                          if(usuarios[i]->getType()=="A"){
                            MenuAdmin:
                            cout << "➤➤➤➤➤INICIO DE ADMIN SESION EXITOSO ✔ "<<endl;
                            char accion;
                            cout<< "a)Agregar empleado\nb)Despedir empleado\nc)Listar empleado o empleados con menor sueldo\nd)Listar empleado o empleados con mayor sueldo\ne)Ver promedio sueldo entre los empleados"<<endl;
                            cin >>accion;
                            switch (accion){
                            case  'a':{
                                EMPLEANDO:
                                ADMINISTRADOR:
                                char agregando;
                                cout << "a)Agregar Chef\nb)Agregar Lavaplatos\nc)Agregar Mesero\n"<<endl;
                                cin>>agregando;
                                switch (agregando){
                                case  'a':{
                                    if(dynamic_cast<Administrador*>(usuarios[i])){
                                        dynamic_cast<Administrador*>(usuarios[i])->setEmpleados(1);
                                    }
                                    string admin=dynamic_cast<Administrador*>(usuarios[i])->getNickname();
                                    cout<< admin << " Esta contratando un CHEF , sumaremos 1 a su lista de empleados"<<endl;
                                    goto CHEF;
                                }
                                    break;
                                    //fin case 'a'
                                case  'b':{
                                    if(dynamic_cast<Administrador*>(usuarios[i])){
                                        dynamic_cast<Administrador*>(usuarios[i])->setEmpleados(1);
                                    }
                                    string admin=dynamic_cast<Administrador*>(usuarios[i])->getNickname();
                                    cout<< admin << " Esta contratando un LAVAPLATOS , sumaremos 1 a su lista de empleados"<<endl;
                                    goto LAVAPLATOS;
                                }
                                    break;
                                    //fin case 'b'
                                case  'c':{
                                    if(dynamic_cast<Administrador*>(usuarios[i])){
                                        dynamic_cast<Administrador*>(usuarios[i])->setEmpleados(1);
                                    }
                                    string admin=dynamic_cast<Administrador*>(usuarios[i])->getNickname();
                                    cout<< admin << " Esta contratando un MESERO , sumaremos 1 a su lista de empleados"<<endl;
                                    goto MESERO;
                                }
                                    break;
                                    //fin case 'c'
                                default:
                                    cout << "La accion que intento no esta contemplada dentro del menu "<<endl;
                                    goto EMPLEANDO;
                                    break;
                                }
                               

                            }
                                break;
                                //fin case 'a'
                            case  'b':{//DESPEDIR EMPLEADO
                                
                                
                                
                            }
                                break;
                                //fin case 'b'
                            case  'c':{//MENOR SUELDO
                                 sueldo_Bajo(usuarios);
                                
                            }
                                break;
                                //fin case 'c'
                            case  'd':{//MAYOR SUELDO
                                sueldo_Alto(usuarios);
                                
                            }
                                break;
                                //fin case 'd'
                            case  'e':{//PROMEDIO 
                                double promedio=promedioSueldo(usuarios); 
                                cout << "El salario promedio entre los empleados es de:  "<<promedio<<endl;

                            }
                                break;
                                //fin case 'e'
                            default:
                                cout << " ✖︎ La accion que intento no esta contemplada dentro del menu "<<endl;
                                goto MenuAdmin;
                                break;
                            }

                          }else{
                              cout << " ✖︎ Algo ocurrio y no se pudo inciar sesion\nAsegurese de iniciar sesion donde corresponde\nasegurese de introducir los datos correctamente"<<endl;
                          }
                      }else{
                              cout << " ✖︎ Algo ocurrio y no se pudo inciar sesion\nAsegurese de iniciar sesion donde corresponde\nasegurese de introducir los datos correctamente"<<endl;
                    }
                  }

                }
                
                
            }
            break;
            //fin case 'c' de menu principal
            case  'd':{
                cout << "Esperamos vuelva pronto"<<endl;
                resp='n';
            }
            break;
            //fin case 'd' de menu principal
        default:
            cout << "La accion que intento no esta contemplada dentro del menu "<<endl;
            goto MenuPrincipal;
            break;
        }//fin switch del menu principal
        
        
    }//fin while con respuesta de usuario
    for(int i = 0; i < usuarios.size(); i++){
        delete usuarios[i];
    }
    cout<< "Se limpio exitosamente la memoria"<<endl;
    
    return 0;
}//fin main;

// vector<Usuario*> cargarVector(){
//     vector <Usuario*> usuarios;
    
//     return usuarios;
// }

void imprimirVector(vector<Usuario*> usuarios){
    for(int i = 0; i < usuarios.size(); i++){
        if(dynamic_cast<Chef*>(usuarios[i])){
            string x =dynamic_cast<Cliente*>(usuarios[i])->getNickname();
            cout << x;
        }
    }
    

}

int calificacion(vector<Usuario*> users){
    int cont=0;
    int acum=0;
    int res=0;
    for(int i = 0; i < users.size(); i++){
        if(dynamic_cast<Cliente*>(users[i])){
            acum+= dynamic_cast<Cliente*>(users[i])->getFeedback();
            cont++;
        }
    }
    
    if(acum>0){
        res=acum/cont;
    }
    
    return res;
}

void imprimirPosibles_empleados(vector<Usuario*> gente){
    for(int i = 0; i < gente.size(); i++){
        cout<<"PENE"<<endl;
        if(dynamic_cast<Chef*>(gente[i])->getType()=="CH"){
           cout<<"TRUE"<<endl;
            string x= dynamic_cast<Chef*>(gente[i])->getNickname();
            cout << x;
        }else{
            cout<<"AJABER"<<endl;
        }
        
        
    }
    

}

double promedioSueldo(vector<Usuario*> users){
    int cont=0;
    double acum=0;
    double res=0;
    for(int i = 0; i < users.size(); i++){
        if(dynamic_cast<Mesero*>(users[i])){
            acum+= dynamic_cast<Mesero*>(users[i])->getSueldo();
            cont++;
        }
        if(dynamic_cast<Lavaplatos*>(users[i])){
            acum+= dynamic_cast<Lavaplatos*>(users[i])->getSueldo();
            cont++;
        }
        if(dynamic_cast<Chef*>(users[i])){
            acum+= dynamic_cast<Chef*>(users[i])->getSueldo();
            cont++;
        }
    }
    
    if(acum>0){
        res=acum/cont;
    }
    
    return res;
}

void sueldo_Alto(vector<Usuario*> users){
    double mayor=0;
    double tempo=0;
    double res=0;
    for(int i = 0; i < users.size(); i++){
         if(dynamic_cast<Personal*>(users[i])->getType()!="A"){
            mayor= dynamic_cast<Personal*>(users[i])->getSueldo();
        }
    }
    
    for(int i = 0; i < users.size(); i++){
        if(dynamic_cast<Personal*>(users[i])->getType()!="A"){
               tempo= dynamic_cast<Personal*>(users[i])->getSueldo();
                if(tempo>mayor){
                    mayor=tempo;
                }
            } 
    }
    for(int i = 0; i < users.size(); i++){ 
        if(dynamic_cast<Personal*>(users[i])->getSueldo()==mayor){
            //if(dynamic_cast<Personal*>(users[i])->getType()!="A"){
                cout << "Empleado(s) con el sueldo mas alto"<<endl;
                cout << "El empleado: "<<dynamic_cast<Personal*>(users[i])->getNombre()<<endl;;
                cout << "Con un sueldo de: "<<dynamic_cast<Personal*>(users[i])->getSueldo()<<endl;

            //}
        }
    }
}

void sueldo_Bajo(vector<Usuario*> users){
    double menor=0;
    double tempo=0;
    double res=0;
    for(int i = 0; i < users.size(); i++){
         if(dynamic_cast<Personal*>(users[i])->getType()!="A"){
            menor= dynamic_cast<Personal*>(users[i])->getSueldo();
        }
    }
    
    for(int i = 0; i < users.size(); i++){
        if(dynamic_cast<Personal*>(users[i])->getType()!="A"){
               tempo= dynamic_cast<Personal*>(users[i])->getSueldo();
                if(tempo<menor){
                    menor=tempo;
                }
            } 
    }
    for(int i = 0; i < users.size(); i++){ 
        if(dynamic_cast<Personal*>(users[i])->getSueldo()==menor){
            //if(dynamic_cast<Personal*>(users[i])->getType()!="A"){
                cout << "Empleado(s) con el sueldo mas alto"<<endl;
                cout << "El empleado: "<<dynamic_cast<Personal*>(users[i])->getNombre()<<endl;;
                cout << "Con un sueldo de: "<<dynamic_cast<Personal*>(users[i])->getSueldo()<<endl;

            //}
        }
    }
}