#include<iostream>
using namespace std;
// �л�ó��

#define DIV 10 


int T, A, B;

int main() {
	cin >> T;
	for (int k = 0; k < T; k++) {
		cin >> A >> B;

		int ans = 1;
		for (int k = 1; k <= B; k++) {
			ans *= A;
			ans = ans % DIV;
		}
		cout << (ans ? ans : 10) << endl;
		// 1~9 ������ ������ ������, 0�� 10�� ��踦 �ǹ�
	}
}