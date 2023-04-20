#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;
#include "amazon.h"

int main() {
  cout << "Hello World!\n";
  Producto dvd = Producto("Batman Begins", 100, 3000);
  cout << dvd << endl;

  ShoppingCar carrito = ShoppingCar();
  cout << carrito << endl;
  carrito.agregarProducto(dvd);
  carrito.agregarProducto(Producto("The Flash"));
 cout << carrito << endl;

 Inventario inventario = Inventario();
 //cout << inventario;

 string pregunta;
 cout << "Qué buscas? "<< endl;
 getline(cin, pregunta);
 vector<Producto> salida = inventario.consultaPorPalabra(pregunta);

 for(int i= 0;  i< salida.size(); i++){
     cout << salida[i] << endl;
 }




}