#include<iostream>
using namespace std;
// �輺�� ������ ���� ����
// ��Ÿ����

int main() {
	int loop;	
	cin >> loop; // �ݺ� Ƚ��

	char answer[20]; //������ �׽�Ʈ ���̽��� �ִ� 20��

	for (int k = 0; k < loop; k++) {
		int people, coffee, card; //�ο� ��, Ŀ�� ����, ī���ѵ�
		cin >> people >> coffee >> card;
		
		int list[20] = {}; //�� ������ ���� ������ ���
		// Ŀ�� ������ �ִ� 20���̹Ƿ�, 20���� �����迭 ���

		for (int i = 0; i < people; i++) {
			int select;
			cin >> select;
			list[select - 1]++; //��ȣ�ϴ� Ŀ�� ������ �ް� ���� ����
		}

		int total = 0;
		for (int i = 0; i < coffee; i++) {
			int price;
			cin >> price; //������ �Է¹ް�
			total += list[i] * price; //��*������ �� ��
		}
		answer[k] = total <= card ? 'Y' : 'N'; //�� ����	
	}

	for (int k = 0; k < loop; k++)
		cout << "#" << k + 1 << " " << answer[k] << endl; // ���

}