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
#include <libros.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>

/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos internos ================================================ */

/* === Definiciones de variables internas ====================================================== */

/* === Declaraciones de funciones internas ===================================================== */

/* === Definiciones de funciones internas ====================================================== */
/*aqui iria main*/
/* === Definiciones de funciones externas ====================================================== */
// Archivo: gestion_libros.c

// Función para capitalizar palabras
void capitalizarPalabras(char cadena[])
{
  int nuevaPalabra = 1;
  for (int i = 0; i < strlen(cadena); i++)
  {
    if (isspace(cadena[i]))
    {
      nuevaPalabra = 1;
    }
    else
    {
      if (nuevaPalabra && isalpha(cadena[i]))
      {
        cadena[i] = toupper(cadena[i]);
        nuevaPalabra = 0;
      }
      else
      {
        cadena[i] = tolower(cadena[i]);
      }
    }
  }
}

// Función para validar nombres
int nombreValido(char cadena[])
{
  for (int i = 0; i < strlen(cadena); i++)
  {
    if (!isalpha(cadena[i]) && cadena[i] != ' ' && cadena[i] != '\'')
    {
      printf("Nombre inválido. Intente de nuevo.\n");
      return 0;
    }
  }
  return 1;
}

// Función para controlar existencia de archivo
void control(char nombre[])
{
  _mkdir("media"); // Crea carpeta si no existe

  FILE *p = fopen(nombre, "rb");
  if (p == NULL)
  {
    printf("No se pudo abrir el archivo, se intentara crearlo...\n");

    p = fopen(nombre, "wb");
    if (p == NULL)
    {
      perror("Error al crear el archivo");
      exit(1);
    }
    else
    {
      printf("Archivo creado exitosamente.\n");
    }
  }
  else
  {
    printf("Archivo ya existe, se abrio correctamente.\n");
  }

  fclose(p);
}

// Función para ingresar precios validados
float IngresoPrecio()
{
  char cad[15];
  int valido, cantPunto;

  do
  {
    valido = 1;
    cantPunto = 0;
    printf("Ingresar el precio: ");
    fgets(cad, 15, stdin);
    cad[strlen(cad) - 1] = '\0';

    if (cad[0] == '\0')
    {
      valido = 0;
      continue;
    }

    for (int i = 0; i < strlen(cad); i++)
    {
      if (!isdigit(cad[i]) && cad[i] != '.')
      {
        valido = 0;
        break;
      }
      if (cad[i] == '.')
        cantPunto++;
    }

    if (cantPunto > 1)
      valido = 0;
  } while (!valido);

  return atof(cad);
}

// Función para ingresar stock validado
int IngresoStock()
{
  char cad[10];
  int valido;

  do
  {
    valido = 1;
    printf("Ingresar el stock: ");
    fgets(cad, 10, stdin);
    cad[strlen(cad) - 1] = '\0';

    if (cad[0] == '\0')
    {
      valido = 0;
      continue;
    }

    for (int i = 0; i < strlen(cad); i++)
    {
      if (!isdigit(cad[i]))
      {
        valido = 0;
        break;
      }
    }
  } while (!valido);

  return atoi(cad);
}

// Función para generar códigos únicos
int ingresarCodigoUnico(char nombreArchivo[])
{
  FILE *pf = fopen(nombreArchivo, "rb");
  if (pf == NULL)
    return 1;

  libro aux;
  int maxCodigo = 0;

  while (fread(&aux, sizeof(libro), 1, pf) == 1)
  {
    if (aux.unProducto.codigo > maxCodigo)
      maxCodigo = aux.unProducto.codigo;
  }

  fclose(pf);
  return maxCodigo + 1;
}

// Función para validar números
int numeroValido(char cadena[])
{
  for (int i = 0; cadena[i] != '\0'; i++)
  {
    if (!isdigit(cadena[i]))
    {
      printf("Codigo invalido. Intente de nuevo.\n");
      return 0;
    }
  }
  return 1;
}

