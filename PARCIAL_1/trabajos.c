#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "trabajos.h"
#include "utn.h"
#include "informes.h"

/** \brief inicializa todos los trabajos isEmpty en 1
 *
 * \param list puntero al array Trabajo
 * \param tam tamaño del array Trabajo
 *
 */

void initTrabajos(Trabajo* list, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        list[i].isEmpty = 1;
    }
}

/**
 * \brief Busca la primera posicion vacia
 * \param list Array de estructura Trabajo
 * \param tam tamaño del array list
 * \return retorna el indice de la posicion vacia si encuentra alguna o -1 si la base esta completa)
 *
 */
int buscarEmptyTrab(Trabajo* list, int tam)
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

/** \brief imprime por pantalla el listado de trabajos
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listS puntero al array Servicio
 * \param tamS tamaño del array Servicio
 * \param listT puntero al array Trabajo
 * \param tamT tamaño del array Trabajo
 * \param checkT bandera para saber si se cargaron datos
 *
 */
void listarTrabajos (Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, int checkT)
{
    system("CLS");
    if (checkT == 1)
    {
        char descM[20];
        char descS[20];
        float descP;
        system("CLS");
        printf("\n ID Trabajo          Mascota         Servicio        Fecha       precio\n\n");
        for (int i=0; i < tamT; i++)
        {
            if (listT[i].isEmpty == 0)
            {
                cargarDescMascota(descM, listT[i].idMascota, listM, tamM);
                cargarDescServicios(descS, listT[i].idServicio, listS, tamS);
                cargarPrecios(&descP, listT[i].idServicio, listS, tamT);
                printf("   %03d    %15s   %15s      %02d/%02d/%04d    %6.2f\n", listT[i].id, descM, descS, listT[i].fecha.dia, listT[i].fecha.mes, listT[i].fecha.anio,descP);
            }
        }
        printf("\n");
    }
    else
    {
        printf("\n\n**************************************************\n");
        printf("*            No hay trabajos cargados            *\n");
        printf("**************************************************\n\n");
    }
}

/** \brief harcodeo de mascotas para pruebas
 *
 * \param list array de estructura Trabajo
 * \param tam tamaño del array list
 *
 */
void harcodeoTrabajos(Trabajo* list, int tam)
{
    int id[10]= {10000,10001,10002,10003,10004,10005,10006,10007,10008,10009};
    int idMascota[10]= {100,101,102,103,104,105,106,107,108,109};
    int idServicio[10]= {20001,20003,20002,20002,20003,20001,20001,20003,20002,20001};
    int dia[10]= {1, 6, 8, 10, 22, 31, 28, 17, 12, 11};
    int mes[10]= {2, 9, 1, 10, 12, 12, 5, 5, 2, 11};
    int anio[10]= {2025, 2020, 2022, 2023, 2020, 2022, 2029, 2027, 2022, 2025};

    for (int i=0; i<tam; i++)
    {
        list[i].id=id[i];
        list[i].idMascota=idMascota[i];
        list[i].idServicio=idServicio[i];
        list[i].fecha.dia=dia[i];
        list[i].fecha.mes=mes[i];
        list[i].fecha.anio=anio[i];
        list[i].isEmpty=0;
    }
}

/** \brief imprime por pantalla el listado de trabajos
 *
 * \param idx ID a asignar
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listServ puntero al array Servicio
 * \param tamS tamaño del array Servicio
 * \param listT puntero al array Trabajo
 * \param tamT tamaño del array Trabajo
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param check bandera para saber si se cargaron datos
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
int altaTrabajo(int idx, Trabajo* listT, int tamT, Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Servicio* listServ, int tamS, Cliente* listCli, int tamCli, int check, Raza* listR, int tamR)
{
    int id;
    int auxDia;
    int auxMes;
    int auxAnio;
    int flagCarga=0;
    int index;
    system("CLS");
    index=buscarEmptyTrab(listT, tamT);
    if (check == 1)
    {
        Trabajo listTrabajoAux;
        mostrarMascotas(listM, tamM, listTipo, tamT, listC, tamC, listCli, tamCli, check, listR, tamR);
        printf("\nIngrese ID de la mascota: ");
        scanf("%d",&id);
        for (int i=0; i < tamM; i++ )
        {
            if (listM[i].id == id && listM[i].isEmpty == 0)
            {
                listarServicios(listServ,3);
                utn_getNumero(&listTrabajoAux.idServicio, "\nIngrese un servicio: ", "\nError, ingreso incorrecto, debe ingresar de 20001 a 20003\n", 20001, 20003, 3);
                while (flagCarga==0)
                {
                    printf("\nIngrese fecha dd/mm/aaaa: ");
                    scanf("%d/%d/%d",&auxDia, &auxMes, &auxAnio);
                    if ((auxDia >0 && auxDia <32) && (auxMes >0 && auxMes <13) && (auxAnio >= 2020 && auxAnio < 2030))
                    {
                        listTrabajoAux.fecha.dia = auxDia;
                        listTrabajoAux.fecha.mes = auxMes;
                        listTrabajoAux.fecha.anio = auxAnio;
                        listTrabajoAux.id = idx;
                        listTrabajoAux.idMascota = id;
                        listTrabajoAux.isEmpty = 0;
                        listT[index] = listTrabajoAux;
                        flagCarga=1;
                        printf("\nCarga exitosa\n");
                        system("pause>nul");
                        return 0;
                    }
                    else
                    {
                        printf("\nFecha incorrecta, utilice el siguiente formato dd/mm/aaaa (hasta 2030)\n");
                        system("pause");
                    }
                }
            }
        }
        system("CLS");
        printf("\n\n**************************************************\n");
        printf("*            El ID no fue encontrado             *\n");
        printf("**************************************************\n\n");
        system("pause>nul");
    }
    else
    {
        printf("\n\n**************************************************\n");
        printf("*          La base de datos esta vacia           *\n");
        printf("**************************************************\n\n");
        system("pause");
    }
    return -1;
}

/**
 * \brief carga los precios de de los servicios en un puntero
 * \param precio puntero donde guardara el precio
 * \param list Array de estructura Servicio
 * \param tam tamaño del array list
 * \return retorna 0 luego de cargar el precio o -1 si no logro cargarlo.
 *
 */
int cargarPrecios(float* precio, int id, Servicio* list, int tam)
{
    for (int i=0; i < tam; i++ )
    {
        if (list[i].id == id)
        {
            *precio=list[i].precio;
            return 0;
        }
    }
    return -1;
}

