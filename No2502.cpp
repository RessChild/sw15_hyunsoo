#include<iostream>
// ���Դ� ȣ����
using namespace std;

// �Ǻ���ġ ������ ���빮��. ����Լ�
// ����� ��� : �ᱹ �������� �����̹Ƿ�,
// �ش� ��¥������ a,b �� ���� ��� (����Լ�)
// ���� �� ���� ������ �����ذ��� �� ����

int day; //�� ��¥

void Check(int* a_count_first, int* b_count_first, int* a_count_second, int* b_count_second, int& index);
//Ƚ�� ��� �Լ� (���)

int main() {
	int first_a = 1;
	int first_b = 0;
	int second_a = 0;
	int second_b = 1;
	int index = 3; //�ε��� ���� 3���� ����

	int rice_cake; //�׳� �� ���� ��
	cin >> day >> rice_cake; //�� �Է�

	Check(&first_a, &first_b, &second_a, &second_b, index);

	int last_a = first_a + second_a;
	int last_b = first_b + second_b; //���� ����

//	cout << last_a << "\t" << last_b << endl;

	// ���Ŀ� ���ϸ� Ma + Nb = ��


	for (int i = 0; i < rice_cake / last_a; i++) { // ���� �� �ִ� �� ��ŭ
		int leftover = rice_cake - last_a * i; // ���� a�� ũ�⸦ ����
		
		if ( leftover % last_b == 0 ) {
			//�� �������� ���

			cout << i << "\n" << leftover / last_b << endl; //���
			break;
		}
	}
}

void Check(int* a_count_first, int* b_count_first, int* a_count_second, int* b_count_second, int& index) {
	//a (ù��), b(��¶��)�� ��ü �� ������ �󸶳� ���� ���Դ°�

	if (day > index) { // ���� ������� ��¥�� ���� ���̶��
		switch (index%2)
		{
		case 0: // ¦�� �� (2,4,6,8..) second�� �ǵ帲
			*a_count_second += *a_count_first;
			*b_count_second += *b_count_first;
			break;
		case 1: //Ȧ�� �� (3,5,7,9...) first�� �ǵ帲
			*a_count_first += *a_count_second;
			*b_count_first += *b_count_second;
			break;
		default:
			break;
		}
		index++; //�ε��� ����
		Check(a_count_first, b_count_first, a_count_second, b_count_second, index);
		//��� ȣ��
	}

}