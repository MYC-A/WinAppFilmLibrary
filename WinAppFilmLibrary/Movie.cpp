#include "Movie.h"

Movie::Movie(int Id, String^ Poster, String^ Title, DateTime Data, array<String^>^ Genre, double Rating, String^ Annotation)
{
    this->Id = Id;
    this->Title = Title;
    this->Poster = Poster;
    this->Data = Data;

    String^ genres = String::Join(",", Genre);
    genres = genres->Replace(" ", ""); // ������� ��� �������
    genres = genres->TrimEnd(','); // ������� ��������� �������, ���� ����

    this->Genre = genres->Split(',');

    this->Rating = Rating;
    this->Annotation = Annotation;

    this->Release = (this->Data.Date <= DateTime::Now.Date);
    return;
}


