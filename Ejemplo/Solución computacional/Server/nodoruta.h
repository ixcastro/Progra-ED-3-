#ifndef NODORUTA_H
#define NODORUTA_H

class NodoRuta {
public:
    NodoRuta(int pCodRuta,int pCodPais, int pCodCiudad, int pCodPaisDetino, int pCodCiudadDestino, int pPrecio){
        codRuta = pCodRuta;
        codPais = pCodPais;
        codCiudad = pCodCiudad;
        codPaisDest = pCodPaisDetino;
        codCiudadDest = pCodCiudadDestino;
        precio = pPrecio;

        hd = nullptr;
        hi = nullptr;
        padre = nullptr;
        nivel = 1;
    }

private:
    int codRuta;
    int codPais;
    int codCiudad;
    int codPaisDest;
    int codCiudadDest;
    int precio;
    int nivel;
    NodoRuta* hd;
    NodoRuta* hi;
    NodoRuta* padre;

    friend class arbolTrenes;
    friend class ServicioDeTrenes;
};
typedef NodoRuta *pnodoRuta;
#endif // NODORUTA_H
