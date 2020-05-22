#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// �̷� Ż��
// ��ư�� ���� ���, ��� ��ġ�� �ƴ� ������ ��ĸ� �������Ƿ�
// �� ��� ���� ��ư Ȱ��ȭ ���� ���� �����ϰ� ó���ؾ� ��

// �ش� ������ BFS Ž�� �����̸�, �� Ž������ �־����� ���� ������ ��� �ٸ� �� ����
// so, �̸� ��Ʈ ����ŷ���� ���ٴϴ� ����� ����ϸ�
// dp ������ ���� ������ �ʿ䰡 ����

// ���� �ִ� ũ��� 7*7 �̹Ƿ�, �࿭ ������ ���� 7 Bit ������ ���

#define NUM 7
#define ROOM ( 1<< 8 )
#define INF 2000
#define X "1210"
#define Y "0121"

#define VER (1 << 3) + (1 << 1) // ��, �Ʒ� ( 1010 )
#define HOR (1 << 2) + (1 << 0) // ��, ������ ( 0101 )
#define ALL VER + HOR // ��� ( 1111 )
#define NON 0 // �� ����

typedef tuple<int, int, int, int, int> dp_data;
// ��ǥ, ���� ������ ������ ����, �ɸ� �ð�

struct func {
	bool operator()(dp_data a, dp_data b) { // �ɸ� �ð��� ���� ������ ����
		return get<4>(a) > get<4>(b);
	}
};

int N, M, map[NUM][NUM][2];
int dp[NUM][NUM][ROOM][ROOM]; // �̸�������̼� ( ��ǥ, �� ��Ʈ, �� ��Ʈ )
priority_queue<dp_data, vector<dp_data>, func> q; // BFS Ž����

int main() {
	cin >> N >> M;
	for (int k = 0; k < N; k++) { // �� ����
		for (int m = 0; m < M; m++) {
			char ch;
			cin >> ch;
			if (ch == 'A') { // ��濡 ��
				map[k][m][0] = ALL;
				map[k][m][1] = ALL;
			}
			if (ch == 'B') { // �� ����
				map[k][m][0] = NON;
				map[k][m][1] = NON;
			}
			if (ch == 'C') { // ���� ��
				map[k][m][0] = VER;
				map[k][m][1] = HOR;
			}
			if (ch == 'D') { // ���� ��
				map[k][m][0] = HOR;
				map[k][m][1] = VER;
			}
		}
	}

	// BFS Ž�� (�̸�������̼�)
	q.emplace(0, 0, 0, 0, 0);
	while (!q.empty()) {
		int x, y, ver, hor, t; // ��ǥ, ��ư�� Ȱ��ȭ�� ����, �ɸ� �ð�
		tie(x, y, ver, hor, t) = q.top();
		q.pop();

		if (dp[x][y][ver][hor]) continue; // �̹� �湮�ߴٸ� ����
		dp[x][y][ver][hor] = t; // �ð� ���

		if (x == N - 1 && y == M - 1) { // ���ϴ� ���� ������ ���
			cout << t << endl; // ��� �� ����
			return 0;
		}

		int room = ((ver & (1 << x) ? 1: 0) + (hor & (1 << y) ? 1: 0)) % 2; // ���� ���� � �����ΰ�?
		for (int k = 0; k < 4; k++) { // ��, ��, ��, ��
			if (map[x][y][room] & (1 << k)) { // �ش� ���⿡ ���� �ִ� ���
				int n_x = x + X[k] - '1', n_y = y + Y[k] - '1'; // ���ο� ��ǥ
				if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue; // ���ָ� ����� ����

				// �̵��� �濡 ���ؼ��� ���� �˻���
				int n_room = ((ver & (1 << n_x) ? 1 : 0) + (hor & (1 << n_y) ? 1 : 0)) % 2; 
				if (map[n_x][n_y][n_room] & (1 << k)) { // �̵��� �� ���� ���� �ִٸ�
					q.emplace(n_x, n_y, ver, hor, t + 1);
				}
				if (map[n_x][n_y][(n_room + 1) % 2] & (1 << k)) { // ��ư�� ������ �����ϴٸ�
					q.emplace(n_x, n_y, ver ^ (1 << x), hor ^ (1 << y), t + 2);
				}
			}
		}
	}
	cout << -1 << endl; // �߰��� ������ �ʴ´ٸ� ���� ã�� ���� �� ( ���� )
	return 0;
}