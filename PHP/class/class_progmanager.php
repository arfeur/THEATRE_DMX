<?php
require('class_bdd_php.php');/*----------------------------------------------------------------/
PROJET THEATRE DMX512
DEVELOPPÉ PAR : MAXIME LEPELLETIER 
BTS SN2

		- classe manager de programme de l'ihm php - 

cette classe permet de parametrer les scene de lumiere.
ces derniers composent les programmes (objet du fichier class_programme.php)
/----------------------------------------------------------------*/

	Class progmanager extends Programme

	{ 
				protected $_Programme;

// fonction qui permet d'ajouter un Programme sur l'ihm
		public function AjouterProgramme($_nomprog)
		{
			$_idprog=lastid();
			if($this->_Bdd->query("INSERT INTO `program` (`idProgram`, `Nom`) VALUES ('".$this->_idprog."','".$this->_nomprog."')"))
			{
				echo "programme ajouté";
			}	
			
		}
// fonction qui permet de modifier un Programme
		public function ModifierProgramme()
		{
			
		}
// fonction qui permet de supprimer un Programme sur l'ihm
		public function SupprimerProgramme()
		{
		
		}
// fonction qui permet de lancer un Programme a partir de l'ihm		
		public function RunProgramme()
		{
		
		}

		public function Lastid($nomtable)
		{
			if($this->_Bdd->query("SELECT MAX(".$nomtable.") FROM program"))
			echo $_Bdd;	
			return $_Bdd;	
		}


	}

?>