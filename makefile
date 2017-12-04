main:    main.cpp Usuario.o Cliente.o Personal.o Administrador.o Chef.o Lavaplatos.o Mesero.o 
	g++ main.cpp Usuario.o Cliente.o Personal.o Administrador.o Chef.o Lavaplatos.o Mesero.o -o main
main.o:	main.cpp Usuario.h Cliente.h Personal.h Administrador.h Chef.h Lavaplatos.h Meseros.h 
	g++ -c main.cpp
Usuario:	Usuario.cpp Usuario.h
	g++ -c Usuario.cppCliente:	Cliente.cpp Cliente.h
	g++ -c Cliente.cppPersonal:	Personal.cpp Personal.h
	g++ -c Personal.cppAdministrador:	Administrador.cpp Administrador.h
	g++ -c Administrador.cppChef:	Chef.cpp Chef.h
	g++ -c Chef.cppLavalatos:	Lavaplatos.cpp LavaPlatos.h
	g++ -c LavaPlatos.cppMesero:	Meseros.cpp Mesero.h
	g++ -c Mesero.cpp
clean:
	rm  *.o main 