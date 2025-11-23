/*
 * Streckenende.cpp
 *
 *  Created on: Nov 12, 2025
 *      Author: cw
 */

#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"

#include <iostream>

Streckenende::Streckenende(Fahrzeug& fahrzeug, Weg& weg): Fahrausnahme(fahrzeug, weg) {
	// TODO Auto-generated constructor stub

}

Streckenende::~Streckenende() {
	// TODO Auto-generated destructor stub
}

void Streckenende::vBearbeiten()
{
	std::cout << "Streckenende: " << p_rFahrzeug.getName()
			<< " (" << p_rWeg.getName() << ") " << std::endl;

	p_rWeg.pAbgabe(p_rFahrzeug);
}
