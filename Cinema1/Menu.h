#include "raylib.h"
#include <vector>
#include <string>

using namespace std;

// Screen size
const int screenWidth = 1000;
const int screenHeight = 700;

// App states
enum ScreenState
{
    MAIN_MENU,
    MOVIE_SELECTION,
    SEAT_RESERVATION,
    HELP_SCREEN
};

// Functions
void DrawMainMenu(ScreenState& currentScreen);
void DrawHelpMenu(ScreenState& currentScreen);

void DrawMovieSelection(
    ScreenState& currentScreen,
    vector<string>& movies,
    int& selectedMovie
);

void DrawSeatReservation(
    ScreenState& currentScreen,
    vector<vector<char>>& seats,
    string& seatInput
);