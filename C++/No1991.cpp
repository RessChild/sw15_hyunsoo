#include<iostream>
#include<map>
using namespace std;
// Ʈ�� ��ȸ
// Ʈ���� preorder, inorder, postorder traversal
// ���� Ʈ���̹Ƿ� �� �ڽ��� �ε����� (N * 2 + 1), (N * 2 + 2)

char tree[50]; // Ʈ�� ������ ����� �迭
map<char, int> index; // �Էµ� ������ �ӽ÷� ������ map
// �Է� ������ Ư���� ������ ���� �ʱ� ������
// ������ �����ϰ� ������ Ž���ϱ� ���� ������ �ʿ�����

void front(int index);
void middle(int index);
void back(int index); // ���� �Լ� (���)

int main() {
	int node;
	cin >> node;

	index['A'] = 0; // ��Ʈ�� A �̸�, �迭 �� ��ġ�� 0
	tree[0] = 'A';
	for (int k = 0; k < node; k++) {
		char n, l, r;
		cin >> n >> l >> r; // ���, ����, ������ �ڽ�

		int wh = index[n]; // �Էµ� ��尡 ��ġ�� �迭�� �ε��� ��

		tree[wh * 2 + 1] = l;
		tree[wh * 2 + 2] = r; // �迭���� �ڽ� ��ġ�� ������ ����

		index[l] = wh * 2 + 1;
		index[r] = wh * 2 + 2; // �ʿ� �ε��� ���� ����
	}
	front(0); cout << endl;
	middle(0); cout << endl;
	back(0); cout << endl; // �Լ� ����
}

void front(int index) { // ���� Ž��
	if (tree[index] == '.') return; // '.' �̶�� ����
	cout << tree[index];
	front(index * 2 + 1);
	front(index * 2 + 2);
}

void middle(int index) { // ���� Ž��
	if (tree[index] == '.') return; // '.' �̶�� ����
	middle(index * 2 + 1);
	cout << tree[index];
	middle(index * 2 + 2);
}

void back(int index) { // ���� Ž��
	if (tree[index] == '.') return; // '.' �̶�� ����
	back(index * 2 + 1);
	back(index * 2 + 2);
	cout << tree[index];
}