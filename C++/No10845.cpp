#include<iostream>
#include<string>
using namespace std;
// ť
// STL �� ���������� �� ������ ��ǥ�� ��

int main() {
	int loop;
	cin >> loop;

	int h = 0, t = 0; // ť�� ��, �� �ε���
	int q[10000] = {}; // ť �ʱ�ȭ

	string toDo;
	for (int k = 0; k < loop; k++) {
		cin >> toDo;
		if (!toDo.compare("push")) { // push �� ���
			cin >> q[t++];
		}
		else if (!toDo.compare("pop")) { // pop �� ���
			int num = h != t ? q[h++] : -1;
			cout << num << endl;
		}
		else if (!toDo.compare("size")) { // size �� ���
			cout << t - h << endl;
		}
		else if (!toDo.compare("empty")) { // empty �� ���
			cout << (t == h) << endl;
		}
		else if (!toDo.compare("front")) { // front �� ���
			int num = h != t ? q[h] : -1;
			cout << num << endl;
		}
		else if (!toDo.compare("back")) { // back �� ���
			int num = h != t ? q[t - 1] : -1;
			cout << num << endl;
		}
	}
}