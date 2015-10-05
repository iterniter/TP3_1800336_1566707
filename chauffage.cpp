//
//  chauffage.cpp
//  inf1010_tp1
//
//  Created by Benjamin De Leener on 2015-08-26.
//	Modified by Dominique Beaini on 2015-09-20
//

#include "chauffage.h"
#include <iostream>

using namespace std;



//__________________________________________________________________________________________________________________________
// TP2
//__________________________________________________________________________________________________________________________

/****************************************************************************
* Fonction:	chauffage::operator++
* Description: Surcharge de l operateur++. change la valeur du chauffage true si allume false si etient
* Parametres:	- ()
* Retour:		- un objet meme de la class chauffage par son adresse apres sa modification
****************************************************************************/
bool Chauffage::operator++()
{
	if (!estAllume_)
	{
		allumer();
		return true;
	}
	return false;
}

/****************************************************************************
* Fonction:	chauffage::operator--
* Description: surcharge-- , change la valeur du chauffage true si allume false si etient
* Parametres:	- ()
* Retour:		- un objet meme de la class chauffage par son adresse apres sa modification
****************************************************************************/
bool Chauffage::operator--()
{
	if (estAllume_)
	{
		eteindre();
		return false;
	}
	return true;
}



//__________________________________________________________________________________________________________________________
// TP1
//__________________________________________________________________________________________________________________________

Chauffage::Chauffage(): estAllume_(false)
{
}


Chauffage::~Chauffage()
{
}


void Chauffage::allumer()
{
    estAllume_ = true;
    cout << "Le chauffage est allume." << endl;
}


void Chauffage::eteindre()
{
    estAllume_ = false;
    cout << "Le chauffage est eteint." << endl;
}

