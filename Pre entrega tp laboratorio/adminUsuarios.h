#ifndef ADMINUSUARIOS_H_INCLUDED
#define ADMINUSUARIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "Validaciones.h"



typedef struct
{
    char calle[50];
    int altura;
    int cp;
    char ciudad[100];
    char localidad[50];
    char pais[100];
} stDomicilio;

typedef struct
{
    int idUsuario;
    char email[100];
    char password[20];
    char username[20];
    int esAdmin; /// 1 = si 0 = no
    char genero;
    char fechaNacimiento[20]; /// o se puede hacer con dia, mes, anio.
    int librosFavoritos[50]; /// se van a guardar los id de los libros favs.
    int validosLibrosFavs;
    char dni[10];
    stDomicilio domicilio;
    int eliminado; /// 0 si está activo - 1 si está eliminado
} stUsuario;

typedef struct
{
    stUsuario datosUsuarios;
    struct nodoUsuarios * sig;
} nodoUsuarios;


typedef struct{
    int idLibro; /// único, autoincremental
    char titulo[100];
    char editorial[50];
    char autor[50];
    char categoria[50];
    float valoracion;
    int eliminado; /// 0 si está activo - 1 si está eliminado
}stLibro;

typedef struct {
    stLibro datosLibros;
    struct nodoLibros * sig;
}nodoLibros;

/// PROTOTIPADO

nodoLibros * iniclistaLibros();
nodoLibros * cargarUnLibroManual(nodoLibros * listaLibros);
nodoLibros* bajaDelLibro(nodoLibros * listaLibros);
void mostrarUnLibro(nodoLibros* listaLibros);
void mostrarListaLibros (nodoLibros * listaLibros);
nodoLibros * buscarLibroPorAutor(nodoLibros * listaLibros);
nodoLibros * buscarLibroPorTitulo(nodoLibros * listaLibros);
nodoLibros * buscarLibroPorCategoria(nodoLibros * listaLibros);
nodoLibros * agregarAlFinalListaLibros(nodoLibros * listaLibros, nodoLibros * nuevo);
nodoLibros * iniclistaLibros();
nodoLibros * crearNodoLibros(stLibro libro);
nodoLibros * buscarUltimoNodoListaLibros(nodoLibros * listaLibros);
int generarIdLibros(nodoLibros * listaLibros);
void agregarLibroFavorito(nodoUsuarios *usuarioLogueado, nodoLibros *listaLibros, int idLibro);
void gestionarLibrosFavoritos(nodoUsuarios *usuarioLogueado, nodoLibros *listaLibros);
void quitarLibroFavorito(stUsuario* usuario, int idLibro);
nodoLibros* buscarLibroPorId(nodoLibros* listaLibros, int idLibro);


nodoUsuarios * buscarUltimoNodoListaUsuarios(nodoUsuarios * listaUsuarios);
nodoUsuarios * agregarUsuarioAlFinalLista(nodoUsuarios * listaUsuarios, nodoUsuarios * nuevo);
nodoUsuarios * buscarUsuarioPorDni(nodoUsuarios * listaUsuarios);
nodoUsuarios * buscarUsuarioPorEmail(nodoUsuarios * listaUsuarios);
nodoUsuarios * bajaDelUsuario(nodoUsuarios * listaUsuarios);
nodoUsuarios * modificarDireccionUsuario(nodoUsuarios * listaUsuarios);
nodoUsuarios * modificarUsername (nodoUsuarios * listaUsuarios);
void mostrarUnUsuario(nodoUsuarios* usuario);
void mostrarListaUsuariosInactivos (nodoUsuarios * listaUsuarios);
void mostrarListaUsuariosActivos (nodoUsuarios * listaUsuarios);
void mostrarListaUsuarios (nodoUsuarios * listaUsuarios);
void elegirListaAVer (nodoUsuarios * listaUsuarios);
stUsuario cargaRandomUsuario();
nodoLibros* buscarLibroPorId(nodoLibros* listaLibros, int idLibro);
void quitarLibroFavorito(stUsuario* usuario, int idLibro);
void elegirListaAVerLibros (nodoLibros * listaLibros);
void mostrarListaLibrosActivos (nodoLibros * listaLibros);
void mostrarListaLibrosInactivos (nodoLibros * listaLibros);



#endif // ADMINUSUARIOS_H_INCLUDED
