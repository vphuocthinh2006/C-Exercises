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
bool check(string s){
	stack<char> st;
	st.push(s[0]);
	for(int i = 1; i < s.length(); i++){
		if(!st.empty() && st.top==')'){
			return false;
		}else if(s[i] == '('){
			st.push(s[i]);
		}else if(!st.empty() && st.top() == '(' && s[i] == ')') st.pop();
		else if(st.empty() && s[i] == ')') return false;
	}
	if(st.size() == 0) return true;
	return false;
}
string res, int ok;
void sinh(){
	int i = res.size() - 1;
	while(i>=0 && res[i] == '1'){
		res[i] = '0';
		--i;
	}
	if(i==-1) ok = 0;
	else{
		res[i] = '1';
	}
}
main(){
  file();
  int n; cin >> n;
  res = string(n, '0');
  ok = 1, int  cnt = 0;
  while(ok){
  	string s = "";
  	for(int i = 0; i < s.length(); i++){
  		if(res[i] == '0'){
  			s+='('
  		}else s+=')';
  	}
  	if(check(s)){
  		cout << s << endl;
  		cnt = 1;
  	}
  	sinh();
  }
  if(!cnt) cout << "NOT FOUND";
  return 0;
}