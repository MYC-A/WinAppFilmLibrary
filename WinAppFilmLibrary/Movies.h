#pragma once
#include "Movie.h"
ref class Movies 
{
public:
	Movies() {
		movieList = gcnew List<Movie^>();
		Current_Id = 0;
	}

private:
	List<Movie^>^ movieList;
	int Current_Id;// Уникальный идентификатор
public:
	int getCount();
	int getCurrent_Id();

	int getIndex(int id);
	void SetCurrent_Id(int id);

	void addMovie(Movie^ movie);

	void deleteMovie(Movie^ movie);

	void RemoveAt(int index);

	void Edit(int index,String^ Poster, String^ Title, String^ Annotation, DateTime Data, array<String^>^ tmp_Genre, double tmp_Rating,bool Rating);

	Movie^ getMovie(int index);

	List<Movie^>^ getmovieList();
	List<Movie^>^ find_Movie(String^ Title, DateTime Data, double Rating_From, double Rating_to);//Поиск фильма по названию, дате и жанру

	List<Movie^>^ find_Movie(String^ Title, DateTime Data); //Перегрузка метода

	List<Movie^>^ find_Movie(String^ Title, double Rating_From, double Rating_to); //Перегрузка метода

	List<Movie^>^ find_Movie(DateTime Data, double Rating_From, double Rating_to); //Перегрузка метода

	List<Movie^>^ find_Movie(String^ Title); //Перегрузка метода

	List<Movie^>^ find_Movie(DateTime Data); //Перегрузка метода

	List<Movie^>^ find_Movie(double Rating_From, double Rating_to); //Перегрузка метода

	Movie^ find_Movie_id(int id);//Поиск фильма по id
	List<Movie^>^ find_UnRelease_Movie(); // Поиск не вышедших фильмов
};