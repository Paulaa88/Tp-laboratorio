#include "adminUsuarios.h"


void mostrarUnUsuario(nodoUsuarios* usuario) {
    if (usuario)
    {
        printf("\n -----------------------\n");

        printf("ID Usuario: %d\n", usuario->datosUsuarios.idUsuario);
        printf("Username: %s\n", usuario->datosUsuarios.username);
        printf("Email: %s\n", usuario->datosUsuarios.email);
        printf("DNI: %s\n", usuario->datosUsuarios.dni);
        printf("Gebanero: %c\n", usuario->datosUsuarios.genero);
        printf("Fecha de Nacimiento: %s\n", usuario->datosUsuarios.fechaNacimiento);
        printf("Domicilio: %s %d\n", usuario->datosUsuarios.domicilio.calle, usuario->datosUsuarios.domicilio.altura);
        printf("Codigo Postal: %d\n", usuario->datosUsuarios.domicilio.cp);
        printf("Ciudad: %s\n", usuario->datosUsuarios.domicilio.ciudad);
        printf("Pais: %s\n", usuario->datosUsuarios.domicilio.pais);

        printf("\n -----------------------\n");

    }
}
/// Ver listado de todos los usuarios

void mostrarListaUsuarios (nodoUsuarios * listaUsuarios)
{
    while (listaUsuarios!=NULL)
    {
        mostrarUnUsuario (listaUsuarios);
        listaUsuarios = listaUsuarios->sig;

    }
}
/// Ver listado solo de usuarios activos

void mostrarListaUsuariosActivos (nodoUsuarios * listaUsuarios)
{
    while (listaUsuarios!=NULL)
    {
        if (listaUsuarios->datosUsuarios.eliminado == 0)
        {
            mostrarUnUsuario (listaUsuarios);
        }
        listaUsuarios = listaUsuarios->sig;
    }
}

/// Ver listado solo de usuarios inactivos
void mostrarListaUsuariosInactivos (nodoUsuarios * listaUsuarios)
{
    while (listaUsuarios!=NULL)
    {
        if (listaUsuarios->datosUsuarios.eliminado == -1)
        {
            mostrarUnUsuario (listaUsuarios);
        }
        listaUsuarios = listaUsuarios->sig;
    }
}
/// Opcion de que lista le interesa ver al admin

void elegirListaAVer (nodoUsuarios * listaUsuarios)
{
    char opcion;

    printf ("Elija lista a ver: A- Todos los usuarios B- Usuarios activos C- Usuarios Inactivos\n");
    fflush(stdin);
    scanf("%c",&opcion);

    if (opcion == 'A' || opcion == 'a')
    {
        mostrarListaUsuarios (listaUsuarios);
    }
    else if (opcion == 'B' || opcion == 'b')
    {
        mostrarListaUsuariosActivos (listaUsuarios);
    }
    else if (opcion == 'C' || opcion == 'c')
    {
        mostrarListaUsuariosInactivos (listaUsuarios);
    }
    else
    {
        printf ("\nOpcion invalida\n");
    }
}

/// Buscar Usuario por Dni o Email y mostrarlo

nodoUsuarios * buscarUsuarioPorDni(nodoUsuarios * listaUsuarios)
{
    nodoUsuarios * aux = listaUsuarios;
    int encontrado=0;
    char buscarPorDni[20];

    printf("\n Ingrese numero de documento a buscar:\n");
    fflush (stdin);
    gets(buscarPorDni);

    while(aux!=NULL && encontrado == 0)
    {
        if(strcmp (aux->datosUsuarios.dni, buscarPorDni) == 0) ///datosUsuarios dentro de struct nodoUsuarios
        {
            encontrado = 1;
            printf("Usuario encontrado!\n");
        }
        else
        {
            aux = aux->sig;
        }
    }
    if (encontrado == 0)
    {
        printf ("\nDni inexistente\n");
        aux = NULL;
    }

    return aux;
}

/// Buscar Usuario por Email y mostrarlo

nodoUsuarios * buscarUsuarioPorEmail(nodoUsuarios * listaUsuarios)
{
    nodoUsuarios * aux = listaUsuarios;
    int encontrado = 0;
    char buscarPorEmail[100];

    printf("\n Ingrese email a buscar:\n");
    fflush (stdin);
    gets (buscarPorEmail);

    while(aux!=NULL && encontrado == 0)
    {
        if (strcmpi(aux->datosUsuarios.email, buscarPorEmail) == 0)
        {
            encontrado = 1;
            printf("Usuario encontrado!\n");
        }
        else
        {
            aux = aux->sig;
        }
    }
    if (encontrado == 0)
    {
        printf ("\nEmail inexistente\n");
        aux = NULL;
    }
    return aux;
}

