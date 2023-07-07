//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    void dfsTopo(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st)
    {
        visited[node] = 1;
        
        for(auto x: adj[node])
        {
            if(!visited[x])
            dfsTopo(x, adj, visited, st);
        }
        st.push(node);
    }
    public:
    string findOrder(string dict[], int N, int K) 
    {
        vector<int> adj[K];
        for(int i=0; i<N-1; i++)
        {
            string s1 = dict[i], s2 = dict[i+1];
            int c1 = 0, c2 = 0;
            while(c1 < s1.length() && c2 < s2.length())
            {
                if(s1[c1] != s2[c2])
                {
                    int src = s1[c1] - 'a', dst = s2[c2] - 'a';
                    adj[src].push_back(dst);
                    break;
                }
                c1 ++, c2 ++;
            }
        }
        
        vector<bool> visited(K, 0);
        stack<int> st;
        for(int i=0; i<K; i++)
        {
            if(!visited[i])
            dfsTopo(i, adj, visited, st);
        }
        string order = "";
        while(!st.empty())
        {
            order += (char)(st.top() + 'a');
            st.pop();
        }
        return order;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends