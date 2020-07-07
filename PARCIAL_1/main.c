#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "utn.h"
#include "trabajos.h"
#include "informes.h"

#define TAMTIPO 5
#define TAMCOLOR 5
#define TAMSERVICIO 3
#define TAMCLIENTES 10
#define TAMMASCOTAS 100
#define TAMTRABAJO 100
#define TAMRAZA 10
#define TAMHARDCODEO 10

#define IDSTART 100
#define IDSTARTTRABAJOS 10000
#define IDCLIENTE 30000

Mascota listMascota[TAMMASCOTAS];
Trabajo listTrabajo[TAMTRABAJO];

int menu();

Servicio listServ[3]=
{
    {20001, "Corte", 250.00},
    {20002, "Desparasitado", 300.00},
    {20003, "Castrado", 400.00}
};

Color listColor[5]=
{
    {5001, "Negro"},
    {5002, "Blanco"},
    {5003, "Gris"},
    {5004, "Rojo"},
    {5005, "Azul"}
};

Tipo listTipo[5]=
{
    {1001, "Ave"},
    {1002, "Perro"},
    {1003, "Gato"},
    {1004, "Roedor"},
    {1005, "Pez"}
};

Cliente listCli[10]=
{
    {30000, "juan", 'm'},
    {30001, "maria", 'f'},
    {30002, "carlos", 'm'},
    {30003, "marta", 'f'},
    {30004, "lujan", 'f'},
    {30005, "dario", 'm'},
    {30006, "sofia", 'f'},
    {30007, "juana", 'f'},
    {30008, "roberto", 'm'},
    {30009, "pepe", 'm'}
};

Raza listRaza[10]=
{
    {60000, "mojarrita", "Atlantico"},
    {60001, "bagre", "America"},
    {60002, "caniche", "Francia"},
    {60003, "boxer", "Aleman"},
    {60004, "siames", "Tailandia"},
    {60005, "persa", "Iran"},
    {60006, "ardillas", "Brasil"},
    {60007, "hamster", "Siria"},
    {60008, "loro", "Tropicales"},
    {60009, "lechuza", "Bosques"}
};

int main()
{
    int salida=1;
    int idMascota=IDSTART;
    int idTrabajos=IDSTARTTRABAJOS;
    int idCliente=IDCLIENTE;
    int check=1;
    int checkTrabajo=1;

    idMascota= idMascota+TAMHARDCODEO;
    idCliente= idCliente+IDCLIENTE;
    idTrabajos=idTrabajos+TAMHARDCODEO;
    initMascotas(listMascota, TAMMASCOTAS);
    initTrabajos(listTrabajo, TAMTRABAJO);
    harcodeomascotas(listMascota, TAMHARDCODEO);
    harcodeoTrabajos(listTrabajo, TAMHARDCODEO);

    do
    {
        system("CLS");
        switch(menu())
        {
        case 1://Alta
            if (altaMascota(idMascota, idCliente, TAMCLIENTES, listMascota, TAMMASCOTAS, listColor, listTipo, listCli, listRaza, TAMRAZA) == 0)
            {
                idMascota++;
                check=1;
            }
            break;
        case 2://Modificar
            buscarMascota(listMascota, TAMMASCOTAS, listTipo, TAMTIPO, listColor, TAMCOLOR, listCli, TAMCLIENTES, check, listRaza, TAMRAZA);
            break;
        case 3://Baja
            bajaMascota(listMascota, TAMMASCOTAS, listTipo, TAMTIPO, listColor, TAMCOLOR, listCli, TAMCLIENTES, check, listRaza, TAMRAZA);
            break;
        case 4://lista
            mostrarMascotas(listMascota, TAMMASCOTAS, listTipo, TAMTIPO, listColor, TAMCOLOR, listCli, TAMCLIENTES, check, listRaza, TAMRAZA);
            system("pause>nul");
            break;
        case 5://Listar tipos
            listarTipos(listTipo, TAMTIPO);
            system("pause>nul");
            break;
        case 6://Listar colores
            listarColores(listColor, TAMCOLOR);
            system("pause>nul");
            break;
        case 7://Listar servicios
            listarServicios(listServ, TAMSERVICIO);
            system("pause>nul");
            break;
        case 8://Alta trabajo
            if (altaTrabajo(idTrabajos, listTrabajo, TAMTRABAJO, listMascota, TAMMASCOTAS, listTipo, TAMTIPO, listColor, TAMCOLOR, listServ, TAMSERVICIO, listCli, TAMCLIENTES, check, listRaza, TAMRAZA) == 0)
            {
                checkTrabajo=1;
                idTrabajos++;
            }
            break;
        case 9://Listar trabajos
            listarTrabajos(listTrabajo, TAMTRABAJO, listMascota, TAMMASCOTAS, listServ, TAMSERVICIO, checkTrabajo);
            system("pause>nul");
            break;
        case 10://Listar trabajos
            if (informes(listMascota, TAMMASCOTAS, listServ, TAMSERVICIO, listTrabajo, TAMTRABAJO, listColor, TAMCOLOR, listTipo, TAMTIPO, listCli, TAMCLIENTES, check, listRaza, TAMRAZA)== -1)
            {
                salida=0;
            }
            break;
        case 11://Listar razas
            listarRazas(listRaza, TAMRAZA);
            system("pause>nul");
            break;
        case 12:
            system("cls");
            printf("\n\n**************************************************\n");
            printf("*          Saliendo de la aplicacion             *\n");
            printf("**************************************************\n\n");
            salida=0;
            break;
        default:
            printf("\nSe ingreso un dato invalido\n");
            system("pause>nul");
            break;
        }
    }
    while (salida !=0);
    return 0;
}

/** \brief Menu principal
 *
 *
 */
int menu()
{
    int resp;
    printf("\n\n**************************************************\n");
    printf("*                Menu Veterinaria                *\n");
    printf("**************************************************\n\n");
    printf("1) Alta Mascota\n");
    printf("2) Modificar Mascota\n");
    printf("3) Baja Mascota\n");
    printf("4) Listar Mascotas\n");
    printf("5) Listar Tipos\n");
    printf("6) Listar Colores\n");
    printf("7) Listar Servicios\n");
    printf("8) Alta Trabajo\n");
    printf("9) Listar Trabajos\n");
    printf("10) Menu de informes\n");
    printf("11) listar razas\n");
    printf("12) Exit\n");
    utn_getNumero(&resp, "\nIngrese una opcion: ", "\nError, ingreso incorrecto, debe ingresar de 0 a 12\n", 0, 12, 3);
    return resp;
}
