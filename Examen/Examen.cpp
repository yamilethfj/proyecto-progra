#include <mysql.h>
#include <iostream>
#include <string> 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "../Compra.cpp";
#include "../Puesto.cpp";
#include "../Clientes.cpp";
#include "../Empleados.cpp";
#include "../Ventas.cpp";
#include "../VentasDetalle.cpp";
#include "../Marca.h";
#include "../productos.h";
#include "../ComprasDetalle.h";
#include "../Proveedores.h";
#include "../Imprimir.h";


using namespace std;


void compras() {
	int idcompra, no_orden_compra, idproveedor, opcion;
	string fecha_orden, fecha_ingreso;

	int idcompra_temp = 0, no_orden_compra_temp = 0, idproveedor_temp = 0;
	char fecha_orden_temp[20], fecha_ingreso_temp[20];

	cout << "MENU" << endl;
	cout << "1. Insertar" << endl;
	cout << "2. Actualizar" << endl;
	cout << "3. Eliminar" << endl;
	cout << "4. Listado" << endl;
	cin >> opcion;

	switch (opcion) {
	case 1: {
		system("cls");
		int idcompra_temp = 0, no_orden_compra_temp = 0, idproveedor_temp = 0;
		char fecha_orden_temp[20], fecha_ingreso_temp[20];

		cout << "Ingrese numero de compra:";
		cin >> no_orden_compra_temp;

		cout << "Ingrese Id Proveedor:";
		cin >> idproveedor_temp;

		cout << "Ingrese fecha ingreso :";
		cin >> fecha_ingreso_temp;

		cout << "Ingrese fecha Orden :";
		cin >> fecha_orden_temp;

		Compras compra = Compras(no_orden_compra_temp, idproveedor_temp, fecha_ingreso_temp, fecha_orden_temp);
		compra.createData();

		system("pause");
		break;
	}
	case 2: {
		system("cls");
		int idcompra_temp = 0, no_orden_compra_temp = 0, idproveedor_temp = 0;
		char fecha_orden_temp[20], fecha_ingreso_temp[20];

		system("cls");
		cout << "Ingrese Id compra:";
		cin >> idcompra_temp;

		cout << "Ingrese numero de compra:";
		cin >> no_orden_compra_temp;

		cout << "Ingrese Id Proveedor:";
		cin >> idproveedor_temp;

		cout << "Ingrese fecha ingreso :";
		cin >> fecha_ingreso_temp;

		cout << "Ingrese fecha Orden :";
		cin >> fecha_orden_temp;

		Compras compra = Compras(idcompra_temp, no_orden_compra_temp, idproveedor_temp, fecha_ingreso_temp, fecha_orden_temp);
		compra.updateData();

		system("pause");
		break;
	}
	case 3: {
		system("cls");
		int idcompra = 0;

		cout << "Ingrese Id compra: ";
		cin >> idcompra;

		Compras compra = Compras(idcompra);
		compra.deleteData();

		system("pause");
		break;
	}
	case 4: {
		system("cls");
		cout << "Ingrese Id compra: ";
		cin >> idcompra;

		Compras compra = Compras(idcompra);
		compra.selectData();

		system("pause");
		break;
	}
	}
}

void puestos() {
	int idpuesto, opcion;
	string puesto;

	int idcompra_temp = 0, no_orden_compra_temp = 0, idproveedor_temp = 0;
	string fecha_orden_temp, fecha_ingreso_temp;

	cout << "MENU" << endl;
	cout << "1. Insertar" << endl;
	cout << "2. Actualizar" << endl;
	cout << "3. Eliminar" << endl;
	cout << "4. Listado" << endl;
	cin >> opcion;

	switch (opcion) {
	case 1: {
		system("cls");
		string puesto_temp;

		cout << "Ingrese puesto:";
		cin >> puesto_temp;

		Puestos puesto = Puestos(puesto_temp);
		puesto.createData();

		system("pause");
		break;
	}
	case 2: {
		system("cls");
		int idpuesto_temp = 0;
		string puesto_temp;

		system("cls");
		cout << "Ingrese Id compra:";
		cin >> idpuesto_temp;

		cout << "Ingrese numero de compra:";
		cin >> puesto_temp;

		Puestos puesto = Puestos(idpuesto_temp, puesto_temp);
		puesto.updateData();

		system("pause");
		break;
	}
	case 3: {
		system("cls");
		int idpuesto = 0;

		cout << "Ingrese Id puesto: ";
		cin >> idpuesto;

		Puestos puesto = Puestos(idpuesto);
		puesto.deleteData();

		system("pause");
		break;
	}
	case 4: {
		system("cls");
		cout << "Ingrese Id puesto: ";
		cin >> idpuesto;

		Puestos puesto = Puestos(idpuesto);
		puesto.selectData();

		system("pause");
		break;
	}
	}
}

