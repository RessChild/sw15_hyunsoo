#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
// 2018 KAKAO BLIND RECRUITMENT
// ��Ʋ����

// ���ڿ��� �ð�ó�� + ��Ģ�� �� ���� ���� ����

string solution(int n, int t, int m, vector<string> timetable) {

    priority_queue<int, vector<int>, greater<int>> pq; // ������������ �ð� ����
    for (string time : timetable) {
        string str; // ���� ���ڿ��� ������ ����
        stringstream ss(time); // ���ڿ��� ���� ��Ʈ����Ʈ��

        int t = 0; // �ð�,
        getline(ss, str, ':');
        t += atoi(str.c_str()) * 100; // �ð�
        getline(ss, str, ':');
        t += atoi(str.c_str()); // ��

        pq.push(t); // ���� �ð��� ����
    }

    bool left = false; // �� �¼��� �ִ°�?
    int ans = 0; // ������ Ž���� �°� ��, ���� �������� ������ �ð�
    int s_h = 9, s_m = 0; // ���� �ֱٿ� ���� ���� �ð�
    int t_h = 9, t_m = 0; // ���� ���� �ð�
    for (int k = 0; k < n; k++) {
        left = false; // ������ ������ �� �¼� ���ΰ� �߿��ϹǷ�, �Ź� Ȯ��

        int bus_time = 100 * t_h + t_m; // ���� ���� �ð�
        for (int i = 0; i < m; i++) { // ž�� ����ŭ ����
            if (pq.empty()) { // �� �������ߴ��� ť�� �� ���
                left = true; // �� �ڸ� ����
                break;
            }
            if (pq.top() > bus_time) { // �¿� �°��� ���� ���� ���ߴٸ�,
                left = true; // ���� �¼��� ����
                break; // ����
            }
            ans = max(ans, pq.top()); // ������� ���� �ʰ� ������ �°� �ð�
            pq.pop();
        }

        s_h = t_h;
        s_m = t_m; // ���� �������� ����� ���� �ð� ����

        t_m += t;
        t_h += t_m / 60;
        t_m %= 60; // �ð� ����
    }

    string answer = "";
    int hour, minute;
    if (left) { // �������� �� �ڸ��� �־��ٸ�
        hour = s_h;
        minute = s_m; // ������ ���� �ð��� ������� ��
    }
    else { // �� �ڸ��� �����ٸ�, ���� �������� ������ �°����� 1�� ����
        minute = (ans % 100) + 59;
        hour = (ans / 100) - 1 + (minute / 60);
        minute %= 60;
    }

    if (hour < 10) answer += "0"; // ���¿� ���� ���� ����
    answer += to_string(hour) + ":";
    if (minute < 10) answer += "0";
    answer += to_string(minute);
    return answer;
}
