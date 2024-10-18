#include "menu.h"


#define ADMIN_USERNAME "admin"
#define ADMIN_PASSWORD "admin123"


nodoUsuarios * listaUsuarios= NULL;
nodoLibros * listaLibros= NULL;


int menu()
{
    int opcion =0;

    do
    {
        mostrarMenuPrincipal();
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            registrarUsuario(&listaUsuarios);
            break;
        case 2:
            system("cls");
            iniciarSesion(listaUsuarios);
            system("pause");
            system("cls");

            break;
        case 3:
            system("cls");

            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción no válida.\n");
        }
    }
    while(opcion != 3);

    return 0;
}

void mostrarMenuPrincipal()
{
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1. Registrarse\n");
    printf("2. Iniciar sesion\n");
    printf("3. Salir\n");
}

void registrarUsuario(nodoUsuarios **listaUsuarios) {
    stUsuario usuario;
    char username[20];
    char email[100];
    char opcionStr[10];
    int rta = 0;
    int correcto = 0;
    int opcion = 0;

    do {
        printf("Ingrese su Nombre de Usuario:  \n");
        fflush(stdin);
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = 0;
        rta = verificarUsuarioExistente(*listaUsuarios, username);

        if (rta == 1) {
            printf("El nombre de usuario ya existe.\n");
            printf("1. Intentar de nuevo\n");
            printf("2. Salir\n");
            printf("Elija una opcion: ");
            fflush(stdin);
            fgets(opcionStr, sizeof(opcionStr), stdin);
            opcion = atoi(opcionStr);
            if (opcion == 2) {
                printf("Registro cancelado.\n");
                return;
            }
        }
    } while (rta == 1);
    strcpy(usuario.username, username);

    do {
        printf("Ingrese su email:  \n");
        fflush(stdin);
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = 0;

        correcto = validarMail(email);

        if (correcto != 1) {
            printf("Formato de email invalido. Debe contener un @ y .com.\n");
            printf("1. Intentar de nuevo\n");
            printf("2. Salir\n");
            printf("Elija una opcion: ");
            fflush(stdin);
            fgets(opcionStr, sizeof(opcionStr), stdin);
            opcion = atoi(opcionStr);

            if (opcion == 2) {
                printf("Registro cancelado.\n");
                system("cls");
                return;
            }
        }
        rta = verificarEmailExistente(*listaUsuarios, email);

        if (rta == 1) {
            printf("El email ya se encuentra registrado.\n");
            printf("1. Intentar de nuevo\n");
            printf("2. Salir\n");
            printf("Elija una opcion: ");
            fflush(stdin);
            fgets(opcionStr, sizeof(opcionStr), stdin);
            opcion = atoi(opcionStr);
            if (opcion == 2) {
                printf("Registro cancelado.\n");
                return;
            }
        }
    } while (rta == 1 || correcto != 1);
    strcpy(usuario.email, email);

    printf("Ingrese su DNI: \n");
    fflush(stdin);
    fgets(usuario.dni, sizeof(usuario.dni), stdin);
    usuario.dni[strcspn(usuario.dni, "\n")] = 0;

    printf("Ingrese su fecha de nacimiento (dd/mm/aaaa): \n");
    fflush(stdin);
    fgets(usuario.fechaNacimiento, sizeof(usuario.fechaNacimiento), stdin);
    usuario.fechaNacimiento[strcspn(usuario.fechaNacimiento, "\n")] = 0;

    printf("Ingrese su genero (M/F/O): \n");
    scanf(" %c", &usuario.genero);

    printf("Ingrese su calle: \n");
    fflush(stdin);
    fgets(usuario.domicilio.calle, sizeof(usuario.domicilio.calle), stdin);
    usuario.domicilio.calle[strcspn(usuario.domicilio.calle, "\n")] = 0;

    printf("Ingrese la altura de su domicilio: \n");
    scanf("%d", &usuario.domicilio.altura);

    printf("Ingrese el codigo postal: \n");
    scanf("%d", &usuario.domicilio.cp);

    printf("Ingrese la ciudad: \n");
    fflush(stdin);
    fgets(usuario.domicilio.ciudad, sizeof(usuario.domicilio.ciudad), stdin);
    usuario.domicilio.ciudad[strcspn(usuario.domicilio.ciudad, "\n")] = 0;

    printf("Ingrese el pais: \n");
    fflush(stdin);
    fgets(usuario.domicilio.pais, sizeof(usuario.domicilio.pais), stdin);
    usuario.domicilio.pais[strcspn(usuario.domicilio.pais, "\n")] = 0;

    usuario = cargarContraseniaRegistro(usuario);

    usuario.eliminado= 0;
    for (int i = 0; i < 50; i++) {
        usuario.librosFavoritos[i] = 0;
        }

    usuario.idUsuario = generarIdUsuarios(*listaUsuarios);

    nodoUsuarios *nuevoNodo = crearNodoUsuario(usuario);
    *listaUsuarios = agregarUsuarioAlFinalLista(*listaUsuarios, nuevoNodo);

    printf("Usuario registrado exitosamente!\n");
}

