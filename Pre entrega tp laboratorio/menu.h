#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#include "adminUsuarios.h"
#include "Libros.h"

#define ARCHIVO_USUARIOS "usuarios.dat"
#define ARCHIVO_LIBROS "libros.dat"



int menu();
void mostrarMenuPrincipal();
void iniciarSesion(nodoUsuarios *listaUsuarios);
void menuAdministrador();
void menuLibros(nodoUsuarios * usuarioLogueado, nodoLibros *listaLibros);
void modificarInformacionPersonal(nodoUsuarios* usuario);
nodoLibros * cargarUnLibroManual(nodoLibros *listaLibros);
void registrarUsuario(nodoUsuarios **listaUsuarios);
nodoUsuarios * iniclista();
nodoUsuarios * crearNodoUsuario(stUsuario usuario);
nodoUsuarios * buscarUltimoNodoListaUsuarios(nodoUsuarios * listaUsuarios);
nodoUsuarios * agregarUsuarioAlFinalLista(nodoUsuarios * listaUsuarios, nodoUsuarios * nuevo);
stUsuario cargarContraseniaRegistro(stUsuario usuario);
int generarIdUsuarios(nodoUsuarios *listaUsuarios);
int verificarUsuarioExistente(nodoUsuarios *listaUsuarios, char username[]);
int verificarEmailExistente(nodoUsuarios *listaUsuarios, char email[]);



#endif // MENU_H_INCLUDED