void clientes() {
	int opcion;

	cout << "MENU" << endl;
	cout << "1. Insertar" << endl;
	cout << "2. Actualizar" << endl;
	cout << "3. Eliminar" << endl;
	cout << "4. Listado" << endl;
	cin >> opcion;

	switch (opcion) {
	case 1: {
		system("cls");
		int genero;
		int telefono;

		string nombre;
		string apellido;
		string nit;
		string correo;
		string fecha;

		cout << "Ingrese Nombre:";
		cin >> nombre;

		cout << "Ingrese Apellido:";
		cin >> apellido;

		cout << "Ingrese NIT :";
		cin >> nit;
		
		cout << "Ingrese Correo :";
		cin >> correo;

		cout << "Ingrese Telefono :";
		cin >> telefono;

		cout << "Ingrese genero(1/0) :";
		cin >> genero;

		cout << "Ingrese fecha";
		cin >> fecha;

		Clientes compra = Clientes(nombre,apellido, nit,genero,telefono, correo, fecha);
		compra.createData();

		system("pause");
		break;
	}
	case 2: {
		system("cls");
		int idCliente;
		int genero;
		int telefono;

		string nombre;
		string apellido;
		string nit;
		string correo;
		string fecha;

		cout << "Ingrese idCliente:";
		cin >> idCliente;

		cout << "Ingrese Nombre:";
		cin >> nombre;

		cout << "Ingrese Apellido:";
		cin >> apellido;

		cout << "Ingrese NIT :";
		cin >> nit;

		cout << "Ingrese Correo :";
		cin >> correo;

		cout << "Ingrese Telefono :";
		cin >> telefono;

		cout << "Ingrese genero(1/0) :";
		cin >> genero;

		cout << "Ingrese fecha";
		cin >> fecha;

		Clientes compra = Clientes(idCliente,nombre, apellido, nit, genero, telefono, correo, fecha);
		compra.updateData();

		system("pause");
		break;
	}
	case 3: {
		system("cls");
		int idCliente ;

		cout << "Ingrese idCliente: ";
		cin >> idCliente;

		Clientes compra = Clientes(idCliente);
		compra.deleteData();

		system("pause");
		break;
	}
	case 4: {
		system("cls");
		int idCliente;
		cout << "Ingrese idCliente: ";
		cin >> idCliente;

		Clientes compra = Clientes(idCliente);
		compra.selectData();

		system("pause");
		break;
	}
	}
}

