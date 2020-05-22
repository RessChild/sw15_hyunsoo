#include <string>
#include <vector>
#include <queue>
#include <utility>
// 2019 KAKAO BLIND RECRUITMENT
// ������ �Թ� ���̺�

// ��Ģ���� Ȱ���Ͽ� �� Ƚ���� ���̴� ���� ��ǥ
// ȿ���� �׽�Ʈ�� �Է°� ���ְ� int ���� �Ѿ�Ƿ�, long long int Ÿ���� ����ؾ� ��

using namespace std;

int solution(vector<int> food_times, long long k) {
    queue<pair<int, int>> q[2];
    for (int m = 0; m < food_times.size(); m++) {
        q[0].push({ m, food_times[m] }); // �ʱ� ����
    }

    long long int m = 0, loop, left = k; // ȿ���� �׽�Ʈ���� ���� ����
    for (; !q[m].empty(); m = !m) {
        loop = left / q[m].size(); // ��ü �ݺ� ���� Ƚ��
        left = left % q[m].size(); // ���� ó�� Ƚ��

        if (!loop) break; // ��ü�� ���� �Ұ����ϸ� ����

        while (!q[m].empty()) { // ť�� ��� ���ҿ� ����
            pair<int, int> d = q[m].front();
            q[m].pop();

            int v = d.second - loop; // ���� ���ľ翡�� �Ծ�� �ϴ� Ƚ���� ����
            if (v > 0) q[!m].push({ d.first, v }); // ����� ���, �������� ���� �� ����
            else if (v < 0) left -= v; // ������ ���, �����Ѹ�ŭ �ٸ� ������ �Ծ�� ��
        }
    }

    if (q[m].empty()) return -1; // ������ ť�� ����ִٸ� ���� ������ ����
    else {
        while (left--) q[m].pop(); // ���� Ƚ����ŭ ������ ����
        return q[m].front().first + 1; // ��� ��
    }
}