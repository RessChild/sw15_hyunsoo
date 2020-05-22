#include<iostream>
#include<stack>
using namespace std;
// ������

stack<char> l_q, r_q; // Ŀ�� ����, ������

int main() {
	string s;
	cin >> s;
	for (char ch : s) { // ���ڿ��� �����ϴ� �� ����
		l_q.push(ch); // �ʱ� Ŀ���� ���ڿ� �� ���̹Ƿ� ���� ���ں��� stack �� ����
	}

	int loop;
	cin >> loop;
	for (int k = 0; k < loop; k++) {
		char toDo;
		cin >> toDo; // L, D, B, P

		if (toDo == 'L') { // Ŀ�� ���� �̵�
			if (l_q.empty()) continue; // Ŀ���� �� ���� ���
			r_q.push(l_q.top());
			l_q.pop(); // ���� ������ �ֻ���� �̾Ƽ� ���������� �ű�
		}
		else if (toDo == 'D') { // Ŀ�� ������ �̵�
			if (r_q.empty()) continue; // Ŀ���� �� ���� ���
			l_q.push(r_q.top());
			r_q.pop(); // ������ ���� ���� �̵�
		}
		else if (toDo == 'B') { // ���� ����
			if (l_q.empty()) continue; // Ŀ���� �� ���ΰ��
			l_q.pop(); // ���� ����
		}
		else if (toDo == 'P') { // ���� ����
			char ch;
			cin >> ch; // ������ ���ڸ� �߰��� �Է�
			l_q.push(ch);
		}
	}

	// ���� ������ ������ ��� ���������� ���Ƽ� ���ڿ� �ϳ��� ����
	while (!l_q.empty()) {
		r_q.push(l_q.top());
		l_q.pop();
	}
	
	while (!r_q.empty()) { // ��� ���ڿ� ���
		cout << r_q.top();
		r_q.pop();
	}
}