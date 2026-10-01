#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

struct Movie {
    string title;
    int year;
    string genre;
    string language;
    string ageRating;
    string synopsis;
};

// Helper function to compare strings case-insensitively
bool equalsIgnoreCase(const string& a, const string& b) {
    if (a.size() != b.size()) return false;
    return equal(a.begin(), a.end(), b.begin(), [](char ch1, char ch2) {
        return tolower(static_cast<unsigned char>(ch1)) == tolower(static_cast<unsigned char>(ch2));
    });
}

void displayMovie(const Movie& m) {
    cout << "\n----------------------------------------" << endl;
    cout << "Title     : " << m.title << endl;
    cout << "Year      : " << m.year << endl;
    cout << "Genre     : " << m.genre << endl;
    cout << "Language  : " << m.language << endl;
    cout << "Age Rating: " << m.ageRating << endl;
    cout << "Synopsis  : " << m.synopsis << endl;
    cout << "----------------------------------------" << endl;
}

// Functions to display unique options directly from the database
void showAvailableYears(const Movie movies[], int count) {
    set<int> years;
    for (int i = 0; i < count; i++) years.insert(movies[i].year);
    cout << "\nAvailable Years:\n";
    bool first = true;
    for (int y : years) {
        if (!first) cout << ", ";
        cout << y;
        first = false;
    }
    cout << "\n" << endl;
}

void showAvailableGenres(const Movie movies[], int count) {
    set<string> genres;
    for (int i = 0; i < count; i++) genres.insert(movies[i].genre);
    cout << "\nAvailable Genres:\n";
    bool first = true;  
    for (const auto& g : genres) {
        if (!first) cout << ", ";
        cout << g;
        first = false;
    }
    cout << "\n" << endl;
}

void showAvailableLanguages(const Movie movies[], int count) {
    set<string> languages;
    for (int i = 0; i < count; i++) languages.insert(movies[i].language);
    cout << "\nAvailable Languages:\n";
    bool first = true;
    for (const auto& l : languages) {
        if (!first) cout << ", ";
        cout << l;
        first = false;
    }
    cout << "\n" << endl;
}

void showAvailableAgeRatings(const Movie movies[], int count) {
    set<string> ratings;
    for (int i = 0; i < count; i++) ratings.insert(movies[i].ageRating);
    cout << "\nAvailable Age Ratings:\n";
    bool first = true;
    for (const auto& r : ratings) {
        if (!first) cout << ", ";
        cout << r;
        first = false;
    }
    cout << "\n" << endl;
}

int main() {
    const int movieCount = 8;
    Movie movies[movieCount] = {
        {"Munafik", 2016, "Horror", "Malay", "18", "A man questions his faith after a supernatural event forces him to confront his past."},
        {"Abang Long Fadil", 2014, "Comedy", "Malay", "13", "A small-time gangster tries to turn his life around after a chance encounter changes his outlook."},
        {"Titanic", 1997, "Romance", "English", "13", "Two passengers from different social classes fall in love aboard a doomed ocean liner."},
        {"The Dark Knight", 2008, "Action", "English", "16", "A vigilante crime-fighter faces a chaotic new threat that pushes his morals to the limit."},
        {"Vikram", 2022, "Action", "Tamil", "16", "A special task force investigates a series of murders linked to a masked vigilante."},
        {"Master", 2021, "Action", "Tamil", "16", "A troubled professor is sent to a juvenile school and clashes with a ruthless gang leader."},
        {"Crouching Tiger Hidden Dragon", 2000, "Adventure", "Chinese", "13", "A stolen sword sets off a journey of honor, love and martial arts mastery in ancient China."},
        {"Ne Zha", 2019, "Animation", "Chinese", "PG", "A mischievous young boy born with immense power must decide whether to embrace his destiny."}
    };

    int searchChoice = 0;

    do {
        cout << "\n=====================" << endl;
        cout << "       MOVIE HUB       " << endl;
        cout << "=======================" << endl;
        cout << "1. Movie Title" << endl;
        cout << "2. Release Year" << endl;
        cout << "3. Genre" << endl;
        cout << "4. Language" << endl;
        cout << "5. Age Rating" << endl;
        cout << "6. Exit Program" << endl;

        cout << "\nEnter your choice: ";
        if (!(cin >> searchChoice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        cin.ignore(10000, '\n');

        bool found = false;

        if (searchChoice == 1) {
            string query;
            cout << "Enter movie title: ";
            getline(cin, query);
            for (int i = 0; i < movieCount; i++) {
                if (equalsIgnoreCase(movies[i].title, query)) {
                    displayMovie(movies[i]);
                    found = true;
                }
            }
        }
        else if (searchChoice == 2) {
            int query;
            showAvailableYears(movies, movieCount); 
            cout << "Enter release year: ";
            if (cin >> query) {
                cin.ignore(10000, '\n'); // Clear remaining newline
                for (int i = 0; i < movieCount; i++) {
                    if (movies[i].year == query) {
                        displayMovie(movies[i]);
                        found = true;
                    }
                }
            } else {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid year input." << endl;
                continue;
            }
        }
        else if (searchChoice == 3) {
            string query;
            showAvailableGenres(movies, movieCount);
            cout << "Enter genre: ";
            getline(cin, query);
            for (int i = 0; i < movieCount; i++) {
                if (equalsIgnoreCase(movies[i].genre, query)) {
                    displayMovie(movies[i]);
                    found = true;
                }
            }
        }
        else if (searchChoice == 4) {
            string query;
            showAvailableLanguages(movies, movieCount);
            cout << "Enter language: ";
            getline(cin, query);
            for (int i = 0; i < movieCount; i++) {
                if (equalsIgnoreCase(movies[i].language, query)) {
                    displayMovie(movies[i]);
                    found = true;
                }
            }
        }
        else if (searchChoice == 5) {
            string query;
            showAvailableAgeRatings(movies, movieCount);
            cout << "Enter age rating: ";
            getline(cin, query);
            for (int i = 0; i < movieCount; i++) {
                if (equalsIgnoreCase(movies[i].ageRating, query)) {
                    displayMovie(movies[i]);
                    found = true;
                }
            }
        }
        else if (searchChoice == 6) {
            cout << "\nExiting application. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice. Please pick between 1 and 6." << endl;
        }

        if (!found && searchChoice >= 1 && searchChoice <= 5) {
            cout << "\nNo matching movie found." << endl;
        }

    } while (searchChoice != 6);

    return 0;
}
