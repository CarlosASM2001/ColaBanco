// ColaBanco.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
#include "Persona.h"
#include "Colas_dinamicas.h"
#include "Pilas_dinamicas.h"
#include <string>
#include <vector>





//Variable Global
Colas_dinamicas<int> cola;
Pilas_dinamicas<int> pila;

void menu();
void generarClave();
int generador(int cedula);
using namespace std;




int main()
{
    menu();
}


void menu() {

    char tecla;
    bool band = false;
    int claveUsuario;

    do {
        system("cls");
        if (cola.isVacia()) {

            cout << "No hay clientes en espera" << endl;


        }
        else {
            cout << "Clientes en Espera" << endl;
            cola.Imprimir();
        }
        cout << "====================================" << endl;
        cout << "A-) Ingrese Cedula para generar su Clave" <<endl;
        cout << "1-) Llamar al siguiente de la cola virtual a taquilla 1" << endl;
        cout << "2-) Llamar al siguiente de la cola virtual a taquilla 2" << endl;
        cout << "3-) Llamar al siguiente de la cola virtual a taquilla 3" << endl;
        cout << "4-) Finalizar Programa" << endl;
        cout << "Opcion:";
        tecla = _getch();


        switch (tecla) {
        case 'a':
            generarClave();
            break;

        case '1':
            system("cls");
            claveUsuario = cola.Eliminar();
            cout << "Taquilla #1" << endl;
            if (claveUsuario == NULL) {
                cout << "No hay cliente en taquilla" << endl;
            }
            else {
                cout << "LLamando a Cliente: " << claveUsuario << endl;
            }
            system("PAUSE");
            break;

        case '2':
            system("cls");
            claveUsuario = cola.Eliminar();
            cout << "Taquilla #3" << endl;
            if (claveUsuario == NULL) {
                cout << "No hay cliente en taquilla" << endl;
            }
            else {
                cout << "LLamando a Cliente: " << claveUsuario << endl;
            }
            system("PAUSE");
            break;

        case '3':
            system("cls");
            claveUsuario = cola.Eliminar();
            cout << "Taquilla #3" << endl;
            if (claveUsuario == NULL) {
                cout << "No hay cliente en taquilla" << endl;
            }
            else {
                cout << "LLamando a Cliente: " << claveUsuario << endl;
            }
            system("PAUSE");
            break;

        case '4':
            cout << "finalizado" << endl;
            band = true;
            break;

        }




    } while (band==false);




}

void generarClave() {

    int cedula;
    int i=0;
    int auxClave;
    vector<int> cifras;
    string cedulaInvert;
    string claveString;
    system("cls");

    cout << "Ingrese Cedula del cliente: " << endl;
    cin >> cedula;

    auxClave = generador(cedula);
    claveString = std::to_string(auxClave);


    if (auxClave == 0 || claveString.length()<=2){

        
        
        while (cedula > 0) {
            cifras.push_back(cedula % 10);

            cedula = cedula / 10;

            pila.Anadir(cifras[i]);

            i++;

            
        }
       

        pila.invert();
        
        while (!pila.isVacia()) {
            cedulaInvert += std::to_string(pila.Eliminar());
           
        }


        cout <<" Cedula Invertida " << cedulaInvert << endl;
        system("PAUSE");
        auxClave = generador(atoi(cedulaInvert.c_str()));
         

    }
        
   
    cola.Anadir(auxClave);

    
    

}
int generador(int cedula) {

    int clave;
    int auxClave;
    int aux;
    clave = cedula % 1000;
  



    if (cola.isVacia()) {
        return clave;
    }

    while (!cola.isVacia()) {

        while (cedula > 0) {
            clave = cedula % 1000;
            aux = cola.Buscar(clave);

            if (aux == 1) {
                cedula = cedula / 10;
                
            }
            else {
                return clave;
            }
        }

    }


    return 0;
}










// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
