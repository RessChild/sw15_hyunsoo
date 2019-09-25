#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Ceiling Function
// Ʈ���� ������ ��, DFS Ž���� ���� ����� '����'�� ǥ��ȭ ��Ŵ
// �� ����� ��,�� ��� ���ο� ���� ������ ǥ���ؾ� �ϹǷ�,
// �� 2��Ʈ�� ������ �ʿ� (�ӵ������� ���� ������ ��Ʈ���� ���)
// 0 : ����, 1 : ���� ����, 2 : ������ ����, 3 : ���� ����

class Node {
public:
	int val; //��� ������
	int state; //��,�� ��� ��������
	Node *l, *r;
	Node(){}
	Node(int val);
};

int test; // �׽�Ʈ Ƚ��
int node; // ��� ��
vector<long long int> ans; // �� ���̽� �� Ʈ������ ������ ����

void DFS(long long int& save, Node* here); // ���� ����� �Լ�

int main() {
	cin >> test >> node; // �׽�Ʈ Ƚ��, ��� �� �Է�
	for (int k = 0; k < test; k++) { // �׽�Ʈ �ݺ�
		Node* root = NULL; // Ʈ���� ��Ʈ
		for (int i = 0; i < node; i++) {
			int data;
			cin >> data;
			if (root == NULL) // ��Ʈ�� ��������� ��Ʈ�� ä��� ��
				root = new Node(data);
			else {
				Node* make = new Node(data); // ���� ���� ���
				Node* move = root; // �̵��� ���� ���
				while (true) {
					if (move->val > data) { //������ġ�� ���������� ũ��
						if (move->l == NULL) {
							move->state += 1; // ������ ������ 1�� ����
							move->l = make; //���� ���� ����
							break; //���� ��
						}
						move = move->l; //�� �ܿ� �̵�
					}
					else {
						if (move->r == NULL) {
							move->state += 2; // �������� 2 ����
							move->r = make; //���� ���� ����
							break; //���� ��
						}
						move = move->r; //�� �ܿ� �̵�
					}
				} // ���� ��� ���� ��
			}
		} // �� �Է� �� (Ʈ�� ����)

		long long int result = 0; //����� ������ ����
		DFS(result, root); // �ش� Ʈ���� ����� ������ ����ȭ
		ans.push_back(result); // ���� ����
	} // ��� ���̽��� ���� ó�� ��

	sort(ans.begin(), ans.end()); // ���͸� ������ �� ����
	int count = 1;
	for (int k = 1; k < ans.size(); k++) {
		if (ans[k - 1] < ans[k]) //�ռ� ���� ������ ũ�� ���� ����
			count++;
		// �ش� ��Ģ�� �� �����ϴ°�?
		// �켱 ������ �� �����̹Ƿ�, ���� ���� ���� ���� x
		// ���� ���� ����, ����ȭ�� Ʈ���� ����� �����ϴٴ� �ǹ�
		// so, ���������� ū ��쿡�� ���ο� ����� ���������� �ǹ�
	}
	cout << count << endl;
}

Node::Node(int val) {
	this->val = val;
	state = 0;
	l = r = NULL;
}

void DFS(long long int& save, Node* here) {
	if (here == NULL)
		return;
	save <<= 2;
	save |= here->state; // ��Ʈ������ ����
	DFS(save, here->l);
	DFS(save, here->r); // �¿쿡 ���� ���
}