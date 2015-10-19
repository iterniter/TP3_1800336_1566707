#include <ctime>
#include <cstdio>
#include <iostream>
#include "maison.h"

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
	positionDeLaMaison_ = position;
}

void Maison::ajouterCellulaire(Cellulaire* cellulaire)
{
	cellulairesObserves_.push_back(cellulaire);
}


void Maison::ajouterOccupant(Personne* personne)
{
	occupants_.push_back(personne);
}


bool Maison::estOccupant(Personne* personne)
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
	/*bool estVide = true;
	for (size_t j = 0; j<occupants_.size(); j++)
	{
		if (occupants_[j]->estALaMaison())
		{
			estVide = false;
			break;
		}
	}
	return estVide;*/

	return(!occupants_.size());
}


void Maison::observerCellulaires(float temps_observation)
{
	// boucle dans le temps
	// les cellulaires enregistres sont observes en continu.
	time_t start = time(0);
	while (difftime(time(0), start) <= temps_observation)
	{

		// Observation de tous les cellulaires, detection de proximite et ouverture du systeme de la maison si besoin.
		for (size_t i = 0; i < cellulairesObserves_.size(); i++)
		{
			if (cellulairesObserves_[i]->estProche(positionDeLaMaison_))
			{
				cellulairesObserves_[i]->getProprietaire()->setEstALaMaison(true);
				cout << "Bienvenue " << cellulairesObserves_[i]->getProprietaire()->getPrenom() << " !" << endl;

				if (estOccupant(cellulairesObserves_[i]->getProprietaire()))
				{
					cellulairesObserves_[i]->seConnecter(this->getRouteur());

					for (size_t j = 0; j < listDeChauffage_.size(); j++)
					{
						this->envoyerMessage(Message(this->getId(), this->listDeChauffage_[j]->getId(), ALLUMAGE_AUTOMATIQUE));
						this->listDeChauffage_[j]->setEtat(1);
					}
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

					if (unOccupantALaMaison)
						cellulairesObserves_[i]->seConnecter(this->getRouteur());

					for (unsigned int j = 0; j < cellulairesObserves_.size(); j++)
						this->envoyerMessage(Message(this->getId(), this->getRouteur()->getCellulaireConnecte(j)->getId(), NOTIFICATION_VISITEUR));

				}
			}

			if (!cellulairesObserves_[i]->estProche(positionDeLaMaison_))
			{
				cellulairesObserves_[i]->getProprietaire()->setEstALaMaison(false);
				cout << "Au revoir " << cellulairesObserves_[i]->getProprietaire()->getPrenom() << " !" << endl;
				cellulairesObserves_[i]->seDeconnecter();

					if (estVide())
					{
						for (unsigned int j = 0; j < listDeChauffage_.size(); j++)
							this->envoyerMessage(Message(this->getId(), this->listDeChauffage_[j]->getId(), ETTEINDRE_CHAUFFAGE));
							this->listDeChauffage_[i]->setEtat(0);
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
	return positionDeLaMaison_;
}


void Maison::setPosition(float position)
{
	positionDeLaMaison_ = position;
}

void Maison::seConnecter(Routeur* routeur)
{
	routeur->accepterConnexion(this);
}

Maison::~Maison()
{
	// A faire
}