#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mascotas.h"
#include "trabajos.h"
#include "utn.h"
#include "informes.h"

/** \brief imprime en pantalla el listado de tipos
 *
 * \param list array de estructura Tipo
 * \param tam tamaño del array
 *
 */
void listarTipos (Tipo* list, int tam)
{
    system("CLS");
    printf("\n\n**************************************************\n");
    printf("*               Tipos de mascotas                *\n");
    printf("**************************************************\n\n");
    printf(" ID          Descripcion\n\n");
    for (int i=0; i < tam; i++)
    {
        printf(" %03d    %12s\n", list[i].id,list[i].descripcion);
    }
}

/** \brief imprime en pantalla el listado de colores
 *
 * \param list array de estructura Color
 * \param tam tamaño del array
 *
 */
void listarColores (Color* list, int tam)
{
    system("CLS");
    printf("\n\n**************************************************\n");
    printf("*               Lista de colores                 *\n");
    printf("**************************************************\n\n");
    printf(" ID            Color\n\n");
    for (int i=0; i < tam; i++)
    {
        printf(" %03d    %12s\n", list[i].id,list[i].nombreColor);
    }
}

/** \brief imprime en pantalla el listado de servicios
 *
 * \param list array de estructura Servicio
 * \param tam tamaño del array
 *
 */
void listarServicios (Servicio* list, int tam)
{
    system("CLS");
    printf("\n\n**************************************************\n");
    printf("*             Listado de servicios               *\n");
    printf("**************************************************\n\n");
    printf(" ID         Descripcion       precio\n\n");
    for (int i=0; i < tam; i++)
    {
        printf(" %03d    %14s      %6.2f\n", list[i].id,list[i].descripcion, list[i].precio);
    }
}

/** \brief realiza el alta de una mascota
 *
 * \param idx ID a asignar
 * \param idx ID de cliente
 * \param tamCli tamaño del array Cliente
 * \param listM array de estructura Mascota
 * \param tamM tamaño del array listM
 * \param listColor array de estructura Color
 * \param listTipo array de estructura Tipo
 * \param listCli array de estructura Cliente
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 * \return retorna 0 si el alta fue exitosa, -1 en caso de error
 *
 */
int altaMascota(int idx, int idC, int tamCli, Mascota* listM, int tamM, Color* listColor, Tipo* listTipo, Cliente* listCli, Raza* listR, int tamR)
{
    int index;
    index = buscarEmpty(listM, tamM);
    if (listM != NULL && listColor != NULL && listTipo != NULL && listCli != NULL )
    {
        if (index != -1)
        {
            Mascota auxMascota;
            system("cls");
            printf("\n\n**************************************************\n");
            printf("*                 Alta Mascota                   *\n");
            printf("**************************************************\n");
            auxMascota.id  = idx;
            listarDuenios (listCli, tamCli);
            utn_getNumero(&auxMascota.idCliente, "Ingrese el ID del duenio: ", "Error, ingreso incorrecto, debe ingresar de 30000 a 30010\n", 30000, 30010, 3);
            utn_getNombre(auxMascota.nombre, sizeof(auxMascota.nombre), "\nIngrese nombre de la mascota: ", "\nError, ingrese solo letras\n", 3);
            listarTipos(listTipo, 5);
            utn_getNumero(&auxMascota.idTipo, "\nIngrese un tipo: ", "Error, ingreso incorrecto, debe ingresar de 1001 a 1005\n", 1001, 1005, 3);
            listarColores(listColor, 5);
            utn_getNumero(&auxMascota.idColor, "\nIngrese un color: ", "Error, ingreso incorrecto, debe ingresar de 5001 a 5005\n", 5001, 5005, 3);
            listarRazas(listR, tamR);
            utn_getNumero(&auxMascota.idRaza, "\nIngrese edad: ", "Error, ingreso incorrecto, debe ingresar de 60000 a 60009\n", 60000, 60009, 3);
            utn_getNumero(&auxMascota.edad, "\nIngrese edad: ", "Error, la edad no puede ser un numero nevativo o mayor a 500\n", 0, 500, 3);

            printf("\n*** Carga Exitosa ***\n");
            system("pause>nul");
            auxMascota.isEmpty=0;
            listM[index] = auxMascota;
        }
        else
        {
            printf("\n\n**************************************************\n");
            printf("*          La base de datos esta llena           *\n");
            printf("**************************************************\n\n");
            return -1;
        }
        return 0;
    }
    return -1;
}

