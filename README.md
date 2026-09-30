**Recommendation Program For Netflix Movie**

This is a console based application designed as a solution for LDCW6123 Fundamentals of Digital Competence for Programmer, Group Assignment Part B. The program enables a user to search a mini movie database by title, year released, movie genre, language and age rating and is related to the innovation that our group chose which is Netflix.

**Features**

- Searching movie by:
    - Title of movie
    - Year released
    - Genre
    - Language
    - Age rating
- Shows the user the available options such as all genres in the database before searching
- Menu-driven loop where user can perform the searching several times without having to start the program again
- Option to exit the program
- Mini database consisting of 8 movies in four different languages (Malay, English, Tamil, Chinese)

## How to Compile and Run

**Compile:**
```
g++ Assignment_3.cpp -o Assignment_3.exe
```

**Run (Windows):**
```
.\Assignment_3.exe
```

**Run (Mac/Linux):**
```
g++ Assignment_3.cpp -o Assignment_3
./Assignment_3
```

## File Structure

```
├── Assignment_3.cpp   # Main program: movie database, search logic, menu loop
└── README.md          # This file
```

## How It Works

- Movie data is stored using a `Movie` structure (title, year, genre, language, age rating, synopsis)
- All movies are held in a fixed-size array
- Each menu option loops through the array and prints any matching movie(s) using `displayMovie()`
- A `do while` loop keeps the menu running until the user selects "Exit"

## Team

| Name | Role |
|---|---|
| [Irfan Zuhair bin Azman] | Group Leader / Part B – C++ Programming |
| [Swetha A/P Ramasamy] | Part B – C++ Programming |
| [Susnitha A/P Balamurungan] | Part B – C++ Programming |
| [Bachir Zakaria] | Part A – Poster & Research |
| [Amir Ziqry] | Part A – Poster & Research |
| [Izza Nelly binti Mohd Nasir] | Video Editor / Documentation |


## Assignment Info

- **Course:** LDCW6123 – Fundamentals of Digital Competence for Programmer
- **Component:** Part B – C++ Programming (linked to Netflix's Innovation Technology Life Cycle)

