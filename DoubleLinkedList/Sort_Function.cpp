
// 학번과 평균을 비교해서 정렬하는 함수
// 정렬 메뉴를 출력해서 그 값을 iMenu에 넣어서 같이 가지고 왔다
void Sort(PLIST pList, int iMenu)
{
	PNODE pNode = pList->pBegin->pNext;

	switch (iMenu)
	{
	case ST_NUMBER: // 학번 정렬 메뉴
		while (true)
		{
			PNODE pNode = pList->pBegin->pNext;
			for (int i = 0; i < pList->iSize; ++i)
			{
				while (pNode != NULL)
				{
					if (pNode->tStudent.iNumber == i + 1)
					{
						OutputStudent(&pNode->tStudent);
						break;
					}
					else
						pNode = pNode->pNext;
				}
				pNode = pList->pBegin->pNext;
			}
			cout << "학번 정렬 완료" << endl;
			system("pause");
			return;
		}

	case ST_AVERAGE: // 평균 정렬 메뉴
		int iBCount = 0;
		PNODE pNode = pList->pBegin->pNext;
		while (1)
		{
			if (pNode == pList->pEnd)
			{
				if (iBCount == 0)
				{
					pNode = pList->pBegin->pNext;
					while (pNode != pList->pEnd)
					{
						OutputStudent(&pNode->tStudent);
						pNode = pNode->pNext;
					}
					cout << "평균 정렬 완료\n";
					system("pause");
					return;
				}
				iBCount = 0;
				pNode = pList->pBegin->pNext;
			}

			else if (pNode->tStudent.fAvg < pNode->pNext->tStudent.fAvg)
			{

				PNODE pNode1 = pNode;
				PNODE pNode2 = pNode->pNext;
				PNODE pBPrev = pNode->pPrev;

				pNode->pPrev->pNext = pNode2;
				pNode->pNext = pNode2->pNext;
				pNode->pPrev = pNode2;
				pNode2->pNext = pNode1;
				pNode2->pPrev = pBPrev;
				pNode->pNext->pPrev = pNode1;

				++iBCount;
				pNode = pNode->pNext;
			}
			else
				pNode = pNode->pNext;
		}
	}
}

/*
아직 링크드 리스트를 배우는 도중이기도 해서, 실제 적용해서 코드를 만드는것에 어려움이 있었다.
처음에는 링크드 리스트의 그림을 보며 머리속에서 생각해보고 노트에 그림으로 그리면서 이해하려고 노력했다.
더블 링크드 리스트로 넘어가자 더 복잡해졌고, Next와 Prev의 값 두개가 필요했으며 각 각 연결이 되어야 했다.
이것 역시 그림으로 그려서 이해를 했다.
코드를 짜면서도 코드 한줄이 실행이 되면 그 노드의 Next값이 어떤것이 될지를 계속해서 그리면서 만들었다.
아무리 생각해도 모르겠을때는 정답을 보고 싶은 마음도 있었지만 그러지 않았다.
시간이 꽤 걸려서 풀어낸 문제지만, 그래도 내 힘으로 풀어냈다는 작은 성취감이 있었다.
많은 경험과 공부로 어떤 상황에서도 아이디어가 생각나도록 노력해야겠다.

학번 정렬 : 
계단 올라가면서 운동을 하다가 생각해낸 방법을 적용해서 만들었다.
학번을 1번부터 차례대로 출력하고 싶었기 때문에 그것에 관해 생각하다가 for문이 생각이 났다.
노드가 추가 될 때마다 Size를 추가 했으므로 for문을 그 횟수만큼 돌게 하고, i의 값은 1씩 증가하니
if문을 이용해서 i의 값과 같은 노드를 출력하기로 했던것이다.

만약 학번을 큰 순서대로 한다고 하더라도 i의 값을 노드 Size 값으로 주고 꺼꾸로 내려오면서 비교하면
될것 같다.


평균 정렬 :
너무 포기하고 싶게 만들었던 정렬이였다.
단순히 1번 노드와 2번 노드 비교를 한 뒤에 서로 위치는 바꾸는것으로는 끝나지 않았다.
그리고 노드의 위치르 바꾸면서 서로 재연결 시켜줘야 했는데, 이것에 대해 너무 실패를 많이 했다.
그림으로 그렸을때 각 노드마다 연결이 되어야하는것이 보이기는 했지만 코드로 구현하는것에는 
생각보다 다른 점이 많았다.
이것 역시 다른일을 하다가 생각난 아이디어로 풀어냈는데, 잠을 자기 전까지 고민하다가 
정렬을 할때마다 카운트를 줘서 정렬을 전혀 할 필요가 없을때까지 반복을 하자라는 생각을 했다.
모든 노드를 검사해서 크기 비교를 했고, 만약 비교를 하지 않고 빠져나왔다는건 정렬이 되었다고 생각했다.
노드들의 연결은 바꿔야하는 노드, 노드의 다음, 노드의 이전 총 3개의 주소를 담을 변수를 만들었다.
단순히 주소 하나만을 저장할 변수 하나로도 만들어 봤었는데, 도저히 지금 상황에서는 아이디어가 생각나지
않았다.
결국 각 위치를 저장해서 하나 하나 넣어줌으로써 노드의 재연결이 가능해졌다.
*/
