class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        
        // Create adjacency list
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        // Build graph & calculate in-degree
        for (const auto& prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            inDegree[prerequisite[0]]++;
        }
        
        // Initialize queue with courses having in-degree 0
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        
        // Topological sort
        while (!q.empty()) {
            int currCourse = q.front();
            q.pop();
            result.push_back(currCourse);
            for (int neighbor : graph[currCourse]) {
                if (--inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        
        // If result size is equal to the number of courses, return the result
        if (result.size() == numCourses)
            return result;
        
        // Otherwise, there's a cycle, return an empty vector
        return {};
    }
};
