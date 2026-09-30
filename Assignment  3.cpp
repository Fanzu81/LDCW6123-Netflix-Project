#include <iostream>
using namespace std;

int main () {

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

    return 0;
}