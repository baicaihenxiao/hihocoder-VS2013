/*
2015��12��22��16:26:33

http://blog.csdn.net/labud/article/details/43448449

��λDP ǳ̸(hihocoder 1033:�����)
��ǩ�� �㷨 ��̬�滮 �������� ��λDP
2015-02-03 13:16 1277���Ķ� ����(5) �ղ� �ٱ�
���ࣺ ACM-��̬�滮
��Ȩ����������Ϊ����ԭ�����£�δ������������ת�ء�


��λDP��һ�ֱȽ������DP������֮�����˽⵽��Ϊ�˳��Խ��hihocoder��һ������͵���Ŀ������ϸ����Ϣ��ο�:���¡�ǳ̸��λ��ͳ�����⡷�ͽ��塶��̽��λDP��
��ʵ����ACM�У����Ǿ�����������������:

����������[L,R]����������Q�������ĸ���(�����ǵĺ͡�����)

�����������⣬էһ�����������⣬����ȴ��������Qһ�㲻����ô���ԣ��Ҳ����򵥵Ĺ��ɣ��������ö�٣���Ȼʱ�䳬����


��ϸ���ǣ���Ȼ[L,R]�����������ĸ���������[0,R]��ȥ[0,L-1]���������ĸ������������ǵ�һ��������������f(n)�����⣬����f(n)��ʾ����[0,n]����������Q�ĸ�����


����θ�Ч����f(n)�� ���ʱ������������Ҫ����λDP�����н������������˵��λDP��һ�ּ��仯�����ķ���(��ȻҲ�кܶ���Ŀ�Ƚϼ򵥣�����ֱ��DP)�� ��ʵ��������һ������Ȼ����ʵ��[0,n]�����������һ������Ӹ�λ����λ������Ȼ����ĳһλ�ϸ�С��n�Ķ�Ӧλ����֮ǰ����λȴһֱ��ȣ��������ֻ��Ҫö�����ֵ�λ�������λ���ּ��ɡ�


���������Ҫһ����ά����dp[len][digit] (��ƪ�����⡰����͡����漰������ͣ������Ǹ���ά���飬��ǰ��ά��Ȼ�ǳ��Ⱥ����λ���֣���˱�����ͬ)�� ��ʾ����Ϊlenλ(������ǰ��0)�������λΪdigit������������Q�����ֵĸ������������dp[i][j]? ע�⵽�����λ�̶�Ϊjʱ������ֻ��Ҫ������Ҫö����һλ������i-1λ����ʱֻ��Ҫ��0ö�ٵ�9(�������ⶼ��10����)���ɡ���������ٸ�����Щdp�Ľ�������n����(��ϸ�Ŀ��Բ�������Ľ��塶��̽��λDP��)��


��������ķ���������΢���ӣ���Ϊ��Ҫ�����dp���飬Ȼ��Ҫö��n�ĸ�λ�������������ͨ���Դ�����޸ģ����Խ���ϲ���һ����ʵ��������Ҫ����������

DP[len][digit]���飬������¼�м����ݣ�����Ϊ����Ķ���
solve(n) �������[0,n]����������Q�������ĸ���(���ߺ͵�)����Ҫ����������һ�����n�ĳ���l����n�ĸ�����λ����ȫ������bits�У��ڶ������������dfs(l+1, 0, true)����������
dfs(len, digit, end_flag)���bits��dp�������飬�����������п��ܽ���������Ӧdp�����������μ���ͬһ��������������ǰ����������������⣬�ؼ������һ��end_flag�� ��ʵ���������ǰ���dp�������[0,n]������Q�������������������������һ�����dfs������������������������ֵķ���������end_flag����ǣ�
���ñ��Ϊtrue��ʱ�򣬱�ʾǰ��ö�ٵĸ�λ��n�ĸ�λ��ȫ��ͬ�������һ��ö����һλʱ��Ϊ��ʹ���ִ�С������n������ֻ��ö�ٵ�bits[��λ]�����Ҽ���Ľ�����ܴ���dp����
��֮�����Ϊfalse,��ʾ֮ǰö�ٵĸ�λ�Ѿ�С��n��Ӧ��λ�ˣ���ô��һ����ö����һλʱ�����Դ�0ö�ٵ�9���Ҽ��������Դ���dp���顣
��������������ģ��(����ֻ�������������͵����Ҫ����һЩ��ο�����͵Ĵ���)��

[cpp] view plaincopy
int dp[len][digit]

int dfs(int len, int dig, bool end_flag){
int ILLEGAL, LEGAL;
//�����߽�ֵ
if(len <= 0)
return ILLEGAL;
//�������е�DP����������仯����
if(!end_flag && dp[len][dig] != -1)
return dp[len][dig];
//����ֻ��һλ���Ͳ���Ҫö����һλ�ˣ�ֱ�����۷��ؼ���
if(len == 1){
return (Q? LEGAL : ILLEGAL);
}
//��ʼö����һλ������
int end = end_flag? bits[len-2] : 9;
int ans = 0;
rep(j,0,end + 1){
ans += dfs(len-1, j,end_flag && j == end);
}
if(!end_flag) dp[len][dig] = ans;
return ans;
}

int solve(int n){
if(n <= 0)
return 0;
//���n��λ�������������λ��������bits��
int l = 0;
rep(i,0,21) bits[i] = 0;
while(n){
bits[l++]= n%10;
n /= 10;
}
//����dfs����������ע�⵽��һ������l +1��ָ���ǽ�nǰ��һ����λ0��Ȼ��ʼ���ң�����������ö��ԭ��n�����λ
return dfs(l+1,0,true);
}

ע�⵽����������漰��end_flag��״̬ת�������������λDP�Ļ���ģ�壬�󲿷���Ŀ������ֱ��������Ļ����޸ġ�

����ǽ���͵�����⣬ע�⵽���ڽ���ͺ�ǰ���λ���йأ����dfs������������begin_zero��sum��������ĺ�����ģ��û�б�������

[cpp] view plaincopy
#include<iostream>
#include<cstring>
using namespace std;

#define ll long long int
#define rep(a,b,c) for(int a = b ;  a < c; a++)

const int mod = 1000000007;

struct node{
ll s,n;
};

node dp[21][20][400];

int bits[21];
ll base[21];

//len��λ����, dig���׸�����, begin_zero��ʾ֮ǰ�Ƿ��Ѿ���ʼ��ţ� end_flag��ʾ��һλö��ʱ�Ƿ�ö�ٵ�bit[len-2]�������ö�ٵ�9�� sum��Ҫ������ֺ�
node dfs(int len, int dig, bool begin_zero, bool end_flag, int sum){
node t;
t.s = 0, t.n = 0;
//�����߽�ֵ
if(len <= 0 || len >= 20 || dig < 0 || dig > 9 || sum < -200 || sum >= 200)
return t;
//�������е�DP����������仯����
if(!end_flag && dp[len][dig + (begin_zero?0:10)][sum+200].n != -1)
return dp[len][dig + (begin_zero?0:10)][sum+200];
//����ֻ��һλ���Ͳ���Ҫö����һλ�ˣ�ֱ�����۷��ؼ���
if(len == 1){
if(dig != sum)
return t;
t.n = 1, t.s = sum;
return t;
}
//��ʼö����һλ������
int end = end_flag? bits[len-2] : 9;
int newsum = dig - sum;
node tmp;
rep(j,0,end + 1){
if(!begin_zero){
tmp = dfs(len-1, j, j!=0, end_flag&& (j == end), sum);
}
else{
tmp = dfs(len-1, j, true, end_flag&& (j == end), newsum);
}
//��tmp��ֵ�ۼӵ�t��
t.n += tmp.n;
t.s = ((t.s + tmp.s)%mod + ((tmp.n * dig )%mod * base[len-1])%mod)%mod;
}
if(!end_flag) dp[len][dig + (begin_zero?0:10)][sum+200] = t;
return t;
}

int solve(ll n, int s){
if(n <= 0)
return 0;
int l = 0;
rep(i,0,21) bits[i] = 0;
while(n){
bits[l++]= n%10;
n /= 10;
}
return dfs(l+1,0,false,true,s).s;
}

int main(){
ll l, r, s;
node t;
t.n = -1;
t.s = 0;
rep(i,0,21) rep(j,0,20) rep(k,0,400) dp[i][j][k] = t;
base[0] = 1;
rep(i,1,21) base[i] = (base[i-1]*10)%mod;
cin >> l >> r >> s;
cout <<(solve(r,s) - solve(l-1,s) + mod )%mod << endl;
return 0;
}


*/


