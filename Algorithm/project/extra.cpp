#include <bits/stdc++.h>
using namespace std;

void change(char & currentPlayer)
{
    currentPlayer = (currentPlayer == 'w') ? 'b' : 'w';
}

int main()
{
    char currentPlayer = 'w';
    
    change(currentPlayer);

    cout<<currentPlayer;
}