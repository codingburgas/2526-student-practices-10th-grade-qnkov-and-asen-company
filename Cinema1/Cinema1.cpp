#include "Menu.h"

int main()
{
    InitWindow(screenWidth, screenHeight, "Watch Zone");

    SetTargetFPS(60);

    ScreenState currentScreen = MAIN_MENU;

    // Movies
    vector<string> movies =
    {
        "Avengers: Endgame",
        "Spider-Man: No Way Home",
        "Interstellar"
    };

    int selectedMovie = -1;

    // Seats
    vector<vector<char>> seats(5, vector<char>(8, 'O'));

    // Example taken seats
    seats[0][2] = 'X';
    seats[2][4] = 'X';

    // Seat input
    string seatInput = "";

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        switch (currentScreen)
        {
        case MAIN_MENU:
            DrawMainMenu(currentScreen);
            break;

        case MOVIE_SELECTION:
            DrawMovieSelection(
                currentScreen,
                movies,
                selectedMovie
            );
            break;

        case SEAT_RESERVATION:
            DrawSeatReservation(
                currentScreen,
                seats,
                seatInput
            );
            break;

        case HELP_SCREEN:
            DrawHelpMenu(currentScreen);
            break;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}