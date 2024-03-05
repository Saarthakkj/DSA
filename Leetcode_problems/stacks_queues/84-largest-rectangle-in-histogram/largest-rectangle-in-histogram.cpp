class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int maxArea = 0;
        std::stack<std::pair<int, int>> stack; // pair: (index, height)
        int n = heights.size();

        for (int i = 0; i < n; ++i) {
            int start = i;
            while (!stack.empty() && stack.top().second > heights[i]) {
                int index = stack.top().first;
                int height = stack.top().second;
                stack.pop();
                maxArea = std::max(maxArea, height * (i - index));
                start = index;
            }
            stack.push({start, heights[i]});
        }

        while (!stack.empty()) {
            int index = stack.top().first;
            int height = stack.top().second;
            stack.pop();
            maxArea = std::max(maxArea, height * (n - index));
        }
        return maxArea;
    }
};