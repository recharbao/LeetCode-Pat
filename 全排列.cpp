#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


vector<vector<int>> permuteUnique(vector<int>& nums);


/*
vector<vector<int>> permuteUnique(vector<int>& nums);
vector<vector<int>>dfs(int curent,int number,vector<vector<int>> &sign,vector<int> tmp);
*/
int main()
{
    vector<int> nums{1,2,1,1,2,5,8};
    vector<vector<int>> result;
    result=permuteUnique(nums);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j];
        }
        cout<<endl;
    }
    return 0;   
}
/*
vector<vector<int>> result;
 vector<vector<int>> permuteUnique(vector<int>& nums)
 {
    map<int,int> count;
    for(int i=0;i<nums.size();i++)
    {
        int k=nums[i];
        count[k]++;
    }

    vector<vector<int>> sign(count.size(),vector<int>(2,0));
    map<int,int> ::iterator iter;
    int i=0;
    for(i,iter=count.begin();iter!=count.end();i++,iter++)
    {
        sign[i][0]=(iter->first);//������ȡֵ����
        sign[i][1]=(iter->second);
    }
   vector<int> tmp;
    result=dfs(0,nums.size(),sign,tmp);
    return result;
 }

vector<vector<int>>dfs(int curent,int number,vector<vector<int>> &sign,vector<int> tmp)
{
    if((curent++)>=number)
    {
        result.push_back(tmp);
        return result;
    }
    else
    {
        for(int i=0;i<sign.size();i++)
        {
            //��������������
            if((sign[i][1])>0)//����������ǲ�ͬ�����鷵��ԭ����ֵ���䣬�����Ǹ��ݵ�ַ��¼ֵ�ģ�����������ԭ������ֵ��ص�ԭ�����趨��ֵ��
            {
                sign[i][1]--;
                tmp.push_back(sign[i][0]);
                dfs(curent,number,sign,tmp);
                tmp.pop_back();
                sign[i][1]++;
            }
        }
    }
        return result;
}
*/





    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); //ע������sort������
        
        do {
            result.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));//���ֺ���next_permutation()�ǰ����ֵ���������еģ������Ǵ������е�ǰ���ֵ���ʼ��������ֱ��������ֵ���
        return result;
    }




/*

class Solution {
public:
    void backtrace(map<int, int>& m, int k, int n,
                   vector<int>& v, vector<vector<int>>& res) {
        if (k == n) {
            res.push_back(v);
            return;
        }
        for (auto& p : m) {
            if (p.second == 0) continue;
            --p.second;
            v.push_back(p.first);
            backtrace(m, k + 1, n, v, res);
            ++p.second;
            v.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> m;
        for (auto x : nums) ++m[x];
        vector<vector<int>> res;
        vector<int> v;
        backtrace(m, 0, nums.size(), v, res);
        return res;
    }
};






class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        vector<bool> visit(nums.size(), false);
        recursive(nums, cur, visit);
        return ret;
    }
    
    void recursive(vector<int>& nums, vector<int> cur, vector<bool>& visit) {
        if(nums.size() == cur.size()) {
            ret.push_back(cur);
            return ;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i - 1] && !visit[i - 1])//ȥ��
                continue;
            if(!visit[i]) {
                visit[i] = true;
                cur.push_back(nums[i]);
                recursive(nums, cur, visit);
                cur.pop_back();
                visit[i] = false;
            }
        }
        
    }
};

*/