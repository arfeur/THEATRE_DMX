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

if (InsertEquipmentEdit->Visible==true)
	{
	std::string converted;
    wchar_t * tmp;
	tmp = InsertEquipmentEdit->Text.w_str();
	int len = wcslen(tmp);
	char * rep = new char[len+1];
	wcstombs(rep, tmp, len);
    converted = *rep;

	M1->InsertEquipment(converted)   ;
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

}
//---------------------------------------------------------------------------

