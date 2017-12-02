#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]){
    char resp='s';
    cout << "Bienvenido a nuestro restaurante"<< endl;
    while(resp=='s' || resp=='S'){
        MenuPrincipal:
        char mp;
        cout<<"a)LOGIN\nb)CREATE ACCOUNT\nc)EXIT\n"<<endl;
        cin>>mp;//cin>>menuprincipal
        switch (mp){
            case  'a':{
                string nickname="";
                string password="";
                cout << "Ingrese nickname de usuario"<<endl;
                cin>>nickname;
                cout << "Ingrese password de usuario"<<endl;
                cin>>password;
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

                    }
                    break;
                    //fin case 'a' de agregar personal
                    case 'b':{

                    }
                    break;
                    //fin case 'b' de agregar personal
                    case 'c':{

                    }
                    break;
                    //fin case 'c' de agregar personal
                    case 'd':{

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
                cout << "Esperamos vuelva pronto"<<endl;
                resp='n';
            }
            break;
            //fin case 'c' de menu principal
        default:
            cout << "La accion que intento no esta contemplada dentro del menu "<<endl;
            goto MenuPrincipal;
            break;
        }//fin switch del menu principal
        

    }//fin while con respuesta de usuario
    return 0;
}//fin main;


