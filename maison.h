//
//  maison.h
//  inf1010_tp1
//
//  Created by Benjamin De Leener on 2015-08-26.
//  Modified by Dominique Beaini on 2015-09-18.
//  Modified by Karim Keddam on 2015-09-26.
//

#ifndef MAISON_H
#define MAISON_H

#include <vector>
#include <string>
#include "personne.h"
#include "objetConnecte.h"
#include "cellulaire.h"
#include "Routeur.h"
#include "chauffage.h"

using namespace std;

class Maison : public ObjetConnecte
{
public:
	// TP3

	// Constructeur
	Maison(unsigned int id, const string& adresse, float position);

	void seConnecter(Routeur* routeur);

	// À compléter...

	// Méthodes TP1 et TP2:
	~Maison();

	void ajouterCellulaire(Cellulaire* cellulaire);
	void ajouterOccupant(Personne* personne);

	// cette fonction permet de savoir si une personne, passee en parametre, fait partie des occupants de la maison.
	bool estOccupant(Personne* personne);

	// cette fonction permet de savoir si la maison est vide, c'est-à-dire si aucun occupant n'est present dans la maison.
	bool estVide() const;

	// la fonction observeCellulaire() analyse en boucle la liste des cellulaires enregistres pour voir s'ils sont proches. Si un cellulaire est proche, la maison regarde a qui il appartient, vérifie si cette personne est occupante.
	// Si la personne est occupante, la maison active le chauffage et desactive le systeme de securite. Sinon, rien ne s'active et un message apparait, indiquant aux occupants qu'un ami est arrive.
	// Les cellulaires sont observes pour un temps determine. Defaut = 60 secondes.
	void observerCellulaires(float temps_observation = 60.0);

	// accesseurs et modificateurs
	string getAdresse() const;
	void setAdresse(string adresse);

	float getPosition() const;
	void setPosition(float position);

private:
	// TP1 et TP2
	string adresse_;
	vector<Personne*> occupants_;
	vector<Cellulaire*> cellulairesObserves_;
	vector<Chauffage*> listDeChauffage_;

	float positionDeLaMaison_;
};

#endif