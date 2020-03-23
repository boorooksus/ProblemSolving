#include <iostream>
using namespace std;

bool median(int, int d, int*);

int main() {
	std::ios::sync_with_stdio(false);
	int t; //t : test cases
	cin >> t;
	for (int i = 0; i < t; i++) {
		int cnt = 0; //cnt : 알람 횟수
		int n, d; //n : 총 날 짜 수, d : 고려할 지출 범위일
		cin >> n >> d;
		//save expenditure by day
		int* expenDay = new int[n + 1];
		//int expenDay[200000];
		int expenCnt[201]; //save expenditure by count
		fill_n(expenCnt, 201, 0);

		for (int j = 1; j <= n; j++) {
			cin >> expenDay[j];

			//아직 고려 지출 범위일 이전이면 continue
			if (j < d + 1) {
				expenCnt[expenDay[j]]++;
				continue;
			}
			//고려 지출 범위 이후 일 때
			else {
				//지출이 중앙값의 두 배 이상이면 알람 카운트 추가
				if (median(expenDay[j], d, expenCnt) == true) 
					cnt++;
			}
			//오래된 지출 범위 내의 값 줄이고 새로운 값 추가
			expenCnt[expenDay[j - d]]--;
			expenCnt[expenDay[j]]++;
		}
		cout << cnt << "\n";
	}
}

//지출이 중앙값의 두 배 이상이면 True 리턴
bool median(int expen, int d, int* expenCnt) {
	int cnt = 0; //누적 카운트 세기
	//d가 홀수일 때
	if (d % 2 == 1) {
		for (int i = 0; i < 201; i++) {
			cnt += expenCnt[i];
			if (cnt >= (d / 2 + 1)) {
				if(expen >= 2 * i) return true;
				else return false;
			}
		}
	}
	//d가 짝수일 때
	else {
		for (int i = 0; i < 201; i++) {
			int save = 0;
			cnt += expenCnt[i];
			if (cnt >= d / 2) {
				//중간값이 연속인 숫자 사이에 없을 때
				//ex) 1 2 <3> <4> 5 6
				if (cnt == d / 2) {
					//중간값 바로 직전 숫자 저장하고 컨티뉴
					save = i;
					continue;
				}
				else if (save != 0) {
					//중간값 바로 직전 숫자와 다음 숫자 더한 값의 2배 이상 되는지 확인
					//as int((double(save + i) / 2) * 2) == save + i
					if (expen >= save + i) return true;
					else return false;
				}
				//중간값이 연속인 숫자 사이에 있을 때
				//ex) 1 2 <2> <2> 3 4
				else {
					if (expen >= 2 * i) return true;
					else return false;
				}
			}
		}
	}
	return false; //의미 없음
}
