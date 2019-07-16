#include<iostream>
using namespace std;
// N-Queen
// ���� �̵� ��Ģ���� stack�� ����� ����� Ǯ��

int Put(int num);

int queen;
int stack[14];

int main() {
	cin >> queen; // ü��ĭ ũ�� = ���� ��

	int total = 0;
	if (queen == 1) // 1X1�� ��� ����ó��
		total = 1;
	else {
		for (int k = 0; k < queen; k++) {
			// �� ���� ��쿣 0~queen-1���� �־�� ���� ����
			stack[0] = k;
			total += Put(1);
		}
	}
	cout << total << endl;
}

int Put(int num) {
	bool line[14] = {}; // false�̸� ���� �� ����
	for (int k = 0; k < num; k++) { //�� ���� ���� �� ��ŭ
		line[stack[k]] = true; // �̹� ���� ������ ���� �� ����

		int left = stack[k] - (num - k);
		int right = stack[k] + (num - k);
		if (left >= 0) // 0�� �ƴ϶�� (���ָ� ����� ������)
			line[left] = true;
		if (right < queen) //���ָ� ����� ������
			line[right] = true;
		//�� �밢������ ��ġ�� �κ� Ȯ��
	}

	if (num != queen - 1) { //���� ��� �ܰ踦 ���� �ʾҴٸ�
		int total = 0;
		for (int k = 0; k < queen; k++) {
			if (!line[k]) { //���� ������ �־�����
				stack[num] = k; // k��° ������ num��°�� ��
				total += Put(num + 1); // ���ȣ��
			}
		}
		return total; //�ڽ����κ��� ���� ���� ��� ��ȯ
	}
	else { // ������ �ܰ��̸�
		for (int k = 0; k < queen; k++) {
			if (!line[k]) { //���� ������ �־�����
				return 1; // ��ȯ (������ ������ 1��)
			}
		}
		return 0;  // �� �ܿ� 0��
	}
}