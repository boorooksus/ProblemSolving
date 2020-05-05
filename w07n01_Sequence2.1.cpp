#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int sq[9]; //N개의 자연수를 저장하는 수열
int new_sq[9]; //새로 조합한 수열
int used[9]; //원래 수열의 원소가 새로운 수열에 사용됐는지 저장(0이면 미사용, 1이면 사용)
int cnt = 0; //조건을 만족하는 시퀸스 가짓수
//n : 수열의 자연수 개수, min_res : 조건 범위의 최소값, max_res : 조건 범위의 최대값, x : 특정 수 x
int n, min_res, max_res, x; 


//새로 만들어진 수열이 조건을 만족하는지 확인하는 함수
void isValid() {
	//수열을 조건에 따라 숫자로 변환
	int res = 0;
	for (int i = 0; i < n; i++) {
		res = (res + (new_sq[i] * (int(pow(x, i)) % 1013)) % 1013) % 1013;
	}

	//변환한 숫자가 특정 범위 안에 있으면 cnt에 1을 더한다
	if (res >= min_res && res <= max_res) {
		cnt++;
	}

	return;
}

//dfs를 이용한 백트래킹으로 시퀸스 구하기
//idx : sq의 원소 인덱스, lv : 진행 단계
void dfs(int idx, int lv) {
	//이미 사용한 원소이면 리턴
	if (used[idx] != 0) return;

	//마지막 단계일 때
	if (lv == n - 1) {
		new_sq[n - 1] = sq[idx];
		//조건을 만족하는 수열인지 확인
		isValid();
		return;
	}

	used[idx] = 1; //원소 사용 여부 1로 저장
	new_sq[lv] = sq[idx]; //새로운 수열 배열에 저장

	//재귀를 통해 새로운 수열의 다음 원소 구하기
	for (int i = 0; i < n; i++) {
		dfs(i, lv + 1);
	}

	//현재 단계가 끝나면 사용된 원소의 사용 여부 0으로 초기화
	used[idx] = 0;

	return;
}

int main() {
	std::ios::sync_with_stdio(false);
	int T; //테스트 케이스
	cin >> T;
	while (T--) {
		cin >> n; //자연수 개수 입력

		//수열의 원소 입력
		for (int i = 0; i < n; i++) {
			cin >> sq[i];
		} 
		//조건 범위와 특정 수 x 입력
		cin >> min_res >> max_res >> x;

		//백트래킹을 통해 수열 조합
		for (int i = 0; i < n; i++) {
			dfs(i, 0);
		}
		//조건을 만족하는 수열 개수 출력
		cout << cnt << "\n";

		//sq, cnt를 0으로 초기화
		fill_n(sq, 9, 0);
		cnt = 0;
	}
}