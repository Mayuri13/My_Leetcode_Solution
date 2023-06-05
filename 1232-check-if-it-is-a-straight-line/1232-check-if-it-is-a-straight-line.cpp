class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        if(c.size()==2) return true;
        int x1=c[0][0], y1 = c[0][1];
        int x2 = c[1][0], y2 = c[1][1];
        int ym = y2-y1, xm = x2-x1;
        if(xm==0){
            for(int i=2; i<c.size(); i++){
                if(c[i][0]!=c[0][0])
                    return false;
            }
            return true;
        }
        float m = (float)ym/xm;
        for(int i=2; i<c.size(); i++){
            if(c[i][1] != (c[0][1] + m*c[i][0] - m*c[0][0]))
                return false;
        }
        
        return true;
    }
};