#include "Movies.h"

int Movies::getCount()
{
    return movieList->Count;;
}

int Movies::getCurrent_Id()
{
    return Current_Id;
}

int Movies::getIndex(int id)
{
    int index = -1;
    for each (Movie ^ movie in movieList) {
        index++;
        if (movie->Id == id) {
            return index;
        }

    }
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

void Movies::Edit(int index,String^ Poster, String^ Title, String^ Annotation, DateTime Data, array<String^>^ Genre, double Rating,bool Release)
{
    Movie^movie = find_Movie_id(index);
    
    movie->Poster = Poster;
    movie->Title = Title;
    movie->Annotation = Annotation;
    movie->Data = Data;
    movie->Genre = Genre;
    movie->Rating = Rating;
    movie->Release = Release;
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

List<Movie^>^ Movies::find_Movie(String^ Title, DateTime DataFrom, DateTime DataTo, double Rating_From, double Rating_to)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if ((movieList[i]->Title == Title) && (movieList[i]->Data.Date.CompareTo(DataFrom.Date) >= 0) && (movieList[i]->Data.Date.CompareTo(DataTo.Date) <= 0) && (movieList[i]->Rating >= Rating_From && movieList[i]->Rating <= Rating_to)) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

List<Movie^>^ Movies::find_Movie(String^ Title, DateTime DataFrom, DateTime DataTo)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if ( (movieList[i]->Title == Title) && (movieList[i]->Data.Date.CompareTo(DataFrom.Date) >= 0) && (movieList[i]->Data.Date.CompareTo(DataTo.Date) <= 0) ) {
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

List<Movie^>^ Movies::find_Movie(DateTime DataFrom, DateTime DataTo, double Rating_From, double Rating_to)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if ( (movieList[i]->Data.Date.CompareTo(DataFrom.Date) >= 0) && (movieList[i]->Data.Date.CompareTo(DataTo.Date) <= 0)
            && (movieList[i]->Rating >= Rating_From && movieList[i]->Rating <= Rating_to) ) {
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

List<Movie^>^ Movies::find_Movie(DateTime DataFrom, DateTime DataTo)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if ( (movieList[i]->Data.Date.CompareTo(DataFrom.Date) >= 0) && (movieList[i]->Data.Date.CompareTo(DataTo.Date) <= 0) ) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

List<Movie^>^ Movies::find_Movie(double Rating_From, double Rating_to)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {

        if ((movieList[i]->Rating.CompareTo(Rating_From) >= 0 && movieList[i]->Rating.CompareTo(Rating_to) <= 0)) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

Movie^ Movies::find_Movie_id(int index)
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
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {

        if (movieList[i]->Release == false)
        {
            lm->Add(movieList[i]);
        }
    }
    return lm;
    // TODO: вставьте здесь оператор return
}

