
// IB FIRSTDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "IB FIRST.h"
#include "IB FIRSTDlg.h"
#include "afxdialogex.h"

#include <iostream>
#include <iomanip>
#include <fstream>                          
#include <ctime>
#include <sstream>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <random>


// Диалоговое окно CIBFIRSTDlg



CIBFIRSTDlg::CIBFIRSTDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_IBFIRST_DIALOG, pParent)
	, IPT(_T(""))
	, OPT(_T(""))
	, Key(_T(""))
	, _n(_T(""))
	, _e(_T(""))
	, _d(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIBFIRSTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FILEIN, IPT);
	DDX_Text(pDX, IDC_EDIT_FILEOUT, OPT);
	DDX_Text(pDX, IDC_EDIT_KEY, Key);
	DDX_Text(pDX, IDC_EDIT3, _n);
	DDX_Text(pDX, IDC_EDIT2, _e);
	DDX_Text(pDX, IDC_EDIT1, _d);
}

BEGIN_MESSAGE_MAP(CIBFIRSTDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FILE_GET_IN, &CIBFIRSTDlg::OnBnClickedFileGetIn)
	ON_BN_CLICKED(IDC_FILE_OUT_IN, &CIBFIRSTDlg::OnBnClickedFileOutIn)
	ON_BN_CLICKED(IDC_FILE_GET_OUT, &CIBFIRSTDlg::OnBnClickedFileGetOut)
	ON_BN_CLICKED(IDC_FILE_OUT_OUT, &CIBFIRSTDlg::OnBnClickedFileOutOut)
	ON_BN_CLICKED(IDC_KEYIN, &CIBFIRSTDlg::OnBnClickedKeyin)
	ON_BN_CLICKED(IDC_KEYOUT, &CIBFIRSTDlg::OnBnClickedKeyout)
	ON_BN_CLICKED(IDC_KEY, &CIBFIRSTDlg::OnBnClickedKey)
	ON_BN_CLICKED(IDC_CRYPT, &CIBFIRSTDlg::OnBnClickedCrypt)
	ON_BN_CLICKED(IDC_DECRYPT, &CIBFIRSTDlg::OnBnClickedDecrypt)
	ON_BN_CLICKED(IDC_CRYPT_DES, &CIBFIRSTDlg::OnBnClickedCryptDes)
	ON_BN_CLICKED(IDC_DECRYPT_DES, &CIBFIRSTDlg::OnBnClickedDecryptDes)
	ON_BN_CLICKED(IDC_BUTTON3, &CIBFIRSTDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CIBFIRSTDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CIBFIRSTDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Обработчики сообщений CIBFIRSTDlg

BOOL CIBFIRSTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CIBFIRSTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CIBFIRSTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CIBFIRSTDlg::OnBnClickedFileGetIn() //считывание исходного текста с файла
{
	// TODO: добавьте свой код обработчика уведомлений
	setlocale(LC_ALL, "Russian");
	ifstream Filein("in.txt", ios_base::in);
	char simbol;

	// считываем из файла
	S = "\0";
	while (Filein.get(simbol)) {
		S += simbol;
	}

	// записываем в edit
	UpdateData(TRUE);
	IPT = S;
	UpdateData(FALSE);

	Filein.close();
}


void CIBFIRSTDlg::OnBnClickedFileOutIn() //запись исходного текста в файл
{
	// TODO: добавьте свой код обработчика уведомлений
	setlocale(LC_ALL, "Russian");
	UpdateData(TRUE);
	ofstream Filein("in.txt", ios_base::out | ios_base::trunc); // открыли файл,предварительно его очистив
	char simbol;
	for (int i = 0; i <= IPT.GetLength(); i++) {
		simbol = IPT[i];
		Filein << simbol;
	}
	Filein.close();
	UpdateData(FALSE);
}


void CIBFIRSTDlg::OnBnClickedFileGetOut() //считывание зашифр текста из файла
{
	// TODO: добавьте свой код обработчика уведомлений
	setlocale(LC_ALL, "Russian");
	ifstream Fileout("out.txt", ios_base::in);
	char simbol;

	// считываем из файла
	S = "\0";
	while (Fileout.get(simbol)) {
		S = S + simbol;
	}

	// записываем в edit
	UpdateData(TRUE);
	OPT = S;
	UpdateData(FALSE);

	Fileout.close();
}


void CIBFIRSTDlg::OnBnClickedFileOutOut() //запись зашифр текста в файл
{
	// TODO: добавьте свой код обработчика уведомлений
	setlocale(LC_ALL, "Russian");
	UpdateData(TRUE);
	ofstream Fileout("out.txt", ios_base::out | ios_base::trunc);
	char simbol;
	for (int i = 0; i <= OPT.GetLength(); i++) {
		simbol = OPT[i];
		Fileout << simbol;
	}
	Fileout.close();
	UpdateData(FALSE);
}


void CIBFIRSTDlg::OnBnClickedKeyin() //считывание ключа из файл
{
	// TODO: добавьте свой код обработчика уведомлений
	setlocale(LC_ALL, "Russian");
	ifstream FileKey("key.txt", ios_base::in);
	char simbol;

	// считываем из файла
	S = "\0";
	while (FileKey.get(simbol)) {
		S = S + simbol;
	}

	// записываем в edit
	UpdateData(TRUE);
	Key = S;
	UpdateData(FALSE);

	FileKey.close();
}


void CIBFIRSTDlg::OnBnClickedKeyout()  // запись ключа в файл
{
	// TODO: добавьте свой код обработчика уведомлений
	setlocale(LC_ALL, "Russian");
	UpdateData(TRUE);
	UpdateData(FALSE);
	ofstream FileKey("key.txt", ios_base::out | ios_base::trunc);
	char simbol;
	for (int i = 0; i <= Key.GetLength(); i++) {
		simbol = Key[i];
		FileKey << simbol;
	}
	FileKey.close();
}


void CIBFIRSTDlg::OnBnClickedKey() //генерация ключа
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(TRUE);///(содержимое эрана передается переменным элементов управления)
	srand(time(0));
	Key = '\0';

	int length = 8;
	int l = 0;
	bool check;
	string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int charsLength = chars.length();
	unsigned char simbol;
	for (int i = 0; i < length; i++) {
		//int randomIndex = rand() % (charsLength - 1);
		//Key += chars[randomIndex];;
		int randomIndex = rand() % 94 + 33;
		//simbol = (unsigned char)chars[randomIndex];
		simbol = (unsigned char)(randomIndex);
		for (int i = 0; i < 8; i++) {
			check = simbol & (1 << i); // получили значение бита в i-ой ячейке 
			if (check != 0) { l++; } // подсчет для четности
		}

		simbol &= ~(1 << 7); // занулили 8 бит

		if (l % 2 != 0) simbol |= 1 << 7; // записали единицу в 8 бит 
		l = 0;
		Key += (unsigned char)(simbol);
	}
	UpdateData(FALSE);
}


