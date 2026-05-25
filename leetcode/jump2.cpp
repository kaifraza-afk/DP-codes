class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<int> vis(n, 0);
        queue<int> q;

        q.push(0);
        vis[0] = 1;

        int farthest = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == n - 1)
                return true;

            int start = max(node + minJump, farthest + 1);
            int end = min(node + maxJump, n - 1);

            for (int i = start; i <= end; i++) {
                if (s[i] == '0' && !vis[i]) {
                    vis[i] = 1;
                    q.push(i);
                }
            }

            farthest = end;
        }

        return false;
    }
};