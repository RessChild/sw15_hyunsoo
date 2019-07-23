#include<iostream>
#include<vector> //�����Ҵ� (����) ���
using namespace std;
// ������

const int MAX_NUM = 200; // �ִ� ����

int cow, cage; // �ҿ� öâ ��
int isThere[MAX_NUM]; // �� öâ�� �� ��ȣ
bool visit[MAX_NUM]; // �� öâ�� �湮 ����
vector<vector<int>> prefer; //�� ���� ��ȣ ��� ���� ����

void Binary_Match();
int Search(int who);

int main() {
	cin >> cow >> cage;
	prefer.resize(cow); // ������ ũ�� ����
						// ���� -1�� �ƴ� 0���� ���� �����ϸ�, ���� index ��ȣ�� 0�� ���ؾ��Ѵ�
						// = 1���� �����ؾ� ��
						// cause, �� ���� �Ǵ��ϴ� �������� 0�� �Ҵ� ���� ����ִ� �Ͱ� �����ϰ� �ǴܵǱ� ����

	for (int k = 0; k < cage; k++)
		isThere[k] = -1; // ������ �ּ� �ʱ�ȭ

	for (int k = 0; k < cow; k++) {
		int count;
		cin >> count; // ��ȣ�ϴ� ���� ��

		for (int i = 0; i < count; i++) {
			int like;
			cin >> like;
			prefer[k].push_back(like); // k��° ���Ϳ� ���� �߰�
		}
	} // ���� ��ȣ öâ ���� ����

	Binary_Match(); //ȣ��
}

void Binary_Match() {
	int ans = 0; // ����

	for (int k = 0; k < cow; k++) { // ��� �ҵ鿡 ���ؼ� ���� ����� ����
		for (int i = 0; i < cow; i++)
			visit[i] = false;
		ans += Search(k);
		// �� �� ����, 1���� ���� ������ �õ�
		// ������ ��� ���� ���� ���� ���� +1
		// �ƴ� ���� ����
	}
	cout << ans << endl; // ���� ���
}

int Search(int who) { //�ش� �ҿ� ���� �湮 �õ�
	if (visit[who]) return 0; // �ش� �ҿ� ���� �ٽ� �õ��Ϸ��� ��� ����
	visit[who] = true; // �湮�ߴٰ� ǥ��

	for (int k = 0; k < prefer[who].size(); k++) { // �Ұ� ��ȣ�Ѵٰ� ���� öâ ��ο� ����
		int room = prefer[who][k] - 1; // �̹� ���� �����ϰ� �ִ� ���� ����

		if (isThere[room] == -1 || Search(isThere[room])) {
			// ���� ����ְų�, Ȥ�� �ش� ���� ���� �Ҹ� �ٸ� ������ �ű� �� ������
			isThere[room] = who; //�ش� ���� �̳��� ����
			return 1; // ��Ī�� �� +1
		}
	}
	return 0; //��� öâ�� ���� ��Ī ������ ��� ��
}