// Mostrar detalles de un libro
void mostrarLibro(libro l)
{
  printf("\nLibro [%d]: %s - %s - %c\n",
         l.unProducto.codigo, l.titulo, l.autor, l.genero);
  printf("Precio: $%.2f - Stock: %d\n",
         l.unProducto.precio, l.unProducto.stock);
  printf("Descripcion: %s\n", l.descripcion);
}

// Registrar nuevo libro
libro registrarLibro(char nombre[])
{
  libro unLibro;
  printf("Ingrese el titulo del libro: ");
  fgets(unLibro.titulo, 50, stdin);
  unLibro.titulo[strcspn(unLibro.titulo, "\n")] = '\0';
  capitalizarPalabras(unLibro.titulo);

  do
  {
    printf("Ingrese el autor: ");
    fgets(unLibro.autor, 50, stdin);
    unLibro.autor[strcspn(unLibro.autor, "\n")] = '\0';
    capitalizarPalabras(unLibro.autor);
  } while (!nombreValido(unLibro.autor));

  printf("Ingrese la descripcion: ");
  fgets(unLibro.descripcion, 100, stdin);
  unLibro.descripcion[strcspn(unLibro.descripcion, "\n")] = '\0';

  do
  {
    printf("Géneros: N-Novela, I-Infantil, C-Ciencia Ficcion, D-Distopia, F-Fantasia\n");
    printf("Ingrese el genero: ");
    unLibro.genero = toupper(getchar());
    while (getchar() != '\n')
      ;
  } while (strchr("NICDF", unLibro.genero) == NULL);

  unLibro.unProducto.precio = IngresoPrecio();
  unLibro.unProducto.stock = IngresoStock();
  unLibro.unProducto.codigo = ingresarCodigoUnico(nombre);

  return unLibro;
}

void IngresoDatos(char nombre[])
{
  FILE *p;
  libro l;
  p = fopen(nombre, "a");
  l = registrarLibro(nombre);

  fwrite(&l, sizeof(l), 1, p);
  fclose(p);
  return;
}

// Listar todos los libros
void listarLibros(char nombre[])
{
  libro l;
  FILE *archivo = fopen(nombre, "r");

  printf("\n Listado de Libros");
  while (feof(archivo) == 0)
  {
    fread(&l, sizeof(l), 1, archivo);
    if (feof(archivo) == 0)
    {
      mostrarLibro(l);
    }
  }
  fclose(archivo);
  return;
}

// Modificar precio de un libro
void modificarPrecioLibro(char nombre[])
{
  FILE *archivo = fopen(nombre, "rb+");
  if (archivo == NULL)
  {
    printf("Error: No se pudo abrir el archivo\n");
    return;
  }

  char codigoCad[10];
  int codigo, encontrado = 0;
  libro aux;

  do
  {
    printf("Ingrese el codigo del libro: "); // imprime el codigo del libro
    fgets(codigoCad, 10, stdin);
    codigoCad[strlen(codigoCad) - 1] = '\0';
  } while (!numeroValido(codigoCad)); // verifica que sea un caracter numerico

  codigo = atoi(codigoCad); // convierte a entero

  while (fread(&aux, sizeof(libro), 1, archivo) == 1)
  {
    if (aux.unProducto.codigo == codigo) // lee el archivo hasta encontrar el codigo que coincida con el libro
    {
      printf("Libro encontrado. Precio actual: %.2f\n", aux.unProducto.precio);
      aux.unProducto.precio = IngresoPrecio();

      fseek(archivo, -sizeof(libro), SEEK_CUR); // mueve el cursor hacia atrás una estructura
      fwrite(&aux, sizeof(libro), 1, archivo);  //  sobrescribe el libro con el nuevo precio
      encontrado = 1;                           // valor de verdad de encontrado, se encontro el libro
      printf("Precio actualizado correctamente.\n");
      break;
    }
  }

  if (!encontrado)
  {
    printf("Libro no encontrado.\n"); // en caso de encontrado = 0, muestra este mensaje
  }

  fclose(archivo);
}

