#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "trabajos.h"
#include "utn.h"
#include "informes.h"

/** \brief Menu de informes
 *
 */
int menuInformes()
{
    int resp;
    system("CLS");
    printf("\n\n**************************************************\n");
    printf("*                Menu de informes                *\n");
    printf("**************************************************\n\n");
    printf("\n1) Mascotas por color");
    printf("\n2) Mascotas por tipo");
    printf("\n3) Mascota mas joven");
    printf("\n4) Mascotas por tipo");
    printf("\n5) Cantidad por tipo y color");
    printf("\n6) El color mas usado");
    printf("\n7) Trabajos por mascota");
    printf("\n8) Total costo por mascota");
    printf("\n9) Informe de un servicio");
    printf("\n10) Servicios por fecha");
    printf("\n11) Volver al menu principal");
    printf("\n\n***** Recuperatorio *****\n");
    printf("\n12) Informe por raza");
    printf("\n13) Informe de raza mas habitual");
    printf("\n14) Informe ordenado por raza");
    printf("\n15) Informe de mascotas por origen");
    printf("\n16) Informe de raza y mayor a tal edad");
    printf("\n17) Informe de raza y color");
    utn_getNumero(&resp, "\n\nIngrese una opcion: ", "\nError, ingreso incorrecto, debe ingresar de 1 a 16\n", 1, 16, 3);
    return resp;
}

/** \brief switch con la respuesta del menu de informes
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listS puntero al array Servicio
 * \param tamS tamaño del array Servicio
 * \param listT puntero al array Trabajo
 * \param tamT tamaño del array Trabajo
 * \param listColor puntero al array Color
 * \param tamC tamaño del array Color
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param checkT bandera para saber si se cargaron datos
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 * \return retorna 0  al seleccionar la opcion de salir
 *
 */

