# Get Next Line - Subject (Versión 14.0)

> "Leer una línea de un descriptor de archivo es demasiado tedioso."

**Resumen:** El objetivo de este proyecto es programar una función que devuelva una línea desde un descriptor de archivo (`file descriptor`).

---

## Índice general
I. Objetivos  
II. Instrucciones generales  
III. Instrucciones sobre la IA  
IV. Parte obligatoria  
V. Requisitos del Readme  
VI. Parte bonus  
VII. Entrega y evaluación  

---

## Capítulo I: Objetivos
Este proyecto no solo te permitirá añadir una función bastante práctica a tu colección, también te hará aprender el increíble concepto de las variables estáticas en C.

---

## Capítulo II: Instrucciones generales
- El proyecto deberá estar escrito en **C**.
- El código debe seguir estrictamente la **Norma**. Los archivos o funciones adicionales también serán evaluados y un error de norma en cualquiera de ellos implicará un `0`.
- Las funciones no deben terminar de forma inesperada (`segfault`, `bus error`, `double free`, etc.), excepto por comportamientos indefinidos. Si sucede, el proyecto será considerado no funcional (`0`).
- Toda la memoria asignada en el *heap* deberá liberarse adecuadamente (sin *leaks* de memoria).
- Se debe entregar un **Makefile** que compile los archivos fuente con las flags `-Wall`, `-Werror` y `-Wextra` usando `cc`. No debe hacer *relink*.
- El Makefile debe contener al menos las normas: `$(NAME)`, `all`, `clean`, `fclean` y `re`.
- Para los bonus, se incluirá una regla `bonus` en el Makefile y los archivos llevarán el sufijo `_bonus.{c/h}`. Se evalúan por separado.
- Si se permite `libft`, debe copiarse su fuente y Makefile en un directorio `libft/`, compilándose antes que el proyecto principal.
- Es recomendable crear programas de prueba propios (aunque no se entreguen ni evalúen).
- Entrega el trabajo en el repositorio Git asignado.

---

## Capítulo III: Instrucciones sobre la IA
- **Mensaje principal:** Construir fundamentos sólidos sin atajos, desarrollar habilidades técnicas de forma real, experimentar el aprendizaje entre pares y priorizar el proceso de aprendizaje sobre el resultado final.
- **Reglas:** Aplica la lógica y el razonamiento antes de recurrir a la IA, no pidas respuestas directas y comprende los riesgos asociados durante esta fase de formación en 42.

---

## Capítulo IV: Parte obligatoria

| Elemento | Detalle |
| :--- | :--- |
| **Nombre de función** | `get_next_line` |
| **Prototipo** | `char *get_next_line(int fd);` |
| **Archivos a entregar** | `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h` |
| **Parámetros** | `fd`: El descriptor de archivo a leer |
| **Valor devuelto** | Si todo va bien: la línea leída. En caso de fallo o fin de lectura: `NULL`. |
| **Funciones autorizadas** | `read`, `malloc`, `free` |

### Especificaciones técnicas:
- Llamadas repetidas (ej. bucle) permiten leer el archivo línea a línea hasta el final.
- Funciona correctamente tanto con archivos como con la entrada estándar (`stdin`).
- La línea devuelta debe terminar con `\n`, excepto si se llega al final del archivo y este no termina en `\n`.
- El programa debe compilar obligatoriamente con el indicador `-D BUFFER_SIZE=n`. Debe poder compilarse con y sin él, eligiendo un tamaño por defecto.
- Ejemplo de compilación: `cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c`
- **Comportamiento indeterminado:** Si el archivo cambia desde la última llamada (sin llegar al final) o si se leen archivos binarios.
- **Optimización:** Leer lo menos posible en cada llamada (no leer el archivo entero de golpe para luego procesarlo).
- **Prohibido:** Uso de `libft`, uso de `lseek`, uso de variables globales.

---

## Capítulo V: Requisitos del Readme
Se debe incluir un archivo `README.md` en la raíz del repositorio que contenga como mínimo:
1. La primera línea en cursiva: *Este proyecto ha sido creado como parte del currículo de 42 por [login], [login], [...]داث.*
2. Sección de **Descripción** (objetivo y visión general).
3. Sección de **Instrucciones** (compilación, instalación, ejecución).
4. Sección de **Recursos** (referencias, documentación y descripción detallada del uso de IA).
5. Explicación detallada y justificación del algoritmo seleccionado.

---

## Capítulo VI: Parte bonus
Requisitos (solo evaluados si la parte obligatoria está perfecta):
- Desarrollar `get_next_line()` utilizando **una sola variable estática**.
- Capacidad de gestionar **múltiples descriptores de archivo a la vez** (alternar entre `fd` 3, 4, 5, etc., sin perder el estado de lectura de cada uno).
- Archivos requeridos:
  - `get_next_line_bonus.c`
  - `get_next_line_bonus.h`
  - `get_next_line_utils_bonus.c`