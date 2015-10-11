#ifndef OBJETCONNECTE_H
#define OBJETCONNECTE_H

#include <string>
#include <iostream>

#include "message.h"

using namespace std;

class Routeur;
class ObjetConnecte:
{
public:
	ObjetConnecte(unsigned int id = 1);

	unsigned int getId() const;
	bool getEtatDeLaConnexion() const;

	void setId(unsigned int nouveauId);
	void setEtatDeLaConnexion(bool nouveauEtat);

	void seDeconnecter() const;
	void seConnecter(Routeur* routeur);

	void envoyerMessage(const Message& message);
	void recevoirMessage(const Message& message) const;

	Routeur* getRouteur() const;
	
private:
  unsigned int id_ ;
  bool etatDeLaconnexion_ ;
  Routeur* routeur_ ;
};
#endif