#include<iostream>
using namespace std;
// N�� M (1)
// �ɸ��� �ð��� C���� ������ ������ ������ ����..
// ������� ���� �ɸ��� �ð��ε�, �̰� ��� ���̶�°ɱ�

void DFS(int tag);

int n, m;
int stack[8]; //����
bool use[8]; //false �ʱ�ȭ

int main() {
	cin >> n >> m;
	DFS(0);
}

void DFS(int tag) {
	
	if (tag == m) {
				for (int i = 0; i < m; i++) { //��������� ������ ���
					cout << stack[i]+1 << " ";
				}
				cout << endl; // �� ���� ��
				return;
	}
	else { //������ ������ �κ��� �ƴ϶��, ���ȣ��
		for (int k = 0; k < n; k++) { //��� ���� ���캸��
			if (!use[k]) { //���� ��� �ȵ� ���� ������
				stack[tag] = k;
				use[k] = true; //�̹� ���� �κ��� ��������� ǥ��
				DFS(tag + 1); //���ȣ��
				use[k] = false; //�̹� ���� �κ��� ��������� ǥ��
			}
		}
	}
}