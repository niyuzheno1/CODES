#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7fffffff
#define mm 100010
using namespace std;

struct Node
{
	char val;
	Node* next;
	Node* fail;
}node[mm], *next = node + 1, *tail = node;

char buffer[mm];

void ins(char ch)
{
	tail -> val = ch;
	if (ch == '*')
	{
		tail -> fail = tail;
	} else {
		tail -> next = next;
		Node* fail = tail;
		while (fail -> val != ch && fail -> val != '?' && fail -> fail != fail && fail)
			fail = fail -> fail;
		next -> fail = fail;
		tail = next;
		++next;
	}
}

Node* match(Node* now, char ch)
{
	if (now -> val == '?' || now -> val == ch)
		return now -> next;
	Node* ret = now -> fail;
	for (;;)
	{
		if (!ret)
			return ret;
		if (ret -> val == '?' || ret -> val == ch)
			return ret -> next;
		if (ret -> fail == ret)
			return ret;
		ret = ret -> fail;
	}
}

int main()
{
	freopen("sample.in", "r", stdin);
	freopen("sample.out", "w", stdout);

	scanf("%s", buffer);
	clr(node, 0);
	for (char* ch = buffer; *ch; ++ch)
		ins(*ch);
	int n;
	scanf("%d", &n);
	rep(i, 1, n)
	{
		scanf("%s", buffer);
		Node* now = node;
		for (char* ch = buffer; *ch; ++ch)
		{
			now = match(now, *ch);
			if (!now)
				break;
		}
		if (now == tail)
			printf("YES\n");
		else
			printf("NO\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
