/*
2016å¹?æ?æ?9:54:45

#1105 : é¢å¤è¯Â·å 
æ¶é´éå¶:10000ms
åç¹æ¶é:1000ms
åå­éå¶:256MB
æè¿°

å°Hoæä¸ä¸ªç³æçå­ï¼æ¯è¿ä¸æ®µæ¶é´å°Hoé½ä¼å°æ°ä¹°æ¥çç³ææ¾è¿å»ï¼åæ¶ä»ä¹ä¼ä¸æ­çä»å¶ä¸­æéåºæå¤§çç³æåºæ¥åæï¼ä½æ¯å¯»æ¾æå¤§çç³æä¸æ¯ä¸ä»¶éå¸¸ç®åçäºæï¼æä»¥å°Hoå¸æè½å¤ç¨è®¡ç®æºæ¥ä»å¸®å¿è®¡ç®è¿ä¸ªé®é¢ï¼?
æç¤ºï¼åç³æåå¤äºä¼åèçï¼

è¾å¥

æ¯ä¸ªæµè¯ç¹ï¼è¾å¥æä»¶ï¼æä¸ä»æä¸ç»æµè¯æ°æ®ã?
å¨ä¸ç»æµè¯æ°æ®ä¸­ï¼?
ç¬?è¡ä¸º1ä¸ªæ´æ°Nï¼è¡¨ç¤ºéè¦å¤ççäºä»¶æ°ç®ã?
æ¥ä¸æ¥çMè¡ï¼æ¯è¡æè¿°ä¸ä¸ªäºä»¶ï¼ä¸äºä»¶ç±»åç±è¯¥è¡çç¬¬ä¸ä¸ªå­ç¬¦è¡¨ç¤ºï¼å¦æä¸?A'ï¼è¡¨ç¤ºå°Hoå°ä¸ç²ç³ææ¾è¿äºçå­ï¼ä¸æ¥ä¸æ¥ä¸ºä¸ä¸ªæ´æ°Wï¼è¡¨ç¤ºè¿é¢ç³æçééï¼å¦æä¸º'T'ï¼è¡¨ç¤ºå°Hoéè¦ç¥éå½åçå­ä¸­æéçç³æçééæ¯å¤å°ï¼å¨ç¥éè¿ä¸ªå¼ä¹åï¼å°Hoä¼å°è¿é¢ç³æä»çå­ä¸­ååºå¹¶åæã?
å¯¹äº100%çæ°æ®ï¼æ»¡è¶³1<=N<=10^5, 1<=w<=10^5ã?>

å¯¹äº100%çæ°æ®ï¼æ»¡è¶³æ²¡æ2é¢ç³æçééæ¯ç¸åçï¼æå¼å§çæ¶åå°Hoçç³æçå­æ¯ç©ºçï¼ä¸æ¯æ¬¡å°Hoæ³è¦ååºä¸é¢ç³æçæ¶åçå­éä¸å®è³å°æä¸é¢ç³æã?
è¾åº

å¨ä¸ç»æµè¯æ°æ®ä¸­ï¼?
å¯¹äºæ¯ä¸ªç±»åä¸?T'çæ¶é´ï¼è¾åº1ä¸ªæ´æ°W_MAXï¼è¡¨ç¤ºå¨è¿ä¸æ¶å»ï¼çå­ä¸­æéçç³æçééã?


æ ·ä¾è¾å¥
5
A 77751
A 1329
A 26239
A 80317
T
æ ·ä¾è¾åº
80317

*/
//change


#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;


int heap[100010] = { 0 };

int heapSize = 0;


int parent(int son)
{

	return son / 2;

}

int left(int parent)
{
	return 2 * parent;
}


int right(int parent)
{
	return 2 * parent + 1;
}

void insertCandy(int weight)
{
	//throw std::logic_error("The method or operation is not implemented.");

	++heapSize;//å ä»ä¸æ ä¸ºä¸å¼å§å­å¨ï¼

	heap[heapSize] = weight;

	int tmp = heapSize;
	int inTmp = 0;

	while (tmp > 1 && heap[parent(tmp)] < heap[tmp])
	{
		inTmp = heap[parent(tmp)];
		heap[parent(tmp)] = heap[tmp];
		heap[tmp] = inTmp;

		tmp = parent(tmp);
	}

}

int eatCandy()
{
	//throw std::logic_error("The method or operation is not implemented.");

	if (heapSize == 0)
	{
		return -1;
	}

	int result = heap[1];

	heap[1] = heap[heapSize];

	--heapSize;

	//start compare with children
	int tmp = 1;
	int larger;

	while (true)
	{
		larger = tmp;

		if (left(tmp) <= heapSize && heap[left(tmp)] > heap[tmp])
		{
			larger = left(tmp);
		}

		if (right(tmp) <= heapSize && heap[right(tmp)] > heap[larger])//notice:heap[right(tmp)] > heap[larger] ; not  heap[right(tmp)] > heap[tmp];
		{
			larger = right(tmp);
		}

		if (larger == tmp)
		{
			break;
		}
		else
		{
			heap[tmp] ^= heap[larger];
			heap[larger] ^= heap[tmp];
			heap[tmp] ^= heap[larger];

			tmp = larger;
		}

	}


	return result;

}

int main()
{

	freopen("../test.txt", "r", stdin);

	int N;

	scanf("%d\n", &N);
	
	char type;
	int weight;

	while ((N --) != 0)
	{
		scanf("%c", &type);

		if (type == 'A')
		{
			scanf("%d\n", &weight);

			insertCandy(weight);
		}
		else if (type == 'T')
		{
			scanf("\n");

			int tmpCandy = eatCandy();

			printf("%d\n", tmpCandy);
		}


	}



}
