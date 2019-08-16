
// �й��� ����� ���ؼ� �����ϴ� �Լ�
// ���� �޴��� ����ؼ� �� ���� iMenu�� �־ ���� ������ �Դ�
void Sort(PLIST pList, int iMenu)
{
	PNODE pNode = pList->pBegin->pNext;

	switch (iMenu)
	{
	case ST_NUMBER: // �й� ���� �޴�
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
			cout << "�й� ���� �Ϸ�" << endl;
			system("pause");
			return;
		}

	case ST_AVERAGE: // ��� ���� �޴�
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
					cout << "��� ���� �Ϸ�\n";
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
���� ��ũ�� ����Ʈ�� ���� �����̱⵵ �ؼ�, ���� �����ؼ� �ڵ带 ����°Ϳ� ������� �־���.
ó������ ��ũ�� ����Ʈ�� �׸��� ���� �Ӹ��ӿ��� �����غ��� ��Ʈ�� �׸����� �׸��鼭 �����Ϸ��� ����ߴ�.
���� ��ũ�� ����Ʈ�� �Ѿ�� �� ����������, Next�� Prev�� �� �ΰ��� �ʿ������� �� �� ������ �Ǿ�� �ߴ�.
�̰� ���� �׸����� �׷��� ���ظ� �ߴ�.
�ڵ带 ¥�鼭�� �ڵ� ������ ������ �Ǹ� �� ����� Next���� ����� ������ ����ؼ� �׸��鼭 �������.
�ƹ��� �����ص� �𸣰������� ������ ���� ���� ������ �־����� �׷��� �ʾҴ�.
�ð��� �� �ɷ��� Ǯ� ��������, �׷��� �� ������ Ǯ��´ٴ� ���� ���밨�� �־���.
���� ����� ���η� � ��Ȳ������ ���̵� ���������� ����ؾ߰ڴ�.

�й� ���� : 
��� �ö󰡸鼭 ��� �ϴٰ� �����س� ����� �����ؼ� �������.
�й��� 1������ ���ʴ�� ����ϰ� �;��� ������ �װͿ� ���� �����ϴٰ� for���� ������ ����.
��尡 �߰� �� ������ Size�� �߰� �����Ƿ� for���� �� Ƚ����ŭ ���� �ϰ�, i�� ���� 1�� �����ϴ�
if���� �̿��ؼ� i�� ���� ���� ��带 ����ϱ�� �ߴ����̴�.

���� �й��� ū ������� �Ѵٰ� �ϴ��� i�� ���� ��� Size ������ �ְ� ���ٷ� �������鼭 ���ϸ�
�ɰ� ����.


��� ���� :
�ʹ� �����ϰ� �Ͱ� ������� �����̿���.
�ܼ��� 1�� ���� 2�� ��� �񱳸� �� �ڿ� ���� ��ġ�� �ٲٴ°����δ� ������ �ʾҴ�.
�׸��� ����� ��ġ�� �ٲٸ鼭 ���� �翬�� ������� �ߴµ�, �̰Ϳ� ���� �ʹ� ���и� ���� �ߴ�.
�׸����� �׷����� �� ��帶�� ������ �Ǿ���ϴ°��� ���̱�� ������ �ڵ�� �����ϴ°Ϳ��� 
�������� �ٸ� ���� ���Ҵ�.
�̰� ���� �ٸ����� �ϴٰ� ������ ���̵��� Ǯ��´µ�, ���� �ڱ� ������ ����ϴٰ� 
������ �Ҷ����� ī��Ʈ�� �༭ ������ ���� �� �ʿ䰡 ���������� �ݺ��� ���ڶ�� ������ �ߴ�.
��� ��带 �˻��ؼ� ũ�� �񱳸� �߰�, ���� �񱳸� ���� �ʰ� �������Դٴ°� ������ �Ǿ��ٰ� �����ߴ�.
������ ������ �ٲ���ϴ� ���, ����� ����, ����� ���� �� 3���� �ּҸ� ���� ������ �������.
�ܼ��� �ּ� �ϳ����� ������ ���� �ϳ��ε� ����� �þ��µ�, ������ ���� ��Ȳ������ ���̵� ��������
�ʾҴ�.
�ᱹ �� ��ġ�� �����ؼ� �ϳ� �ϳ� �־������ν� ����� �翬���� ����������.
*/
