//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Scene.h-----------------------------------------------------------//
//---Cette classe permet de r�pertorier une sc�ne qui poss�de plusieurs s�quences---//
//---------------------------------------------------------------------------//

#pragma hdrstop

#include "Scene.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//constructeur
	scene::scene(int id, char*name, int tpsPause, std::map<std::string,sequence*>seq)
	{
		this->id=id;
		this->name=name;
		this->tpsPause=tpsPause;
		this->seq=seq;
	}
//setID
	void scene::setId(int id)
	{
		this->id=id;
	}
//initialisation du nom
	void scene::setName(char*name)
	{
		this->name=name;
	}
//initialisation du temps de pause
	void scene::setTime(int tpsPause)
	{
		this->tpsPause=tpsPause;
	}
//initialisation du nombre de s�quences d'une sc�ne
	void scene::setNbSeq(std::map<int,sequence*>)
	{
		this->seq=seq;
	}
//r�cup�ration de l'id scene
	int scene::getId()
	{
		return id;
	}
//r�cup�ration du Nom de la sc�ne
	char* scene::getName()
	{
		return name;
	}
//r�cup�ration du temps entre chaque sc�ne
	int scene::getTime()
	{
		return tpsPause;
	}
//r�cup�ration du nombre de s�quences
	int scene::getNbSeq()
	{
		return seq.size();
	}
//initialisation des sequences des sc�nes
	void scene::setSequences(std::map<std::string,sequence*>seq)
	{
		this->seq=seq;
	}
//r�cup�ration des sequences des sc�nes
	std::map<std::string,sequence*> scene::getSequences()
	{
		return seq;
    }
