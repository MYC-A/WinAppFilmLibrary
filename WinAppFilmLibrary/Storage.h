#pragma once
#include "Movie.h"
#include "Movies.h"
ref class Storage {
public:
	static void save_Id(int id); //���������� �������� ���������� ��������������;
	static void load_Id(Movies^ movies); // �������� �������� ��������������

	static void save_Movie(Movie^ movie); //�������� � ���� ������

	static void save_AllMovie(Movies^ movies); //���������� ������ �������
	static void load_Movie(Movies^ movies); //�������� ������� �� ����� 

	List<Movie^>^ find_UnRelease_Movie(); // ����� �� �������� �������
	Storage() {
	}

};
