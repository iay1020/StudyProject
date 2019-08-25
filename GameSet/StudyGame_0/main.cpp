#include<iostream>
#include<time.h>
using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_START,
	MM_EXIT
};

enum GAME_MENU
{
	GM_NONE,
	GM_BASEBALL,
	GM_NUMBERPUZZLE,
	GM_BINGO,
	GM_EXIT
};

int Inputint()
{
	int iInput;

	while (true)
	{
		cin >> iInput;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			return 0;
		}
		else
			break;
	}
	return iInput;
}

int Main_Menu()
{
	int iMenu = 0;

	while (iMenu != MM_EXIT)
	{
		system("cls");
		cout << "==================================\n\n";
		cout << "\t[ MAIN MENU ] \n\n";
		cout << "\t1. START\n";
		cout << "\t2. EXIT\n\n";
		cout << "==================================\n\n";
		cout << "메뉴를 선택해주세요.\n";
		cout << "Enter : ";
		iMenu = Inputint();

		if (iMenu < MM_START || iMenu > MM_EXIT)
			continue;

		else
			return iMenu;
	}
	return iMenu;
}

int Game_Menu()
{
	int iGameMenu = 0;

	while (iGameMenu != GM_EXIT)
	{
		system("cls");
		cout << "==================================\n\n";
		cout << "\t[ GAME MENU ] \n\n";
		cout << "\t1. Base Ball\n";
		cout << "\t2. Number Puzzle\n";
		cout << "\t3. Bingo\n";
		cout << "\t4. Exit\n\n";
		cout << "==================================\n\n";
		cout << "게임를 선택해주세요.\n";
		cout << "Enter : ";
		iGameMenu = Inputint();

		if (iGameMenu < GM_BASEBALL || iGameMenu > GM_EXIT)
			continue;

		else
			return iGameMenu;
	}
	return iGameMenu;
}

void Game_BaseBall()
{
	srand((unsigned)time(0));

	int iNumber[9] = {};

	for (int i = 0; i < 9; ++i)
	{
		iNumber[i] = i + 1;
	}

	int iTemp = 0, idx1 = 0, idx2 = 0;

	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	while (true)
	{
		system("cls");
		cout << "====================================================\n\n";
		cout << "\t   [ BASE BALL ]\n\n";
		cout << "\t[ *\t *\t* ]\n\n";

		int iInput[3] = {};
		cout << "범위 : 1 ~ 9, 종료 : 0, 서로 다른수를 입력하세요.\n";
		cout << "숫자 3개를 입력하세요 : ";
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
			break;

		else if (iInput[0] == iInput[1] || iInput[0] == iInput[2] ||
			iInput[1] == iInput[2])
			continue;

		else if (iInput[0] < 1 || iInput[0] > 9 || iInput[1] < 1 || iInput[1] > 9 ||
			iInput[2] < 1 || iInput[2] > 9)
			continue;

		int iStrike = 0, iBall = 0;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (iNumber[i] == iInput[j])
				{
					if (i == j)
						++iStrike;
					else
						++iBall;
				}
			}
		}

		if (iStrike == 0 && iBall == 0)
			cout << "Out!!!!!!!!!!\n";

		else if (iStrike == 3)
		{
			cout << "3 Strike !!!!!!!!!\n";
			cout << "Win ~ \n";
			system("pause");
			break;
		}

		else
			cout << iStrike << " strike " << iBall << " ball \n";

		system("pause");
		iStrike = iBall = 0;
	}
	
}

int main()
{
	int iInput;
	iInput = Main_Menu();

	if (iInput == MM_EXIT)
		return 0;

	iInput = Game_Menu();

	if (iInput == GM_EXIT)
		return 0;

	switch (iInput)
	{
	case GM_BASEBALL:
		Game_BaseBall();
		iInput = Main_Menu();
		break;
	case GM_NUMBERPUZZLE:
		break;
	case GM_BINGO:
		break;
	}

	return 0;
}