#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

int informes(Mascota* listM, int tamM, Servicio* listS, int tamS, Trabajo* listT, int tamT, Color* listColor, int tamC, Tipo* listTipo, int tamTipo, Cliente* listCli, int tamCli, int checkT, Raza* listR, int tamR);
int menuInformes();
void informeXColor (Mascota* listM, int tamM, Tipo* listT, int tamT, Color* listC, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR);
void imprimirXColor(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Cliente* listCli, int tamCli, int resp, Raza* listR, int tamR);
void informeXTipo (Mascota* listM, int tamM, Tipo* listT, int tamT, Color* listC, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR);

void imprimirXTipo(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Cliente* listCli, int tamCli, int resp, Raza* listR, int tamR);
void masJoven (Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR);
void separadosXColor(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR);
int xTipoYColor(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Raza* listR, int tamR);
void informeMayorColor(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Raza* listR, int tamR);
void servicioXMascota (Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int checkT, Raza* listR, int tamR);
void TotalPrecioXMascota(Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int checkT, Raza* listR, int tamR);
void informeTrabajosXfecha (Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int checkT, Raza* listR, int tamR);
void unServicio (Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR);

void informeXRaza(Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR);
void mayorRaza(Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR);
void orderXRaza(Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int checkT, Raza* listR, int tamR);
void informeXOrigen(Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR);
void informeXRazayEdad(Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR);
void informeXRazaYColor(Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, Raza* listR, int tamR);