void empleados() {
	int opcion;

	cout << "MENU" << endl;
	cout << "1. Insertar" << endl;
	cout << "2. Actualizar" << endl;
	cout << "3. Eliminar" << endl;
	cout << "4. Listado" << endl;
	cin >> opcion;

	switch (opcion) {
	case 1: {
		system("cls");
		int telefono, dpi, genero, idPuesto;
		string nombre, apellido, direccion, fehaNacimiento, fechaInicio, fechaIngreso;

		cout << "Ingrese telefono:";
		cin >> telefono;

		cout << "Ingrese dpi :";
		cin >> dpi;

		cout << "Ingrese genero(1/0) :";
		cin >> genero;

		cout << "Ingrese idPuesto :";
		cin >> idPuesto;

		cout << "Ingrese nombre:";
		cin >> nombre;

		cout << "Ingrese apellido:";
		cin >> apellido;

		cout << "Ingrese direccion :";
		cin >> direccion;

		cout << "Ingrese fehaNacimiento :";
		cin >> fehaNacimiento;

		cout << "Ingrese fechaInicio :";
		cin >> fechaInicio;

		cout << "Ingrese fechaIngreso";
		cin >> fechaIngreso;

		Empleados empleado = Empleados(telefono, dpi, genero, idPuesto, nombre, apellido, direccion, fehaNacimiento, fechaInicio, fechaIngreso);
		empleado.createData();

		system("pause");
		break;
	}
	case 2: {
		system("cls");
		int idEmpleado, telefono, dpi, genero, idPuesto;
		string nombre, apellido, direccion, fehaNacimiento, fechaInicio, fechaIngreso;

		cout << "Ingrese idEmpleado:";
		cin >> idEmpleado;

		cout << "Ingrese telefono:";
		cin >> telefono;

		cout << "Ingrese dpi :";
		cin >> dpi;

		cout << "Ingrese genero(1/0) :";
		cin >> genero;

		cout << "Ingrese idPuesto :";
		cin >> idPuesto;

		cout << "Ingrese nombre:";
		cin >> nombre;

		cout << "Ingrese apellido:";
		cin >> apellido;

		cout << "Ingrese direccion :";
		cin >> direccion;

		cout << "Ingrese fehaNacimiento :";
		cin >> fehaNacimiento;

		cout << "Ingrese fechaInicio :";
		cin >> fechaInicio;

		cout << "Ingrese fechaIngreso";
		cin >> fechaIngreso;

		Empleados empleado = Empleados(idEmpleado, telefono, dpi, genero, idPuesto, nombre, apellido, direccion, fehaNacimiento, fechaInicio, fechaIngreso);
		empleado.updateData();

		system("pause");
		break;
	}
	case 3: {
		system("cls");
		int idEmpleado;

		cout << "Ingrese idEmpleado: ";
		cin >> idEmpleado;

		Empleados empleado = Empleados(idEmpleado);
		empleado.deleteData();

		system("pause");
		break;
	}
	case 4: {
		system("cls");
		int idEmpleado;
		cout << "Ingrese idEmpleado: ";
		cin >> idEmpleado;

		Empleados empleado = Empleados(idEmpleado);
		empleado.selectData();

		system("pause");
		break;
	}
	}
}

void ventas() {
	int opcion;

	cout << "MENU" << endl;
	cout << "1. Insertar" << endl;
	cout << "2. Actualizar" << endl;
	cout << "3. Eliminar" << endl;
	cout << "4. Listado" << endl;
	cin >> opcion;

	switch (opcion) {
	case 1: {
		system("cls");
		int nofactura, idcliente, idempleado;
		string serie, fechafactrura, fechaIngreso;


		cout << "Ingrese nofactura:";
		cin >> nofactura;

		cout << "Ingrese idcliente :";
		cin >> idcliente;

		cout << "Ingrese idempleado :";
		cin >> idempleado;

		cout << "Ingrese serie :";
		cin >> serie;

		cout << "Ingrese fechafactrura :";
		cin >> fechafactrura;

		cout << "Ingrese fechaIngreso";
		cin >> fechaIngreso;

		Ventas ventas = Ventas(nofactura,idcliente, idempleado, serie,fechafactrura,fechaIngreso);
		ventas.createData();

		system("pause");
		break;
	}
	case 2: {
		system("cls");
		int idVentas, nofactura, idcliente, idempleado;
		string serie, fechafactrura, fechaIngreso;

		cout << "Ingrese idVentas:";
		cin >> idVentas;

		cout << "Ingrese nofactura:";
		cin >> nofactura;

		cout << "Ingrese idcliente :";
		cin >> idcliente;

		cout << "Ingrese idempleado :";
		cin >> idempleado;

		cout << "Ingrese serie :";
		cin >> serie;

		cout << "Ingrese fechafactrura :";
		cin >> fechafactrura;

		cout << "Ingrese fechaIngreso";
		cin >> fechaIngreso;

		Ventas ventas = Ventas(idVentas, nofactura, idcliente, idempleado, serie, fechafactrura, fechaIngreso);
		ventas.updateData();

		system("pause");
		break;
	}
	case 3: {
		system("cls");
		int idVentas;

		cout << "Ingrese idVentas: ";
		cin >> idVentas;

		Ventas ventas = Ventas(idVentas);
		ventas.deleteData();

		system("pause");
		break;
	}
	case 4: {
		system("cls");
		int idVentas;
		cout << "Ingrese idVentas: ";
		cin >> idVentas;

		Ventas ventas = Ventas(idVentas);
		ventas.selectData();

		system("pause");
		break;
	}
	}
}

