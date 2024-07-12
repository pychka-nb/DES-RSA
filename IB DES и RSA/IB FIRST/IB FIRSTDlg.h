
// IB FIRSTDlg.h: файл заголовка
//

#pragma once
#include <vector>

using namespace std;
// Диалоговое окно CIBFIRSTDlg
class CIBFIRSTDlg : public CDialogEx
{
// Создание
public:
	CIBFIRSTDlg(CWnd* pParent = nullptr);	// стандартный конструктор
	
	












// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IBFIRST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFileGetIn();
	
	CString S;//вспомогательный буффер
	CString IPT;
	CString OPT;
	CString Key;

	vector<unsigned char> OPTBit;
	vector<unsigned char> IPTBit;
	vector<unsigned char> KeyBit; vector<unsigned char> OPTbuff; vector<unsigned char> IPTbuff;
	
	afx_msg void OnBnClickedFileOutIn();
	afx_msg void OnBnClickedFileGetOut();
	afx_msg void OnBnClickedFileOutOut();
	afx_msg void OnBnClickedKeyin();
	afx_msg void OnBnClickedKeyout();
	afx_msg void OnBnClickedKey();
	afx_msg void OnBnClickedCrypt();
	afx_msg void OnBnClickedDecrypt();
	afx_msg void OnBnClickedCryptDes();
	afx_msg void OnBnClickedDecryptDes();
	unsigned int n, e, d;
	CString _n;
	CString _e;
	CString _d;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
