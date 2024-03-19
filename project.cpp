#include<iostream>
#include<conio.h>
#include<windows.h>
#include <thread>
#include <mmsystem.h>
#include <chrono>

#define h 26
#define w 60

using namespace std;
int cnt=0;
int coin = 0;
//int health = 100;
bool finish = false;
int E1X = 7, E1Y = 1, E2X = 7, E2Y = 7,E3X = 7, E3Y = 13, E4X = 7, E4Y = 19, PX = 1, PY = 1;
int E5X = 34, E5Y = 1, E6X = 34, E6Y = 7,E7X = 34, E7Y = 13, E8X = 34, E8Y = 19;
void make(char place[][w])
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (place[i][j] == 'P')
            {
                place[i][j] = ' ';
            }
            if (place[i][j] == 'E')
            {
                place[i][j] = '.';

            }
        }
    }

    if (place[PY][PX] == '.')
    {
        sndPlaySound("eat.wav",SND_ASYNC);
        coin++;
    }
    if (place[PY][PX] == '*')
    {
        sndPlaySound("special coin.wav",SND_ASYNC);
        place[PY][PX] = ' ';
        cnt++;

    }

    if (place[PY][PX] == '|')
    {
        system("cls");

        finish=true;
        sndPlaySound("pacdies.wav",SND_ASYNC);
    }

    place[PY][PX] = 'P';
    place[E1Y][E1X] = 'E';
    place[E2Y][E2X] = 'E';
    place[E3Y][E3X] = 'E';
    place[E4Y][E4X] = 'E';
    place[E5Y][E5X] = 'E';
    place[E6Y][E6X] = 'E';
    place[E7Y][E7X] = 'E';
    place[E8Y][E8X] = 'E';

    if (place[PY][PX] == 'E')
    {
        system("cls");
        finish = true;
        sndPlaySound("pacdies.wav",SND_ASYNC);

    }
//
//    if (health < 0) {
//        finish = true;
//    }
}

void playermove()
{
    char ch;
    if (_kbhit())
    {
        ch = _getch();
        if (ch == 'l' && PX < w - 2)   // Increase PX limit to w-2
        {
            PX++;
        }
        else if (ch == 'j' && PX > 1)  // Ensure PX is greater than 1
        {
            PX--;
        }
        else if (ch == 'i' && PY > 1)  // Ensure PY is greater than 1
        {
            PY--;
        }
        else if (ch == 'k' && PY < h - 2)  // Increase PY limit to h-2
        {
            PY++;
        }
    }
}

void enemymove()
{
    if (E1X <21 && E1Y == 1)
    {
        E1X++;
    }
    else if (E1X ==21 && E1Y<6)
    {
        E1Y++;
    }
    else if (E1X >7 && E1Y == 6)
    {
        E1X--;
    }
    else if (E1X == 7 && E1Y > 1)
    {
        E1Y--;
    }



    if (E2X < 21 && E2Y == 7)
    {
        E2X++;
    }
    else if (E2X == 21 && E2Y< 12)
    {
        E2Y++;
    }
    else if (E2X > 7 && E2Y == 12)
    {
        E2X--;
    }
    else if (E2X == 7 && E2Y > 7)
    {
        E2Y--;
    }



    if (E3X < 21 && E3Y == 13)
    {
        E3X++;
    }
    else if (E2X == 21 && E3Y < 18)
    {
        E3Y++;
    }
    else if (E3X > 7 && E3Y == 18)
    {
        E3X--;
    }
    else if (E3X == 7 && E3Y > 7)
    {
        E3Y--;
    }




    if (E4X < 21 && E4Y == 19)
    {
        E4X++;
    }
    else if (E4X == 21 && E4Y < 24)
    {
        E4Y++;
    }
    else if (E4X > 7 && E4Y == 24)
    {
        E4X--;
    }
    else if (E4X == 7 && E4Y > 7)
    {
        E4Y--;
    }


//int E5X = 34, E5Y = 1, E6X = 34, E6Y = 7,E7X = 34, E7Y = 13, E8X = 34, E8Y = 19;

    if (E5X < 48 && E5Y == 1)
    {
        E5X++;
    }
    else if (E5X == 48 && E5Y < 6)
    {
        E5Y++;
    }
    else if (E5X > 34 && E5Y == 6)
    {
        E5X--;
    }
    else if (E5X == 34 && E5Y > 1)
    {
        E5Y--;
    }



    if (E6X < 48 && E6Y == 7)
    {
        E6X++;
    }
    else if (E6X == 48 && E6Y < 12)
    {
        E6Y++;
    }
    else if (E6X > 34 && E6Y == 12)
    {
        E6X--;
    }
    else if (E6X == 34 && E6Y > 7)
    {
        E6Y--;
    }




    if (E7X < 48 && E7Y == 13)
    {
        E7X++;
    }
    else if (E7X == 48 && E7Y < 18)
    {
        E7Y++;
    }
    else if (E7X > 34 && E7Y == 18)
    {
        E7X--;
    }
    else if (E7X == 34 && E7Y > 13)
    {
        E7Y--;
    }





    if (E8X < 48 && E8Y == 19)
    {
        E8X++;
    }
    else if (E8X == 48 && E8Y < 24)
    {
        E8Y++;
    }
    else if (E8X > 34 && E8Y == 24)
    {
        E8X--;
    }
    else if (E8X == 34 && E8Y > 19)
    {
        E8Y--;
    }




}

