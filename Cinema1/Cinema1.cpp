#include "Menu.h"

int main()
{
    InitWindow(screenWidth, screenHeight, "Watch Zone");

    SetTargetFPS(60);

    ScreenState currentScreen = MAIN_MENU;

    // Movies
    vector<Movie> movies =
    {
        {
            "Avengers: Endgame",
            "PG-13",
            "18:00",
            "21:00",
            5,
            "Kevin Feige",
            {
                "Robert Downey Jr.",
                "Chris Evans",
                "Scarlett Johansson"
            }
        },

        {
            "Spider-Man: No Way Home",
            "PG-13",
            "19:30",
            "22:00",
            4,
            "Kevin Feige",
            {
                "Tom Holland",
                "Zendaya",
                "Willem Dafoe"
            }
        },

        {
            "Interstellar",
            "PG-13",
            "20:00",
            "23:00",
            5,
            "Christopher Nolan",
            {
                "Matthew McConaughey",
                "Anne Hathaway",
                "Jessica Chastain"
            }
        }
    };

    int selectedMovie = -1;

    // Seats
    vector<vector<char>> seats(5, vector<char>(8, 'O'));

    // LOAD SAVED SEATS
    LoadSeats(seats);

    // Input
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