// pRA.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);		//메뉴출력
void MakeAccount(void);		//계좌개설을 위한 함수
void DepositMoney(void);	//입 금
void WithdrawMoney(void);	//출 금
void ShowAllAccInfo(void);	//잔액조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

typedef struct {
	int accID;					//계좌번호
	int balance;				//잔액
	char cusName[NAME_LEN];		//고객이름
} ACCOUNT;

ACCOUNT accARR[100];			//ACCOUNT 저장을 위한 배열
int accNUM = 0;					//저장된 ACCOUNT 수

int main()
{
	int choice;

	while (true) {
		ShowMenu();
		cout << "선택 : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
			break;
		default:
			cout << "1~5선택바람" << endl;
			break;
		}
	}
	return 0;
}
void ShowMenu(void) {
	cout << "----Menu----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4.계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}
void MakeAccount(void) {
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌 ID(숫자) : ";
	cin >> id;
	cout << "이름 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> balance;
	cout << endl;

	accARR[accNUM].accID = id;
	accARR[accNUM].balance = balance;
	strcpy(accARR[accNUM].cusName, name);
	accNUM++;
}
void DepositMoney(void) {
	int money;
	int id;
	cout << "[입 금]" << endl;
	cout << "계좌 ID : ";
	cin >> id;
	cout << "입금액 : ";
	cin >> money;

	for (int i = 0; i < accNUM; i++) {
		if (accARR[i].accID == id)
		{
			accARR[i].balance += money;
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl << endl;
}
void WithdrawMoney(void) {
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌 ID : ";
	cin >> id;
	cout << "출금액 : ";
	cin >> money;

	for (int i = 0; i < accNUM; i++) {
		if (accARR[i].accID == id)
		{
			if (accARR[i].balance < money) {
				cout << "잔액부족" << endl << endl;
				return;
			}
			accARR[i].balance -= money;
			cout << "출금 완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl << endl;
}
void ShowAllAccInfo(void) {
	for (int i = 0; i < accNUM; i++) {
		cout << "계좌ID : " << accARR[i].accID << endl;
		cout << "이 름 : " << accARR[i].cusName << endl;
		cout << "잔 액 : " << accARR[i].balance << endl << endl;
	}
}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.