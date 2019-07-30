#include<iostream>
using namespace std;
// ���� ����
// ���ó��� ������ �Ǿ�� ��ȹ��� ������ �� �ִٴ� ���� ������ ��
// so, �� ���ð� �ϳ��� ���Ͽ����� �̷���� �ִ������� �Ǵ�

class Link { //������ ���� ����
public:
	Link * link;
	Link();
};

int city, schedule;
Link Bridge[200];

int main() {
	cin >> city >> schedule;
	
	for (int k = 0; k < city; k++) {
		for (int i = 0; i < city; i++) {
			// NxN �� ��ŭ ������ ���� ���Ῡ�θ� �Է¹���
			int a;
			cin >> a;
			if (a)  // ���� ���δ�  0 �Ǵ� 1�� �ԷµǹǷ�, 1�� ��� ��
				if (k <= i) { // �̶�, ������ ��Ī���� ��� ��
					// so, �ߺ��Է��� ���ϱ� ���� ����� ũ�� ������ ��
					Link* find = &Bridge[i];
					while (find->link != NULL) { // �� ĭ�� ã�� �� ���� ��� ����
						find = find->link; //�ش� ĭ���� �̵�
					}
					find->link = &Bridge[k]; // i���� �Ž��� �ö� ��忡�� k�� ����
				}
		}
	} // �׷��� ����

	int to = -1; // �� ���� �ΰ��� ��常�� ���� ����
	Link* from = NULL, *find = NULL;
	while (schedule--) {
		from = find; // ���� ������ ����
		cin >> to;

		find = &Bridge[to - 1];
		while (find->link != NULL) { // �� ĭ�� ã�� �� ���� ��� ����
			find = find->link; //�ش� ĭ���� �̵�
		}

		if (from != NULL) { // ù �Է��� �ƴ϶��
			if (from != find) { // ���ϴ� �� ����� ����Ǿ����� ������ ���� �Ұ���
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl; // �ݺ����� ������ ���� ��� ����
	return 0;
}

Link::Link() {
	link = NULL;
}