namespace fastIO
{
	const int size=1<<15|1,maxl=23;
	char buf[size],*l,*r;
	void getChar(char &c)
	{
		if(l==r) r=(l=buf)+fread(buf,1,size,stdin);
		c=l==r?(char)EOF:*l++;
	}
	template<typename T>inline void read(T &x) 
	{
		char c;x=0;int f=1;
		getChar(c);
		while(c>'9'||c<'0'){if(c=='-') f=-1;getChar(c);}
		while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',getChar(c);
		x*=f;
	}
	template<typename T>inline void put(T x)
    {
        if(!x){putchar('0');return;}
        if(x<0){x=-x;putchar('-');}
        static int out[maxl];
        int len=0;
        while(x){out[++len]=x%10;x/=10;}
        while(len)putchar(out[len--]+'0');
    }
}