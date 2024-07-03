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
	int Current_Id;// ���������� �������������
public:
	int getCount();
	int getCurrent_Id();

	void SetCurrent_Id(int id);

	void addMovie(Movie^ movie);

	void deleteMovie(Movie^ movie);

	void RemoveAt(int index);

	Movie^ getMovie(int index);

	List<Movie^>^ getmovieList();
	List<Movie^>^ find_Movie(String^ Title, DateTime Data, double Rating_From, double Rating_to);//����� ������ �� ��������, ���� � �����

	List<Movie^>^ find_Movie(String^ Title, DateTime Data); //���������� ������

	List<Movie^>^ find_Movie(String^ Title, double Rating_From, double Rating_to); //���������� ������

	List<Movie^>^ find_Movie(DateTime Data, double Rating_From, double Rating_to); //���������� ������

	List<Movie^>^ find_Movie(String^ Title); //���������� ������

	List<Movie^>^ find_Movie(DateTime Data); //���������� ������

	List<Movie^>^ find_Movie(double Rating_From, double Rating_to); //���������� ������

	Movie^ find_Movie_index(int index);//����� ������ �� id
	List<Movie^>^ find_UnRelease_Movie(); // ����� �� �������� �������
};