#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
	nombre = nombre*10 +chiffre;

}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{

	do {
		ajouter_chiffre_droit(nombre,  chiffre);
		repetitions_chiffre--;
	}while(repetitions_chiffre!=0);
}

int lire_et_dire(int nombre)
{

	int tmp1 = separer_chiffre_gauche( nombre);
	int tmp2;
	int rep = 1;
	do{
		tmp2 = separer_chiffre_gauche( nombre);
		if(tmp1 == tmp2){
			rep = rep+1;
		}else{
			dire_chiffre( nombre, rep,  tmp1);
		tmp1 = separer_chiffre_gauche( nombre);
			rep = 1;
		}
	}while(nombre > 0);


return nombre ;




}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}