void ventasDetalles() {
	int opcion;

	cout << "MENU" << endl;
	cout << "1. Insertar" << endl;
	cout << "2. Actualizar" << endl;
	cout << "3. Eliminar" << endl;
	cout << "4. Listado" << endl;
	cin >> opcion;

	switch (opcion) {
	case 1: {
		system("cls");
		int idVentaDetalle, idVenta, idProducto, precioUnitario, cantidad;

		cout << "Ingrese idVenta :";
		cin >> idVenta;

		cout << "Ingrese idProducto :";
		cin >> idProducto;

		cout << "Ingrese precioUnitario :";
		cin >> precioUnitario;

		cout << "Ingrese cantidad :";
		cin >> cantidad;

		VentasDetalles ventas = VentasDetalles(idVenta, idProducto,precioUnitario, cantidad);
		ventas.createData();

		system("pause");
		break;
	}
	case 2: {
		system("cls");
		
		int idVentaDetalle, idVenta, idProducto, precioUnitario, cantidad;


		cout << "Ingrese idVentaDetalle:";
		cin >> idVentaDetalle;

		cout << "Ingrese idVenta :";
		cin >> idVenta;

		cout << "Ingrese idProducto :";
		cin >> idProducto;

		cout << "Ingrese precioUnitario :";
		cin >> precioUnitario;

		cout << "Ingrese cantidad :";
		cin >> cantidad;

		VentasDetalles ventas = VentasDetalles(idVentaDetalle, idVenta, idProducto, precioUnitario, cantidad);
		ventas.updateData();

		system("pause");
		break;
	}
	case 3: {
		system("cls");
		int idVentaDetalle;

		cout << "Ingrese idVentaDetalle: ";
		cin >> idVentaDetalle;

		VentasDetalles ventas = VentasDetalles(idVentaDetalle);
		ventas.deleteData();

		system("pause");
		break;
	}
	case 4: {
		system("cls");
		int idVentaDetalle;
		cout << "Ingrese idVentaDetalle: ";
		cin >> idVentaDetalle;

		VentasDetalles ventas = VentasDetalles(idVentaDetalle);
		ventas.selectData();

		system("pause");
		break;
	}
	}
}

void marcas() {
	int idpuesto, opcion;
	

	cout << "MENU" << endl;
	cout << "1. Insertar" << endl;
	cout << "2. Actualizar" << endl;
	cout << "3. Eliminar" << endl;
	cout << "4. Listado" << endl;
	cin >> opcion;

	switch (opcion) {
	case 1: {
		system("cls");
		int idMarca;
		string marca;

		cout << "Ingrese puesto:";
		cin >> marca;

		Marca marcass = Marca(marca);
		marcass.createData();

		system("pause");
		break;
	}
	case 2: {
		system("cls");
		int idMarca;
		string marca;

		cout << "Ingrese idMarca:";
		cin >> idMarca;

		cout << "Ingrese puesto:";
		cin >> marca;

		Marca marcass = Marca(idMarca,marca);
		marcass.updateData();

		system("pause");
		break;
	}
	case 3: {
		system("cls");
		int idMarca = 0;

		cout << "Ingrese idMarca: ";
		cin >> idMarca;

		Marca puesto = Marca(idMarca);
		puesto.deleteData();

		system("pause");
		break;
	}
	case 4: {
		system("cls");
		int idMarca = 0;
		cout << "Ingrese idMarca: ";
		cin >> idMarca;

		Marca puesto = Marca(idMarca);
		puesto.selectData();

		system("pause");
		break;
	}
	}
}