#include<iostream>
#include<cstring>
using namespace std;

#define ll long long int
#define rep(a,b,c) for(int a = b ;  a < c; a++)

const int mod = 1000000007;

struct node{
	ll s, n;
};

node dp[21][20][400];

int bits[21];
ll base[21];

//len��λ����, dig���׸�����, begin_zero��ʾ֮ǰ�Ƿ��Ѿ���ʼ��ţ� end_flag��ʾ��һλö��ʱ�Ƿ�ö�ٵ�bit[len-2]�������ö�ٵ�9�� sum��Ҫ������ֺ� 
node dfs(int len, int dig, bool begin_zero, bool end_flag, int sum){
	node t;
	t.s = 0, t.n = 0;
	//�����߽�ֵ 
	if (len <= 0 || len >= 20 || dig < 0 || dig > 9 || sum < -200 || sum >= 200)
		return t;
	//�������е�DP����������仯���� 
	if (!end_flag && dp[len][dig + (begin_zero ? 0 : 10)][sum + 200].n != -1)
		return dp[len][dig + (begin_zero ? 0 : 10)][sum + 200];
	//����ֻ��һλ���Ͳ���Ҫö����һλ�ˣ�ֱ�����۷��ؼ��� 
	if (len == 1){
		if (dig != sum)
			return t;
		t.n = 1, t.s = sum;
		return t;
	}
	//��ʼö����һλ������ 
	int end = end_flag ? bits[len - 2] : 9;
	int newsum = dig - sum;
	node tmp;
	rep(j, 0, end + 1){
		if (!begin_zero){
			tmp = dfs(len - 1, j, j != 0, end_flag && (j == end), sum);
		}
		else{
			tmp = dfs(len - 1, j, true, end_flag && (j == end), newsum);
		}
		//��tmp��ֵ�ۼӵ�t��
		t.n += tmp.n;
		t.s = ((t.s + tmp.s) % mod + ((tmp.n * dig) % mod * base[len - 1]) % mod) % mod;
	}
	if (!end_flag) dp[len][dig + (begin_zero ? 0 : 10)][sum + 200] = t;
	return t;
}

int solve(ll n, int s){
	if (n <= 0)
		return 0;
	int l = 0;
	rep(i, 0, 21) bits[i] = 0;
	while (n){
		bits[l++] = n % 10;
		n /= 10;
	}
	return dfs(l + 1, 0, false, true, s).s;
}

int main(){
	freopen("F:\\test.txt", "r", stdin);

	ll l, r, s;
	node t;
	t.n = -1;
	t.s = 0;
	rep(i, 0, 21) rep(j, 0, 20) rep(k, 0, 400) dp[i][j][k] = t;
	base[0] = 1;
	rep(i, 1, 21) base[i] = (base[i - 1] * 10) % mod;
	cin >> l >> r >> s;
	//cout << (solve(r, s) - solve(l - 1, s) + mod) % mod << endl;
	printf("%lld\n", (solve(r, s) - solve(l - 1, s) + mod) % mod);
	return 0;
}

//
//cout << solve(r, s) << endl;
//cout << solve(l - 1, s) << endl;12123893812690944