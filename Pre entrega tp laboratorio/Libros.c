/*
#include "Libros.h"

/** Usando estructura:

typedef struct {
stLibro datosLibros;
struct nodoLibros * sig;
}nodoLibros;
-----------------------------------------------------
typedef struct{
int idLibro; /// único, autoincremental
char titulo[100];
char editorial[50];
char autor[50];
char categoria[50];
float valoracion;
int eliminado; /// 0 si está activo - 1 si está eliminado
}stLibro;
**/
/*
/// Cargar un libro

nodoLibros * cargarUnLibroManual(nodoLibros * listaLibros)
{
   stLibro libro;
    char tituloLibro[100];
    printf("\nTitulo del libro: \n");
    fflush(stdin);
   fgets(libro.titulo, sizeof(libro.titulo), stdin);
    libro.titulo[strcspn(libro.titulo, "\n")] = 0;

   printf("\nEditorial del libro: \n");
    fflush(stdin);
    fgets(libro.editorial, sizeof(libro.editorial), stdin);
    libro.editorial[strcspn(libro.editorial, "\n")] = 0;

    printf("\nAutor del libro: \n");
    fflush(stdin);
    fgets(libro.autor, sizeof(libro.autor), stdin);
    libro.autor[strcspn(libro.autor, "\n")] = 0;

    printf("\nCategoria del libro: \n");
    fflush(stdin);
    fgets(libro.categoria, sizeof(libro.categoria), stdin);
    libro.categoria[strcspn(libro.categoria, "\n")] = 0;

    libro.valoracion = 0;
    libro.eliminado = 0;
    libro.idLibro = generarIdLibros(listaLibros);

    nodoLibros *nuevoLibro = crearNodoLibros(libro);
    listaLibros = agregarUsuarioAlFinalListaLibros(listaLibros, nuevoLibro);

    printf("\nLibro agregado exitosamente!\n");

    return listaLibros;
}

///Carga un libro de forma automatica
nodoLibros* cargarLibroAutomatico (stLibro librin,nodoLibros * listaLibros)
{
  nodoLibros* nuevoLibro=(nodoLibros*)malloc(sizeof(nodoLibros*));

    if(nuevoLibro)
    {
        strcpy(nuevoLibro->datosLibros.titulo,librin.titulo);
        strcpy(nuevoLibro->datosLibros.editorial, librin.editorial);
        strcpy(nuevoLibro->datosLibros.autor, librin.autor);
        strcpy(nuevoLibro->datosLibros.categoria, librin.categoria);
        nuevoLibro->datosLibros.valoracion = librin.valoracion;
        nuevoLibro->datosLibros.eliminado = librin.eliminado; /// Activacion del libro
        nuevoLibro->datosLibros.idLibro = generarIdLibros(listaLibros);
        nuevoLibro->sig = NULL;
    }
     return nuevoLibro;
}

/// Libro de la lista al Archivo
void libroAArchivo (nodoLibros * listaLibros)
{
FILE * archivoLibros= fopen ("libros.dat", "ab");

    nodoLibros *aux = listaLibros;
    while (aux)
    {
        fwrite(&aux->datosLibros, sizeof(stLibro), 1, archivoLibros);
        aux = aux->sig;
    }

    fclose(archivoLibros);
    printf("Libros guardados exitosamente en el archivo.\n");
}


/// Baja lógica de un libro

nodoLibros* bajaDelLibro(nodoLibros * listaLibros)
{
    nodoLibros * aux = listaLibros;
    char opcion;

    if (listaLibros)
    {
        printf("\nBuscar libro a eliminar segun: A-AUTOR B- TITULO C- CATEGORIA\n");
        fflush(stdin);
        scanf ("%c",&opcion);
    switch(opcion){
        case 'A':
        case 'a':
            aux = buscarLibroPorAutor(listaLibros);
            break; // Añadido break para evitar fall-through
        case 'B':
        case 'b':
            aux = buscarLibroPorTitulo(listaLibros);
            break; // Añadido break para evitar fall-through
        case 'C':
        case 'c':
            aux = buscarLibroPorCategoria(listaLibros);
            break; // Añadido break para evitar fall-through
        default:
            printf("\nOpción inválida\n");
    }

    if (aux != NULL) {
        aux->datosLibros.eliminado = 1;  // Activo = 0, No Activo = -1
        printf("\nLibro dado de baja exitosamente:\n");
        mostrarUnLibro(aux);
    } else {
        printf("\nNo se encontró el libro.\n");
    }
    } else
    {
        printf("\nNo hay libros en la lista.\n");
    }
    return listaLibros;
}


void mostrarUnLibro(nodoLibros* listaLibros)
{
    if (listaLibros) {
        printf ("ID Libro: %i\n", listaLibros->datosLibros.idLibro);
        printf ("Titulo: %s\n", listaLibros->datosLibros.titulo);
        printf("Editorial: %s\n", listaLibros->datosLibros.editorial);
        printf("Autor: %s\n", listaLibros->datosLibros.autor);
        printf("Categoria: %s\n", listaLibros->datosLibros.categoria);
        printf("Valoracion: %f %d\n", listaLibros->datosLibros.valoracion);
        printf("Libro activo?: %i\n", listaLibros->datosLibros.eliminado == 0 ? "Sí" : "No");
    }
}

/// Ver listado de todos los libros

void mostrarListaLibros (nodoLibros * listaLibros)
{
    while (listaLibros)
    {
        mostrarUnLibro (listaLibros);
        listaLibros = listaLibros->sig;
    }
}

nodoLibros * buscarLibroPorAutor(nodoLibros * listaLibros)
{
    nodoLibros * autor = listaLibros;
    int encontrado=0;
    char buscarPorAutor[20];

    printf("\n Ingrese nombre del autor:\n");
    fflush (stdin);
    gets(buscarPorAutor);

     while(autor!=NULL && encontrado == 0)
    {
            if(strcmp (autor->datosLibros.autor, buscarPorAutor) == 0)
            {
                encontrado = 1;
              mostrarUnLibro (autor);
            }
            else
            {
                autor = autor->sig;
            }
        }
        if (encontrado == 0)
        {
            printf ("\n Autor inexistente\n");
            autor = NULL;
        }

    return autor;
}

nodoLibros * buscarLibroPorTitulo(nodoLibros * listaLibros)
{
    nodoLibros * titulo = listaLibros;
    char buscarPorTitulo[20];

    printf("\n Ingrese el titulo del libro:\n");
    fflush (stdin);
    gets(buscarPorTitulo);

     while(titulo!=NULL)
    {
            if(strcmp (titulo->datosLibros.titulo, buscarPorTitulo) == 0)
            {
              mostrarUnLibro (titulo);
              return titulo;
            }
              titulo = titulo->sig;
            }

            printf ("\n Titulo inexistente\n");
            titulo = NULL;

    return listaLibros;
}

nodoLibros * buscarLibroPorCategoria(nodoLibros * listaLibros)
{
    nodoLibros * categoria = listaLibros;
    int encontrado=0;
    char buscarPorCategoria[20];

    printf("\n Ingrese la categoria:\n");
    fflush (stdin);
    gets(buscarPorCategoria);

     while(categoria!=NULL && encontrado == 0)
    {
            if(strcmp (categoria->datosLibros.categoria, buscarPorCategoria) == 0)
            {
                encontrado = 1;
              mostrarUnLibro (categoria);
            }
            else
            {
                categoria = categoria->sig;
            }
        }
        if (encontrado == 0)
        {
            printf ("\n Categoria inexistente\n");
            categoria = NULL;
        }
    return categoria;
}

int generarIdLibros(nodoLibros * listaLibros)
{
     int id = 0;
    nodoLibros * aux = listaLibros;

    while(aux)
    {
        if(aux->datosLibros.idLibro > id)
        {
            id = aux->datosLibros.idLibro;
        }
        aux = aux->sig;
    }
    return id + 1;
}

nodoLibros * iniclistaLibros()
{
    return NULL;
}

nodoLibros * crearNodoLibros(stLibro libro)
{
    nodoLibros * aux= (nodoLibros*) malloc(sizeof(nodoLibros));
    aux->datosLibros= libro;
    aux->sig=NULL;
    return aux;
}

nodoLibros * buscarUltimoNodoListaLibros(nodoLibros * listaLibros)
{
    nodoLibros * aux=listaLibros;

    while(aux->sig !=NULL)
    {
        aux=aux->sig;
    }
    return aux;
}

nodoLibros * agregarUsuarioAlFinalListaLibros(nodoLibros * listaLibros, nodoLibros * nuevo)
{
    if(!listaLibros)
    {
        listaLibros=nuevo;
    }
    else
    {
        nodoLibros * aux= buscarUltimoNodoListaLibros(listaLibros);
        aux->sig=nuevo;
    }
    return listaLibros;
}


void agregarLibroFavorito(stUsuario* usuario, nodoLibros* listaLibros, int idLibro) {
    if (usuario->validosLibrosFavs < 50) { // Verifica si hay espacio en el arreglo de favoritos
        // Buscar si el libro está en la lista de libros
        nodoLibros* aux = listaLibros;
        int libroEncontrado = 0;

        while (aux != NULL) {
            if (aux->datosLibros.idLibro == idLibro && aux->datosLibros.eliminado == 0) {
                libroEncontrado = 1;
                break;
            }
            aux = aux->sig;
        }

        if (libroEncontrado) {
            // Verificar si el libro ya es favorito del usuario
            int libroYaFavorito = 0;
            for (int i = 0; i < usuario->validosLibrosFavs; i++) {
                if (usuario->librosFavoritos[i] == idLibro) {
                    libroYaFavorito = 1;
                    break;
                }
            }

            if (!libroYaFavorito) {
                usuario->librosFavoritos[usuario->validosLibrosFavs] = idLibro;
                usuario->validosLibrosFavs++;
                printf("Libro con ID %d agregado a favoritos.\n", idLibro);
            } else {
                printf("El libro ya está en los favoritos.\n");
            }
        } else {
            printf("El libro con ID %d no se encuentra disponible.\n", idLibro);
        }
    } else {
        printf("No se pueden agregar más libros a favoritos.\n");
    }
}

void quitarLibroFavorito(stUsuario* usuario, int idLibro) {
    int indice = -1;

    // Buscar el índice del libro en el arreglo de favoritos
    for (int i = 0; i < usuario->validosLibrosFavs; i++) {
        if (usuario->librosFavoritos[i] == idLibro) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {  // Si se encuentra el libro
        // Mover los elementos para llenar el hueco
        for (int i = indice; i < usuario->validosLibrosFavs - 1; i++) {
            usuario->librosFavoritos[i] = usuario->librosFavoritos[i + 1];
        }
        usuario->validosLibrosFavs--;  // Disminuir el contador de libros favoritos
        printf("Libro con ID %d eliminado de favoritos.\n", idLibro);
    } else {
        printf("El libro con ID %d no se encuentra en los favoritos.\n", idLibro);
    }
}

nodoLibros* buscarLibroPorId(nodoLibros* listaLibros, int idLibro) {
    nodoLibros* aux = listaLibros;
    while (aux != NULL) {
        if (aux->datosLibros.idLibro == idLibro && aux->datosLibros.eliminado == 0) {
            return aux;
        }
        aux = aux->sig;
    }
    return NULL; // No encontrado o eliminado
}
*/
