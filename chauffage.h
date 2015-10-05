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


class Chauffage: public ObjetConnecte
{
public:
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
};

#endif /* defined(__inf1010_tp1__chauffage__) */
