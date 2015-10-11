#include "Routeur.h"
#include <iostream>
#include  <vector>

using namespace std;

//Constructeur par defaut >> Cf exemple du cours en ligne "Manager.cpp"
Routeur::Routeur() : Chauffage(), Cellulaire(), maisonConnectee_(nullptr)
{
}

Routeur::~Routeur()
{
}

//Rajouter Get et set necessaires

//retire l objet connecte definit par id du vecteur des objets connectes au routeur
void Routeur::retirerConnexion(unsigned int id)
{	
	bool idTrouvee = false;

	if (id == maisonConnectee_->getId())
	{
		delete maisonConnectee_;
		idTrouvee = true;
	}

	if (!idTrouvee)
	{
		for (int i = 0; i < cellulairesConnectes_.size(); i++)
		{
			if (id == cellulairesConnectes_[i]->getId())
			{
				erase(cellulairesConnectes_, i);
				idTrouvee = true;
				break;
			}
		}
	}

	if (!idTrouvee)
	{
		for (int i = 0; i < chauffagesConnectes_.size(); i++)
		{
			if (id == chauffagesConnectes_[i]->getId())
			{
				erase(chauffagesConnectes_, i);
				idTrouvee = true;
				break;
			}
		}
	}

}

void Routeur::erase(vector<Chauffage*>& chauffage, int pos)
{
	unsigned int max = chauffage.size() - 1;
	for (int i = pos; i < max; i++)
	{
		chauffage[i] = chauffage[i + 1];
	}
	chauffage.pop_back();
}

void Routeur::erase(vector<Cellulaire*>& cellulaire, int pos)
{
	unsigned int max = cellulaire.size() - 1;
	for (int i = pos; i < max; i++)
	{
		cellulaire[i] = cellulaire[i + 1];
	}
	cellulaire.pop_back();
}

//Recupere un message d un objet source et l envoie a un objet destinataire
void Routeur::acheminerMessage(const Message& message) const
{
	cout << "Acheminement d un message de " << message.getSrc() << " to " << message.getDest() << endl;

	bool idTrouvee = false;

	if (message.getDest() == 0)
	{
		//maisonConnectee_->recevoirMessage(message);
		for (int i = 0; i < cellulairesConnectes_.size(); i++)
			cellulairesConnectes_[i]->recevoirMessage(message);
		for (int i = 0; i < chauffagesConnectes_.size(); i++)
			chauffagesConnectes_[i]->recevoirMessage(message);
		idTrouvee = true;
	}

	/*
	if (!idTrouvee)
	{
		if (message.getDest() == maisonConnectee_->getId())
		{
			maisonConnectee_->recevoirMessage(message);
			idTrouvee = true;
		}
	}*/

	if (!idTrouvee)
	{
		for (int i = 0; i < cellulairesConnectes_.size(); i++)
		{
			if (message.getDest() == cellulairesConnectes_[i]->getId())
			{
				cellulairesConnectes_[i]->recevoirMessage(message);
				idTrouvee = true;
				break;
			}
		}
	}

	if (!idTrouvee)
	{
		for (int i = 0; i < chauffagesConnectes_.size(); i++)
		{
			if (message.getDest() == chauffagesConnectes_[i]->getId())
			{
				chauffagesConnectes_[i]->recevoirMessage(message);
				idTrouvee = true;
				break;
			}
		}
	}

	if (!idTrouvee)
	{
		cout << "Id non trouvee, rien ne se passe !" << endl;
	}

}

void Routeur::accepterConnexion(Cellulaire* cell)
{
	cellulairesConnectes_.push_back(cell);
}

void Routeur::accepterConnexion(Maison* maison)
{
	// ????? Attention j'ai mis un delete dans retierConnexion.. à voir
}

void Routeur::accepterConnexion(Chauffage* chauffage)
{
	chauffagesConnectes_.push_back(chauffage);
}

unsigned int Routeur::getNbChauffagesConnectes() const
{
	return chauffagesConnectes_.size();
}

Chauffage* Routeur::getChauffageConnecte(unsigned int pos) const
{
	if (pos >= 0 && pos < chauffagesConnectes_.size()) {
		return chauffagesConnectes_[pos];
	}

	return nullptr;
}

unsigned int Routeur::getNbCellulairesConnectes() const
{
	return cellulairesConnectes_.size();
}

Cellulaire* Routeur::getCellulaireConnecte(unsigned int pos) const
{
	if (pos >= 0 && pos < cellulairesConnectes_.size()) {
		return cellulairesConnectes_[pos];
	}

	return nullptr;
}