/** \brief harcodeo de mascotas para pruebas
 *
 * \param list array de estructura Mascota
 * \param tam tamaño del array list
 *
 */
void harcodeomascotas(Mascota* list, int tam)
{
    int id[10]= {100,101,102,103,104,105,106,107,108,109};
    char nombre[10][30]= {"Negra", "Rocco", "Lola", "Magui", "Michi", "Milo", "Homero", "Chispita", "piquenha", "rasta"};
    int tipo[10]= {1003,1002,1002,1004,1003,1002,1001,1005,1002,1001};
    int color[10]= {5001,5002,5003,5004,5005,5004,5002,5005,5002,5001};
    int edad[10]= {3,4,7,8,43,3,2,14,7,3};
    int cliente[10]= {30003,30002,30001,30006,30005,30004,30009,30008,30000,30007};
    int raza[10]= {60005,60002,60003,60007,60005,60003,60008,60000,60002,60009};

    for (int i=0; i<tam; i++)
    {
        list[i].id=id[i];
        strcpy(list[i].nombre, nombre[i]);
        list[i].idTipo=tipo[i];
        list[i].idColor=color[i];
        list[i].edad=edad[i];
        list[i].isEmpty=0;
        list[i].idCliente=cliente[i];
        list[i].idRaza=raza[i];
    }
}

/**
 * \brief Busca la primera posicion vacia
 * \param list Array de estructura Mascota
 * \param tam tamaño del array list
 * \return retorna el indice de la posicion vacia si encuentra alguna o -1 si la base esta completa)
 *
 */
int buscarEmpty(Mascota* list, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty == 1)
        {
            return i;
            break;
        }
    }
    return -1;
}

/**
 * \brief carga el tipo de una mascota en un puntero
 * \param desc puntero donde guardara la descripcion
 * \param list Array de estructura Tipo
 * \param tam tamaño del array list
 * \return retorna 0 luego de cargar la descrion o -1 si no logro cargarlo.
 *
 */
int cargarDescTipo(char* desc, int id, Tipo* list, int tam)
{
    for (int i=0; i < tam; i++ )
    {
        if (list[i].id == id)
        {
            strcpy ( desc, list[i].descripcion);
            return 0;
        }
    }
    return -1;
}

/**
 * \brief carga el color de una mascota en un puntero
 * \param desc puntero donde guardara el color
 * \param list Array de estructura Tipo
 * \param tam tamaño del array list
 * \return retorna 0 luego de cargar la descrion o -1 si no logro cargarlo.
 *
 */
int cargarDescColor(char* desc, int id, Color* list, int tam)
{
    for (int i=0; i < tam; i++ )
    {
        if (list[i].id == id)
        {
            strcpy ( desc, list[i].nombreColor);
            return 0;
        }
    }
    return -1;
}

/**
 * \brief carga el nombre de una mascota en un puntero
 * \param desc puntero donde guardara el nombre
 * \param list Array de estructura Tipo
 * \param tam tamaño del array list
 * \return retorna 0 luego de cargar la descrion o -1 si no logro cargarlo.
 *
 */
int cargarDescMascota(char* desc, int id, Mascota* list, int tam)
{
    for (int i=0; i < tam; i++ )
    {
        if (list[i].id == id)
        {
            strcpy ( desc, list[i].nombre);
            return 0;
        }
    }
    return -1;
}

/**
 * \brief carga la descripcion de un servicio en un puntero
 * \param desc puntero donde guardara la descripcion
 * \param list Array de estructura Tipo
 * \param tam tamaño del array list
 * \return retorna 0 luego de cargar la descrion o -1 si no logro cargarlo.
 *
 */
int cargarDescServicios(char* desc, int id, Servicio* list, int tam)
{
    for (int i=0; i < tam; i++ )
    {
        if (list[i].id == id)
        {
            strcpy ( desc, list[i].descripcion);
            return 0;
        }
    }
    return -1;
}

/**
 * \brief carga el nombre del dueño de una mascota en un puntero
 * \param desc puntero donde guardara el nombre del sueño
 * \param list Array de estructura Tipo
 * \param tam tamaño del array list
 * \return retorna 0 luego de cargar la descrion o -1 si no logro cargarlo.
 *
 */
int cargarNombreCli(char* desc, int id, Cliente* list, int tam)
{
    for (int i=0; i < tam; i++ )
    {
        if (list[i].id == id)
        {
            strcpy ( desc, list[i].nombre);
            return 0;
        }
    }
    strcpy ( desc, "NOENCONTRADO");
    return -1;
}