nodoUsuarios * iniclista()
{
    return NULL;
}

nodoUsuarios * crearNodoUsuario(stUsuario usuario)
{
    nodoUsuarios * aux= (nodoUsuarios*) malloc(sizeof(nodoUsuarios));
    aux->datosUsuarios= usuario;
    aux->sig=NULL;
    return aux;
}

nodoUsuarios *buscarUltimoNodoListaUsuarios(nodoUsuarios *lista)
 {
    nodoUsuarios *aux = lista;
    if (aux != NULL)
    {
        while (aux->sig != NULL)
         {
            aux = aux->sig;
        }
    }
    return aux;
}

nodoUsuarios * agregarUsuarioAlFinalLista(nodoUsuarios * listaUsuarios, nodoUsuarios * nuevo)
{
    if(!listaUsuarios)
    {
        listaUsuarios=nuevo;
    }
    else
    {
        nodoUsuarios * aux= buscarUltimoNodoListaUsuarios(listaUsuarios);
        aux->sig=nuevo;
    }
    return listaUsuarios;
}

stUsuario cargarContraseniaRegistro(stUsuario usuario)
{
    char contrasenia[30];
    char confirmacion[30];

    do {
        printf("Ingrese su nueva contrasenia:  \n");
        fflush(stdin);
        gets(contrasenia);

        printf("Vuelva a ingresar su contrasenia \n");
        fflush(stdin);
        gets(confirmacion);

        if (!validarContrasenia(contrasenia, confirmacion))
        {
            printf("Las contrasenias no coinciden\n");
        }
        else if (!validarMayusculaMinuscula(contrasenia))
        {
            printf("La contrasenia debe tener al menos una mayuscula y una minuscula\n");
        }

    } while (!validarContrasenia(contrasenia, confirmacion) || !validarMayusculaMinuscula(contrasenia));

    strcpy(usuario.password, contrasenia);

    return usuario;
}

int generarIdUsuarios(nodoUsuarios *listaUsuarios)
{
    int id = 0;
    nodoUsuarios *aux = listaUsuarios;

    while (aux)
    {
        if (aux->datosUsuarios.idUsuario > id)
        {
            id = aux->datosUsuarios.idUsuario;
        }
        aux = aux->sig;
    }
    return id + 1;
}

int verificarUsuarioExistente(nodoUsuarios *listaUsuarios, char username[])
{
    nodoUsuarios *aux = listaUsuarios;

    while (aux != NULL)
    {
        if (strcmp(aux->datosUsuarios.username, username) == 0)
        {
            return 1;
        }
        aux = aux->sig;
    }

    return 0;  /// devuelve 0 si el usuario no existe
}

int verificarEmailExistente(nodoUsuarios *listaUsuarios, char email[])
{
    nodoUsuarios *aux = listaUsuarios;

    while (aux != NULL)
    {
        if (strcmp(aux->datosUsuarios.email, email) == 0)
        {
            return 1;
        }
        aux = aux->sig;
    }

    return 0; /// devuelve 1 si el mail ya existe
}


void iniciarSesion(nodoUsuarios *listaUsuarios)
{
    char email[30], password[20];
    nodoUsuarios *usuarioActual = listaUsuarios;

    printf("\n=== INICIO DE SESION ===\n");
    printf("Ingrese su email: ");
    fflush(stdin);
    gets(email);

    printf("Ingrese su contrasenia: ");
    fflush(stdin);
    gets(password);

    if (strcmp(email, ADMIN_USERNAME) == 0 && strcmp(password, ADMIN_PASSWORD) == 0) {
        printf("Inicio de sesion exitoso como administrador.\n");
        menuAdministrador();
        return;
    }

    while (usuarioActual != NULL) {
        if (strcmp(usuarioActual->datosUsuarios.email, email) == 0) {
            if (strcmp(usuarioActual->datosUsuarios.password, password) == 0) {
                printf("Inicio de sesion exitoso.\n");
                menuPostLogin(usuarioActual);
                return;
            } else {
                printf("Contrasenia incorrecta. Por favor, intente de nuevo.\n");
                return;
            }
        }
        usuarioActual = usuarioActual->sig;
    }

    printf("No existe usuario con ese email.\n");
}

