#include <iostream>
#include <string>
#include "Estudiantes.h"
using namespace std;

int main()
{
    string  carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento;
    int id_estudiante = 0, telefono = 0, op = 0;
    Estudiantes l = Estudiantes(id_estudiante, carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento);
    cout << "1. Insertar datos\n2. Ver informacion\n3. Actualizar datos\n4. Eliminar informacion";
    cout << "\nIngrese el numero de la accion que desea realizar: ";
    cin >> op;


    if (op == 1) {
        cin.ignore();
        cout << "Ingresecarnet del Estudiante: ";
        getline(cin, carnet);
        cout << "Ingrese nombre del Estudiante: ";
        getline(cin, nombres);
        cout << "Ingrese apellidos del estudiante: ";
        getline(cin, apellidos);
        cout << "Ingrese direccion del estudiante: ";
        getline(cin, direccion);
        cout << "Ingrese el telefono del estudiante: ";
        getline(cin, telefono);
        cout << "Ingrese el genero del estudiante: ";
        getline(cin, telefono);
        cout << "Ingrese el email del estudiante: ";
        getline(cin,email);
        cout << "Ingresela fecha de nacimeinto del estudiante: ";
        getline(cin, fecha_nacimiento);


        Estudiantes e = Estudiantes(id_estudiante, carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento);
        e.crear();
    }
    if (op == 2) {
        l.leer();
    }
    if (op == 3) {
        l.leer();
        cout << "\nIngrese el id del estudiante que desea actualizar: ";
        cin >> id_estudiante;
        cin.ignore();
        cout << "Ingrese carnet del estudiante: ";
        getline(cin, carnet);
        cout << "Ingrese nombre del estudiante: ";
        getline(cin, nombres);
        cout << "Ingrese apellidos del estudiante: ";
        getline(cin, apellidos);
        cout << "Ingrese direccion del estudiante: ";
        getline(cin, direccion);
        cout << "Ingrese el telefono del estudiante: ";
        getline(cin, telefono);
        cout << "Ingrese el genero del estudiante: ";
        getline(cin, genero);
        cout << "Ingrese el email del estudiante: ";
        getline(cin, email);
        cout << "Ingrese la fecha de nacimiento del estudiante: ";
        getline(cin, fecha_nacimiento);

        Estudiantes e = Estudiantes(id_estudiante, carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento);
        e.actualizar();
    }
    if (op == 4) {
        l.leer();
        cout << "\nIngrese el id del proveedor que desea eliminar: ";
        cin >> id_estudiante;
        Estudiantes e = Estudiantes(id_estudiante, carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento);
        e.eliminar();
    }

}
