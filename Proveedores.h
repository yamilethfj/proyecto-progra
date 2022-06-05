// Examen.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// 
#include <mysql.h>
#include <iostream>
#include <string> 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "conexionBD.h"

using namespace std;

class Proveedores {
private:
	int idProveedores;
	string proveedor, nit, direccion, telefono;
public:
	Proveedores() {}

	Proveedores(int idProveedoresc, string proveedorc, string nitc, string direccionc, string telefonoc) {
		idProveedores = idProveedoresc;
		proveedor = proveedorc;
		nit = nitc;
		direccion = direccionc;
		telefono = telefonoc;
	}

	Proveedores(string proveedorc, string nitc, string direccionc, string telefonoc) {
		proveedor = proveedorc;
		nit = nitc;
		direccion = direccionc;
		telefono = telefonoc;
	}

	Proveedores(int idProveedoresc) {
		idProveedores = idProveedoresc;
	}


	void SetidProveedores(int idProveedoresc) { idProveedores = idProveedoresc; }
	void Setproveedor(string proveedorc) { proveedor = proveedorc; }
	void Setnit(string nitc) { nit = nitc; }
	void Setdireccion(string direccionc) { direccion = direccionc; }
	void Settelefono(string telefonoc) { telefono = telefonoc; }


	const int GetidProveedores() { return idProveedores; }
	const string Getproveedor() { return proveedor; }
	const string Getnit() { return nit; }
	const string Getdireccion() { return direccion; }
	const string Gettelefono() { return telefono; }


	//CRUD

	void createData() {
		int q_estado;
		conexionBD cn = conexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insert = "INSERT INTO `tareasql`.`proveedores`(`proveedor`,`nit`,`direccion`,`telefono`)VALUES('" + proveedor+ "','" + nit + "','" + direccion + "','" + telefono + "')";
			cout << insert;
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
			string update = "update tareasql.proveedores  SET proveedor = '" + proveedor + "',nit = '" + nit + "',direccion = '" + direccion + "',telefono = '" + telefono + "' where idProveedor = " + to_string(idProveedores) + "  ";
			cout << update;
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
			string deleteSQL = "DELETE FROM tareasql.proveedores WHERE idProveedor = " + to_string(idProveedores) + "; ";
			cout << deleteSQL;
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
			string selectSQL = "Select * from tareasql.proveedores WHERE idProveedor = " + to_string(idProveedores) + "; ";
			const char* i = selectSQL.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << endl;
				}
			}
			else {
				cout << "Error al ingresar";
			}
		}
		cn.cerrar_conexion();
	}
};