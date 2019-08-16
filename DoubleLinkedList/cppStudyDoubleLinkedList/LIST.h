
// #pragma once : �� ��������� �� 1���� ���Խ�Ű�ڴ� ��� �ǹ�
#pragma once

#include<iostream>

using namespace std;

enum OUTPUT_TYPE
{
	OT_NONE,
	OT_OUTPUT,
	OT_INVERSE
};

// ������Ͽ��� ���� �Լ� ����κ��� ������ش�.
#define NAME_SIZE 32

typedef struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
}STUDENT, * PSTUDENT;

typedef struct _tagNode
{
	STUDENT tStudent;
	_tagNode* pNext;
	_tagNode* pPrev;
}NODE, * PNODE;

typedef struct _tagList
{
	// pBegin�� pEnd�� ���������� ó���� ���� �ǹ��ϵ��� �����. ���� �����͸� �����ϴ�
	// ���� �ƴϴ�. ���� �����͸� �����ϴ� ���� pBegin�� pEnd ���̿� �����ϰ� ������ش�.
	PNODE pBegin;
	PNODE pEnd;
	int iSize;
}LIST, * PLIST;

static int InputInt()
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}
	return iInput;
}

static void InputString(char* pString, int iSize)
{
	cin.clear();
	cin.ignore(1024, '\n');
	// ���ڿ��� ���� �˸��� Null�� ������ ���� -1
	cin.getline(pString, iSize - 1);
}

void InitList(PLIST pList);
//void CleartList(PLIST pList);
void DestroyList(PLIST pList);
void Push_Back(PLIST pList);
void Push_Front(PLIST pList);
void OutputStudent(const PSTUDENT pStudent);
void Output(PLIST pList);
void Search(PLIST pList);
void Delete(PLIST pList);