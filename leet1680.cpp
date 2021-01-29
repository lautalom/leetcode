#define rep(i,a,b) for(int i=(a),_5=(b);i<_5;++i)
const int MOD = 1e9+7;//10^9+7
int dp[100001];
struct Solution {
    void f(){
        ios::sync_with_stdio(false); cin.tie(NULL);
        int l=1;
        size_t r=0;
        rep(i,1,100001){
            int cl = l;
            while(cl){
                //i&cl sums 1 at every 1 position in i, and 0 otherwise
                r=((r<<1)+((i&cl)!=0))%MOD;
                cl>>=1;
            }
            //this means i+1 is a power of 2
            if(!(i&(i+1))){
                l<<=1;
            }
            dp[i]=r;
        }
    }
    int concatenatedBinary(int n) {
        if(dp[n]==0) f();
        return dp[n];
    }
};

using ll = long long;
vector<ll> dp;
const ll MOD=1'000'000'007;
const int N = 1'00'010;
//best runtime
class Solution {
public:
    
    void fill() {
        dp.resize(N);
        dp[1] = 1;
        for(int i = 2; i < N; ++i) {
            //length of current int in binary repr
            ll len = log2(i) + 1;
            // 1 of type long long (no need given constraints but still)
            len = (1LL<<len);
            dp[i] = ((dp[i - 1] * len) % MOD + i) % MOD;
        }
    }
    
    int concatenatedBinary(int n) {
        if (dp.empty()) {
            fill();
        }
        return dp[n];
    }
};