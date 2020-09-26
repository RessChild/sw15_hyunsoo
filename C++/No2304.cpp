#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// â�� �ٰ���
// ��, �ڷ� ���̸� �˻��ϴ� ����� ���

int height[1001]; // �� ������ õ�� ����
vector<pair<int, int>> line; // ��� ����

int main() {
	int cnt;
	cin >> cnt;
	for (int k = 0; k < cnt; k++) { // �Է�
		int pos, height;
		cin >> pos >> height;
		line.emplace_back(pos, height);
	}

	// ������ ����
	sort(line.begin(), line.end(), [](pair<int, int> a, pair<int, int> b)->bool {
		return a.first < b.first;
	});

	// �տ��� õ���� ġ�� ���
	int front = 1, maxHeight = 0;
	for (auto l : line) {
		for (; front != l.first; front++) { // ����� ���� ���� ����
			height[front] = maxHeight;
		}
		maxHeight = max(maxHeight, l.second); // �� ���� ���̷� õ���� ħ
		height[front++] = maxHeight;
	}

	// �ڿ��� õ���� ġ�� ���
	int back = 1000, minHeight = 0;
	for (int k = line.size() - 1; k >= 0; k--) {
		auto l = line[k];
		for (; back != l.first; back--) { // ����� ���� ���� ����
			height[back] = minHeight;
		}
		if (height[back] == l.second) break; // ���� ���� ������ õ�� ���̰� ����
		minHeight = max(minHeight, l.second);
		height[back--] = minHeight;
	}

	// �� ������ õ�� �ʺ� �ջ�
	int sum = 0;
	for (int k = 0; k <= 1000; k++) {
		sum += height[k];
	}
	cout << sum << endl;
}