nodoUsuarios * buscarUsuarioPorUsername(nodoUsuarios * listaUsuarios)
{
    nodoUsuarios * aux = listaUsuarios;
    int encontrado = 0;
    char username[100];

    printf("\n Ingrese el nombre de usuario a buscar:\n");
    fflush (stdin);
    gets (username);

    while(aux!=NULL && encontrado == 0)
    {
        if (strcmpi(aux->datosUsuarios.username, username) == 0)
        {
            encontrado = 1;
            printf("Usuario encontrado!\n");
        }
        else
        {
            aux = aux->sig;
        }
    }
    if (encontrado == 0)
    {
        printf ("\n Nombre de usuario inexistente\n");
        aux = NULL;
    }
    return aux;
}

/// Baja lógica de un usuario
nodoUsuarios* bajaDelUsuario(nodoUsuarios * listaUsuarios)
{
    nodoUsuarios * aux = listaUsuarios;
    char opcion;

    if (listaUsuarios)
    {
        printf("\nBuscar usuario a modificar segun: A-DNI B- EMAIL C- USERNAME\n");
        fflush(stdin);
        scanf ("%c",&opcion);
    switch(opcion){
        case 'A':
        case 'a':
            aux = buscarUsuarioPorDni(listaUsuarios);
            break;
        case 'B':
        case 'b':
            aux = buscarUsuarioPorEmail(listaUsuarios);
            break;
        case 'C':
        case 'c':
            aux = buscarUsuarioPorUsername(listaUsuarios);
            break;
        default:
            printf("\nOpcion invalida\n");
    }

    if (aux != NULL) {
        aux->datosUsuarios.eliminado = -1;  // Activo = 0, No Activo = -1
        printf("\nUsuario dado de baja exitosamente:\n");
    } else {
        printf("\nNo se encontro el usuario.\n");
    }
    } else
    {
        printf("\nNo hay usuarios en la lista.\n");
    }
    return listaUsuarios;
}

/// Modificar domicilio del usuario

nodoUsuarios * modificarDireccionUsuario(nodoUsuarios * listaUsuarios)
{
    nodoUsuarios * aux = NULL;
    char opcion;
    char cambios[100];
    int nuevoNumero;

    if (listaUsuarios)
    {
        printf("\nBuscar usuario a modificar segun: A-DNI B- EMAIL\n");
        fflush(stdin);
        scanf ("%c",&opcion);

        if (opcion == 'A' || opcion == 'a')
        {
            aux = buscarUsuarioPorDni(listaUsuarios);
        }
        else if (opcion == 'B' || opcion == 'b')
        {
            aux = buscarUsuarioPorEmail(listaUsuarios);
        }
        else
        {
            printf ("\nOpcion invalida\n");
        }
        if (aux!=NULL)
        {
            printf ("\nDesea modificar domicilio del usuario? s/n\n");
            fflush(stdin);
            scanf ("%c",&opcion);

            if (opcion == 's' || opcion == 'S')
            {
                printf ("\nIngrese nueva calle:\n");
                fflush(stdin);
                gets (cambios);
                strcpy(aux->datosUsuarios.domicilio.calle, cambios);

                printf ("\nIngrese nueva altura:\n");
                scanf ("%i", &nuevoNumero);
                aux->datosUsuarios.domicilio.altura = nuevoNumero;

                printf ("\nIngrese nuevo codigo postal:\n");
                scanf ("%i", &nuevoNumero);
                aux->datosUsuarios.domicilio.cp = nuevoNumero;

                printf ("\nIngrese nueva localidad\n:");
                fflush(stdin);
                gets (cambios);
                strcpy(aux->datosUsuarios.domicilio.localidad, cambios);

                printf ("\nIngrese ciudad:\n");
                fflush(stdin);
                gets (cambios);
                strcpy(aux->datosUsuarios.domicilio.ciudad, cambios);
            }

            printf ("\nDesea modificar el pais? s/n\n");
            fflush(stdin);
            scanf ("%c",&opcion);

            if (opcion == 's' || opcion == 'S')
            {
                printf ("\nIngrese nuevo pais:\n");
                fflush(stdin);
                gets (cambios);
                strcpy(aux->datosUsuarios.domicilio.pais, cambios);
            }
            printf ("\nUsuario modificado:\n");
            mostrarUnUsuario (aux);
        }
    }
    return listaUsuarios;
}

/// Modificar usernme de un usuario

