// Examen.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// 
#include <mysql.h>
#include <iostream>
#include <string> 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "conexionBD.h"

using namespace std;

class VentasDetalles {
private:
	int idVentaDetalle, idVenta, idProducto, precioUnitario, cantidad;
public:
	VentasDetalles() {}

	VentasDetalles(int idVentaDetallec, int idVentac, int idProductoc, int precioUnitarioc, int cantidadc) {
		idVentaDetalle = idVentaDetallec;
		idVenta = idVentac;
		idProducto = idProductoc;
		precioUnitario = precioUnitarioc;
		cantidad = cantidadc;
	}

	VentasDetalles(int idVentac, int idProductoc, int precioUnitarioc, int cantidadc) {
		idVenta = idVentac;
		idProducto = idProductoc;
		precioUnitario = precioUnitarioc;
		cantidad = cantidadc;
	}

	VentasDetalles(int idVentaDetallec) {
		idVentaDetalle = idVentaDetallec;
	}


	void SetidVentaDetalle(int idVentaDetallec) { idVentaDetalle = idVentaDetallec; }
	void SetidVenta(int idVentac) { idVenta = idVentac; }
	void SetidProducto(int idProductoc) { idProducto = idProductoc; }
	void SetprecioUnitarioc(int precioUnitarioc) { precioUnitario = precioUnitarioc; }
	void Setcantidad(int cantidadc) { cantidad = cantidadc; }

	const int GetidVentaDetalle() { return idVentaDetalle; }
	const int GetidVenta() { return idVenta; }
	const int GetidProducto() { return idProducto; }
	const int GetprecioUnitarioc() { return precioUnitario; }
	const int Getcantidad() { return cantidad; }


	//CRUD

	void createData() {
		int q_estado;
		conexionBD cn = conexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insert = "INSERT INTO `tareasql`.`venta_detalle`(`idVenta`,`idProducto`,`cantidad`,`precio_unitario`)VALUES('" + to_string(idVenta) + "','" + to_string(idProducto) + "','" + to_string(cantidad) + "','" + to_string(precioUnitario) + "')";
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
			string update = "update tareasql.venta_detalle  SET idVenta = '" + to_string(idVenta) + "',idProducto = '" + to_string(idProducto) + "',cantidad = '" + to_string(cantidad) + "',precio_unitario = '" + to_string(precioUnitario) + "' where idVenta_detalle = " + to_string(idVentaDetalle) + "  ";
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
			string deleteSQL = "DELETE FROM tareasql.venta_detalle WHERE idVenta_detalle = " + to_string(idVentaDetalle) + "; ";
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
			string selectSQL = "Select * from tareasql.venta_detalle WHERE idVenta_detalle = " + to_string(idVentaDetalle) + "; ";
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