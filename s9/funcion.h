

typedef struct
{
    char titulo [100];
    char autor [50];
    int anio;
    char estado[15];
}registrar;

int validarEntero(int a, int b);
void leerCadena (char *cadena, int n);
int menu();
void registro_libros(registrar *libros, int *numLibros);
void mostrar(registrar *libros, int *numLibros);
int buscarLibro (registrar *libros, int *numLibros);
void actualizar (registrar *libros, int *numLibros);
void eliminar (registrar *libros, int *numLibros);