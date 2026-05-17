#pragma once
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

// Movie structure
struct Movie
{
    string title;
    string ageRating;
    string startTime;
    string endTime;
    int stars;

    string producer;

    vector<string> cast;
};

// Functions
void DrawMainMenu(ScreenState& currentScreen);

void DrawHelpMenu(ScreenState& currentScreen);

void DrawMovieSelection(
    ScreenState& currentScreen,
    vector<Movie>& movies,
    int& selectedMovie
);

void DrawSeatReservation(
    ScreenState& currentScreen,
    vector<vector<char>>& seats,
    string& seatInput,
    bool& deleteMode
);

// Save & Load
void SaveSeats(vector<vector<char>>& seats);

void LoadSeats(vector<vector<char>>& seats);