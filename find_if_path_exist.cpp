class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        if (source == destination)
        {
            return true;
        }

        vector<vector<int>> adj(n);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> meow;
        queue<int> q;

        q.push(source);
        meow.insert(source);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int neighbour : adj[node])
            {
                if (neighbour == destination)
                {
                    return true;
                }
                if (!meow.contains(neighbour))
                {
                    meow.insert(neighbour);
                    q.push(neighbour);
                }
            }
        }

        return false;
    }
};