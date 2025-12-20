/* Copyright 2021, Cátedra de Informática y Programación I
 * Departamento de Electricidad, Electrónica y Computación
 * Facultad de Ciencias Exactas y Tecnología
 * Universidad Nacional de Tucuman
 * Copyright 2021, Mariana Sánchez <msanchez@herrera.unt.edu.ar>, Enzo A. Sémola <esemola@herrera.unt.edu.ar>
 * All rights reserved.
 */

/* === Inclusiones de cabeceras ================================================================ */
/*#include "plantilla.h"
#include "persona.h"
*/
#include <presentacion.h>
#include <stdlib.h>
#include <stdio.h>
#include <libros.h>
#include <ctype.h>

/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos internos ================================================ */

/* === Definiciones de variables internas ====================================================== */

/* === Declaraciones de funciones internas ===================================================== */

/* === Definiciones de funciones internas ====================================================== */
/*aqui iria main*/
/* === Definiciones de funciones externas ====================================================== */
void mostrarPresentacion()
{
  printf("***********************************************\n");
  printf("    Integrantes: Toledo Juan Pablo, Rodriguez Gonzalo    \n");
  printf("    Grupo: 7                               \n");
  printf("    Carrera: Ingenieria en Computacion, Ingeniería Electronica  \n");
  printf("    Trabajo: Sistema de Stock para una Libreria \n");
  printf("***********************************************\n\n");
}

void mostrarMenu()
{
  printf("\n----- MENU -----\n");
  printf("a) Registrar un libro\n");
  printf("b) Listar todos los libros\n");
  printf("c) Mostrar libros por genero\n");
  printf("d) Modificar el precio de un libro\n");
  printf("e) Generar reportes de stock bajo\n");
  printf("s) Salir del programa\n");
  printf("Ingrese una opcion: ");
}

void pausarPantalla()
{
  char c;
  printf("Presione <Enter> para continuar.... ");
  do
  {
    c = getchar(); // Leer un carácter
    if (c != '\n')
    {
      printf("Por favor, presione solo <Enter> para continuar....");
      // Limpiar el buffer si se ingresaron más caracteres
      while (getchar() != '\n')
        ;
    }
  } while (c != '\n'); // Repetir hasta que se presione solo <Enter>
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
/* === Ciere de archivo ======================================================================== */
