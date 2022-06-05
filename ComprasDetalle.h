// Examen.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// 
#include <mysql.h>
#include <iostream>
#include <string> 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "conexionBD.h"

using namespace std;

class CompraDetalles {
private:
	int idCompraDetalle, idCompra, idProducto, cantidad;
	double precioCostoUnitario;
public:
	CompraDetalles() {}

	CompraDetalles(int idCompraDetallec, int idComprac, int idProductoc, int cantidadc, double precioCostoUnitarioc) {
		idCompraDetalle = idCompraDetallec;
		idCompra = idComprac;
		idProducto = idProductoc;
		cantidad = cantidadc;
		precioCostoUnitario = precioCostoUnitarioc;
	}

	CompraDetalles( int idComprac, int idProductoc, int cantidadc, double precioCostoUnitarioc) {
		idCompra = idComprac;
		idProducto = idProductoc;
		cantidad = cantidadc;
		precioCostoUnitario = precioCostoUnitarioc;
	}

	CompraDetalles(int idCompraDetallec) {
		idCompraDetalle = idCompraDetallec;
	}


	void SetidCompraDetalle(int idCompraDetallec) { idCompraDetalle = idCompraDetallec; }
	void SetidCompra(int idComprac) { idCompra = idComprac; }
	void SetidProducto(int idProductoc) { idProducto = idProductoc; }
	void Setcantidad(int cantidadc) { cantidad = cantidadc; }
	void SetprecioCostoUnitario(int precioCostoUnitarioc) { precioCostoUnitario = precioCostoUnitarioc; }

	const int GetidCompraDetalle() { return idCompraDetalle; }
	const int GetidCompra() { return idCompra; }
	const int GetidProducto() { return idProducto; }
	const int Getcantidad() { return cantidad; }
	const double GetprecioCostoUnitario() { return precioCostoUnitario; }



	//CRUD

	void createData() {
		int q_estado;
		conexionBD cn = conexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insert = "INSERT INTO `tareasql`.`compras_detalle`(`idCompra`,`idProducto`,`cantidad`,`precio_costo_unitario`)VALUES('" + to_string(idCompra) + "','" + to_string(idProducto) + "','" + to_string(cantidad) + "','" + to_string(precioCostoUnitario) + "')";
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
			string update = "update tareasql.compras_detalle  SET idCompra = '" + to_string(idCompra) + "',idProducto = '" + to_string(idProducto) + "',cantidad = '" + to_string(cantidad) + "',precio_costo_unitario = '" + to_string(precioCostoUnitario) + "' where idCompra_detalle = " + to_string(idCompraDetalle) + "  ";
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
			string deleteSQL = "DELETE FROM tareasql.compras_detalle WHERE idCompra_detalle = " + to_string(idCompraDetalle) + "; ";
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
			string selectSQL = "Select * from tareasql.compras_detalle WHERE idCompra_detalle = " + to_string(idCompraDetalle) + "; ";
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