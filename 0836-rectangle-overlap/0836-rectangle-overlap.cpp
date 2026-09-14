class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1{rec1[0]}, y1{rec1[1]}, a1{rec1[2]}, b1{rec1[3]};
        int x2{rec2[0]}, y2{rec2[1]}, a2{rec2[2]}, b2{rec2[3]};
        return (y1 >= b2) || (y2 >= b1) || (x1 >= a2) || (x2 >= a1) ? false : true;
    }
};