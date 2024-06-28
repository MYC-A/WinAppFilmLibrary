#include "Movie.h"

Movie::Movie(int Id, String^ Poster, String^ Title, DateTime Data, array<String^>^ Genre, double Rating, String^ Annotation)
{
    this->Id = Id;
    this->Title = Title;
    this->Poster = Poster;
    this->Data = Data;
    this->Genre = Genre;
    this->Rating = Rating;
    this->Annotation = Annotation;
    this->Release = true;
    throw gcnew System::NotImplementedException();
}


