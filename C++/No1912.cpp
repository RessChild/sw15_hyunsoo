#include<iostream>
using namespace std;
// ������
// Maximum array �˰���

int main() {
	int size;
	cin >> size; // ���� ����� �Է¹���

	int* arr = new int[size]; //�Է¹��� �����ŭ �迭 ����
	int total = -1000; //��ü �� �� (����)
		// ���� -1000 ���� ��ŸƮ�� ���� ������, �ּ��� �ϳ��� ���� �̾ƾ� �ϱ� ����
	int save = 0; // �ӽ�����
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
		save += arr[i]; //���� ���� �Է°��� ����

		if (save > total)  //��������� ���� ���ߵ� ���亸�� ũ�ٸ�
			total = save; // ������ �ٲٱ�
		if (save < 0) // 0ĭ¥���� ��, ������ �Ǵ� ���
			save = 0; // 0���� �ʱ�ȭ (���ֹ���)
	}
	cout << total << endl; //���
	delete[] arr; // �����Ҵ� ����
}