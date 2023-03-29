class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        vector<int>p,n;
        for(auto x : s){
            if(x>=0) p.push_back(x);
            else n.push_back(x);
        }
        sort(p.begin(),p.end());
        sort(n.rbegin(),n.rend());

        if(p.size()==0) return 0;     //all are neg
        int max_value=0,sum=0;
        for(int i=0;i<p.size();i++) {
            max_value+=(p[i]*(i+1));
            sum+=p[i];
        }
        if(n.size()==0) return max_value;
        
    //for every neg value our max_value will increase with sum
    //we have to check if negative value is less than sum or not
    
    //cout<<max_value<<" "<<sum<<"\n";

    for(int i=0;i<n.size();i++){
        int x=abs(n[i]);
        if(x>=sum) break;
        max_value+=(sum-x);
        sum-=x;
    }

    return max_value;

    }
};






