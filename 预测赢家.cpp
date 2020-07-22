#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Ҫ�ؿ�


bool PredictTheWinner(vector<int>& nums);

int winner(vector<int> &nums, int s, int e, int turn);

int main()
{
    vector<int> nums{1,5,2};
    bool result;
    result=PredictTheWinner(nums);
    cout<<result;
    return 0;
}
/*
bool PredictTheWinner(vector<int>& nums)
{
    vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
    //vector<vector<int>> dp;/��������������Ϊû�и������ʼ��С�޷�ʹ�������±���з��ʣ�
     //dp[i][j]��ָʣ��[i.....j]ʱ  ����ǰ����ѡ������һλѡ�ֵ�������֮�
     //dp[i][j]=max(dp[i+1][j],dp[i][j-1]),����dp[i][j]ʱ���һ���֣����һ����Ҷ���ķ��������һ-��Ҷ�����
     //dp[i+1][j],����dp[i][j-1],ʱ��Ҷ����֣���Ҷ������һ��ķ�������Ҷ�-���һ��
     //dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);

    for(int i = 0;i < nums.size();i++)
    {
        dp[i][i] = nums[i];
    }

    for(int length = 1;length < nums.size();length++)//���ֲ��ҵ���ʽ
    {
        for(int i = 0,j = length;j < nums.size();i++,j++)
        {
            dp[i][j] = max(nums[i] - dp[i + 1][j],nums[j] - dp[i][j - 1]);
            cout<<dp[i][j]<<endl;
        }
    }
    return dp[0][nums.size()-1]>=0;
}
*/
/*
    bool PredictTheWinner(vector<int>& nums) {
       int len=nums.size();
       vector<int>ans(len);
       for(int i=0;i<len;i++)ans[i]=nums[i];
       for(int i=len-1;i>=0;i--){
           for(int j=i+1;j<len;j++){
           ans[j]=max(nums[i]-ans[j],nums[j]-ans[j-1]);
           }
       }
       return ans[len-1]>=0;
    }



 class Solution {
    public: bool PredictTheWinner(vector<int> &nums) {
        return winner(nums, 0, nums.size() - 1, 1) >= 0;
    }
    public: int winner(vector<int> &nums, int s, int e, int turn) {
        if (s == e)
            return turn * nums[s];
        int a = turn * nums[s] + winner(nums, s + 1, e, -turn);
        int b = turn * nums[e] + winner(nums, s, e - 1, -turn);
        return turn * max(turn * a, turn * b);
    }
};
*/

//�ݹ�ʹ��

bool PredictTheWinner(vector<int> &nums) 
{
    return winner(nums,0,nums.size()-1,1)>=0;
}

int winner(vector<int> &nums, int s, int e, int turn)
{
    if(s==e)
        return turn*nums[s];
    int a=turn*nums[s]+winner(nums,s+1,e,-turn);
    int b=turn*nums[e]+winner(nums,s,e-1,-turn);
    return turn * max(turn * a, turn * b);//�ؼ���ֵ�ĵ�����
}



