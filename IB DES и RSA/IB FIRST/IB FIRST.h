
// IB FIRST.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CIBFIRSTApp:
// Сведения о реализации этого класса: IB FIRST.cpp
//

class CIBFIRSTApp : public CWinApp
{
public:
	CIBFIRSTApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()

	
};
void IP(unsigned char OTbuff[]);
void IPinv(unsigned char OTbuff[]);
void Ffunkcrypt(unsigned char R[], unsigned char Keyi[]);
void KeyP(unsigned char KeyBuff[]);
void KeyPinv(unsigned char Keyi[]);
int GCD(unsigned int a, unsigned int b);
int ext_GCD(unsigned int a, unsigned int b, int& x, int& y);
unsigned powmod(unsigned base, unsigned exp, unsigned modulo);
bool ferma(unsigned int x);
long long pows(long long a, long long b, long long m);
extern CIBFIRSTApp theApp;
