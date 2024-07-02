#include "Storage.h"
#include <iostream>
using namespace System::IO;
void Storage::save_Id()
{
    StreamWriter^ sw1 = gcnew StreamWriter("C:\\Movie_Library\\DB\\Ind.txt", false);
    sw1->WriteLineAsync(this->Current_Id.ToString());
    sw1->Close();

    return;
}

void Storage::load_Id()
{
    array<String^>^ lines = File::ReadAllLines("C:\\Movie_Library\\DB\\Ind.txt");
    Current_Id = Int32::Parse(lines[0]);
    
    return;
}

void Storage::save_Movie(Movie^ newMovie)
{
    StreamWriter^ sw = gcnew StreamWriter("C:\\Movie_Library\\DB\\MovieDB.txt", true);
    sw->WriteLine("{0}|{1}|{2}|{3}|{4}|{5}|{6}|{7}", newMovie->Id, newMovie->Poster, newMovie->Title, newMovie->Data.ToString(), String::Join(", ", newMovie->Genre), newMovie->Rating, newMovie->Annotation, newMovie->Release);
    sw->Close();

    return;
}


void Storage::save_AllMovie()
{
    throw gcnew System::NotImplementedException();
}

void Storage::load_Movie()
{
    StreamReader^ sr = gcnew StreamReader("C:\\Movie_Library\\DB\\MovieDB.txt");
    String^ line;

    while ((line = sr->ReadLine()) != nullptr) {
        Movie^ movie = gcnew Movie();
        if (line == "") {
        	break;
        }
        array<String^>^ data = line->Split('|');
        movie->Id = Convert::ToInt32(data[0]);
        movie->Poster = data[1];
        movie->Title = data[2];
        movie->Data = Convert::ToDateTime(data[3]);
        movie->Genre = data[4]->Split(',');
        movie->Rating = Convert::ToDouble(data[5]);
        movie->Annotation = data[6];
        movie->Release = Convert::ToBoolean(data[7]);
        this->movieList->Add(movie);
        //line = sr->ReadLine();
    }
    sr->Close();
    
    return;
}

List<Movie^>^ Storage::find_Movie(String^ Title, DateTime Data, double Rating_From, double Rating_to)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if ( (movieList[i]->Title == Title) && (movieList[i]->Data.ToShortDateString() == Data.ToShortDateString()) && (movieList[i]->Rating >= Rating_From && movieList[i]->Rating <= Rating_to) ) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

List<Movie^>^ Storage::find_Movie(String^ Title, DateTime Data)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if ((movieList[i]->Title == Title) && (movieList[i]->Data.ToShortDateString() == Data.ToShortDateString()) ) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

List<Movie^>^ Storage::find_Movie(String^ Title, double Rating_From, double Rating_to)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if ((movieList[i]->Title == Title) && (movieList[i]->Rating >= Rating_From && movieList[i]->Rating <= Rating_to)) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

List<Movie^>^ Storage::find_Movie(DateTime Data, double Rating_From, double Rating_to)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if ((movieList[i]->Data.ToShortDateString() == Data.ToShortDateString()) && (movieList[i]->Rating >= Rating_From && movieList[i]->Rating <= Rating_to)) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

List<Movie^>^ Storage::find_Movie(String^ Title)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if (movieList[i]->Title == Title) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

List<Movie^>^ Storage::find_Movie(DateTime Data)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if (movieList[i]->Data.ToShortDateString() == Data.ToShortDateString()) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

List<Movie^>^ Storage::find_Movie(double Rating_From, double Rating_to)
{
    List<Movie^>^ lm = gcnew List<Movie^>();
    for (int i = 0; i < movieList->Count; i++) {
        if ((movieList[i]->Rating >= Rating_From && movieList[i]->Rating <= Rating_to)) {
            lm->Add(movieList[i]);
        }
    }
    return lm;
}

Movie^ Storage::find_Movie_index(int index)
{
    for each (Movie ^ movie in movieList) {
        if (movie->Id == index) {
            return movie;
        }
        
    }
    return gcnew Movie();
}



List<Movie^>^ Storage::find_UnRelease_Movie()
{
    throw gcnew System::NotImplementedException();
    // TODO: вставьте здесь оператор return
}
