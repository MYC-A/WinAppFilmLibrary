#include "Movies.h"

int Movies::getCount()
{
    return movieList->Count;;
}

int Movies::getCurrent_Id()
{
    return Current_Id;
}

void Movies::SetCurrent_Id(int id)
{
    this->Current_Id = id;
}

void Movies::addMovie(Movie^ movie)
{
    movieList->Add(movie);
}

void Movies::deleteMovie(Movie^ movie)
{
    movieList->Remove(movie);
}

void Movies::RemoveAt(int index)
{
    movieList->RemoveAt(index);
}

Movie^ Movies::getMovie(int index)
{
    return movieList[index];
    // TODO: вставьте здесь оператор return
}

List<Movie^>^ Movies::getmovieList()
{
    return movieList;
}

List<Movie^>^ Movies::find_Movie(String^ Title, DateTime Data, double Rating_From, double Rating_to)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if ((movieList[i]->Title == Title) && (movieList[i]->Data.ToShortDateString() == Data.ToShortDateString()) && (movieList[i]->Rating >= Rating_From && movieList[i]->Rating <= Rating_to)) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

List<Movie^>^ Movies::find_Movie(String^ Title, DateTime Data)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if ((movieList[i]->Title == Title) && (movieList[i]->Data.ToShortDateString() == Data.ToShortDateString())) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

List<Movie^>^ Movies::find_Movie(String^ Title, double Rating_From, double Rating_to)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if ((movieList[i]->Title == Title) && (movieList[i]->Rating >= Rating_From && movieList[i]->Rating <= Rating_to)) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

List<Movie^>^ Movies::find_Movie(DateTime Data, double Rating_From, double Rating_to)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if ((movieList[i]->Data.ToShortDateString() == Data.ToShortDateString()) && (movieList[i]->Rating >= Rating_From && movieList[i]->Rating <= Rating_to)) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

List<Movie^>^ Movies::find_Movie(String^ Title)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if (movieList[i]->Title == Title) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

List<Movie^>^ Movies::find_Movie(DateTime Data)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if (movieList[i]->Data.ToShortDateString() == Data.ToShortDateString()) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

List<Movie^>^ Movies::find_Movie(double Rating_From, double Rating_to)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if ((movieList[i]->Rating >= Rating_From && movieList[i]->Rating <= Rating_to)) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

Movie^ Movies::find_Movie_index(int index)
{
    for each (Movie ^ movie in movieList) {
        if (movie->Id == index) {
            return movie;
        }

    }
    return gcnew Movie();
}

List<Movie^>^ Movies::find_UnRelease_Movie()
{
    throw gcnew System::NotImplementedException();
    // TODO: вставьте здесь оператор return
}

