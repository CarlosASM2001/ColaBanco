#ifndef PERSONA_H
#define PERSONA_H

class Persona
{
	int clave;

public:

	Persona();
	Persona(int clave) {
		this->clave = clave;
	}



	int getClave() { return clave; }





};




#endif // !PERSONA_H