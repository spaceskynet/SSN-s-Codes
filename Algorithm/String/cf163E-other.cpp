struct FENWICK_TREE
{
	int table[MAXN];
	int size;
	void init(int tn)
	{
		size = tn;
		memset(table+1, 0, sizeof(table[0])*size);
	}

	void add(int sour, int value)
	{
		for(int i = sour; i <= size; i += i&-i)
			table[i] += value;
	}

	int query(int sour)
	{
		int ret = 0;
		for(int i = sour; i >= 1; i -= i&-i)
			ret += table[i];
		return ret;
	}
};

FENWICK_TREE ft;

int left[MAXN], right[MAXN];
int count;

struct TREE
{
	struct EDGE
	{
		int v, next;
	};
	int first[MAXN];
	EDGE edge[MAXN];
	int rear;
	void init(int tn)
	{
		memset(first, -1, sizeof(first[0])*(tn+1));
		rear = 0;
	}
	void insert(int tu, int tv)
	{
		edge[rear].v = tv;
		edge[rear].next = first[tu];
		first[tu] = rear++;
	}
	void dfs(int u)
	{
		left[u] = ++count;
		for(int i = first[u]; ~i; i = edge[i].next)
			dfs(edge[i].v);
		right[u] = count;
	}
};

TREE tree;

bool del[100010];
int ind[100010];
char str[MAXN];

struct AC
{
	int ch[MAXN][SIGMA_SIZE];
	int val[MAXN], f[MAXN];
	int size;
	inline int idx(char temp)
	{
		return temp-'a';
	}
	void init()
	{
		memset(ch[0], 0, sizeof(ch[0]));
		f[0] = val[0] = 0;
		size = 1;
	}
	void insert(char *S, int tn)
	{
		int u = 0, id;
		for(char *sp = S; *sp; ++sp)
		{
			id = idx(*sp);
			if(!ch[u][id])
			{
				memset(ch[size], 0, sizeof(ch[size]));
				f[0] = val[0] = 0;
				ch[u][id] = size++;
			}
			u = ch[u][id];
		}
		val[u] = 1;
		ind[tn] = u;
	}
	int que[MAXN], front, back;
	void construct()
	{
		int u, cur;
		front = back = 0;
		for(int i = 0; i < SIGMA_SIZE; ++i)
			if(ch[0][i])
			{
				que[back++] = ch[0][i];
				f[ch[0][i]] = 0;
			}
		while(front < back)
		{
			cur = que[front++];
			for(int i = 0; i < SIGMA_SIZE; ++i)
			{
				u = ch[cur][i];
				if(u)
				{
					que[back++] = u;
					f[u] = ch[f[cur]][i];
					val[u] += val[f[u]];
				}
				else
					ch[cur][i] = ch[f[cur]][i];
			}
		}
	}
	int query(char *S)
	{
		int u = 0, ret = 0, id;
		for(char *sp = S; *sp; ++sp)
		{
			id = idx(*sp);
			u = ch[u][id];
			if(val[u])
				ret += ft.query(left[u]);
		}
		return ret;
	}
};

AC ac;

void solve(int n, int K)
{
	ac.init();
	for(int i = 1; i <= K; ++i)
	{
		scanf("%s", str);
		ac.insert(str, i);
		del[i] = false;
	}
	ac.construct();
	tree.init(ac.size);
	for(int i = 1; i < ac.size; ++i)
		tree.insert(ac.f[i], i);
	count = 0;
	tree.dfs(0);
	ft.init(ac.size);
	for(int i = 0; i < ac.size; ++i)
	{
		ft.add(left[i], ac.val[i]);
		ft.add(left[i]+1, -ac.val[i]);
	}
	char flag;
	int temp;
	for(int i = 0; i < n; ++i)
	{
		scanf(" %c", &flag);
		if(flag == '?')
		{
			scanf("%s", str);
			printf("%d\n", ac.query(str));
		}
		else if(flag == '+')
		{
			scanf("%d", &temp);
			if(del[temp])
			{
				del[temp] = false;
				ft.add(left[ind[temp]], 1);
				ft.add(right[ind[temp]]+1, -1);
			}
		}
		else
		{
			scanf("%d", &temp);
			if(!del[temp])
			{
				del[temp] = true;
				ft.add(left[ind[temp]], -1);
				ft.add(right[ind[temp]]+1, 1);
			}
		}
	}
}

int main()
{
	int n, K;
	while(~scanf("%d%d", &n, &K))
	{
		solve(n, K);
	}
	return 0;
}
