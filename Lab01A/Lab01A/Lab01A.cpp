#include <iostream>
#include <string>

using namespace std;

struct MovieData {
	string title;
	string director;
	int yearReleased;
	int runningTime; // minutes
};

void printMovieInfo(MovieData movie, int order);

int main() {
	cout << "Default movies are stored here." << endl;
	MovieData movies[4];
	movies[0] = { "Titanic", "Bugs Bunny", 3016, 9999 };
	movies[1] = { "Hot Shots: Part Deux", "Lucifer", 1111, 20 };

	for (int i = 0;i < 2;i++) {
		printMovieInfo(movies[i], i+1);
	}

	// Taking user input for movies
	cout << endl << "Now it's your turn :) Add 2 movies to the list" << endl;
	for (int i = 2;i < 4;i++) {
		cout << "Title: ";
		//cin >> movies[i].title;
		getline(cin, movies[i].title);

		// Need to flush out/ignore spare \n chars that are being interpreted, only needs to happen right after a cin call, hence we can ignore it the first time
		if (i != 2) { cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }
		cout << "Director: ";
		//cin >> movies[i].director;
		getline(cin, movies[i].director);

		// We don't need to flush out any \n chars because getline auto does that, while cin only gets tokens?
		//if (i != 2) { cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }
		cout << "Year Released (a whole number): ";
		cin >> movies[i].yearReleased;
		cout << "Running Time (a whole number, minutes): ";
		cin >> movies[i].runningTime;
		cout << "Movie added to Database" << endl;
	}

	cout << endl << "Now for everything, correctly formatted." << endl << endl;

	for (int i = 0;i < 4;i++) {
		printMovieInfo(movies[i], i + 1);
	}

	cout << endl << "Have a nice day!" << endl;

	return 0;
}

void printMovieInfo(MovieData movie, int order) {
	cout << "Movie #" << order << ":" << endl << "\t";
	cout << "Title: " << movie.title << endl << "\t";
	cout << "Director: " << movie.director << endl << "\t";
	cout << "Year Released: " << movie.yearReleased << endl << "\t";
	cout << "Running Time (Minutes): " << movie.runningTime << endl;
}