void draw_place(char place[][w])
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    // Hide the console cursor
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(console, &cursorInfo);

    // Set the cursor position to the top-left corner
    SetConsoleCursorPosition(console, { 0, 0 });

    cout<<endl<<endl;

    for (int i = 0; i < h; i++)
    {
        cout <<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t";
        for (int j = 0; j < w; j++)
        {
            switch (place[i][j])
            {
            case 'P':
                SetConsoleTextAttribute(console, 14); // Yellow color for the player
                cout << char(219);  // Use a block character for the player
                break;
            case 'E':
                SetConsoleTextAttribute(console, 12); // Red color for enemies
                cout << char(219);  // Use a block character for enemies
                break;
            case '.':
                SetConsoleTextAttribute(console, 10); // Green color for coins
                cout << char(250);  // Use a block character for coins
                break;
            case '*':
                SetConsoleTextAttribute(console, 13); // Purple color for health
                cout << char(547);    // Use an extended ASCII heart character for health
                break;
            case '|':
                SetConsoleTextAttribute(console, 7);  // White color for walls
                cout << char(219);  // Use a block character for walls
                break;
            default:
                cout << place[i][j];
            }
        }
        SetConsoleTextAttribute(console, 7); // Reset to default color after each row
        cout << endl;
    }



    cout << "Your Total Coin Is:" << coin << endl;
    cout << "Your Total special Coin Is:" << cnt << endl;
    if(cnt==8 && coin>=200)
    {
        finish=true;
    }
}

void result()
{
    if(cnt==8 && coin>=200)
    {
        system("cls");
        cout << "\n\n\n\n";
        cout << "\t\t\t  Congratulations! You Won The Game.\n";
        cout << "\t\t\t Your Total coin is:" << coin << endl;
        cout<<"t\t\t Your Total special coin="<<cnt<<endl;
    }
    else
    {
//        sndPlaySound("pacdies.wav",SND_ASYNC);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t  You Lost The Game\n";
        cout << "\t\t\t Your Total coin Is: " << coin << endl;
        cout << "\t\t\t Your Total special coin Is: " << cnt << endl;
//    }
    }
}

