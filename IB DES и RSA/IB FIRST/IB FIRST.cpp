
// IB FIRST.cpp: определяет поведение классов для приложения.
//

#include "pch.h"
#include "framework.h"
#include "IB FIRST.h"
#include "IB FIRSTDlg.h"
#include <vector>
#include <iostream>
#include <iomanip>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;
// CIBFIRSTApp

BEGIN_MESSAGE_MAP(CIBFIRSTApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Создание CIBFIRSTApp

CIBFIRSTApp::CIBFIRSTApp()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CIBFIRSTApp

CIBFIRSTApp theApp;


// Инициализация CIBFIRSTApp

BOOL CIBFIRSTApp::InitInstance()
{
	// InitCommonControlsEx() требуется для Windows XP, если манифест
	// приложения использует ComCtl32.dll версии 6 или более поздней версии для включения
	// стилей отображения.  В противном случае будет возникать сбой при создании любого окна.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Выберите этот параметр для включения всех общих классов управления, которые необходимо использовать
	// в вашем приложении.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// Создать диспетчер оболочки, в случае, если диалоговое окно содержит
	// представление дерева оболочки или какие-либо его элементы управления.
	CShellManager* pShellManager = new CShellManager;

	// Активация визуального диспетчера "Классический Windows" для включения элементов управления MFC
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Стандартная инициализация
	// Если эти возможности не используются и необходимо уменьшить размер
	// конечного исполняемого файла, необходимо удалить из следующих
	// конкретных процедур инициализации, которые не требуются
	// Измените раздел реестра, в котором хранятся параметры
	// TODO: следует изменить эту строку на что-нибудь подходящее,
	// например на название организации
	SetRegistryKey(_T("Локальные приложения, созданные с помощью мастера приложений"));

	CIBFIRSTDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Введите код для обработки закрытия диалогового окна
		//  с помощью кнопки "ОК"
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Введите код для обработки закрытия диалогового окна
		//  с помощью кнопки "Отмена"
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Предупреждение. Не удалось создать диалоговое окно, поэтому работа приложения неожиданно завершена.\n");
		TRACE(traceAppMsg, 0, "Предупреждение. При использовании элементов управления MFC для диалогового окна невозможно #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Удалить диспетчер оболочки, созданный выше.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// Поскольку диалоговое окно закрыто, возвратите значение FALSE, чтобы можно было выйти из
	//  приложения вместо запуска генератора сообщений приложения.
	return FALSE;
}

void IP(unsigned char OTbuff[]) { //начальная перестановка IP
	// OTbuff = OTBitBlock
	unsigned char OTbb[64];

	for (int i = 0; i < 64; i++) {
		OTbb[i] = OTbuff[i];
	}
	OTbuff[0] = OTbb[57];
	OTbuff[1] = OTbb[49];
	OTbuff[2] = OTbb[41];
	OTbuff[3] = OTbb[33];
	OTbuff[4] = OTbb[25];
	OTbuff[5] = OTbb[17];
	OTbuff[6] = OTbb[9];
	OTbuff[7] = OTbb[1];
	OTbuff[8] = OTbb[59];
	OTbuff[9] = OTbb[51];
	OTbuff[10] = OTbb[43];
	OTbuff[11] = OTbb[35];
	OTbuff[12] = OTbb[27];
	OTbuff[13] = OTbb[19];
	OTbuff[14] = OTbb[11];
	OTbuff[15] = OTbb[3];
	OTbuff[16] = OTbb[61];
	OTbuff[17] = OTbb[53];
	OTbuff[18] = OTbb[45];
	OTbuff[19] = OTbb[37];
	OTbuff[20] = OTbb[29];
	OTbuff[21] = OTbb[21];
	OTbuff[22] = OTbb[13];
	OTbuff[23] = OTbb[5];
	OTbuff[24] = OTbb[63];
	OTbuff[25] = OTbb[55];
	OTbuff[26] = OTbb[47];
	OTbuff[27] = OTbb[39];
	OTbuff[28] = OTbb[31];
	OTbuff[29] = OTbb[23];
	OTbuff[30] = OTbb[15];
	OTbuff[31] = OTbb[7];
	OTbuff[32] = OTbb[56];
	OTbuff[33] = OTbb[48];
	OTbuff[34] = OTbb[40];
	OTbuff[35] = OTbb[32];
	OTbuff[36] = OTbb[24];
	OTbuff[37] = OTbb[16];
	OTbuff[38] = OTbb[8];
	OTbuff[39] = OTbb[0];
	OTbuff[40] = OTbb[58];
	OTbuff[41] = OTbb[50];
	OTbuff[42] = OTbb[42];
	OTbuff[43] = OTbb[34];
	OTbuff[44] = OTbb[26];
	OTbuff[45] = OTbb[18];
	OTbuff[46] = OTbb[10];
	OTbuff[47] = OTbb[2];
	OTbuff[48] = OTbb[60];
	OTbuff[49] = OTbb[52];
	OTbuff[50] = OTbb[44];
	OTbuff[51] = OTbb[36];
	OTbuff[52] = OTbb[28];
	OTbuff[53] = OTbb[20];
	OTbuff[54] = OTbb[12];
	OTbuff[55] = OTbb[4];
	OTbuff[56] = OTbb[62];
	OTbuff[57] = OTbb[54];
	OTbuff[58] = OTbb[46];
	OTbuff[59] = OTbb[38];
	OTbuff[60] = OTbb[30];
	OTbuff[61] = OTbb[22];
	OTbuff[62] = OTbb[14];
	OTbuff[63] = OTbb[6];

}

void E(unsigned char R[]) { //функия расширения E правой части с 32 до 48 бит
	unsigned char Rb[32];

	for (int i = 0; i < 32; i++) {
		Rb[i] = R[i];
	}
	R[0] = Rb[31];
	R[1] = Rb[0];
	R[2] = Rb[1];
	R[3] = Rb[2];
	R[4] = Rb[3];
	R[5] = Rb[4];
	R[6] = Rb[3];
	R[7] = Rb[4];
	R[8] = Rb[5];
	R[9] = Rb[6];
	R[10] = Rb[7];
	R[11] = Rb[8];
	R[12] = Rb[7];
	R[13] = Rb[8];
	R[14] = Rb[9];
	R[15] = Rb[10];
	R[16] = Rb[11];
	R[17] = Rb[12];
	R[18] = Rb[11];
	R[19] = Rb[12];
	R[20] = Rb[13];
	R[21] = Rb[14];
	R[22] = Rb[15];
	R[23] = Rb[16];
	R[24] = Rb[15];
	R[25] = Rb[16];
	R[26] = Rb[17];
	R[27] = Rb[18];
	R[28] = Rb[19];
	R[29] = Rb[20];
	R[30] = Rb[19];
	R[31] = Rb[20];
	R[32] = Rb[21];
	R[33] = Rb[22];
	R[34] = Rb[23];
	R[35] = Rb[24];
	R[36] = Rb[23];
	R[37] = Rb[24];
	R[38] = Rb[25];
	R[39] = Rb[26];
	R[40] = Rb[27];
	R[41] = Rb[28];
	R[42] = Rb[27];
	R[43] = Rb[28];
	R[44] = Rb[29];
	R[45] = Rb[30];
	R[46] = Rb[31];
	R[47] = Rb[0];

}

// получение первого индекса S-блока
int DES1(unsigned char& value1, unsigned char& value2) {
	int result1 = 0;
	if (value1 == '1') result1 += 2;
	if (value2 == '1') result1 += 1;
	return result1;
}

//получение второго индекса S-блока
int DES2(unsigned char& value1, unsigned char& value2, unsigned char& value3, unsigned char& value4) {
	int result1 = 0;
	if (value1 == '1')result1 += 8;
	if (value2 == '1')result1 += 4;
	if (value3 == '1')result1 += 2;
	if (value4 == '1')result1 += 1;
	return result1;
}

// перевод из десятичной СС в двоичную СС
void DES(unsigned char result[], int value,int q1) {
	// перевод в двоичную СС
	/*for (int i = 0; i < 4; i++) {//получаем обратное двоичное число в векторе
		result.push_back(value % 2+'0');
		value /= 2;
	}
	// разворачиваем вектор
	for (int i = 0; i < 2; i++) {
		unsigned char temp = result[result.size() - i - 1];
		result[result.size() - i - 1] = result[result.size() - 4 + i];
		result[result.size() - 4 + i] = temp;
	}*/
	
	for (int i = 0; i < 4; i++) {//получаем обратное двоичное число в векторе
		result[i + q1]=value % 2 + '0';
		value /= 2;
	}
	for (int i = 0; i < 2; i++) {
		swap(result[i + q1], result[3 - i + q1]);
	}

}

// подстановка - S-блоки
void S_Blocks(unsigned char res[], unsigned char R[]) {
	int S1[4][16] = {
		{ 14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7},
		{  0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8 },
		{  4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0 },
		{ 15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13 } };
	int S2[4][16] = {
		{ 15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10 },
		{  3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5 },
		{  0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15 },
		{ 13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9 } };
	int S3[4][16] = {
		{ 10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8 },
		{ 13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1 },
		{ 13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7 },
		{  1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12 } };
	int S4[4][16] = {
		{  7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15 },
		{ 13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9 },
		{ 10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4 },
		{  3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14 } };
	int S5[4][16] = {
		{  2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9 },
		{ 14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6 },
		{  4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14 },
		{ 11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10 , 4,  5,  3 } };
	int S6[4][16] = {
		{ 12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11 },
		{ 10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8 },
		{  9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6 },
		{  4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13 } };
	int S7[4][16] = {
		{  4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1 },
		{ 13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6 },
		{  1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2 },
		{  6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12 } };
	int S8[4][16] = {
		{ 13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7 },
		{  1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2 },
		{  7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8 },
		{  2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11 } };



	//vector<unsigned char> result;
	unsigned char result[32];
	unsigned char S_block[8][6];

	// разбиение на 8 блоков
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 6; j++) {
			S_block[i][j] = res[i * 6 + j];

		}
	}

	// подстановка в блоки
	int q1 = 0;
	DES(result, S1[DES1(S_block[0][0], S_block[0][5])][DES2(S_block[0][1], S_block[0][2], S_block[0][3], S_block[0][4])], q1);
	q1 = q1 + 4;
    DES(result, S2[DES1(S_block[1][0], S_block[1][5])][DES2(S_block[1][1], S_block[1][2], S_block[1][3], S_block[1][4])], q1);
	q1 = q1 + 4;
	DES(result, S3[DES1(S_block[2][0], S_block[2][5])][DES2(S_block[2][1], S_block[2][2], S_block[2][3], S_block[2][4])], q1);
	q1 = q1 + 4;
	DES(result, S4[DES1(S_block[3][0], S_block[3][5])][DES2(S_block[3][1], S_block[3][2], S_block[3][3], S_block[3][4])], q1);
	q1 = q1 + 4;
	DES(result, S5[DES1(S_block[4][0], S_block[4][5])][DES2(S_block[4][1], S_block[4][2], S_block[4][3], S_block[4][4])], q1);
	q1 = q1 + 4;
	DES(result, S6[DES1(S_block[5][0], S_block[5][5])][DES2(S_block[5][1], S_block[5][2], S_block[5][3], S_block[5][4])], q1);
	q1 = q1 + 4;
	DES(result, S7[DES1(S_block[6][0], S_block[6][5])][DES2(S_block[6][1], S_block[6][2], S_block[6][3], S_block[6][4])], q1);
	q1 = q1 + 4;
	DES(result, S8[DES1(S_block[7][0], S_block[7][5])][DES2(S_block[7][1], S_block[7][2], S_block[7][3], S_block[7][4])], q1);

	for (int i = 0; i < 32; i++) {
		R[i] = result[i];
	}
}

