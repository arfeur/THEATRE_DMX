//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Sequence.h--------------------------------------------------------//
//---Cette classe permet de d�finir une s�quence avec une dur�e et la trame--//
//qui lui sera affect�e------------------------------------------------------//
//---------------------------------------------------------------------------//

#ifndef SequenceH
#define SequenceH
#include "TrameManager.h"
#include "SequenceUsedEquipement.h"
//---------------------------------------------------------------------------

class sequence
{
	private:
		int id;
		int duree;
		trameManager* trame;
		int nbSeqUsedEq;
		std::vector<sequenceUsedEquipement *> seqEquipValues;

	public:
		sequence(int id, int duree, trameManager*);
		void setDuree(int value);
		void setId(int id);
		void setTrame(trameManager* trame);
		int getDuree();
		int getId();
		trameManager*getTrame();
		void addSequenceUsedEquipment(sequenceUsedEquipement * seqUsedEquip);
		std::vector<sequenceUsedEquipement *> & getSequenceUsedEquipments();
};

#endif

