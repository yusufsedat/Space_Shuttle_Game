#pragma once
#include<Windows.h>
#define YAZIRENK_SIYAH		0X00
#define YAZIRENK_MAVI		0x09
#define YAZIRENK_YESIL		0x0A
#define YAZIRENK_TURKUAZ	0x0B
#define YAZIRENK_KIRMIZI	0x0C
#define YAZIRENK_MOR			0x0D
#define YAZIRENK_SARI		0x0E
#define YAZIRENK_BEYAZ		0x0F

#define ARKARENK_SIYAH		0x00
#define ARKARENK_MAVI		0x90
#define ARKARENK_YESIL		0xA0
#define ARKARENK_TURKUAZ	0xB0
#define ARKARENK_KIRMIZI	0xC0
#define ARKARENK_MOR		0xD0
#define ARKARENK_SARI		0xE0
#define ARKARENK_BEYAZ		0xF0



//yazdırma fonksiyonunun dizideki elemanlari okuma sekli yüzünden
//Genislik ve yukseklik asagidaki gibi belirtilmistir
namespace Grafik
{
	int renkOlustur(int yaziRengi, int arkaRenk);
	void sahneAyarla(int genislik, int yukseklik);
	int sahneYuksekligi();
	int sahneGenisligi();
	void pencereyiTasi(int x, int y);
	void karakterYaz(int x, int y, char karakter, int renk);
	void sahneyiCizdir();
	void sahneyiTemizle();
	void klavyeOku();
	bool tusBasilimi(char karakter);
	void kursoruGizle();
	
}
