// Examen.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// 
#include <mysql.h>
#include <iostream>
#include <string> 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "conexionBD.h"

using namespace std;

class Ventas {
private:
	int idVentas, nofactura, idcliente, idempleado;
	string serie, fechafactrura, fechaIngreso;

public:
	Ventas() {}

	Ventas( int nofacturac, int idclientec, int idempleadoc, string seriec, string fechafactrurac, string fechaIngresoc) {
		nofactura = nofacturac;
		idcliente = idclientec;
		idempleado = idempleadoc;
		serie = seriec;
		fechafactrura = fechafactrurac;
		fechaIngreso = fechaIngresoc;
	}

	Ventas(int idVentasc, int nofacturac, int idclientec, int idempleadoc, string seriec, string fechafactrurac, string fechaIngresoc) {
		idVentas = idVentasc;
		nofactura = nofacturac;
		idcliente = idclientec;
		idempleado = idempleadoc;
		serie = seriec;
		fechafactrura = fechafactrurac;
		fechaIngreso = fechaIngresoc;
	}

	Ventas(int idVentasc) {
		idVentas = idVentasc;
	}


	void SetidVentas(int idVentasc) { idVentas = idVentasc; }
	void Setnofactura(int nofacturac) { nofactura = nofacturac; }
	void Setidcliente(int idclientec) { idcliente = idclientec; }
	void Setidempleado(int idempleadoc) { idempleado = idempleadoc; }
	void Setserie(string seriec) { serie = seriec; }
	void Setfechafactrura(string fechafactrurac) { fechafactrura = fechafactrurac; }
	void SetfechaIngreso(string fechaIngresoc) { fechaIngreso = fechaIngresoc; }

	const int GetidVentas() { return idVentas; }
	const int Getnofactura() { return nofactura; }
	const int Getidcliente() { return idcliente; }
	const int Getidempleado() { return idempleado; }
	const string Getserie() { return serie; }
	const string Getfechafactrura() { return fechafactrura; }
	const string GetfechaIngreso() { return fechaIngreso; }


	//CRUD

	void createData() {
		int q_estado;
		conexionBD cn = conexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insert = "INSERT INTO `tareasql`.`ventas`(`noFactura`,`serie`,`fechafactura`,`idcliente`,`idempleado`,`fechaingreso`) VALUES ('" + to_string(nofactura) + "','" + serie + "','" + fechafactrura + "','" + to_string(idcliente) + "','" + to_string(idempleado) + "','" + fechaIngreso + "')";
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
			string update = "update tareasql.ventas  SET noFactura = '" + to_string(nofactura) + "',serie = '" + serie + "',fechafactura = '" + fechafactrura + "',idcliente = '" + to_string(idcliente) + "',idempleado = '" + to_string(idempleado) + "',fechaIngreso = '" + fechaIngreso + "' where idVenta = " + to_string(idVentas) + "  ";
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
			string deleteSQL = "DELETE FROM tareasql.ventas WHERE idVenta = " + to_string(idVentas) + "; ";
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
			string selectSQL = "Select * from tareasql.ventas WHERE idVenta = " + to_string(idVentas) + "; ";
			const char* i = selectSQL.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << endl;
				}
			}
			else {
				cout << "Error al ingresar";
			}
		}
		cn.cerrar_conexion();
	}
};