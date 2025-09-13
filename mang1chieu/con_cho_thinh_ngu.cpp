#include <bits/stdc++.h>

#define MOD 1000000007
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
#define Dennis ""
#define heap_max(a) priority_queue<a>
#define heap_min(a) priority_queue<a, vector<a>, greater <a>>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define el cout << '\n'
#define rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, b) for(int i = (a); i <= (b); i++)
#define Fod(i, a, b) for(int i = (a); i >= (b); i--)
#define inf 9223372036854775807
#define nl endl
#define prDouble(x,y) cout << fixed << setprecision(y) << x
#define pll pair<ll, ll>
#define spi set<pii>
#define si set<int>
#define mpci map<char, ll>
#define mpii map<ll, ll>
#define M 1000000007
#define ci cin
#define co cout
#define maxn 1000005
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

/*------------------------------------SOME BASIC FUNCTION--------------------------------------------------*/

ll sumofdigit(ll n){ll s = 0;while (n > 0){ll r = n % 10;s += r;n = n / 10;}return s;}
ll gcd(ll a, ll b){if (b % a == 0){return a;}else{return gcd(b % a, a);}}
ll POW(ll x, ll y){ll ans=1;for(ll i=0;i<y;i++){ans=ans*x;}return ans;}
ll ndigit(ll n){ll s=0;while(n>0){s++;n=n/10;}return s;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;}//O(sqrt(N))
bool isPrime(int n){if (n <= 1) return false; for (int i = 2; i < n; i++)if (n % i == 0) return false; return true;}
int binExpo(int a, int b){ if(b==0) return 1;if(b==1) return a; int r = binExpo(a, b/2); if(b%2==0) return (r%M * r%M)%M; else return (r%M*r%M*a%M)%M;}
int fast_mul(int x, int y){if (x == 0) return 0; else if (x % 2 == 1) return (fast_mul(x >> 1, y << 1) + y); else return fast_mul(x >> 1, y << 1);}


/*---------------------------------------------------------------------------------------------------------------*/

#define ii pair<int,int>
#define int long long
const int N = 1005;
const int mod = 1e9 + 7;

int n, m;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int isin(int a, int b){
	return (a >= 1 && a <= n && b >= 1 && b <= m);
}

int dem = 0;
char a[N][N];
ii head[N];

int vis[N][N];
int used[N][N];
void dfs(int i, int j, char x){
	used[i][j] = 1;
	cout << i << " " << j << " , ";
	For(k,0,3){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(!isin(i1, j1) || used[i1][j1]) continue;
		if(a[i1][j1] == x){
			dfs(i1, j1, x);
		}
	}	
}

void up1(){
	memset(used, 0, sizeof(used));
	queue<ii> q;
	if(a[1][1] != '*'){
		used[1][1] = 1;
		q.push(ii(1, 1));
	}
	while(q.size()){
		auto [i, j] = q.front(); q.pop();
		For(k,0,3){
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if(a[i1][j1] == '*') continue;
			if(!isin(i1, j1)) continue;
			if(used[i1][j1]) continue;
			q.push(ii(i1, j1));
			used[i1][j1] = 1;
		}
	}
}

void up2(){
	memset(vis, 0, sizeof(vis));
	queue<ii> q;
	if(a[n][m] != '*'){
		vis[n][m] = 1;
		q.push(ii(n, m));
	}
	while(q.size()){
		auto [i, j] = q.front(); q.pop();
		For(k,0,3){
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if(a[i1][j1] == '*') continue;
			if(!isin(i1, j1)) continue;
			if(vis[i1][j1]) continue;
			q.push(ii(i1, j1));
			vis[i1][j1] = 1;
		}
	}
}

void solve(){
	cin >> n >> m;
	For(i,1,n)	For(j,1,m) cin >> a[i][j];
	
	For(i,1,n)	For(j,1,m){
		if(!used[i][j] && a[i][j] != '*'){
			cout << "$: ";
			dfs(i, j, a[i][j]);
			head[++dem] = ii(i, j);
			cout << "\n";
		}
	}
	
	up1();	up2();
	
	int ans = 0;
	For(i,1,dem){
		auto [x, y] = head[i];
		if(used[x][y] && vis[x][y])++ans;
	}
	cout << ans;
}

/*-----------------------------------ACTUAL CODE STARTS HERE-----------------------------------------------------*/

void file()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
}

main(){
 	file();
 	solve();
}
