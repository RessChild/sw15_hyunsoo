#include<iostream>
#include<cstdio>
// ���൹ ������
// ���� �������� Ȯ�� ���� �� �ϳ�
// �� ���� ���� �ش� ������ ���� Ȯ���� ���� ��, �̸� ��� ����

using namespace std;

int cnt[50];
int total;
double rate;

int main() {
	int color;
	cin >> color;
	for (int k = 0; k < color; k++) {
		cin >> cnt[k];
		total += cnt[k];
	}
	int sel;
	cin >> sel;

	for (int k = 0; k < color; k++) { // ��� ���൹ ���� ����
		if (sel > cnt[k]) rate += 0; // �������� ������ ������ Ȯ�� 0
		else {
			double val = 1;
			for (int m = 0; m < sel; m++) { // �� �ܿ��� ���������� 1���� ���ư� Ȯ���� ���
				val *= ((double)cnt[k] - m) / (total - m);
			}
			rate += val; //���� ����� ���
		}
	}
	printf("%.15f", rate);
	// ���� ��� ���� �Ҽ��� 9�ڸ� �����̹Ƿ�,
	// �Ҽ��� ����� �����ϱ� ���� printf �� ���
}