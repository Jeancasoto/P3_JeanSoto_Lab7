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
                cout << "a)Agregar Cliente\nb)Agregar Personal\n"<<endl;
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
                    cout << "a)Agregar Administrador\nb)Agregar Chef\nc)Agregar Lavaplatos\nd)Agregar Mesero\n"<<endl;
                    cin>>personal;
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


                        //Usuario* cliente =new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback); 
                        fstream file;
                        //clientes.push_back(new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback));
                        usuarios.push_back(new Administrador(nickname,password,nombre,edad,id,telefono,fecha,sueldo));
                        file.open ("Datos.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                        //file << cliente->escritura();
                        cout << "Agrego Administrador exitosamente"<<endl;
                        file.close();
                        cout << "Le recordamos que como cliente puede inciar sesion\ny ver la cantidad de estrellas de nuestro \nrestaurante segun la valoracion que han dado nuestros clientes"<<endl;


                    }
                    break;
                    //fin case 'a' de agregar personal
                    case 'b':{
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
                        


                        //Usuario* cliente =new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback); 
                        fstream file;
                        //clientes.push_back(new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback));
                        usuarios.push_back(new Chef(nickname,password,nombre,edad,id,telefono,fecha,sueldo,platillo));
                        file.open ("Datos.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                        //file << cliente->escritura();
                        cout << "Agrego Chef exitosamente"<<endl;
                        cout<<"Le hacemos saber que como chef del restaurante queda bajo su servicio\nlos lavaplatos a los cuales puede adularles por un buen\ntrabajo, o bien reganarlos si no se desenpenan de la forma correcta "<<endl;
                        file.close();

                    }
                    break;
                    //fin case 'b' de agregar personal
                    case 'c':{
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

                    }
                    break;
                    //fin case 'c' de agregar personal
                    case 'd':{
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

                    }
                    break;
                    //fin case 'd' de agregar personal
                    default:
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
                imprimirVector(usuarios);

                // ifstream reader("Datos.txt");
                // string antes;
                // reader>>antes;
                // cout<<antes<<endl;
                // string despues="----- ";
                // ofstream writer("Datos.txt");
                
                // writer<<antes+despues<<endl;
                // writer<<"\n";

                // reader.close();

                // ifstream reader ("Datos.txt");
                // if(reader.is_open()){
                //     string nombre;
                //     getline(reader,nombre,',');
                //     string password;
                //     string apellido;
                //     getline(reader,apellido,',');
                //     string edad;
                //     cout << "nombre "<<nombre <<endl;
                //     cout << "password "<<password <<endl;
                //     cout << "apellido "<<apellido <<endl;
                //     cout << "edad "<<edad <<endl;

                // }
                
                
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
    return 0;
}//fin main;

// vector<Usuario*> cargarVector(){
//     vector <Usuario*> usuarios;
    
//     return usuarios;
// }

void imprimirVector(vector<Usuario*> usuarios){
    for(int i = 0; i < usuarios.size(); i++){
        if(dynamic_cast<Cliente*>(usuarios[i])){
            int x =dynamic_cast<Cliente*>(usuarios[i])->getFeedback();
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