void productos() {
	int opcion;

	cout << "MENU" << endl;
	cout << "1. Insertar" << endl;
	cout << "2. Actualizar" << endl;
	cout << "3. Eliminar" << endl;
	cout << "4. Listado" << endl;
	cin >> opcion;

	switch (opcion) {
	case 1: {
		system("cls");
		int idMarca, existencia;
		string producto, descripcion, imagen, fechaingreso;
		double precio_costo, precio_venta;

		cout << "Ingrese idMarca :";
		cin >> idMarca;

		cout << "Ingrese existencia :";
		cin >> existencia;

		cout << "Ingrese producto :";
		cin >> producto;

		cout << "Ingrese descripcion:";
		cin >> descripcion;

		cout << "Ingrese imagen:";
		cin >> imagen;

		cout << "Ingrese fechaingreso :";
		cin >> fechaingreso;

		cout << "Ingrese precio_costo :";
		cin >> precio_costo;

		cout << "Ingrese precio_venta :";
		cin >> precio_venta;


		Productos empleado = Productos(idMarca,existencia, producto,descripcion, imagen, fechaingreso,precio_costo, precio_venta);
		empleado.createData();

		system("pause");
		break;
	}
	case 2: {
		system("cls");
		int idProducto, idMarca, existencia;
		string producto, descripcion, imagen, fechaingreso;
		double precio_costo, precio_venta;

		cout << "Ingrese idProducto:";
		cin >> idProducto;

		cout << "Ingrese idMarca :";
		cin >> idMarca;

		cout << "Ingrese existencia :";
		cin >> existencia;

		cout << "Ingrese producto :";
		cin >> producto;

		cout << "Ingrese descripcion:";
		cin >> descripcion;

		cout << "Ingrese imagen:";
		cin >> imagen;

		cout << "Ingrese fechaingreso :";
		cin >> fechaingreso;

		cout << "Ingrese precio_costo :";
		cin >> precio_costo;

		cout << "Ingrese precio_venta :";
		cin >> precio_venta;


		Productos empleado = Productos(idProducto, idMarca, existencia, producto, descripcion, imagen, fechaingreso, precio_costo, precio_venta);
		empleado.createData();

		system("pause");
		break;
	}
	case 3: {
		system("cls");
		int idProducto;

		cout << "Ingrese idProducto: ";
		cin >> idProducto;

		Productos empleado = Productos(idProducto);
		empleado.deleteData();

		system("pause");
		break;
	}
	case 4: {
		system("cls");
		int idProducto;
		cout << "Ingrese idProducto: ";
		cin >> idProducto;

		Productos empleado = Productos(idProducto);
		empleado.selectData();

		system("pause");
		break;
	}
	}
}

void comprasventasDetalles() {
	int opcion;

	cout << "MENU" << endl;
	cout << "1. Insertar" << endl;
	cout << "2. Actualizar" << endl;
	cout << "3. Eliminar" << endl;
	cout << "4. Listado" << endl;
	cin >> opcion;

	switch (opcion) {
	case 1: {
		system("cls");
		int idCompra, idProducto, cantidad;
		double precioCostoUnitario;
		cout << "Ingrese idCompra :";
		cin >> idCompra;

		cout << "Ingrese idProducto :";
		cin >> idProducto;

		cout << "Ingrese cantidad :";
		cin >> cantidad;
		cout << "Ingrese precioCostoUnitario :";
		cin >> precioCostoUnitario;

		CompraDetalles ventas = CompraDetalles(idCompra,idProducto,cantidad,precioCostoUnitario);
		ventas.createData();

		system("pause");
		break;
	}
	case 2: {
		system("cls");

		int idCompraDetalle, idCompra, idProducto, cantidad;
		double precioCostoUnitario;

		cout << "Ingrese idCompraDetalle :";
		cin >> idCompraDetalle;

		cout << "Ingrese idCompra :";
		cin >> idCompra;

		cout << "Ingrese idProducto :";
		cin >> idProducto;

		cout << "Ingrese cantidad :";
		cin >> cantidad;
		cout << "Ingrese precioCostoUnitario :";
		cin >> precioCostoUnitario;

		CompraDetalles ventas = CompraDetalles(idCompraDetalle, idCompra, idProducto, cantidad, precioCostoUnitario);
		ventas.updateData();

		system("pause");
		break;
	}
	case 3: {
		system("cls");
		int idCompraDetalle;

		cout << "Ingrese idCompraDetalle: ";
		cin >> idCompraDetalle;

		CompraDetalles ventas = CompraDetalles(idCompraDetalle);
		ventas.deleteData();

		system("pause");
		break;
	}
	case 4: {
		system("cls");
		int idCompraDetalle;
		cout << "Ingrese idCompraDetalle: ";
		cin >> idCompraDetalle;

		CompraDetalles ventas = CompraDetalles(idCompraDetalle);
		ventas.selectData();

		system("pause");
		break;
	}
	}
}

