#include<iostream>
#include<set>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	set<int> s;
	set<pair<int, int> > big; // 수열의 최장 길이, 시작값
	//초기값 등록
	big.insert({ n + 1,0 });
	s.insert(-1);
	s.insert(n+1);

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		auto iter = s.upper_bound(num);
		int num1 = *iter;
		iter--;
		int num2 = *iter;
		s.insert(num);
		auto bigit = big.find({ num1 - num2 -1,num2+1 });
		int st = bigit->second;
		int ed = st + bigit->first - 1;

		big.erase({ bigit->first,bigit->second });
		int dist1 = num - st;
		int dist2 = ed - num;
		big.insert({ dist1,st });
		big.insert({ dist2, num + 1 });

		cout << big.rbegin()->first << '\n';
	}
}