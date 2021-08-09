//Programmers > ����/�ʺ� �켱 Ž��(DFS/BFS) > �ܾ� ��ȯ
//https://programmers.co.kr/learn/courses/30/lessons/43163


    //Ư�� words�� ã�� ���� �ƴ϶�, words������ ��θ� ã�ƾ� �Ѵ�.
    //DFS


#include <string>
#include <vector>

using namespace std;

int answer{ 100 }; //�ܾ�� 50������ �־����� �����Ƿ�, 50���� ū ���� �־���.


//���۴ܾ�, ��ǥ�ܾ�, �ܾ��Ʈ, �ܾ��Ʈ��뿩��, ��ǥ���� �� Ƚ��(����)
void dfs(string begin, string target, vector<string> words, vector<bool>& useCheck, int cnt = 0) {
    //�ܾ��� �����ŭ �ݺ�
    for (int i = 0; i < words.size(); i++) {
        //���ĺ����� ��ġ���� �ʱ�ȭ
        int count{ 0 };
        //�ѱ��ھ� ���ϸ鼭 ���ڰ� �ٸ���� ī��Ʈ ����
        for (int j = 0; j < words[i].length(); j++)
            if (!useCheck[i] && begin[j] != words[i][j])    count++;
        //ī��Ʈ�� 1�̶��(�� ���ڸ� �ٸ����)
        if (count == 1) {
            //1���ڸ� �ٸ� �ܾ target�ܾ��̰� answer�� ���ݱ��� ���� ����+1���� ū��� answer����
            if (target == words[i] && answer > cnt + 1) {
                answer = cnt + 1;
                return;
            }
            //�ܾ ����ߴ� üũ�ϰ� ���
            useCheck[i] = true;
            dfs(words[i], target, words, useCheck, cnt + 1);
            //�Լ��� ���°�� �ܾ��뿩�� ����
            useCheck[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    //����� �ܾ� üũ��(words�� ���̸�ŭ �����ϰ� fasle�� �ʱ�ȭ�Ѵ�.)
    vector<bool> useCheck(words.size(), false); 
    dfs(begin, target, words, useCheck);
    //answer�� 100�̸� target���� ���������Ƿ� 0�� �����Ѵ�.
    if (answer == 100)   return 0;
    //�������� ���õȴٸ� target���� ����ª�� Ƚ���� ����
    return answer;
}


//https://mungto.tistory.com/53