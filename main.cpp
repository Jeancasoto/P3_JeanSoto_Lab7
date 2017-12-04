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
void imprimirVector(vector<Usuario *>);
int calificacion(vector<Usuario *>);
//void imprimirPosibles_empleados(vector<Usuario*>);
double promedioSueldo(vector<Usuario *>);
void sueldo_Alto(vector<Usuario *>);
void sueldo_Bajo(vector<Usuario *>);
void Sobrestritura(vector<Usuario *>);
vector<Usuario *> cargar();
//vector<Usuario*> leer();

using namespace std;

int main(int argc, char const *argv[])
{
    char resp = 's';
    vector<Usuario *> usuarios;
    cout << "|||| ⚔︎Bienvenido a nuestro restaurante⚔︎ ||||" << endl;
    cout << "    ⍼ ⚙︎⚙︎⚙︎LA ESQUINA DEL VIKINGO⚙︎⚙︎⚙︎ ⍼" << endl
         << endl;
    usuarios = cargar();
    while (resp == 's' || resp == 'S')
    {
    //ofstream file("Datos.txt");
    //cout << "El archivo debio crearse exitosamente"<<endl;
    MenuPrincipal:
        char mp;
        cout << "☛ a)LOGIN\n☛ b)CREATE ACCOUNT\n☛ c)LOGIN AS ADMIN\n☛ d)EXIT\n"
             << endl;
        cin >> mp; //cin>>menuprincipal
        switch (mp)
        {
        case 'a':
        {
            char login;
            cout << "a)Login as Client\nb)Login as Chef\nc)Login as Dishwasher\nd)Login as waiter" << endl;
            cin >> login;
            switch (login)
            {
            case 'a':
            {
                string nickname = "";
                string password = "";
                cout << "Ingrese nickname de usuario" << endl;
                cin >> nickname;
                cout << "Ingrese password de usuario" << endl;
                cin >> password;

                for (int i = 0; i < usuarios.size(); i++)
                {
                    if (usuarios[i]->getNickname() == nickname)
                    {
                        if (usuarios[i]->getPassword() == password)
                        {
                            if (usuarios[i]->getType() == "C")
                            {
                            MenuCliente:
                                cout << "➤➤➤➤➤INICIO DE SESION EXITOSO ✔ " << endl;
                                char accion;
                                cout << "a)Ver calificacion del restaurante ★ \nb)Salir" << endl;
                                cin >> accion;
                                switch (accion)
                                {
                                case 'a':
                                {
                                    int estrellas = 0;
                                    cout << "La calificacion promedio del restaurante es: " << endl;
                                    estrellas = calificacion(usuarios);
                                    for (int i = 0; i < estrellas; i++)
                                    {
                                        cout << "★";
                                    }
                                    cout << endl;
                                }
                                break;
                                case 'b':
                                {
                                    goto MenuPrincipal;
                                }
                                break;
                                    //fin case 'b'
                                default:
                                    cout << " ✖︎ La accion que intento no esta contemplada dentro del menu " << endl;
                                    goto MenuCliente;
                                    break;
                                }
                            }
                            else
                            {
                                cout << " ✖︎ Algo ocurrio y no se pudo inciar sesion\nAsegurese de iniciar sesion donde corresponde\nasegurese de introducir los datos correctamente" << endl;
                            }
                        }
                    }
                }
            }
            break;
                //fin case 'a'
            case 'b':
            { //chef
                string nickname = "";
                string password = "";
                cout << "Ingrese nickname de usuario" << endl;
                cin >> nickname;
                cout << "Ingrese password de usuario" << endl;
                cin >> password;

                for (int i = 0; i < usuarios.size(); i++)
                {
                    if (usuarios[i]->getNickname() == nickname)
                    {
                        if (usuarios[i]->getPassword() == password)
                        {
                            if (usuarios[i]->getType() == "CH")
                            {
                            MenuChef:
                                cout << "➤➤➤➤➤INICIO DE SESION EXITOSO ✔ " << endl;
                                cout << "|||||BIENVENIDO CHEF " << nickname << "|||||" << endl;
                                cout << "Se le recuerda que como chef del restaurante usted puede llamar la atencion del personal\npor mal desempeno o felicitarlos por buen desempeno, ellos inician con\n una motivacion en 50, si les llama la atencion bajara en 25 pts\ny si los felicita la misma subira en 25 pts" << endl;
                                char accion;
                                cout << "a)Revisar Platillo favorito\nb)Llamar la atencion a un lavaplatos\nc)Felicitar por buen trabajo a un lavaplatos\nd)Salir" << endl;
                                cin >> accion;
                                switch (accion)
                                {
                                case 'a':
                                {
                                    cout << "El platillo Favorito del Chef es:  " << dynamic_cast<Chef *>(usuarios[i])->getPlatilloFav() << endl;
                                }
                                break;
                                    //fin case 'a'
                                case 'b':
                                {
                                    cout << "Ingrese el nombre del empleado al que desea llamar la atencion por mal desempeno?" << endl;
                                    string llamado;
                                    //int cont=0;
                                    for (int i = 0; i < usuarios.size(); i++)
                                    {
                                        if (dynamic_cast<Personal *>(usuarios[i])->getType() == "L")
                                        {
                                            cout << dynamic_cast<Personal *>(usuarios[i])->getNombre() << endl;
                                            //cont++;
                                        }
                                    }
                                    cout << "---Fin de la lista---" << endl;
                                    cin >> llamado;
                                    for (int i = 0; i < usuarios.size(); i++)
                                    {
                                        if (dynamic_cast<Personal *>(usuarios[i])->getType() == "L")
                                        {
                                            if (dynamic_cast<Personal *>(usuarios[i])->getNombre() == llamado)
                                            {
                                                cout << "Motivacion antes de llamarle la atencion" << dynamic_cast<Lavaplatos *>(usuarios[i])->getMotivacion() << endl;
                                                dynamic_cast<Lavaplatos *>(usuarios[i])->setMotivacionN(25);
                                                cout << "Se llamo la atencion del empleado exitosamente" << endl;
                                                cout << "Motivacion despues de llamarle la atencion" << dynamic_cast<Lavaplatos *>(usuarios[i])->getMotivacion() << endl;
                                            }
                                        }
                                    }
                                }
                                break;
                                    //fin case 'b'
                                case 'c':
                                {
                                    cout << "Ingrese el nombre del empleado al que desea felicitar por buen desempeno?" << endl;
                                    string felicitar;
                                    //int cont=0;
                                    for (int i = 0; i < usuarios.size(); i++)
                                    {
                                        if (dynamic_cast<Personal *>(usuarios[i])->getType() == "L")
                                        {
                                            cout << dynamic_cast<Personal *>(usuarios[i])->getNombre();
                                            //cont++;
                                        }
                                    }
                                    cout << "---Fin de la lista---" << endl;
                                    cin >> felicitar;
                                    for (int i = 0; i < usuarios.size(); i++)
                                    {
                                        if (dynamic_cast<Personal *>(usuarios[i])->getType() == "L")
                                        {
                                            if (dynamic_cast<Personal *>(usuarios[i])->getNombre() == felicitar)
                                            {
                                                cout << "Motivacion antes de felicitarlo" << dynamic_cast<Lavaplatos *>(usuarios[i])->getMotivacion() << endl;
                                                dynamic_cast<Lavaplatos *>(usuarios[i])->setMotivacionP(25);
                                                cout << "Se ha felicitado al empleado exitosamente" << endl;
                                                cout << "Motivacion despues de felicitarlo" << dynamic_cast<Lavaplatos *>(usuarios[i])->getMotivacion() << endl;
                                            }
                                        }
                                    }
                                }
                                break;
                                    //fin case 'c'
                                case 'd':
                                {
                                    goto MenuPrincipal;
                                }
                                break;
                                    //fin case 'd'
                                default:
                                    cout << " ✖︎ La accion que intento no esta contemplada dentro del menu " << endl;
                                    goto MenuChef;
                                    break;
                                }
                                goto MenuChef;
                            }
                            else
                            {
                                cout << " ✖︎ Algo ocurrio y no se pudo inciar sesion\nAsegurese de iniciar sesion donde corresponde\nasegurese de introducir los datos correctamente" << endl;
                            }
                        }
                    }
                }
            }
            break;
                //fin case 'b'
            case 'c':
            { //lavaplatos
                string nickname = "";
                string password = "";
                cout << "Ingrese nickname de usuario" << endl;
                cin >> nickname;
                cout << "Ingrese password de usuario" << endl;
                cin >> password;

                for (int i = 0; i < usuarios.size(); i++)
                {
                    if (usuarios[i]->getNickname() == nickname)
                    {
                        if (usuarios[i]->getPassword() == password)
                        {
                            if (usuarios[i]->getType() == "L")
                            {
                            MenuLavaplatos:
                                cout << "➤➤➤➤➤INICIO DE SESION EXITOSO ✔ " << endl;
                                cout << "|||||BIENVENIDO LAVAPLATOS " << nickname << "|||||" << endl;
                                cout << "Como lavaplatos del restaurante le recordamos que usted tiene un nivel de motivacion que se ve\nreflejado atravez de su desempeno, dicho esto se le informa que si su\nmotivacion es mayor o igual a 100 puede pedir un aumento, de una cantidad\nno mayor a su actual salario, mientras que si su motivacion se encuentra igual o menor a 25\npuede decidir renunciar al trabajo" << endl;
                                char opcion;
                                cout << "a)Ver mi motivacion\nb)Pedir un aumento\nc)Renunciar\nd)Salir" << endl;
                                cin >> opcion;
                                switch (opcion)
                                {
                                case 'a':
                                {
                                    cout << "Su motivacion actualmente se encuentra en: " << dynamic_cast<Lavaplatos *>(usuarios[i])->getMotivacion() << endl;
                                }
                                break;
                                    //fin case 'a'
                                case 'b':
                                {
                                    double aumento;
                                    int x = dynamic_cast<Lavaplatos *>(usuarios[i])->getMotivacion();
                                    if (x >= 100)
                                    {
                                        cout << "Su sueldo actualmente es de: " << dynamic_cast<Lavaplatos *>(usuarios[i])->getSueldo() << endl;
                                        cout << "Ingrese lo que pide de aumeno" << endl;
                                        cin >> aumento;
                                        while (aumento >= dynamic_cast<Lavaplatos *>(usuarios[i])->getSueldo())
                                        {
                                            cout << "Su aumento no puede ser mayor al salario actual, cifras mas pequenas!" << endl;
                                            cin >> aumento;
                                        }
                                        dynamic_cast<Lavaplatos *>(usuarios[i])->setSueldo(aumento);
                                        cout << "Su sueldo despues del aumento es de: " << dynamic_cast<Lavaplatos *>(usuarios[i])->getSueldo();
                                    }
                                    else
                                    {
                                        cout << "Actualmente no puede optar por un aumento" << endl;
                                    }
                                }
                                break;
                                    //fin case 'b'
                                case 'c':
                                {
                                    int x = dynamic_cast<Lavaplatos *>(usuarios[i])->getMotivacion();
                                    if (x <= 25)
                                    {
                                        cout << "Le deseamos lo mejor, gracias por laborar para nosotros, Hasta la proxima!" << endl;
                                    }
                                    else
                                    {
                                        cout << "Actualmente no creemos que deba renunciar, tenemos grandes planes para usted!" << endl;
                                    }
                                }
                                break;
                                    //fin case 'c'
                                case 'd':
                                {
                                    goto MenuPrincipal;
                                }
                                break;
                                    //fin case 'd'
                                default:
                                    cout << " ✖︎ La accion que intento no esta contemplada dentro del menu " << endl;
                                    goto MenuLavaplatos;
                                    break;

                                    break;
                                } //fin switch
                                goto MenuLavaplatos;
                            }
                        }
                    }
                }
            }
            break;
                //fin case 'b'
            case 'd':
            { //mesero
                string nickname = "";
                string password = "";
                cout << "Ingrese nickname de usuario" << endl;
                cin >> nickname;
                cout << "Ingrese password de usuario" << endl;
                cin >> password;

                for (int i = 0; i < usuarios.size(); i++)
                {
                    if (usuarios[i]->getNickname() == nickname)
                    {
                        if (usuarios[i]->getPassword() == password)
                        {
                            if (usuarios[i]->getType() == "M")
                            {
                            MenuMesero:
                                cout << "➤➤➤➤➤INICIO DE SESION EXITOSO ✔ " << endl;
                                cout << "|||||BIENVENIDO MESERO " << nickname << "|||||" << endl;
                                cout << "Le recordamos que como mesero usted dispone de una cantidad de platillos que debe entregar\nusted es libre de decidir si los entrega uno por uno o todos al mismo tiemo" << endl;
                                char opciones;
                                cout << "a)Ver cantidad de platillos a la espera\nb)Entregar un platillo\nc)Entregar todos los platillos\nd)Salir" << endl;
                                cin >> opciones;
                                switch (opciones)
                                {
                                case 'a':
                                {
                                    cout << "La cantidad de platillos actualmente es : " << dynamic_cast<Mesero *>(usuarios[i])->getPlatillos() << endl;
                                }
                                break;
                                    //fin case 'a'
                                case 'b':
                                {
                                    cout << "Bien! , decidio entregar de uno en uno!" << endl;
                                    int p = dynamic_cast<Mesero *>(usuarios[i])->getPlatillos();
                                    cout << "La cantidad de platillos que tenia antes era: " << p;
                                    dynamic_cast<Mesero *>(usuarios[i])->setPlatillos(1);
                                    cout << "Los platillos que le restan por entregar son: " << dynamic_cast<Mesero *>(usuarios[i])->getPlatillos() << endl;
                                }
                                break;
                                    //fin case 'b'
                                case 'c':
                                {
                                    cout << "Bien! , decidio entregarlos todos!" << endl;
                                    int p = dynamic_cast<Mesero *>(usuarios[i])->getPlatillos();
                                    dynamic_cast<Mesero *>(usuarios[i])->setPlatillos(p);
                                    cout << "Los platillos que le restan por entregar son: " << dynamic_cast<Mesero *>(usuarios[i])->getPlatillos() << endl;
                                }
                                break;
                                    //fin case 'c'
                                case 'd':
                                {
                                    goto MenuPrincipal;
                                }
                                break;
                                    //fin case 'd'
                                default:
                                    cout << " ✖︎ La accion que intento no esta contemplada dentro del menu " << endl;
                                    goto MenuMesero;
                                    break;
                                } //fin switch
                                goto MenuMesero;
                            }
                        }
                    }
                }
            }
            break;
                //fin case 'd'
            default:
                cout << " ✖︎ La accion que intento no esta contemplada dentro del menu " << endl;
                goto MenuPrincipal;
                break;
            }
        }
        break;
        //fin case 'a' de menu principal
        case 'b':
        {
        Agregar:
            char ag;
            cout << "a)Agregar Cliente\nb)Agregar Personal administrativo\n"
                 << endl;
            cin >> ag;
            switch (ag)
            {
            case 'a':
            {
                try
                {
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
                    cout << "Ingrese su nickname" << endl;
                    cin >> nickname;
                    cout << "Ingrese su password" << endl;
                    cin >> password;
                    cout << "Ingrese su nombre" << endl;
                    getline(cin, nombre);
                    getline(cin, nombre);
                    cout << "Ingrese su edad" << endl;
                    cin >> edadS;
                    edad = stoi(edadS);
                    // if(edad<18 ){
                    //     throw 99;
                    // }
                    if (edad < 18)
                    {
                        cout << "Debe tener una edad superior a 18" << endl;
                        goto MenuPrincipal;
                    }
                    cout << "Ingrese su ID" << endl;
                    cin >> id;
                    cout << "Ingrese su numero de telefono" << endl;
                    cin >> telefono;
                    cout << "Ingrese su direccion" << endl;
                    getline(cin, direccion);
                    getline(cin, direccion);
                    cout << "Ingrese su feedback" << endl;
                    cin >> feedbackS;
                    feedback = stoi(feedbackS);
                    while (feedback > 5)
                    {
                        cout << "Su rating al restaurante debe ser entre 1 - 5 " << endl;
                        cin >> feedbackS;
                        feedback = stoi(feedbackS);
                    }
                    Usuario *cliente = new Cliente(nickname, password, nombre, edad, id, telefono, direccion, feedback);
                    fstream file;
                    //clientes.push_back(new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback));
                    usuarios.push_back(new Cliente(nickname, password, nombre, edad, id, telefono, direccion, feedback));
                    file.open("Datos.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                    file << cliente->escritura();
                    cout << "Agrego Cliente exitosamente" << endl;
                    file.close();
                }
                catch (std::invalid_argument)
                {
                    cout << " ✖︎ Querido usuario, no quiera arruinarme el programa, ingreso un dato incorrecto" << endl;
                }
                catch (int c)
                {
                    cout << " ✖︎ Querido usuario, no quiera arruinarme el programa, ingreso un dato incorrecto" << endl;
                }
            }
            break;
            //fin case 'a' de switch agregar
            case 'b':
            {
            Personal:
                char personal;
                //cout << "a)Agregar Administrador\nb)Agregar Chef\nc)Agregar Lavaplatos\nd)Agregar Mesero\n"<<endl;
                cout << "a)Agregar Administrador" << endl;

                cin >> personal;
                if (personal == 'b' || personal == 'c' || personal == 'd')
                {
                    goto NOENCONTRO;
                }
                switch (personal)
                {
                case 'a':
                {

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
                    cout << "Ingrese su nickname" << endl;
                    cin >> nickname;
                    cout << "Ingrese su password" << endl;
                    cin >> password;
                    cout << "Ingrese su nombre" << endl;
                    getline(cin, nombre);
                    getline(cin, nombre);
                    cout << "Ingrese su edad" << endl;
                    cin >> edadS;
                    edad = stoi(edadS);
                    if (edad < 18)
                    {
                        throw 99;
                    }
                    if (edad < 18)
                    {
                        cout << "Debe tener una edad superior a 18" << endl;
                        goto MenuPrincipal;
                    }
                    cout << "Ingrese su ID" << endl;
                    cin >> id;
                    cout << "Ingrese su numero de telefono" << endl;
                    cin >> telefono;
                    cout << "Ingrese el ano en el que fue contratado" << endl;
                    cin >> fecha;
                    cout << "Ingrese sueldo" << endl;
                    cin >> sueldoS;
                    sueldo = stod(sueldoS);

                    Usuario *admin = new Administrador(nickname, password, nombre, edad, id, telefono, fecha, sueldo);
                    fstream file;
                    //clientes.push_back(new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback));
                    usuarios.push_back(new Administrador(nickname, password, nombre, edad, id, telefono, fecha, sueldo, 0, 0));
                    file.open("Datos.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                    file << admin->escritura();
                    cout << "Agrego Administrador exitosamente" << endl;
                    file.close();
                    cout << "Le hacemos saber que como administrador , usted puede realizar varias tareas\n como agregar personal o despedir el mismo, ver los salarios de los empleados\nentre otras diversas funciones como administrador, cuando haga login\npodra ver mas a detalle lo que aqui le notificamos" << endl;
                }
                break;
                //fin case 'a' de agregar personal
                case 'b':
                {
                CHEF:
                    cout << "\n┼┼┼┼┼AGREGANDO CHEF┼┼┼┼┼" << endl;
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
                    cout << "Ingrese su nickname" << endl;
                    cin >> nickname;
                    cout << "Ingrese su password" << endl;
                    cin >> password;
                    cout << "Ingrese su nombre" << endl;
                    getline(cin, nombre);
                    getline(cin, nombre);
                    cout << "Ingrese su edad" << endl;
                    cin >> edadS;
                    edad = stoi(edadS);
                    if (edad < 18)
                    {
                        throw 99;
                    }
                    if (edad < 18)
                    {
                        cout << "Debe tener una edad superior a 18" << endl;
                        goto MenuPrincipal;
                    }
                    cout << "Ingrese su ID" << endl;
                    cin >> id;
                    cout << "Ingrese su numero de telefono" << endl;
                    cin >> telefono;
                    cout << "Ingrese el ano en el que fue contratado" << endl;
                    cin >> fecha;
                    cout << "Ingrese sueldo" << endl;
                    cin >> sueldoS;
                    sueldo = stod(sueldoS);
                    cout << "Ingrese platillo favorito del chef" << endl;
                    cin >> platillo;

                    Usuario *chef = new Chef(nickname, password, nombre, edad, id, telefono, fecha, sueldo, platillo);
                    fstream file;
                    //clientes.push_back(new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback));
                    usuarios.push_back(new Chef(nickname, password, nombre, edad, id, telefono, fecha, sueldo, platillo));
                    file.open("Datos.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                    file << chef->escritura();
                    cout << "Agrego Chef exitosamente" << endl;
                    cout << "Le hacemos saber que como chef del restaurante queda bajo su servicio\nlos lavaplatos a los cuales puede adularles por un buen\ntrabajo, o bien reganarlos si no se desenpenan de la forma correcta " << endl;
                    file.close();
                    //goto ADMINISTRADOR;
                }
                break;
                //fin case 'b' de agregar personal
                case 'c':
                {
                LAVAPLATOS:
                    cout << "\n┼┼┼┼┼AGREGANDO LAVAPLATOS┼┼┼┼┼" << endl;
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
                    cout << "Ingrese su nickname" << endl;
                    cin >> nickname;
                    cout << "Ingrese su password" << endl;
                    cin >> password;
                    cout << "Ingrese su nombre" << endl;
                    getline(cin, nombre);
                    getline(cin, nombre);
                    cout << "Ingrese su edad" << endl;
                    cin >> edadS;
                    edad = stoi(edadS);
                    if (edad < 18)
                    {
                        throw 99;
                    }
                    if (edad < 18)
                    {
                        cout << "Debe tener una edad superior a 18" << endl;
                        goto MenuPrincipal;
                    }
                    cout << "Ingrese su ID" << endl;
                    cin >> id;
                    cout << "Ingrese su numero de telefono" << endl;
                    cin >> telefono;
                    cout << "Ingrese el ano en el que fue contratado" << endl;
                    cin >> fecha;
                    cout << "Ingrese sueldo" << endl;
                    cin >> sueldoS;
                    sueldo = stod(sueldoS);

                    Usuario *lavaplatos = new Lavaplatos(nickname, password, nombre, edad, id, telefono, fecha, sueldo, 50);
                    fstream file;
                    //clientes.push_back(new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback));
                    usuarios.push_back(new Lavaplatos(nickname, password, nombre, edad, id, telefono, fecha, sueldo, 50));
                    file.open("Datos.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                    file << lavaplatos->escritura();
                    cout << "Agrego Lavaplatos exitosamente" << endl;
                    cout << "Le hacemos saber que como lavaplatos del restaurante usted tiene un nivel\nde motivacion dependiendo en que nivel esta, puede \npedir un aumento o renunciar a su trabajo, su motivacion depende\n de las adulaciones o reganos del chef segun la forma e\n la que se desempena en el trabajo" << endl;
                    file.close();
                    //goto ADMINISTRADOR;
                }
                break;
                //fin case 'c' de agregar personal
                case 'd':
                {
                MESERO:
                    cout << "\n┼┼┼┼┼AGREGANDO MESERO┼┼┼┼┼" << endl;
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
                    cout << "Ingrese su nickname" << endl;
                    cin >> nickname;
                    cout << "Ingrese su password" << endl;
                    cin >> password;
                    cout << "Ingrese su nombre" << endl;
                    getline(cin, nombre);
                    getline(cin, nombre);
                    cout << "Ingrese su edad" << endl;
                    cin >> edadS;
                    edad = stoi(edadS);
                    if (edad < 18)
                    {
                        throw 99;
                    }
                    if (edad < 18)
                    {
                        cout << "Debe tener una edad superior a 18" << endl;
                        goto MenuPrincipal;
                    }
                    cout << "Ingrese su ID" << endl;
                    cin >> id;
                    cout << "Ingrese su numero de telefono" << endl;
                    cin >> telefono;
                    cout << "Ingrese el ano en el que fue contratado" << endl;
                    cin >> fecha;
                    cout << "Ingrese sueldo" << endl;
                    cin >> sueldoS;
                    sueldo = stod(sueldoS);

                    //rand = rand() % 20 + 1;
                    Usuario *mesero = new Mesero(nickname, password, nombre, edad, id, telefono, fecha, sueldo, 8);
                    fstream file;
                    //clientes.push_back(new Cliente(nickname,password,nombre,edad,id,telefono,direccion,feedback));
                    usuarios.push_back(new Mesero(nickname, password, nombre, edad, id, telefono, fecha, sueldo, 8));
                    file.open("Datos.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                    file << mesero->escritura();
                    cout << "Agrego Mesero exitosamente" << endl;
                    cout << "Le hacemos saber que como mesero de nuestro restaurante , usted tendra una lista\nde platillos por entregar, usted puede decidir\nsi entregarlos todos o uno por uno" << endl;
                    file.close();
                    //goto ADMINISTRADOR;
                }
                break;
                //fin case 'd' de agregar personal
                default:
                NOENCONTRO:
                    cout << "La accion que intento no esta contemplada dentro del menu " << endl;
                    goto Personal;
                    break;
                }
            }
            break;
            //fin case 'b' de agregar
            default:
                cout << "La accion que intento no esta contemplada dentro del menu " << endl;
                goto Agregar;
                break;
            } //fin switch agregar
        }
        break;
        //fin case 'b' de menu principal
        case 'c':
        {
            string nickname = "";
            string password = "";
            cout << "Ingrese nickname de usuario" << endl;
            cin >> nickname;
            cout << "Ingrese password de usuario" << endl;
            cin >> password;

            for (int i = 0; i < usuarios.size(); i++)
            {
                if (usuarios[i]->getNickname() == nickname)
                {
                    if (usuarios[i]->getPassword() == password)
                    {
                        if (usuarios[i]->getType() == "A")
                        {
                        MenuAdmin:
                            cout << "➤➤➤➤➤INICIO DE ADMIN SESION EXITOSO ✔ " << endl;
                            char accion;
                            cout << "a)Agregar empleado\nb)Despedir empleado\nc)Listar empleado o empleados con menor sueldo\nd)Listar empleado o empleados con mayor sueldo\ne)Ver promedio sueldo entre los empleados" << endl;
                            cin >> accion;
                            switch (accion)
                            {
                            case 'a':
                            {
                            EMPLEANDO:
                            ADMINISTRADOR:
                                char agregando;
                                cout << "a)Agregar Chef\nb)Agregar Lavaplatos\nc)Agregar Mesero\n"
                                     << endl;
                                cin >> agregando;
                                switch (agregando)
                                {
                                case 'a':
                                {
                                    if (dynamic_cast<Administrador *>(usuarios[i]))
                                    {
                                        dynamic_cast<Administrador *>(usuarios[i])->setEmpleados(1);
                                    }
                                    string admin = dynamic_cast<Administrador *>(usuarios[i])->getNickname();
                                    cout << admin << " Esta contratando un CHEF , sumaremos 1 a su lista de empleados" << endl;
                                    goto CHEF;
                                }
                                break;
                                    //fin case 'a'
                                case 'b':
                                {
                                    if (dynamic_cast<Administrador *>(usuarios[i]))
                                    {
                                        dynamic_cast<Administrador *>(usuarios[i])->setEmpleados(1);
                                    }
                                    string admin = dynamic_cast<Administrador *>(usuarios[i])->getNickname();
                                    cout << admin << " Esta contratando un LAVAPLATOS , sumaremos 1 a su lista de empleados" << endl;
                                    goto LAVAPLATOS;
                                }
                                break;
                                    //fin case 'b'
                                case 'c':
                                {
                                    if (dynamic_cast<Administrador *>(usuarios[i]))
                                    {
                                        dynamic_cast<Administrador *>(usuarios[i])->setEmpleados(1);
                                    }
                                    string admin = dynamic_cast<Administrador *>(usuarios[i])->getNickname();
                                    cout << admin << " Esta contratando un MESERO , sumaremos 1 a su lista de empleados" << endl;
                                    goto MESERO;
                                }
                                break;
                                    //fin case 'c'
                                default:
                                    cout << "La accion que intento no esta contemplada dentro del menu " << endl;
                                    goto EMPLEANDO;
                                    break;
                                }
                            }
                            break;
                                //fin case 'a'
                            case 'b':
                            { //DESPEDIR EMPLEADO
                                try
                                {
                                    string despedir;
                                    string admin = dynamic_cast<Administrador *>(usuarios[i])->getNickname();
                                    cout << "Se desplegara la lista de empleados, ingrese el nombre del que desea despedir" << endl;
                                    for (int i = 0; i < usuarios.size(); i++)
                                    {
                                        if (dynamic_cast<Personal *>(usuarios[i])->getType() == "L")
                                        {
                                            cout << dynamic_cast<Lavaplatos *>(usuarios[i])->getNombre() << endl;
                                        }
                                    }
                                    cout << "---Fin de la lista---" << endl;
                                    cin >> despedir;

                                    for (int i = 0; i < usuarios.size(); i++)
                                    {
                                        if (dynamic_cast<Personal *>(usuarios[i])->getNombre() == despedir)
                                        {
                                            //usuarios.erase(usuarios[i]);
                                            usuarios.erase(usuarios.begin() + i);
                                        }
                                    }

                                    if (dynamic_cast<Administrador *>(usuarios[i]))
                                    {
                                        dynamic_cast<Administrador *>(usuarios[i])->setDesempleados(1);
                                    }
                                    cout << admin << " Despidio exitosamente a un empleado, sumaremos 1 a su lista de desempleados" << endl;
                                }
                                catch (const std::exception &)
                                {
                                    cout << " ✖︎ Querido usuario, no quiera arruinarme el programa, ingreso un dato incorrecto" << endl;
                                }
                            }
                            break;
                                //fin case 'b'
                            case 'c':
                            { //MENOR SUELDO
                                sueldo_Bajo(usuarios);
                            }
                            break;
                                //fin case 'c'
                            case 'd':
                            { //MAYOR SUELDO
                                sueldo_Alto(usuarios);
                            }
                            break;
                                //fin case 'd'
                            case 'e':
                            { //PROMEDIO
                                double promedio = promedioSueldo(usuarios);
                                cout << "El salario promedio entre los empleados es de:  " << promedio << endl;
                            }
                            break;
                                //fin case 'e'
                            default:
                                cout << " ✖︎ La accion que intento no esta contemplada dentro del menu " << endl;
                                goto MenuAdmin;
                                break;
                            }
                        }
                        else
                        {
                            cout << " ✖︎ Algo ocurrio y no se pudo inciar sesion\nAsegurese de iniciar sesion donde corresponde\nasegurese de introducir los datos correctamente" << endl;
                        }
                    }
                    else
                    {
                        cout << " ✖︎ Algo ocurrio y no se pudo inciar sesion\nAsegurese de iniciar sesion donde corresponde\nasegurese de introducir los datos correctamente" << endl;
                    }
                }
            }
        }
        break;
        //fin case 'c' de menu principal
        case 'd':
        {
            cout << "Esperamos vuelva pronto" << endl;
            resp = 'n';
        }
        break;
        //fin case 'd' de menu principal
        case 'e':
        {

            //Sobrestritura(usuarios);
            for (int i = 0; i < usuarios.size(); i++)
            {
                cout << usuarios[i]->getNombre() << endl;
            }
        }
        break;
        //fin case 'e' de menu principal
        case 'z':
        {

            usuarios = cargar();
        }
        break;
            //fin case 'z' de menu principal
        default:
            cout << "La accion que intento no esta contemplada dentro del menu " << endl;
            goto MenuPrincipal;
            break;
        } //fin switch del menu principal

    } //fin while con respuesta de usuario
    for (int i = 0; i < usuarios.size(); i++)
    {
        delete usuarios[i];
    }
    cout << "Se limpio exitosamente la memoria" << endl;

    return 0;
} //fin main;

// vector<Usuario*> cargarVector(){
//     vector <Usuario*> usuarios;

//     return usuarios;
// }

void imprimirVector(vector<Usuario *> usuarios)
{
    for (int i = 0; i < usuarios.size(); i++)
    {
        if (dynamic_cast<Chef *>(usuarios[i]))
        {
            string x = dynamic_cast<Cliente *>(usuarios[i])->getNickname();
            cout << x;
        }
    }
}

int calificacion(vector<Usuario *> users)
{
    int cont = 0;
    int acum = 0;
    int res = 0;
    for (int i = 0; i < users.size(); i++)
    {
        if (dynamic_cast<Cliente *>(users[i]))
        {
            acum += dynamic_cast<Cliente *>(users[i])->getFeedback();
            cont++;
        }
    }

    if (acum > 0)
    {
        res = acum / cont;
    }

    return res;
}

// void imprimirPosibles_empleados(vector<Usuario*> gente){
//     for(int i = 0; i < gente.size(); i++){
//         cout<<"PNE"<<endl;
//         if(dynamic_cast<Chef*>(gente[i])->getType()=="CH"){
//            cout<<"TRUE"<<endl;
//             string x= dynamic_cast<Chef*>(gente[i])->getNickname();
//             cout << x;
//         }else{
//             cout<<"AJABER"<<endl;
//         }

//     }

// }

double promedioSueldo(vector<Usuario *> users)
{
    int cont = 0;
    double acum = 0;
    double res = 0;
    for (int i = 0; i < users.size(); i++)
    {
        if (dynamic_cast<Mesero *>(users[i]))
        {
            acum += dynamic_cast<Mesero *>(users[i])->getSueldo();
            cont++;
        }
        if (dynamic_cast<Lavaplatos *>(users[i]))
        {
            acum += dynamic_cast<Lavaplatos *>(users[i])->getSueldo();
            cont++;
        }
        if (dynamic_cast<Chef *>(users[i]))
        {
            acum += dynamic_cast<Chef *>(users[i])->getSueldo();
            cont++;
        }
    }

    if (acum > 0)
    {
        res = acum / cont;
    }

    return res;
}

void sueldo_Alto(vector<Usuario *> users)
{
    double mayor = 0;
    double tempo = 0;
    double res = 0;
    for (int i = 0; i < users.size(); i++)
    {
        if (dynamic_cast<Personal *>(users[i])->getType() != "A")
        {
            mayor = dynamic_cast<Personal *>(users[i])->getSueldo();
        }
    }

    for (int i = 0; i < users.size(); i++)
    {
        if (dynamic_cast<Personal *>(users[i])->getType() != "A")
        {
            tempo = dynamic_cast<Personal *>(users[i])->getSueldo();
            if (tempo > mayor)
            {
                mayor = tempo;
            }
        }
    }
    for (int i = 0; i < users.size(); i++)
    {
        if (dynamic_cast<Personal *>(users[i])->getSueldo() == mayor)
        {
            //if(dynamic_cast<Personal*>(users[i])->getType()!="A"){
            cout << "Empleado(s) con el sueldo mas alto" << endl;
            cout << "El empleado: " << dynamic_cast<Personal *>(users[i])->getNombre() << endl;
            ;
            cout << "Con un sueldo de: " << dynamic_cast<Personal *>(users[i])->getSueldo() << endl;

            //}
        }
    }
}

void sueldo_Bajo(vector<Usuario *> users)
{
    double menor = 0;
    double tempo = 0;
    double res = 0;
    for (int i = 0; i < users.size(); i++)
    {
        if (dynamic_cast<Personal *>(users[i])->getType() != "A")
        {
            menor = dynamic_cast<Personal *>(users[i])->getSueldo();
        }
    }

    for (int i = 0; i < users.size(); i++)
    {
        if (dynamic_cast<Personal *>(users[i])->getType() != "A")
        {
            tempo = dynamic_cast<Personal *>(users[i])->getSueldo();
            if (tempo < menor)
            {
                menor = tempo;
            }
        }
    }
    for (int i = 0; i < users.size(); i++)
    {
        if (dynamic_cast<Personal *>(users[i])->getSueldo() == menor)
        {
            //if(dynamic_cast<Personal*>(users[i])->getType()!="A"){
            cout << "Empleado(s) con el sueldo mas bajo" << endl;
            cout << "El empleado: " << dynamic_cast<Personal *>(users[i])->getNombre() << endl;
            ;
            cout << "Con un sueldo de: " << dynamic_cast<Personal *>(users[i])->getSueldo() << endl;

            //}
        }
    }
}

void Sobrestritura(vector<Usuario *> hood)
{
    //ofstream writer("Datos.txt");
    //writer.clear();

    // writer.close();
    fstream file;
    //if(file.size()!=0){
    //file.trunc();
    file.open("Datos.txt", std::fstream::trunc | std::fstream::in | std::fstream::out | std::fstream::app);
    vector<Usuario *> tempo;
    for (int i = 0; i < hood.size(); i++)
    {
        if (hood[i]->getType() == "C")
        {
            string type = dynamic_cast<Cliente *>(hood[i])->getType();
            string nickname = dynamic_cast<Cliente *>(hood[i])->getNickname();
            string password = dynamic_cast<Cliente *>(hood[i])->getPassword();
            string nombre = dynamic_cast<Cliente *>(hood[i])->getNombre();
            int edad = dynamic_cast<Cliente *>(hood[i])->getEdad();
            string id = dynamic_cast<Cliente *>(hood[i])->getId();
            string telefono = dynamic_cast<Cliente *>(hood[i])->getTelefono();
            string direccion = dynamic_cast<Cliente *>(hood[i])->getDireccion();
            int feedback = dynamic_cast<Cliente *>(hood[i])->getFeedback();
            Usuario *cliente = new Cliente(nickname, password, nombre, edad, id, telefono, direccion, feedback);
            tempo.push_back(new Cliente(nickname, password, nombre, edad, id, telefono, direccion, feedback));
            file << cliente->escritura();
            //cout << "Agrego Cliente exitosamente"<<endl;
        }
        if (hood[i]->getType() == "A")
        {
            string type = dynamic_cast<Administrador *>(hood[i])->getType();
            string nickname = dynamic_cast<Administrador *>(hood[i])->getNickname();
            string password = dynamic_cast<Administrador *>(hood[i])->getPassword();
            string nombre = dynamic_cast<Administrador *>(hood[i])->getNombre();
            int edad = dynamic_cast<Administrador *>(hood[i])->getEdad();
            string id = dynamic_cast<Administrador *>(hood[i])->getId();
            string telefono = dynamic_cast<Administrador *>(hood[i])->getTelefono();
            string fecha = dynamic_cast<Administrador *>(hood[i])->getFecha();
            double sueldo = dynamic_cast<Administrador *>(hood[i])->getSueldo();
            int empleados = dynamic_cast<Administrador *>(hood[i])->getEmpleados();
            int desempleados = dynamic_cast<Administrador *>(hood[i])->getDesempleados();
            Usuario *admin = new Administrador(nickname, password, nombre, edad, id, telefono, fecha, sueldo);
            tempo.push_back(new Administrador(nickname, password, nombre, edad, id, telefono, fecha, sueldo, 0, 0));
            file << admin->escritura();
            //cout << "Agrego Administrador exitosamente"<<endl;
        }
        if (hood[i]->getType() == "CH")
        {
            string type = dynamic_cast<Chef *>(hood[i])->getType();
            string nickname = dynamic_cast<Chef *>(hood[i])->getNickname();
            string password = dynamic_cast<Chef *>(hood[i])->getPassword();
            string nombre = dynamic_cast<Chef *>(hood[i])->getNombre();
            int edad = dynamic_cast<Chef *>(hood[i])->getEdad();
            string id = dynamic_cast<Chef *>(hood[i])->getId();
            string telefono = dynamic_cast<Chef *>(hood[i])->getTelefono();
            string fecha = dynamic_cast<Chef *>(hood[i])->getFecha();
            double sueldo = dynamic_cast<Chef *>(hood[i])->getSueldo();
            string platilloFav = dynamic_cast<Chef *>(hood[i])->getPlatilloFav();
            Usuario *chef = new Chef(nickname, password, nombre, edad, id, telefono, fecha, sueldo, platilloFav);
            tempo.push_back(new Chef(nickname, password, nombre, edad, id, telefono, fecha, sueldo, platilloFav));
            file << chef->escritura();
        }
        if (hood[i]->getType() == "M")
        {
            string type = dynamic_cast<Mesero *>(hood[i])->getType();
            string nickname = dynamic_cast<Mesero *>(hood[i])->getNickname();
            string password = dynamic_cast<Mesero *>(hood[i])->getPassword();
            string nombre = dynamic_cast<Mesero *>(hood[i])->getNombre();
            int edad = dynamic_cast<Mesero *>(hood[i])->getEdad();
            string id = dynamic_cast<Mesero *>(hood[i])->getId();
            string telefono = dynamic_cast<Mesero *>(hood[i])->getTelefono();
            string fecha = dynamic_cast<Mesero *>(hood[i])->getFecha();
            double sueldo = dynamic_cast<Mesero *>(hood[i])->getSueldo();
            int platillos = dynamic_cast<Mesero *>(hood[i])->getPlatillos();
            Usuario *mesero = new Mesero(nickname, password, nombre, edad, id, telefono, fecha, sueldo, 8);
            tempo.push_back(new Mesero(nickname, password, nombre, edad, id, telefono, fecha, sueldo, 8));
            file << mesero->escritura();
        }
        if (hood[i]->getType() == "L")
        {
            string type = dynamic_cast<Lavaplatos *>(hood[i])->getType();
            string nickname = dynamic_cast<Lavaplatos *>(hood[i])->getNickname();
            string password = dynamic_cast<Lavaplatos *>(hood[i])->getPassword();
            string nombre = dynamic_cast<Lavaplatos *>(hood[i])->getNombre();
            int edad = dynamic_cast<Lavaplatos *>(hood[i])->getEdad();
            string id = dynamic_cast<Lavaplatos *>(hood[i])->getId();
            string telefono = dynamic_cast<Lavaplatos *>(hood[i])->getTelefono();
            string fecha = dynamic_cast<Lavaplatos *>(hood[i])->getFecha();
            double sueldo = dynamic_cast<Lavaplatos *>(hood[i])->getSueldo();
            int motivacion = dynamic_cast<Lavaplatos *>(hood[i])->getMotivacion();
            Usuario *lavaplatos = new Lavaplatos(nickname, password, nombre, edad, id, telefono, fecha, sueldo, 50);
            tempo.push_back(new Lavaplatos(nickname, password, nombre, edad, id, telefono, fecha, sueldo, 50));
            file << lavaplatos->escritura();
        }
    }
    //}

    file.close();
}

vector<Usuario *> cargar()
{
    vector<Usuario *> tempo;
    ifstream file("Datos.txt");
    //file.trunc();
    //file.open ("Datos.txt", std::fstream::trunc | std::fstream::in | std::fstream::out | std::fstream::app);
    if (file.is_open())
    {
        while (!file.eof())
        {
            string TYPE;
            getline(file, TYPE, ';');
            if (TYPE == "C")
            {
                string edadS;
                string feedbackS;
                string type = TYPE;
                string nickname;
                getline(file, nickname, ';');
                string password;
                getline(file, password, ';');
                string nombre;
                getline(file, nombre, ';');
                int edad;
                getline(file, edadS, ';');
                string id;
                getline(file, id, ';');
                string telefono;
                getline(file, telefono, ';');
                string direccion;
                getline(file, direccion, ';');
                int feedback;
                getline(file, feedbackS, ';');
                edad = (stoi(edadS));
                feedback = stoi(feedbackS);

                tempo.push_back(new Cliente(nickname, password, nombre, edad, id, telefono, direccion, feedback));
            }
            //cout<<TYPE<<endl;

            if (TYPE == "A")
            {
                //cout << "entro" << endl;
                string edadS;
                string sueldoS;
                string empleadosS;
                string desempleadosS;
                string type = TYPE;
                string nickname;
                getline(file, nickname, ';');
                //cout << nickname << endl;
                string password;
                getline(file, password, ';');
                string nombre;
                getline(file, nombre, ';');
                int edad;
                getline(file, edadS, ';');
                string id;
                getline(file, id, ';');
                string telefono;
                getline(file, telefono, ';');
                string fecha;
                getline(file, fecha, ';');
                double sueldo;
                getline(file, sueldoS, ';');
                int empleados;
                getline(file, empleadosS, ';');
                int desempleados;
                getline(file, desempleadosS, ';');
                edad = (stoi(edadS));
                empleados = (stoi(empleadosS));
                desempleados = (stoi(desempleadosS));
                sueldo = (stod(sueldoS));
                tempo.push_back(new Administrador(nickname, password, nombre, edad, id, telefono, fecha, sueldo, 0, 0));
            }
            if (TYPE == "CH")
            {
                string edadS;
                string sueldoS;
                string type = TYPE;

                string nickname;
                getline(file, nickname, ';');
                string password;
                getline(file, password, ';');
                string nombre;
                getline(file, nombre, ';');
                int edad;
                getline(file, edadS, ';');
                string id;
                getline(file, id, ';');
                string telefono;
                getline(file, telefono, ';');
                string fecha;
                getline(file, fecha, ';');
                double sueldo;
                getline(file, sueldoS, ';');
                string platilloFav;
                getline(file, platilloFav, ';');
                edad = (stoi(edadS));
                sueldo = (stod(sueldoS));
                tempo.push_back(new Chef(nickname, password, nombre, edad, id, telefono, fecha, sueldo, platilloFav));
            }
            if (TYPE == "M")
            {
                string edadS;
                string sueldoS;
                string platillosS;
                string type = TYPE;

                string nickname;
                getline(file, nickname, ';');
                string password;
                getline(file, password, ';');
                string nombre;
                getline(file, nombre, ';');
                int edad;
                getline(file, edadS, ';');
                string id;
                getline(file, id, ';');
                string telefono;
                getline(file, telefono, ';');
                string fecha;
                getline(file, fecha, ';');
                double sueldo;
                getline(file, sueldoS, ';');
                int platillos;
                getline(file, platillosS, ';');
                platillos = (stoi(platillosS));
                edad = (stoi(edadS));
                sueldo = (stod(sueldoS));
                tempo.push_back(new Mesero(nickname, password, nombre, edad, id, telefono, fecha, sueldo, 8));
            }
            if (TYPE == "L")
            {
                string edadS;
                string sueldoS;
                string motivacionS;
                string type = TYPE;

                string nickname;
                getline(file, nickname, ';');
                string password;
                getline(file, password, ';');
                string nombre;
                getline(file, nombre, ';');
                int edad;
                getline(file, edadS, ';');
                string id;
                getline(file, id, ';');
                string telefono;
                getline(file, telefono, ';');
                string fecha;
                getline(file, fecha, ';');
                double sueldo;
                getline(file, sueldoS, ';');
                edad = (stoi(edadS));
                sueldo = (stod(sueldoS));
                int motivacion;
                getline(file, motivacionS, ';');
                motivacion = (stoi(motivacionS));
                edad = (stoi(edadS));
                sueldo = (stod(sueldoS));
                tempo.push_back(new Lavaplatos(nickname, password, nombre, edad, id, telefono, fecha, sueldo, 50));
            }

            file.close();
        }
    }
    //file.close();
    cout << "Carga de archivo exitosa" << endl;
    return tempo;
}