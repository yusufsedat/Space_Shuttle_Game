


#include <iostream>
#include <string>
#include <sstream>


#include "GrafikKonsol.hpp"


using namespace std;

struct Konum
{
	int x;
	int y;
};

class UzayMekigi
{
public:

	
	UzayMekigi() {

		karakter = "**    ****  ";
		renk = Grafik::renkOlustur(YAZIRENK_TURKUAZ, ARKARENK_SIYAH);

		konum = { 10,10 };


	}

	void ciz() {

		for (int satir = 0; satir < 3; satir++) {
			for (int sutun = 0; sutun < 4; sutun++)
			{
				int index = satir * 4 + sutun;

				Grafik::karakterYaz(konum.x + sutun, konum.y + satir, karakter[index], renk);


			}

		}
	}

	void hareketEt() {

		if (Grafik::tusBasilimi('A') && konum.x > 1) {

			konum.x--;
		}
		if (Grafik::tusBasilimi('D') && konum.x +3 < 99) {

			konum.x++;
		}

		if (Grafik::tusBasilimi('S') && konum.y + 2 < 18) {

			konum.y++;
		}
		if (Grafik::tusBasilimi('W') && konum.y > 2) {

			konum.y--;
		}

	
	}
	
	string karakter;
	int renk;
	Konum konum;

};

class Mermi {
public:
	static const int MAX_MERMI_SAYISI = 10;
	Konum mermilerKonum[MAX_MERMI_SAYISI];
	bool mermilerAktif[MAX_MERMI_SAYISI];
	string karakter;


	Mermi() {

		karakter = "-->";

		for (int i = 0; i < MAX_MERMI_SAYISI; i++) {
			mermilerAktif[i] = false;
		}
	}

	void mermiAtesle(int baslangicX, int baslangicY) {

		for (int i = 0; i < MAX_MERMI_SAYISI; i++) {


			if (!mermilerAktif[i]) {

				mermilerKonum[i].x = baslangicX;
				mermilerKonum[i].y = baslangicY;
				mermilerAktif[i] = true;
				return;
			}
		}
	}

	void mermileriCiz() { 


		for (int i = 0; i < MAX_MERMI_SAYISI; i++) {

			if (mermilerAktif[i]) {

				for (int j = 0; j < 3; j++) {

					Grafik::karakterYaz(mermilerKonum[i].x + j, mermilerKonum[i].y, karakter[j], Grafik::renkOlustur(YAZIRENK_SARI, ARKARENK_SIYAH));
				}
			}

		}



	}

	void mermileriHareketEt() {


		for (int i = 0; i < MAX_MERMI_SAYISI; i++) {


			if (mermilerAktif[i]) {

				mermilerKonum[i].x++;

				if (mermilerKonum[i].x > 95) {


					mermilerAktif[i] = false;



				}


			}
		}


	}
};

class Dusman {


public:
	Konum konum; 

	
	string karakter;
		
	int secim = 0;
	



	void karakterSec() {

		
		

		switch (secim)
		{
		case 0:
			karakter = "**** ** ****";
			break;
		case 1:
			karakter = " ** *  * ** ";
			break;
		case 2:
			karakter = " ** **** ** ";
			break;
		default:
			break;
		}

	}


	void dusmanCiz()
	{
		for (int satir = 0; satir < 3; satir++)
		{
			for (int sutun = 0; sutun < 4; sutun++)
			{
				int index = satir * 4 + sutun;

				Grafik::karakterYaz(konum.x + sutun, konum.y + satir, karakter[index], Grafik::renkOlustur(YAZIRENK_YESIL, ARKARENK_SIYAH));
			}

		}
	}

};

class Ekran {

public:

	void sinirCiz() {

		for (int i = 0; i < 99; i++)
		{
			Grafik::karakterYaz(i, 1, '-', Grafik::renkOlustur(YAZIRENK_MOR, ARKARENK_MAVI));
		}
		for (int i = 0; i < 99; i++)
		{
			Grafik::karakterYaz(i, 19, '-', Grafik::renkOlustur(YAZIRENK_MOR, ARKARENK_MAVI));
		}

	}

	
	

};

class Skor {


public:
	
	UzayMekigi uzayMekigi;
	Dusman dusman;
	Mermi mermi;

	int skorSayisi = 0;
	int renk = Grafik::renkOlustur(YAZIRENK_KIRMIZI, ARKARENK_YESIL);
	
	

	void SkorArttir() {

		skorSayisi++;
	}

	void SkorAzalt() {

		skorSayisi--;
	}

	void SkorYazdir(){

		
		stringstream ss;

		ss << "Skor: " << skorSayisi;

		string skorString = ss.str();

		for (int i = 0; i < skorString.size(); i++) {
			Grafik::karakterYaz(99 - skorString.size() + i, 0, skorString[i],renk);
		}


	}


};

UzayMekigi uzayMekigi;
Ekran ekran;
Dusman dusman1,dusman2;
Konum konum;
Mermi mermi;
Skor skor;


