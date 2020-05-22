#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
// ����
// ���� Ž������� ����Ϸ� ������, �ð��ʰ��� �߻�
// so, �������� Ž���� ������ ������ ������ ���� �� �ִٴ� ������ �������
// ���� ���� ���� ���� Ž���� �õ�

// �ٸ�, �߰������� Ž������ 1�� ������Ű�� ���� �ƴ�,
// �������� ���� �ٷ� �̵���Ű�� ���¸� ����ؾ߸� ȿ���� �׽�Ʈ�� ����� �� ����

long long int solution(vector<int> weight) {
    
    sort(weight.begin(), weight.end()); // ����

    long long int idx = 0, val = 0, mw = 1; // ���� �������� int ���� ���
    while (idx <= weight.size()) { // ���� ���� ����
        if (val < mw) { // ���� ���� ���� �����պ��� ũ�ٸ�,
            val += weight[idx++]; // ���� ���� �� Ű��
            continue;
        }
        if (val >= 2 * mw) break; 
        // "������ - Ž���� < Ž����" �� �����ؾ� �ش� ���� ���� �� ����
        // cause, �ش� ���� ������ ���� ��� ���� �� �ִٴ� ������ �ֱ� ����

        mw = val + 1; // ���� ���������� ������ �����ϹǷ� �������� �Ѿ
    }

    return mw;
}