void PP(unsigned char R[]) { //конечная перестановка для полчучения функции шифрования после S - блоков 
	unsigned char Rb[32];

	for (int i = 0; i < 32; i++) {
		Rb[i] = R[i];
	}
	R[0] = Rb[15];
	R[1] = Rb[6];
	R[2] = Rb[19];
	R[3] = Rb[20];
	R[4] = Rb[28];
	R[5] = Rb[11];
	R[6] = Rb[27];
	R[7] = Rb[16];
	R[8] = Rb[0];
	R[9] = Rb[14];
	R[10] = Rb[22];
	R[11] = Rb[25];
	R[12] = Rb[4];
	R[13] = Rb[17];
	R[14] = Rb[30];
	R[15] = Rb[9];
	R[16] = Rb[1];
	R[17] = Rb[7];
	R[18] = Rb[23];
	R[19] = Rb[13];
	R[20] = Rb[31];
	R[21] = Rb[26];
	R[22] = Rb[2];
	R[23] = Rb[8];
	R[24] = Rb[18];
	R[25] = Rb[12];
	R[26] = Rb[29];
	R[27] = Rb[5];
	R[28] = Rb[21];
	R[29] = Rb[10];
	R[30] = Rb[3];
	R[31] = Rb[24];
}
void Ffunkcrypt(unsigned char R[], unsigned char Keyi[]) { //функция шифрования 
	unsigned char res[48];
	E(R);

	for (int i = 0; i < 48; i++) {
		res[i] = (R[i] - '0') ^ (Keyi[i] - '0') + '0';
		//if (Keyi[i] && R[i]) res[i] = false;
		//else if (Keyi[i] || R[i]) res[i] = true;
		//else res[i] = false;
	}

	S_Blocks(res, R);


	PP(R);
}
void KeyP(unsigned char KeyBuff[]) { //подготовка 56-битового ключа 
	unsigned char Keybb[64];

	for (int i = 0; i < 64; i++) {
		Keybb[i] = KeyBuff[i];
	}
	KeyBuff[0] = Keybb[56];
	KeyBuff[1] = Keybb[48];
	KeyBuff[2] = Keybb[40];
	KeyBuff[3] = Keybb[32];
	KeyBuff[4] = Keybb[24];
	KeyBuff[5] = Keybb[16];
	KeyBuff[6] = Keybb[8];
	KeyBuff[7] = Keybb[0];
	KeyBuff[8] = Keybb[57];
	KeyBuff[9] = Keybb[49];
	KeyBuff[10] = Keybb[41];
	KeyBuff[11] = Keybb[33];
	KeyBuff[12] = Keybb[25];
	KeyBuff[13] = Keybb[17];
	KeyBuff[14] = Keybb[9];
	KeyBuff[15] = Keybb[1];
	KeyBuff[16] = Keybb[58];
	KeyBuff[17] = Keybb[50];
	KeyBuff[18] = Keybb[42];
	KeyBuff[19] = Keybb[34];
	KeyBuff[20] = Keybb[26];
	KeyBuff[21] = Keybb[18];
	KeyBuff[22] = Keybb[10];
	KeyBuff[23] = Keybb[2];
	KeyBuff[24] = Keybb[59];
	KeyBuff[25] = Keybb[51];
	KeyBuff[26] = Keybb[43];
	KeyBuff[27] = Keybb[35];
	KeyBuff[28] = Keybb[62];
	KeyBuff[29] = Keybb[54];
	KeyBuff[30] = Keybb[46];
	KeyBuff[31] = Keybb[38];
	KeyBuff[32] = Keybb[30];
	KeyBuff[33] = Keybb[22];
	KeyBuff[34] = Keybb[14];
	KeyBuff[35] = Keybb[6];
	KeyBuff[36] = Keybb[61];
	KeyBuff[37] = Keybb[53];
	KeyBuff[38] = Keybb[45];
	KeyBuff[39] = Keybb[37];
	KeyBuff[40] = Keybb[29];
	KeyBuff[41] = Keybb[21];
	KeyBuff[42] = Keybb[13];
	KeyBuff[43] = Keybb[5];
	KeyBuff[44] = Keybb[60];
	KeyBuff[45] = Keybb[52];
	KeyBuff[46] = Keybb[44];
	KeyBuff[47] = Keybb[36];
	KeyBuff[48] = Keybb[28];
	KeyBuff[49] = Keybb[20];
	KeyBuff[50] = Keybb[12];
	KeyBuff[51] = Keybb[4];
	KeyBuff[52] = Keybb[27];
	KeyBuff[53] = Keybb[19];
	KeyBuff[54] = Keybb[11];
	KeyBuff[55] = Keybb[3];

}

