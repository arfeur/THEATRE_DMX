//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:TrameManager.h--------------------------------------------------------//
//---Cette classe permet la construction de la trame DMX en r�cup�rant le canal,
//les �quipements et leurs propri�t�s---//
//---------------------------------------------------------------------------//
#pragma hdrstop

#include "TrameManager.h"
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)

//constructeur
	trameManager::trameManager()
	{
		 dmx = new char[512];
		 for (int i = 0; i < 512; i++)
		 {
			 this->dmx[i]=0;
		 }
	}
//insere dans dmx[512] l'equipement �  l'adresse choisi
	bool trameManager::insertEquipement(usedEquipement*usedEquip)
	{
        trame.push_back(usedEquip);
	}
//suppression d'un �quipement au canal choisis
	void trameManager::removeEquipement(usedEquipement*usedEquip)
	{
		std::vector<usedEquipement*>::iterator it = std::find(trame.begin(), trame.end(), usedEquip);
		if(it != trame.end())
            trame.erase(it);
	}
//verifie si des trames ne se superposes pas et si il n'y a pas d'erreurs
	bool trameManager::checkConflict()
	{
		int i,j;
		graph= new Graph();

		for (i = 0; i < graph->nodes.size() ; i++)
		{
			for (j = i+1; j < graph->nodes.size() ; j++)
			{
				if (Node::localCheckIntersection(graph->nodes[i],graph->nodes[j]))
				{
					graph->conflicts.push_back(new Conflict(graph->nodes[i],graph->nodes[j]));
					return graph->conflicts.size()>0;
				}
			}
		}
		return true;
	}
//r�cup�re et planifie la trame
	char* trameManager::getTrame()
	{
		for(int iEquip = 0; iEquip < trame.size(); iEquip++)
		{
			usedEquipement * usedEquip = trame[iEquip];
			int address = usedEquip->getAdresse();
			std::map<property*, int> & props = usedEquip->getValues();

			if(props.size() > 0)
			{
				std::vector<property*> orderedProperties = usedEquip->getOrderedProperties();

				for (int i = 0; i < orderedProperties.size(); i++)
				{
					dmx[address + i]=props[orderedProperties[i]];
				}
			}
		}

		return dmx;
	}
//renvoi un vecteur avec toutes les informations utilent � la trame
	std::vector<usedEquipement*> trameManager::getUsedEquipement()
	{
		return trame;
	}
