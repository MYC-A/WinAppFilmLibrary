#include "Storage.h"
#include <iostream>
#include "Movies.h"
using namespace System::IO;

void Storage::save_Id(int id)
{
    StreamWriter^ sw1 = gcnew StreamWriter("C:\\Movie_Library\\DB\\Ind.txt", false);
    sw1->WriteLineAsync(id.ToString());
    sw1->Close();

}

void Storage::load_Id(Movies^ movies)
{
    array<String^>^ lines = File::ReadAllLines("C:\\Movie_Library\\DB\\Ind.txt");
    movies->SetCurrent_Id(Int32::Parse(lines[0]));
    
}

void Storage::save_Movie(Movie^ newMovie)
{
    StreamWriter^ sw = gcnew StreamWriter("C:\\Movie_Library\\DB\\MovieDB.txt", true);
    sw->WriteLine("{0}|{1}|{2}|{3}|{4}|{5}|{6}|{7}", newMovie->Id, newMovie->Poster, newMovie->Title, newMovie->Data.ToString(), String::Join(", ", newMovie->Genre), newMovie->Rating, newMovie->Annotation, newMovie->Release);
    sw->Close();

}


void Storage::save_AllMovie(Movies^movies)
{
    StreamWriter^ sw = gcnew StreamWriter("C:\\Movie_Library\\DB\\MovieDB.txt", false);
    for each (Movie ^ movie in movies->getmovieList())
    {
        sw->WriteLine("{0}|{1}|{2}|{3}|{4}|{5}|{6}|{7}", movie->Id, movie->Poster, movie->Title, movie->Data.ToShortDateString(), String::Join(", ", movie->Genre), movie->Rating, movie->Annotation, movie->Release);

    }
    sw->Close();

}

void Storage::load_Movie(Movies^ movies)
{
    StreamReader^ sr = gcnew StreamReader("C:\\Movie_Library\\DB\\MovieDB.txt");
    String^ line;

    while ((line = sr->ReadLine()) != nullptr) {
        //if (line == "") {
        	//break;
        //}
        array<String^>^ data = line->Split('|');
        Movie^ movie = gcnew Movie(Convert::ToInt32(data[0]), data[1], data[2], Convert::ToDateTime(data[3]), data[4]->Split(','), Convert::ToDouble(data[5]), data[6]);
        movies->addMovie(movie);

        //this->movieList->Add(movie);
        
        //line = sr->ReadLine();
    }
    sr->Close();
    
    return;
}


List<Movie^>^ Storage::find_UnRelease_Movie()
{
    throw gcnew System::NotImplementedException();
    // TODO: вставьте здесь оператор return
}
