#include<iostream>
using namespace std;
// �������� ��
// ���̳��� ���α׷��� ���
// ���������� �ִ� ���� ���Ͽ� �ִ� ��θ� ����

int main() {

	int num;
	cin >> num; // �� �Է�

	int* record = new int[num + 1]; // �Է¹��� �� ũ�⸸ŭ�� ����� ����
		// 0���� �Է¹��� �������� �迭�̹Ƿ� num+1
	record[0] = 0; // ���� 0�� ä��� ����� �ƹ��͵� ������ ���� �� 0   
	for (int i = 1; i < num + 1; i++) { //��� �迭�� ä�� �� ���� ����
		
		int select = i - 1; //������ index ��ȣ
		int loop = 1; // ������ ���� �� 
		int save = i - 1;
			// �켱 �� �ؿ��� +1�� �ϴ� ������ �ִܰŸ�
		while (save >= 0) { //save ���� ���ٰ����� �ε��� ���� �����̸� ����ؼ�

			if (record[select] > record[save]) { 
				// ���� ���� ���� ���� �����ߴ� ������ �� ������
				// �����Ǵ� ���� �������� ����
				select = save; // ����
			}
			loop++; // ���� ����
			save = i - (loop * loop); // save �� ��ȯ
			  // ���� ���� ����������
			  // �ش� ������ ������ ���鼭 ���� 
		}
		record[i] = record[select] + 1; // ����
	}

	cout << record[num] << endl; //���

	delete[] record;
}