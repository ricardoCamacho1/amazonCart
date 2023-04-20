class Producto{
    private:
       string product_name;
       double stars, max_price;
    public:
    /*
    Producto()
    Producto(string)
    Producto(string, double)
    Producto(string, double, double)
    */
      Producto( string product_name = "amazon thing", double stars = 0.0, double max_price = 1.0 ){
          this->product_name = product_name;
          this->stars = stars;
          this->max_price = max_price;
      }

        //constructor copia
      Producto(const Producto & producto){
          this-> product_name = producto.getProductName();
          this->stars = producto.getStars();
          this->max_price = producto.getMaxPrice();

      }

      string getProductName() const{
          return product_name;
      }
      double getStars() const{
          return stars;
      }
      double  getMaxPrice() const{
          return max_price;
      }

/*
int a = 10;
int *aptr = new int(6);
&a // refencia
*/
      friend ostream&  operator<<(ostream & salida, const Producto & producto);
    protected:
    // atributos o métodos para herencia

};
 ostream&  operator<<(ostream & salida, const Producto & producto){
     salida << producto.product_name <<","<< producto.stars<<","<<producto.max_price;
     return salida;
}


class ShoppingCar{
    private:
       vector<Producto> productos;
    public:
        ShoppingCar(){
            productos = vector<Producto>();
        }
        void agregarProducto(Producto producto){
            productos.push_back(producto);
        }
        friend ostream& operator<<(ostream & salida, const ShoppingCar & shopping);
    protected:

};

ostream& operator<<(ostream & salida, const ShoppingCar & shopping){
    if( shopping.productos.empty()  ){
        salida<< "Empty";
    }
    for(int i = 0; i < shopping.productos.size(); i++){
        salida << shopping.productos[i] << endl;
    }
    return salida;

}



class Inventario{
    private:
       vector<Producto> productos;
       void cargaInventario(){
           ifstream archivo("mx-dvd.csv");
          
           string linea;
           getline(archivo, linea);

          string id, time, rank, productName, stars, reviews, author, edition, price, maxPrices;

          while(getline(archivo, linea)){
              istringstream parser(linea);
              getline(parser, id, '|');
              getline(parser, time, '|');
              getline(parser, rank, '|');
              getline(parser, productName, '|');
              getline(parser, stars, '|');
              getline(parser, reviews, '|');
              getline(parser, author, '|');
              getline(parser, edition, '|');
              getline(parser, price, '|');
              getline(parser, maxPrices, '|');
              
              double dstars = strtod(stars.c_str(), NULL);
              double dmaxPrice = strtod(maxPrices.c_str(), NULL);
              Producto temp = Producto(productName, dstars, dmaxPrice);

              productos.push_back(temp);


          }


       }
    public:
        Inventario(){
            productos = vector<Producto>();
            cargaInventario();
        }
        void agregarProducto(Producto producto){
            productos.push_back(producto);
        }
        friend ostream& operator<<(ostream & salida, const Inventario & inventario);



        vector<Producto> consultaPorPalabra(string consulta){
            vector<Producto> salida = vector<Producto>();

            for(int i = 0; i < productos.size(); i++){
                if(productos[i].getProductName().find(consulta) != string::npos ){

                    salida.push_back(productos[i]);

                }
            }

            return salida;
        }
    protected:

};

ostream& operator<<(ostream & salida, const Inventario & inventario){
    if( inventario.productos.empty()  ){
        salida<< "Empty";
    }
    for(int i = 0; i < inventario.productos.size(); i++){
        salida << inventario.productos[i] << endl;
    }
    return salida;

}