// ----------------------------------------------------------------
// Copyright (c)  
// All rights reserved.
// 
// File name:	ResMultFolder.h
// File mark:   
// File summary:���ڹ�������DMDesigner����Դ��Ҫ�༭����Դ
// Author:		guoyouhuang
// Edition:     1.0
// Create date: 2016-7-8
// ----------------------------------------------------------------
#pragma once
#include "ResFolder.h"
/// <summary>
///		���ļ��й���,0�ļ���Ϊ�����������Դ(ȫ��ds_��ͷ),1�ļ���ΪҪ�༭����Դ
/// </summary>
typedef ResFolder* ResFolderPtr;
class ResMultFolder: public IDMRes,public DMArrayT<ResFolderPtr>
{
	DMDECLARE_CLASS_NAME(ResMultFolder,"ResMultFolder",DMREG_Res);
public:
	ResMultFolder();
	~ResMultFolder();

public:
	virtual DMCode LoadResPack(WPARAM wp, LPARAM lp);
	virtual DMCode IsItemExists(LPCSTR lpszType, LPCSTR lpszName, LPCSTR lpszThemeName=NULL);
	virtual DMCode GetItemSize(LPCSTR lpszType, LPCSTR lpszName, unsigned long& ulSize, LPCSTR lpszThemeName=NULL);
	virtual LPCWSTR GetItemPath(LPCSTR lpszType, LPCSTR lpszName, LPCSTR lpszThemeName);
	virtual DMCode GetItemBuf(LPCSTR lpszType, LPCSTR lpszName, DMBufT<byte>&, PULONG lpULSize, LPCSTR lpszThemeName = NULL);
	virtual DMCode LoadTheme(WPARAM wp, LPARAM lp);
	virtual DMCode SetCurTheme(LPCSTR lpszName, LPCSTR lpszOldName=NULL);
	virtual DMCode SendExpandInfo(WPARAM wp, LPARAM lp);

protected:
	virtual void PreArrayObjRemove(const ResFolderPtr &obj);
	bool IsDMDesignerRes(const char* pszName);
	ResFolderPtr GetResFolderPtr(const char* pszName);
};