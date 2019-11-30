
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

int east(int x, int y,char ch,int change)//right
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
        if(change == 1)
        {
            a[x][j] = ch;
        }
        f = f + 1;
    }
    if(f != 0)
    {
        // cout << "right : " << f-1 << endl;
        enter = 1;
        return f-1;
    }
    else 
    return 0;
}

int west(int x, int y,char ch,int change)//left
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
        if(change == 1)
        {
            a[x][j] = ch;
        }
        f = f + 1;
    }
    if(f != 0)
    {
        // cout << "left : " << f-1 << endl;
        enter = 1;
        return f-1;
    }
    else
    return 0;
}

int north(int x, int y,char ch,int change)//up
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
        if(change == 1)
        {
            a[j][y] = ch;
        }
        f = f + 1;
    }
    if(f != 0)
    {
        // cout << "up : " << f-1 << endl;
        enter = 1;
        return f-1;
    }
    else
    return 0;
}

int south(int x, int y,char ch,int change)//down
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
        if(change == 1)
        {
            a[j][y] = ch;
        }
        f = f + 1;
    }
    if(f != 0)
    {
        // cout << "down : " << f-1 << endl;
        enter = 1;
        return f-1;
    }
    else
    return 0;
}

int southwest(int x, int y,char ch,int change)//downleft
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
        if(change == 1)
        {
            a[i][j] = ch;
        }
        f = f + 1;
    }
    if(f != 0)
    {
        // cout << "downleft : " << f-1 << endl;
        enter = 1;
        return f-1;
    }
    else 
    return 0;
}

int southeast(int x, int y,char ch,int change)//downright
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
         if(change == 1)
         {
            a[i][j]=ch;
         }
         f = f + 1;
     }
     if(f != 0)
     {
        // cout << "downright : " << f-1 << endl;
        enter = 1;
        return f-1;
     }
     else 
     return 0;
}

int northwest(int x, int y,char ch,int change)//upleft
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
        if(change == 1)
        {
            a[i][j]=ch;
        }
        f = f + 1;
    }
    if(f != 0)
    {
        // cout << "upleft : " << f-1 << endl;
        enter = 1;
        return f-1;
    }
    else
    return 0;
}

int northeast(int x, int y,char ch,int change)//upright
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
        if(change == 1)
        {
            a[i][j]=ch;
        }
        f = f + 1;
    }
    if(f != 0)
    {
        // cout << "upright : " << f-1 << endl;
        enter = 1;
        return f-1;
    }
    else
    return 0;
}

int computer_turn(char c)
{
    int highest_flips = 0;
    int computer_entry = 0;
    for(int i = 0 ; i < 8; i++)
    {
        for(int j = 0 ;j < 8; j++)
        {
            if(a[i][j] == '-')
            {
                int current_flips = 0;
                current_flips = current_flips + north(i,j,c,0) + south(i,j,c,0) + east(i,j,c,0) + west(i,j,c,0) + northeast(i,j,c,0) + northwest(i,j,c,0) + southeast(i,j,c,0) + southwest(i,j,c,0);
                if(current_flips > highest_flips)
                {
                    highest_flips = current_flips;
                    computer_entry = (i * 10) + j;
                }
            }
        }
    }
    // cout << "Highest Flips : " << highest_flips << endl; 
    return computer_entry;
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
    (white == black) ? (cout << "draw match") : ((white > black) ? cout << "Computer is winner...!!" : cout << "Player is winner...!!" << endl);
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
        (empty % 2 == 0 ) ? cout << "player 1...B... turn : " <<endl : cout << "Computer...W... turn : " << endl;
        c = ( (empty % 2) == 0 ) ? 'B' : 'W';
        if(empty % 2 == 0)
        {
            cout << "enter the row and column : ";
            cin >> x >> y;
            x=x-1;
            y=y-1;
            if(a[x][y] == '-')
            {
                east(x,y,c,1);
                west(x,y,c,1);
                north(x,y,c,1);
                south(x,y,c,1);
                northeast(x,y,c,1);
                northwest(x,y,c,1);
                southeast(x,y,c,1);
                southwest(x,y,c,1);
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
        }
        else
        {
            int computer_entry = computer_turn(c);
            x = computer_entry / 10;
            y = computer_entry % 10;
            cout << "Computer Entry is : " << x+1 << " " << y+1 << endl << endl;
            east(x,y,c,1);
            west(x,y,c,1);
            north(x,y,c,1);
            south(x,y,c,1);
            northeast(x,y,c,1);
            northwest(x,y,c,1);
            southeast(x,y,c,1);
            southwest(x,y,c,1);
        }
        cout << "the updated puzzle is : " << endl;
        display();
        enter = 0;
    }
    who_is_winner();
    return 0;
}                       