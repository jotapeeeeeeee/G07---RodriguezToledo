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
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <presentacion.h>
#include <tdalibros.h>
#include <libros.h>
#include <direct.h>

/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos internos ================================================ */

/* === Definiciones de variables internas ====================================================== */

/* === Declaraciones de funciones internas ===================================================== */

/* === Definiciones de funciones internas ====================================================== */
/*aqui iria main*/

int main()
{
    char opcion;
    char nombre[] = "media/libros.dat";
    char nombrestock[] = "media/stockbajo.txt";
    libro unLibro;

    control(nombre);
    mostrarPresentacion();

    do
    {
        mostrarMenu();
        scanf(" %c", &opcion);
        while (getchar() != '\n')
            ;

        switch (tolower(opcion))
        {
        case 'a':
            printf("\n>> Registrar un nuevo libro:\n");

            IngresoDatos(nombre); // Usa libros.dat
            pausarPantalla();
            break;

        case 'b':
            printf("\n>> Listar todos los libros:\n");
            listarLibros(nombre); // Usa libros.dat
            pausarPantalla();
            break;

        case 'c':
            printf("\n>> Mostrar libros por genero:\n");
            mostrarLibrosPorGenero(nombre); // Usa libros.dat
            pausarPantalla();
            break;

        case 'd':
            printf("\n>> Modificar el precio de un libro:\n");
            modificarPrecioLibro(nombre); // Usa libros.dat
            pausarPantalla();
            break;

        case 'e':
            printf("\n>> Generar reporte de stock bajo:\n");
            generarReporteStockBajo(nombre, nombrestock); // Usa libros.dat y crea stockbajo.txt
            pausarPantalla();
            break;

        case 's':
            printf("\nSaliendo del programa...\n");
            break;

        default:
            printf("\nOpción incorrecta. Intente de nuevo.\n");
            pausarPantalla();
            break;
        }
    } while (tolower(opcion) != 's');

    return 0;
}

/* === Definiciones de funciones externas ====================================================== */

/* === Cierre de archivo ======================================================================== */
