#include<iostream>
#include<string>
using namespace std;
// ����
// ���̺귯���� ����������, �� ������ �ϱ�� ��

int top;
int s[10000]; // ���ÿ� ����� �迭

int main() {
	int loop;
	cin >> loop; // ��� ���� Ƚ��

	string toDo; // ���
	for (int k = 0; k < loop; k++) {
		cin >> toDo;
		if (!toDo.compare("push")) { // push �� ���
			cin >> s[top++];
		}
		else if (!toDo.compare("pop")) { // pop �� ���
			int num = top != 0 ? s[--top] : -1;
			cout << num << endl;
		}
		else if (!toDo.compare("size")) { // size �� ���
			cout << top << endl;
		}
		else if (!toDo.compare("empty")) { // empty �� ���
			cout << (top == 0) << endl;
		}
		else if (!toDo.compare("top")) { // top �� ���
			int num = top != 0 ? s[top - 1] : -1;
			cout << num << endl;
		}
	}
}