/**
 * \brief carga la descripcion de la raza en un puntero
 * \param desc puntero donde guardara el nombre del sueño
 * \param list Array de estructura Raza
 * \param tam tamaño del array Raza
 * \return retorna 0 luego de cargar la descrion o -1 si no logro cargarlo.
 *
 */
int cargarDescRaza(char* desc, int id, Raza* list, int tam)
{
    for (int i=0; i < tam; i++ )
    {
        if (list[i].id == id)
        {
            strcpy ( desc, list[i].descripcion);
            return 0;
        }
    }
    strcpy ( desc, "NOENCONTRADO");
    return -1;
}

/** \brief busca una mascota por el ID y modifica el tipo o la edad
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param check bandera para saber si se cargaron datos
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 * \return 0 si se logro modificar y -1 en caso de error
 *
 */
int buscarMascota(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int check, Raza* listR, int tamR)
{
    int id;
    int resp;
    system("cls");
    if( listM != NULL)
    {
        if (check == 1)
        {
            mostrarMascotas(listM, tamM, listTipo, tamTipo, listC, tamC, listCli, tamCli, check, listR, tamR);
            printf("\nIngrese ID de la mascota: ");
            scanf("%d",&id);
            for (int i=0; i < tamM; i++)
            {
                if (listM[i].id == id)
                {
                    system("CLS");
                    printf("\n\n*****************************************************************\n");
                    printf("*                        Modificar mascota                      *\n");
                    printf("*****************************************************************\n");
                    printf(" ID             Nombre      Tipo      Color     Edad       Duenio\n");
                    mostrarMascota(listM[i], listTipo, tamTipo, listC, tamC, listCli, tamCli, listR, tamR);
                    printf("*****************************************************************\n");
                    printf("\nQue desea modificar?\n\n");
                    printf("1) Tipo\n");
                    printf("2) Edad\n");
                    utn_getNumero(&resp, "Ingrese una opcion: ", "\nError, ingreso incorrecto, debe ingresar de 1 a 2\n", 1, 2, 3);
                    if (resp == 1)
                    {
                        listarTipos(listTipo, 5);
                        utn_getNumero(&listM[i].idTipo, "\nIngrese ID del nuevo tipo: ", "\nError, ingreso incorrecto, debe ingresar de 1001 a 1005\n", 1001, 1005, 3);
                        printf ("\nModificacion exitosa\n");
                        system("pause>nul");
                    }
                    else
                    {
                        utn_getNumero(&listM[i].edad, "\nIngrese nueva edad: ", "\nError, ingreso incorrecto, debe ingresar de 0 a 100\n", 0, 100, 3);
                        printf ("\nModificacion exitosa\n");
                        system("pause>nul");
                    }
                    return 0;
                }
            }
            printf("\nEl ID no coincide con ninguna mascota\n");
            system("pause");
        }
        else
        {
            printf("\n\n**************************************************\n");
            printf("*          La base de datos esta vacia           *\n");
            printf("**************************************************\n\n");
            system("pause");
        }
    }
    return -1;
}

/** \brief inicializa todo el array con isEmpty=1
 *
 * \param list puntero al array Mascota
 * \param tam tamaño del array Mascota
 *
 */
void initMascotas(Mascota* list, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        list[i].isEmpty = 1;
    }
}

