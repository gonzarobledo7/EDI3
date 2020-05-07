#include <iostream>
#include <string>
class Coche
{

private:
	string marca;


public:
		
	Coche(string marca){
		this.marca = marca;

	}
	string getMarcaCoche(){
		return marca;
	}
	
};

class CocheDataBase
{
public:
	void guardarCoche(Coche coche){
		cin >> coche;
	}

	void eliminaCoche (Coche coche){
		delete coche;

	}
};