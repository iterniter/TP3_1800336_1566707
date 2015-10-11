#ifndef ROUTEUR_H
#define ROUTEUR_H

#include  <vector>
#include <iostream>
#include <stdio.h>

#include "chauffage.h"
#include "maison.h"
#include "cellulaire.h"
#include "message.h"
#include "ObjetConnecte.h"

class Routeur
{
public:
	//Constructeur par defaut
	Routeur();
	//Destructeur
	~Routeur();

	//Rajouter Get et set necessaires

	//retire l objet connecte definit par id du vecteur des objets connectes au routeur
	void retirerConnexion(unsigned int id);

	//Recupere un message d un objet source et l envoie a un objet destinataire
	void acheminerMessage(const Message& message) const;

	//Ajoute le pointeur passe en parametre aux attributs de la classe
	void accepterConnexion(Cellulaire* cell);
	void accepterConnexion(Maison* maison);
	void accepterConnexion(Chauffage* chauffage);

	unsigned int getNbChauffagesConnectes() const;
	Chauffage* getChauffageConnecte(unsigned int pos) const;
	unsigned int getNbCellulairesConnectes() const;
	Cellulaire* getCellulaireConnecte(unsigned int pos) const;

private:
	vector<Chauffage*> chauffagesConnectes_;
	vector<Cellulaire*> cellulairesConnectes_;
	Maison* maisonConnectee_;

	void erase(vector<Chauffage*>& chauffage, int pos);
	void erase(vector<Cellulaire*>& cellulaire, int pos);
};
#endif

