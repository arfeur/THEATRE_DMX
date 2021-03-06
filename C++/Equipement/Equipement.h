//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Equipement.h------------------------------------------------------//
//---Cette classe permet d'instancier des equipements comme des lumi�res-----//
//---------------------------------------------------------------------------//

#ifndef EquipementH
#define EquipementH
#include "./Property/Property.h"
#include <map>
#include <vector>
#include <string>

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
		int equipement::getNbVoies();
		std::map<std::string,property*> getProperties();
		int getId();
	//ajoute une propri�t� � un �quipement
	void  addProperty(std::string name, property * prop)
	{
		properties[name] = prop;
	}
	//retourne les propri�t�s ordonn�es
	std::vector<property*>  equipement::getOrderedProperties()
	{
		std::vector<property*> nonOrderedProperties;

		for(std::map<std::string,property*>::iterator it = properties.begin(); it != properties.end(); it++)
		{
			nonOrderedProperties.push_back((*it).second);
		}

		std::vector<property*> orderedProperties;

		while(nonOrderedProperties.size() > 0)
		{
			int minIdx = 0;
			for(int i = 1; i < nonOrderedProperties.size(); i++)
			{
				if(nonOrderedProperties[i]->getOrder() < nonOrderedProperties[minIdx]->getOrder())
				{
					minIdx = i;
				}
			}

			orderedProperties.push_back(nonOrderedProperties[minIdx]);
			nonOrderedProperties.erase(nonOrderedProperties.begin() + minIdx);
		}

		return orderedProperties;
	}
};

#endif

