class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // all dists from 0,0
        // heap push k first dists -> every next push pops biggest

        std::priority_queue<std::pair<double,int>> distsH;
        for (int i = 0; i < points.size(); ++i)
        {
            double currDist = std::sqrt(std::pow(points[i][0]-0.0,2) + std::pow(points[i][1]-0.0,2));
            distsH.push({currDist, i});
            if (distsH.size() > k)
                distsH.pop();
        }

        std::vector<std::vector<int>> res;

        while (!distsH.empty())
        {
            int currI = distsH.top().second;
            distsH.pop();
            res.push_back(points[currI]);
        }

        return res;
    }
};
