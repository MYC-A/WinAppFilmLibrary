#pragma once
#include "Movie.h"
ref class Storage {
public:
	List<Movie^>^ movieList;
	int Current_Id;// ���������� �������������

	void save_Id(); //���������� �������� ���������� ��������������;
	void load_Id(); // �������� �������� ��������������

	void save_Movie(Movie^ movie); //�������� � ���� ������

	void save_AllMovie(); //���������� ������ �������
	void load_Movie(); //�������� ������� �� ����� 
	List<Movie^>^ find_Movie(String^ Title, DateTime Data, String^ Genre);//����� ������ �� ��������, ���� � �����
	Movie^ find_Movie_index(int index);//����� ������ �� id
	List<Movie^>^ find_UnRelease_Movie(); // ����� �� �������� �������
	Storage() {
		movieList = gcnew List<Movie^>();
		Current_Id = 0;
	}

};
