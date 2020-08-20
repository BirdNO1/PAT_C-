#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[1],y = click[0];
        switch(board[y][x]){
            case 'M': return case1(board,y,x);
                break;
            case 'E': return case2(board,y,x);
                break;
            default: break;
        }
        return board;
    }

    vector<vector<char>> case1(vector<vector<char>>& board, int y,int x){
        board[y][x] = 'X';
        return board;
    }

    vector<vector<char>> case2(vector<vector<char>>& board, int y,int x){
           queue<node> t;
           t.push({y,x});
           while(t.size()){
               node tem = t.front(); t.pop();
               if(board[tem.y][tem.x]!='E') continue;
               char c = test(board,tem.y,tem.x);
               if(c == 'B'){
                   board[tem.y][tem.x] = 'B';
                    for(int i=-1; i<2; i++){
                        for(int j=-1; j<2; j++){
                            if((tem.y+i)>=0&&(tem.y+i)<board.size()&&(tem.x+j)>=0&&(tem.x+j)<=board[0].size()){
                                if(i==0&&j==0) continue;
                                t.push({tem.y+i,tem.x+j});
                            }
                        }
                    }
               }else{
                   board[tem.y][tem.x] = c;
               }
               
           }
           return board;
    }

    char test(vector<vector<char>>& board, int y,int x){
        int cnt = 0;
        for(int i=-1; i<2; i++){
            for(int j=-1; j<2; j++){
                if((y+i)>=0&&(y+i)<board.size()&&(x+j)>=0&&(x+j)<=board[0].size()){
                    if(board[y+i][x+j]=='M'){
                        cnt++;
                    }
                }
            }
        }
        if(cnt){
            return cnt+'0';
        }else{
            return 'B';
        }
    }

    struct node{
        int y, x;
    };

};

int main(){
    vector<vector<char> > t1 = {{'E', 'E', 'E', 'E', 'E'},
                            {'E', 'E', 'M', 'E', 'E'},
                            {'E', 'E', 'E', 'E', 'E'},
                            {'E', 'E', 'E', 'E', 'E'}};
    vector<int> t2 = {1,2};
    Solution s;
    s.updateBoard(t1,t2);
    system("pause");
    return 0;


}

