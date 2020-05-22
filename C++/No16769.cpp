#include<iostream>
using namespace std;
// Mixing Milk
// ���δٸ� �� �絿�̿� ������ �ְ�
// �� 100ȸ �絿���� ������ ���� ���ų� �� �� ���� �̵�
// ���� ���¿��� �� �絿�� ���� ������ ���� ���

class Bucket {
public:
	int limit; //�ִ� ��
	int input; //���� ��
	int left; //�� ����
	Bucket(); //������
	void operator+=(Bucket& from); // ������ �����ε�
};

int main() {
	Bucket buckets[3]; //3���� �絿�� ����

	for (int k = 0; k < 100; k++) {	
			buckets[(k+1) % 3] += buckets[k % 3]; //������ ���� �ξ����
	}

	for (int k = 0; k < 3; k++) { //���
		cout << buckets[k].input << endl;
	}
	
}

Bucket::Bucket() { //������
	cin >> limit >> input; //���� �Է¹޾� �־����
	left = limit - input; //���� ���� ���
}

void Bucket::operator+=(Bucket& from) { // += �����ڿ� ����
	
	int can; //�̵� ������ ������
	if (left - from.input > 0) // �� �־ �ڸ��� ���°��
		can = from.input;
	else //�ڸ��� �����Ѱ��
		can = left;

	from.input -= can; //���� �� �ִ¸�ŭ�� ����
	input += can; //������ ���� �ξ������
	
	left = limit - input; //�� ����
	from.left = from.limit - from.input; // ����
}