void menuAdministrador() {
    int opcion;

    do {
        printf("\n=== MENU ADMINISTRADOR ===\n");
        printf("1. Ver usuarios\n");
        printf("2. Agregar usuario\n");
        printf("3. Eliminar usuario\n");
        printf("4. Ver libros\n");
        printf("5. Agregar libro\n");
        printf("6. Eliminar libro\n");
        printf("7. Salir al menu principal\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                elegirListaAVer(listaUsuarios);
                system("pause");
                system("cls");
                break;
            case 2:
                registrarUsuario(&listaUsuarios);
                system("pause");
                system("cls");
                break;
            case 3:
                bajaDelUsuario(listaUsuarios);
                system("pause");
                system("cls");
                break;
            case 4:
                elegirListaAVerLibros(listaLibros);
                system("pause");
                system("cls");
                break;
            case 5:
                listaLibros=cargarUnLibroManual(listaLibros);
                system("pause");
                system("cls");
                break;
            case 6:
                listaLibros= bajaDelLibro(listaLibros);
                system("pause");
                system("cls");
                break;
            case 7:
                guardarUsuariosEnArchivo(listaUsuarios);
                guardarLibrosEnArchivo(listaLibros);
                printf("Cerrando sesion...\n");
                system("cls");
                return;
            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (opcion != 7);
}

void menuPostLogin(nodoUsuarios *usuarioLogueado)
{
    int opcion;

    do {
        printf("\n=== MENU POST LOGIN ===\n");
        printf("1. Modificar informacion personal\n");
        printf("2. Menu de libros\n");
        printf("3. Cerrar sesion\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                system("cls");
                modificarInformacionPersonal(usuarioLogueado);
                break;
            case 2:
                system("cls");
                menuLibros(usuarioLogueado,listaLibros);
                break;
            case 3:
                guardarUsuariosEnArchivo(listaUsuarios);
                printf("Cerrando sesion...\n");
                system("cls");
                return;
            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (opcion != 3);
}

void modificarInformacionPersonal(nodoUsuarios* usuario)
{
    int opcion;
    do
    {
        printf("\n=== MODIFICAR INFORMACION PERSONAL ===\n");
        printf("1. Cambiar email\n");
        printf("2. Cambiar contrasenia\n");
        printf("3. Cambiar nombre de usuario\n");
        printf("4. Volver\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese nuevo email: ");
            fflush(stdin);
            gets(usuario->datosUsuarios.email);
            printf("Email actualizado.\n");
            system("pause");
            system("cls");
            break;
        case 2:
            printf("Ingrese nueva contrasenia: ");
            fflush(stdin);
            gets(usuario->datosUsuarios.password);
            printf("Contrasenia actualizada.\n");
            system("pause");
            system("cls");
            break;
        case 3:
            printf("Ingrese nuevo nombre de usuario: ");
            fflush(stdin);
            gets(usuario->datosUsuarios.username);
            printf("Nombre de usuario actualizado.\n");
            system("pause");
            system("cls");
            break;
        case 4:
            printf("Retorno exitoso.\n");
            system("pause");
            system("cls");
            return;
        default:
            printf("Opcion no valida.\n");
        }
    }
    while(opcion != 4);
}


/// Cargar libros desde el archivo al iniciar
void menuLibros(nodoUsuarios * usuarioLogueado, nodoLibros * listaLibros)
{
    nodoLibros * aux=NULL;
    int opcion;
    do
    {
        printf("\n=== MENU DE LIBROS ===\n");
        printf("1. Consultar libros por categoria\n");
        printf("2. Consultar libros por autor\n");
        printf("3. Buscar libro por titulo\n");
        printf("4. Agregar/Quitar libro favorito\n");
        printf("5. Mostrar todos los libros\n");
        printf("6. Salir al menu principal\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            aux=buscarLibroPorCategoria(listaLibros);
            mostrarUnLibro(aux);
            system("pause");
            system("cls");
            break;
        case 2:
            aux=buscarLibroPorAutor(listaLibros);
            mostrarListaLibros(aux);
            system("pause");
           system("cls");
            break;
        case 3:
            aux=buscarLibroPorTitulo(listaLibros);
            mostrarUnLibro(aux);
            system("pause");
            system("cls");
            break;
        case 4:
            printf("\n LISTADO DE LIBROS\n");
            mostrarListaLibrosActivos(listaLibros);
            int idLibro;
            gestionarLibrosFavoritos(usuarioLogueado, listaLibros);

            break;
        case 5:
            mostrarListaLibros(listaLibros);
            system("pause");
            system("cls");
            break;
        case 6:
            guardarLibrosEnArchivo(listaLibros);
            printf("Regresando al menu principal...\n");
            system("cls");
            break;
        default:
            printf("Opcion no valida.\n");
        }
    }
    while(opcion != 6);
}


void guardarUsuariosEnArchivo(nodoUsuarios *listaUsuarios) {
    FILE *archivo = fopen(ARCHIVO_USUARIOS, "wb");
    if (!archivo) {
        printf("Error al abrir el archivo de usuarios.\n");
        return;
    }

    nodoUsuarios *aux = listaUsuarios;

    while (aux != NULL) {
        fwrite(&aux->datosUsuarios, sizeof(stUsuario), 1, archivo);
        aux = aux->sig;
    }

    fclose(archivo);
}

void guardarLibrosEnArchivo(nodoLibros *listaLibros) {
    FILE *archivo = fopen(ARCHIVO_LIBROS, "wb");
    if (!archivo) {
        printf("Error al abrir el archivo de libros.\n");
        return;
    }

    nodoLibros *aux = listaLibros;

    while (aux != NULL) {
        fwrite(&aux->datosLibros, sizeof(stLibro), 1, archivo);
        aux = aux->sig;
    }

    fclose(archivo);
}


