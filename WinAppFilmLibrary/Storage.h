#pragma once
#include "Movie.h"
#include "Movies.h"
ref class Storage {
public:
	static void save_Id(int id); //сохранение текущего свободного идентификатора;
	static void load_Id(Movies^ movies); // Загрузка текущего идентификатора

	static void save_Movie(Movie^ movie); //Дозапись в базу данных

	static void save_AllMovie(Movies^ movies); //сохранение списка фильмов
	static void load_Movie(Movies^ movies); //загрузка фильмов из файла 

	List<Movie^>^ find_UnRelease_Movie(); // Поиск не вышедших фильмов
	Storage() {
	}

};