void KeyPinv(unsigned char KeyBuff[]) { //завершающая обработка ключа 
	unsigned char Keybb[56];

	for (int i = 0; i < 56; i++) {
		Keybb[i] = KeyBuff[i];
	}
	KeyBuff[0] = Keybb[13];
	KeyBuff[1] = Keybb[16];
	KeyBuff[2] = Keybb[10];
	KeyBuff[3] = Keybb[23];
	KeyBuff[4] = Keybb[0];
	KeyBuff[5] = Keybb[4];
	KeyBuff[6] = Keybb[2];
	KeyBuff[7] = Keybb[27];
	KeyBuff[8] = Keybb[14];
	KeyBuff[9] = Keybb[5];
	KeyBuff[10] = Keybb[20];
	KeyBuff[11] = Keybb[9];
	KeyBuff[12] = Keybb[22];
	KeyBuff[13] = Keybb[18];
	KeyBuff[14] = Keybb[11];
	KeyBuff[15] = Keybb[3];
	KeyBuff[16] = Keybb[25];
	KeyBuff[17] = Keybb[7];
	KeyBuff[18] = Keybb[15];
	KeyBuff[19] = Keybb[6];
	KeyBuff[20] = Keybb[26];
	KeyBuff[21] = Keybb[19];
	KeyBuff[22] = Keybb[12];
	KeyBuff[23] = Keybb[1];
	KeyBuff[24] = Keybb[40];
	KeyBuff[25] = Keybb[51];
	KeyBuff[26] = Keybb[30];
	KeyBuff[27] = Keybb[36];
	KeyBuff[28] = Keybb[46];
	KeyBuff[29] = Keybb[54];
	KeyBuff[30] = Keybb[29];
	KeyBuff[31] = Keybb[39];
	KeyBuff[32] = Keybb[50];
	KeyBuff[33] = Keybb[44];
	KeyBuff[34] = Keybb[32];
	KeyBuff[35] = Keybb[47];
	KeyBuff[36] = Keybb[43];
	KeyBuff[37] = Keybb[48];
	KeyBuff[38] = Keybb[38];
	KeyBuff[39] = Keybb[55];
	KeyBuff[40] = Keybb[33];
	KeyBuff[41] = Keybb[52];
	KeyBuff[42] = Keybb[45];
	KeyBuff[43] = Keybb[41];
	KeyBuff[44] = Keybb[49];
	KeyBuff[45] = Keybb[35];
	KeyBuff[46] = Keybb[28];
	KeyBuff[47] = Keybb[31];
}

