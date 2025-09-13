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
int bfs(int a, int b){
	set<int> se;
	queue<ii> q;
	q.push({a, 0});
	while(!q.empty()){
		int tmp = q.front().fi;
		int cnt = q.front().se; q.pop();
		if(tmp == b){
			return cnt;
		}
		if(top > 1 && !se.count(top-1)){
			q.push({top-1, cnt+1});
            se.insert(top-1);
		}else if(top < b && !se.count(top*2)){
			q.push({top * 2, cnt + 1});
            se.insert(top*2);
		}
	}
	return 0;
}
main(){
  file();
  int a, b; cin >> a >> b;
  cout << bfs(a, b);
  
  return 0;
}