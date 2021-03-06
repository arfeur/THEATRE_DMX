//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#pragma hdrstop

#include "IHM.h"
#include "./TCPServer/ServerStructs.h"
#include "./TCPServer/Parser.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
//-------------------------------lumi�re---------------------------------------

	server = NULL;
	this->form = new TForm2(Owner);
	simul=new simulation();
	recup="0";
    tramePrincipale =new trameManager();
}


//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//---------------------------------------------------------------------------
//Connexion TCPServeur
	server= new TCPServer();
	if (edtPort->Text!="")
	{
		server->bindSocket(edtPort->Text.ToInt());
	}
	else
	{
		Label16->Visible=true;
    }
	DWORD dwThreadId;

	CreateThread(
		NULL,
		0,
		TCPServer::connexion,
		server,
		0,
		&dwThreadId);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{

//-------------------------------------------------------------------------------------------------------
	if (btnValideEqp->OnClick)
	{
//		equipement* equip;
//        equip->addProperty(
	}
//-------------------------------------------------------------------------------------------------------

//-------------------------------serveur---------------------------------------
	if(server != NULL)
	{
		Shape3->Brush->Color=clGreen;
		try
		{   //r�cup�ration du
			 cl = server->shData->Get();
			//on v�rifie l'etat du client stock� dans une structure InfoClient
			if(cl.clInfo.clEtat.connect== true)
			{
				Label6->Caption = cl.message.c_str();
				Shape4->Brush->Color=clGreen;
				std::string test=Parser::Parse(cl);
				recup = new char[test.length() +1];
				strcpy(recup,test.c_str());
				Edit1->Text=recup;

			}
			else
			{
				Label4->Caption = "Client d�connect�";
				Shape3->Brush->Color=clRed;
				Shape4->Brush->Color=clRed;
			}


		}
		catch(TCPServerException error)
		{
			//MessageBox(this->Handle, error.c_str(), "Erreur", 0);
		}
	}

//---------------------------------------------------------------------------

//chargement de la dll
    //chargement pour la dll
	HINSTANCE g_dasusbdll = NULL;
	typedef int (*DASHARDCOMMAND)(int, int, unsigned char*);
	DASHARDCOMMAND  DasUsbCommand = NULL;

	g_dasusbdll = LoadLibrary("DasHard2006.dll");
	if (g_dasusbdll)
		DasUsbCommand  = (DASHARDCOMMAND)::GetProcAddress((HMODULE)g_dasusbdll, "DasUsbCommand");
	if (DasUsbCommand)
		Shape1->Brush->Color=clGreen;

//connexion � l'usb dmx
	DasUsbCommand(DHC_INIT,0,NULL);
	if (DasUsbCommand(DHC_OPEN,0,0)>0)
	{

	/*int val=0;
//	val = atoi(recup);
//	if (val != 0)
//		{
			if(scn.size() > 0)
			{
				//lblNbCan->Caption=scn.size();
				scene * curScene = scn.front();
				// Si la scene est termin�e, on la retire de la liste de scene � executer

				if(curScene->updateScene())
				{
					scn.erase(scn.begin());
					if(scn.size() > 0)
						scn.front()->planifyScene();
				}

				if(scn.size() == 0)
				{
					 scn = simul->getProgramme(val)->getScenes();
					 scn.front()->planifyScene();
				}

				//DasUsbCommand(DHC_DMXOUT, 512, curScene->getSequences()[curScene->getSeqIndex()]->getTrame()->getTrame());
			}
			else
			{   //programme*progID=manager->getProg(8);
				scn = simul->getProgramme(val)->getScenes(); //progID->getScenes();
				scn.front()->planifyScene();
			}

		Shape2->Brush->Color=clGreen;
		//}
		//DasUsbCommand(DHC_DMXOUT, 512, trame->dmx );
		*/

		if(scn.size() > 0)
		{
			//lblNbCan->Caption=scn.size();
			scene * curScene = scn.front();
			// Si la scene est termin�e, on la retire de la liste de scene � executer

			if(curScene->updateScene())
			{
				scn.erase(scn.begin());
				if(scn.size() > 0)
					scn.front()->planifyScene();
			}

			if(scn.size() == 0)
			{
				 scn = ProgrammeEnCours->getScenes();
				 scn.front()->planifyScene();
			}

			DasUsbCommand(DHC_DMXOUT, 512, curScene->getSequences()[curScene->getSeqIndex()]->getTrame()->getTrame());
		}
		else
		{   //programme*progID=manager->getProg(8);
			scn = ProgrammeEnCours->getScenes(); //progID->getScenes();
			scn.front()->planifyScene();
		}



	}

	if (DasUsbCommand(DHC_OPEN,0,0)>0)
	DasUsbCommand(DHC_CLOSE,0,0);
	DasUsbCommand(DHC_EXIT,0, NULL);

}


