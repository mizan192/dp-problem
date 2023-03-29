class Solution {
public:
    static const int lmt=400;
    int mincostTickets(vector<int>& days, vector<int>& c) {
        int n=days.size();
        vector<int>dp,vis;
        dp.resize(lmt,INT_MAX);
        vis.resize(lmt,0);
        
        int first_day=days[0];
        dp[0]=c[0];
        first_day+=6;
        int l=lower_bound(days.begin(),days.end(),first_day)-days.begin();
        l=min(l,n-1);
        if(days[l]>first_day) l--;
        l=max(l,1);
        dp[l]=min(dp[l],c[1]);
        first_day=days[0]+29;
        l=lower_bound(days.begin(),days.end(),first_day)-days.begin();
        l=min(l,n-1);
        if(days[l]>first_day) l--;
        l=max(l,1);
        dp[l]=min(dp[l],c[2]);

//         for(int i=0;i<n;i++){
//             int pre = dp[i];
//            if(dp[i]==INT_MAX)  pre=dp[i-1];    //not travel yet

//         cout<<i<<" "<<pre<<" ";

//                 dp[i]=min(dp[i],pre+c[0]);
                
//                 cout<<dp[i]<<" ind->";

//                 int day = days[i]+6;
//                 int l=lower_bound(days.begin(),days.end(),day)-days.begin();
//                 l=min(l,n-1);
//                 if(days[l]>day) l--;
//                 l=max(l+1,l);
//                 dp[l]=min(dp[l],pre+c[1]);
               
//                 cout<<l<<" "<<dp[l]<<" ind->";
                
//                 day = days[i]+29;
//                 l=lower_bound(days.begin(),days.end(),day)-days.begin();
//                 l=min(l,n-1);
//                 if(days[l]>day) l--;
//                 l=max(l+1,l);
//                 dp[l]=min(dp[l],pre+c[2]);

//                 cout<<l<<" "<<dp[l]<<endl;


//         }

// for(int i=0;i<n;i++) cout<<dp[i]<<" ";
dp[0] = 0;
        int j = 0;
        for (int i = 1; i <= 365; i++) {
            if (j < n && i == days[j]) {
                dp[i] = min(dp[i], dp[i-1] + c[0]);
                if (i >= 7) 
                    dp[i] = min(dp[i], dp[i-7] + c[1]);
                else 
                    dp[i] = min(dp[i], c[1]);
                if (i >= 30) 
                    dp[i] = min(dp[i], dp[i-30] + c[2]);
                else 
                    dp[i] = min(dp[i], c[2]);
                j++;
            } 
            else {
                dp[i] = dp[i-1];
            }
        }
        
    return dp[365];


        // for(auto x : days) vis[x]=1;
        // int last_day = days[n-1];
        // int first_day=days[0];
        // dp[first]=c[0];
        // dp[first+6]=c[1];
        // dp[first+29]=c[2];

        // for(int x=1;x<=365;x++){
        //     if(vis[x]==1){
        //         int nextTwo = x+1;
        //         int nextSev = x+6;
        //         int nextThrt = x+29;
        //         dp[nextTwo]=min(dp[nextTwo],dp[x]+c[0]);
        //     }
        // }



    }
};