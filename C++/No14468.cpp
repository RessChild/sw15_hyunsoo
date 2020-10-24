#include<iostream>
#include<stack>
using namespace std;
// �Ұ� ���� �ǳʰ� ���� 2
// ����� ������ �������� �մ´ٴ� Ư¡�� ����
// �̋� ���� �����ϴ� ���� �׵θ��� ������ ���� ������ ���� ��ų ��
// ( ex. ��� or HTML ������ ���� )

#define ALP 26
#define NUM 52

int cow[ALP]; // ���ĺ� ���� Ƚ��
stack<int> s; // ������ ���ĺ� ���� (�׵θ���)

int main() {
	int ans = 0;
	for (int k = 0; k < NUM; k++) {
		char ch;
		cin >> ch;
		int alp = ch - 'A';

		if (!cow[alp]) { // ù ����
			cow[alp] = 1;
			s.push(alp);
		}
		else { // �����
			stack<int> save;
			while (s.top() != alp) { // �� ���̿� �� ���ĺ� ����
				save.push(s.top());
				s.pop();
			}
			s.pop(); // ���� ���ĺ� ����
			ans += save.size(); // ���̿� �� ���ĺ���ŭ ���� ����

			while (!save.empty()) { // �ٽ� �̵�
				s.push(save.top());
				save.pop();
			}
		}
	}
	cout << ans << endl;
}