#include "Menu.h"
#include <fstream>
#include <cctype>

// =====================================================
// MAIN MENU
// =====================================================
void DrawMainMenu(ScreenState& currentScreen)
{
    DrawText("WATCH ZONE", 320, 80, 55, RED);

    Rectangle buyBtn = { 350, 220, 300, 60 };
    Rectangle helpBtn = { 350, 320, 300, 60 };
    Rectangle exitBtn = { 350, 420, 300, 60 };

    DrawRectangleRec(buyBtn, DARKGRAY);
    DrawRectangleRec(helpBtn, DARKGRAY);
    DrawRectangleRec(exitBtn, DARKGRAY);

    DrawText("Buy Tickets", 420, 240, 30, WHITE);
    DrawText("Help", 470, 340, 30, WHITE);
    DrawText("Exit", 480, 440, 30, WHITE);

    Vector2 mouse = GetMousePosition();

    if (CheckCollisionPointRec(mouse, buyBtn) &&
        IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        currentScreen = MOVIE_SELECTION;
    }

    if (CheckCollisionPointRec(mouse, helpBtn) &&
        IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        currentScreen = HELP_SCREEN;
    }

    if (CheckCollisionPointRec(mouse, exitBtn) &&
        IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        CloseWindow();
    }
}

// =====================================================
// HELP MENU
// =====================================================
void DrawHelpMenu(ScreenState& currentScreen)
{
    DrawText("HELP", 430, 80, 50, YELLOW);

    DrawText("1. Click Buy Tickets", 250, 200, 30, WHITE);
    DrawText("2. Select a movie", 250, 250, 30, WHITE);
    DrawText("3. Type seat like C5", 250, 300, 30, WHITE);
    DrawText("4. [X] = Taken", 250, 350, 30, WHITE);
    DrawText("5. [O] = Available", 250, 400, 30, WHITE);

    Rectangle backBtn = { 400, 550, 200, 50 };

    DrawRectangleRec(backBtn, DARKGRAY);
    DrawText("Back", 465, 565, 30, WHITE);

    if (CheckCollisionPointRec(GetMousePosition(), backBtn) &&
        IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        currentScreen = MAIN_MENU;
    }
}

// =====================================================
// MOVIE SELECTION
// =====================================================
void DrawMovieSelection(
    ScreenState& currentScreen,
    vector<Movie>& movies,
    int& selectedMovie
)
{
    DrawText("SELECT A MOVIE", 300, 40, 45, RED);

    for (int i = 0; i < movies.size(); i++)
    {
        Rectangle movieBtn = { 50, 120 + i * 100, 350, 70 };

        DrawRectangleRec(movieBtn,
            selectedMovie == i ? RED : DARKGRAY);

        DrawText(movies[i].title.c_str(),
            80,
            145 + i * 100,
            25,
            WHITE);

        if (CheckCollisionPointRec(GetMousePosition(), movieBtn) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            selectedMovie = i;
        }
    }

    // Movie Details
    if (selectedMovie != -1)
    {
        Movie& movie = movies[selectedMovie];

        DrawRectangle(470, 120, 450, 420, DARKGRAY);

        DrawText(movie.title.c_str(), 500, 140, 30, YELLOW);

        DrawText(
            ("Age Rating: " + movie.ageRating).c_str(),
            500,
            190,
            22,
            WHITE
        );

        DrawText(
            ("Starts: " + movie.startTime).c_str(),
            500,
            230,
            22,
            WHITE
        );

        DrawText(
            ("Ends: " + movie.endTime).c_str(),
            500,
            270,
            22,
            WHITE
        );

        string stars = "";

        for (int i = 0; i < movie.stars; i++)
        {
            stars += "* ";
        }

        DrawText(
            ("Rating: " + stars).c_str(),
            500,
            310,
            22,
            GOLD
        );

        DrawText(
            ("Producer: " + movie.producer).c_str(),
            500,
            350,
            22,
            WHITE
        );

        DrawText("Cast:", 500, 390, 24, SKYBLUE);

        for (int i = 0; i < movie.cast.size(); i++)
        {
            DrawText(
                movie.cast[i].c_str(),
                530,
                430 + i * 30,
                20,
                WHITE
            );
        }
    }

    // Reserve Button
    Rectangle reserveBtn = { 350, 600, 300, 60 };

    DrawRectangleRec(reserveBtn, DARKGREEN);

    DrawText("Reserve Seats", 390, 620, 30, WHITE);

    if (CheckCollisionPointRec(GetMousePosition(), reserveBtn) &&
        IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
        selectedMovie != -1)
    {
        currentScreen = SEAT_RESERVATION;
    }
}

