#include<iostream>
#include<algorithm>
using namespace std;
// �ϰ� ������

bool check[9]; // ����üũ��

int main() {
	int dwarf[9]; // 9���� Ű ����
	int total = -100; //����� �� Ű ����

	for (int k = 0; k < 9; k++) {
		cin >> dwarf[k];
		total += dwarf[k]; // ��� Ű�� ��
	}

	sort(dwarf, dwarf + 9); //����

	bool find = false;	// �پ��� ������ ���� �� �ֱ� ������
						// ���� �ϳ��� ã���� ����
	for (int k = 0; k < 8; k++) {
		for (int i = k + 1; i < 9; i++) {
			if (dwarf[k] + dwarf[i] == total) {
				check[k] = check[i] = true; // �� ���� �� �������� Ű�� ���ǿ� ����
				find = true;
			}
		}
		if (find)
			break;
	}
	
	for (int k = 0; k < 9; k++) {
		if (!check[k]) { // �ϰ� �����̰� �´ٸ� ���
			cout << dwarf[k] << endl;
		}
	}
}