# 💻 Sistema de Gestión en C - Proyecto Integrador

## 📖 Descripción
Proyecto académico desarrollado como parte de la carrera de **Ingeniería en Computación (UNT)**. Implementa un sistema de gestión de datos utilizando **estructuras dinámicas** y **algoritmos de búsqueda y ordenamiento** en lenguaje C.

## 🛠️ Tecnologías utilizadas
- **C** (Lenguaje de programación)
- **Estructuras de datos** (Listas enlazadas, árboles, hash)
- **Algoritmos de ordenamiento** (QuickSort, MergeSort)

## 📂 Estructura del Repositorio
- `main.c`: Archivo principal con el menú interactivo.
- `estructuras/`: Implementación de listas, árboles y tablas hash.
- `algoritmos/`: Funciones de búsqueda y ordenamiento.
- `utils/`: Funciones auxiliares (validación de entrada, manejo de archivos).

## 🚀 Instrucciones de Ejecución
1. Clonar el repositorio.
2. Compilar con GCC:
   ```bash
   gcc main.c estructuras/*.c algoritmos/*.c utils/*.c -o sistema_gestion

🎯 Funcionalidades principales
Gestión de usuarios: Alta, baja, modificación y consulta.

Persistencia: Guardado y carga desde archivos de texto.

Búsqueda avanzada: Por nombre, ID o rango de fechas.

🔮 Mejoras futuras
Implementar interfaz gráfica (GUI) con GTK o Qt.

Migrar la persistencia a una base de datos SQLite.

Agregar autenticación con contraseñas encriptadas.
