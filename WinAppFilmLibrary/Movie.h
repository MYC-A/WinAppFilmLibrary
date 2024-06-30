#pragma once
#include <string>
#include <array>
using namespace System::Collections::Generic;
using namespace System;

ref class Movie
{
public:
    property int Id; // Уникальный идентификатор фильма
    property String^ Title; // Название фильма
    property String^ Poster; // Ссылка на постер в локальной базе данных
    property DateTime Data; // Выход в прокат
    property array<String^>^ Genre; // Жанр фильма
    property double Rating;// Рейтинг фильма
    property String^ Annotation;// Аннотация к фильму
    property bool Release; 
   


    Movie(int Id, String^ Poster, String^ Title, DateTime Data, array<String^>^ Genre, double Rating, String^ Annotation);
    Movie() {

    }

};
