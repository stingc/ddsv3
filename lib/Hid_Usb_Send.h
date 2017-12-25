// Hid_Usb_Send.h : Hid_Usb_Send DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CHid_Usb_SendApp
// �йش���ʵ�ֵ���Ϣ������� Hid_Usb_Send.cpp
//

extern "C" _declspec(dllexport) int ReadCard(byte*PEmpNo);
extern "C" _declspec(dllexport) int Readblock(int PEmpBlockNo,byte*PEmpSectorPassword,byte*PEmpBlockdata);
extern "C" _declspec(dllexport) int bell(byte pEmptimes);
extern "C" _declspec(dllexport) int Writeblock(int PEmpBlockNo,byte*PEmpSectorPassword,byte*PEmpBlockdata);


extern "C" _declspec(dllexport) int BPWD_Readblock(int PEmpBlockNo,byte*PEmpSectorPassword,byte*PEmpBlockdata);
extern "C" _declspec(dllexport) int BPWD_Writeblock(int PEmpBlockNo,byte*PEmpSectorPassword,byte*PEmpBlockdata);



extern "C" _declspec(dllexport) int FindDevCnt(int*GetDevCnt);

extern "C" _declspec(dllexport) int ReadCard_No(byte*PEmpNo,int com_no);
extern "C" _declspec(dllexport) int Readblock_No(int PEmpBlockNo,byte*PEmpSectorPassword,byte*PEmpBlockdata,int com_no);
extern "C" _declspec(dllexport) int bell_No(byte pEmptimes,int com_no);
extern "C" _declspec(dllexport) int Writeblock_No(int PEmpBlockNo,byte*PEmpSectorPassword,byte*PEmpBlockdata,int com_no);

extern "C" _declspec(dllexport) int BPWD_Readblock_No(int PEmpBlockNo,byte*PEmpSectorPassword,byte*PEmpBlockdata,int com_no);
extern "C" _declspec(dllexport) int BPWD_Writeblock_No(int PEmpBlockNo,byte*PEmpSectorPassword,byte*PEmpBlockdata,int com_no);



extern "C" _declspec(dllexport) int ControlBuzzer(byte pEmptimes);
extern "C" _declspec(dllexport) BOOL OpenComport(DWORD port, unsigned long baudrate);
extern "C" _declspec(dllexport) void CloseComport();
extern "C" _declspec(dllexport) BOOL ReadVersion(BYTE* ver);
extern "C" _declspec(dllexport) int ReadSerialNo(BYTE* sn);
extern "C" _declspec(dllexport) int ReadBlockData(unsigned char *sn,    //	Ӳ��̖
unsigned char blkNo,           //	Ҫ��ȡ�Ŀ��
unsigned char keyType,         //	�ܴa����(KeyA,KeyB)
unsigned char *keyValue,       //	�ܴa����
unsigned char *pdata); 
extern "C" _declspec(dllexport) int WriteBlockData(unsigned char *sn,             //	Ӳ����
unsigned char blkNo,           //	Ҫ��ȡ�Ŀ��
unsigned char keyType,         //	�ܴa����(KeyA,KeyB)
unsigned char *keyValue,       //	�ܴa����
unsigned char *pdata); 
extern "C" _declspec(dllexport) int ReadSectorData(unsigned char *sn,    //	Ӳ����
unsigned char secNo,           //	Ҫ��ȡ��������
unsigned char keyType,         //	�ܴa����(KeyA,KeyB)
unsigned char *keyValue,       //	�ܴa����
unsigned char *pdata); 
extern "C" _declspec(dllexport) int WriteSectorData(unsigned char *sn,             //	Ӳ����
unsigned char secNo,           //	Ҫ��ȡ��������
unsigned char keyType,         //	�ܴa����(KeyA,KeyB)
unsigned char *keyValue,       //	�ܴa����
unsigned char *pdata); 





class CHid_Usb_SendApp : public CWinApp
{
public:
	CHid_Usb_SendApp();

// ��д
public:
	virtual BOOL InitInstance();





	DECLARE_MESSAGE_MAP()







};



