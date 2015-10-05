#ifndef OBJETCONNECTE_H
#define OBJETCONNECTE_H


class ObjetConnecte: public Routeur
{
public:
	// A compléter
	ObjetConnecte(unsigned int id = 1);
	unsigned int getId() const;
	bool getEtatDeLaConnexion() const;

	void setId(unsigned int nouveauId);
	void setEtatDeLaConnexion(bool nouveauEtat);

	virtual void seConnecter(Routeur*);
	void seDeconnecter() const;

	void envoyerMessage(const string Message) const;
	string recevoirMessage(const string Message) const;

protected:
	
private:
  unsigned int id_ ;
  bool etatDeLaconnexion_ ;
  Routeur routeur_ ;
};
#endif