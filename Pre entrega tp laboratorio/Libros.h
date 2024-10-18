/*#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "adminUsuarios.h"

#define ARCHIVO_LIBROS "libros.dat"


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

///     FUNCIONES

///- AGREGAR LIBRO
///- CONSULTA LIBRO POR AUTOR
///- CONSULTA LIBRO POR CATEGORIA
///- BUSQUEDA LIBRO POR TITULO
///- BUSQUEDA LIBRO POR AUTOR

/// PROTOTIPADO

nodoLibros * iniclistaLibros();
nodoLibros * cargarUnLibroManual(nodoLibros * listaLibros);
nodoLibros* cargarLibroAutomatico (stLibro librin,nodoLibros * listaLibros);
void libroAArchivo (nodoLibros * listaLibros);
nodoLibros* bajaDelLibro(nodoLibros * listaLibros);
void mostrarUnLibro(nodoLibros* listaLibros);
void mostrarListaLibros (nodoLibros * listaLibros);
nodoLibros * buscarLibroPorAutor(nodoLibros * listaLibros);
nodoLibros * buscarLibroPorTitulo(nodoLibros * listaLibros);
nodoLibros * buscarLibroPorCategoria(nodoLibros * listaLibros);
nodoLibros * agregarUsuarioAlFinalListaLibros(nodoLibros * listaLibros, nodoLibros * nuevo);
nodoLibros * iniclistaLibros();
nodoLibros * crearNodoLibros(stLibro libro);
nodoLibros * buscarUltimoNodoListaLibros(nodoLibros * listaLibros);
int generarIdLibros(nodoLibros * listaLibros);
void agregarLibroFavorito(stUsuario* usuario, nodoLibros* listaLibros, int idLibro);
void quitarLibroFavorito(stUsuario* usuario, int idLibro);
nodoLibros* buscarLibroPorId(nodoLibros* listaLibros, int idLibro);

#endif // LIBROS_H_INCLUDED
*/
