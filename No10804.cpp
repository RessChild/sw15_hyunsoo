#include<iostream>
using namespace std;
// ī�� ����ġ
int main() {
	int card[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	// ����� ī�� ����Ʈ
	// ������ ���迭

	int start, end;
	for (int i = 0; i < 10; i++) { // �� 10���� �Է¹���
		cin >> start >> end; // �Է�
		start--;
		end--; // ������ �迭���� �� ���� �ϳ� ���� ��
		for (int k = 0; k < (end - start + 1) / 2; k++) {
			// �� ���̰��� ���ݸ�ŭ ���� �ٲ� ����
			int swap = card[start + k];
			card[start + k] = card[end - k];
			card[end - k] = swap; // �迭 ������ �������� ����
		}
	}

	for (int i = 0; i < 20; i++) {
		cout << card[i] << ' '; // ���
	}
	cout << endl;
}
