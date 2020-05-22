#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
// Ż��
// BFS �� ����Ͽ� S ���� D �� ���� �ִܰ�θ� �ľ�
// �ٸ�, �ð��� ���� ���� �Բ� Ȯ���Ѵٴ� ����
// �ð��� ����س��� ��Ŀ��� ���� �������� ���� ������ ���� ����ó���� ���� �ʿ�����

#define NUM 50
#define MAX NUM * NUM // �ִ� ��

#define X "0121" // X�� �̵�
#define Y "1210" // Y�� �̵�

char map[NUM][NUM]; // �Է�
int R, C, time[NUM][NUM], visit[NUM][NUM]; // ����, ����, ���� ���� �ð�, ����ġ �湮 ����
queue<tuple<int, int, int>> S, W; // ����ġ ��ǥ ť, �� ��ǥ ť

int main() {
	cin >> R >> C;
	for (int k = 0; k < R; k++) {
		for (int m = 0; m < C; m++) {
			cin >> map[k][m];
			if (map[k][m] == '*') W.push(tuple<int, int, int>(k, m, 0));
			else if (map[k][m] == 'S') S.push(tuple<int, int, int>(k, m, 0));
			else if (map[k][m] == 'D') time[k][m] = MAX;
		} // �Է�
	}

	// �� ä���
	while (!W.empty()) {
		tuple<int, int, int> water = W.front();
		W.pop();
		int w_x = get<0>(water), w_y = get<1>(water); // ���� ��ǥ��
		for (int k = 0; k < 4; k++) {
			int n_x = w_x + X[k] - '1', n_y = w_y + Y[k] - '1';
			if (n_x < 0 || n_x >= R || n_y < 0 || n_y >= C) continue; // ���ָ� �Ѿ�� ����
			if (time[n_x][n_y] || map[n_x][n_y] == '*' || map[n_x][n_y] == 'X') continue; // �̹� �湮�߰ų�, �������ٸ� �ǳʶ�
			time[n_x][n_y] = get<2>(water) + 1; // ���� �����ϴµ� �ɸ��� �ð��� ���
			W.push(tuple<int, int, int>(n_x, n_y, time[n_x][n_y])); // ����
		}
	}

	// ����ġ �̵�
	int ans = 0; // �ִܰŸ� (����)
	while (!S.empty()) { // ��� ����ġ�� ���ɼ��� �Ǵ�
		tuple<int, int, int> ani = S.front();
		S.pop();

		int a_x = get<0>(ani), a_y = get<1>(ani); // ����ġ ��ǥ��
		if (map[a_x][a_y] == 'D') {
			ans = get<2>(ani);
			break; // �������� �����ߴٸ� �ð��� �����ϰ� ����
		}

		for (int k = 0; k < 4; k++) { // ��� ���⿡ ���� �̵�
			int n_x = a_x + X[k] - '1', n_y = a_y + Y[k] - '1';
			if (n_x < 0 || n_x >= R || n_y < 0 || n_y >= C) continue; // ���ָ� �Ѿ�� ����
			if (visit[n_x][n_y]) continue; // �̹� �湮�� ���� �Ѿ
			visit[n_x][n_y] = 1;

			if ((time[n_x][n_y] <= get<2>(ani) + 1) && !(!time[n_x][n_y] && map[n_x][n_y] == '.')) continue; 
			// �ش� ������ �� ������ ���� ���ִ� ��� ( ��, '.' �̸鼭 0 �� ����, ���� �������� ���� ���̹Ƿ� ����ó�� )
			S.push(tuple<int, int, int>(n_x, n_y, get<2>(ani) + 1)); // ť�� ����
		}
	}
	if (ans) cout << ans << endl; // ���ǿ� ���� ���
	else cout << "KAKTUS" << endl;
}