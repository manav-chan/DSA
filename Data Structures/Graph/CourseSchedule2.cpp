class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> adj[numCourses];
        for(auto x: prerequisites)
        {
            adj[x[1]].push_back(x[0]);
        }
        // Topo sort Kahn's algo
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<numCourses; i++)
        {
            for(auto x: adj[i])
            indegree[x] ++;
        }
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
            q.push(i);
        }

        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto x: adj[node])
            {
                indegree[x] --;
                if(indegree[x] == 0)
                q.push(x);
            }
        }
        if(topo.size() == numCourses)
        return topo;
        else
        return {};
    }
};