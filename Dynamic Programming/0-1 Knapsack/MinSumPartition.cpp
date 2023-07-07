//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  
	{ 
	    int sum = 0;
	    for(int i=0; i<n; i++)
	    sum += arr[i];
	    
	    bool t[n+1][sum+1];
	    for(int i=0; i<=n; i++)
	    t[i][0] = true;
	    
	    for(int i=1; i<=sum; i++)
	    t[0][i] = false;
	    
	    for(int i=1; i<=n; i++)
	    {
	        for(int j=1; j<=sum; j++)
	        {
	            if(arr[i-1] <= j)
	            t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
	            else
	            t[i][j] = t[i-1][j];
	        }
	    }
	    
	    vector<int> sums;
	    for(int i=0; i<=sum/2; i++)
	    {
	        if(t[n][i] == true)
	        sums.push_back(i);
	    }
        	    
	    int mini = INT_MAX;
	    for(int i=0; i<sums.size(); i++)
	    {
	        mini = min(mini, sum-2*sums[i]);
	    }
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends