#include<cstdio>
#include<algorithm>
using namespace std;
// ���� ū ���簢��
// ���簢���� ��������� ���ؼ�, ����,����,�밢���� ��� ������ ä���� �־�� ��
// so, �� ������ ��� �����ؾ��ϸ� �̴� �ּڰ� �������� �Ǵ��� ����

#define MAX 1000

int N, M;
pair<int, int> arr[MAX + 1][MAX + 1]; // �ش� ����� ����, ���� ���ӵ� 1�� ����

int main() {
	scanf("%d %d", &N, &M);
	int result = 0;
	char d;
	for (int k = 1; k <= N; k++) {
		getchar(); // '\n' �� ���ۿ��� ������ ����ó�� �ϴ� �뵵
		// ���� ���� map �� �ϳ��� ���� ����ؾ� �ϹǷ�, int ���� �ƴ� char ������ �޾ƾ� �ϸ�
		// ���� �Է����� ���� ���� ���뿡 ���� ����ó���� �ʿ���

		for (int m = 1; m <= M; m++) {
			scanf("%c", &d);
			if ( d == '1') { // �Է� ���ڰ� 1�� ���
				int top = min(arr[k - 1][m].first, arr[k][m - 1].first); 
				top = min(top, arr[k - 1][m - 1].first); 
				int left = min(arr[k - 1][m].second, arr[k][m - 1].second);
				left = min(left, arr[k - 1][m - 1].second);
				// �ڽ��� ����, ��, �밢�� ���⿡�� ���ӵ� ����, ���ӵ� ������ �ּҰ��� ���ؿ� 
				// cause, ���簢���� ũ�Ⱑ Ȯ��Ǳ� ���ؼ� �� 3 ������ ������ ��� �����ؾ� �ϱ� ����

				arr[k][m] = pair<int, int>(top + 1, left + 1); // �迭�� ����
				result = max(result, min(arr[k][m].first, arr[k][m].second));
				// ���� ���� �� ��, ���� ���� ������ �ش� �������� ���� �� �ִ� ���簢���� ũ��
				// ���� ū ���� �Ź� ����
			}
		}
	}
	printf("%d\n", result * result); // ���� ���
}