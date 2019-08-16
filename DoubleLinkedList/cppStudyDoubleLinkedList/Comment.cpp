/*
Linked List에 이어 Double Linked List를 배우고 있다.
그림으로 계속 그리면서 이해를 하면서 노력을 하고 있다.
단순히 공식 외우듯이 외우는것 같은 느낌이라서 확실히 이해 하고 갔으면 좋겠다.
Begin과 End를 서로 연결 시키면서 시작 하고,
데이터를 입력 받은 후
Prev에 End의 Prev값을 넣는다. 
Prev는 Begin의 주소값을 가지고 있기에 Begin 그 자체라고 생각하기로 했다.
Prev->Next에는 데이터가 담긴 현재 pNode의 주소를 넣고,
pNode->Prev에는 Prev의 값을 넣는다.
Begin과 pNode가 연결 되었다.
pNode->Next에는 End의 주소를
End->Prev는 Pnode의 주소를 넣어준다.
Begin과 Pnode가 서로 연결되고, Pnode와 End가 서로 연결된다.

 두개 이상에서(여기선 main과 List.cpp) 헤더 파일을 끌어다 쓸 경우 링크 에러가 뜰 수 있다
 그럴땐 헤더 파일에서 static을 붙여주면 main과 list.cpp 모두 obj가 생기고
오류가 없어진다?
 InputInt와 IntputString 두 함수 앞에 붙여줬더니 사라짐

 헤더에다 저런식으로? 다 구현할꺼면 static 해두는게 좋다

 
숙제 : 현재 구성되어 있는 학생관리프로그램 메인 메뉴에 정렬 기능을 추가한다.
정렬 기준은 학번, 평균 기준으로 오름차순으로 정렬할 수 있는 기능을 만들어보자.

*/