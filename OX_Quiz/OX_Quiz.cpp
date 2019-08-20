#include<iostream>
using namespace std;
#define OX_MAX 80
int main()
{
	int iInput;
	cin >> iInput;
	cin.ignore(1024, '\n');
	char cValue[OX_MAX] = {};
	int iOXCount = 0, iScore = 0;;
	for (int i = 0; i < iInput; ++i)
	{
		cin.tie(NULL);
		cin.getline(cValue, OX_MAX);

		for (int j = 0; cValue[j] != NULL; ++j)
		{
			if (cValue[j] != NULL)
			{
				if (cValue[j] == 'O')
				{
					iOXCount += 1;
					iScore += iOXCount;
				}
				else if (cValue[j] == 'X')
				{
					iOXCount = 0;
				}
			}
		}
		ios::sync_with_stdio(false);
		cout << iScore << "\n";
		iScore = 0;
		iOXCount = 0;
	}
	return 0;
}

/*
O�� ������ ���� ���̰�, X�� ������ Ʋ�� ���̴�.
������ ���� ��� �� ������ ������ �� �������� ���ӵ� O�� ������ �ȴ�.
1������ ���߸� 1�� �������� 2������ ���߸� 2�� ���߿� Ʋ���� 0���� �ʱ�ȭ
ù° �� �׽�Ʈ ���̽� ����
���̴� 0���� ũ�� 80���� ���� ���ڿ��̰� ���ڿ��� O�� X�� �̷���� �ִ�.

�� ������ Ǯ�鼭 ������� ����
cin�� �̿��ؼ� �ݺ� Ƚ���� �Է� �ް�
���ۿ� ���ƹ��� \n�� �ذ��ϴ°� ���� ū ��������.
���ۿ� ���ƹ��� \n�� ������� �ʰ� �ݺ� Ƚ���� 1���� 0�� ��������ν� ����ȴ�.
�̰� �ذ��ϱ� ���ؼ� �����ð��� ����� cin.fail, cin.clear, cin.ignore �Լ��� ����
�ٽ� �����ϰ� �Ǿ���, ��� ����ϴ����� �˰� �Ǿ��� ������ �ᱹ���� ���ۿ� �����ִ�
\n�� ���� �� �ְ� �Ǿ���.

cin�� cout�� �׳� ���°Ͱ�
cin.tie�� ios::sync_with_stdio�� ���� ���°Ͱ� 4ms ���� �ð� ���̰� ����.
*/