int main()
{	
	

	srand(time(0));

	Grafik::sahneAyarla(100, 20);

	dusman1.konum.x = 95;
	dusman1.secim = rand() % 2;
	dusman1.konum.y = 0 + rand() % 15 + 2;

	dusman2.konum.x = -1;

	bool dusman1EnSolaUlasti = false;
	bool dusman2EnSolaUlasti = false;
	bool carpismaOldu = false;

	bool spaceBasildi = false;
	

	while (true)
	{	
		Grafik::sahneyiTemizle();

		Grafik::klavyeOku();

		skor.SkorYazdir();

		dusman1.karakterSec();

		uzayMekigi.hareketEt();


		uzayMekigi.ciz();


		

		mermi.mermileriCiz();
		mermi.mermileriHareketEt();

		if (dusman1.konum.x > 0 ) {
			dusman1.dusmanCiz();
			dusman1.konum.x--;
		}
		

		if (dusman2.konum.x > 0 ) {
			dusman2.dusmanCiz();
			dusman2.konum.x--;
		}

		if (dusman1.konum.x == 40 ) {
			dusman2.konum.x = 95;
			dusman2.secim = rand() % 3;
			dusman2.konum.y = 0 + rand() % 15 + 2;
			dusman2.karakterSec();
		}

		if (dusman2.konum.x == 40) {
			dusman1.konum.x = 95;
			dusman1.secim = rand() % 3;
			dusman1.konum.y = 0 + rand() % 15 + 2;
			dusman1.karakterSec();
		}


		if (Grafik::tusBasilimi(' ')) {
			if (!spaceBasildi) {
				mermi.mermiAtesle(uzayMekigi.konum.x+4, uzayMekigi.konum.y+1);
				spaceBasildi = true;
			}
		}
		else {
			spaceBasildi = false;
		}



		for (int i = 0; i < mermi.MAX_MERMI_SAYISI; i++) {
			if (mermi.mermilerAktif[i] &&
				mermi.mermilerKonum[i].y >= dusman1.konum.y &&
				mermi.mermilerKonum[i].y <= dusman1.konum.y + 2 &&
				mermi.mermilerKonum[i].x >= dusman1.konum.x &&
				mermi.mermilerKonum[i].x <= dusman1.konum.x + 4) { 

				skor.SkorArttir();
				mermi.mermilerAktif[i] = false;
				dusman1.konum.x = 95;
				dusman1.secim = rand() % 2;
				dusman1.konum.y = 0 + rand() % 15 + 2;
			}
		}

		for (int i = 0; i < mermi.MAX_MERMI_SAYISI; i++) {
			if (mermi.mermilerAktif[i] &&
				mermi.mermilerKonum[i].y >= dusman2.konum.y &&
				mermi.mermilerKonum[i].y <= dusman2.konum.y +2 &&
				mermi.mermilerKonum[i].x == dusman2.konum.x &&
				mermi.mermilerKonum[i].x <= dusman1.konum.x + 4 ) {

				skor.SkorArttir();

				

				mermi.mermilerAktif[i] = false;
				dusman2.konum.x = 95;
				dusman2.secim = rand() % 2;
				dusman2.konum.y = 0 + rand() % 15 + 2;
			}
		}

	
		if (dusman1.konum.x == 0 && !dusman1EnSolaUlasti) {
			skor.SkorAzalt();
			dusman1EnSolaUlasti = true;
		}
		else if (dusman1.konum.x != 0) {
			dusman1EnSolaUlasti = false;
		}



		if (dusman2.konum.x == 0 && !dusman2EnSolaUlasti) {
			skor.SkorAzalt();
			dusman2EnSolaUlasti = true;
		}
		else if (dusman2.konum.x != 0) {
			dusman2EnSolaUlasti = false;
		}

		
		int dusman1Sol = dusman1.konum.x;
		int dusman1Sag = dusman1.konum.x + 4;
		int dusman1Ust = dusman1.konum.y;
		int dusman1Alt = dusman1.konum.y + 3;

		int dusman2Sol = dusman2.konum.x;
		int dusman2Sag = dusman2.konum.x + 4;
		int dusman2Ust = dusman2.konum.y;
		int dusman2Alt = dusman2.konum.y + 3;

		int uzayMekigiSol = uzayMekigi.konum.x;
		int uzayMekigiSag = uzayMekigi.konum.x + 4;
		int uzayMekigiUst = uzayMekigi.konum.y;
		int uzayMekigiAlt = uzayMekigi.konum.y + 3;


		
		if (dusman1Sag > uzayMekigiSol && dusman1Sol < uzayMekigiSag &&
			dusman1Alt > uzayMekigiUst && dusman1Ust < uzayMekigiAlt) {

			if (!carpismaOldu) {
				skor.SkorAzalt();

				carpismaOldu = true;

				dusman1.konum.x = 95;
				dusman1.secim = rand() % 2;
				dusman1.konum.y = 0 + rand() % 15 + 2;
			}
		}
		else {
			carpismaOldu = false;
		}

		if (dusman2Sag > uzayMekigiSol && dusman2Sol < uzayMekigiSag &&
			dusman2Alt > uzayMekigiUst && dusman2Ust < uzayMekigiAlt) {

			if (!carpismaOldu) {
				skor.SkorAzalt();

				carpismaOldu = true;

				dusman2.konum.x = 95;
				dusman2.secim = rand() % 2;
				dusman2.konum.y = 0 + rand() % 15 + 2;
			}
		}
		else {
			carpismaOldu = false;
		}


		ekran.sinirCiz();


		Grafik::sahneyiCizdir();

		Sleep(30);

	}

}
