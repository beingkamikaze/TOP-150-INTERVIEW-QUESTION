LINK : https://leetcode.com/problems/evaluate-division/submissions/?envType=study-plan-v2&envId=top-interview-150

lass Solution {
    private:
    void dfs(string s,string d,map<string,vector<pair<string,double>>> &mp,set<string>vis,double &ans,double temp)
    {
        if(vis.find(s)!=vis.end())
        return;
        else
        {
            vis.insert(s);
            if(s==d)
            {
                ans=temp;
                return;
            }
            else
            {
                for(auto it : mp[s])
                {
                    dfs(it.first,d,mp,vis,ans,temp*it.second);
                }
            }
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>> mp;
        for(int i=0;i<equations.size();i++)
        {
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            mp[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        vector<double> res;
        for(int i=0;i<queries.size();i++)
        {
            string source=queries[i][0];
            string dessti=queries[i][1];
            set<string> vis;
            double ans=-1.0;
            if(mp.find(source)!=mp.end())
            dfs(source,dessti,mp,vis,ans,1.0);
            res.push_back(ans);

        }
        return res;
    }
};
