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
const int maxn = 10001;
//vector<int> v[maxn];
//int check[maxn];
int a[maxn][maxn];
struct Basic{
	int x, y, cnt;
};
bool check(int x , int y , int n)
{
    if(x <= n && y <= n && x >= 1 && y >= 1) return true;
    return false;
} 
int dx[] = {1 , 1 , 1 , 0 , 0 , -1 , -1 , -1};
int dy[] = {0 , 1 , -1 , 1 , -1 , 1 , 0 , -1};
int BFS(int a, int b, int c, int d, int n){
	queue<Basic> q;
	q.push({a,b, 0});
	a[a][b] =0;
//	Basic t;
	while(!q.empty()){
		Basic t = q.front(); q.pop();
		if(t.x == c && t.y == d) return t.cnt;
		for(int k = 0; k < 8; k++){
			int i1 = t.x + dx[k];
			int j1 = t.y + dy[k];
			if(check(i1, j1, n) && a[i1][j1]){
				a[i1][j1] = 0;
				q.push({i1, j1, t.cnt+1});
			}
		}
	}
	return -1;
}    
main(){
  file();
  int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
  for(int i = 1; i<=n;i++){
  	for(int j = 1; j<=n;j++){
  		cin >> a[i][j];
	  }
  }
  cout << bfs(a, b, c, d, n);
}
