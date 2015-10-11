/*
Fichier: message.cpp
Auteur(s): Khalil et Charley
Date de creation: 05 octobre 2015
Date de modification: 05 octobre 2015
Description: Cette classe represente un message permettant de communiquer entre deux objets de type ObjetConnecte.
*/

#include "objetConnecte.h"
#include "Routeur.h"

using namespace std;

ObjetConnecte::ObjetConnecte(unsigned int id) : id_(id), routeur_(nullptr), etatDeLaconnexion_(false)
{
}

unsigned int ObjetConnecte::getId() const
{
	return id_;
}


bool ObjetConnecte::getEtatDeLaConnexion() const
{
	return etatDeLaconnexion_;
}

void ObjetConnecte::setId(unsigned int nouveauId)
{
	id_ = nouveauId;
}

void ObjetConnecte::setEtatDeLaConnexion(bool nouveauEtat)
{
	etatDeLaconnexion_ = nouveauEtat;
}

void ObjetConnecte::seConnecter(Routeur* routeur)
{
	//Ne contient rien, sera redefinie dans les classes filles
}
void ObjetConnecte::seDeconnecter() const
{
	routeur_->retirerConnexion(id_);
}

void ObjetConnecte::envoyerMessage(const Message& message)
{
	routeur_->acheminerMessage(message);
}

void ObjetConnecte::recevoirMessage(const Message& message) const
{
	//Ne contient rien, sera redefinie dans les classes filles
}

Routeur* ObjetConnecte::getRouteur() const
{
	return routeur_;
}




