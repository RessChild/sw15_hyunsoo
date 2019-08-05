#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
// ���ڸ� �����
// N���� '��ǥ'�� �־�����, ������ �־����� �ʾ����Ƿ�
// ��� ���̸� �����ϴ� ��� ���� NxN���� ��� ���

class Pos { // ��ǥ�� ������ Ÿ��
public:
	float x, y;
	Pos();
	Pos(float i_x, float i_y);
};

int num; // ���� ��
float total; // ���д� Ʈ���� ���� ��
int group[100]; // ���Ͽ����ε� ����
Pos star[100]; // �� ��ġ ����
float length[100][100]; // �� �� ������ �Ÿ��� ����Ͽ� ������ �迭
vector<int> sort; // ������ ���Ľ�ų ����

int Find(int here);
void Union(int a, int b); // �׷��� ���꿡 ���� Union-find ������ �ʼ���

int main() {
	cin >> num; // ���� ����
	for (int k = 0; k < num; k++) { // �� ������ŭ �Է�, ó������
		float x, y;
		cin >> x >> y;
		star[k] = Pos(x, y); //���� ��ǥ�� �Է¹޾� ����

		group[k] = k; // �ʱ⼼��

		for (int i = 0; i < k; i++) {
			float ans = sqrtf(powf(star[i].x - x, 2.0f) + powf(star[i].y - y, 2.0f));
			// �� ���� �밢�� �Ÿ��� ����
			length[i][k] = ans; // ������ �ֹ������� 2���� ���⳪
								// �ߺ��� ���ʿ��ϹǷ� �迭 ��ĭ���� ����

			for (int j = 0; j <= sort.size(); j++) { //���Ϳ� ���� ���ϸ� ���Ļ��� �� ����
				if (sort.size() == j) {
					sort.push_back(i * 100 + k); // ���������� �����ϸ� ���� ����
					break; //����
				}
				if (length[sort[j] / 100][sort[j] % 100] > ans) {
					// ���� �ְ��� �ϴ� ������ ū ���� ������, ���� ��ġ�� ����
					sort.insert(sort.begin() + j, i * 100 + k);
					break; //��������
				}
			}
		} // �Էµ� ����� ��� ��
	} //�Է� �Ϸ�

	for (int k = 0; k < sort.size(); k++) {
		// �Է��� ��� ������ ������� ��� ����
		Union(sort[k] / 100, sort[k] % 100); // ���� ����ŭ �ݺ�
	}
	cout << fixed; // �Ҽ��� �ڸ����� ����
	cout.precision(2); // �Ҽ��� �� 2�ڸ����� ǥ��
	cout << total << endl; //���� ���
}

Pos::Pos(){}
Pos::Pos(float i_x, float i_y) { // ������
	x = i_x;
	y = i_y;
}

int Find(int here){ // �־��� ���� �Ҽ� �׷� ��ǥ���� ã�� �Լ�
	if (group[here] == here) return here;
	return group[here] = Find(group[here]);
}

void Union(int a, int b){ // ������ �Լ�
	int root_a = Find(a);
	int root_b = Find(b); // ������ ��Ʈ���� ã��
	if (root_a != root_b) { // �ٸ� ���� �Ҽ� �� ���, ���ľ� ��
		group[root_a] = root_b; // ��Ʈ�� ���� ����
		total += length[a][b]; // �־��� ������ ���, �� ���� ����
	}
}