void proveedores() {
	int opcion;

	cout << "MENU" << endl;
	cout << "1. Insertar" << endl;
	cout << "2. Actualizar" << endl;
	cout << "3. Eliminar" << endl;
	cout << "4. Listado" << endl;
	cin >> opcion;

	switch (opcion) {
	case 1: {
		system("cls");
		int idProveedores;
		string proveedor, nit, direccion, telefono;

		cout << "Ingrese proveedor :";
		cin >> proveedor;

		cout << "Ingrese nit :";
		cin >> nit;

		cout << "Ingrese direccion :";
		cin >> direccion;

		cout << "Ingrese telefono :";
		cin >> telefono;

		Proveedores ventas = Proveedores(proveedor, nit, direccion, telefono);
		ventas.createData();

		system("pause");
		break;
	}
	case 2: {
		system("cls");

		int idProveedores;
		string proveedor, nit, direccion, telefono;
		cout << "Ingrese idProveedores :";
		cin >> idProveedores;

		cout << "Ingrese proveedor :";
		cin >> proveedor;

		cout << "Ingrese nit :";
		cin >> nit;

		cout << "Ingrese direccion :";
		cin >> direccion;

		cout << "Ingrese telefono :";
		cin >> telefono;

		Proveedores ventas = Proveedores(idProveedores, proveedor, nit, direccion, telefono);
		ventas.updateData();

		system("pause");
		break;
	}
	case 3: {
		system("cls");
		int idProveedores;

		cout << "Ingrese idProveedores: ";
		cin >> idProveedores;

		Proveedores ventas = Proveedores(idProveedores);
		ventas.deleteData();

		system("pause");
		break;
	}
	case 4: {
		system("cls");
		int idProveedores;
		cout << "Ingrese idProveedores: ";
		cin >> idProveedores;

		Proveedores ventas = Proveedores(idProveedores);
		ventas.selectData();

		system("pause");
		break;
	}
	}
}



int main()
{
	int opcion;
	do {
		system("cls");
		cout << "MENU" << endl;
		cout << "1. Compras" << endl;
		cout << "2. Puestos" << endl;
		cout << "3. Clientes" << endl;
		cout << "4. Empleados" << endl;
		cout << "5. Ventas" << endl;
		cout << "6. Ventas Detalles" << endl;
		cout << "7. Marcas" << endl;
		cout << "8. Productos" << endl;
		cout << "9. Compras Detalles" << endl;
		cout << "10. Proveedores" << endl;
		cout << "11. Imprimir factura" << endl;
		cout << "12. Salir" << endl;
		cin >> opcion;

		switch (opcion) {
		case 1: {
			system("cls");
			compras();
		}
		case 2: {
			system("cls");
			puestos();
		}
		case 3: {
			system("cls");
			clientes();
		}
		case 4: {
			system("cls");
			empleados();
		}
		case 5: {
			system("cls");
			ventas();
		}
		case 6: {
			system("cls");
			ventasDetalles();
		}
		case 7: {
			system("cls");
			marcas();
		}
		case 8: {
			system("cls");
			productos();
		}
		case 9: {
			system("cls");
			comprasventasDetalles();
		}
		case 10: {
			system("cls");
			proveedores();
		}
		case 11: {
			system("cls");
			int idventa;
			cout << "Ingrese Id ventta :";
			cin >> idventa;
			Imprimir imp = Imprimir(idventa);
			imp.imprimirData();
		}
		case 12: {
			exit(0);
		}
		}
	} while (opcion > 11);

}
