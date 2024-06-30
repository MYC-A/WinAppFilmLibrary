#pragma once
#include <string>
#include <array>
using namespace System::Collections::Generic;
using namespace System;

ref class Movie
{
public:
    property int Id; // ���������� ������������� ������
    property String^ Title; // �������� ������
    property String^ Poster; // ������ �� ������ � ��������� ���� ������
    property DateTime Data; // ����� � ������
    property array<String^>^ Genre; // ���� ������
    property double Rating;// ������� ������
    property String^ Annotation;// ��������� � ������
    property bool Release; 
   


    Movie(int Id, String^ Poster, String^ Title, DateTime Data, array<String^>^ Genre, double Rating, String^ Annotation);
    Movie() {

    }

};
