#include<iostream>
#include<time.h>
using namespace std;
int main()
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

	cout << "*\t*\t*\n";

	int iStrike = 0, iBall = 0, iGameCount = 1;
	int iInput[3] = {};

	while (1)
	{
		cout << iGameCount << "번째\n";
		cout << "숫자 3개를 입력 하세요(종료:0) : ";
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		iStrike = iBall = 0;
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

					break;
				}
			}
		}

		if (iStrike == 0 && iBall == 0)
			cout << "아웃\n";

		else if (iStrike == 3)
		{
			cout << "3 스트라이크\n";
			break;
		}
		else
			cout << iStrike << " strike " << iBall << " ball \n";

		++iGameCount;
	}

	return 0;
}