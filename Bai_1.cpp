#include <iostream>
#include <string>

using namespace std;


struct MovieData {
    string title;         
    string director;      
    int releaseYear;     
    int runningTime;     
};


void displayMovieData(const MovieData& movie) {
    cout << "Ten phim: " << movie.title << endl;
    cout << "Dao dien: " << movie.director << endl;
    cout << "Nam phat hanh: " << movie.releaseYear << endl;
    cout << "Thoi luong: " << movie.runningTime << " phut" << endl;
}

int main() {
    
    MovieData movie1 = {"Ha Lan", "Nguyen Van A", 2010, 148};
    MovieData movie2 = {"Xi Trum", "The Lu", 1999, 136};

    
    cout << "Thong tin phim 1:\n";
    displayMovieData(movie1);

    cout << "\nThong tin phim 2:\n";
    displayMovieData(movie2);

    return 0;
}


