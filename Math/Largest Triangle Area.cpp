/**
 * leetcode no.812
 */
 
double area(vector<int> P, vector<int> Q, vector<int> R) {
    return 0.5 * abs(P[0]*Q[1] + Q[0]*R[1] + R[0]*P[1] -P[1]*Q[0] - Q[1]*R[0] - R[1]*P[0]);
}

double largestTriangleArea(vector<vector<int>>& points) {
    int len = points.size();
    double res = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            for (int k = j + 1; k < len; ++k) {
                res = max(res, area(points[i], points[j], points[k]));
            }
        }
    }
    return res;
}
