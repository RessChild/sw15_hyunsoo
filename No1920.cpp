#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
// �� ã��
// ������ ũ�Ⱑ 10��, Ž�� Ƚ���� 10��
// so, �ܼ� Ž���� ����ϸ� �ð� �ʰ� (100��)
// �̺� Ž���� ���

// �ٸ�, �ð��ʰ��� �߻��ߴµ� �̴� cin, cout �� �ð��������� ���� ����
// cstdio �� scanf, printf �� ��ȯ�Ͽ� �ذ�

int num, datas[100000], data_n, find_n;
int Binary_search(int start, int end);

int main() {

	scanf("%d", &data_n);
	for (int k = 0; k < data_n; k++) {
		scanf("%d", &datas[k]); // �Է¹ޱ�
	}
	sort(&datas[0], &datas[data_n]); // �Է����� ����

	scanf("%d", &find_n); // ���� ���� �Է�

	for (int i = 0; i < find_n; i++) {
		scanf("%d", &num); // ���������鼭 �Է�

		int start = 0, end = data_n - 1; 
		bool succ = false; // ���� ����
		while (start <= end) { // �̺� Ž�� ����
			int middle = (start + end) / 2;
			if (datas[middle] == num) { // ã�� ��� ����
				succ = true;
				break;
			}
			else if (datas[middle] > num) { // ũ�� ���� Ž��
				end = middle - 1;
				continue;
			}
			else { // ������ ���� Ž��
				start = middle + 1;
				continue;
			}
		}

		if (succ) printf("1\n"); // ã������ 1
		else printf("0\n"); // �ƴϸ� 0
	}
}