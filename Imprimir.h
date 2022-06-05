// Examen.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// 
#include <mysql.h>
#include <iostream>
#include <string> 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "conexionBD.h"

using namespace std;

class Imprimir {
private:

	int idEmpleado;

public:
	Imprimir() {}

	Imprimir(int idEmpleadoc) {
		idEmpleado = idEmpleadoc;
	}


	void SetidEmpleado(int idEmpleadoc) { idEmpleado = idEmpleadoc; }
	const int GetidEmpleado() { return idEmpleado; }

	//CRUD

	void imprimirData() {
		int q_estado;
		conexionBD cn = conexionBD();
		MYSQL_ROW fila, fili;
		MYSQL_RES* resultado;
		MYSQL_RES* resultado1;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string selectSQL = "Select noFactura, serie, nit, fechaFactura, CONCAT(c.nombres, CONCAT('',c.apellidos)) as nombre from ventas inner join clientes c on c.idcliente = ventas.idcliente where ventas.idVenta = " + to_string(idEmpleado) + "; ";
			//cout << selectSQL;
			const char* i = selectSQL.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			int count = 0;
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << endl;
					cout << "___________________________________________________________" << endl;
					cout << "|No Factura: | "<< fila[0] <<"	Fecha: "<< fila[3] <<"                 |" << endl;
					cout << "|Nit:        | " << fila[2] << "                                   |" << endl;
					cout << "|Cliente:    | " << fila[4] << "                                |" << endl;
					cout << "|Direccion:  | Ciudad                                     |" << endl;
					cout << "___________________________________________________________" << endl;
					
					string selectSQL1 = "select productos.idProducto,productos.precio_venta, productos.descripcion from venta_detalle inner join productos on productos.idProducto = venta_detalle.idProducto where venta_detalle.idVenta = " + to_string(idEmpleado) + "; ";
					//cout << selectSQL1;
					const char* j = selectSQL1.c_str();
					q_estado = mysql_query(cn.getConectar(), j);
					if (!q_estado) {
						resultado1 = mysql_store_result(cn.getConectar());
						while (fili = mysql_fetch_row(resultado1)) {
							count = count + stoi(fili[1]);
							cout << fili[0]<<"-" << fili[2] << "      " << fili[1]<<endl;
							cout << "___________________________________________________________" << endl;
						}
						cout << "Total Q." << count <<endl;
						cout << "Gracias por su compra";
					}
				
				}

			}
			else {
				cout << "Error al ingresar";
			}
		}
		cn.cerrar_conexion();
	}
};