#include<iostream>
#include<math.h>
using namespace std;
// ������
// ���ڸ� �߽����κ��� ���������� ������� ����
// �ܼ��� ��Ģ���� �̿��� ����
// �� ���� �����ϴ� ���� �� = n + 2(n-1) + (n-2) = 5n-4

int main() {
	int size; //��ü ����
	int pos; //ã�� ��
	cin >> size >> pos; //�Է�
	
	int** room = new int*[size]; //���� ����
	for (int k = 0; k < size; k++) {
		room[k] = new int[size];
	} // �� ���� ������ ���� ������ ����

	int an_x, an_y; //ã�� ������ ��ġ�� ���� ��ǥ�� 2��
	int value = size*size; //�Է��� ��

	int x = 0, y =0; //������ ��ǥ
	for (int k = 0; k < (size + 1) / 2; k++) {
		// �������� ���� ä�� �� ����
		while (y < size - k - 1) { //�Ʒ��� �̵�
			if (value == pos) { //���ϴ� ���̶��
				an_x = x + 1;
				an_y = y + 1; //��ġ ����
			}
			room[x][y++] = value--; //���� �ְ� ���� ���ҽ�Ŵ
		}
		while (x < size - k -1) { //������ �̵�
			if (value == pos) { //���ϴ� ���̶��
				an_x = x + 1;
				an_y = y + 1; //��ġ ����
			}
			room[x++][y] = value--; //���� �ְ� ���� ���ҽ�Ŵ
		}
		while (y > k) { //���� �̵�
			if (value == pos) { //���ϴ� ���̶��
				an_x = x + 1;
				an_y = y + 1; //��ġ ����
			}
			room[x][y--] = value--; //���� �ְ� ���� ���ҽ�Ŵ
		}
		while (x > k+1) { //���� �̵�
			if (value == pos) { //���ϴ� ���̶��
				an_x = x + 1;
				an_y = y + 1; //��ġ ����
			}
			room[x--][y] = value--; //���� �ְ� ���� ���ҽ�Ŵ
		}
	}
	
	room[x][y] = 1; // �ݺ������� ���� ���� ���� ��

	for (int k = 0; k < size; k++) {
		for (int i = 0; i < size; i++) {
			cout << room[i][k] << " ";
		}
		cout << endl;
	} //���
	cout << an_y << " " << an_x << endl; //���� ���

	for (int k = 0; k < size; k++) {
		delete[] room[k];
	}
	delete[] room; //�޸𸮰���
}