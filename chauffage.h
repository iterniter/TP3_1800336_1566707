//
//  chauffage.h
//  inf1010_tp1
//
//  Created by Benjamin De Leener on 2015-08-26.
//  Modified by Dominique Beaini on 2015-09-20
//

#ifndef __inf1010_tp1__chauffage__
#define __inf1010_tp1__chauffage__

#include <stdio.h>
#include "objetConnecte.h"
#include "Routeur.h"


class Chauffage: public ObjetConnecte
{
public:

	Chauffage(unsigned int id);

	//Getter du booleen estAllume_
	bool getEtat() const;
	//setter de l attribut etat
	void setEtat(const bool nouveauEtat);
	//Getter du booleen estAutomatique_
	bool getAutomatique() const;
	//setter de l attribut Automatique_
	void setAutomatique(const bool typeChauffage);
	// Khalil: void setEtat(const bool& nouveauEtat);
	// Khalil : void setAutomatique(bool onOff);

	void seConnecter(Routeur* routeur);
	void recevoirMessage(const Message& message); // N'est plus const car on MAJ l'attribut estAutomatique_

	// TP2
	//surcharge de l operateur++
	bool operator++();
	//surcharge de l operateur--
	bool operator--();
	
	// TP1
	Chauffage();
	~Chauffage();

	void allumer();
	void eteindre();

private:
	bool estAllume_;
	bool estAutomatique_;
};

#endif
