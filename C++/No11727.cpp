#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int size; // Ÿ�� ũ��
	cin >> size; //�Է�

	int* count = new int[size + 1]; //0~size ��ŭ�� �迭 ����
	count[0] = 1; // 0¥�� ������� ���� �ʴ� �� �� (1��)
	count[1] = 1; // 1¥�� ������� 1�� ��

	for (int k = 2; k < size + 1; k++) { // �ݺ��� �õ�
		count[k] = (2 * count[k - 2] + count[k - 1]) % 10007;
		// �� Ÿ�Ͽ���, 2ĭ�� �þ�� ����� ����
		// 2x1 Ÿ�� 2���� ���̰ų�, 2x2 Ÿ�� �ϳ��� ���̰ų�
	}
	cout << count[size] << endl;
	//������ ��ġ�� �䱸�ϴ� ������ ������ ���
	delete[] count; // �޸� ����
}