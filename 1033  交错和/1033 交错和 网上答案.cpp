/*
2015年12月22日16:26:33

http://blog.csdn.net/labud/article/details/43448449

数位DP 浅谈(hihocoder 1033:交错和)
标签： 算法 动态规划 区间问题 数位DP
2015-02-03 13:16 1277人阅读 评论(5) 收藏 举报
分类： ACM-动态规划
版权声明：本文为博主原创文章，未经博主允许不得转载。


数位DP是一种比较特殊的DP方法，之所以了解到是为了尝试解决hihocoder上一道交错和的题目，更详细的信息请参考:文章《浅谈数位类统计问题》和讲义《初探数位DP》
事实上在ACM中，我们经常遇到如下类问题:

求整数区间[L,R]中满足条件Q的整数的个数(或它们的和、积等)

对于这类问题，乍一看是数论问题，但是却发现条件Q一般不是那么明显，找不到简单的规律；尝试逐个枚举，显然时间超出。


仔细考虑，显然[L,R]中满足条件的个数，等于[0,R]减去[0,L-1]满足条件的个数，这样我们第一步把问题变成了求f(n)的问题，其中f(n)表示区间[0,n]内满足条件Q的个数。


而如何高效率求f(n)， 这个时候我们往往需要用数位DP来进行解决，本质上来说数位DP是一种记忆化搜索的方法(当然也有很多题目比较简单，可以直接DP)。 事实上它基于一个很显然的事实：[0,n]中任意的数，一定满足从高位往地位看，必然出现某一位严格小于n的对应位，而之前的数位却一直相等，因此我们只需要枚举数字的位数和最高位数字即可。


因此我们需要一个二维数组dp[len][digit] (开篇的问题“交错和”中涉及到计算和，所以是个三维数组，但前两维仍然是长度和最高位数字，因此本质相同)， 表示长度为len位(可以有前导0)，且最高位为digit的且满足条件Q的数字的个数。而如何求dp[i][j]? 注意到当最高位固定为j时，我们只需要根据需要枚举下一位，即第i-1位，此时只需要从0枚举到9(假设问题都是10进制)即可。最后我们再根据这些dp的结果，求出n即可(详细的可以参照上面的讲义《初探数位DP》)。


但是上面的方法还是稍微复杂，因为需要先求出dp数组，然后还要枚举n的各位情况。但是我们通过对代码的修改，可以将其合并在一起。事实上我们需要三个东西：

DP[len][digit]数组，用来记录中间数据，定义为上面的定义
solve(n) 用来求出[0,n]中满足条件Q的整数的个数(或者和等)，主要分两步：第一步求出n的长度l并将n的各个数位存在全局数组bits中，第二步调用下面的dfs(l+1, 0, true)用来求结果。
dfs(len, digit, end_flag)结合bits和dp两个数组，求出结果，并有可能将结果存入对应dp数组中以免多次计算同一种情况。这个函数前两个参数很容易理解，关键是最后一个end_flag， 事实上由于我们把求dp数组和求[0,n]中满足Q的整数个数这两个步骤合在了一起，因此dfs必须区分这两种情况，而区分的方法就是用end_flag做标记：
当该标记为true的时候，表示前面枚举的高位和n的高位完全相同，因此这一步枚举下一位时，为了使数字大小不超过n，必须只能枚举到bits[低位]，并且计算的结果不能存入dp数组
反之，如果为false,表示之前枚举的高位已经小于n对应高位了，那么这一步在枚举下一位时，可以从0枚举到9，且计算结果可以存入dp数组。
因此我们有下面的模板(这里只考虑求个数，求和的情况要复杂一些请参看交错和的代码)：

[cpp] view plaincopy
int dp[len][digit]

int dfs(int len, int dig, bool end_flag){
int ILLEGAL, LEGAL;
//超过边界值
if(len <= 0)
return ILLEGAL;
//返回已有的DP结果，即记忆化搜索
if(!end_flag && dp[len][dig] != -1)
return dp[len][dig];
//长度只有一位，就不需要枚举下一位了，直接讨论返回即可
if(len == 1){
return (Q? LEGAL : ILLEGAL);
}
//开始枚举下一位的数字
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
//求出n的位数，并将其各个位存入数组bits中
int l = 0;
rep(i,0,21) bits[i] = 0;
while(n){
bits[l++]= n%10;
n /= 10;
}
//调用dfs求出最后结果，注意到第一个参数l +1是指我们将n前补一个高位0，然后开始查找，这样避免了枚举原来n的最高位
return dfs(l+1,0,true);
}

注意到上面代码中涉及到end_flag的状态转换。上面就是数位DP的基本模板，大部分题目都可以直接在上面的基础修改。

最后是交错和的问题解，注意到由于交错和和前面的位数有关，因此dfs多了两个参数begin_zero和sum，但其余的和上面模板没有本质区别。

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

//len数位长度, dig是首个数字, begin_zero表示之前是否已经开始变号， end_flag表示下一位枚举时是否枚举到bit[len-2]，否则就枚举到9， sum是要求的数字和
node dfs(int len, int dig, bool begin_zero, bool end_flag, int sum){
node t;
t.s = 0, t.n = 0;
//超过边界值
if(len <= 0 || len >= 20 || dig < 0 || dig > 9 || sum < -200 || sum >= 200)
return t;
//返回已有的DP结果，即记忆化搜索
if(!end_flag && dp[len][dig + (begin_zero?0:10)][sum+200].n != -1)
return dp[len][dig + (begin_zero?0:10)][sum+200];
//长度只有一位，就不需要枚举下一位了，直接讨论返回即可
if(len == 1){
if(dig != sum)
return t;
t.n = 1, t.s = sum;
return t;
}
//开始枚举下一位的数字
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
//将tmp的值累加到t上
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

//len数位长度, dig是首个数字, begin_zero表示之前是否已经开始变号， end_flag表示下一位枚举时是否枚举到bit[len-2]，否则就枚举到9， sum是要求的数字和 
node dfs(int len, int dig, bool begin_zero, bool end_flag, int sum){
	node t;
	t.s = 0, t.n = 0;
	//超过边界值 
	if (len <= 0 || len >= 20 || dig < 0 || dig > 9 || sum < -200 || sum >= 200)
		return t;
	//返回已有的DP结果，即记忆化搜索 
	if (!end_flag && dp[len][dig + (begin_zero ? 0 : 10)][sum + 200].n != -1)
		return dp[len][dig + (begin_zero ? 0 : 10)][sum + 200];
	//长度只有一位，就不需要枚举下一位了，直接讨论返回即可 
	if (len == 1){
		if (dig != sum)
			return t;
		t.n = 1, t.s = sum;
		return t;
	}
	//开始枚举下一位的数字 
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
		//将tmp的值累加到t上
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