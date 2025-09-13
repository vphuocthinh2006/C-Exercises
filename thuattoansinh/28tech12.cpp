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
int a[1001], n, r, ok;
void ktao(){
	for(int i = 1; i<=n; i++){
		a[i] = 0;
	}
}
void sinh(){
	int i = n;
	while(i>=0 && a[i] == 1){
		a[i] = 0;
		i--;
	}
	if(i==0){
		ok = 0;
	}else{
		a[i] = 1;
	}
}
bool check(){
	int cnt = 0, int res = 0;
	for(int i = 1; i<=n; i++){
		if(a[i] == 1){
			++cnt;
		}else cnt = 0;
		if(cnt > res) res = cnt;
		if(cnt == res && res == r) return false;
	}
	return res == r;
}
main(){
  file();
  cin >> n >> r;
  ok = 1;
  ktao();
  vector<string>v1, v2;
  while(ok){
  	string s = "", res = "";
  	int sum = 0;
  	for(int i = 1; i <= n; i++){
  		sum+=a[i];
  		s+=to_string(a[i]);
  		res+=to_string(a[i]);
  	}
  	if(sum==r) v1.push_back(s);
  	if(check()) v2.push_back(res);
  	sinh();
  }
  sort(all(v));
  for(auto x : v1){
  	cout << x << " ";
  }
  cout << endl;
  for(auto x : v2){
  	cout << x << " ";
  }
  return 0;
}