// Mostrar libros por género
void mostrarLibrosPorGenero(char nombre[])
{
  control(nombre);
  FILE *archivo = fopen(nombre, "rb");
  if (archivo == NULL)
  {
    printf("Error: No se pudo abrir el archivo\n");
    return;
  }

  char genero;
  int encontrado = 0;
  libro aux;

  do
  {
    printf("Generos disponibles: N, I, C, D, F\n");
    printf("Ingrese genero a buscar: ");
    genero = fgetc(stdin); // elige una letra
    while (fgetc(stdin) != '\n')
      ;
    genero = toupper(genero); // la convierte a mayuscula
  } while (strchr("NICDF", genero) == NULL); // verifica que se repite el do while mientras no sea "NICDF"

  while (fread(&aux, sizeof(libro), 1, archivo) == 1)
  {
    if (aux.genero == genero)
    {
      mostrarLibro(aux); // muestra los libros que hay en el archivo
      encontrado = 1;    // valor de verdad de que se encontro un libro
    }
  }

  if (!encontrado) // en caso de que encontrado siga = 0
  {
    printf("No hay libros del genero '%c'\n", genero); // muestra este mensaje
  }

  fclose(archivo);
}

// Función para ingresar límite de stock
int ingresarStockLimite()
{
  char cad[10];
  int valido;

  do
  {
    valido = 1;
    printf("Ingrese el valor de stock limite: "); // ingresa el valor del stock a verificar
    fgets(cad, 10, stdin);
    cad[strlen(cad) - 1] = '\0';

    if (cad[0] == '\0') // verifica si el arreglo esta vacio
    {
      valido = 0;
      continue;
    }

    for (int i = 0; i < strlen(cad); i++)
    {
      if (!isdigit(cad[i])) // verifica que cada slot de la cadena sea un digito
      {
        valido = 0;
        break;
      }
    }
  } while (!valido); // mientras que valido no cambie de valor, se repetira el do while

  return atoi(cad); // retorna entero
}

// Generar reporte de stock bajo
void generarReporteStockBajo(char nombre[], char nombre1[])
{
  FILE *archivo = fopen(nombre, "rb");
  if (archivo == NULL)
  {
    printf("Error: No se pudo abrir archivo de libros\n");
    return;
  }

  FILE *reporte = fopen(nombre1, "w");
  if (reporte == NULL)
  {
    printf("Error: No se pudo crear el reporte\n");
    fclose(archivo);
    return;
  }

  int limite = ingresarStockLimite();
  libro aux;
  int contador = 0;

  while (fread(&aux, sizeof(libro), 1, archivo) == 1) // lee todo el archivo y busca que el stock sea menor que el limite
  {
    if (aux.unProducto.stock < limite)
    {
      fprintf(reporte, "Codigo: %d\n", aux.unProducto.codigo);
      fprintf(reporte, "Titulo: %s\n", aux.titulo);
      fprintf(reporte, "Autor: %s\n", aux.autor);
      fprintf(reporte, "Genero: %c\n", aux.genero);
      fprintf(reporte, "Precio: %.2f\n", aux.unProducto.precio);
      fprintf(reporte, "Stock: %d\n\n", aux.unProducto.stock); // crea una linea de diferencia por si hay mas de un libro
      contador++;
    }
  }

  fclose(archivo);
  fclose(reporte);

  if (contador > 0)
  {
    printf("Se genero reporte con %d libros bajo stock minimo\n", contador);
  }
  else
  {
    printf("No hay libros bajo el stock minimo\n");
    remove(nombre1);
  }
}
/* === Ciere de archivo ======================================================================== */
