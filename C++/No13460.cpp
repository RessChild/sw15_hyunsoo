#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// ���� Ż�� 2
// �� ������ ���ÿ� �����̴� BFS Ž��

#define NUM 10

#define X "1210"
#define Y "2101"

typedef pair<int, int> pr;
typedef tuple<pr, pr, int> tp; // ���� ����, �Ķ� ����, �̵� Ƚ��

char map[NUM][NUM];
int N, M, visit[NUM][NUM][NUM][NUM]; // ����, ����, ���� ��ǥ�� �湮 ����
queue<tp> q;

pr operator+(pr a, pr b) { // Ʃ�� ������
	return pr(a.first + b.first, a.second + b.second);
}

bool check(pr a, pr b) { // �̵� �������� �Ǵ�
	return map[a.first][a.second] != '#' && !(a.first == b.first && a.second == b.second);
}

int main() {
	cin >> N >> M;

	pr R, B, O;
	for (int k = 0; k < N; k++) {
		for (int m = 0; m < M; m++) {
			cin >> map[k][m];

			switch (map[k][m]) {
			case 'R': // ���� ����
				R = pair<int, int>(k, m);
				break;
			case 'B': // �Ķ� ����
				B = pair<int, int>(k, m);
				break;
			}
		}
	}

	int ans = -1;
	q.emplace(R, B, 0); // BFS Ž��
	while (!q.empty()) {
		int cnt;
		pr pa, pb; // R, B �� ��ǥ

		tie(pa, pb, cnt) = q.front();
		q.pop();
		if (cnt > 9) break; // 10���� �Ѱܼ� �����̸� ����
		
		// ������ �湮�ߴ� ���¸� ����
		if (visit[pa.first][pa.second][pb.first][pb.second]) continue;
		visit[pa.first][pa.second][pb.first][pb.second] = cnt;

		for (int k = 0; k < 4; k++) { // �� �������� �����
			bool hole[2] = {};
			pr dir = pr(X[k] - '1', Y[k] - '1'); // �߷� ����
			pr bpa = pa, bpb = pb, npa = pa + dir, npb = pb + dir;

			while (check(npa, bpb) || check(npb, bpa)) { // ����� �������� ������ ������ �� �ִ°�?
				if (check(npa, bpb)) { // a�� ������
					if (map[npa.first][npa.second] == 'O') {
						// �������� ���⿡ ������ �ִٸ� ���
						hole[0] = true;
						bpa = pr(0, 0);
						npa = pr(0, 0); // ��ǥ ����ó��
					}
					else {
						bpa = npa;
						npa = npa + dir;
					}
				}
				if (check(npb, bpa)) { // b�� ������
					if (map[npb.first][npb.second] == 'O') {
						// �������� ���⿡ ������ �ִٸ� ���
						hole[1] = true;
						bpb = pr(0, 0);
						npb = pr(0, 0);
					}
					else {
						bpb = npb;
						npb = npb + dir;
					}
				}
			}

			if (hole[0] || hole[1]) { // �ϳ��� ���� ���� �Ǵ�
				if (hole[0] && !hole[1]) { // ���� ���� ���ۿ� ���ٸ�
					ans = cnt + 1; // �������� ���
					break; // ����
				}
				continue; // ���� �ܿ� ����
			}
			q.emplace(bpa, bpb, cnt + 1); // ���ۿ� �� ������ ���ٸ� ť�� ����
		}
		if (ans != -1) break; // ������ ����ٸ� ����
	}
	cout << ans << endl;
}