#include<iostream>
using namespace std;
// ���谨�� ����
// �� �����忡�� �Ѱ����� 1�� �ʼ�, �׿� �ΰ������� �� ���x

int main() {
	int room; //�� ��
	int main; //�Ѱ����� Ž�� ��
	int sub; //�ΰ����� Ž�� ��

	cin >> room;
	int* student = new int[room]; //�� �濡 �ִ� �ο� ���� ������ ����	

	for (int i = 0; i < room; i++)
		cin >> student[i]; 
	cin >> main >> sub; //�� �Է�

	int sub_people = 0; // �ΰ��� ��
	for (int i = 0; i < room; i++) {
		//��� �濡 ���Ͽ� ���� �����ؾ��ϰ�,
		//�Ѱ��� ���� room ���� ���� ������ �ǹǷ�,
		//�ΰ����� ���� ����� ��

		student[i] -= main; //�� �渶�� �Ѱ����� �� �� �ִ� ����� ����
		while (student[i] > 0) { //���� Ŀ���� �ȵǸ�
			sub_people++; 
			student[i] -= sub;
			//Ŀ���� �� �� ���� ��� �߰�
		}
	}

	cout << sub_people + room << endl; //��°��� �ΰ�����+�Ѱ����� ��
}