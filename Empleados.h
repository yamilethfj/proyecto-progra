// Examen.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// 
#include <mysql.h>
#include <iostream>
#include <string> 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "conexionBD.h"

using namespace std;

class Empleados {
private:
	
	int idEmpleado, telefono, dpi, genero, idPuesto;
	string nombre, apellido, direccion, fehaNacimiento, fechaInicio, fechaIngreso;

public:
	Empleados() {}

	Empleados(int telefonoc, int dpic, int generoc, int idPuestoc, string nombrec, string apellidoc, string direccionc, string fehaNacimientoc, string fechaInicioc, string fechaIngresoc) {
		telefono = telefonoc;
		dpi = dpic;
		genero = generoc;
		idPuesto = idPuestoc;
		nombre = nombrec;
		apellido = apellidoc;
		direccion = direccionc;
		fehaNacimiento = fehaNacimientoc;
		fechaInicio = fechaInicioc;
		fechaIngreso = fechaIngresoc;
	}
	
	Empleados(int idEmpleadoc, int telefonoc, int dpic, int generoc, int idPuestoc, string nombrec, string apellidoc, string direccionc, string fehaNacimientoc, string fechaInicioc, string fechaIngresoc) {
		idEmpleado = idEmpleadoc;
		telefono = telefonoc;
		dpi = dpic;
		genero = generoc;
		idPuesto = idPuestoc;
		nombre = nombrec;
		apellido = apellidoc;
		direccion = direccionc;
		fehaNacimiento = fehaNacimientoc;
		fechaInicio = fechaInicioc;
		fechaIngreso = fechaIngresoc;
	}

	Empleados(int idEmpleadoc) {
		idEmpleado = idEmpleadoc;
	}


	void SetidEmpleado(int idEmpleadoc) { idEmpleado = idEmpleadoc; }
	void Settelefono(int telefonoc) { telefono = telefonoc; }
	void Setdpi(int dpic) { dpi = dpic; }
	void Setgenero(int generoc) { genero = generoc; }
	void SetidPuesto(int idPuestoc) { idPuesto = idPuestoc; }
	void Setnombre(string nombrec) { nombre = nombrec; }
	void Setapellido(string apellidoc) { apellido = apellidoc; }
	void Setdireccion(string direccionc) { direccion = direccionc; }
	void SetfehaNacimiento(string fehaNacimientoc) { fehaNacimiento = fehaNacimientoc; }
	void SetfechaInicio(string fechaInicioc) { fechaInicio = fechaInicioc; }
	void SetfechaIngreso(string fechaIngresoc) { fechaIngreso = fechaIngresoc; }


	const int GetidEmpleado() { return idEmpleado; }
	const int Gettelefono() { return telefono; }
	const int Getdpi() { return dpi; }
	const int Getgenero() { return genero; }
	const int GetidPuesto() { return idPuesto; }
	const string Getnombre() { return nombre; }
	const string Getapellido() { return apellido; }
	const string Getdireccion() { return direccion; }
	const string GetfehaNacimiento() { return fehaNacimiento; }
	const string GetfechaInicio() { return fechaInicio; }
	const string GetfechaIngreso() { return fechaIngreso; }

	//CRUD

	void createData() {
		int q_estado;
		conexionBD cn = conexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insert = "INSERT INTO `tareasql`.`empleados`(`nombres`,`apellidos`,`direccion`,`telefono`,`DPI`,`genero`,`fecha_nacimiento`,`idPuestos`,`fecha_inicio_labores`,`fechaingreso`) VALUES ('" + nombre + "','" + apellido + "','" + direccion + "','" + to_string(telefono) + "','" + to_string(dpi) + "',b'" + to_string(genero) + "','" + fehaNacimiento + "','" + to_string(idPuesto) + "','" + fechaInicio + "','" + fechaIngreso + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso existoso";
			}
			else {
				cout << "Error al ingresar";
			}
		}
		cn.cerrar_conexion();
	}

	void updateData() {
		int q_estado;
		conexionBD cn = conexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string update = "update tareasql.empleados  SET nombres = '" + nombre + "', apellidos = '" + apellido + "', direccion = '" + direccion + "', telefono = '" + to_string(telefono) + "',DPI = '" + to_string(dpi) + "', genero = b'" + to_string(genero) + "', fecha_nacimiento = '" + fehaNacimiento + "', idPuestos = '" + to_string(idPuesto) +"', fecha_inicio_labores = '" + fechaInicio + "', fechaingreso = '" + fechaIngreso + "'  where idEmpleado = " + to_string(idEmpleado) + "  ";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "update existoso";
			}
			else {
				cout << "Error al update";
			}
		}
		cn.cerrar_conexion();
	}

	void deleteData() {
		int q_estado;
		conexionBD cn = conexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string deleteSQL = "DELETE FROM tareasql.empleados WHERE idEmpleado = " + to_string(idEmpleado) + "; ";
			const char* i = deleteSQL.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "delete existoso";
			}
			else {
				cout << "Error al delete";
			}
		}
		cn.cerrar_conexion();
	}

	void selectData() {
		int q_estado;
		conexionBD cn = conexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string selectSQL = "Select * from tareasql.empleados WHERE idEmpleado = " + to_string(idEmpleado) + "; ";
			const char* i = selectSQL.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << fila[2] << "," << fila[3] << fila[4] << "," << fila[5] << fila[6] << "," << fila[7] << "," << fila[8] << fila[9] << "," << fila[10]<<endl;
				}
			}
			else {
				cout << "Error al ingresar";
			}
		}
		cn.cerrar_conexion();
	}
};