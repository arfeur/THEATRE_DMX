//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Equipement.h------------------------------------------------------//
//---Cette classe permet d'instancier des equipements comme des lumi�res-----//
//---------------------------------------------------------------------------//

#ifndef EquipementH
#define EquipementH
#include "Property.h"
#include <map>
#include <vector>
#include "String.h"
//---------------------------------------------------------------------------

class equipement
{
	private:
		std::map<std::string,property*>properties;
		char* name;
		int id;

	public:
		equipement(int id, char* name);
		void setId(int id);
		void setName(char* name);

		char*getName();
		bool verifOrder(property*order);
		int getNbVoies();
		std::map<std::string,property*> getProperties();
		int getId();



};

#endif

