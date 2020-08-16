#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldcolor = image[sr][sc];
        flood_fill(image,sr,sc,newColor,oldcolor);
        return image;
    }

    void flood_fill(vector<vector<int>>& image, int sr, int sc, int newColor,int oldcolor){
        if(image[sr][sc] == newColor||image[sr][sc]!=oldcolor) return;
        image[sr][sc] = newColor;
        if(sr-1>=0) flood_fill(image,sr-1,sc,newColor,oldcolor);
        if(sr+1<image.size()) flood_fill(image,sr+1,sc,newColor,oldcolor);
        if(sc-1>=0) flood_fill(image,sr,sc-1,newColor,oldcolor);
        if(sc+1<=image[0].size()) flood_fill(image,sr,sc+1,newColor,oldcolor);

    }
};

int main(){
    vector<vector<int> > image = {{1,1,1},{1,1,0},{1,0,1}};
    Solution t;
    t.floodFill(image,1,1,2);
    system("pause");
    return 0;
}