// Examen.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// 
#include <mysql.h>
#include <iostream>
#include <string> 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "conexionBD.h"

using namespace std;

class Productos {
private:
	    int idProducto, idMarca, existencia;
		string producto, descripcion, imagen, fechaingreso;
		double precio_costo, precio_venta;
public:
	Productos() {}

	Productos(int idproductoc, int idMarcac, int existenciac, string productoc, string descripcionc, string imagenc, string fechaingresoc, double precio_costoc, double precio_ventac ) {
		idProducto = idproductoc;
		idMarca = idMarcac;
		existencia = existenciac;
		producto = productoc;
		descripcion = descripcionc;
		imagen = imagenc;
		fechaingreso = fechaingresoc;
		precio_costo = precio_costoc;
		precio_venta = precio_ventac;
	}

	Productos(int idMarcac, int existenciac, string productoc, string descripcionc, string imagenc, string fechaingresoc, double precio_costoc, double precio_ventac) {
		idMarca = idMarcac;
		existencia = existenciac;
		producto = productoc;
		descripcion = descripcionc;
		imagen = imagenc;
		fechaingreso = fechaingresoc;
		precio_costo = precio_costoc;
		precio_venta = precio_ventac;
	}

	Productos(int idproductoc) {
		idProducto = idproductoc;
	}


	void SetidProducto(int idProductoc) { idProducto = idProductoc; }
	void SetidMarca(int idMarcac) { idMarca = idMarcac; }
	void Setexistencia(int existenciac) { existenciac = existenciac; }
	void Setproducto(string productoc) { producto = productoc; }
	void Setdescripcion(string descripcionc) { descripcion = descripcionc; }
	void Setimagen(string imagenc) { imagen = imagenc; }
	void Setfechaingreso(string fechaingresoc) { fechaingreso = fechaingresoc; }
	void Setprecio_costo(double precio_costoc) { precio_costo = precio_costoc; }
	void Setprecio_venta(double precio_ventac) { precio_venta = precio_ventac; }

	const int GetidProducto(){ return idProducto; }
	const int GetidMarca() { return idMarca; }
	const int Getexistencia() { return existencia; }
	const string Getproducto() { return producto; }
	const string Getdescripcion() { return descripcion; }
	const string Getimagen() { return imagen; }
	const string Getfechaingreso() { return fechaingreso; }
	const double Getprecio_costo() { return precio_costo; }
	const double Getprecio_venta() { return precio_venta; }



	//CRUD

	void createData() {
		int q_estado;
		conexionBD cn = conexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insert = "INSERT INTO `tareasql`.`productos`(`producto`,`idMarca`,`descripcion`,`imagen`,`precio_costo`,`precio_venta`,`existencia`,`fecha_ingreso`)VALUES('" + producto + "','" + to_string(idMarca) + "','" + descripcion + "','" + imagen + "','" + to_string(precio_costo) + "','" + to_string(precio_venta) + "','" + to_string(existencia) + "','" + fechaingreso + "')";
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
			string update = "update tareasql.productos  SET producto = '" + producto + "', idMarca = '" + to_string(idMarca) + "', descripcion = '" + descripcion + "', imagen = '" + imagen + "',precio_costo = '" + to_string(precio_costo) + "', precio_venta = '" + to_string(precio_venta) + "', existencia = '" + to_string(existencia) + "', fecha_ingreso = '" + fechaingreso + "'  where idProducto = " + to_string(idProducto) + "  ";
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
			string deleteSQL = "DELETE FROM tareasql.productos WHERE idProducto = " + to_string(idProducto) + "; ";
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
			string selectSQL = "Select * from tareasql.productos WHERE idProducto = " + to_string(idProducto) + "; ";
			const char* i = selectSQL.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << fila[2] << "," << fila[3] << fila[4] << "," << fila[5] << fila[6] << "," << fila[7]<< endl;
				}
			}
			else {
				cout << "Error al ingresar";
			}
		}
		cn.cerrar_conexion();
	}
};