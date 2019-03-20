//---------------------------------------------------------------------------

#ifndef MySQLH
#define MySQLH
//---------------------------------------------------------------------------
#include <vcl.h>
#define __WIN__
#include "include/mysql.h"
#include <vector>
#include <string>
#include "BDD.h"

using namespace std;

class MySQL
{
	public:

		virtual void Connect(char*Addr,char*Id,char*Mdp,char*Table);
		virtual void Disconnect();

		bool Insert(string request);
		bool Update(string request);
		bool Delete(string request);
		vector< vector<string> > Select(string request);

}





#endif
