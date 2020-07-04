#include<iostream>
#include<cmath>
using namespace std;
// ���� ����
// Ÿ�� ���� ������ ����
// 100�� ���ǿ� 100�� �ο��� ���� �� ���·�, ������ 1���� ����ϴ� ���

#define NUM 1000000

int room, exam[NUM], B, C;

int main() {
	cin >> room;
	for (int k = 0; k < room; k++) cin >> exam[k];
	cin >> B >> C;

	long long int cnt = 0; // ���� �÷ο� ������
	for (int k = 0; k < room; k++) {
		cnt += 1;
		exam[k] -= B;
		if (exam[k] > 0) cnt += ceil((double)exam[k] / C); // double ���� ��������
	}
	cout << cnt << endl;
}