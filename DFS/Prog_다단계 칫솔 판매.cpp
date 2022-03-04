//Programmers > 2021 Dev-Matching: 웹 백엔드 개발자(상반기) > 다단계 칫솔 판매
//https://programmers.co.kr/learn/courses/30/lessons/77486

	//dfs를 이용해 해결했다.
	//전역변수랑 주소값을 이용하기 싫었지만, 해야했던 문제.
	//코테는 실용 코딩과 다르다는 것을 다시 한번 기억하게 해준 문제였다.
	//또한, 올라가는 돈이 0원이라면 더 이상 호출할 필요가 없다는 것을 인지해야 한다.

#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> idx;
unordered_map<string, string> person;

void dfs(vector<string>& enroll, vector<string>& referral, string seller, int amount, vector<int>& answer)
{
	int tenp_money = amount / 10;
	answer[idx[seller]] += (amount - tenp_money);

	if (tenp_money != 0 && person[seller] != "-")
		dfs(enroll, referral, person[seller], tenp_money, answer);
	return;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<int> answer(enroll.size(), 0);

	for (int i = 0; i < enroll.size(); i++)
	{
		idx[enroll[i]] = i; //인덱스값. seller의 이름을 넣으면 몇 번 데이터인지 바로 찾을 수 있다.
		person[enroll[i]] = referral[i]; //referral의 이름과 enroll의 이름을 묶어줬다.
	}

	for (int i = 0; i < seller.size(); i++)
		dfs(enroll, referral, seller[i], amount[i] * 100, answer);

	return answer;
}