#include<iostream>
using namespace std;
// Auxiliary Project
// ���� ������ ǥ������ �� �� �ִ� ������ ���� �־��� ���,
// ���� �� �ִ� �� ������ �ִ� �� (�ߺ� ���)

#define THREE 7
#define FOUR 4
#define TWO 1 // ��� �� �ش� ����θ� �����Ǹ�, ������ ���� ȿ���� ������

int main() {
	int N;
	cin >> N;

	int ans = THREE * (N / 3);
	if (N % 3 == 1) ans = ans - THREE + FOUR; // 3��¥�� ���� 4��¥���� ä��
	else if (N % 3 == 2) ans += TWO; // 2��¥�� �� �߰�
	cout << ans << endl;
}