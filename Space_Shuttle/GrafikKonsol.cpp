#include "GrafikKonsol.hpp"
#include<iostream>
using namespace std;
namespace Grafik
{
	SMALL_RECT consoleWriteArea;
	CHAR_INFO* sahneHucreleri;
	COORD bufferSize;
	int genislik;
	int yukseklik;
	char tuslar[256];
	int renkOlustur(int yaziRengi, int arkaRenk)
	{
		return yaziRengi | arkaRenk;
	}
	void sahneAyarla(int gen, int yuk)
	{
		kursoruGizle();
		genislik = gen;
		yukseklik = yuk;

		consoleWriteArea.Left = 0;
		consoleWriteArea.Right = genislik - 1;
		consoleWriteArea.Top = 0;
		consoleWriteArea.Bottom = yukseklik - 1;

		bufferSize.X = genislik;
		bufferSize.Y = yukseklik;
		
		pencereyiTasi(0, 0);
		SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &consoleWriteArea);

		SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);


		WINDOWINFO wInfo;
		GetWindowInfo(GetConsoleWindow(), &wInfo);
		int a = wInfo.rcWindow.right - wInfo.rcWindow.left;
		int b = wInfo.rcClient.right - wInfo.rcClient.left;
		cout << a <<"-"<<b<< endl;
		int diziBoyutu = genislik * yukseklik;
		sahneHucreleri = new CHAR_INFO[diziBoyutu];


	}
	void karakterYaz(int x, int y, char karakter, int renk)
	{
		sahneHucreleri[y * genislik + x].Char.AsciiChar = karakter;
		sahneHucreleri[y * genislik + x].Attributes = renk;
	}
	bool tusBasilimi(char karakter)
	{
		return tuslar[karakter];
	}
	void klavyeOku()
	{
		
		for (int x = 0; x < 256; x++) {
			tuslar[x] = (char)(GetAsyncKeyState(x) >> 8);
			
		}
			
	}
	void sahneyiTemizle()
	{
		for (int i = 0; i < yukseklik; i++)
		{
			for (int j = 0; j < genislik; j++)
			{
				int index = i * genislik + j;
				sahneHucreleri[index].Char.AsciiChar = 0;
				sahneHucreleri[index].Attributes = 0;
			}
		}
	}
	void sahneyiCizdir()
	{

		WriteConsoleOutputA(GetStdHandle(STD_OUTPUT_HANDLE),
			sahneHucreleri,
			bufferSize,
			{ 0,0 },
			&consoleWriteArea);
	}

	int sahneYuksekligi()
	{
		return yukseklik;
	}
	int sahneGenisligi()
	{
		return genislik;
	}
	void pencereyiTasi(int x, int y)
	{
		WINDOWINFO wInfo;
		GetWindowInfo(GetConsoleWindow(), &wInfo);
		 
		MoveWindow(GetConsoleWindow(),
			x, y,
			wInfo.rcWindow.right - wInfo.rcWindow.left,
			wInfo.rcWindow.bottom - wInfo.rcWindow.top, true);
	}
	void kursoruGizle()
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_CURSOR_INFO     cursorInfo;

		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = false;
		SetConsoleCursorInfo(out, &cursorInfo);
	}
}
