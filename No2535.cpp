#include<iostream>
using namespace std;
// ó������ �� �ϳ��� �����鼭 �����ϴ� ����� ����
// but, �ߺ����� ó�� �κп��� ������ ���ܼ� �뼱 ����

class Student {
public :
	int country; //���ù�ȣ
	int number; //������ȣ
	int score; // ����
	Student() {}
};

int over[100]; //�ߺ� ���� üũ�� �迭
// �������� memset�� Ȱ���Ϸ�������, ���ǰ� �ȵǾ������Ƿ�
// ���������� ���� �ʱ�ȭ

int main() {
	int loop; // ������ ��
	Student **list;
	cin >> loop; //������ �� �Է�

	list = new Student*[loop]; // �迭 ����
	for (int k = 0; k < loop; k++) {
		list[k] = new Student();
		cin >> list[k]->country >> list[k]->number >> list[k]->score; 
		//��ü ���� �Է¹���

		for (int i = k; i >= 1; i--) {
			if (list[i]->score > list[i - 1]->score) {
				// ���� �Էµ� ���� �ڽ��� ���� ������ ũ��
				Student* save = list[i - 1];
				list[i - 1] = list[i];
				list[i] = save; // �� ���� �ڸ��� �ٲ�
			}
			else // ���� �ش� ��Ģ�� ������ �ʾ�����
				break; // �� ������ ��� ���� ����. ����
		} // �ش� ������ �� �ݺ������� ����ǹǷ�, ��������� ����
	}


	for (int k = 0, flag = 0; flag != 3; k++) { 
			// �迭�� ���� k, �ݺ�Ƚ�� flag
			// 3���� ����� �� ����
		if (over[list[k]->country - 1] != 2) { // 2���� �ƴ϶��
			cout << list[k]->country << " " << list[k]->number << endl;
			over[list[k]->country - 1]++; // �׳��� �����ϰ� +1
			flag++;
		}
		// �ƴѰ��� �׳� �ѱ�
	}
}