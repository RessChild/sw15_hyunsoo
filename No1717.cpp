#include<iostream>
using namespace std;
// ������ ǥ��

class Group {
public:
	Group* root;
	Group();
}; // ������ ������ ���� �ִ� �׷�

int total, loop;
Group group[1000000]; // �� ���� ����

bool Equal(int a, int b, Group* pa, Group* pb); // ���� ���� ����
void Union(int a, int b); // ������ ����

int main() {

	cin >> total >> loop;

	while (loop--) {
		bool toDo;
		int a, b;
		cin >> toDo >> a >> b; //������ ���� �� �� ���


		if (toDo) { // 1�� ���, �ܼ� Ȯ��
			if (Equal(a, b, NULL, NULL)) //������� ���� �����̹Ƿ� NULL ����
				cout << "YES\n"; // ����
			else
				cout << "NO\n"; // �ٸ� ����
		}
		else { // 0�� ���, ������
			Union(a, b);
		}
	}
}

Group::Group() {
	this->root = NULL;
}

bool Equal(int a, int b, Group* here_a, Group* here_b) {
	Group* pa = &group[a];
	Group* pb = &group[b];
	Group* move = NULL;
	Group* save = NULL;
	while (pa->root != NULL) { // NULL�� ���� �� ���� ��� ã��
		move = save;
		save = pa;
		pa = pa->root; // Ʈ�����¸� ������ �Ѿư�
		
		if(move != NULL) move->root = pa; // NULL�� �ƴϸ�, ���� �ǳ� �� �� �ֵ��� ��
	}

	save = NULL;
	while (pb->root != NULL) {
		move = save;
		save = pb;
		pb = pb->root; // b�� ���ؼ��� ������ ����� ���
					   // �Ž��� �ö󰡴� ������ Ʈ������, �ᱹ �ϳ��� ������ ��ǥ�� �ϳ��� ���̰� ��
		if (move != NULL) move->root = pb; // NULL�� �ƴϸ�, ���� �ǳ� �� �� �ֵ��� ��
	}
	if (here_a != NULL) here_a = pa;
	if (here_b != NULL) here_b = pb; // �ܼ� Ž������ ����ó��

	return pa == pb; //�� ��ġ�� ���� ���θ� bool ������ return
}

void Union(int a, int b) {
	Group *here_a = &group[a], *here_b = &group[b];
	if (!Equal(a, b, here_a, here_b)) {
		//�켱 �� ��ġ�� ���� ���� ���� ����� ��ĥ �� ����
		here_b->root = here_a; // �� ��� ��, ���� ���� ������ ����
	}
}