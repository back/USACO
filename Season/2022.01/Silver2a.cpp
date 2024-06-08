#include <stdio.h>
#include <vector>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main( int argc, char** argv )
{
        int n = 0;
        char sz_count[ 128 ];
        fgets( sz_count, 128, stdin );
        n = strtol( sz_count, nullptr, 10 );
        char sz_height[ 128 ] = {0};
        fgets( sz_height, 1000000, stdin );
        if( strlen( sz_height ) == 0 )
                return EINVAL;
        char* token = strtok( sz_height, " \n" );
        std::vector< int > p;
        while( token != nullptr )
        {
               int num = strtol( token, nullptr, 10 );
               p.push_back( num );
               token = strtok(nullptr, " ");
               if (token == NULL)
                   break;
        }

        std::vector<int> q;
        for( int i = 0; i < n; i++ )
                q.push_back( -1 );
        long long answer = ( n - 1 )*2;
        for( int i = 1; i < n; i++ )
        {
                int tracer = i - 1;
                while( tracer > -1 && p[ tracer ] < p[ i ] )
                {
                        tracer = q[ tracer ];
                        if( tracer > -1 )
                                answer += i - tracer + 1;
                }
                q[ i ] = tracer;
        }
        printf( "%d\n", answer );
        return 0;
}
