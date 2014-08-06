#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std ;
 
#define N 200000000
 
int ch ;
 
void getint( int &t ) {
    for ( ch = getchar(  ) ; ch < '0' || ch > '9' ; ch = getchar(  ) ) ;
    t = ch - '0' ;
    for ( ch = getchar(  ) ; ch >= '0' && ch <= '9' ; ch = getchar(  ) ) t = 10 * t + ch - '0' ;
}
 
#define clear( x ) memset( x , 0 , sizeof( x ) )
 
int n , m ;
 
#define L( t ) left[ t ]
#define R( t ) right[ t ]
#define T( t ) tag[ t ]
#define maxv 5001000
 
int left[ maxv ] , right[ maxv ] , tag[ maxv ] , V = 0 ;
 
void Init_sgt(  ) {
    clear( left ) , clear( right ) , clear( tag ) ;
    T( V = 1 ) = 0 ;
}
 
void pushdown( int t ) {
    if ( T( t ) ) {
        T( L( t ) ) = T( t ) , T( R( t ) ) = T( t ) ;
        T( t ) = 0 ;
    }
}
 
void change( int l , int r , int _l , int _r , int c , int t ) {
    if ( _l < _r ) {
        if ( ! L( t ) ) L( t ) = ++ V ;
        if ( ! R( t ) ) R( t ) = ++ V ;
        pushdown( t ) ;
    }
    if ( l == _l && r == _r ) {
        T( t ) = c ;
        return ;
    }
    int mid = ( _l + _r ) >> 1 ;
    if ( r <= mid ) change( l , r , _l , mid , c , L( t ) ) ; else
    if ( l > mid ) change( l , r , mid + 1 , _r , c , R( t ) ) ; else
    change( l , mid , _l , mid , c , L( t ) ) , change( mid + 1 , r , mid + 1 , _r , c , R( t ) ) ;
}
 
int query( int x , int l , int r , int t ) {
    if ( T( t ) ) return T( t ) ;
    int mid = ( l + r ) >> 1 ;
    return x <= mid ? query( x , l , mid , L( t ) ) : query( x , mid + 1 , r , R( t ) ) ;
}
 
#undef maxv
#undef L( t )
#undef R( t )
 
#define L( t ) Left[ t ]
#define R( t ) Right[ t ]
#define S( t ) Sum[ t ]
#define LL( t ) left_range[ t ]
#define RR( t ) right_range[ t ]
#define maxv 501000
#define F( t ) Father[ t ]
#define G( t ) F( F( t ) )
#define C( t ) ( t == L( F( t ) ) )
 
int Left[ maxv ] , Right[ maxv ] , Sum[ maxv ] , left_range[ maxv ] , right_range[ maxv ] , Father[ maxv ] , Vv ;
int root ;
 
void Init_splay(  ) {
    clear( Left ) , clear( Right ) , clear( Sum ) , clear( left_range ) , clear( right_range ) , clear( Father ) ;
    Vv = root = 1 , S( 1 ) = n , LL( 1 ) = 1 , RR( 1 ) = n ;
}
 
int k , u ;
bool flag ;
 
void update( int t ) {
    S( t ) = S( L( t ) ) + S( R( t ) ) + RR( t ) - LL( t ) + 1 ;
}
 
void zag( int t ) {
    k = R( t ) , u = F( t ) , flag = C( t ) ;
    update( F( R( t ) = L( k ) ) = t ) ;
    update( F( L( k ) = t ) = k ) ;
    if ( F( k ) = u ) if ( flag ) L( u ) = k ; else R( u ) = k ;
}
 
void zig( int t ) {
    k = L( t ) , u = F( t ) , flag = C( t ) ;
    update( F( L( t ) = R( k ) ) = t ) ;
    update( F( R( k ) = t ) = k ) ;
    if ( F( k ) = u ) if ( flag ) L( u ) = k ; else R( u ) = k ;
}
 