int main()
{

    while(1)
    {
        cout << "\t-------------------------------" << endl;
        cout << "\t\t Simple Pac Man Game" << " " << " " << " " << endl;
        cout << "\t-------------------------------" << endl;
        cout<<endl;
        cout<< "1.Press 'N' to Play normal mode;"<<endl;
        cout<< "2.Press 'M' to Play mediam mode;"<<endl;
        cout<< "3.Press 'H' to Play hard mode;"<<endl;


        cout<<endl;
        cout<<"Mode:";
        char ch;
        cin>>ch;


        if(ch=='N')
        {
            cout<<endl;
            cout <<"Press 's' to start: ";

            char start;
            cin >> start;
            system("cls");
            if (start == 's')
            {
                char place[h][w] =
                {
                    "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||",
                    "|                                                         |",
                    "|       |||||||||||||              |||||||||||||          |",
                    "|       ||....*....||              ||....*....||          |",
                    "|       ||.........||              ||.........||          |",
                    "|       ||||   ||||||              ||||   ||||||          |",
                    "|                                                         |",
                    "|                                                         |",
                    "|       |||||||||||||              |||||||||||||          |",
                    "|       ||....*....||              ||....*....||          |",
                    "|       ||.........||              ||.........||          |",
                    "|       ||||||   ||||              ||||||   ||||          |",
                    "|                                                         |",
                    "|                                                         |",
                    "|       |||||||||||||              |||||||||||||          |",
                    "|       ||.....*...||              ||.....*...||          |",
                    "|       ||.........||              ||.........||          |",
                    "|       |||||  ||||||              |||||  ||||||          |",
                    "|                                                         |",
                    "|                                                         |",
                    "|       |||||||||||||              |||||||||||||          |",
                    "|       ||.....*...||              ||.....*...||          |",
                    "|       ||.........||              ||.........||          |",
                    "|       ||||||   ||||              ||||||   ||||          |",
                    "|                                                         |",
                    "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||",
                };
                cout<<endl;

                cout << "\tPress 'l' to move right: "<<endl;
                cout << "\tPress 'j' to move left: "<<endl;
                cout << "\tPress 'i' to move up: "<<endl;
                cout << "\tPress 'k' to move down: "<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"\tcondition:"<<endl;
                cout <<"\twin: "<<endl;
                cout <<"\t1.coin>=200"<<endl;
                cout <<"\t2.special coin=8"<<endl;
                while (!finish)
                {
                    make(place);
                    playermove();
                    enemymove();
                    draw_place(place);
                    std::this_thread::sleep_for(std::chrono::milliseconds(250));
                }
                result();
            }
        }



        else if(ch=='M')
        {
            cout<<endl;
            cout <<"Press 's' to start: ";

            char start;
            cin >> start;
            system("cls");
            if (start == 's')
            {
                char place[h][w] =
                {
                    "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||",
                    "|                                                         |",
                    "|       |||||||||||||              |||||||||||||          |",
                    "|       ||....*....||              ||....*....||          |",
                    "|       ||.........||              ||.........||          |",
                    "|       |||||  ||||||              |||||  ||||||          |",
                    "|                                                         |",
                    "|                                                         |",
                    "|       |||||||||||||              |||||||||||||          |",
                    "|       ||....*....||              ||....*....||          |",
                    "|       ||.........||              ||.........||          |",
                    "|       |||||  ||||||              |||||  ||||||          |",
                    "|                                                         |",
                    "|                                                         |",
                    "|       |||||||||||||              |||||||||||||          |",
                    "|       ||.....*...||              ||.....*...||          |",
                    "|       ||.........||              ||.........||          |",
                    "|       |||||  ||||||              |||||  ||||||          |",
                    "|                                                         |",
                    "|                                                         |",
                    "|       |||||||||||||              |||||||||||||          |",
                    "|       ||.....*...||              ||.....*...||          |",
                    "|       ||.........||              ||.........||          |",
                    "|       |||||  ||||||              |||||  ||||||          |",
                    "|                                                         |",
                    "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||",
                };
                cout<<endl;

                cout << "\tPress 'l' to move right: "<<endl;
                cout << "\tPress 'j' to move left: "<<endl;
                cout << "\tPress 'i' to move up: "<<endl;
                cout << "\tPress 'k' to move down: "<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"\tcondition:"<<endl;
                cout <<"\twin: "<<endl;
                cout <<"\t1.coin>=200"<<endl;
                cout <<"\t2.special coin=8"<<endl;
                while (!finish)
                {
                    make(place);
                    playermove();
                    enemymove();
                    draw_place(place);
                    std::this_thread::sleep_for(std::chrono::milliseconds(150));
                }
                result();
            }
        }



        else if(ch=='H')
        {
            cout<<endl;
            cout <<"Press 's' to start: ";

            char start;
            cin >> start;
            system("cls");
            if (start == 's')
            {
                char place[h][w] =
                {
                    "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||",
                    "|                                                         |",
                    "|       |||||||||||||              |||||||||||||          |",
                    "|       ||....*....||              ||....*....||          |",
                    "|       ||.........||              ||.........||          |",
                    "|       |||||| ||||||              |||||| ||||||          |",
                    "|                                                         |",
                    "|                                                         |",
                    "|       |||||||||||||              |||||||||||||          |",
                    "|       ||....*....||              ||....*....||          |",
                    "|       ||.........||              ||.........||          |",
                    "|       |||||| ||||||              |||||| ||||||          |",
                    "|                                                         |",
                    "|                                                         |",
                    "|       |||||||||||||              |||||||||||||          |",
                    "|       ||.....*...||              ||.....*...||          |",
                    "|       ||.........||              ||.........||          |",
                    "|       |||||| ||||||              |||||| ||||||          |",
                    "|                                                         |",
                    "|                                                         |",
                    "|       |||||||||||||              |||||||||||||          |",
                    "|       ||.....*...||              ||.....*...||          |",
                    "|       ||.........||              ||.........||          |",
                    "|       |||||| ||||||              |||||| ||||||          |",
                    "|                                                         |",
                    "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||",
                };
                cout<<endl;

                cout << "\tPress 'l' to move right: "<<endl;
                cout << "\tPress 'j' to move left: "<<endl;
                cout << "\tPress 'i' to move up: "<<endl;
                cout << "\tPress 'k' to move down: "<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"\tcondition:"<<endl;
                cout <<"\twin: "<<endl;
                cout <<"\t1.coin>=200"<<endl;
                cout <<"\t2.special coin=8"<<endl;
                while (!finish)
                {
                    make(place);
                    playermove();
                    enemymove();
                    draw_place(place);
                    std::this_thread::sleep_for(std::chrono::milliseconds(50));
                }
                result();
            }
        }
        while(1)
        {
            cout<<endl;
            cout << "\tPress 'E' to EXIT:";
            char ch;
            cin>>ch;
            if(ch=='E')break;
        }
        cout<<endl;
        cout << "\tPress 'A' to play again:"<<endl;
        cout << "\tPress 'E' to end:"<<endl;
        cout<< "\tPress:";
        char c;
        cin>>c;
        if(c=='A')continue;
        else if(c=='E')break;
    }
    return 0;
}
//sndPlaySound("pacdies.wav",SND_ASYNC);

