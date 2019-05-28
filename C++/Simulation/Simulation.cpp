//---------------------------------------------------------------------------

#pragma hdrstop

#include "Simulation.h"
#include "Property.h"
#include "Equipement.h"
#include "UsedEquipement.h"
#include "SequenceUsedEquipement.h"
#include "Sequence.h"
#include "Scene.h"
#include "Programme.h"
#include "TrameManager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

	programme*simulation::getProgramme()
	{

//SCENE1-----------------------------------------------------------------------------------------------------------------------------
//lumi�re SABER SPOT---------------------------------------------------------------------------

	equipement * equip = new equipement(1, "Lampe");

	equip->addProperty("Strobo", new property(1, 0, "Strobo"));
	equip->addProperty("Rouge", new property(2, 1, "Composante rouge"));
	equip->addProperty("Vert", new property(3, 2, "Composante verte"));
	equip->addProperty("Bleu", new property(4, 3, "Composante bleue"));
	equip->addProperty("Blanc", new property(5, 4, "Composante blanche"));
	equip->addProperty("Intensit�", new property(6, 5, "Intensit�"));

	trameManager*trame=new trameManager();
	std::vector<property*> orderedProps = equip->getOrderedProperties();
	usedEquipement * usedEquip = new usedEquipement(0, equip);
	trame->insertEquipement(usedEquip);

	// Sequence rouge
	sequenceUsedEquipement * seqUsedEquip1[6];
	seqUsedEquip1[0] = new sequenceUsedEquipement(usedEquip, orderedProps[0], 116);
	seqUsedEquip1[1] = new sequenceUsedEquipement(usedEquip, orderedProps[1], 255);
	seqUsedEquip1[2] = new sequenceUsedEquipement(usedEquip, orderedProps[2], 0);
	seqUsedEquip1[3] = new sequenceUsedEquipement(usedEquip, orderedProps[3], 0);
	seqUsedEquip1[4] = new sequenceUsedEquipement(usedEquip, orderedProps[4], 0);
	seqUsedEquip1[5] = new sequenceUsedEquipement(usedEquip, orderedProps[5], 255);

	sequence * seq1 = new sequence(1, 1500, trame);
	for(int i = 0; i < 6; i++)
		seq1->addSequenceUsedEquipment(seqUsedEquip1[i]);

	// Sequence verte
	sequenceUsedEquipement * seqUsedEquip2[6];
	seqUsedEquip2[0] = new sequenceUsedEquipement(usedEquip, orderedProps[0], 116);
	seqUsedEquip2[1] = new sequenceUsedEquipement(usedEquip, orderedProps[1], 0);
	seqUsedEquip2[2] = new sequenceUsedEquipement(usedEquip, orderedProps[2], 255);
	seqUsedEquip2[3] = new sequenceUsedEquipement(usedEquip, orderedProps[3], 0);
	seqUsedEquip2[4] = new sequenceUsedEquipement(usedEquip, orderedProps[4], 0);
	seqUsedEquip2[5] = new sequenceUsedEquipement(usedEquip, orderedProps[5], 255);

	sequence * seq2 = new sequence(2, 1500, trame);
	for(int i = 0; i < 6; i++)
		seq2->addSequenceUsedEquipment(seqUsedEquip2[i]);

	// Sequence bleue
	sequenceUsedEquipement * seqUsedEquip3[6];
	seqUsedEquip3[0] = new sequenceUsedEquipement(usedEquip, orderedProps[0], 116);
	seqUsedEquip3[1] = new sequenceUsedEquipement(usedEquip, orderedProps[1], 0);
	seqUsedEquip3[2] = new sequenceUsedEquipement(usedEquip, orderedProps[2], 0);
	seqUsedEquip3[3] = new sequenceUsedEquipement(usedEquip, orderedProps[3], 255);
	seqUsedEquip3[4] = new sequenceUsedEquipement(usedEquip, orderedProps[4], 0);
	seqUsedEquip3[5] = new sequenceUsedEquipement(usedEquip, orderedProps[5], 255);

	sequence * seq3 = new sequence(3, 1500, trame);
	for(int i = 0; i < 6; i++)
		seq3->addSequenceUsedEquipment(seqUsedEquip3[i]);

	scn1= new scene(1, "RGB", 20);
	scn1->setSequences(seq1);
	scn1->setSequences(seq2);
	scn1->setSequences(seq3);
//	scn1->planifyScene();
//	scn.push_back(scn1);

//lumi�re WALL-E---------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

	equipement * equip2 = new equipement(2, "Wall-E");

	equip2->addProperty("Strobo", new property(1, 0, "Strobo"));
	equip2->addProperty("Gobo", new property(2, 1, "Gobo"));
	equip2->addProperty("Gobo-rotatie", new property(3, 2, "Gobo-rotatie"));
	equip2->addProperty("Couleur", new property(4, 3, "Couleur"));
	equip2->addProperty("Pan", new property(5, 4, "Pan"));
	equip2->addProperty("Tilt", new property(6, 5, "Tilt"));

	std::vector<property*> orderedProps2 = equip2->getOrderedProperties();
	usedEquipement * usedEquip2 = new usedEquipement(19, equip2);
	trame->insertEquipement(usedEquip2);

	// Sequence random
	sequenceUsedEquipement * seqUsedEquip20[6];
	seqUsedEquip20[0] = new sequenceUsedEquipement(usedEquip2, orderedProps2[0], 255);
	seqUsedEquip20[1] = new sequenceUsedEquipement(usedEquip2, orderedProps2[1], 2);
	seqUsedEquip20[2] = new sequenceUsedEquipement(usedEquip2, orderedProps2[2], 135);
	seqUsedEquip20[3] = new sequenceUsedEquipement(usedEquip2, orderedProps2[3], 82);
	seqUsedEquip20[4] = new sequenceUsedEquipement(usedEquip2, orderedProps2[4], 135);
	seqUsedEquip20[5] = new sequenceUsedEquipement(usedEquip2, orderedProps2[5], 135);

	sequence * seq20 = new sequence(1, 500, trame);
	for(int i = 0; i < 6; i++)
	{
		seq1->addSequenceUsedEquipment(seqUsedEquip20[i]);
		seq20->addSequenceUsedEquipment(seqUsedEquip20[i]);
	}

	// Sequence random
	sequenceUsedEquipement * seqUsedEquip21[6];
	seqUsedEquip21[0] = new sequenceUsedEquipement(usedEquip2, orderedProps2[0], 255);
	seqUsedEquip21[1] = new sequenceUsedEquipement(usedEquip2, orderedProps2[1], 2);
	seqUsedEquip21[2] = new sequenceUsedEquipement(usedEquip2, orderedProps2[2], 135);
	seqUsedEquip21[3] = new sequenceUsedEquipement(usedEquip2, orderedProps2[3], 255);
	seqUsedEquip21[4] = new sequenceUsedEquipement(usedEquip2, orderedProps2[4], 13);
	seqUsedEquip21[5] = new sequenceUsedEquipement(usedEquip2, orderedProps2[5], 13);

	sequence * seq21 = new sequence(2, 500, trame);
	for(int i = 0; i < 6; i++)
	{
		seq2->addSequenceUsedEquipment(seqUsedEquip21[i]);
		seq21->addSequenceUsedEquipment(seqUsedEquip21[i]);
	}


	// Sequence random
	sequenceUsedEquipement * seqUsedEquip22[6];
	seqUsedEquip22[0] = new sequenceUsedEquipement(usedEquip2, orderedProps2[0], 255);
	seqUsedEquip22[1] = new sequenceUsedEquipement(usedEquip2, orderedProps2[1], 2);
	seqUsedEquip22[2] = new sequenceUsedEquipement(usedEquip2, orderedProps2[2], 135);
	seqUsedEquip22[3] = new sequenceUsedEquipement(usedEquip2, orderedProps2[3], 1);
	seqUsedEquip22[4] = new sequenceUsedEquipement(usedEquip2, orderedProps2[4], 255);
	seqUsedEquip22[5] = new sequenceUsedEquipement(usedEquip2, orderedProps2[5], 255);
	sequence * seq22 = new sequence(3, 500, trame);
	for(int i = 0; i < 6; i++)
	{
		seq3->addSequenceUsedEquipment(seqUsedEquip22[i]);
		seq22->addSequenceUsedEquipment(seqUsedEquip22[i]);
	}

	//scn2= new scene(2,"WallE",19);
	scn1->setSequences(seq20);
	scn1->setSequences(seq21);
	scn1->setSequences(seq22);
	scn1->planifyScene();
	scn.push_back(scn1);

//SCENE2-----------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------

	// Sequence rouge

	seqUsedEquip1[0] = new sequenceUsedEquipement(usedEquip, orderedProps[0], 32);
	seqUsedEquip1[1] = new sequenceUsedEquipement(usedEquip, orderedProps[1], 255);
	seqUsedEquip1[2] = new sequenceUsedEquipement(usedEquip, orderedProps[2], 0);
	seqUsedEquip1[3] = new sequenceUsedEquipement(usedEquip, orderedProps[3], 0);
	seqUsedEquip1[4] = new sequenceUsedEquipement(usedEquip, orderedProps[4], 0);
	seqUsedEquip1[5] = new sequenceUsedEquipement(usedEquip, orderedProps[5], 255);

	sequence * seq4 = new sequence(1, 6000, trame);

	for(int i = 0; i < 6; i++)
		seq4->addSequenceUsedEquipment(seqUsedEquip1[i]);

	// Sequence verte

	seqUsedEquip2[0] = new sequenceUsedEquipement(usedEquip, orderedProps[0], 87);
	seqUsedEquip2[1] = new sequenceUsedEquipement(usedEquip, orderedProps[1], 255);
	seqUsedEquip2[2] = new sequenceUsedEquipement(usedEquip, orderedProps[2], 0);
	seqUsedEquip2[3] = new sequenceUsedEquipement(usedEquip, orderedProps[3], 0);
	seqUsedEquip2[4] = new sequenceUsedEquipement(usedEquip, orderedProps[4], 0);
	seqUsedEquip2[5] = new sequenceUsedEquipement(usedEquip, orderedProps[5], 255);

	sequence * seq5 = new sequence(1, 6000, trame);

	for(int i = 0; i < 6; i++)
		seq5->addSequenceUsedEquipment(seqUsedEquip2[i]);

	// Sequence bleue

	seqUsedEquip3[0] = new sequenceUsedEquipement(usedEquip, orderedProps[0], 159);
	seqUsedEquip3[1] = new sequenceUsedEquipement(usedEquip, orderedProps[1], 255);
	seqUsedEquip3[2] = new sequenceUsedEquipement(usedEquip, orderedProps[2], 0);
	seqUsedEquip3[3] = new sequenceUsedEquipement(usedEquip, orderedProps[3], 0);
	seqUsedEquip3[4] = new sequenceUsedEquipement(usedEquip, orderedProps[4], 0);
	seqUsedEquip3[5] = new sequenceUsedEquipement(usedEquip, orderedProps[5], 255);


	sequence * seq6 = new sequence(1, 6000, trame);

	for(int i = 0; i < 6; i++)
		seq6->addSequenceUsedEquipment(seqUsedEquip3[i]);

	scn2= new scene(1, "RGB", 20);
	scn2->setSequences(seq4);
	scn2->setSequences(seq5);
	scn2->setSequences(seq6);
//	scn1->planifyScene();
//	scn.push_back(scn1);

//lumi�re WALL-E---------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

	//trame->insertEquipement(usedEquip2);

	// Sequence random
	/*
	seqUsedEquip20[0] = new sequenceUsedEquipement(usedEquip2, orderedProps2[0], 255);
	seqUsedEquip20[1] = new sequenceUsedEquipement(usedEquip2, orderedProps2[1], 255);
	seqUsedEquip20[2] = new sequenceUsedEquipement(usedEquip2, orderedProps2[2], 245);
	seqUsedEquip20[3] = new sequenceUsedEquipement(usedEquip2, orderedProps2[3], 67);
	seqUsedEquip20[4] = new sequenceUsedEquipement(usedEquip2, orderedProps2[4], 255);
	seqUsedEquip20[5] = new sequenceUsedEquipement(usedEquip2, orderedProps2[5], 135);


	for(int i = 0; i < 6; i++)
	{
		seq1->addSequenceUsedEquipment(seqUsedEquip20[i]);
		seq20->addSequenceUsedEquipment(seqUsedEquip20[i]);
	}

	// Sequence random

	seqUsedEquip21[0] = new sequenceUsedEquipement(usedEquip2, orderedProps2[0], 131);
	seqUsedEquip21[1] = new sequenceUsedEquipement(usedEquip2, orderedProps2[1], 255);
	seqUsedEquip21[2] = new sequenceUsedEquipement(usedEquip2, orderedProps2[2], 245);
	seqUsedEquip21[3] = new sequenceUsedEquipement(usedEquip2, orderedProps2[3], 67);
	seqUsedEquip21[4] = new sequenceUsedEquipement(usedEquip2, orderedProps2[4], 255);
	seqUsedEquip21[5] = new sequenceUsedEquipement(usedEquip2, orderedProps2[5], 135);


	for(int i = 0; i < 6; i++)
	{
		seq2->addSequenceUsedEquipment(seqUsedEquip21[i]);
		seq21->addSequenceUsedEquipment(seqUsedEquip21[i]);
	}


	// Sequence random

	seqUsedEquip22[0] = new sequenceUsedEquipement(usedEquip2, orderedProps2[0], 252);
	seqUsedEquip22[1] = new sequenceUsedEquipement(usedEquip2, orderedProps2[1], 255);
	seqUsedEquip22[2] = new sequenceUsedEquipement(usedEquip2, orderedProps2[2], 255);
	seqUsedEquip22[3] = new sequenceUsedEquipement(usedEquip2, orderedProps2[3], 67);
	seqUsedEquip22[4] = new sequenceUsedEquipement(usedEquip2, orderedProps2[4], 255);
	seqUsedEquip22[5] = new sequenceUsedEquipement(usedEquip2, orderedProps2[5], 135);

	for(int i = 0; i < 6; i++)
	{
		seq3->addSequenceUsedEquipment(seqUsedEquip22[i]);
		seq22->addSequenceUsedEquipment(seqUsedEquip22[i]);
	}

	//scn2= new scene(2,"WallE",19);
	scn2->setSequences(seq20);
	scn2->setSequences(seq21);
	scn2->setSequences(seq22);
	*/
	//scn2->planifyScene();
	scn.push_back(scn2);

	return new programme(3, "Simulation", scn);
	}