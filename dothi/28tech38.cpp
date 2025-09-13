/** TO MY NOTION:

                                               ,----'   `-,

                     ___,-'~~~`---'~~~~`-----' ,-'        \,

             ___,---'          '        ,-~~~~~            :

        ,--'                 ,        ; ;       ) "   _   \,

   _,--'     ,                 ,'      :: "  ;  ` ,'  (\o\)  |

  / _,       `,                     ,  `; " ;    (     `~~ `'\

 ; /         ,`               ,     `    ~~~`. " ;   _     ,  `.

,'/          ` ,              `     ` ,  ,    \_/ ?   ;    )   `.

:;:            `                      `  ` ,     uu`--(___(    ~:

:::          , ,  ,            ,   ;     , `  ,-'      \~(  ~   :

||:          ` `  `         ,  ` ,'    ( ` ,-          \ \   ~:

:|`.        , ,  ,          `_   ;       ) );            \__>   :

|:  : ;     ` `  ` ;  __,--~~ `-(         ( |              `.  ~|

:|  :         ` __,--'           :  ()    : :               |~  ;

|;  |  `     ,-'    ;             :  )(   | `.         /(   `. ~|

::  :   ~  _/;     ;               |   )  :  :        ; /    ;~ ;

{}  ;     /  :   ~ :               :      ; ,;        : `._,-  ,

{} /~    /   ;    ;                 : ,  |  `;         `.___,-'

  ;~    ;    ;  ~ `.                | `  )   ;

  :`    \    `;~   \                ;~   `-, `-.     VOI24

  `.__OOO;    `;_OOO;               )_____OO;_(O)

   ~~~~~~       ~~~~                ~~~~~~~~ ~~~~

   */

#include<bits/stdc++.h>
////Ta thuat
//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,fma")
#define MOD 1000000007
#define fi first
#define se second
#define int long long
#define ii pair<int,int>
#define Dennis "Top1Server"
#define Jack1e "DB bainao"
#define heap_max(a) priority_queue<a>
#define heap_min(a) priority_queue<a, vector<a>, greater <a>>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define el cout << '\n'
#define rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, b) for(int i = (a); i <= (b); i++)
#define Fod(i, a, b) for(int i = (a); i >= (b); i--)
#define bit(x, i) ((x >> i) & 1)
using namespace std;
template <class X, class Y> bool minimize(X &a, Y b){
    if (a > b) return a = b, true;
    return false;
}

template <class X, class Y> bool maximize(X &a, Y b){
    if (a < b) return a = b, true;
    return false;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {return l + rng() % (r - l + 1);}
const int N = 1e6 + 5;
void file()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
}
int a[501][501];
void dijkstra(int n , int m)
{
    vector<vector<int>>d(n + 1, vector<int>(m + 1, 1e9 + 7));
    int dx[] = {1 , -1 , 0 , 0};
    int dy[] = {0 , 0 , -1 , 1};
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>Q;
    Q.push({a[1][1] , make_pair(1 , 1)});
    d[1][1] = a[1][1];
    while(!Q.empty())
    {
        pair<ll,pair<ll,ll>> top = Q.top(); Q.pop();
        if(d[top.second.first][top.second.second] < top.first) continue;
        for(int i = 0 ; i < 4 ; i++)
        {
            int i1 = dx[i] + top.second.first;
            int j1 = dy[i] + top.second.second;
            if(i1 < 1 || j1 < 1 || i1 > n || j1 > m) continue;
            if(d[i1][j1] > top.first + a[i1][j1])
            {
                d[i1][j1] = top.first + a[i1][j1];
                Q.push({d[i1][j1] ,make_pair(i1 , j1)});
            }
        }
    }
    cout << d[n][m];
}
int main()
{
    int n , m ; cin >> n >> m;
    for(int i = 1 ;i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> a[i][j];
        }
    }
    dijkstra(n ,m);
}
