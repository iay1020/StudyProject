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
		cout << "파일 만들기 성공:" << endl;
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

	cout << "파일 읽기 성공\n";
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
		cout << "1. 새로만들기\n";
		cout << "2. 이어하기\n";
		cout << "3. 종료하기\n";
		cout << "입력 : ";
		iLogin = InputInt();

		if (iLogin == LM_EXIT)
			pbID = false;

		if (iLogin < LM_NEW_ID || iLogin > LM_EXIT)
			continue;

		

		switch (iLogin)
		{
		case LM_NEW_ID:

			system("cls");
			cout << "====== 회원 가입 =====\n";
			cout << "아이디 : ";
			cin.ignore(1024, '\n');
			cin.getline(PlayerID.strID, ID_SIZE);
			cout << "비밀번호 : ";
			cin >> PlayerID.iPW;

			CreateID(&PlayerID);
			LoadID();

			break;

		case LM_LOAD_ID:
			cout << "아이디   : ";
			cin.getline(PlayerID.strID, ID_SIZE);

			cout << "비밀번호 : ";
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
1. 로그인 화면 
2. 아이디 / 비밀번호를 DB에서 찾는다.
3. 만약 있다면, 서버 선택창 출력

*/