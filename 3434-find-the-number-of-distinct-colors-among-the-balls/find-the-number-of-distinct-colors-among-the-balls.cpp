class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result;
        unordered_map<int, int> colorMap, ballMap;
        for (auto ele: queries) {
            int ball = ele[0], color = ele[1];
            if (ballMap.find(ball) != ballMap.end()) {
                int prevColor = ballMap[ball];
                colorMap[prevColor]--;
                if (colorMap[prevColor] == 0) colorMap.erase(prevColor);
            }
            ballMap[ball] = color;
            colorMap[color]++;
            result.push_back(colorMap.size());
        }
        return result;
    }
};