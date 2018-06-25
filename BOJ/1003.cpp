#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    vector<vector<int>> pibo(41,vector<int>(2,0));
    pibo[0][0]=1;
    pibo[1][1]=1;
    for(int i=2;i<41;i++){
        pibo[i][0]=pibo[i-1][0]+pibo[i-2][0];
        pibo[i][1]=pibo[i-1][1]+pibo[i-2][1];
    }
    int T,N;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        cout<<pibo[N][0]<<" "<<pibo[N][1]<<"\n";
    }
    return 0;
}