void CIBFIRSTDlg::OnBnClickedCrypt() //шифрование xor
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(TRUE);
	int KeyLength = Key.GetLength();
	string res("0", IPT.GetLength() + ((KeyLength - (IPT.GetLength() % KeyLength)) % KeyLength));
	for (int i = 0; i < res.length(); i++)
	{
		if (i < IPT.GetLength()) {
			res[i] = (unsigned char)(IPT[i] ^ Key[i % KeyLength]);
		}
		else {
			res[i] = (unsigned char)(Key[i % KeyLength]);
		}

	}
	OPT = res.c_str();
	UpdateData(FALSE);
}


void CIBFIRSTDlg::OnBnClickedDecrypt() //дешифрование xor
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(TRUE);
	int KeyLength = Key.GetLength();
	string res("0", OPT.GetLength() + ((KeyLength - (OPT.GetLength() % KeyLength)) % KeyLength));
	for (int i = 0; i < res.length(); i++)
	{
		if (i < OPT.GetLength()) {
			res[i] = (unsigned char)(OPT[i] ^ Key[i % KeyLength]);
			/*if (OPT[i] && Key[i % KeyLength]) res[i] = (unsigned char)0;
			else if (OPT[i] || Key[i % KeyLength]) res[i] = (unsigned char)1;
			else res[i] = (unsigned char)0;*/
		}
		else {
			res[i] = (unsigned char)(Key[i % KeyLength]);
		}

	}
	IPT = res.c_str();
	UpdateData(FALSE);
}

