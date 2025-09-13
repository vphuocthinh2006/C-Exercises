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
string cong(string a, string b){
	if(a.length() < b.length()) swap(a, b);
	int n = a.length(), m = b.length();
	reverse(all(a));
	reverse(all(b));
	b+=string(n-m, '0');
	string res = "";
	int nho = 0;
	for(int i = 0; i < n; i++){
		int tmp = (a[i] - '0') + (b[i] - '0') + nho;
		res += (char)(tmp%10 + '0');
        nho = tmp/10;
	}  
    if(nho) res+=(char)(nho + '0');
    reverse(all(res));
    // cout << res;
    return res;
}
bool check(string s, int beg, int len1, int len2){
    string s1 = s.substr(beg, len1);
    string s2 = s.substr(beg + len1, len2);
    string s3 = cong(s1, s2);
    if(s3.size() > s.size() - len1 - len2) return false;
    if(s3 == s.substr(beg+len1+len2, s3.size())){
        if(beg+len1+len2+s3.size() == s.size()) return true;
        return check(s, beg+len1, len2, s3.size());
    }
    return false;
}
bool issumstr(string s){
    int n = s.size();
    for(int i=1; i<n; i++){
        for(int j =1; j<n-i;j++){
            if(check(s, 0, i, j)){
                return true;
            }
        }
    }
    return false;
}
main(){
  file();
  string s; cin >> s;
  if(issumstr(s)){
    cout << "YES";
  }else cout << "NO";
  return 0;
}