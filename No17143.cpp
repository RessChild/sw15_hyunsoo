#include<iostream>
#include<queue>
#include<tuple>
#include<cmath>
using namespace std;
// ���ÿ�
// ��Ģ�� ���� �ùķ��̼�
// �� ���� �ε����� ������ ���� ���� ����ȭ�ϴµ� ����� �ָ� ����
// so, �׳� �� ���� ������ ó��

#define MAP 100
#define X "10211"
#define Y "11120" // ��, �Ʒ�, ������, ����

typedef tuple<int, int, int, int> datas; // ����, �ӵ�, ����, ũ��

struct func {
	bool operator()(datas a, datas b) {
		return get<0>(a) != get<0>(b) ? get<0>(a) > get<0>(b) : get<3>(a) < get<3>(b);
		// ���� �� ���� (��������), ���ٸ� ũ�� �� ���� (��������)
	}
};

int R, C, M;
priority_queue<datas, vector<datas>,func> shark[2][MAP + 1]; // �� ���κ� ��� ����

int main() {
	cin >> R >> C >> M;

	for (int k = 0; k < M; k++) {
		int r, c, s, d, z; // ��ǥ, �ӵ�, ����, ũ��
		cin >> r >> c >> s >> d >> z;
		shark[0][c].push({ r,s,d,z });
	}

	int ans = 0;
	for (int k = 1, idx = 0; k <= C; k++, idx = !idx) { // ���ò��� ���� �� ĭ�� ��������
		if (!shark[idx][k].empty()) { // �ش� ���ο� �� �ִٸ� �� ���� ����
			int x, y, z, w;
			tie(x, y, z, w) = shark[idx][k].top();
			ans += w;
			while (!shark[idx][k].empty() && x == get<0>(shark[idx][k].top()))
				shark[idx][k].pop(); // �� �� ��Ƹ��� ������ ����
		}

		for (int c = 1; c <= C; c++) { // ���� ���θ� ���� ���캽
			while (!shark[idx][c].empty()) { // �� ������ ��� �� �̵�
				int r, s, d, z; // ����, �ӵ�, ����, ũ��
				tie(r, s, d, z) = shark[idx][c].top();
				while (!shark[idx][c].empty() && r == get<0>(shark[idx][c].top()))
					shark[idx][c].pop();
				// ���� ������ �ִ� ������ ���� ���� (ū �𿡰� ��Ƹ�����)
				int nx = r + (X[d] - '1') * s, ny = c + (Y[d] - '1') * s;

				// ���� ���� ó��
				while (nx <= 0 || nx > R) {
					if (nx <= 0) nx = 2 + abs(nx);
					else nx = R - abs(nx - R);
					d = d % 2 + 1;
				}
				while (ny <= 0 || ny > C) {
					if (ny <= 0) ny = 2 + abs(ny);
					else ny = C - abs(ny - C);
					d = d % 2 + 3;
				}
				shark[!idx][ny].push({ nx,s,d,z }); // ny ��° ���� nx ���̷� �� �̵�
			}
		}
	}
	cout << ans << endl;
}