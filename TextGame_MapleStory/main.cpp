#include<iostream>
using namespace std;

enum Login_MENU
{
	LM_NONE,
	LM_NEW_ID,
	LM_LOAD_ID,
	LM_EXIT
};

#define ID_SIZE 32

typedef struct PlayerID
{
	char strID[ID_SIZE];
	int iPW;
}PLAYERID, * PPLAYERID;

int InputInt()
{
	int iInput;

	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return iInput;
	}

	return iInput;
}

void CreateID(PPLAYERID pPlayerID)
{
	FILE* pFile = NULL;

	fopen_s(&pFile, "UserDB.txt", "wt");

	if (pFile != NULL)
	{
		fwrite(pPlayerID, sizeof(PLAYERID), 1, pFile);

		fclose(pFile);
		cout << "���� ����� ����:" << endl;
		system("pause");
	}
}

void LoadID()
{
	PLAYERID pPlayer;

	FILE* pFile = NULL;

	fopen_s(&pFile, "UserDB.txt", "rt");

	if (pFile != NULL)
	{
		fread(&pPlayer, sizeof(PLAYERID), 1, pFile);

		fclose(pFile);
	}

	cout << "���� �б� ����\n";
	cout << pPlayer.strID << "\n";
	cout << pPlayer.iPW << "\n";
	system("pause");
}

void LoginScreen(bool *pbID)
{
	PLAYERID PlayerID;

	int iLogin = 0;

	while (pbID)
	{
		system("cls");
		cout << "===== Maple Story =====\n";
		cout << "1. ���θ����\n";
		cout << "2. �̾��ϱ�\n";
		cout << "3. �����ϱ�\n";
		cout << "�Է� : ";
		iLogin = InputInt();

		if (iLogin == LM_EXIT)
			pbID = false;

		if (iLogin < LM_NEW_ID || iLogin > LM_EXIT)
			continue;

		

		switch (iLogin)
		{
		case LM_NEW_ID:

			system("cls");
			cout << "====== ȸ�� ���� =====\n";
			cout << "���̵� : ";
			cin.ignore(1024, '\n');
			cin.getline(PlayerID.strID, ID_SIZE);
			cout << "��й�ȣ : ";
			cin >> PlayerID.iPW;

			CreateID(&PlayerID);
			LoadID();

			break;

		case LM_LOAD_ID:
			cout << "���̵�   : ";
			cin.getline(PlayerID.strID, ID_SIZE);

			cout << "��й�ȣ : ";
			cin >> PlayerID.iPW;

			break;
		}
	}

}

int main()
{
	bool bID = true;

	LoginScreen(&bID);

	if (!bID)
		return 0;


	return 0;
}










/*
Text RPG Game
[Maple Story]
1. �α��� ȭ�� 
2. ���̵� / ��й�ȣ�� DB���� ã�´�.
3. ���� �ִٸ�, ���� ����â ���

*/