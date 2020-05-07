#include "ICoche.h"
#include "Renault.h"
#include "Audi.h"
#include "Mercedes.h"
#include <iostream>
using namespace std;


int main(){

   Coche[] arrayCoches = {
            new Renault(),
            new Audi(),
            new Mercedes()
    }

    imprimirPrecioMedioCoche(arrayCoches);


void imprimirPrecioMedioCoche(Coche[] arrayCoches){ 
    for (Coche coche : arrayCoches) {
        cout << coche + precioMedioCoche() << endl;
    
}

}

}
