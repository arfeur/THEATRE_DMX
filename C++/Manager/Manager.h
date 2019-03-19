//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Manager.h---------------------------------------------------------//
//---Cette classe permet de generer un objet de type scene ou programme en lien
//--------------avec la BDD--------------------------------------------------//
//---------------------------------------------------------------------------//


#ifndef ManagerH
#define ManagerH
#include"Programme.h"
#include"Scene.h"
//---------------------------------------------------------------------------

class manager
{
	private:
		programme*prog;
		scene*scn;

	public:
		manager();

		programme*getProg(idProg); //compare avec l'id de la bdd
		scene*getScn(idScn);      		//compare avec l'id de la bdd
		scene*updateScene(scene*scn);      	//instancie un nouvel objet scene
		programme*updateProg(programme*prog); 	//instancie un nouvel objet programme
		char*sendOk();
		char*sendError();


};

#endif

