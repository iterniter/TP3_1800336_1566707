#include <ctime>
#include <cstdio>
#include <iostream>
#include "Maison.h"
#include "Routeur.h"

#ifdef _WIN32
#   include <Windows.h>
#   define PAUSE(x) Sleep(x * 1000)
#else
#   include <unistd.h>
#   define PAUSE(x) sleep(x)
#endif

using namespace std;

Maison::Maison(unsigned int id, const std::string& adresse, float position) : ObjetConnecte(id)
{
	id_ = id;
	adresse_ = adresse;
	position_ = position;
}

void Maison::ajouterCellulaire(Cellulaire* cellulaire)
{
	cellulairesEnregistres_.push_back(cellulaire);
}


void Maison::ajouterOccupant(Personne* personne)
{
	occupants_.push_back(personne);
}


bool Maison::estOccupant(const Personne* personne) const
{
	bool estOccupant = false;
	for (size_t j = 0; j<occupants_.size(); j++)
	{
		if (occupants_[j] == personne)
		{
			estOccupant = true;
			break;
		}
	}
	return estOccupant;
}


bool Maison::estVide() const
{
	bool estVide = true;
	for (size_t j = 0; j<occupants_.size(); j++)
	{
		if (occupants_[j]->estALaMaison())
		{
			estVide = false;
			break;
		}
	}
	return estVide;
}


void Maison::observerCellulaires(float temps_observation)
{
	// boucle dans le temps
	// les cellulaires enregistres sont observes en continu.
	time_t start = time(0);
	while (difftime(time(0), start) <= temps_observation)
	{
		// À compléter

		// pause de une seconde. Attention, le comportement de la fonction pause() est different sous Windows et sous Linux/OSX
		PAUSE(1);
	}
}


string Maison::getAdresse() const
{
	return adresse_;
}


void Maison::setAdresse(string adresse)
{
	adresse_ = adresse;
}


float Maison::getPosition() const
{
	return position_;
}


void Maison::setPosition(float position)
{
	position_ = position;
}

// À compléter...