#pragma once
#include <mysql.h>
#include <string>
#include "ConexionBD.h"
using namespace std;

class Estudiantes{
public:
	string carnet, nombres, apellidos, direccion, genero, email,fecha_nacimiento;
	int id_estudiante;
	int telefono;

public:
	Estudiantes() {
	}
	Estudiantes(int idest, string nom, string ape, string dir, string gen, int tel, string em, string fn) {
		id_estudiante = idest;
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		genero = gen
		telefono = tel;
		email = em;
		fecha_nacimiento = fn;

	}

	void crear() {
		int q_query;
		ConexionBD cn = ConexionBD();
		cn.ab_conexion();

		if (cn.getConectar()) {
			string t = to_string(telefono);
			string insertar = "insert into estudiantes(carnet,nombres,apellidos,direccion,telefono,genero,email,fecha_nacimiento) values('" + carnet + "','" +nombres + "','" +apellidos + "','" + direccion + "'," + t + ",'" + genero + "','" + email + "','" + fecha_nacimiento + "');";
			const char* i = insertar.c_str();
			q_query = mysql_query(cn.getConectar(), i);
			if (!q_query) {
				cout << "Ingreso exitoso\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.ce_conexion();
	}

	void leer() {
		int q_query;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.ab_conexion();

		if (cn.getConectar()) {
			string consulta = "select * from estudiantes";
			const char* c = consulta.c_str();
			q_query = mysql_query(cn.getConectar(), c);
			cout << "\n---------- Estudiantes ----------\n";
			cout << "\nId Estudiantes, Carnet, Nombres, Apellidos, Direccion, Telefono, Genero, Email, Fecha Nacimineto\n\n";
			if (!q_query) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << " , " << fila[7] << " , " << fila[8] << endl;

				}
			}
			else {
				cout << "Error al consultar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.ce_conexion();
	}


void actualizar() {
	int q_query;
	ConexionBD cn = ConexionBD();
	cn.ab_conexion();

	if (cn.getConectar()) {
		string e = to_string(id_estudiante);
		string t = to_string(telefono);
		string update = "update estudiantes set estudiante='" + carnet + "',nombres='" + nombres + "',apellidos='" + apellidos + "',direccion='" + direccion + "',telefono='" + t + "',genero='" + genero + "',apellidos='" + email + "',fecha_nacimiento='" + fecha_nacimiento + "' where id_estudiantes=" + e + ";";
		const char* i = update.c_str();
		q_query = mysql_query(cn.getConectar(), i);
		if (!q_query) {
			cout << "Actualizacion exitosa\n";
		}
		else {
			cout << "Error al ingresar\n";
		}
	}
	else {
		cout << "Error";
	}
	cn.ce_conexion();

}

void eliminar() {
	int q_query;
	ConexionBD cn = ConexionBD();
	cn.ab_conexion();

	if (cn.getConectar()) {
		string e = to_string(id_estudiante);
		string elimin = "delete from estudiantes where id_estudiantes=" + e + ";";
		const char* i = elimin.c_str();
		q_query = mysql_query(cn.getConectar(), i);
		if (!q_query) {
			cout << "Eliminacion exitosa\n";
		}
		else {
			cout << "Error al ingresar\n";
		}
	}
	else {
		cout << "Error";
	}
	cn.ce_conexion();
}

};
