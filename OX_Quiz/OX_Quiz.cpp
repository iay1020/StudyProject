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
O는 문제를 맞은 것이고, X는 문제를 틀린 것이다.
문제를 맞은 경우 그 문제의 점수는 그 문제까지 연속된 O의 개수가 된다.
1문제를 맞추면 1점 연속으로 2문제를 맞추면 2점 도중에 틀리면 0으로 초기화
첫째 줄 테스트 케이스 개수
길이는 0보다 크고 80보다 작은 문자열이고 문자열은 O와 X만 이루어져 있다.

이 문제를 풀면서 어려웠던 점은
cin을 이용해서 반복 횟수를 입력 받고
버퍼에 남아버린 \n을 해결하는게 가장 큰 문제였다.
버퍼에 남아버린 \n은 사라지지 않고 반복 횟수의 1개를 0을 출력함으로써 써버렸다.
이걸 해결하기 위해서 이전시간에 배웠던 cin.fail, cin.clear, cin.ignore 함수에 대해
다시 공부하게 되었고, 어떻게 기능하는지를 알게 되었기 때문에 결국에는 버퍼에 남아있던
\n을 지울 수 있게 되었다.

cin과 cout을 그냥 쓰는것과
cin.tie와 ios::sync_with_stdio를 같이 쓰는것과 4ms 정도 시간 차이가 났다.
*/