char* w2c(char* pcstr, const wchar_t* pwstr, size_t len)
{
	int nlength = wcslen(pwstr);
	//Gets the converted length
	int nbytes = WideCharToMultiByte(0, 0, pwstr, nlength, NULL, 0, NULL, NULL);
	if (nbytes > len)   nbytes = len;
	//With the results obtained above, convert unicode characters to ASCII characters
	WideCharToMultiByte(0, 0, pwstr, nlength, pcstr, nbytes, NULL, NULL);
	return pcstr;
}


void CIBFIRSTDlg::OnBnClickedCryptDes()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(TRUE);
	unsigned char L[32], R[48];
	unsigned char Lnext[32], Rnext[48];
	unsigned char IPTBitBlock[64], KeyBitBlock[64], KeyBitDec1[16][56]; // переменные,чтобы не изменять IPTBit,KeyBit
	unsigned char Keyi[56];// раундовый ключ
	unsigned char C[28], D[28];


	//////////////////////////////////////////////////// переводим наш текст и ключ в битовые вектора 
	unsigned char sim[8];
	int buff;
	int c; // счетчик,чтобы исключить ситуацию,когда меньше 8 бит

	int l = IPT.GetLength();
	wchar_t* vIn = IPT.GetBuffer();
	char* vOut = new char[wcslen(vIn) + 1];
	vOut[wcslen(vIn)] = '\0';
	w2c(vOut, vIn, l);


	for (int i = 0; i < wcslen(vIn)/*IPT.GetLength()*/; i++) {
		c = 0; buff = (unsigned int)(vOut[i]);//присваивание номера символа из таблицы ASCII

		do {
			sim[c] = buff % 2 + '0';
			buff /= 2;
			c++;
		} while (buff > 1);
		sim[c] = buff + '0';
		c++;
		while (c != 8) {
			sim[c] = '0';
			c++;
		}

		for (int j = 7; j >= 0; j--) {
			IPTBit.push_back(sim[j]);
		}

	}// получили битовый вектор нашего открытого текста

	for (int i = 0; i < Key.GetLength(); i++) {
		c = 0; buff = (unsigned int)(Key[i]);

		do {
			sim[c] = buff % 2 + '0';
			buff /= 2;
			c++;
		} while (buff > 1);
		sim[c] = buff + '0';
		c++;

		while (c != 8) {
			sim[c] = '0';
			c++;
		}

		for (int j = 7; j >= 0; j--) {
			KeyBit.push_back(sim[j]);
		}

		for (int j = 0; j <= 7; j++) {
			KeyBitBlock[j + i * 8] = KeyBit[j + i * 8];

		}
	}// получили битовый вектор нашего ключа*/


	int add = (KeyBit.size() - (IPTBit.size() % KeyBit.size())) % KeyBit.size(); // добавка,чтобы текст был кратен блокам

	for (int k = 0; k < IPTBit.size() + add; k += 64) {// разбиваем на блоки по 64 бит

		for (int i = 0; i < 64; i++) { // если блок и ключ не кратны ,то в последние биты записывает нули
			if (k + i < IPTBit.size()) {
				IPTBitBlock[i] = IPTBit[i + k];
			}
			else {
				//IPTBitBlock[i] = KeyBit[i % KeyBit.size()];
				IPTBitBlock[i] = '0';
			}
		}

		IP(IPTBitBlock); // начальная перестановка

		for (int j = 0; j < 64; j++) { // разбиваем блок на правую и левую части
			if (j < 32) {
				L[j] = IPTBitBlock[j];
			}
			else {
				R[j - 32] = IPTBitBlock[j];
			}
		}

		KeyP(KeyBitBlock);// 64->56

		for (int i = 0; i < 56; i++) { // разбиваем ключ на правую и левую части
			if (i < 28) {
				C[i] = KeyBitBlock[i];
			}
			else {
				D[i - 28] = KeyBitBlock[i];
			}
		}

		for (int i = 1; i <= 16; i++) { // преобразование Фейстеля

			// циклический сдвиг
			int f = 2;
			if ((i == 1) || (i == 2) || (i == 9) || (i == 16)) f = 1;
			do {
				unsigned char u = C[0];
				unsigned char o = D[0];
				for (int i1 = 1; i1 < 28; i1++) { // циклический сдвиг 
					C[i1 - 1] = C[i1];
					D[i1 - 1] = D[i1];
				}
				C[27] = u;
				D[27] = o;
				f--;
			} while (f != 0);

			for (int j = 0; j < 56; j++) { // собираем левую и правую части в раундовый ключ
				if (j < 28) {
					Keyi[j] = C[j];
					KeyBitDec1[i - 1][j] = C[j];
				}
				else {
					Keyi[j] = D[j - 28];
					KeyBitDec1[i - 1][j] = D[j - 28];
				}

			}

			KeyPinv(Keyi);// 56->48

			for (int j = 0; j < 32; j++) { // правую часть кладем в левую
				Lnext[j] = R[j];
			}

			Ffunkcrypt(R, Keyi);

			for (int j = 0; j < 32; j++) {
				// левую часть с ислючающим "или" кладем в правую 
				/*if (L[j] && R[j]) Rnext[j] = false;
				else if (L[j] || R[j]) Rnext[j] = true;
				else Rnext[j] = false;*/
				Rnext[j] = (L[j] - '0') ^ (R[j] - '0') + '0';

			}

			for (int j = 0; j < 32; j++) {
				L[j] = Lnext[j];
				R[j] = Rnext[j];
			}
		}

		// собираем левую и правую части 
		for (int j = 0; j < 64; j++) {
			if (j < 32) {
				IPTBitBlock[j] = L[j];
			}
			else {
				IPTBitBlock[j] = R[j - 32];
			}
		}

		IPinv(IPTBitBlock);

		// заносим зашифрованный текст во временный OTbuff 
		for (int i = 0; i < 64; i++) {
			OPTbuff.push_back(IPTBitBlock[i]);
		}
	}
	//OPTbuff.push_back('\0');
	OPT = "\0";
	UpdateData(TRUE);


	OPT = "\0";
	// переводим получившуюся строку из битов символов в 10 СС ,т.е. из битов получаем символы
	int des;
	for (int i = 0; i < IPTBit.size() + add; i += 8) {
		des = 0;
		for (int j = 0; j < 8; j++) {
			des += pow(2, 7 - j) * (OPTbuff[i + j] - '0');
		}
		//выводим окончательный результат
		OPT += (unsigned char)(des);
	}
	//OPT = OPTbuff.data();

	UpdateData(FALSE);

	IPTBit.clear();
	KeyBit.clear();


}


