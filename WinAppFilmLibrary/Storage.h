#pragma once
#include "Movie.h"
ref class Storage {
public:
	List<Movie^>^ movieList;
	int Current_Id;// Уникальный идентификатор

	void save_Id(); //сохранение текущего свободного идентификатора;
	void load_Id(); // Загрузка текущего идентификатора

	void save_Movie(Movie^ movie); //Дозапись в базу данных

	void save_AllMovie(); //сохранение списка фильмов
	void load_Movie(); //загрузка фильмов из файла 
	List<Movie^>^ find_Movie(String^ Title, DateTime Data, String^ Genre);//Поиск фильма по названию, дате и жанру
	List<Movie^>^ find_UnRelease_Movie(); // Поиск не вышедших фильмов
	Storage() {
		movieList = gcnew List<Movie^>();
		Current_Id = 0;
	}

};
