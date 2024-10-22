#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include "menu.h"

#define ARCHIVO_USUARIOS "usuarios.dat"
#define ARCHIVO_LIBROS "libros.dat"

int main()
{

    printf("\n");
    printf("\n");

    printf("-----      ---       ---     --    --  --      --     ---       -----  -------   ------   ------ \n");
    printf("--  --   --   --   --   --   --   --   ---    ---    --  --     --        --     --       --   --    \n");
    printf("----    --    --  --     --  ----      --  --  --   -- -- --    -----     --     ----     -----     \n");
    printf("--  --   --   --   --   --   --   --   --      --   --     --       --    --     --       --    --      \n");
    printf("-----      ---       ---     --    --  --      --  --       --  -----     --     ------   --    -- \n");

    printf("\n");
    printf("\n");

    printf("---------------------------------------- TU BIBLIOTECA PREFERIDA -----------------------------------------------\n");

    srand(time(NULL));

    //int cantidadUsuarios = 20;
    //int cantidadLibros = 50;

    //cargarUsuariosAleatorios(cantidadUsuarios);

    //cargarLibrosAleatorios(cantidadLibros);



    menu();
    return 0;
}


/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void generarStringAleatorio(char *cadena, int longitud) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < longitud - 1; i++) {
        cadena[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    cadena[longitud - 1] = '\0';
}

// Función para cargar usuarios aleatorios
void cargarUsuariosAleatorios(int cantidad) {
    FILE *archivo = fopen(ARCHIVO_USUARIOS, "ab");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de usuarios.\n");
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        stUsuario nuevoUsuario;

        nuevoUsuario.idUsuario = i + 1;
        generarStringAleatorio(nuevoUsuario.email, 10);
        strcat(nuevoUsuario.email, "@mail.com");
        generarStringAleatorio(nuevoUsuario.password, 8);
        generarStringAleatorio(nuevoUsuario.username, 8);
        nuevoUsuario.esAdmin = rand() % 2;
        nuevoUsuario.genero = (rand() % 2 == 0) ? 'M' : 'F';
        sprintf(nuevoUsuario.fechaNacimiento, "%02d/%02d/%04d", rand() % 30 + 1, rand() % 12 + 1, 1990 + rand() % 30);
        sprintf(nuevoUsuario.dni, "%08d", rand() % 100000000);

        generarStringAleatorio(nuevoUsuario.domicilio.calle, 8);
        nuevoUsuario.domicilio.altura = rand() % 2000 + 1;
        nuevoUsuario.domicilio.cp = rand() % 9000 + 1000;
        generarStringAleatorio(nuevoUsuario.domicilio.ciudad, 8);
        generarStringAleatorio(nuevoUsuario.domicilio.localidad, 8);
        generarStringAleatorio(nuevoUsuario.domicilio.pais, 8);

        nuevoUsuario.validosLibrosFavs = 0;
        nuevoUsuario.eliminado = 0;

        fwrite(&nuevoUsuario, sizeof(stUsuario), 1, archivo);
    }

    fclose(archivo);
    printf("Se cargaron %d usuarios aleatorios exitosamente.\n", cantidad);
}

void cargarLibrosAleatorios(int cantidad) {
    FILE *archivo = fopen(ARCHIVO_LIBROS, "ab");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de libros.\n");
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        stLibro nuevoLibro;

        nuevoLibro.idLibro = i + 1;
        generarStringAleatorio(nuevoLibro.titulo, 10);
        generarStringAleatorio(nuevoLibro.editorial, 8);
        generarStringAleatorio(nuevoLibro.autor, 8);
        generarStringAleatorio(nuevoLibro.categoria, 8);
        nuevoLibro.valoracion = (float)(rand() % 50) / 10; // Valoración entre 0.0 y 5.0
        nuevoLibro.eliminado = 0; // Libro activo

        fwrite(&nuevoLibro, sizeof(stLibro), 1, archivo);
    }

    fclose(archivo);
    printf("Se cargaron %d libros aleatorios exitosamente.\n", cantidad);
}

/// //////////////////////////// FALTA ///////////////////////////////////////////

/// * VALIDACIONES DE SOLO NUMEROS EN ALTURA, DE M, F U O EN GENERO,
