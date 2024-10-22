#include "Validaciones.h"


char username[10];

int validarStringNombre(char username[])
{
    for(int i=0; i<strlen(username); i++)
    {
        if(!isalpha(username[i]) && !isspace(username[i]))
        {
            return 0;
        }
    }
    return 1;
}

///2. VALIDAR STRING NUM
int validarStringNum(char username[])
{
    for(int i=0; i<strlen(username); i++)
    {
        if(!isdigit(username[i]))
        {
            return 0;
        }
    }
    return 1;
}

int validarMayusculaMinuscula(char contrasenia[])
{
    int tieneMayuscula = 0;
    int tieneMinuscula = 0;

    for (int i = 0; contrasenia[i] != '\0'; i++)
    {
        if (isupper(contrasenia[i]))
        {
            tieneMayuscula = 1;
        }
        if (islower(contrasenia[i]))
        {
            tieneMinuscula = 1;
        }
    }
    return tieneMayuscula && tieneMinuscula;
}

///3. VALIDAR MAIL
int validarMail(char mail[])
{
    int arroba = 0;
    int largo = strlen(mail);

    if (largo < 5 || strcmp(&mail[largo - 4], ".com") != 0)
    {
        return 0;
    }

    for (int i = 0; i < largo; i++)
    {
        if (mail[i] == '@')
        {
            if (arroba)
            {
                return 0;
            }
            arroba = 1;
        }
    }

    if (!arroba)
    {
        return 0;
    }
    return 1;
}


///4. VALIDAR LENGHT DE LA CONTRASENIA
int validarLenghtContrasenia(char password[])
{
    if(strlen(password)<5)
    {
        return 0;
    }
    return 1;
}

///5. VALIDAR CONTRASENIA
int validarContrasenia(char password[], char password1[])
{
    if(strcmp(password, password1)==0)
    {
        return 1;
    }
    return 0;
}

int validarFechaNacimiento(char *fecha) {
    int dia, mes, anio;
    if (sscanf(fecha, "%d/%d/%d", &dia, &mes, &anio) == 3) {
        if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && anio >= 1900 && anio <= 2024) {
            return 1;  // Fecha válida
        }
    }
    return 0;  // Fecha no válida
}

int validarGenero(char genero) {
    genero = toupper(genero);  // Convierte a mayúscula para evitar problemas con minúsculas
    return (genero == 'M' || genero == 'F' || genero == 'O');
}

int validarAltura(char *alturaStr) {
    for (int i = 0; i < strlen(alturaStr); i++) {
        if (!isdigit(alturaStr[i])) {
            return 0;  // Si encuentra un carácter no numérico, no es válido
        }
    }
    return atoi(alturaStr) > 0;  // Asegura que sea un número mayor que 0
}
