#include <string>
#include <vector>
using namespace std;
// 2020 KAKAO BLIND RECRUITMENNT
// �ڹ���� ����

// �Է� ũ�Ⱑ �ִ� 20 �̹Ƿ�, ���� Ž������ ���ص� ���

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int N = key.size(), M = lock.size();

    int value, key_set[20][20][4] = {}; // 4 �������� ȸ����Ų ����

    // ȸ����Ų ���� ����
    for (int k = 0; k < N; k++) {
        for (int m = 0; m < N; m++) {
            key_set[k][m][0] = key[k][m]; // ���迡�� �� ����
            key_set[m][(N - 1) - k][1] = key_set[k][m][0];
            key_set[(N - 1) - k][(N - 1) - m][2] = key_set[k][m][0];
            key_set[(N - 1) - m][k][3] = key_set[k][m][0];
        }
    }

    for (int k = -N; k < M && !answer; k++) {
        for (int m = -N; m < M && !answer; m++) { // Ű�� �ڹ��� �ٱ����� �� ĭ�� �ű�� Ȯ��

            // Ű�� ȸ�� ��Ų �� ��쿡 ���� �Ǵ� (4����)
            for (int i = 0; i < 4 && !answer; i++) {
                bool flag = true;
                vector<vector<int>> cpy(lock);

                for (int v = 0; v < N && flag; v++) {
                    for (int h = 0; h < N && flag; h++) { // ������ �� ��ġ
                        int x = k + v, y = m + h; // �ش� ���� ��Ʈ�� �ʿ��� ������ ��ǥ
                        if (x < 0 || x >= M || y < 0 || y >= M) continue; // ���� �ʰ�

                        // 0�� ���� �����ϸ鼭, �� ���� ���� �ٸ� ��� ( 0,1 ���� )
                        if (!(cpy[x][y] & key_set[v][h][i]) && (cpy[x][y] ^ key_set[v][h][i])) {
                            cpy[x][y] = 1;
                        }
                        else flag = false;
                    }
                }
                if (flag) { // �����ϴٸ� ��ȣ ��ü�� ä�����°� Ȯ��
                    for (int v = 0; v < M && flag; v++) {
                        for (int h = 0; h < M && flag; h++) {
                            if (!cpy[v][h]) flag = false;
                        }
                    }
                }
                answer = flag; // ��� ���� ����
            }
        }
    }
    return answer;
}