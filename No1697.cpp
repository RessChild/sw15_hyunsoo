#include<iostream>
using namespace std;

void Hide_And_Seek(); // ���ٲ��� �Լ�
void Walk(int index, int depth); //�ȱ� �Լ�
void Back(int index, int depth); //-1
void Jump(int index, int depth); //�����̵� �Լ�

int* info; //������ ������ �迭
int me; //�� ��ġ
int sis; //���� ��ġ
		 // �ش� ������ ���̳��� ���α׷��� (�̸�������̼�)
		 // �� ���� Ʋ������ ���� ������ jump,back ������ ���信�� ����
		 // so, �迭 ũ�⸦ sis+1���� sis+2�� Ȯ��

int main() {


	cin >> me >> sis; // ��ġ�Է¹���
	info = new int[sis + 2]; //���� ��ġ��ŭ�� �迭 +2ĭ (2�� ��, -1 �ϴ� ���)

	for (int i = 0; i < sis + 2; i++) {
		info[i] = 99999999;
	}
	//�޸� �ʱ�ȭ
	// memset�� �����׷��µ� �ڲ� �ȸԾ.. �ᱹ for�� ����
	Hide_And_Seek();
	delete[] info; //�����Ҵ� ����
}

void Hide_And_Seek() { //���ٲ��� �Լ�


	if (me >= sis) //���� ������ġ���� �ڿ�������, -1�θ� �̵��ؾ���
		cout << me - sis << endl;
	else {
		Jump(me * 2, 0);
		Walk(me + 1, 0);
		Back(me - 1, 0);
		//������ ���ؼ� �ּ��� ���� ��� ����

		cout << info[sis] << endl;
	}
}
void Walk(int index, int depth) {
	if ((index > -1 && index < sis + 2) && info[index] > depth) { //�ε����� ����� ������ �� Ƚ���� �� ª����
		depth++; //���̵� +1
		info[index] = depth; //����

		if (index == sis) //���������� 
			return; //����
		else { // �ƴ϶��
			Jump(index * 2, depth); //2�� ������Ű�� ���� �ְ�
			Walk(index + 1, depth); //��ĭ ����
									// ������ �������, �ڵ��ư��� ���� �ʿ�x (�ݺ�)
		}
	}
}
void Back(int index, int depth) {
	if ((index>-1 && index<sis + 2) && info[index] > depth) { //�ε����� ����� ������ �� Ƚ���� �� ª����
		depth++; //���̵� +1
		info[index] = depth; //����

		if (index == sis) //���������� 
			return; //����
		else { // �ƴ϶��
			Jump(index * 2, depth); //2�� ������Ű�� ���� �ְ�
			Back(index - 1, depth); //��ĭ ��
									// �ڷ� �� ���, ������ ���� �� �ʿ�x
		}
	}
}
void Jump(int index, int depth) {
	if ((index>-1 && index<sis + 2) && info[index] > depth) { //�ε����� ����� ������ �� Ƚ���� �� ª����
		depth++; //���̵� +1
		info[index] = depth; //����

		if (index == sis) //���������� 
			return; //����
		else { // �ƴ϶��
			Jump(index * 2, depth); //2�� ������Ű�� ���� �ְ�
			Walk(index + 1, depth); //��ĭ ����
			Back(index - 1, depth); //��ĭ ��
		}
	}
}