void CIBFIRSTDlg::OnBnClickedDecryptDes()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(TRUE);
	unsigned char L[48], R[32];
	unsigned char Lnext[48], Rnext[32];
	unsigned char OPTBitBlock[64], KeyBitBlock[64], KeyBitDec[16][56]; // переменные,чтобы не изменять OPTBit,KeyBit
	unsigned char Keyi[56];// раундовый ключ
	unsigned char C[28], D[28];


	// переводим наш текст и ключ в битовые вектора 
	unsigned char sim[8];
	int buff;
	int c; // счетчик,чтобы исключить ситуацию,когда меньше 8 бит
	/*
	for (int i = 0; i < OPT.GetLength(); i++) {
		c = 0; buff = (unsigned int)(OPT[i]);
		do {
			sim[c] = buff % 2 + '0';
			buff /= 2;
			c++;
		} while (buff > 1);
		sim[c] = buff + '0';
		c++;
		while (c != 8) {
			sim[c] = '0';
			c++;
		}
		for (int j = 7; j >= 0; j--) {
			OPTBit.push_back(sim[j]);
		}
	}*/


	for (int i = 0; i < Key.GetLength(); i++) {
		c = 0; buff = (unsigned int)(Key[i]);
		do {
			sim[c] = buff % 2 + '0';
			buff /= 2;
			c++;
		} while (buff > 1);
		sim[c] = buff + '0';
		c++;
		while (c != 8) {
			sim[c] = '0';
			c++;
		}
		for (int j = 7; j >= 0; j--) {
			KeyBit.push_back(sim[j]);
		}
		for (int j = 0; j <= 7; j++) {
			KeyBitBlock[j + i * 8] = KeyBit[j + i * 8];

		}
	}// получили битовый вектор нашего ключа
	/// ////////////////////////////////////////////////


	//int add = (KeyBit.size() - (OPTBit.size() % KeyBit.size())) % KeyBit.size(); // добавка,чтобы текст был кратен блокам

	int add = (KeyBit.size() - (OPTbuff.size() % KeyBit.size())) % KeyBit.size(); // добавка,чтобы текст был кратен блокам
	for (int k = 0; k < OPTbuff.size() + add; k += 64) {// разбиваем на блоки по 64 бит

		for (int i = 0; i < 64; i++) { // если блок и ключ не кратны ,то в последние биты записывает биты ключа
			if (k + i < OPTbuff.size()) {
				OPTBitBlock[i] = OPTbuff[i + k];
				//OPTBitBlock[i] = OPTBit[i];
			}
			else {
				//OPTBitBlock[i] = KeyBit[i % KeyBit.size()];
				OPTBitBlock[i] = '0';
			}
		}

		IP(OPTBitBlock); // начальная перестановка

		for (int j = 0; j < 64; j++) { // разбиваем блок на правую и левую части
			if (j < 32) {
				L[j] = OPTBitBlock[j];
			}
			else {
				R[j - 32] = OPTBitBlock[j];
			}
		}

		KeyP(KeyBitBlock);

		for (int i = 0; i < 56; i++) { // разбиваем ключ на правую и левую части
			if (i < 28) {
				C[i] = KeyBitBlock[i];
			}
			else {
				D[i - 28] = KeyBitBlock[i];
			}
		}

		for (int i = 1; i <= 16; i++) { // преобразование Фейстеля

			// циклический сдвиг
			int f = 2;
			if ((i == 1) || (i == 2) || (i == 9) || (i == 16)) f = 1;
			do {
				unsigned char u = C[0];
				unsigned char o = D[0];
				for (int i1 = 1; i1 < 28; i1++) { // циклический сдвиг 
					C[i1 - 1] = C[i1];
					D[i1 - 1] = D[i1];
				}
				C[27] = u;
				D[27] = o;
				f--;
			} while (f != 0);

			for (int j = 0; j < 56; j++) { // собираем левую и правую части в раундовый ключ
				if (j < 28) {
					Keyi[j] = C[j];
					KeyBitDec[i - 1][j] = C[j];
				}
				else {
					Keyi[j] = D[j - 28];
					KeyBitDec[i - 1][j] = D[j - 28];
				}

			}
		}
		for (int i = 16; i >= 1; i--) {

			for (int j = 0; j < 56; j++) {
				Keyi[j] = KeyBitDec[i - 1][j];
			}

			KeyPinv(Keyi);

			for (int j = 0; j < 32; j++) { // правую часть кладем в левую
				Rnext[j] = L[j];
			}

			Ffunkcrypt(L, Keyi);

			for (int j = 0; j < 32; j++) {
				// левую часть с ислючающим"или" кладем в правую 
				Lnext[j] = (L[j] - '0') ^ (R[j] - '0') + '0';
				/*if (L[j] && R[j]) Lnext[j] = false;
				else if (L[j] || R[j]) Lnext[j] = true;
				else Lnext[j] = false;*/
			}

			for (int j = 0; j < 32; j++) {
				L[j] = Lnext[j];
				R[j] = Rnext[j];
			}
		}

		// собираем левую и правую части 
		for (int j = 0; j < 64; j++) {
			if (j < 32) {
				OPTBitBlock[j] = L[j];
			}
			else {
				OPTBitBlock[j] = R[j - 32];
			}
		}

		IPinv(OPTBitBlock);

		// заносим зашифрованный текст во временный PTbuff 
		for (int i = 0; i < 64; i++) {
			IPTbuff.push_back(OPTBitBlock[i]);
		}
	}
	//IPTbuff.push_back('\0');
	IPT = '\0';
	UpdateData(TRUE);
	IPT = '\0';
	std::vector<unsigned char> ipt;
	// переводим получившуюся строку из битов символов с 10 СС ,т.е. из битов получаем символы
	int des;
	for (int i = 0; i < OPTbuff.size() + add; i += 8) {
		des = 0;
		for (int j = 0; j < 8; j++) {
			des += pow(2, 7 - j) * (IPTbuff[i + j] - '0');
		}
		//выводим окончательный результат
		ipt.push_back((unsigned char)(des));
	}
	IPT = CString(ipt.data());
	UpdateData(FALSE);

	OPTBit.clear();
	KeyBit.clear();
	OPTBit.clear();

}


