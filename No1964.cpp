#include<iostream>
using namespace std;
// ������
// ��Ģ�� Ȱ���ϴ� ����
// n��° �� = n-1��° �� + 4 + 3*(n-1)
// �̴� ���� ����� �׵θ� ������ + �� ���� �����ϴ� ���� ��

int main() {
	int level;
	cin >> level;
	int total = 5; //��ü �� ��
	// 1�ܰ迡���� ���� ���� ����
	for (int k = 1; k < level; k++) { // 1�ܰ� ��ŵ
		total = (total + 4 + 3 * k) % 45678; // ���
	}
	cout << total << endl; // ���
}