//
// Created by kdongha on 2019/12/14.
//

#include <bits/stdc++.h>

using namespace std;

bool cmp(const string &s1, const string &s2) {
    if (s1.size() == s2.size()) {
        return s1 < s2;
    } else {
        return s1.size() < s2.size();
    }
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> front;
    vector<string> back;
    set<string> check;
    for (auto word:words) {
        if (check.find(word) == check.end()) {
            check.insert(word);
            front.push_back(word);
            reverse(word.begin(), word.end());
            back.push_back(word);
        }
    }
    sort(front.begin(), front.end(), cmp);
    sort(back.begin(), back.end(), cmp);
    for (auto query:queries) {
        string f(query);
        string b(query);
        replace(f.begin(), f.end(), '?', 'a');
        replace(b.begin(), b.end(), '?', 'z');
        if (query[0] == '?') {
            reverse(f.begin(), f.end());
            reverse(b.begin(), b.end());
            long y = lower_bound(back.begin(), back.end(), b, cmp) - back.begin() + 1;
            long x = lower_bound(back.begin(), back.end(), f, cmp) - back.begin() + 1;
            answer.push_back(y - x);
        } else {
            long y = lower_bound(front.begin(), front.end(), b, cmp) - front.begin() + 1;
            long x = lower_bound(front.begin(), front.end(), f, cmp) - front.begin() + 1;
            answer.push_back(y - x);
        }
    }
    return answer;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solution({"frodo", "front", "frost", "frozen", "frame", "kakao"}, {"fro??", "????o", "fr???", "fro???", "pro?"});
    return 0;
}