void IPinv(unsigned char OTbuff[]) { //конечная перестановка IP-1
	unsigned char OTbb[64];

	for (int i = 0; i < 64; i++) {
		OTbb[i] = OTbuff[i];
	}
	OTbuff[0] = OTbb[39];
	OTbuff[1] = OTbb[7];
	OTbuff[2] = OTbb[47];
	OTbuff[3] = OTbb[15];
	OTbuff[4] = OTbb[55];
	OTbuff[5] = OTbb[23];
	OTbuff[6] = OTbb[63];
	OTbuff[7] = OTbb[31];
	OTbuff[8] = OTbb[38];
	OTbuff[9] = OTbb[6];
	OTbuff[10] = OTbb[46];
	OTbuff[11] = OTbb[14];
	OTbuff[12] = OTbb[54];
	OTbuff[13] = OTbb[22];
	OTbuff[14] = OTbb[62];
	OTbuff[15] = OTbb[30];
	OTbuff[16] = OTbb[37];
	OTbuff[17] = OTbb[5];
	OTbuff[18] = OTbb[45];
	OTbuff[19] = OTbb[13];
	OTbuff[20] = OTbb[53];
	OTbuff[21] = OTbb[21];
	OTbuff[22] = OTbb[61];
	OTbuff[23] = OTbb[29];
	OTbuff[24] = OTbb[36];
	OTbuff[25] = OTbb[4];
	OTbuff[26] = OTbb[44];
	OTbuff[27] = OTbb[12];
	OTbuff[28] = OTbb[52];
	OTbuff[29] = OTbb[20];
	OTbuff[30] = OTbb[60];
	OTbuff[31] = OTbb[28];
	OTbuff[32] = OTbb[35];
	OTbuff[33] = OTbb[3];
	OTbuff[34] = OTbb[43];
	OTbuff[35] = OTbb[11];
	OTbuff[36] = OTbb[51];
	OTbuff[37] = OTbb[19];
	OTbuff[38] = OTbb[59];
	OTbuff[39] = OTbb[27];
	OTbuff[40] = OTbb[34];
	OTbuff[41] = OTbb[2];
	OTbuff[42] = OTbb[42];
	OTbuff[43] = OTbb[10];
	OTbuff[44] = OTbb[50];
	OTbuff[45] = OTbb[18];
	OTbuff[46] = OTbb[58];
	OTbuff[47] = OTbb[26];
	OTbuff[48] = OTbb[33];
	OTbuff[49] = OTbb[1];
	OTbuff[50] = OTbb[41];
	OTbuff[51] = OTbb[9];
	OTbuff[52] = OTbb[49];
	OTbuff[53] = OTbb[17];
	OTbuff[54] = OTbb[57];
	OTbuff[55] = OTbb[25];
	OTbuff[56] = OTbb[32];
	OTbuff[57] = OTbb[0];
	OTbuff[58] = OTbb[40];
	OTbuff[59] = OTbb[8];
	OTbuff[60] = OTbb[48];
	OTbuff[61] = OTbb[16];
	OTbuff[62] = OTbb[56];
	OTbuff[63] = OTbb[24];

}


