#include<iostream>
#include<math.h>
using namespace std;
// ������� (īī�� ��ȸ)
// �� ����� �ο� ���� ��Ģ�� ����
// 1�� ������ ��� n+1
// 2�� ������ ��� 2�� ���
// ��, ����� ������ �����Ƿ� ����ġ ���̽� ������ �Է�

int main() {
	int imagine; //��� Ƚ��
	cin >> imagine;

	int* first = new int[imagine];
	int* second = new int[imagine];

	for (int k = 0; k < imagine; k++) {
		cin >> first[k] >> second[k]; // �Է�
	}

	for (int k = 0; k < imagine; k++) {
		int total = 0;

		if (first[k] != 0) {
			for (int i = 1; i < 7; i++) {
				first[k] -= i;
				if (first[k] <= 0) {
					switch (i) { // ������ Ƚ���� ���� ����� ������ 
					case 1:
						total += 500;
						break;
					case 2:
						total += 300;
						break;
					case 3:
						total += 200;
						break;
					case 4:
						total += 50;
						break;
					case 5:
						total += 30;
						break;
					case 6:
						total += 10;
						break;
					default:
						break;
					} //���� ���� ����� ����
					break; //������� �ش� �ݺ��� ��
				}
			}
		}
		if (second[k] != 0) {
			for (int i = 1; i < 6; i++) { // �ι�° ��ȸ�� ���ؼ��� �õ�
				second[k] -= (int)pow(2, i) / 2;
				if (second[k] <= 0) {
					switch (i) { // ������ Ƚ���� ���� ����� ������ 
					case 1:
						total += 512;
						break;
					case 2:
						total += 256;
						break;
					case 3:
						total += 128;
						break;
					case 4:
						total += 64;
						break;
					case 5:
						total += 32;
						break;
					default:
						break;
					} //���� ���� ����� ����
					break; //������� �ش� �ݺ��� ��
				}
			}
		}

		cout << total * 10000 << endl; //���������̹Ƿ� 4�� ����
	}

	delete[] first;
	delete[] second;
}