#include<bits/stdc++.h>
#define fastread()      (ios::sync_with_stdio(false), cin.tie(NULL));
#define  __init__(t) int t; cin >> t; while(t--)
#define int long long
#define endl "\n"
#define mod ((int)1e9 + 7)
using namespace std;

class TC {
    public:
        void solve() {  
            // These are the lamda functions is c++..           
            auto compare = [](pair<int,int> a, pair<int, int> b) {    
                                    int diff1 = a.second - a.first;
                                    int diff2 = b.second - b.first;
                                    if(diff1 > diff2) return false;
                                    else if(diff1 == diff2) return a.first  > b.first;
                                    else return true;
                            };
            int n; 
            cin >> n;
            priority_queue<pair<int, int>, vector<pair<int,int>>,decltype(compare)> q(compare); 
            vector<int>arr(n + 1);
            int span, index;
            q.push(std::make_pair(1, n));
            for(int i = 1; i <= n; i++) {
                pair<int, int> p = q.top();
                q.pop();
                int l = p.first;
                int r = p.second;
                int span = r - l + 1;
                if(span % 2 == 1) {
                    index = (l + r)  / 2;
                    arr[index] = i;
                }else { 
                    index = (l + r - 1)/ 2;
                    arr[index] = i;                    
                }
                if(index - 1 >= l) {
                   q.push(std::make_pair(l, index - 1));
                }
                if(index + 1 <= r) {
                    q.push(std::make_pair(index + 1, r));
                }               
            } 
            for(int i = 1; i <= n; i++){ 
                cout << arr[i] << " ";
            }
            cout << endl;    
        }                 
};  

int32_t main() { 
    fastread()    
    double start = clock();
    __init__(t) {
        TC tc;
        tc.solve();       
    }
    cerr << "[*] Time: " << (clock() - start) * 1.0 / CLOCKS_PER_SEC << std::setprecision(3) << " s" << endl;
    return 0;
}