nodoUsuarios * modificarUsername (nodoUsuarios * listaUsuarios)
{
    nodoUsuarios * aux = NULL;
    char opcion;
    char nuevoUser[20];

    if (listaUsuarios)
    {
        printf("\nBuscar usuario a modificar segun: A-DNI B- EMAIL\n");
        fflush(stdin);
        scanf ("%c",&opcion);

        if (opcion == 'A' || opcion == 'a')
        {
            aux = buscarUsuarioPorDni(listaUsuarios);
        }
        else if (opcion == 'B' || opcion == 'b')
        {
            aux = buscarUsuarioPorEmail(listaUsuarios);
        }
        else
        {
            printf ("\nOpcion invalida\n");
        }

        if (aux!=NULL)
        {

            printf ("\nIngrese el nuevo Username:\n");
            fflush (stdin);
            gets (nuevoUser);
            strcpy(aux->datosUsuarios.username, nuevoUser);
        }

        printf ("\nUsuario modificado:\n");
        mostrarUnUsuario (aux);
    }
    return listaUsuarios;
}


nodoLibros *cargarUnLibroManual(nodoLibros *listaLibros)
{
    stLibro libro;

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
    listaLibros = agregarAlFinalListaLibros(listaLibros, nuevoLibro);

    printf("\nLibro agregado exitosamente!\n");

    return listaLibros;
}


/// Baja lógica de un libro

nodoLibros* bajaDelLibro(nodoLibros * listaLibros) {
    nodoLibros * aux = listaLibros;
    nodoLibros * librosEncontrados = NULL; // Para almacenar los libros encontrados en la búsqueda
    int idLibro;

    char opcion;

    if (listaLibros) {
        printf("\nBuscar libro a eliminar segun: A-AUTOR B- TITULO C- CATEGORIA\n");
        printf("Ingrese opcion: ");
        scanf(" %c", &opcion);

        switch(opcion) {
            case 'A':
            case 'a':
                librosEncontrados = buscarLibroPorAutor(listaLibros);
                break;
            case 'B':
            case 'b':
                librosEncontrados = buscarLibroPorTitulo(listaLibros);
                break;
            case 'C':
            case 'c':
                librosEncontrados = buscarLibroPorCategoria(listaLibros);
                break;
            default:
                printf("\nOpcion invalida\n");
                return listaLibros;
        }

        if (librosEncontrados != NULL) {
            printf("\nLibros encontrados:\n");
            mostrarListaLibros(librosEncontrados);

            printf("\nIngrese el ID del libro que desea eliminar: ");
            scanf("%d", &idLibro);

            aux = buscarLibroPorId(librosEncontrados, idLibro);

            if (aux != NULL) {
                aux->datosLibros.eliminado = -1;
                printf("\nLibro dado de baja exitosamente: %s (ID: %d)\n", aux->datosLibros.titulo, aux->datosLibros.idLibro);
            } else {
                printf("\nNo se encontro el libro con el ID proporcionado.\n");
            }
        } else {
            printf("\nNo se encontraron libros que coincidan con la busqueda.\n");
        }
    } else {
        printf("\nNo hay libros en la lista.\n");
    }

    return listaLibros;
}

