//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IHMrana.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ConnectButtonClick(TObject *Sender)
{
//CREATION DU MANAGER ET VERIFICATION DE LA CONNEXION A LA BDD
M1 = new manager();
M1->Connect();
if (M1->CheckEtat()==true)
	{
	PanelCheckConnection->Color=clLime;
	ConnectButton->Visible=false;
	DisconnectButton->Visible=true;

	//ON FAIT APPARAITRE LA VRAIE IHM
	InsertModeButton->Visible=true;
    SelectModeButton->Visible=true;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm2::DisconnectButtonClick(TObject *Sender)
{
//ON LIBERE L'ALLOCATION MEMOIRE ET ON REND A L'IHM SON ETAT D'ORIGINE
delete M1;
ConnectButton->Visible=true;
DisconnectButton->Visible=false;
PanelCheckConnection->Color=clRed;

//ON FAIT DISPARAITRE LA VRAIE IHM
	GetProgButton->Visible=false;
	GetSceneButton->Visible=false;
	GetProgEdit->Visible=false;
	GetSceneEdit->Visible=false;
	OkButton->Visible=false;
	ValiderSceneIdButton->Visible=false;
	IdLabel->Visible=false;
	NomLabel->Visible=false;
	NbrScnLabel->Visible=false;
	GetProgDataEdit1->Visible=false;
	GetProgDataEdit2->Visible=false;
	GetProgDataEdit3->Visible=false;
}
//---------------------------------------------------------------------------



void __fastcall TForm2::GetProgButtonClick(TObject *Sender)
{
//AFFICHAGE DE LA PARTIE DE L'IHM PERMETTANT LA RECUPERATION D'UN PROGRAMME EN BASE
OkButton->Visible=true;
GetProgEdit->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::OkButtonClick(TObject *Sender)
{
if (GetProgEdit->Visible==true)
	{


	//AFFICHAGE DES CHAMPS DE L'IHM PERMETTANT L'AFFICHAGE DES DONNEES DU PROGRAMME
	IdLabel->Visible=true;
	NomLabel->Visible=true;
	NbrScnLabel->Visible=true;
	GetProgDataEdit1->Visible=true;
	GetProgDataEdit2->Visible=true;
	GetProgDataEdit3->Visible=true;

	//CREATION DU PROGRAMME RECUPERANT LES DONNEES DE LA BDD
	P1 = new programme();
	P1 = M1->getProg(GetProgEdit->Text.ToInt());

	//INCREMENTATIONS DES VARIABLES DE STOCKAGE
	std::string ProgName;
	char* buffer;
	buffer = new char[100];
	itoa(P1->getId(),buffer,10);
	ProgName=P1->getName();

	//UTILISATION DES VARIABLES DE STOCKAGE POUR REMPLIR LES CHAMPS DE L'IHM

	GetProgDataEdit1->Text=buffer;
	GetProgDataEdit2->Text=ProgName.c_str();
	GetProgDataEdit3->Text=P1->getNbScene();

	std::string ChaineMemo;
	Scenes=P1->getScenes();
	}

if (InsertEquipmentEdit->Visible==true)
	{
	std::string converted;
	wchar_t * tmp;
	tmp = InsertEquipmentEdit->Text.w_str();
	int len = wcslen(tmp);
	char * rep = new char[len+1];
	wcstombs(rep, tmp, len);
	converted = rep;

	E1 = M1->InsertEquipment(converted);
	YesButton->Visible=true;
	NoButton->Visible=true;
	AddPropertiesLabel->Visible=true;
	}

if (InsertPropertiesEdit->Visible==true)
	{
	InsertOrdreEdit->Text=IncrementatorProperties;

	std::string convertie1;
	wchar_t * stock1;
	stock1 = InsertPropertiesEdit->Text.w_str();
	int length1 = wcslen(stock1);
	char * result1 = new char[length1+1];
	wcstombs(result1, stock1, length1);
	convertie1 = result1;

	std::string convertie2;
	char *buffer;
	buffer = new char[100];
	itoa(this->IncrementatorProperties,buffer,10);
	convertie2 = buffer;

	std::string convertie3;
	wchar_t * stock3;
	stock3 = GetProgDataEdit1->Text.w_str();
	int length3 = wcslen(stock3);
	char * result3 = new char[length3+1];
	wcstombs(result3, stock3, length3);
	convertie3 = result3;

	this->IncrementatorProperties++;
	InsertOrdreEdit->Text=IncrementatorProperties;
	M1->InsertProperties(convertie1,convertie2,convertie3);
	}
//for (int i = 0; i < Scenes.size(); i++)
//	{
//	ChaineMemo="Scene numero : ";
//	itoa(i,buffer,10);
//	ChaineMemo+=buffer;
//	ChaineMemo+="\nID = ";
//	itoa(Scenes[i]->getId(),buffer,10);
//	ChaineMemo+=buffer;
//	ChaineMemo+=", Nom = ";
//	ChaineMemo+=Scenes[i]->getName();
//	ChaineMemo+=", Temps de pause = ";
//	itoa(Scenes[i]->getTime(),buffer,10);
//	ChaineMemo+=buffer;
//	ChaineMemo+=", Nombre de sequences = ";
//	itoa(Scenes[i]->getNbSeq(),buffer,10);
//	ChaineMemo+=buffer;
//
//	GetDataMemo->Lines->Add(ChaineMemo.c_str());
//	ChaineMemo.clear();
//	}

}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormDestroy(TObject *Sender)
{
delete P1;
delete M1;
}
//---------------------------------------------------------------------------





void __fastcall TForm2::SelectModeButtonClick(TObject *Sender)
{
InsertModeButton->Visible=false;
SelectModeButton->Visible=false;
GetProgButton->Visible=true;
GetSceneButton->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::InsertModeButtonClick(TObject *Sender)
{
InsertModeButton->Visible=false;
SelectModeButton->Visible=false;
OkButton->Visible=true;
InsertEquipmentEdit->Visible=true;
NomLabel->Visible=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::YesButtonClick(TObject *Sender)
{
this->IncrementatorProperties=0;
InsertOrdreEdit->Text=IncrementatorProperties;
IdLabel->Visible=true;
GetProgDataEdit1->Visible=true;
GetProgDataEdit1->Text=E1->getId();
GetProgDataEdit1->Enabled=false;
YesButton->Visible=false;
NoButton->Visible=false;
AddPropertiesLabel->Visible=false;
DescriptionLabel->Visible=true;
InsertPropertiesEdit->Visible=true;
InsertEquipmentEdit->Visible=false;
NomLabel->Visible=false;
InsertOrdreEdit->Visible=true;
OrdreLabel->Visible=true;
InsertOrdreEdit->Enabled=false;

}
//---------------------------------------------------------------------------


