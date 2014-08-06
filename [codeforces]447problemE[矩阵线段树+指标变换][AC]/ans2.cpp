#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define me(x) memset(x,0,sizeof(x))
#define LL long long
#define mo 1000000009ll
#define maxn 300005
struct matrix
{
	LL a[3][3];
};
typedef struct matrix M;
M cheng(M X,M Y)
{
	long i,j,k;
	M re;
	me(re.a);
	for (i=0;i<3;i++) for (j=0;j<3;j++) for (k=0;k<3;k++) re.a[i][j]=(re.a[i][j]+X.a[i][k]*Y.a[k][j])%mo;
	return re;
}
M A[maxn];
long n,m,y[maxn];
struct segtree
{
	long l,r;
	LL su,c1,c2;
};
struct segtree t[maxn*4];
void update(long o)
{
	t[o].su=(t[o<<1].su+t[(o<<1)+1].su)%mo;
}
LL f(LL p,LL q,long k)
{
	LL re=(A[k-1].a[0][0]*p%mo+A[k-1].a[0][1]*q%mo)%mo;
	return re;
}
LL s(LL p,LL q,long k)
{
	LL re=(A[k].a[2][0]*p%mo+A[k].a[2][1]*q%mo)%mo;
	return re;
}
void pushdown(long o)
{
	LL d1,d2;
	if (t[o].c1||t[o].c2)
	{
		t[o<<1].c1=(t[o<<1].c1+t[o].c1)%mo;
		t[o<<1].c2=(t[o<<1].c2+t[o].c2)%mo;
		t[o<<1].su=(t[o<<1].su+s(t[o].c1,t[o].c2,t[o<<1].r-t[o<<1].l+1))%mo;
		d1=f(t[o].c1,t[o].c2,t[o<<1].r-t[o<<1].l+2);
		d2=f(t[o].c1,t[o].c2,t[o<<1].r-t[o<<1].l+3);
		t[(o<<1)+1].c1=(t[(o<<1)+1].c1+d1)%mo;
		t[(o<<1)+1].c2=(t[(o<<1)+1].c2+d2)%mo;
		t[(o<<1)+1].su=(t[(o<<1)+1].su+s(d1,d2,t[(o<<1)+1].r-t[(o<<1)+1].l+1))%mo;
		t[o].c1=t[o].c2=0;
	}
}
void maketree(long o,long ll,long rr)
{
	t[o].l=ll; t[o].r=rr; t[o].c1=t[o].c2=0;
	if (ll==rr)
	{
		t[o].su=y[ll];
	}
	else
	{
		long mid=(ll+rr)>>1;
		maketree(o<<1,ll,mid);
		maketree((o<<1)+1,mid+1,rr);
		update(o);
	}
}
LL getsum(long o,long ll,long rr)
{
	if (t[o].l==ll&&t[o].r==rr) return t[o].su;
	pushdown(o);
	long mid=(t[o].l+t[o].r)>>1;
	if (rr<=mid) return getsum(o<<1,ll,rr);
	if (ll>mid) return getsum((o<<1)+1,ll,rr);
	return (getsum(o<<1,ll,mid)+getsum((o<<1)+1,mid+1,rr))%mo;
}
void change(long o,long ll,long rr,LL f1,LL f2)
{
	if (t[o].l==ll&&t[o].r==rr)
	{
		t[o].c1=(t[o].c1+f1)%mo;
		t[o].c2=(t[o].c2+f2)%mo;
		t[o].su=(t[o].su+s(f1,f2,t[o].r-t[o].l+1))%mo;
		return;
	}
	pushdown(o);
	long mid=(t[o].l+t[o].r)>>1;
	if (rr<=mid) change(o<<1,ll,rr,f1,f2);
	else if (ll>mid) change((o<<1)+1,ll,rr,f1,f2);
	else
	{
		change(o<<1,ll,mid,f1,f2);
		change((o<<1)+1,mid+1,rr,f(f1,f2,mid-ll+2),f(f1,f2,mid-ll+3));
	}
	update(o);
}
int main()
{
	long o,p,q,i;
	scanf("%ld %ld",&n,&m);
	for (i=1;i<=n;i++) scanf("%ld",&y[i]);
	me(A[0].a);
	A[0].a[0][0]=A[0].a[1][1]=A[0].a[2][2]=1;
	A[1].a[0][0]=0;
	A[1].a[0][1]=A[1].a[1][0]=A[1].a[1][1]=A[1].a[2][0]=A[1].a[2][2]=1;
	for (i=2;i<=n;i++) A[i]=cheng(A[i-1],A[1]);
	maketree(1,1,n);
	for (i=1;i<=m;i++)
	{
		scanf("%ld %ld %ld",&o,&p,&q);
		if (o==1)
		{
			change(1,p,q,1ll,1ll);
		}
		else printf("%I64d\n",getsum(1,p,q));
	}
	return 0;
}
