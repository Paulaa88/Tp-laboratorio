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


///6. ENCONTRAR USUARIO
/*int encontrarUsuario (nodoUsuarios * usu, char nombre[], char contra[])
{
    nodoUsuarios* aux=usu;
    int flag=0;
    while (usu->sig!=NULL && flag==0)
    {
        if (strcmp(nombre,aux->stUsuario.username)==0)
            flag=contrastarContra(aux, contra);
        else
            aux=aux->sig;
        return flag;
    }
}

///7.COMPARA CONTRASEÑA
int contrastarContra (nodoUsuarios* aux, char contra[])
{
    if (strcmp(aux.>stUsuario.password,contra)==0)
        return 2;
    else
        return 1;
}
*/
