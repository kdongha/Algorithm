//
// Created by dongha on 18. 6. 25.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> v(46,-1); //n<=45 이고 0부터 시작으므로 46, memoization을 위한 배

int pibo(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        if(v[n]==-1){   //memoization 확인
            v[n]=pibo(n-1)+pibo(n-2);   //memoization 입
        }
        return v[n];
    }
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    cout<<pibo(n)<<"\n";
    return 0;
}