void CIBFIRSTDlg::OnBnClickedButton3()
{
	// TODO: добавьте свой код обработчика уведомлений
	unsigned int p, q;
	unsigned int c = pow(2, 15);

	srand(time(NULL));
	do {
		p = rand() % (c * 2) + c;
		if (!(p % 2)) { p--; }
	} while ((ferma(p) == false));

	do {
		q = rand() % (c * 2) + c;
		if (!(q % 2)) { q--; }
	} while ((ferma(q) == false) || (q == p));

	n = p * q; // получили два простых p и q

	//генерируем число e
	int x, y;
	unsigned int fi = (p - 1) * (q - 1);
	do {
		e = rand() % fi; // сгенерировали число меньше фи 

	} while (ext_GCD(fi, e, x, y) != 1);

	//генерируем число d
	if (y < 0) { d = fi + y; }
	else { d = y; }

	//------------------------------- выводим на экран
	UpdateData(TRUE);
	string S1 = to_string(n);
	string S2 = to_string(e);
	string S3 = to_string(d);

	_n = S1.c_str();
	_e = S2.c_str();
	_d = S3.c_str();

	UpdateData(FALSE);
}


void CIBFIRSTDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(TRUE);
	OPT = '\0';
	unsigned int num;
	string Str, S;
	for (int i = 0; i < IPT.GetLength(); i++) {
		num = pows((unsigned int)(IPT[i]), e, n);
		S = to_string(num);
		Str += S;
		Str += ' ';
	}
	OPT = Str.c_str();
	UpdateData(FALSE);

}


void CIBFIRSTDlg::OnBnClickedButton2()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(TRUE);
	IPT = '\0';
	unsigned long int num;
	string S, S1;
	int j = 1;
	for (int i = 0; i < OPT.GetLength(); i++) {
		if (OPT[i] != ' ') {
			j++;
			if (j <= 5) {
				S += (unsigned char)(OPT[i]);
			}
			else {
				S1 += (unsigned char)(OPT[i]);
			}

		}
		else {
			if (j <= 5) {
				num = stoi(S);
			}
			else {
				num = stoi(S) * pow(10, (j - 5)) + stoi(S1);
			}
			num = pows(num, d, n);
			IPT += (char)(num);
			S = ""; j = 1; S1 = "";
		}
	}


	UpdateData(FALSE);

}
