//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:TCPServer.h-------------------------------------------------------//
//---Cette classe permet de gerer la r�ception des donn�es envoy� par le-----//
//---TCPclient et de d�coup� la trame pour identifier si c'est un programme--//
//-----ou une scene----------------------------------------------------------//
//---------------------------------------------------------------------------//

#pragma hdrstop

#include "TCPServer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

	TCPServer::TCPServer()
	{
		WORD ver= MAKEWORD(2,2);
		int wsok=WSAStartup(ver, &wsData);

	//creation du socket

		listening = socket(AF_INET, SOCK_STREAM, 0);
		shData= new SharedData<clientMessage>;
	}

//cr�ation du bind entre l'adresse ip et le port vers un socket
	void TCPServer::bindSocket(unsigned short port)
	{
		sockaddr_in hint;
		hint.sin_family=AF_INET;
		hint.sin_port=htons(port);
		hint.sin_addr.S_un.S_addr = INADDR_ANY;

		bind(listening, (sockaddr*)&hint, sizeof(hint));

	//on indique � la Winsock que l'on est en �coute

		listen(listening,SOMAXCONN);
	}
//on attend la connexion avec le client

	DWORD WINAPI TCPServer::connexion(LPVOID params)
	{
		TCPServer * server = (TCPServer*)params;


		int clientSize= sizeof(server->client);


		//boucle infini car la connexion attend un client
		while(1)
		{
			SOCKET sock = accept(server->listening, (sockaddr*)
			&(server->client), &clientSize);

			clientInfo * clInfo = new clientInfo();
			clInfo->sock = sock;
			clInfo->server = server;
			clInfo->clEtat.connect = true;

			DWORD ref;
			CreateThread(
				NULL,
				0,
				TCPServer::received,
				clInfo,
				0,
				&ref);
		}


	}
//s'occupe de la r�ception et du partage du message
	DWORD WINAPI TCPServer::received(void * params)
	{
		clientInfo * clInfo = ((clientInfo*)params);
		char buf[4096];
		bool etat;
		etat=true;

		while(etat==true)
		{
			ZeroMemory(buf,4096);
			//reception du message client
			int bytesReceived= recv(clInfo->sock, buf, 4096, 0);
			//allocation de la structure qui contient le message et son client
			clientMessage * message = new clientMessage();

			// Le client s'est d�co
			if (bytesReceived== SOCKET_ERROR || bytesReceived==0)
			{
				etat = false;
				clInfo->clEtat.connect = false;
				//passage des info client au clientMessage
				message->clInfo = *clInfo;
			}
			else
			{
				// Reception de la donn�e
				message->message = buf;
				message->clInfo = *clInfo;

            }

			//ajout du message dans la classe SharedData pour
			//partager mon message � l'aide du mutex
			clInfo->server->shData->Add(*message);
			delete message;

		}
		//fermeture du socket
		if (etat==false)
		{
			closesocket(clInfo->sock);
		}
	}

