#include<iostream>
using namespace std;
char a[8][8];
int enter=0;
void display()
{
    cout << '\t';
    for ( int k = 1 ; k <= 8 ; k++ )
    cout << k << '\t';
    cout << endl;
    cout << endl;
    for ( int i = 0 ; i < 8 ; i++ )
    {
        cout << i+1 << '\t';
        for ( int j = 0 ; j < 8 ; j++ )
        {
            cout << a[i][j] << '\t';
        }
        cout << endl << endl;
    }
}

int east(int x, int y,char ch)//right
{
    int l = y,f=0;
    if(a[x][y+1] == ch || a[x][y+1] == '-')
    return 0;
    for(int i = y+2 ; i < 8 ; i++ )
    {
        if(a[x][i] == '-')
            return 0;
        if(a[x][i] == ch )
            {
                l = i;
                break;
            }
    }
    for(int j = l-1 ; j >= y ; j-- )
    {
        a[x][j] = ch;
        f=1;
    }
    if(f==1)
    {
        enter = 1;
        return 1;
    }
    else 
    return 0;
}

int west(int x, int y,char ch)//left
{
    int l = y,f=0;
    if(a[x][y-1] == ch || a[x][y-1] == '-')
    return 0;
    for(int i = y-2 ; i >= 0 ; i-- )
    {
        if( a[x][i] == '-' )
            return 0;
        if( a[x][i] == ch )
            {
                l = i;
                break;
            }
    }
    for(int j = l+1 ; j <= y ; j++ )
    {
        a[x][j] = ch;
        f=1;
    }
    if(f==1)
    {
        enter = 1;
        return 1;
    }
    else
    return 0;
}

int north(int x, int y,char ch)//up
{
    int l = x,f=0;
    if(a[x-1][y] == ch || a[x-1][y] == '-')
    return 0;
    for(int i = x-2 ; i >= 0 ; i-- )
    {
        if( a[i][y] == '-' )
            return 0;
        if( a[i][y] == ch )
            {
                l = i;
                break;
            }
    }
    for( int j = l+1 ; j <= x ; j++ )
    {
        a[j][y] = ch;
        f=1;
    }
    if(f==1)
    {
        enter = 1;
        return 1;
    }
    else
    return 0;
}

int south(int x, int y,char ch)//down
{
    int l = x,f=0;
    if(a[x+1][y] == ch || a[x+1][y] == '-')
    return 0;
    for(int i = x+2 ; i < 8 ; i++ )
    {
        if( a[i][y] == '-')
            return 0;
        if( a[i][y] == ch )
            {
                l = i;
                break;
            }
    }
    for ( int j = l-1 ; j >= x ; j-- )
    {
        a[j][y] = ch;
        f=1;
    }
    if(f==1)
    {
        enter = 1;
        return 1;
    }
    else
    return 0;
}

int southwest(int x, int y,char ch)//downleft
{
    int m = x, n = y,f=0;
    if(a[x+1][y-1] == ch || a[x+1][y-1] == '-')
    return 0;
    for ( int i = x+2, j = y-2 ; i < 8 && j >= 0 ; i++, j-- )
    {
        if( a[i][j] == '-')
        {
            return 0;
        }
        if ( a[i][j] == ch)
            {
                m = i;
                n = j;
                break;
            }
    }
    for( int i = m-1, j = n+1 ; i >= x && j <= y ; i--, j++ )
    {
        a[i][j] = ch;
        f=1;
    }
    if(f==1)
    {
        enter = 1;
        return 1;
    }
    else 
    return 0;
}

int southeast(int x, int y,char ch)//downright
{
     int m=x,n=y,f=0;
     if(a[x+1][y+1] == ch || a[x+1][y+1] == '-')
     return 0;
     for ( int i = x+2, j=y+2; i<8 && j<8; i++,j++)
     {
         if(a[i][j] == '-')
             return 0;
       if(a[i][j] == ch)
            {
                m=i;
                n=j;
                break;
            }
    }
     for(int i=m-1,j=n-1; i>=x && j>=y; i--,j--)
     {
         a[i][j]=ch;
         f=1;
     }
     if(f==1)
     {
        enter = 1;
        return 1;
     }
     else 
     return 0;
}

int northwest(int x, int y,char ch)//upleft
{
    int m=x,n=y,f=0;
    if(a[x-1][y-1] == ch || a[x-1][y-1] == '-')
    return 0;
    for (int i=x-2,j=y-2; i>=0 && j>=0; i--,j--)
    {
        if(a[i][j] == '-')
            return 0;
        if(a[i][j] == ch)
            {
                m=i;
                n=j;
                break;
            }
    }
    for(int i=m+1,j=n+1;i<=x && j<=y; i++,j++)
    {
        a[i][j]=ch;
        f=1;
    }
    if(f==1)
    {
        enter = 1;
        return 1;
    }
    else
    return 0;
}

int northeast(int x, int y,char ch)//upright
{ 
    int m=x,n=y,f=0;
    if(a[x-1][y+1] == ch || a[x-1][y+1] == '-')
    return 0;
    for (int i=x-2,j=y+2;i>=0 && j<8;i--,j++)
    {
        if(a[i][j] == '-')
            return 0;
        if(a[i][j] == ch)
            {
                m=i;
                n=j;
                break;
            }
    }
    for(int i=m+1,j=n-1; i<=x && j>=y; i++,j--)
    {
        a[i][j]=ch;
        f=1;
    }
    if(f==1)
    {
        enter = 1;
        return 1;
    }
    else
    return 0;
}

void who_is_winner()
{
    int white = 0, black = 0;
    for(int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ( a[i][j] == 'w')
            white++;
            else
            black++;
        }
    }
    (white == black) ? (cout << "draw match") : ((white > black) ? cout << "white is winner...!!" : cout << "black is winner...!!" << endl);
}

int main()
{
    int x,y;
    char c;
    for ( int i = 0 ; i < 8 ; i++ )
    {
        for ( int j = 0 ; j < 8 ; j++ )
        {
            a[i][j] = '-';
        }
    }
    a[3][3]=a[4][4]='W';
    a[3][4]=a[4][3]='B';
    cout << "player 1 : B...player 2 : W " << endl ;
    display();
    for(int empty = 60; empty > 0 ; empty--)
    {
        (empty % 2 == 0 ) ? cout << "player 1...B... turn : " <<endl : cout << "player 2...W... turn : " << endl;
        cout << "enter the row and column : ";
        cin >> x >> y;
        x=x-1;
        y=y-1;
        c = ( (empty % 2) == 0 ) ? 'B' : 'W';
        if(a[x][y] == '-')
        {
            east(x,y,c);
            west(x,y,c);
            north(x,y,c);
            south(x,y,c);
            northeast(x,y,c);
            northwest(x,y,c);
            southeast(x,y,c);
            southwest(x,y,c);
            if(enter == 0)
            {
                cout << "your entry is invalid...please give a valid entry..." << endl;
                empty++;
            }
        }
        else 
        {
            cout << "your entry is invalid...please give a valid entry..." << endl;
            empty++;
        }
        cout << "the updated puzzle is : " << endl;
        display();
        enter = 0;
    }
    who_is_winner();
    return 0;
}                       