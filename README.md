# Control de Estudiantes y Cursos

Este proyecto en C/C++ tiene como objetivo llevar el control de un listado de estudiantes con sus cursos asignados. Se utilizará un archivo de texto como base de datos para almacenar la información de los estudiantes. El programa permite realizar diversas operaciones para gestionar la información de los estudiantes.

## Funcionalidades y Menú Principal

### 1. Crear/Cargar Base de Datos
En esta opción, el programa creará una nueva base de datos (archivo de texto) o cargará la información existente desde un archivo ya creado. El usuario proporcionará el nombre del archivo.

### 2. Ingresar Información de Alumnos
Permite al usuario ingresar la información de los 30 estudiantes, incluyendo número de carnet, nombres, apellidos, sexo, teléfono, curso y sección.

### 3. Actualizar Información de un Alumno
Permite la modificación de la información de un alumno específico. El usuario proporcionará el número de carnet del alumno cuya información desea actualizar.

### 4. Grabar Información de Alumnos
Guarda la información actualizada en el archivo de texto. Si el archivo no existe, se creará antes de guardar la información.

### 5. Listar Información de Alumnos
Muestra en formato de tabla la información de todos los estudiantes almacenados.

### 6. Buscar Alumnos
Permite buscar y listar alumnos según diversas opciones:
- Buscar por Carnet.
- Buscar por Nombre.
- Buscar por Curso y Sección.

### 7. Eliminar un Registro
Elimina la información de un alumno según el número de carnet proporcionado.

### 8. Salir
Finaliza la ejecución del programa.

## Ejemplo de Archivo de Texto (alumnos.txt)
```
No. Carnet   Nombres                Apellidos              Sexo   Teléfono    Curso           Sección
1   796018001 Juan Carlos           López Salazar          M      76234579    Algoritmos       A
2   796018002 Oscar                 Gutiérrez              M      76234580    Algoritmos       B
3   796018003 Regina                Molina                 F      76234581    Algoritmos       C
4   796018004 Alejandro             García                 M      76234582    Programación     A
5   796018005 José Matías           González               M      76234583    Programación     A
...
30  796018020 Carlos Enrique        Bautista               M      76234599    Física 1         A
```

## Contribución

Este proyecto fue desarrollado por [Carbonell-Castillo] y acepta contribuciones de la comunidad. Si deseas contribuir, por favor sigue estos pasos:

1. Haz un fork del repositorio.
2. Crea una rama para tu contribución: `git checkout -b tu-caracteristica`
3. Realiza tus cambios y haz commits: `git commit -m 'Añade nueva característica'`
4. Haz push a la rama: `git push origin tu-caracteristica`
5. Abre un pull request en GitHub.

Gracias por contribuir!

## Licencia

Este proyecto está bajo la Licencia MIT
