#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
// ����Ŭ ����

#define NUM 5000

int num, visit[NUM + 1]; // �� ��� ��, �湮 ����
vector<int> v[NUM + 1]; // ���� ���� 
vector<pair<int, int>> pq;

bool DFS(int idx, int p, int e) { // ���� ��ġ, �θ� ����, ���� ��� ���� 
    bool ans = true;
    visit[idx] = 1;
    for (int dir : v[idx]) { // ����� �������� ���캽
        if (dir == p || dir == e) continue; // �θ� �Ǵ� ���ܱ���
        if (visit[dir]) return false; // ��湮�� �Ѵٸ� ����Ŭ ����
        ans &= DFS(dir, idx, e); // �ڽ� �ʿ��� ����Ŭ�� ����ٸ� false�� ����
    }
    return ans;
}

bool Cycle(int idx) { // ����Ŭ ���� ����
    for (int k = 1; k <= num; k++) visit[k] = 0; // �ʱ�ȭ
    for (int k = 1; k <= num; k++) {
        if (visit[k] || k == idx) continue; // �̹� �湮�߰ų�, ����ó���� ��ġ
        if (!DFS(k, 0, idx)) return false;  // ����Ŭ�� ������ �ִٸ� ����
    }
    return true;
}

int solution(int n, vector<vector<int>> edges) {
    num = n;
    for (vector<int> edge : edges) {
        int a = edge[0], b = edge[1];
        v[a].push_back(b);
        v[b].push_back(a); // ���� ����
    }

    for (int k = 1; k <= num; k++) pq.emplace_back(k, v[k].size()); // ���� ���� ��, ����
    sort(pq.begin(), pq.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
        return a.second > b.second;
    });

    int answer = 0;
    for (pair<int,int> idx : pq) { // ���ʷ� ���캽
        if (!Cycle(idx.first)) continue;
        answer += idx.first;
    }
    return answer;
}