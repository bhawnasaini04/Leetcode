#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int dp[301][27][27];
    int getIndex(char c){
        return c-'A';

    }
    int distance(int a, int b){
        if(a == 26) return 0;
        int x1 = a/6, y1 = a%6;
        int x2 = b/6, y2 = b%6;
        return abs(x1-x2)+abs(y1-y2);
    }
int solve(string &word, int i, int f1, int f2){
    if(i== word.size()) return 0;
    if(dp[i][f1][f2] != -1)
    return dp[i][f1][f2];
    int curr = getIndex(word[i]);
    int useF1 = distance(f1,curr) + solve(word, i+1, curr, f2);
    int useF2 = distance(f2,curr)+ solve(word, i+1,f1,curr);
    return dp[i][f1][f2] = min(useF1,useF2);

}
int minimumDistance(string word){
    memset(dp, -1, sizeof(dp));
    return solve(word, 0, 26,26);
}
};