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

		// Observation de tous les cellulaires, detection de proximite et ouverture du systeme de la maison si besoin.
		for (size_t i = 0; i< cellulairesEnregistres_.size(); i++)
		{
			if (cellulairesEnregistres_[i]->estProche(position_))
			{
				cellulairesEnregistres_[i]->getProprietaire()->setEstALaMaison(true);
				cout << "Bienvenue " << cellulairesEnregistres_[i]->getProprietaire()->getPrenom() << " !" << endl;

				if (estOccupant(cellulairesEnregistres_[i]->getProprietaire()))
				{
					cellulairesEnregistres_[i]->seConnecter(this->ObjetConnecte::getRouteur());

					for (unsigned int j = 0; j < this->ObjetConnecte::getRouteur()->getNbChauffagesConnectes(); j++)
						this->ObjetConnecte::envoyerMessage(Message(this->ObjetConnecte::getId(), this->ObjetConnecte::getRouteur()->getChauffageConnecte(j)->ObjetConnecte::getId(), ALLUMAGE_AUTOMATIQUE));
				}
				else
				{
					bool unOccupantALaMaison = false;
					for (unsigned j = 0; j < occupants_.size(); j++)
					{
						if (occupants_[i]->estALaMaison())
						{
							unOccupantALaMaison = true;
							break;
						}
					}
					if(unOccupantALaMaison)
						cellulairesEnregistres_[i]->seConnecter(this->ObjetConnecte::getRouteur());

					for (unsigned int j = 0; j < this->ObjetConnecte::getRouteur()->getNbCellulairesConnectes(); j++)
						this->ObjetConnecte::envoyerMessage(Message(this->ObjetConnecte::getId(), this->ObjetConnecte::getRouteur()->getCellulaireConnecte(j)->ObjetConnecte::getId(), NOTIFICATION_VISITEUR));
				}
			}

			if (!cellulairesEnregistres_[i]->estProche(position_))
			{
				cellulairesEnregistres_[i]->getProprietaire()->setEstALaMaison(false);
				cout << "Au revoir " << cellulairesEnregistres_[i]->getProprietaire()->getPrenom() << " !" << endl;
				cellulairesEnregistres_[i]->ObjetConnecte::seDeconnecter();

					if (estVide())
					{
						for (unsigned int j = 0; j < this->ObjetConnecte::getRouteur()->getNbChauffagesConnectes(); j++)
							this->ObjetConnecte::envoyerMessage(Message(this->ObjetConnecte::getId(), this->ObjetConnecte::getRouteur()->getChauffageConnecte(j)->ObjetConnecte::getId(), ETTEINDRE_CHAUFFAGE));
					}
			}
		}

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

void Maison::seConnecter(Routeur* routeur)
{
	routeur->accepterConnexion(this);
}

Maison::~Maison()
{
	// A faire
}