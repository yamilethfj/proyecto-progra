// Examen.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// 
#include <mysql.h>
#include <iostream>
#include <string> 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "conexionBD.h"

using namespace std;

class Clientes {
private:
	int idCliente;
	int genero;
	int telefono;

	string nombre;
	string apellido;
	string nit;
	string correo;
	string fecha;


public:
	Clientes() {}

	Clientes(string nombrec, string apellidoc, string nitc, int generoc, int telefonoc, string  correoc, string fechac) {
		nombre = nombrec;
		apellido = apellidoc;
		nit = nitc;
		genero = generoc;
		telefono = telefonoc; 
		correo = correoc;
		fecha = fechac;
	}

	Clientes(int idClientec, string nombrec, string apellidoc, string nitc, int generoc, int telefonoc, string  correoc, string fechac) {
		idCliente = idClientec;
		nombre = nombrec;
		apellido = apellidoc;
		nit = nitc;
		genero = generoc;
		telefono = telefonoc;
		correo = correoc;
		fecha = fechac;
	}

	Clientes(int idClientec) {
		idCliente = idClientec;
	}


	void SetIdCliente(int idClientec) { idCliente = idClientec; }
	void SetGenero(int generoc) { genero = generoc;}
	void SetTelefono(int telefonoc) { telefono = telefonoc; }
	void SetNit(int nitc) { nit = nitc; }

	void SetNombre(string nombrec) { nombre = nombrec;}
	void SetApellido(string apellidoc) { apellido = apellidoc;}
	void SetCorreoElectron(string correoc) { correo = correoc; }
	void SetFecha(string fechac) { fecha = fechac; }

	const int GetIdCleinte() { return idCliente;  }
	const int GetGenero() { return genero;  }
	const int GetTelefono() { return telefono; }

	const string GetNit() { return nit; }
	const string GetNombre() { return nombre; }
	const string GetApellido() { return apellido; }
	const string GetCorreoEletronico() { return correo; }
	const string GetFecha() { return fecha; }



	//CRUD

	void createData() {
		int q_estado;
		conexionBD cn = conexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insert = "INSERT INTO `tareasql`.`clientes`(`nombres`,`apellidos`,`nit`,`correo_electronico`,`telefono`,`genero`,`fechaingreso`) VALUES ('" + nombre + "','" + apellido + "','" + nit + "','" + correo + "','" + to_string(telefono) + "',b'" + to_string(genero) + "','" + fecha + "')";
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
			string update = "update tareasql.clientes  SET nombres = '" + nombre + "',apellidos = '" + apellido + "',nit = '" + nit + "',correo_electronico = '" + correo + "',telefono = '" + to_string(telefono) + "',genero = b'" + to_string(genero) + "',fechaingreso = '" + fecha + "' where idCliente = " + to_string(idCliente) + "  ";
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
			string deleteSQL = "DELETE FROM tareasql.clientes WHERE idCliente = " + to_string(idCliente) + "; ";
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
			string selectSQL = "Select * from tareasql.clientes WHERE idCliente = " + to_string(idCliente) + "; ";
			const char* i = selectSQL.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5]<<endl;
				}
			}
			else {
				cout << "Error al ingresar";
			}
		}
		cn.cerrar_conexion();
	}
};