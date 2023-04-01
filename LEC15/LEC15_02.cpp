#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
    
int mincost(int start, int end, vector<int>& cuts, int cuts_start, int cuts_end)
{
	if(cuts_start>cuts_end)
		return 0;
	
	if(dp[cuts_start][cuts_end]!=-1)
		return dp[cuts_start][cuts_end];
	
	int minimum = INT_MAX;
	for(int i=cuts_start; i<=cuts_end; i++)
		minimum = min(minimum, (end-start)+mincost(start, cuts[i], cuts, cuts_start, i-1)+mincost(cuts[i], end, cuts, i+1, cuts_end));
	
	return dp[cuts_start][cuts_end] = minimum;
}

int minCost(int n, vector<int>& cuts) {

	memset(dp,-1,sizeof(dp));
	sort(cuts.begin(),cuts.end());
	return mincost(0, n, cuts, 0, cuts.size()-1);
}

int main(){
	int n, c, t;
	vector<int> cuts;
	cin>>n;
	cin>>c;
	for(int i=0;i<c;i++){
		cin>>t;
		cuts.push_back(t);
	}
	cout<<minCost(n, cuts);
	return 0;
}