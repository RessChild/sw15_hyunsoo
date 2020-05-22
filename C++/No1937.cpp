#include<iostream>
#include<algorithm>
using namespace std;
// ������� �Ǵ�
// ���̳��� ���α׷����� ���
// ���⿡ ���� �������� 4������, ���ǿ� ���� �̵��ϱ� ������
// �Լ� �ϳ��� ����Ͽ� ����� ����

int map;
int bamboo[500][500]; //�볪�� ��
int max_life[500][500]; // �ִ�� �� �� �ִ� ��
	// �������� ���� ��� 0���� ����ϰ�,
	// �ش� ���������� �ּ� 1���� ���� �����ϹǷ�, �ּҰ��� 1�� ���

int Move(int x, int y); //�� �������� �̵��ϴ� �Լ�
void DP();

int main() {
	cin >> map; //�� ũ�� �Է�
	for (int k = 0; k < map; k++)
		for (int i = 0; i < map; i++) 
			cin >> bamboo[k][i]; // �볪�� ������ ����
	DP();
}

int Move(int x, int y) { // �ֺ��� ������ �� �ִ� ������ �ִ��� Ȯ���ϴ� �Լ�
	if (max_life[x][y]) // �̹� ������ ���� ������ ��ȯ
		return max_life[x][y];

	max_life[x][y] = 1; // �ϴ� �ѹ� �� �����̴� �������� �ּ� 1��

	if (y > 0 && bamboo[x][y] < bamboo[x][y - 1]) 
		max_life[x][y] = max(max_life[x][y], Move(x, y - 1) + 1);
	if (y < map - 1 && bamboo[x][y] < bamboo[x][y + 1])
		max_life[x][y] = max(max_life[x][y], Move(x, y + 1) + 1);
	if (x > 0 && bamboo[x][y] < bamboo[x - 1][y])
		max_life[x][y] = max(max_life[x][y], Move(x - 1, y) + 1);
	if (x < map - 1 && bamboo[x][y] < bamboo[x + 1][y])
		max_life[x][y] = max(max_life[x][y], Move(x + 1, y) + 1);
	// �����¿� ������ �����̸�
	// ���� ��ġ���� �볪�� ���� ���� ��쿡�� �̵�
	// ������ ��ϵǾ��ִ� �ִ� ���� ����, ������ ���⿡�� ���������� �ִ볯 +1 �� ��
	// �볪���� �� �������� ���� �ڽ��� �Դ� �������� �ǵ��ư��� ���� ����
	// ���� x,y�� ũ�������� �Բ� �ɾ
	// �ε��� ���� (0 ~ y-1) �� ����� �ʵ��� ����

	return max_life[x][y]; // ������ �ִ� ���� ���� ��ȯ
}


void DP() {
	int panda = -1; // �Ǵ��� �ִ� ���� �� 
	for (int k = 0; k < map; k++) 
		for (int i = 0; i < map; i++) 
			panda = max(panda, Move(k, i)); // ��� �������� ���������� ���� �ִ��� Ȯ��

	cout << panda << endl; // ���� �� ���
}
