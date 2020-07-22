#include<iostream>
using namespace std;

bool solveSudoku(char S[][9],int x,int y);
            
int main()
{                
    char S[][9]=    {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(S,0,0);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<S[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
/* 
//���㷨ȱ�������û�а취�ж��Ƿ��Ѿ�ʵ�֣��������������һ��Ҫ���жϱ�־��
void solveSudoku(char S[][9],int cur)
{
    if(cur<9)
    {
        for(int j=0;j<9;j++)
        {
            if(S[cur][j]=='.')
            {
                for(char nums='1';nums<='1'+8;nums++)
                {
                    int ok=1;
                    //�����ж�����
                    //same��k
                    for(int k=0;k<9;k++)
                    {
                        if(k!=cur&&S[k][j]==nums)
                        {
                            ok=0;
                        }
                    }
                    //same���ж�
                    //i
                    for(int i=0;i<9;i++)
                    {
                        if(i!=j&&S[cur][i]==nums)
                        {
                            ok=0;
                        }
                    }
                    //ͬһ3*3�����ж�
                    //�ж�������һ���ո���
                    int hjudge=(cur/3)*3;
                    int ljudge=(j/3)*3;
                    //i hang,k lie
                    for(int i=hjudge;j<=hjudge+2;j++)
                    {
                        for(int k=ljudge;k<=ljudge+2;k++)
                        {
                            if(i!=cur&&k!=j&&S[i][k]==nums)
                            {
                                ok=0;
                            }
                        }
                    }
        //������һ���׶�
                if(ok)
                {
                    S[cur][j]=nums;
                    solveSudoku(S,cur+1);
                }
                }
            }
        }
    }
}

*/



bool solveSudoku(char S[][9],int x,int y)
{
    if(y==9)
    {
        x++;
        y=0;
    }

    if(x==9)
    {
        return true;
    }

    for(char nums='1';nums<='1'+8;nums++)
    {
        int ok=1;
        if(S[x][y]!='.')
            ok=0;
        //�����ж�����
        //same��k
        for(int k=0;k<9;k++)
        {
            if(k!=x&&S[k][y]==nums)
            {
                ok=0;
            }
        }
        //same���ж�
        //i
        for(int i=0;i<9;i++)
        {
            if(i!=y&&S[x][i]==nums)
            {
                ok=0;
            }
        }
        //cout<<"ok="<<ok<<endl;
        //ͬһ3*3�����ж�
        //�ж�������һ���ո���
        int hjudge=(x/3)*3;
        int ljudge=(y/3)*3;
        //i hang,k lie
       /*  for(int i=hjudge;i<=hjudge+2;i++)
        {
            for(int k=ljudge;k<=ljudge+2;k++)
            {
                if(i!=x&&k!=y&&S[i][k]==nums)
                {
                    ok=0;
                }
            }
        }
//������һ���׶�
    






