void splay( int t , int v ) {
    while ( F( t ) != v ) {
        if ( G( t ) == v ) if ( C( t ) ) zig( F( t ) ) ; else zag( F( t ) ) ; else {
            if ( C( t ) ) {
                if ( C( F( t ) ) ) zig( G( t ) ) ; zig( F( t ) ) ;
            } else {
                if ( ! C( F( t ) ) ) zag( G( t ) ) ; zag( F( t ) ) ;
            }
        }
    }
    if ( ! v ) root = t ;
}
 
#undef maxv
 
int ans = 0 , a , b , c , d , e ;
 
void Get( int p , int t ) {
    splay( t , 0 ) ;
    if ( LL( t ) < p ) {
        k = ++ Vv ;
        LL( k ) = LL( t ) , RR( k ) = p - 1 ;
        update( F( L( k ) = L( t ) ) = k ) ;
        update( F( L( t ) = k ) = t ) ;
        change( LL( k ) , RR( k ) , 1 , N , k , 1 ) ;
    }
    if ( RR( t ) > p ) {
        k = ++ Vv ;
        LL( k ) = p + 1 , RR( k ) = RR( t ) ;
        update( F( R( k ) = R( t ) ) = k ) ;
        update( F( R( t ) = k ) = t ) ;
        change( LL( k ) , RR( k ) , 1 , N , k , 1 ) ;
    }
    LL( t ) = RR( t ) = p ;
}
 
int Max( int t ) {
    for ( ; R( t ) ; t = R( t ) ) ;
    return t ;
}
 
int Min( int t ) {
    for ( ; L( t ) ; t = L( t  ) ) ;
    return t ;
}
 
int Select( int s ) {
    int t ;
    for ( t = root ; ; ) {
        if ( s >= S( L( t ) ) && s - S( L( t ) ) < RR( t ) - LL( t ) + 1 ) {
            s -= S( L( t ) ) ;
            break ;
        }
        if ( s < S( L( t ) ) ) t = L( t ) ; else {
            s -= ( S( L( t ) ) + RR( t ) - LL( t ) + 1 ) ;
            t = R( t ) ;
        }
    }
    splay( t , 0 ) ;
    return LL( t ) + s ;
}
FILE * debug;
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);debug = fopen("debug.txt","w");
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);fclose(debug);
 #endif
} 

int main(  ) {
    setIO("sample");
    getint( n ) , getint( m ) ;
    Init_sgt(  ) , Init_splay(  ) ;
    change( 1 , n , 1 , N , 1 , 1 ) ;
    while ( m -- ) {
        getint( a ) , getint( b ) ;
        b -= ans ;
        if ( a == 1 ) {
            getint( c ) ;
            c -= ans ;
            d = query( b , 1 , N , 1 ) ;
            Get( b , d ) ;
            printf( "%d\n" , ans = S( L( d ) ) + 1 ) ;
            change( b , b , 1 , N , 0 , 1 ) ;
            change( c , c , 1 , N , d , 1 ) ;
            LL( d ) = RR( d ) = c ;
        } else if ( a == 2 ) {
            c = query( b , 1 , N , 1 ) ;
            Get( b , c ) ;
            printf( "%d\n" , ans = S( L( c ) ) + 1 ) ;
            if ( L( c ) ) {
                splay( d = Max( L( c ) ) , c ) ;
                update( F( R( d ) = R( c ) ) = d ) ;
                L( c ) = 0 , update( F( R( c ) = d ) = c ) ;
            }
        } else if ( a == 3 ) {
            c = query( b , 1 , N , 1 ) ;
            Get( b , c ) ;
            printf( "%d\n" , ans = S( L( c ) ) + 1 ) ;
            if ( R( c ) ) {
                splay( d = Min( R( c ) ) , c ) ;
                update( F( L( d ) = L( c ) ) = d ) ;
                R( c ) = 0 , update( F( L( c ) = d ) = c ) ;
            }
        } else {
            printf( "%d\n" , ans = Select( b - 1 ) ) ;
        }
    }
    closeIO();
    return 0 ;
}
