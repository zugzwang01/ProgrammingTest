#ifndef _529_H_
#define _529_H_
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
namespace Sansan
{
    class Solution_529
    {
    public:
           /*解决方法的基本思想BFS*/
            vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
            {
                vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
                if(board.empty())
                    return board;
                queue<int>recurPos;
                int rowSize=board.size();
                int colSize=board[0].size();
                recurPos.push(click[0]);recurPos.push(click[1]);
                visited[click[0]][click[1]]=true;
                while(!recurPos.empty())
                {
                    int row=recurPos.front();
                    recurPos.pop();
                    int col=recurPos.front();
                    recurPos.pop();
                    if(board[row][col]=='M')
                    {
                        board[row][col]='X';
                        return board;
                    }
                    int mines=0;
                    //如下代码的简化写法：其中h是行数，w是列数
                    /*	
                    for (int m = -1; m <= 1; m++) 
                    {
                       for (int n = -1; n <= 1; n++)
                       {
                            int x = i+m, y = j+n;
                            if (x>=0 && x<h && y>=0 && y<w && board[x][y] == 'M')
                                    res++;
                       }
                    }*/
                    if(row-1>=0 && col-1>=0 && board[row-1][col-1]=='M')
                        mines++;
                    if (row-1>=0 && col>=0 && board[row-1][col]=='M')
                        mines++;
                    if(row-1>=0 && col+1<=colSize-1 && board[row-1][col+1]=='M')
                        mines++;
                    if(row>=0 && col-1>=0 && board[row][col-1]=='M')
                        mines++;
                    if(row>=0 && col+1<=colSize-1 && board[row][col+1]=='M')
                        mines++;
                    if(row+1<=rowSize-1 && col-1>=0 && board[row+1][col-1]=='M')
                        mines++;
                    if(row+1<=rowSize-1 && col>=0 && board[row+1][col]=='M')
                        mines++;
                    if(row+1<=rowSize-1 && col+1<=colSize-1 && board[row+1][col+1]=='M')
                        mines++;
                    if(mines)
                    {
                       board[row][col]=mines+'0';
                    }
                    else
                    {
                        
                    //如下代码的简化写法：其中h是行数，w是列数
                    /*	
                    for (int m = -1; m <= 1; m++) 
                    {
                       for (int n = -1; n <= 1; n++)
                       {
                            int x = i+m, y = j+n;
                            if (x>=0 && x<h && y>=0 && y<w && board[x][y] == 'M')
                                    res++;
                       }
                    }*/
                       board[row][col]='B';
                       if(row-1>=0 && col-1>=0 && !visited[row-1][col-1])
                       {
                           recurPos.push(row-1);recurPos.push(col-1);
                           visited[row-1][col-1]=true;
                       }
                       if(row-1>=0 && col>=0 && !visited[row-1][col])
                       {
                           recurPos.push(row-1);recurPos.push(col);
                           visited[row-1][col]=true;
                       }
                       if(row-1>=0 && col+1<=colSize-1 && !visited[row-1][col+1])
                       {
                           recurPos.push(row-1);recurPos.push(col+1);
                           visited[row-1][col+1]=true;
                       }
                       if(row>=0 && col-1>=0 && !visited[row][col-1])
                       {
                           recurPos.push(row);recurPos.push(col-1);
                           visited[row][col-1]=true;
                       }
                       if(row>=0 && col+1<colSize && !visited[row][col+1])
                       {
                           recurPos.push(row);recurPos.push(col+1);
                           visited[row][col+1]=true;
                       }
                       if(row+1<rowSize && col-1>=0 && !visited[row+1][col-1])
                       {
                           recurPos.push(row+1);recurPos.push(col-1);
                           visited[row+1][col-1]=true;
                       }
                       if(row+1<rowSize && col>=0 && !visited[row+1][col])
                       {
                           recurPos.push(row+1);recurPos.push(col);
                           visited[row+1][col]=true;
                       }
                       if(row+1<rowSize && col+1<colSize && !visited[row+1][col+1])
                       {
                           recurPos.push(row+1);recurPos.push(col+1);
                           visited[row+1][col+1]=true;
                       }
                    }
           
                }
                return board;
            }       
    };
}
#endif