void mostrarUnLibro(nodoLibros* listaLibros)
{
    if (listaLibros) {
        printf("\n -----------------------\n");
        printf ("ID Libro: %i\n", listaLibros->datosLibros.idLibro);
        printf ("Titulo: %s\n", listaLibros->datosLibros.titulo);
        printf("Editorial: %s\n", listaLibros->datosLibros.editorial);
        printf("Autor: %s\n", listaLibros->datosLibros.autor);
        printf("Categoria: %s\n", listaLibros->datosLibros.categoria);
        printf("Valoracion: %f %d\n", listaLibros->datosLibros.valoracion);
        printf("\n -----------------------\n");

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

nodoLibros * agregarAlFinalListaLibros(nodoLibros * listaLibros, nodoLibros * nuevo)
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

void agregarLibroFavorito(nodoUsuarios *usuarioLogueado, nodoLibros *listaLibros, int idLibro)
{
    for (int i = 0; i < usuarioLogueado->datosUsuarios.validosLibrosFavs; i++) {
        if (usuarioLogueado->datosUsuarios.librosFavoritos[i] == idLibro) {
            printf("El libro ya está en tu lista de favoritos.\n");
            return;
        }
    }
    nodoLibros *libro = buscarLibroPorId(listaLibros, idLibro);
    if (libro == NULL) {
        printf("Libro no encontrado.\n");
        return;
    }

    if (usuarioLogueado->datosUsuarios.validosLibrosFavs < 50) {
        usuarioLogueado->datosUsuarios.librosFavoritos[usuarioLogueado->datosUsuarios.validosLibrosFavs] = idLibro;
        usuarioLogueado->datosUsuarios.validosLibrosFavs++;
        printf("Libro '%s' agregado a tus favoritos.\n", libro->datosLibros.titulo);
    } else {
        printf("No puedes agregar más libros a favoritos.\n");
    }
}

void gestionarLibrosFavoritos(nodoUsuarios *usuarioLogueado, nodoLibros *listaLibros)
 {
    printf("\nLibros Favoritos:\n");
    if (usuarioLogueado->datosUsuarios.validosLibrosFavs == 0) {
        printf("No tienes libros favoritos.\n");
    } else {
        for (int i = 0; i < usuarioLogueado->datosUsuarios.validosLibrosFavs; i++) {
            nodoLibros *libro = buscarLibroPorId(listaLibros, usuarioLogueado->datosUsuarios.librosFavoritos[i]);
            if (libro != NULL) {
                printf("%d. %s por %s\n", i + 1, libro->datosLibros.titulo, libro->datosLibros.autor);
            }
        }
    }

    char opcion;
    printf("¿Desea agregar un libro a favoritos (A) o quitar uno (Q)?\n");
    scanf(" %c", &opcion);

    if (opcion == 'A' || opcion == 'a') {
        int idLibro;
        printf("Ingrese el ID del libro a agregar a favoritos:\n");
        scanf("%d", &idLibro);
        agregarLibroFavorito(usuarioLogueado, listaLibros, idLibro);
    } else if (opcion == 'Q' || opcion == 'q') {
        if (usuarioLogueado->datosUsuarios.validosLibrosFavs == 0) {
            printf("No tienes libros favoritos para quitar.\n");
            return;
        }

        int libroAQuitar;
        printf("Ingrese el numero del libro a quitar (1-%d):\n", usuarioLogueado->datosUsuarios.validosLibrosFavs);
        scanf("%d", &libroAQuitar);

        if (libroAQuitar < 1 || libroAQuitar > usuarioLogueado->datosUsuarios.validosLibrosFavs) {
            printf("Opcion no valida.\n");
            return;
        }

        int idLibroAQuitar = usuarioLogueado->datosUsuarios.librosFavoritos[libroAQuitar - 1];

        for (int j = libroAQuitar - 1; j < usuarioLogueado->datosUsuarios.validosLibrosFavs - 1; j++) {
            usuarioLogueado->datosUsuarios.librosFavoritos[j] = usuarioLogueado->datosUsuarios.librosFavoritos[j + 1];
        }
        usuarioLogueado->datosUsuarios.validosLibrosFavs--;

        printf("Libro %s quitado de favoritos.\n", buscarLibroPorId(listaLibros, idLibroAQuitar)->datosLibros.titulo);
    } else {
        printf("Opcion no valida.\n");
    }
}

void quitarLibroFavorito(stUsuario* usuario, int idLibro)
 {
    int indice = -1;

    for (int i = 0; i < usuario->validosLibrosFavs; i++) {
        if (usuario->librosFavoritos[i] == idLibro) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        for (int i = indice; i < usuario->validosLibrosFavs - 1; i++) {
            usuario->librosFavoritos[i] = usuario->librosFavoritos[i + 1];
        }
        usuario->validosLibrosFavs--;
        printf("Libro con ID %d eliminado de favoritos.\n", idLibro);
    } else {
        printf("El libro con ID %d no se encuentra en los favoritos.\n", idLibro);
    }
}

nodoLibros* buscarLibroPorId(nodoLibros* listaLibros, int idLibro)
{
    nodoLibros* aux = listaLibros;
    while (aux != NULL) {
        if (aux->datosLibros.idLibro == idLibro && aux->datosLibros.eliminado == 0) {
            return aux;
        }
        aux = aux->sig;
    }
    return NULL;
}


void elegirListaAVerLibros (nodoLibros * listaLibros)
{
    char opcion;

    printf ("Elija lista a ver: A- Todos los libros B- Libros activos C- Libros eliminados\n");
    fflush(stdin);
    scanf("%c",&opcion);

    if (opcion == 'A' || opcion == 'a')
    {
         mostrarListaLibros(listaLibros);
    }
    else if (opcion == 'B' || opcion == 'b')
    {
        mostrarListaLibrosActivos(listaLibros);
    }
    else if (opcion == 'C' || opcion == 'c')
    {
        mostrarListaLibrosInactivos(listaLibros);
    }
    else
    {
        printf ("\nOpcion invalida\n");
    }
}


/// Ver listado solo de usuarios activos

void mostrarListaLibrosActivos (nodoLibros * listaLibros)
{
    while (listaLibros!=NULL)
    {
        if (listaLibros->datosLibros.eliminado == 0)
        {
            mostrarUnLibro(listaLibros);
        }
        listaLibros = listaLibros->sig;
    }

}

/// Ver listado solo de usuarios inactivos
void mostrarListaLibrosInactivos (nodoLibros * listaLibros)
{
    while (listaLibros!=NULL)
    {
        if (listaLibros->datosLibros.eliminado == -1)
        {
            mostrarUnLibro(listaLibros);
        }
        listaLibros = listaLibros->sig;
    }
}

