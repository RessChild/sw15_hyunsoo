#include<iostream>
using namespace std;
// �ֻ��� ����

int check[6]; //6���� �ֻ��� ���� Ƚ��
int main() {
	for (int k = 0; k < 3; k++) {
		int num;
		cin >> num;
		check[num - 1]++;
	}

	int flag = 0; //���õ� ����� ����
	int select; //���� ��
	int count = 0;
	for (int i = 0; count != 3;i++) { //3��¥���� �� �� ����
		switch (check[i])
		{
		case 1:
			flag = 1;
			select = i + 1;
			count++;
			break;
		case 2:
			flag = 2;
			select = i + 1;
			count = 3; //������ ��. ��������
			break;
		case 3:
			flag = 3;
			select = i + 1;
			count = 3; //������ ��, ��������
			break;
		default:
			break;
		}
	}

	int val = 0;
	switch (flag) {
	case 1:
		val = select * 100;
		break;
	case 2:
		val = 1000 + select * 100;
		break;
	case 3:
		val = 10000 + select * 1000;
		break;
	default:
		break;
	}
	
	cout << val << endl;
}