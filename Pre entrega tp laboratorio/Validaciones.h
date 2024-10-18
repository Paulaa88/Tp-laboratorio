#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int validarStringNombre(char username[]);
int validarStringNum(char username[]);
int validarMayusculaMinuscula(char contrasenia[]);
int validarLenghtContrasenia(char password[]);
int validarContrasenia(char password[], char password1[]);
int validarMail(char mail[]);

//int encontrarUsuario (nodoUsuarios * usu, char nombre[], char contra[]):
//int contrastarContra (nodoUsuarios* aux, char contra[]);

#endif // VALIDACIONES_H_INCLUDED