int informes(Mascota* listM, int tamM, Servicio* listS, int tamS, Trabajo* listT, int tamT, Color* listColor, int tamC, Tipo* listTipo, int tamTipo, Cliente* listCli, int tamCli, int checkT, Raza* listR, int tamR)
{
    if (checkT == 1)
    {


        char seguir = 's';
        while (seguir == 's')
        {
            switch(menuInformes())
            {
            case 1:
                informeXColor(listM, tamM, listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
                system("pause>nul");
                break;
            case 2:
                informeXTipo(listM, tamM, listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
                system("pause>nul");
                break;
            case 3:
                masJoven(listM, tamM, listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
                system("pause>nul");
                break;
            case 4:
                separadosXColor(listM, tamM, listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
                system("pause>nul");
                break;
            case 5:
                xTipoYColor(listM, tamM, listTipo, tamTipo, listColor, tamC, listR, tamR);
                system("pause>nul");
                break;
            case 6:
                informeMayorColor(listM, tamM, listTipo, tamTipo, listColor, tamC, listR, tamR);
                system("pause>nul");
                break;
            case 7:
                servicioXMascota(listT, tamT, listM, tamM, listS, tamS, listTipo, tamTipo, listColor, tamC, listCli, tamCli, checkT, listR, tamR);
                system("pause>nul");
                break;
            case 8:
                TotalPrecioXMascota(listT, tamT, listM, tamM, listS, tamS, listTipo, tamTipo, listColor, tamC, listCli, tamCli, checkT, listR, tamR);
                system("pause>nul");
                break;
            case 9:
                unServicio(listT, tamT, listM, tamM, listS, tamS, listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
                system("pause>nul");
                break;
            case 10:
                informeTrabajosXfecha(listT, tamT, listM, tamM, listS, tamS, listTipo, tamTipo, listColor, tamC, listCli, tamCli, checkT, listR, tamR);
                system("pause>nul");
                break;
            case 11:
                seguir= 'n';
                break;
            case 12:
                informeXRaza(listT, tamT, listM, tamM, listS, tamS, listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
                system("pause>nul");
                break;
            case 13:
                mayorRaza(listT, tamT, listM, tamM, listS, tamS, listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
                system("pause>nul");
                break;
            case 14:
                orderXRaza(listT, tamT, listM, tamM, listS, tamS, listTipo, tamTipo, listColor, tamC, listCli, tamCli, checkT, listR, tamR);
                system("pause>nul");
                break;
            case 15:
                informeXOrigen(listT, tamT, listM, tamM, listS, tamS, listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
                system("pause>nul");
                break;
            case 16:
                informeXRazayEdad(listT, tamT, listM, tamM, listS, tamS, listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
                system("pause>nul");
                break;
            case 17:
                informeXRazaYColor(listT, tamT, listM, tamM, listS, tamS, listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
                system("pause>nul");
                break;
            }
        }
    }
    else
    {
        printf("\n\n**************************************************\n");
        printf("*          La base de datos esta vacia           *\n");
        printf("**************************************************\n\n");
        system("pause");
    }
    return 0;
}

/** \brief Informe por color de mascota
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listT puntero al array Tipo
 * \param tamT tamaño del array Tipo
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void informeXColor (Mascota* listM, int tamM, Tipo* listT, int tamT, Color* listC, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR)
{
    int resp;
    system("cls");
    printf("\n\n**************************************************\n");
    printf("*         Informe por tipo de mascota            *\n");
    printf("**************************************************\n");
    utn_getNumero(&resp, "1) Negro\n2) Blanco\n3) Gris\n4) Rojo\n5) Azul\n\nIngrese una opcion: ", "\nError, ingreso incorrecto, debe ingresar de 1 a 5\n", 1, 5, 3);
    system("cls");
    switch(resp)
    {
    case 1:
        printf("\n\n**************************************************\n");
        printf("*               Listado de negros                *\n");
        printf("**************************************************\n");
        break;
    case 2:
        printf("\n\n**************************************************\n");
        printf("*               Listado de blancos               *\n");
        printf("**************************************************\n");
        break;
    case 3:
        printf("\n\n**************************************************\n");
        printf("*               Listado de grises                *\n");
        printf("**************************************************\n");
        break;
    case 4:
        printf("\n\n**************************************************\n");
        printf("*               Listado de rojos                 *\n");
        printf("**************************************************\n");
        break;
    case 5:
        printf("\n\n**************************************************\n");
        printf("*               Listado de azules                *\n");
        printf("**************************************************\n");
        break;
    }
    imprimirXColor(listM, tamM, listT, tamT, listC, tamC, listCli, tamCli, resp, listR, tamR);
}

/** \brief Informe por color de mascota
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param resp seleccion del usuario del color a imprimir
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void imprimirXColor(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Cliente* listCli, int tamCli, int resp, Raza* listR, int tamR)
{
    printf("\n ID             Nombre      Tipo      Color     Edad       Duenio         Raza\n\n");
    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idColor == resp+5000 && listM[i].isEmpty == 0)
        {
            mostrarMascota(listM[i], listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
        }
    }
    printf("\n\n");
}

/** \brief Informe por tipo de mascota
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listT puntero al array Tipo
 * \param tamT tamaño del array Tipo
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void informeXTipo (Mascota* listM, int tamM, Tipo* listT, int tamT, Color* listC, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR)
{
    int resp;
    system("cls");
    printf("\n\n**************************************************\n");
    printf("*         Informes por tipo de mascota           *\n");
    printf("**************************************************\n");
    utn_getNumero(&resp, "1) Aves\n2) Perros\n3) Gatos\n4) Roedores\n5) Peces\n\nIngrese una opcion: ", "\nError, ingreso incorrecto, debe ingresar de 1 a 5\n", 1, 5, 3);
    system("cls");
    switch(resp)
    {
    case 1:
        printf("\n\n******************************************************************\n");
        printf("*                        listado de aves                         *\n");
        printf("******************************************************************\n");
        break;
    case 2:
        printf("\n\n******************************************************************\n");
        printf("*                        listado de perros                       *\n");
        printf("******************************************************************\n");
        break;
    case 3:
        printf("\n\n******************************************************************\n");
        printf("*                        listado de gatos                        *\n");
        printf("******************************************************************\n");
        break;
    case 4:
        printf("\n\n******************************************************************\n");
        printf("*                      listado de roedores                       *\n");
        printf("******************************************************************\n");
        break;
    case 5:
        printf("\n\n******************************************************************\n");
        printf("*                        listado de peces                        *\n");
        printf("******************************************************************\n");
        break;
    }
    imprimirXTipo(listM, tamM, listT, tamT, listC, tamC, listCli, tamCli, resp, listR, tamR);
}

/** \brief Informe por tipo de mascota
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listT puntero al array Tipo
 * \param tamT tamaño del array Tipo
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param resp seleccion del usuario del tipo a imprimir
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void imprimirXTipo(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Cliente* listCli, int tamCli, int resp, Raza* listR, int tamR)
{
    printf("\n ID             Nombre      Tipo      Color     Edad       Duenio         Raza\n\n");
    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idTipo == resp+1000 && listM[i].isEmpty == 0)
        {
            mostrarMascota(listM[i], listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
        }
    }
    printf("\n\n");
}

/** \brief Informe del mas joven
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listColor puntero al array Color
 * \param tamC tamaño del array Color
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void masJoven (Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR)
{
    int menor;
    int indexMenor;

    system("CLS");
    menor=listM[0].edad;
    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].edad < menor && listM[i].isEmpty == 0)
        {
            menor = listM[i].edad;
            indexMenor=i;
        }
    }
    printf("\n\n");
    printf("\n\n******************************************************************\n");
    printf("*                      Mascota mas joven                         *\n");
    printf("******************************************************************\n\n");
    printf("\n ID             Nombre      Tipo      Color     Edad       Duenio\n\n");
    mostrarMascota(listM[indexMenor], listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
    printf("\n\n");
}

/** \brief Informe del mas joven
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listColor puntero al array Color
 * \param tamC tamaño del array Color
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void separadosXColor(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR)
{
    system("cls");
    printf("\n\n******************************************************************\n");
    printf("*                        listado de aves                         *\n");
    printf("******************************************************************\n");
    printf("\n ID             Nombre      Tipo      Color     Edad       Duenio         Raza\n\n");

    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idTipo == 1001 && listM[i].isEmpty == 0)
        {
            mostrarMascota(listM[i], listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
        }
    }
    printf("\n");
    printf("\n\n******************************************************************\n");
    printf("*                        listado de perros                       *\n");
    printf("******************************************************************\n");
    printf("\n ID             Nombre      Tipo      Color     Edad       Duenio         Raza\n\n");

    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idTipo == 1002 && listM[i].isEmpty == 0)
        {
            mostrarMascota(listM[i], listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
        }
    }
    printf("\n\n******************************************************************\n");
    printf("*                        listado de gatos                        *\n");
    printf("******************************************************************\n");
    printf("\n ID             Nombre      Tipo      Color     Edad       Duenio         Raza\n\n");

    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idTipo == 1003 && listM[i].isEmpty == 0)
        {
            mostrarMascota(listM[i], listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
        }
    }
    printf("\n\n******************************************************************\n");
    printf("*                      listado de roedores                       *\n");
    printf("******************************************************************\n");
    printf("\n ID             Nombre      Tipo      Color     Edad       Duenio\n\n");

    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idTipo == 1004 && listM[i].isEmpty == 0)
        {
            mostrarMascota(listM[i], listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
        }
    }
    printf("\n\n******************************************************************\n");
    printf("*                        listado de peces                        *\n");
    printf("******************************************************************\n");
    printf("\n ID             Nombre      Tipo      Color     Edad       Duenio         Raza\n\n");

    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idTipo == 1005 && listM[i].isEmpty == 0)
        {
            mostrarMascota(listM[i], listTipo, tamTipo, listColor, tamC, listCli, tamCli, listR, tamR);
        }
    }
}

/** \brief Informe por tipo de color
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listColor puntero al array Color
 * \param tamC tamaño del array Color
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
int xTipoYColor(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Raza* listR, int tamR)
{
    int tipo;
    int color;
    char descTipo[20]= "";
    char descColor[20]= "";
    char tipoElegido[20]= "";
    char colorElegido[20]= "";
    int suma=0;
    system("cls");
    printf("\n\n******************************************************************\n");
    printf("*                   Informe por tipo y color                     *\n");
    printf("******************************************************************\n");
    listarTipos(listTipo, 5);
    utn_getNumero(&tipo, "Ingrese un tipo: ", "Error, ingreso incorrecto, debe ingresar de 1001 a 1005\n", 1001, 1005, 3);
    listarColores(listColor, 5);
    utn_getNumero(&color, "Ingrese un color: ", "Error, ingreso incorrecto, debe ingresar de 5001 a 5005\n", 5001, 5005, 3);
    for (int i=0; i < tamM; i++ )
    {
        cargarDescTipo(descTipo, listM[i].idTipo, listTipo, tamTipo);
        cargarDescColor(descColor, listM[i].idColor, listColor, tamC);
        if (listM[i].idTipo == tipo && listM[i].idColor == color)
        {
            suma++;
            strcpy(tipoElegido,descTipo);
            strcpy(colorElegido,descColor);
        }
    }
    if (suma == 0 )
    {
        printf("\n\n******************************************************************\n");
        printf("\n*        No hay ninguna mascota con esa descripcion            *\n");
        printf("******************************************************************\n");
        return -1;
    }
    else
    {
        system("CLS");
        printf("\n\n**************************************************\n");
        printf("\nMascota elegida : %s \nColor elegido : %s\nCantidad en la base de datos: %d\n",tipoElegido, colorElegido, suma);
        printf("\n**************************************************\n");
    }
    return 0;
}

/** \brief Informe del color mas usado
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listColor puntero al array Color
 * \param tamC tamaño del array Color
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void informeMayorColor(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Raza* listR, int tamR)
{
    int negro=0;
    int blanco=0;
    int gris=0;
    int rojo=0;
    int azul=0;
    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idColor == 5001 && listM[i].isEmpty == 0)
        {
            negro++;
        }
        else if (listM[i].idColor == 5002 && listM[i].isEmpty == 0)
        {
            blanco++;
        }
        else if (listM[i].idColor == 5003 && listM[i].isEmpty == 0)
        {
            gris++;
        }
        else if (listM[i].idColor == 5004 && listM[i].isEmpty == 0)
        {
            rojo++;
        }
        else if (listM[i].idColor == 5005 && listM[i].isEmpty == 0)
        {
            azul++;
        }
    }
    printf("\n\n************************************************");
    if (negro > blanco && negro > gris && negro > rojo && negro > azul)
    {
        printf("\nHay mas cantidad de negro, con un total de %d", negro);
    }
    else if (blanco > negro && blanco > gris && blanco > rojo && blanco > azul)
    {
        printf("\nHay mas cantidad de blanco, con un total de %d", blanco);
    }
    else if (gris > negro && gris > blanco && gris > rojo && gris > azul)
    {
        printf("\nHay mas cantidad de gris, con un total de %d", gris);
    }
    else if (rojo > negro && rojo > gris && rojo > blanco && rojo > azul)
    {
        printf("\nHay mas cantidad de rojo, con un total de %d", rojo);
    }
    else if (azul > negro && azul > gris && azul > blanco && azul > rojo)
    {
        printf("\nHay mas cantidad de azul, con un total de %d", azul);
    }
    printf("\n************************************************\n");
    printf("\n\n");
}


/** \brief informe de servicios por mascota
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listS puntero al array Servicio
 * \param tamS tamaño del array Servicio
 * \param listT puntero al array Trabajo
 * \param tamT tamaño del array Trabajo
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param checkT bandera para saber si se cargaron datos
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void servicioXMascota (Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int checkT, Raza* listR, int tamR)
{
    system("CLS");
    if (checkT == 1)
    {
        int id;
        char descM[20];
        char descS[20];
        float descP;
        system("CLS");
        printf("\n\n**************************************************\n");
        printf("*        Informe de trabajos por mascota         *\n");
        printf("**************************************************\n");
        mostrarMascotas(listM, tamM, listTipo, tamTipo, listC, tamC, listCli, tamCli, checkT, listR, tamR);
        printf("\nIngrese ID de la mascota: ");
        scanf("%d",&id);
        system("CLS");
        printf("\n ID Trabajo          Mascota         Servicio        Fecha       precio\n\n");
        for (int i=0; i < tamT; i++)
        {
            if (listT[i].isEmpty == 0 && listT[i].idMascota == id)
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

/** \brief Informe de costo total de trabajos por mascota
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listS puntero al array Servicio
 * \param tamS tamaño del array Servicio
 * \param listT puntero al array Trabajo
 * \param tamT tamaño del array Trabajo
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param checkT bandera para saber si hay algo cargado
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void TotalPrecioXMascota (Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int checkT, Raza* listR, int tamR)
{
    system("CLS");
    if (checkT == 1)
    {
        int id;
        char descM[20];
        char descS[20];
        float descP;
        float suma;
        system("CLS");
        printf("\n\n**************************************************\n");
        printf("*        Informe de trabajos por mascota         *\n");
        printf("**************************************************\n");
        mostrarMascotas(listM, tamM, listTipo, tamTipo, listC, tamC, listCli, tamCli, checkT, listR, tamR);
        printf("\nIngrese ID de la mascota: ");
        scanf("%d",&id);
        system("CLS");
        for (int i=0; i < tamT; i++)
        {
            if (listT[i].isEmpty == 0 && listT[i].idMascota == id)
            {
                cargarDescMascota(descM, listT[i].idMascota, listM, tamM);
                cargarDescServicios(descS, listT[i].idServicio, listS, tamS);
                cargarPrecios(&descP, listT[i].idServicio, listS, tamT);
                suma+=listS[i].precio;
            }
        }
        printf("\nEl costo total es %6.2f\n", suma);
        printf("\n");
    }
    else
    {
        printf("\n\n**************************************************\n");
        printf("*            No hay trabajos cargados            *\n");
        printf("**************************************************\n\n");
    }
}

/** \brief informe de trabajos por fecha indicada por el usuario
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listS puntero al array Servicio
 * \param tamS tamaño del array Servicio
 * \param listT puntero al array Trabajo
 * \param tamT tamaño del array Trabajo
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param checkT bandera para saber si hay algo cargado
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void informeTrabajosXfecha (Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int checkT, Raza* listR, int tamR)
{
    int mes;
    int dia;
    int anio;
    int flag=0;
    system("cls");
    printf("\n\n**************************************************\n");
    printf("*                Trabajos por mes                *\n");
    printf("**************************************************\n\n");
    utn_getNumero(&dia, "\nIngrese dia: ", "\nError, ingreso incorrecto, debe ingresar de 1 a 31\n", 1, 31, 3);
    utn_getNumero(&mes, "\nIngrese mes: ", "\nError, ingreso incorrecto, debe ingresar de 1 a 12\n", 1, 12, 3);
    utn_getNumero(&anio, "\nIngrese anio: ", "\nError, ingreso incorrecto, debe ingresar de 2020 a 2030\n", 2020, 2030, 3);
    printf("\n");
    printf("\n ID             Nombre      Tipo      Color     Edad       Duenio         Raza\n\n");
    for (int i=0; i < tamT; i++ )
    {
        if (listT[i].isEmpty == 0 && listT[i].fecha.dia == dia && listT[i].fecha.mes == mes && listT[i].fecha.anio == anio)
        {
            mostrarMascota(listM[i], listTipo, tamT, listC, tamC, listCli, tamCli, listR, tamR);
            flag = 1;
        }
    }
    printf("\n\n");

    if (flag == 0)
    {
        printf("\n*** No hay trabajos que ingresaron ese mes ***\n");
    }
}

/** \brief informe de mascotas que se realizan el servicio indicado por el usuario
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listS puntero al array Servicio
 * \param tamS tamaño del array Servicio
 * \param listT puntero al array Trabajo
 * \param tamT tamaño del array Trabajo
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void unServicio (Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR)
{
    int resp;
    int flag=0;
    system("cls");
    listarServicios(listS, tamS);
    utn_getNumero(&resp, "\nIngrese servicio: ", "\nError, ingreso incorrecto, debe ingresar de 20001 a 20003\n", 20001, 200013, 3);
    printf("\n\n**************************************************\n");
    printf("*                Un Servicio                *\n");
    printf("**************************************************\n\n");
    printf("\n");
    printf("\n ID             Nombre      Tipo      Color     Edad       Duenio         Raza\n\n");
    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].isEmpty == 0 && listT[i].idServicio == resp)
        {
            mostrarMascota(listM[i], listTipo, tamT, listC, tamC, listCli, tamCli, listR, tamR);
            flag = 1;
        }
    }
    printf("\n\n");

    if (flag == 0)
    {
        printf("\n*** No hay trabajos que ingresaron ese mes ***\n");
    }
}

/** \brief informe de mascotas por raza seleccionada por el usuario
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listS puntero al array Servicio
 * \param tamS tamaño del array Servicio
 * \param listT puntero al array Trabajo
 * \param tamT tamaño del array Trabajo
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void informeXRaza(Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR)
{
    int resp;
    system("cls");
    listarRazas(listR, tamR);
    utn_getNumero(&resp, "\nIngrese raza: ", "\nError, ingreso incorrecto, debe ingresar de 60000 a 60009\n", 60000, 60009, 3);
    system("cls");
    printf("\n\n**************************************************\n");
    printf("*                Informe por raza                *\n");
    printf("**************************************************\n\n");
    printf("\n ID             Nombre      Tipo      Color     Edad       Duenio         Raza\n\n");
    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idRaza == resp)
        {
            mostrarMascota(listM[i], listTipo, tamTipo, listC, tamC, listCli, tamCli, listR, tamR);
        }
    }
    printf("\n\n");
}

/** \brief informe de la raza mas habitual
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listS puntero al array Servicio
 * \param tamS tamaño del array Servicio
 * \param listT puntero al array Trabajo
 * \param tamT tamaño del array Trabajo
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void mayorRaza(Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR)
{
    int raza;
    char razaDesc[20];
    system("CLS");
    for (int i=0; i < tamM-1; i++ )
    {
        for (int j=i+1; j < tamM; j++ )
        {
            if (listM[i].idRaza == listM[j].idRaza && listM[i].isEmpty == 0)
            {
                raza=listM[i].idRaza;
                cargarDescRaza(razaDesc,listM[i].idRaza,listR,tamR);
            }
        }
    }
    printf("\n\n");
    printf("\n\n******************************************************************\n");
    printf("*                      Raza mas habitual                         *\n");
    printf("******************************************************************\n\n");
    printf("La raza mas habitual es %d  %s",raza,razaDesc);
    printf("\n\n");
}

/** \brief informe ordenado por raza
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listS puntero al array Servicio
 * \param tamS tamaño del array Servicio
 * \param listT puntero al array Trabajo
 * \param tamT tamaño del array Trabajo
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param checkT bandera para saber si se cargaron datos
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void orderXRaza(Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int checkT, Raza* listR, int tamR)
{
    Mascota auxMascota;
    char descRaza1[20];
    char descRaza2[20];
    for (int i=0; i<tamM-1; i++)
    {
        cargarDescRaza(descRaza1, listM[i].idRaza, listR, tamR);
        for (int j=i+1; j<tamM; j++)
        {

            cargarDescRaza(descRaza2, listM[j].idRaza, listR, tamR);
            if (strcmp(descRaza1, descRaza2) > 0)
            {
                auxMascota = listM[i];
                listM[i]=listM[j];
                listM[j]=auxMascota;
            }
        }
    }
    mostrarMascotas(listM, tamM, listTipo, tamTipo, listC, tamC, listCli, tamCli, checkT, listR, tamR);
}

/** \brief informe por origen seleccionado por el usuario
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listS puntero al array Servicio
 * \param tamS tamaño del array Servicio
 * \param listT puntero al array Trabajo
 * \param tamT tamaño del array Trabajo
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void informeXOrigen(Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR)
{
    int resp;
    system("cls");
    printf("\n\n******************************************************************\n");
    printf("*                     Informe por origen                         *\n");
    printf("******************************************************************\n\n");
    for (int i=0; i< tamR; i++)
    {
        printf(" %d) %s\n",i, listR[i].Origen);
    }
    utn_getNumero(&resp, "\nIngrese origen: ", "\nError, ingreso incorrecto, debe ingresar de 0 a 9\n", 0, 9, 3);
    system("cls");
    printf("\n\n**************************************************\n");
    printf("*               Informe por origen               *\n");
    printf("**************************************************\n\n");
    printf("\n ID             Nombre      Tipo      Color     Edad       Duenio         Raza\n\n");
    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idRaza == resp+60000)
        {
            mostrarMascota(listM[i], listTipo, tamTipo, listC, tamC, listCli, tamCli, listR, tamR);
        }
    }
    printf("\n\n");
}

/** \brief informe de mascotas por raza seleccionada por el usuario y edad mayor seleccionada
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listS puntero al array Servicio
 * \param tamS tamaño del array Servicio
 * \param listT puntero al array Trabajo
 * \param tamT tamaño del array Trabajo
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void informeXRazayEdad(Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR)
{
    int resp;
    int edad;
    system("cls");
    listarRazas(listR, tamR);
    utn_getNumero(&resp, "\nIngrese raza: ", "\nError, ingreso incorrecto, debe ingresar de 60000 a 60009\n", 60000, 60009, 3);
    utn_getNumero(&edad, "\nIngrese edad minima: ", "\nError, ingreso incorrecto, debe ingresar de 0 a 500\n", 0, 500, 3);
    system("cls");
    printf("\n\n**************************************************\n");
    printf("*                Informe por raza                *\n");
    printf("**************************************************\n\n");
    printf("\n ID             Nombre      Tipo      Color     Edad       Duenio         Raza\n\n");
    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idRaza == resp && listM[i].edad > edad)
        {
            mostrarMascota(listM[i], listTipo, tamTipo, listC, tamC, listCli, tamCli, listR, tamR);
        }
    }
    printf("\n\n");
}



/** \brief informe de mascotas por raza seleccionada por el usuario y color seleccionado
 *
 * \param listM puntero al array Mascota
 * \param tamM tamaño del array Mascota
 * \param listS puntero al array Servicio
 * \param tamS tamaño del array Servicio
 * \param listT puntero al array Trabajo
 * \param tamT tamaño del array Trabajo
 * \param listC puntero al array Color
 * \param tamC tamaño del array Color
 * \param listTipo puntero al array Tipo
 * \param tamTipo tamaño del array Tipo
 * \param listCli puntero al array Cliente
 * \param tamCli tamaño del array Cliente
 * \param listR puntero al array Raza
 * \param tamR tamaño del array Raza
 *
 */
void informeXRazaYColor(Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR)
{
    int resp;
    int color;
    system("cls");
    listarRazas(listR, tamR);
    utn_getNumero(&resp, "\nIngrese raza: ", "\nError, ingreso incorrecto, debe ingresar de 60000 a 60009\n", 60000, 60009, 3);
    listarColores(listC, tamC);
    utn_getNumero(&color, "Ingrese un color: ", "Error, ingreso incorrecto, debe ingresar de 5001 a 5005\n", 5001, 5005, 3);
    system("cls");
    printf("\n\n**************************************************\n");
    printf("*                Informe por raza                *\n");
    printf("**************************************************\n\n");
    printf("\n ID             Nombre      Tipo      Color     Edad       Duenio         Raza\n\n");
    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idRaza == resp && listM[i].idColor == color)
        {
            mostrarMascota(listM[i], listTipo, tamTipo, listC, tamC, listCli, tamCli, listR, tamR);
        }
    }
    printf("\n\n");
}
