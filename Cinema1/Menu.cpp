#include "Menu.h"
#include <iomanip>
#include <cctype>

// Display seats
void displaySeats(vector<vector<char>>& seats)
{
    cout << "\n========== SCREEN SEATS ==========\n\n";

    cout << "      ";
    for (int i = 1; i <= 8; i++)
    {
        cout << " " << i << "  ";
    }

    cout << "\n";

    for (int row = 0; row < seats.size(); row++)
    {
        char rowLetter = 'A' + row;

        cout << " " << rowLetter << "   ";

        for (int col = 0; col < seats[row].size(); col++)
        {
            cout << "[" << seats[row][col] << "]";
        }

        cout << "\n";
    }

    cout << "\n[O] = Available   [X] = Taken\n";
}
// Book seats
void bookSeat(vector<vector<char>>& seats)
{
    string seatChoice;

    while (true)
    {
        displaySeats(seats);

        cout << "\nEnter seat number (Example: C5) or 0 to go back: ";
        cin >> seatChoice;

        if (seatChoice == "0")
        {
            break;
        }

        if (seatChoice.length() < 2)
        {
            cout << "Invalid format!\n";
            continue;
        }

        char rowLetter = toupper(seatChoice[0]);
        int row = rowLetter - 'A';

        int col = stoi(seatChoice.substr(1)) - 1;

        if (row < 0 || row >= seats.size() ||
            col < 0 || col >= seats[0].size())
        {
            cout << "Seat does not exist!\n";
            continue;
        }

        if (seats[row][col] == 'X')
        {
            cout << "Seat already taken!\n";
        }
        else
        {
            seats[row][col] = 'X';
            cout << "Seat booked successfully!\n";
        }
    }
}

// Movie menu
void movieMenu()
{
    vector<string> movies =
    {
        "Avengers: Endgame",
        "Spider-Man: No Way Home",
        "Interstellar"
    };

    int choice;

    while (true)
    {
        cout << "\n========== BUY TICKETS ==========\n";
        cout << "1. " << movies[0] << endl;
        cout << "2. " << movies[1] << endl;
        cout << "3. " << movies[2] << endl;
        cout << "4. Back\n";

        cout << "\nChoose a movie: ";
        cin >> choice;

        if (choice == 4)
        {
            break;
        }

        if (choice < 1 || choice > 3)
        {
            cout << "Invalid choice!\n";
            continue;
        }

        cout << "\nNow Showing: " << movies[choice - 1] << endl;

        // Create seats
        vector<vector<char>> seats(5, vector<char>(8, 'O'));

        // Example taken seats
        seats[0][2] = 'X';
        seats[2][4] = 'X';

        bookSeat(seats);
    }
}

// Help menu
void helpMenu()
{
    cout << "\n========== HELP ==========\n";
    cout << "1. Choose Buy Tickets\n";
    cout << "2. Select a movie\n";
    cout << "3. Enter seat like B4\n";
    cout << "4. X means taken\n";
    cout << "5. O means available\n";
}

// Main menu
void mainMenu()
{
    int choice;

    do
    {
        cout << "\n=================================\n";
        cout << "          WATCH ZONE\n";
        cout << "=================================\n";

        cout << "1. Buy Tickets\n";
        cout << "2. Help\n";
        cout << "3. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            movieMenu();
            break;

        case 2:
            helpMenu();
            break;

        case 3:
            cout << "\nGoodbye!\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 3);
}