#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> Row_index;
vector<int> Row;
vector<int> Col;

bool Loop = true;

void Game_Loop();
void Draw_game_board();
void static_start_shape();
void Display_game_board();

int main()
{
    Draw_game_board();
    Display_game_board();
    while (Loop)
    {
        Game_Loop();
    }

    return 0;
}

void Game_Loop()
{
    bool Loop = false;
}

void Draw_game_board()
{
    int n;
    cout << "How many tiles would you like the sqaure side to be?" << endl;
    cin >> n;

    for (int i = 0; i < n + 2; i++)
    {
        Row_index.push_back(0);
        Row.push_back(0);
    }

    static_start_shape();
}

void static_start_shape()
{
    Row[4] = 1;
}

void Display_game_board()
{
    int n = Row_index.size();
    for (int i = 0; i < n; i++)
    {
        for (const auto &num : Row)
        {
            cout << num << ' ';
        }
        cout << endl;
    }
}