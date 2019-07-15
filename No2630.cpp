#include<iostream>
using namespace std;
// ������ �����
// ����Լ��� ����� ���
// �ٸ�, ���� ���θ� �Ǵ��ϴ� ��Ŀ��� ���� ������ ���

void Cut(int size,int x,int y);

int** map;
int white, blue; //�� ��� ��

int main(){
	int size;
	cin >> size; //ũ�� �Է�

	map = new int*[size]; 
	for (int k = 0; k < size; k++) {
		map[k] = new int[size];

		for (int i = 0; i < size; i++) // �Է�
			cin >> map[k][i];
	} // �����Ҵ�

	Cut(size, 0, 0); //����Լ� ȣ��
	cout << white << "\n" << blue << endl; 
	
	for (int k = 0; k < size; k++) {
		delete[] map[k];
	}
	delete[] map; //�޸� ����
	return 0;
}

void Cut(int size, int x, int y) { // ����Լ�

	int sum = 0;
	for(int k=0;k<size;k++){
		for (int i = 0; i < size; i++) {
			sum += map[x + k][y + i];
		}
	}
	// �� ���� 0 �Ǵ� 1�� ����
	// so, ������ ĭ ���� ��ġ�ϸ� ����

	if (sum == size * size) { // ����
		blue++;
	}
	else if (sum == 0) { //���� 0�� ���
		//�ڸ� �ʿ� ����
		white++;
	}
	else { // ����
		   //�ٽ� �ڸ���
		Cut(size / 2, x, y);
		Cut(size / 2, x + size / 2, y);
		Cut(size / 2, x, y + size / 2);
		Cut(size / 2, x + size / 2, y + size / 2);
		return;
	}
}