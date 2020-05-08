#include<cstdio>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
// ģ�� ��Ʈ��ũ
// Union-Find �׷��� + Hash map �� ����� ����Ǯ��
// �ٸ� cin �� �Էµ����̷� ���� �ð��ʰ��� ����ؼ� �߻�
// so, cstdio ���·� ������ ����

unordered_map<string, int> m; // �� �̸��� �ε��� ��ȣ�� ����
vector<int> group, rel; // �Ҽӵ� �׷� ��ȣ, �׷��� ũ�� (��ǥ���� ���)

int Find(int idx) { // �� �׷��� ��ǥ�� Ž��
	if (group[idx] == idx) return idx;
	return group[idx] = Find(group[idx]);
}

int Union(int a, int b) { // �� ����� ���� �׷��� ��
	int i_a = Find(a), i_b = Find(b);
	if (i_a == i_b) return rel[i_a]; // �̹� ���� ���� �����ϴ� ���, ����

	// �ε��� ���� ���� ������ �׷��� ����
	if (i_a < i_b) {
		rel[i_a] += rel[i_b]; // �׷� a �� �Ҽӵ� ���� �� ����
		group[i_b] = i_a; // �׷��� ����
	}
	else {
		rel[i_b] += rel[i_a];
		group[i_a] = i_b;
	}
	return max(rel[i_a], rel[i_b]); // �� ���� ���������Ƿ�, �� �� ū ���� ����
}

int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		int F;
		scanf("%d",&F);

		m.clear();
		group.clear();
		rel.clear(); // �ܺ� �ڷᱸ�� �ʱ�ȭ

		group.push_back(0);
		rel.push_back(0); // 0�� �ε����� ������� ����
		while (F--) {
			char f[2][21];
			scanf("%s %s", &f[0], &f[1]);

			int idx[2];
			for (int k = 0; k < 2; k++) {
				if (!m[f[k]]) { // Ű�� ��������, ���� ���� ��
					m[f[k]] = group.size();
					group.push_back(group.size());
					rel.push_back(1);
				}
				idx[k] = m[f[k]]; // �̸��� ��ǥ�ϴ� �ε��� �� ����
			}
			printf("%d\n", Union(idx[0], idx[1])); // Union-Find ����
		}
	}
}