void __fastcall TForm1::menuEqpClick(TObject *Sender)
{
	if (menuEqp->OnClick)
	{
		gbEqp->Visible=true;
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::btnValideEqpClick(TObject *Sender)
{
	//---------------Fonctionnalit� de L'IHM-----------------------------
	if (edtNameEqp->Text!="" && edtNbCan->Text!="" && btnValideEqp->OnClick)
	{
		lblProp->Visible=true;
		btnPropEqp->Visible=true;

	}
	else
	{
		MessageBox(this->Handle,"Un ou plusieurs champs sont vides", "Erreur", 0);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnPropEqpClick(TObject *Sender)
{
//	if (edtAdr->Text!="" && btnPropEqp->OnClick)
//	{
//		lblEqpValide->Visible=true;
//		btnOkEqp->Visible=true;
//		btnNokEqp->Visible=true;
//	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::btnOkEqpClick(TObject *Sender)
{
	//TODO: check dans la BDD si l'�quipement n'y est pas via le nom

}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnNokEqpClick(TObject *Sender)
{
	//TODO: recharge une page de formulaire
}
//---------------------------------------------------------------------------



//bouton qui permet d'ajouter des equipements pour les s�quences
void __fastcall TForm1::btnSeqAddClick(TObject *Sender)
{
	int  NbListSq1;
	int  NbListSq2;
	 NbListSq1=lbSeq->Items->Count;
	  NbListSq2=lb2Seq->Items->Count;
		 for(int i=0;i<NbListSq1;i++)
		 {
			if (lbSeq->Selected[i])
				{
					if (!FileExists(lbSeq->Items->Strings[i]))
					 {
						  lb2Seq->Items->Strings[NbListSq2]=lbSeq->Items->Strings[i];

						  NbListSq2++;


					 }
				}
		 }

}
//---------------------------------------------------------------------------
//bouton qui supprime des �quipements pour les s�quences
void __fastcall TForm1::btnSeqSuppClick(TObject *Sender)
{
	int  NbListSq1;
	int  NbListSq2;
	 NbListSq1=lbSeq->Items->Count;
	  NbListSq2=lb2Seq->Items->Count;
		 for(int i=0;i<NbListSq2;i++)
		 {
			if (lb2Seq->Selected[i])
				{
					if (!FileExists(lbSeq->Items->Strings[i]))
					 {

						  lb2Seq->Items->Delete(i);
						  NbListSq2--;


					 }
				}
		 }
}
//---------------------------------------------------------------------------
//g�n�re les �quipements de la bdd
void __fastcall TForm1::gpSeqClick(TObject *Sender)
{
	//TODO: CODE QUI GENERE LES EQUIPEMENTS DEPUIS LA BDD

	lbSeq->Items->Add("Eqp_1");
	lbSeq->Items->Add("Eqp_2");
	lbSeq->Items->Add("Eqp_3");
	lbSeq->Items->Add("Eqp_4");
	lbSeq->Items->Add("Eqp_5");
	lbSeq->Items->Add("Eqp_6");

}
//---------------------------------------------------------------------------
//g�n�re les s�quences de la bdd
void __fastcall TForm1::gpSceneClick(TObject *Sender)
{
	//TODO: CODE QUI GENERE LES SEQUENCES DEPUIS LA BDD

	lbScene->Items->Add("Seq_1");
	lbScene->Items->Add("Seq_2");
	lbScene->Items->Add("Seq_3");
	lbScene->Items->Add("Seq_4");
	lbScene->Items->Add("Seq_5");
	lbScene->Items->Add("Seq_6");
}
//---------------------------------------------------------------------------
//affiche les scenes dans le listbox
void __fastcall TForm1::btnScnAddClick(TObject *Sender)
{
	int  NbListScn1;
	int  NbListScn2;
	 NbListScn1=lbScene->Items->Count;
	  NbListScn2=lb2Scene->Items->Count;
		 for(int i=0;i<NbListScn1;i++)
		 {
			if (lbScene->Selected[i])
				{
					if (!FileExists(lbScene->Items->Strings[i]))
					 {

						 lb2Scene->Items->Strings[NbListScn2]=lbScene->Items->Strings[i];
						 NbListScn2++;


					 }
				}
		 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnScnSuppClick(TObject *Sender)
{
	int  NbListScn1;
	int  NbListScn2;
	 NbListScn1=lbScene->Items->Count;
	  NbListScn2=lb2Scene->Items->Count;
		 for(int i=0;i<NbListScn2;i++)
		 {
			if (lbScene->Selected[i])
				{
					if (!FileExists(lbScene->Items->Strings[i]))
					 {
						 lb2Scene->Items->Delete(i);
						 NbListScn2--;
					 }
				}
		 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::GroupBox4Click(TObject *Sender)
{
  	//TODO: CODE QUI GENERE LES EQUIPEMENTS DEPUIS LA BDD

	lbAdressage->Items->Add("Eqp_1");
	lbAdressage->Items->Add("Eqp_2");
	lbAdressage->Items->Add("Eqp_3");
	lbAdressage->Items->Add("Eqp_4");
	lbAdressage->Items->Add("Eqp_5");
	lbAdressage->Items->Add("Eqp_6");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button6Click(TObject *Sender)
{
	this->form->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::btnAdrClick(TObject *Sender)
{

	int NbList=lbAdressage->Items->Count;
	int i;
	for (i = 0; i < NbList; i++)
	{
		if (lbAdressage->Selected[i] && edtAdr->Text!="")
		{
		  //TODO: Inclure l'adresse � l'�quipement s�lectionn�
		  lblAjoutSucc->Visible=true;
		}
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::btnLancerSimulationClick(TObject *Sender)
{
	simulation * P1simul ;
	if (Timer1->Enabled == false)
	{
		btnLancerSimulation->Caption ="Stoper la simulation";
		P1simul= new simulation();
		ProgrammeEnCours = P1simul->getProgramme(0);
		Timer1->Enabled = true;
	}else
	{
		Timer1->Enabled = false;
		btnLancerSimulation->Caption ="Lancer la simulation";
	}


}
//---------------------------------------------------------------------------

