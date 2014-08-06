//By BLADEVIL
#include <cstdio>
#include <cstring>
#define maxn 100010
#define LL long long
#pragma comment(linker,"/STACK:102400000,102400000")


using namespace std;

LL n,l;
LL pre[maxn<<1],other[maxn<<1],last[maxn],key[maxn],color[maxn],sum[maxn],size[maxn],num[maxn],a0[maxn],a1[maxn],que[maxn],flag[maxn],father[maxn];
LL ans,ANS,ANSor,ansor,ANSx,ansx;

void connect(LL x,LL y) {
    //printf("%d %d %d\n",x,y,l);
    pre[++l]=last[x];
    last[x]=l;
    other[l]=y;
}

void update(LL x){
    //printf("%d ",x);
    sum[x]=color[x]; size[x]=1; num[x]=0; 
    if (color[x]) a1[x]=1,a0[x]=0; else a0[x]=1,a1[x]=0;
    for (LL p=last[x];p;p=pre[p]) {
        if (other[p]==father[x]) continue;
        size[x]+=size[other[p]];
    }
    if (sum[x]) {
        LL tot=0;
        for (LL p=last[x];p;p=pre[p]) if (other[p]!=father[x]) ans+=2*sum[other[p]],tot+=sum[other[p]];
        for (LL p=last[x];p;p=pre[p]) if (other[p]!=father[x]) ans+=sum[other[p]]*(tot-sum[other[p]]);
        sum[x]+=tot;
    }
    if (color[x]) {
        for (LL p=last[x];p;p=pre[p])
            if (other[p]!=father[x]) ansor+=size[other[p]]*(size[x]-size[other[p]]);
        num[x]=size[x];ansor+=num[x]; 
    } else {
        LL tot=size[x];
        for (LL p=last[x];p;p=pre[p])
            if (other[p]!=father[x])
              ansor+=2*num[other[p]]*(tot-size[other[p]]),num[x]+=num[other[p]],tot-=num[other[p]];
    }
    if (color[x]) {
        LL tot0=0,tot1=0;
        for (LL p=last[x];p;p=pre[p]) 
            if (other[p]!=father[x]) tot0+=a0[other[p]],tot1+=a1[other[p]];
        ansx+=2*tot0+1;
        for (LL p=last[x];p;p=pre[p]) 
            if (other[p]!=father[x]) ansx+=2*a0[other[p]]*(tot0-a0[other[p]]),tot0-=a0[other[p]];
        for (LL p=last[x];p;p=pre[p])
            if (other[p]!=father[x]) ansx+=2*a1[other[p]]*(tot1-a1[other[p]]),tot1-=a1[other[p]];
        for (LL p=last[x];p;p=pre[p])
            if(other[p]!=father[x]) a1[x]+=a0[other[p]],a0[x]+=a1[other[p]];
    } else {
        LL tot0=0,tot1=0;
        for (LL p=last[x];p;p=pre[p])
            if (other[p]!=father[x]) tot0+=a0[other[p]],tot1+=a1[other[p]];
        ansx+=2*tot1;
        for (LL p=last[x];p;p=pre[p])
            if (other[p]!=father[x]) ansx+=2*a1[other[p]]*(tot0-a0[other[p]]);
        for (LL p=last[x];p;p=pre[p])
            if (other[p]!=father[x]) a1[x]+=a1[other[p]],a0[x]+=a0[other[p]];
    }
    //printf("%d %d\n",x,ansor);
    //printf("%d %d\n",x,ansx);
}

int main() {
    freopen("sample.in","r",stdin); freopen("sample.out","w",stdout);
    LL task,x,y; scanf("%lld",&task);
    while (task--) {
        memset(last,0,sizeof last); 
        memset(flag,0,sizeof flag); l=0;
        ANS=ANSor=ANSx=0;
        scanf("%lld",&n);
        for (LL i=1;i<=n;i++) scanf("%lld",&key[i]);
        for (LL i=1;i<n;i++) {
            scanf("%lld%lld",&x,&y); 
            connect(x,y); connect(y,x);    
        }
        //printf("fuck\n");    
        LL h=0,t=1;
        que[1]=1; flag[1]=1;
        while (h<t) {
            LL cur=que[++h];
            flag[cur]=1;
            for (LL p=last[cur];p;p=pre[p]) {
                if (flag[other[p]]) continue;
                que[++t]=other[p];
                father[other[p]]=cur;
            }
        }
        //for (LL i=1;i<=n;i++) printf("%d ",que[i]);
        LL cur=1;
        for (LL i=1;i<=20;i++) {
            for (LL j=1;j<=n;j++) color[j]=(key[j]&cur)?1:0;
            ans=ansor=ansx=0; //work(1,-1);
            for (LL j=n;j;j--) update(que[j]);
            for (LL j=1;j<=n;j++) ans+=color[j]; //printf("%d\n",ansor);//printf("%d\n",ans);
            ANS+=ans*cur;
            ANSor+=ansor*cur;
            ANSx+=ansx*cur;
            //for (LL j=1;j<=n;j++) printf("%d %d %d\n",j,size[j],sum[j]); printf("\n");
            //for (LL j=1;j<=n;j++) printf("%d %d %d\n",j,size[j],num[j]); printf("\n");
            //for (LL j=1;j<=n;j++) printf("%d %d %d\n",j,a0[j],a1[j]); printf("\n");
            cur<<=1;
        }
        double ans1=double(ANS)/double(n*n);
        double ans2=double(ANSor)/double(n*n);
        double ans3=double(ANSx)/double(n*n);
        printf("%.3f %.3f %.3f\n",ans1,ans2,ans3);
    }
    fclose(stdin); fclose(stdout);
    return 0;
}
