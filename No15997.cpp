#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
// �º� ����
// ������ ũ�Ⱑ �����Ƿ�, ��� case�� ���� Ž���Ͽ� Ȯ���� ����
// �ߺ��� ����� ���, Ȯ���� �����ϰ� �й��ؾ� �ϹǷ�,
// ������ ó���� ���� hash map �� ����Ͽ� �ߺ��� üũ

#define SCORE_F "310" // first�� ���� ȹ�� ����
#define SCORE_S "013" // second�� ���� ȹ�� ����

int score[4]; // �� ���� ����
double cnt[4], percent[6][3]; // �� ���� ���� Ȯ��, ���� Ȯ�� (3 ���)
pair<int, int> vs[6]; // �� ���� ���� ����
unordered_map<string, int> keys; // ����� ������ȣ

void DFS(int idx, double rate) {
	if (idx == 6) { // ������ �� �� ���, ����� �Ǵ�
		vector<int> select;
		unordered_map<int, int> check;
		for (int k = 0; k < 4; k++) {
			select.push_back(k); // ������ȣ ����
			if (check.find(score[k]) != check.end()) check[score[k]] += 1; // �̹� ���������� �ִ� ����
			else check[score[k]] = 1; // �����ٸ� �ʱ�ȭ
		}
		sort(select.begin(), select.end(), [](int a, int b)->bool {
			return score[a] > score[b]; // ������ ������ ������ ����
			});

		int max_v = check[score[select[0]]]; // ���� ������ ���� ū ���� �ߺ��� ��� �ִ��� Ȯ��
		if (max_v > 1) { // 1�� �̻� �����ߴٸ�, ���� ���� �� �ʿ����
			for (int k = 0; k < max_v; k++) {
				int code = select[k]; // ���� ��ȣ
				cnt[code] += 2 * (rate / max_v); // �̳��� �̱� Ȯ�� �߰�
				// �ٸ�, ���� �����ϸ� ����Ȯ���̸�, �ڸ��� 2���̹Ƿ� 2�� ����
			}
		}
		else {
			cnt[select[0]] += rate; // 1���� �⺻ ó��
			int sub_v = check[score[select[1]]]; // �ߺ� �� Ȯ��
			for (int k = 0; k < sub_v; k++) { // �ߺ� ����ŭ ������ Ȯ���� ����
				int code = select[k + 1]; // ���� ��ȣ
				cnt[code] += rate / sub_v; // �̱� Ȯ�� �߰�
			}
		}
		return;
	}

	for (int k = 0; k < 3; k++) { // 3 ���� ���
		score[vs[idx].first] += SCORE_F[k] - '0';
		score[vs[idx].second] += SCORE_S[k] - '0'; // �� ���, �� ���� ���� �� �ִ� ������

		DFS(idx + 1, rate * percent[idx][k]); // ������ ���� Ȯ���� �Ѱܼ� ��ȣ��
	
		score[vs[idx].first] -= SCORE_F[k] - '0';
		score[vs[idx].second] -= SCORE_S[k] - '0'; // �ش� ���̽� ���󺹱�
	}
}

int main() {
	for (int k = 0; k < 4; k++) {
		string team;
		cin >> team;
		keys[team] = k;
	} // �� �� �� �� ������ȣ�� ����

	for (int k = 0; k < 6; k++) {
		string first, second;
		cin >> first >> second;
		vs[k] = pair<int, int>(keys[first], keys[second]); // ��Ī�Ǵ� ���� ���� ��ȣ�� ���
		for (int m = 0; m < 3; m++) cin >> percent[k][m]; // first �� second �� [�̱�/���/��] Ȯ��
	}

	DFS(0, 1.0); // 0�� �ε�������, �⺻ Ȯ���� 1
	for (int k = 0; k < 4; k++) { // ����� ���� ���
		cout << cnt[k] << endl;
	}
}