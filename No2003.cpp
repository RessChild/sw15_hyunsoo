#include<iostream>
using namespace std;
// ������ �� 2
// �� �����͸� �̿��� �����̵� ������ ����� ���

int main() {
	int N, M;
	int data[10000];

	cin >> N >> M;
	for (int k = 0; k < N; k++) {
		cin >> data[k]; // ������ �Է�
	}

	int f = 0, b = 0, sum = 0, select = 0;
	while (f != N) { // ���� �����Ͱ� ���� ������ �� ����
		if (sum > M || b == N) { // ���� �䱸 ������ ũ�ų�, �ڷ� �� �̻� ������ �� ������
			sum -= data[f]; 
			f += 1; // ���� �����͸� �ڷ� ����, ���� �迭�� �տ��� ��
		}
		else {
			sum += data[b];
			b += 1; // �� �ܿ��� ���� �����͸� �ű��, �迭 �տ� �߰�
		}

		if (sum == M) // �䱸 ���� ��Ȯ�� ��ġ�ϸ�
			select += 1; // ��� �� + 1
	}
	cout << select << endl; // ���
}