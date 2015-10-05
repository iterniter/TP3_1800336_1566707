//
//  personne.cpp
//  inf1010_tp2
//
//  Created by Benjamin De Leener on 2015-08-27.
// 	Modified by Dominique Beaini on 2015-09-20
//

#include <cstdio>
#include <string>
#include <iostream>
#include "personne.h"



///__________________________________________________________________________________________________________________________
/// TP2
///__________________________________________________________________________________________________________________________
/****************************************************************************
* Fonction:	Personne::operator==
* Description: Surcharge operateur
* Parametres:	- (const Personne&) personne2
* Retour:		- (booleen) indiquant si la personne courante est "==" à celle passée en parametre
****************************************************************************/
bool Personne::operator==(const Personne& personne2)
{
	return (this->prenom_ == personne2.prenom_ && this->nom_ == personne2.nom_ && this->age_ == personne2.age_);
}


/****************************************************************************
* Fonction:	Personne::operator<
* Description: Surcharge operateur
* Parametres:	- (const Personne&) personne2
* Retour:		- (booleen) indiquant si la personne courante est "<" à celle passée en parametre
****************************************************************************/
bool Personne::operator<(const Personne& personne2)
{
	bool valeurDeRetour = false;
	if ((this->nom_).compare(personne2.nom_) != 0)
	{

		if ((this->nom_).compare(personne2.nom_)>0)
		{
			valeurDeRetour = true;
		}
		else{
			valeurDeRetour = false;
		}

	}
	if ((this->prenom_).compare(personne2.prenom_)>0)
	{

		valeurDeRetour = true;
	}
	else
	{
		valeurDeRetour = false;
	}
	return valeurDeRetour;

}



/****************************************************************************
* Fonction:	operator<<
* Description: Surcharge operator<<
* Parametres:	- (const Personne*) personne
- (ostream&) os
* Retour:		- (ostream&) reference ostream courant : permet la mise en cascade d operator<<
****************************************************************************/
ostream& operator<<(ostream& os, const Personne * personne)
{
	char tab = '\t';
	os << personne->getNom() << " . " << personne->getPrenom() << tab << "-" << tab << personne->getAge() << " ans" << tab << "#" << personne->getNumeroCellulaire() << endl;
	return os;
}

///__________________________________________________________________________________________________________________________
/// TP1
///__________________________________________________________________________________________________________________________
/****************************************************************************
* Fonction:	Personne::Personne
* Description: Constructeur par defaut
* Parametres:	aucun
* Retour:		aucun
****************************************************************************/
Personne::Personne(): age_(0), estALaMaison_(false)
{
}

/****************************************************************************
* Fonction:	Personne::Personne
* Description: Constructeur par parametre
* Parametres:	- (string) prenom : prenom de la Personne
*              - (string) nom : nom de la Personne
*              - (unsigned int) agePersonne : age de la Personne
*              - (string) numeroDuCellulaire : numero cellulaire de la Personne
*              - (bool) aLaMaison : booleen a true quand Personne est dans la maison
* Retour:		aucun
****************************************************************************/
Personne::Personne(string prenom, string nom, unsigned int age)
: nom_(nom), prenom_(prenom), age_(age), estALaMaison_(false)
{
}

/****************************************************************************
* Fonction:	Personne::~Personne
* Description: Destructeur
* Parametres:	aucun
* Retour:		aucun
****************************************************************************/
Personne::~Personne()
{
    
}

/****************************************************************************
* Fonction:	Personne::getNom
* Description: Getter
* Parametres:	aucun
* Retour:		- (string) nom_
****************************************************************************/
string Personne::getNom() const
{
    return nom_;
}

/****************************************************************************
* Fonction:	Personne::setNom
* Description: Setter
* Parametres:	- (string) nom
* Retour:		aucun
****************************************************************************/
void Personne::setNom(string nom)
{
    nom_ = nom;
}

/****************************************************************************
* Fonction:	Personne::getPrenom
* Description: Getter
* Parametres:	aucun
* Retour:		- (string) prenom_
****************************************************************************/
string Personne::getPrenom() const
{
    return prenom_;
}

/****************************************************************************
* Fonction:	Personne::setPrenom
* Description: Setter
* Parametres:	- (string) prenom
* Retour:		aucun
****************************************************************************/
void Personne::setPrenom(string prenom)
{
    prenom_ = prenom;
}


/****************************************************************************
* Fonction:	Personne::getAge
* Description: Getter
* Parametres:	aucun
* Retour:		- (unsigned int) age_
****************************************************************************/
unsigned int Personne::getAge() const
{
    return age_;
}

/****************************************************************************
* Fonction:	Personne::setAge
* Description: Setter
* Parametres:	- (unsigned int) age
* Retour:		aucun
****************************************************************************/
void Personne::setAge(unsigned int age)
{
    age_ = age;
}

/****************************************************************************
* Fonction:	Personne::estALaMaison
* Description: Getter
* Parametres:	aucun
* Retour:		- (bool) estALaMaison_
****************************************************************************/
bool Personne::estALaMaison() const
{
    return estALaMaison_;
}

/****************************************************************************
* Fonction:	Personne::setEstALaMaison
* Description: Setter
* Parametres:	- (bool) estmaison
* Retour:		aucun
****************************************************************************/
void Personne::setEstALaMaison(bool estmaison)
{
    estALaMaison_ = estmaison;
}

/****************************************************************************
* Fonction:	Personne::attribuerCellulaire
* Description: Setter
* Parametres:	- (string) numeroCellulaire
* Retour:		aucun
****************************************************************************/
void Personne::attribuerCellulaire(string numeroCellulaire)
{
    numeroCellulaire_ = numeroCellulaire;
}

/***************************************************************************
* Fonction:	Personne::getNumeroCellulaire
* Description : Getter
* Parametres : aucun
* Retour : -(string)numeroCellulaire_
****************************************************************************/
string Personne::getNumeroCellulaire() const
{
    return numeroCellulaire_;
}

