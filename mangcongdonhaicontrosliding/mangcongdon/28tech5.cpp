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
//prefix prefix
//tao 2 mang luu mot cai luu mang hieu
//mot cai vector node de luu cac toa do
//sau do tao them 1 vector arr de tang x giam y xuong
//sau do arr[i] += arr[i-1]; de tao mot mang prefix sum
//b[v[i].x] o day la toa do += (arr[i] * v[i].z)
//b[v[i].y] o day la toa do -= (arr[i] * v[i].z)
struct node{
	int x, y, z;
};
main(){
	int n, m, k; cin >> n >> m >> k;
	vector<int>a; a.resize(n+2, 0);
	vector<int>b; b.resize(n+2,0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i] - a[i-1];
	}
	vector<node>v.resize(m+2);
	for(int i = 1; i <= m; i++){
		cin >> v[i].x >> v[i].y >> v[i].z;
	}
	vector<int> arr; arr.resize(m+2, 0);
	for(int i = 1; i <= k; i++){
		int x, y; cin >> x >> y;
		arr[x] +=1;
		arr[y+1]-=1;
	}
	for(int i = 1; i<=m; i++){
		arr[i] += arr[i-1];
	}
	for(int i = 1; i<=m;i++){
		b[v[i].x] += (arr[i] *v[i].z);
		b[v[i].y + 1] -= (arr[i] * v[i].z);
	}
	for(int i = 1; i<=n; i++){
		b[i]+=b[i-1];
		cout << b[i] << " ";
	}

  return 0;
}