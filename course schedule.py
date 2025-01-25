class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = defaultdict(list)
        for a, b in prerequisites:
            adj[a].append(b)

        visited = set()
        safe = set()

        def dfs(root):
            if root in visited:
                return False
            if root in safe:
                return True
            if adj[root]==[]:
                return True

            visited.add(root)

            for a in adj[root]:
                if not dfs(a): return False

            visited.remove(root)
            safe.add(root)

            return True


        for i in range(numCourses):
            if not dfs(i): return False
        return True

        


        