#include<iostream>
using namespace std;
// ��

int main() {
	int cup[3] = { 1,0,0 };	//ó���� 1�� �ſ� ��
	int loop;
	cin >> loop; // �̵� Ƚ��
	for (int k = 0; k < loop; k++) {
		int a, b;
		cin >> a >> b; //�� ��ȣ �Է�

		int swap = cup[a-1];
		cup[a-1] = cup[b-1];
		cup[b-1] = swap; // ��ȯ
	}
	for (int k = 0; k < 3; k++)
		if (cup[k]) // 0�� �ƴ� ���̶��
			cout << k + 1 << endl; // ���
}