/** \brief Mostrar por pantalla una mascota
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listTipo puntero al array Tipo
 * \param tamT tamaño del array Tipo
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param check bandera para saber si se cargaron datos
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void mostrarMascota(Mascota list, Tipo* listTipo, int tamT, Color* listColor, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR)
{
    char tipo[20];
    char color[20];
    char duenio[20];
    char raza[20];
    cargarDescTipo(tipo, list.idTipo, listTipo, tamT);
    cargarDescColor(color, list.idColor, listColor, tamC);
    cargarNombreCli(duenio, list.idCliente, listCli, tamCli);
    cargarDescRaza(raza, list.idRaza, listR, tamR);
    duenio[0]=toupper(duenio[0]);
    printf(" %03d  %15s     %6s     %6s      %2d    %10s   %10s\n", list.id, list.nombre, tipo, color, list.edad,duenio, raza);
}

/** \brief Mostrar por pantalla una mascota
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listTipo puntero al array Tipo
 * \param tamT tamaño del array Tipo
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param check bandera para saber si se cargaron datos
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void mostrarMascotas(Mascota* listM, int tamM, Tipo* listTipo, int tamT, Color* listColor, int tamC, Cliente* listCli, int tamCli, int check, Raza* listR, int tamR)
{
    int flag = 0;
    system("cls");
    if (check == 1)
    {
        printf("\n\n**************************************************\n");
        printf("*              Listado de mascotas               *\n");
        printf("**************************************************\n\n");
        printf(" ID            Nombre       Tipo      color     Edad       Duenio        Raza\n\n");
        for (int i=0; i < tamM; i++ )
        {
            if (listM[i].isEmpty == 0)
            {
                mostrarMascota(listM[i], listTipo, tamT, listColor, tamC, listCli, tamCli, listR, tamR);
                flag= 1;
            }
        }
        if (flag == 0)
        {
            printf("*** No hay empleados que listar ***");
        }
    }
    else
    {
        printf("\n\n**************************************************\n");
        printf("*          La base de datos esta vacia           *\n");
        printf("**************************************************\n\n");
        system("pause");
    }
}

/** \brief Mostrar por pantalla una mascota
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listTipo puntero al array Tipo
 * \param tamT tamaño del array Tipo
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param check bandera para saber si se cargaron datos
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 * \return 0 si se realizo la modificacion con exito
           1 si la baja fue cancelada
           2 si ingreso un dato invalido
           3 si el ID no coincide con ninguna mascota
           4 si no hay cargado datos de mascotas
           -1 en caso de error
  *
  */
int bajaMascota(Mascota* listM, int tamM, Tipo* listTipo, int tamT, Color* listC, int tamC, Cliente* listCli, int tamCli, int check, Raza* listR, int tamR)
{
    char resp;
    int id;
    int retorno=-1;
    system("cls");
    if( listM != NULL)
    {
        if (check == 1)
        {
            mostrarMascotas(listM, tamM, listTipo, tamT, listC, tamC, listCli, tamCli, check, listR, tamR);
            printf("\nIngrese ID de la mascota: ");
            scanf("%d",&id);
            for (int i=0; i < tamM; i++)
            {
                if (listM[i].id == id)
                {
                    system("CLS");
                    printf("\n\n**************************************************\n");
                    printf("*                  Baja mascota                  *\n");
                    printf("**************************************************\n");
                    printf(" ID             Nombre       Tipo     color     edad\n");
                    mostrarMascota(listM[i], listTipo, tamT, listC, tamC, listCli, tamCli, listR, tamR);
                    printf("**************************************************\n");
                    printf("\nDesea continuar con la baja (s/n)?: ");
                    fflush(stdin);
                    scanf("%c",&resp);
                    if (resp == 's')
                    {
                        listM[i].isEmpty=1;
                        printf ("\nBaja exitosa\n");
                        system("pause>nul");
                        retorno=0;
                    }
                    else if (resp == 'n')
                    {
                        printf ("\nBaja Cancelada\n");
                        system("pause>nul");
                        retorno=1;
                    }
                    else
                    {
                        printf ("\nIngreso invalido\n");
                        system("pause>nul");
                        retorno=2;
                    }
                }
            }
            printf("\nEl ID no coincide con ninguna mascota\n");
            system("pause>nul");
            retorno=3;
        }
        else
        {
            printf("\n\n**************************************************\n");
            printf("*          La base de datos esta vacia           *\n");
            printf("**************************************************\n\n");
            system("pause");
            retorno=4;
        }
    }
    return retorno;
}

/** \brief imprime por pantalla el listado de dueños
 *
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 *
 */
void listarDuenios (Cliente* listCli, int tamCli)
{

    printf("**************************************************\n");
    printf("*               Lista de duenios                 *\n");
    printf("**************************************************\n\n");
    for (int i=0; i < tamCli; i++)
    {
        printf(" %d    %15s      %c\n", listCli[i].id, listCli[i].nombre, listCli[i].sexo);
    }
    printf("\n\n");
}

/** \brief imprime por pantalla el listado de razas
 *
 * \param listCli puntero al array Raza
 * \param tamCli tamaño del array Raza
 *
 */
void listarRazas (Raza* listR, int tamR)
{
    system("CLS");
    printf("\n\n**************************************************\n");
    printf("*                Lista de razas                  *\n");
    printf("**************************************************\n\n");
    printf(" ID            Raza                     Origen\n\n");
    for (int i=0; i < tamR; i++)
    {
        printf(" %d    %15s       %15s\n", listR[i].id, listR[i].descripcion, listR[i].Origen);
    }
    printf("\n\n");
}
