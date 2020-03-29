#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
// �� �߱�
// �־����� ���� ���� �ߺ��Ǵ� �κ��� ���ְ� ��ĥ �ʿ䰡 ������
// so, ���׸�Ʈ Ʈ�� ������ ���������� �Է°��� ���ְ� �ʹ� Ŀ�� �Ұ���

// ���� �� ������ ��, �ڸ� �������� �����ϸ�
// �ߺ� ���θ� ���� ���� ��ġ�� ������ �ݺ�

stack<pair<int, int>> s; // ������ �׾��� �� ����
vector<pair<int, int>> v; // ���� ������ ����

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); // ����� �ð����� ���� �ð��ʰ� ����

	int N;
	cin >> N;
	while (N--) { // ������ �Է¹���
		int a, b;
		cin >> a >> b;
		v.emplace_back(a, b);
	}
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b)->bool { // ����
		return a.first != b.first ? a.first < b.first : a.second < b.second;
		});

	for (pair<int,int> line : v) { // ��� ���� Ȯ��
		if (s.empty()) s.push(line); // ������ �� ���, �׳� ���
		else {
			int s_a, s_b, v_a, v_b;
			tie(s_a, s_b) = s.top(); // ������� �׾��� ���� ��, ���� �ֱ��� ����
			tie(v_a, v_b) = line; // ������ ���� ���� �ҷ���

			if (s_b >= v_a) { // �� ���� ��ġ�� ���
				s.pop();
				s.emplace(min(s_a, v_a), max(s_b, v_b)); // �� ���� ��ħ
			}
			else s.emplace(line); // ��ġ�� ������ �� ��ü�� ���
		}
	}

	int ans = 0;
	while (!s.empty()) { // ������ �׾��� ���� Ȯ���ϰ� ���̸� üũ
		int a, b;
		tie(a, b) = s.top();
		s.pop();

		ans += b - a;
	}
	cout << ans << endl;
}