#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
// 2020 KAKAO BLIND RECRUITMENT
// ���� �˻�

// ȿ���� �׽�Ʈ�� ���ؼ� �� ������ ���� �Ǵ��� ������ �̷������ ��
// Trie �� �����Ͽ����� ���ϵ�ī�� �κ��� �� ���� Queue �� ó���� �õ��Ͽ����� �ð��ʰ�
// so, �� �������� �Էµ� ���ڿ��� ������ ������ map ���� ����صδ� ����� ����

#define ALP 26

class Trie { // ���ڿ� Trie 
public:
    Trie* t[ALP]; // �� ���ĺ����� �̵��ϴ� ���
    unordered_map<int, int> cnt; // ���� �������� ������ ���� N �� ���ڿ� ���� 

    Trie(){ // �ʱ� ������
        for (int k = 0; k < ALP; k++) t[k] = NULL;
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    // ��� ���ڿ��� ���� ���յ� Ʈ���̸� ����
    Trie f, b; // ��, �ڷ� �о�� Ʈ����
    for (string str : words) { 
        Trie* pos_f = &f, * pos_b = &b;

        int len = str.length();
        for (int k = 0; k < str.length(); k++) { // �� ���ڿ� ����
            pos_f->cnt[len] += 1;
            pos_b->cnt[len] += 1; // �ش� ��忡 ������ Case ����

            int idx_f = str[k] - 'a';
            int idx_b = str[str.length() - (k + 1)] - 'a'; // ������ �̵��� ����

            // ���� �������� ���� ����� ���Ӱ� ����
            if (pos_f->t[idx_f] == NULL) {
                Trie* n = new Trie();
                pos_f->t[idx_f] = n;
            }
            if (pos_b->t[idx_b] == NULL) {
                Trie* n = new Trie();
                pos_b->t[idx_b] = n;
            }

            pos_f = pos_f->t[idx_f];
            pos_b = pos_b->t[idx_b]; // �̵�
        }
    }

    // ���� ó��
    for (string str : queries) {
        Trie* trie;
        int k = 0, len = str.length(); // �� ������ ����

        if (str[0] == '?') { // ���λ�� ���� ���
            trie = &b; // �ڿ������� ã��

            for (; k < str.length(); k++) {
                if (str[len - (k + 1)] == '?') break; // ?�� ������ ����
                trie = trie->t[str[len - (k + 1)] - 'a']; // �̵�

                if (trie == NULL) { // ���� ���ٸ� �̵� �Ұ�
                    Trie* n_t = new Trie();
                    trie = n_t;
                    break; // �� Ʈ���̷� �ű�� ���� 
                }
            }
        }
        else { // ���̻�� �������
            trie = &f; // �տ������� ã��

            for (; k < str.length(); k++) {
                if (str[k] == '?') break; // ?�� ������ ����
                trie = trie->t[str[k] - 'a']; // �̵�

                if (trie == NULL) { // ���� ���ٸ� �̵� �Ұ�
                    Trie* n_t = new Trie();
                    trie = n_t;
                    break; // �� Ʈ���̷� �ű�� ����
                }
            }
        }
        answer.push_back(trie->cnt[len]); // ���̰� ��ġ�ϴ� ���ڿ� ���� ����
    }
    return answer;
}