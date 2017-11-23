/******************************************************************************************************************
	C++ 프로그래밍 예제 - Wheel of Foortune Game
	사용자가 알파벳을 하나씩 입력하면서 문자열을 추리하는 프로그램
		- 문자열은 사전에 정해져있음
		- 횟수 제한 있음
		- 대소문자 구분함
******************************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

void main() {
	string default = "programming";
	string changing = "programming";
	string answer = "___________";
	char ch;
	int index;
	int count = 10;
	
	cout << "*************************************************************************" << endl;
	cout << "*			 WHEEL OF FORTUME GAME				*" << endl;
	cout << "*************************************************************************" << endl;
	cout << answer << " 에 들어갈 알파벳을 맞춰보세요!" << endl;
	while (default != answer && count > 0) {		// 알아내고자 하는 문자열과 만들어진 문자열이 같아질 때 까지 반복
		cout << "남은 기회 : " << count << endl;
		cout << "알파벳을 입력하세요 ";
		cin >> ch;						// 알파벳 하나 입력받음
		index = changing.find(ch);		// 문자열에서 위치를 찾아 반환

		if (index < 0) {				// ch가 문자열에 없으면
			cout << ch << " 는 없습니다. 다른 알파벳을 입력하세요" << endl;
		} else {								// 있는경우
			while (1) {							// 무한루프(문자열에서 모든 ch를 찾을 때 까지)
				if (index < 0) 	break;			// ch가 문자열에 없으면 루프 종료
				answer[index] = ch;				// 위치에 알파벳 삽입
				changing[index] = '_';			// 기존 문자열에서 제거
				index = changing.find(ch);		// 문자열에서 위치를 찾아 반환
			}
		}
		cout << answer << endl;
		count--;
	}	//문자열 찾아내거나 10번 루프 끝
	if (default == answer)	cout << "**********************축하합니다! 정답을 맞췄습니다**********************" << endl;
	else cout << "***************************아쉽지만 실패했습니다.***************************" << endl;
}