// НОД (Алгоритм Евклида)
int GCD(unsigned int a, unsigned int b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

// НОД (Расширенный алгоритм Евклида)
// Функция вычисляет НОД и находит целочисленные коэффициенты x и y для уравнения ax + by = НОД(a, b).
int ext_GCD(unsigned int a, unsigned int b, int& x, int& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = ext_GCD(b % a, a, x1, y1);//рекурсия
	x = y1 - (b / a) * x1;
	y = x1;
	return d;//НОД
}


// ---------------------------------------------------

// Функция умножения двух чисел с использованием алгоритма "быстрого возведения в степень".
long long mul(long long a, long long b, long long m) {
	if (b == 1)
		return a;
	if (b % 2 == 0) {
		long long t = mul(a, b / 2, m);
		return (2 * t) % m;
	}
	return (mul(a, b - 1, m) + a) % m;   //Если b нечетное, функция рекурсивно вызывается для b - 1, результат прибавляется к a и берется по модулю m.
}

// быстрое возведение в степень по модулю 
long long pows(long long a, long long b, long long m) {
	if (b == 0)
		return 1;
	if (b % 2 == 0) {
		//Если b четное, функция вызывает саму себя для b / 2, результат умножается на себя и берется по модулю m.
		long long t = pows(a, b / 2, m);
		return mul(t, t, m) % m;
	}
	return (mul(pows(a, b - 1, m), a, m)) % m;   //Если b нечетное, функция вызывает саму себя для b - 1, результат умножается на a и берется по модулю m.
}

// проверка на простоту
bool ferma(unsigned int x) {
	if (x == 2)
		return true;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		unsigned int a = (rand() % (x - 2)) + 2;
		if (GCD(a, x) != 1)
			return false;
		if (pows(a, x - 1, x) != 1)
			return false;
	}
	return true;
}

