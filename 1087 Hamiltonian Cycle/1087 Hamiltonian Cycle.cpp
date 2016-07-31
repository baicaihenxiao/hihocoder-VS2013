/*
2016-7-31 02:41:02

http://hihocoder.com/problemset/problem/1087

#1087 : Hamiltonian Cycle
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
Given a directed graph containing n vertice (numbered from 1 to n) and m edges. Can you tell us how many different Hamiltonian Cycles are there in this graph?

A Hamiltonian Cycle is a cycle that starts from some vertex, visits each vertex (except for the start vertex) exactly once, and finally ends at the start vertex.

Two Hamiltonian Cycles C1, C2 are different if and only if there exists some vertex i that, the next vertex of vertex i in C1 is different from the next vertex of vertex i in C2.

输入
The first line contains two integers n and m. 2 <= n <= 12, 1 <= m <= 200.

Then follows m line. Each line contains two different integers a and b, indicating there is an directed edge from vertex a to vertex b.

输出
Output an integer in a single line -- the number of different Hamiltonian Cycles in this graph.

提示
额外的样例:

样例输入	样例输出
3 3
1 2
2 1
1 3	0





样例输入
4 7
1 2
2 3
3 4
4 1
1 3
4 2
2 1
样例输出
2



*/