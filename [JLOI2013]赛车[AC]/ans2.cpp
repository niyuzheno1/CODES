#include "mode.h"
 
using namespace std ;
 
#define MAXN 10010
 
struct Line {
    int k , b , t ;
    bool operator < ( const Line &a ) const {
        return k < a.k || ( k == a.k && b > a.b ) ;
    }
    bool operator == ( const Line &a ) const {
        return k == a.k && b == a.b ;
    }
} line[ MAXN ] ;
 
int Stack[ MAXN ] , top = 0 , ans[ MAXN ] , ansn = 0 , n ;
 
struct Pos {
    double x , y ;
    Pos( double _x , double _y ) :x( _x ) ,y( _y ) {
    }
};
 
double Value( int a , double x ) {
    return line[ a ].k * x + line[ a ].b ;
}
 
Pos Cross( int a , int b ) {
    double x = double( line[ b ].b - line[ a ].b ) / double( line[ a ].k - line[ b ].k ) ;
    return Pos( x ,Value( a , x ) ) ;
}
 
int main(  ) {
    setIO("sample");
    scanf( "%d" , &n ) ;
    for ( int i = 0 ; i ++ < n ; )scanf( "%d" , &line[ i ].b ) ;
    for ( int i = 0 ; i ++ < n ; )scanf( "%d" , &line[ i ].k ) ;
    for ( int i = 0 ; i ++ < n ; ) line[ i ].t = i ;
    sort( line + 1 , line + n + 1 ) ;
    for ( int i = 0 ; i ++ < n ; ) {
        if ( top && line[ Stack[ top ] ].k == line[ i ].k ) continue ;
        while ( top ) {
            Pos p =Cross( i , Stack[ top ] ) ;
            if ( p.x < 0 ) top -- ; else
            if ( top > 1 &&Value( Stack[ top - 1 ] , p.x ) > p.y ) top -- ;
            else break ;
        }
        Stack[ ++ top ] = i ;
    }
    for ( int i = 0 ; i ++ < top ; ) {
        for ( int j = Stack[ i ] ; j <= n && line[ j ] == line[ Stack[ i ] ] ; j ++ ) ans[ ++ ansn ] = line[ j ].t ;
    }
    sort( ans + 1 , ans + ansn + 1 ) ;
    printf( "%d\n" , ansn ) ;
    for ( int i = 0 ; i ++ < ansn - 1 ; )printf( "%d " , ans[ i ] ) ;
    printf( "%d\n" , ans[ ansn ] ) ;
    closeIO();
    return 0 ;
}
