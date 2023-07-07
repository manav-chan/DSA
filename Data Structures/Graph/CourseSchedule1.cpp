class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> adj[numCourses];
        for(auto x: prerequisites)
        {
            adj[x[1]].push_back(x[0]);
        }    

        /* Topological Sort Kahns Algorithn */
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

        int count = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count ++;

            for(auto x: adj[node])
            {
                indegree[x] --;
                if(indegree[x] == 0)
                q.push(x);
            }
        }
        if(count == numCourses)
        return true;
        else
        return false;
    }
};