// =====================================================
// SEAT RESERVATION
// =====================================================
void DrawSeatReservation(
    ScreenState& currentScreen,
    vector<vector<char>>& seats,
    string& seatInput
)
{
    DrawText("RESERVE YOUR SEAT", 250, 40, 45, RED);

    for (int row = 0; row < seats.size(); row++)
    {
        for (int col = 0; col < seats[row].size(); col++)
        {
            int x = 220 + col * 70;
            int y = 150 + row * 70;

            DrawRectangle(x, y, 50, 50, DARKGRAY);

            string seatText = "[";
            seatText += seats[row][col];
            seatText += "]";

            DrawText(
                seatText.c_str(),
                x + 5,
                y + 12,
                20,
                WHITE
            );

            string label = "";
            label += char('A' + row);
            label += to_string(col + 1);

            DrawText(
                label.c_str(),
                x + 5,
                y - 25,
                20,
                YELLOW
            );
        }
    }

    // Input box
    DrawText("Type Seat (Example C5):", 320, 550, 25, WHITE);

    DrawRectangle(350, 590, 250, 50, LIGHTGRAY);

    DrawText(seatInput.c_str(), 370, 605, 30, BLACK);

    // Keyboard input
    int key = GetCharPressed();

    while (key > 0)
    {
        if ((key >= 32) && (key <= 125) &&
            seatInput.length() < 3)
        {
            seatInput += (char)key;
        }

        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE) &&
        !seatInput.empty())
    {
        seatInput.pop_back();
    }

    // Reserve seat
    if (IsKeyPressed(KEY_ENTER))
    {
        if (seatInput.length() >= 2)
        {
            char rowLetter = toupper(seatInput[0]);

            int row = rowLetter - 'A';

            int col = stoi(seatInput.substr(1)) - 1;

            if (row >= 0 && row < seats.size() &&
                col >= 0 && col < seats[0].size())
            {
                seats[row][col] = 'X';

                // SAVE SEATS
                SaveSeats(seats);
            }
        }

        seatInput = "";
    }

    Rectangle backBtn = { 30, 620, 150, 50 };

    DrawRectangleRec(backBtn, DARKGRAY);

    DrawText("Back", 70, 635, 25, WHITE);

    if (CheckCollisionPointRec(GetMousePosition(), backBtn) &&
        IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        currentScreen = MOVIE_SELECTION;
    }
}

// =====================================================
// SAVE SEATS
// =====================================================
void SaveSeats(vector<vector<char>>& seats)
{
    ofstream file("seats.txt");

    for (int row = 0; row < seats.size(); row++)
    {
        for (int col = 0; col < seats[row].size(); col++)
        {
            file << seats[row][col];
        }

        file << endl;
    }

    file.close();
}

// =====================================================
// LOAD SEATS
// =====================================================
void LoadSeats(vector<vector<char>>& seats)
{
    ifstream file("seats.txt");

    if (!file.is_open())
    {
        return;
    }

    string line;

    int row = 0;

    while (getline(file, line) && row < seats.size())
    {
        for (int col = 0;
            col < line.length() &&
            col < seats[row].size();
            col++)
        {
            seats[row][col] = line[col];
        }

        row++;
    }

    file.close();
}