/*
 * Weg.h
 *
 *  Created on: Nov 9, 2025
 *      Author: cw
 */

#ifndef WEG_H_
#define WEG_H_

#include <list>
#include <memory>

#include "Simulationsobjekt.h"
#include "Tempolimit.h"
#include "vertagt_liste.h"

class Fahrausnahme;
class Fahrzeug;

class Weg: public Simulationsobjekt
{
public:
	Weg();
	Weg(std::string sName, double dLaenge, Tempolimit eTempolimit = Tempolimit::Autobahn);

	virtual ~Weg();

	// simulates all the vehicles on this road
	void vSimulieren() override;

	// print out the information of the street
	void vAusgeben(std::ostream& out) const override;

	// Prints the table header
	static void vKopf();

	// Assign a fahrzeug as fahrend on this weg
	void vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug);

	// Assign a fahrzeug as parken on this weg
	void vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double dStart);

	// Removes a vehicle from the road (transfer ownership)
	std::unique_ptr<Fahrzeug> pAbgabe(const Fahrzeug& fahrzeug);

	double getLaenge() const;
	double getTempoLimitWeg() const;

private:
	double p_dLaenge; //distance in km
	vertagt::VListe <std::unique_ptr<Fahrzeug>> p_pFahrzeuge; // list of vehicles on this 'weg'
	Tempolimit p_eTempolimit;
};

#endif /* WEG_H_ */
