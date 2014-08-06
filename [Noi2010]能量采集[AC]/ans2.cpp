#include "mode.h"
 
using namespace std ;
 
#define ll long long
#define Sum( l , r ) ( sum[ r ] - sum[ l - 1 ] )
#define maxn 100100
 
bool f[ maxn ] ;
int u[ maxn ] , n , m , sum[ maxn ] ;
ll ans = 0 ;
 
void Init(  ) {
    memset( f , true , sizeof( f ) ) ;
    f[ 0 ] = f[ 1 ] = false , u[ 1 ] = 1 ; 
    for ( int i = 1 ; i ++ < min( n , m ) ; ) if ( f[ i ] ) {
        u[ i ] = - 1 ; 
        for ( int j = i << 1 ; j <= min( n , m ) ; j += i ) {
            f[ j ] = false ;
            if ( ! ( ( j / i ) % i ) ) u[ j ] = 0 ; else u[ j ] = u[ j / i ] * - 1 ;
        }
    }
    sum[ 0 ] = 0 ;
    for ( int i = 0 ; i ++ < min( n , m ) ; ) sum[ i ] = sum[ i - 1 ] + u[ i ] ;
}
 
ll query( int a , int b ) {
    ll ret = 0 ;
    for ( int i = 1 ; i <= min( a , b ) ; ) {
        int pos = min( a / ( a / i ) , b / ( b / i ) ) ;
        ret += ( ll )( Sum( i , pos ) ) * ( ll )( a / i ) * ( ll )( b / i ) ;
        i = pos + 1 ;
    }
    return ret ;
}
 
int main(  ) {
    setIO("sample");
    scanf( "%d%d" , &n , &m ) ;
    Init(  ) ;
    for ( int i = 0 ; i ++ < min( n , m ) ; ) {
        ans += ( ll )( i ) * query( n / i , m / i ) * 2 ;
    }
    ans -= ( ll )( n ) * ( ll )( m ) ;
    printf( "%lld\n" , ans ) ;
    closeIO();
    return 0 ;
}
