#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(pair<double,double> a, pair<double,double> b){
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> stop;
    vector<int> chal;

    for(int i = 0; i< N+1; i++){
        stop.push_back(0);
        chal.push_back(0);
    }
    vector<pair<double,double>> fail(N+1);

    for(int i=0; i<stages.size(); i++){
        stop[stages[i]] += 1;
    }
    
    for(int i=1; i<=N; i++){
        chal[i] = chal[i-1] + stop[i];
        fail[i].first = (double)stop[i] / (double)chal[i];
        fail[i].second = (double)stop[i] / (double)chal[i];
    }

    stable_sort(fail.begin(),fail.end(),desc);

    for(int i=0; i< N; i++){
        answer.push_back(fail[i].first);
    }

    return answer;
}
