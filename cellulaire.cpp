//
//  cellulaire.cpp
//  inf1010_tp1
//
//  Created by Benjamin De Leener on 2015-08-26.
//	Modified by Dominique Beaini on 2015-09-20
//

#include <stdio.h>
#include "cellulaire.h"
#include "gps.h"

using namespace std;

//TP3
Cellulaire::Cellulaire(unsigned int id, string numeroDeCell) :numero_(numeroDeCell)
{
	ObjetConnecte::setId(id);

}

//__________________________________________________________________________________________________________________________
// TP2
//__________________________________________________________________________________________________________________________

/****************************************************************************
* Fonction:	Cellulaire::operator==
* Description: Surcharge operateur
* Parametres:	- (const Cellulaire&) cellulaire2
* Retour:		- (booleen) indiquant si le cellulaire courant est "==" à celui passé en parametre
****************************************************************************/
bool Cellulaire::operator==(const Cellulaire& cellulaire2)
{
	if (this->getProprietaire()->getNumeroCellulaire() == cellulaire2.numero_)
		if (this->getProprietaire()->getNom() == cellulaire2.getProprietaire()->getNom())
			if (this->getProprietaire()->getPrenom() == cellulaire2.getProprietaire()->getPrenom())
				return true;
	return false;

}

/****************************************************************************
* Fonction:	Cellulaire::operator<
* Description: Surcharge operateur
* Parametres:	- (const Cellulaire&) cellulaire2
* Retour:		- (booleen) indiquant si le cellulaire courant est "<" à celui passé en parametre
****************************************************************************/
bool Cellulaire::operator<(const Cellulaire& cellulaire2)
{ 
	string chaine1 = (*this).numero_;
	string chaine2 = cellulaire2.getNumero();

		if(chaine1.compare(chaine2)==0)
		return true;
	return false;

}


/****************************************************************************
* Fonction:	Cellulaire::operator=
* Description: Operateur d affectation
* Parametres:	- (const Cellulaire&) cellulaire2
* Retour:		- (Cellulaire&) reference au cellulaire courant
****************************************************************************/
Cellulaire& Cellulaire::operator=(const Cellulaire& cellulaire2)
{
	this->setNumero(cellulaire2.numero_);
	this->setPosition(cellulaire2.getPosition());
	this->setProprietaire(cellulaire2.getProprietaire());
	return *this;
}


/****************************************************************************
* Fonction:	operator<<
* Description: Surcharge operator<<
* Parametres:	- (const Cellulaire*) cellulaire
- (ostream&) os
* Retour:		- (ostream&) reference ostream courant : permet la mise en cascade d operator<<
****************************************************************************/
ostream& operator<<(ostream& os, const Cellulaire *cellulaire)
{
	char tab = '\t';
	os << "#" << cellulaire->getNumero() << tab << cellulaire->getProprietaire()->getNom() << ", " << cellulaire->getProprietaire()->getPrenom() << endl;
	return os;
}


/****************************************************************************
* Fonction:	Cellulaire::Cellulaire
* Description: Constructeur par copie
* Parametres:	- (const Cellulaire&) cellulaire
* Retour:		aucun
****************************************************************************/
Cellulaire::Cellulaire(const Cellulaire& cellulaire):numero_(cellulaire.numero_), gps_(cellulaire.gps_), proprietaire_(nullptr)
{
	proprietaire_ = new Personne(cellulaire.proprietaire_->getPrenom(), cellulaire.proprietaire_->getNom(), cellulaire.proprietaire_->getAge());
}



//__________________________________________________________________________________________________________________________
// TP1
//__________________________________________________________________________________________________________________________


Cellulaire::Cellulaire(): numero_("000-000-0000")
{
}


Cellulaire::Cellulaire(string numero)
: numero_(numero)
{
}


Cellulaire::~Cellulaire()
{
}


bool Cellulaire::estProche(float position)
{
    return gps_.estProche(position);
}


string Cellulaire::getNumero() const
{
    return numero_;
}


void Cellulaire::setNumero(string numero)
{
    numero_ = numero;
}


float Cellulaire::getPosition() const
{
    return gps_.getPosition();
}


void Cellulaire::setPosition(float position)
{
    gps_.setPosition(position);
}


Personne* Cellulaire::getProprietaire() const
{
    return proprietaire_;
}


void Cellulaire::setProprietaire(Personne* personne)
{
    proprietaire_ = personne;
}


