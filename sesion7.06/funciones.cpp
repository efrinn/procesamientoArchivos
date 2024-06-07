#include <iostream>
#include <string.h>
#include "variables.h"
using namespace std;

CIUDAD ciudades[MAX_REG];
int pos=0;

//crud
void agregar (CIUDAD *c);
void editar(CIUDAD *c, int id);
void eliminar(int id);
CIUDAD buscar(int id);
int menu(int op);
void principal();
void pedirDatos();

void agregar(CIUDAD *c)
{
    ciudades[pos]=*c;
    pos++;
}

CIUDAD buscar(int id){
    for(int i =0; i<pos; i++){
        if(id == ciudades[i].id){
            return ciudades[i];
        }
    }
    CIUDAD c;
    return c;
};

int obtPos(int id){
    for(int i = 0;i<pos; i++){
        if(ciudades[i].id == id){
            return i;
        }
    }
}

void editar(CIUDAD *c,int id){
    int posi= obtPos(id);
    CIUDAD ciudad = buscar(id);
    strcpy(ciudad.nombre, c-> nombre);
    strcpy(ciudad.descripcion, c->descripcion);
}

void eliminar(int id){
    int posi = obtPos(id);
    for(int i = posi; i<posi-1; i++){
        ciudades[i] = ciudades[i+1];
    }
    pos--;
}

int menu(){
    int op;
    cout <<"Menu\n";
    cout <<"1. Agregar\n";
    cout <<"2. Editar\n";
    cout <<"3. Eliminar\n";
    cout <<"4. Buscar\n";
    cout <<"5. Mostrar todo\n";
    cout <<"6. SALIR\n";
    cout <<"digite la opcion";
    cin >> op;
    return op;
}

void principal(){
    int op;
    do{
        op = menu();
        switch(op){
            case 1:
            pedirDatos();
            break;
            case 6:
            cout<<"Adios mi loco";
            break;
            default:
            cout<<"No hay mas opciones tarado";
        }
    }while(op !=6);
}

void pedirDatos(){
    CIUDAD ciudads;
    cout <<"Datos de Ciudad\n";
    cout <<"ID: ";
    cin >> ciudads.id;
    cout<<"NOMBRE: ";
    cin >> ciudads.nombre;
    cout<<"Descripcion: ";
    cin >> ciudads.descripcion;
    agregar(&ciudads);
}