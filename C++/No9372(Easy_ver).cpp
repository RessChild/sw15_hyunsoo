#include<iostream>
#include<vector>
using namespace std;
// ������� ����
// ��� ������ �˸� �ʹ� �ǹ̾��� ����
// cause, ����Ŭ�� ����, ��� ��带 �����ϴ� �׷����� ���� ��,
// ������ ������ �׻� ������ n-1�̶�� ���� ����ϸ� ���� �Է°� �Բ� �ذ�Ǿ����

int country, plane; //���� ��, ����� ����

int main() {
	int loop;
	cin >> loop; // �ݺ� Ƚ��

	while (loop--) {
		cin >> country >> plane;

		while (plane--) {
			int from, to;
			cin >> from >> to;
		}
		cout << country - 1 << endl;
	}
}