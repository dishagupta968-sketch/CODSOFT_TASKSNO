#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Structure to store movie information
struct Movie
{
    string name;
    string genre;
    double rating;
};

// Convert string to lowercase
string toLowerCase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Display all available movies
void displayMovies(const vector<Movie>& movies)
{
    cout << "\n========== AVAILABLE MOVIES ==========\n";

    for (int i = 0; i < movies.size(); i++)
    {
        cout << i + 1 << ". "
             << movies[i].name
             << " | Genre: " << movies[i].genre
             << " | Rating: " << movies[i].rating
             << "/10\n";
    }
}

// Recommend movies according to genre
void recommendMovies(const vector<Movie>& movies, string preference)
{
    bool found = false;

    preference = toLowerCase(preference);

    cout << "\n========== RECOMMENDATIONS ==========\n";

    for (const Movie& movie : movies)
    {
        if (toLowerCase(movie.genre) == preference)
        {
            cout << "\nMovie  : " << movie.name;
            cout << "\nGenre  : " << movie.genre;
            cout << "\nRating : " << movie.rating << "/10\n";

            found = true;
        }
    }

    if (!found)
    {
        cout << "\nSorry! No movies found for this genre.\n";
    }
}

// Main function
int main()
{
    // Movie database
    vector<Movie> movies =
    {
        {"Inception", "Sci-Fi", 8.8},
        {"Interstellar", "Sci-Fi", 8.7},
        {"The Matrix", "Sci-Fi", 8.7},

        {"Avengers", "Action", 8.0},
        {"John Wick", "Action", 7.5},
        {"Mission Impossible", "Action", 7.7},

        {"Titanic", "Romance", 7.9},
        {"The Notebook", "Romance", 7.8},
        {"La La Land", "Romance", 8.0},

        {"The Conjuring", "Horror", 7.5},
        {"It", "Horror", 7.3},
        {"Insidious", "Horror", 6.8},

        {"3 Idiots", "Comedy", 8.4},
        {"Hera Pheri", "Comedy", 8.1},
        {"Welcome", "Comedy", 7.1}
    };

    int choice;
    string preference;

    cout << "========================================\n";
    cout << "       MOVIE RECOMMENDATION SYSTEM\n";
    cout << "========================================\n";

    while (true)
    {
        cout << "\n----------- MENU -----------\n";
        cout << "1. View All Movies\n";
        cout << "2. Get Recommendations\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            displayMovies(movies);
        }

        else if (choice == 2)
        {
            cout << "\nAvailable Genres:\n";
            cout << "1. Sci-Fi\n";
            cout << "2. Action\n";
            cout << "3. Romance\n";
            cout << "4. Horror\n";
            cout << "5. Comedy\n";

            cout << "\nEnter your preferred genre: ";
            getline(cin, preference);

            recommendMovies(movies, preference);
        }

        else if (choice == 3)
        {
            cout << "\nThank you for using Movie Recommendation System!\n";
            break;
        }

        else
        {
            cout << "\nInvalid choice! Please try again.\n";
        }
    }

    return 0;
}