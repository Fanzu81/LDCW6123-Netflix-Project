#include <iostream>
#include <string>
using namespace std;

struct Movie {
    string title;
    int year;
    string genre;
    string language;
    string ageRating;
    string synopsis;
};

void displayMovie(const Movie& m) {
    cout << "\nTitle: " << m.title << endl;
    cout << "Year: " << m.year << endl;
    cout << "Genre: " << m.genre << endl;
    cout << "Language: " << m.language << endl;
    cout << "Age Rating: " << m.ageRating << endl;
    cout << "Synopsis: " << m.synopsis << endl;
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

    int searchChoice;

    cout << "===========================" << endl;
    cout << " MOVIE RECOMMENDATION SITE " << endl;
    cout << "===========================" << endl;

    cout << "\nWhat would like to search for?" << endl;
    cout << "1. Movie Title" << endl;
    cout << "2. Release Year" << endl;
    cout << "3. Genre" << endl;
    cout << "4. Language" << endl;
    cout << "5. Age Rating" << endl;

    cout << "\nEnter your choice: ";
    cin >> searchChoice;
    cin.ignore(); // clear leftover newline so getline works properly next

    bool found = false;

    if (searchChoice == 1) {
        string query;
        cout << "Enter movie title: ";
        getline(cin, query);
        for (int i = 0; i < movieCount; i++) {
            if (movies[i].title == query) {
                displayMovie(movies[i]);
                found = true;
            }
        }
    }
    else if (searchChoice == 2) {
        int query;
        cout << "Enter release year: ";
        cin >> query;
        for (int i = 0; i < movieCount; i++) {
            if (movies[i].year == query) {
                displayMovie(movies[i]);
                found = true;
            }
        }
    }
    else if (searchChoice == 3) {
        string query;
        cout << "Enter genre: ";
        getline(cin, query);
        for (int i = 0; i < movieCount; i++) {
            if (movies[i].genre == query) {
                displayMovie(movies[i]);
                found = true;
            }
        }
    }
    else if (searchChoice == 4) {
        string query;
        cout << "Enter language: ";
        getline(cin, query);
        for (int i = 0; i < movieCount; i++) {
            if (movies[i].language == query) {
                displayMovie(movies[i]);
                found = true;
            }
        }
    }
    else if (searchChoice == 5) {
        string query;
        cout << "Enter age rating: ";
        getline(cin, query);
        for (int i = 0; i < movieCount; i++) {
            if (movies[i].ageRating == query) {
                displayMovie(movies[i]);
                found = true;
            }
        }
    }
    else {
        cout << "Invalid choice." << endl;
    }

    if (!found && searchChoice >= 1 && searchChoice <= 5) {
        cout << "\nNo matching movie found." << endl;
    }

    return 0;
}