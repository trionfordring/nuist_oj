#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
vector<vector<int>> sum(81, vector<int>(81)),a(81, vector<int>(81));
vector<int> getMaxMatrix(vector<vector<int>> &matrix){
    vector<int> ans(4);
    if (matrix.size() == 1 && matrix[0].size() == 1)
    {
        ans[0] = ans[1] = ans[2] = ans[3] = 0;
        return ans;
    }
    int ans_v = -2147483645;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (j > 0)
                sum[i][j] = sum[i][j - 1] + matrix[i][j];
            else
                sum[i][j] = matrix[i][j];
        }
    }
    vector<int> temp(matrix.size());
    vector<int> dp(matrix.size());
    vector<bool> mk(matrix.size());
    for (int i = 0; i < matrix[0].size(); i++)
    {
        for (int j = i; j < matrix[0].size(); j++)
        {
            for (int k = 0; k < temp.size(); k++)
            {
                if (i > 0)
                    temp[k] = sum[k][j] - sum[k][i - 1];
                else
                    temp[k] = sum[k][j];
            }
            dp[0] = temp[0];
            mk[0] = false;
            int temp_max_index = 0;
            for (int k = 1; k < temp.size(); k++)
            {
                dp[k] = max(temp[k], dp[k - 1] + temp[k]);
                if (dp[k] == temp[k])
                {
                    mk[k] = false;
                }
                else
                {
                    mk[k] = true;
                }
                if (dp[k] > dp[temp_max_index])
                    temp_max_index = k;
            }
            if (dp[temp_max_index] > ans_v)
            {
                ans_v = dp[temp_max_index];
                ans[1] = i, ans[3] = j, ans[2] = temp_max_index;
                while (mk[temp_max_index])
                    temp_max_index--;
                ans[0] = temp_max_index;
            }
        }
    }
    // delete &sum;
    return ans;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        vector<int> v=getMaxMatrix(a);
        int sum=0;
        for(int i=v[0];i<=v[2];i++){
            for(int j=v[1];j<=v[3];j++){
                sum+=a[i][j];
            }
        }
        printf("%d\n",sum);
    }
}