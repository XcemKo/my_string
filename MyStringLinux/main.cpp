/*
 * main.cpp
 *
 *  Created on: 11 ���. 2017 �.
 *      Author: Xcem
 *       �������� ����� ������������ �����, �������:

		1. ����� ����������� �����������(+), �������� ������������(+) � "�������" �������� �������� ���� �����(+).
		2. ������������ ������ ������������� �������, ��������� �������� ������ � ������������ �����(+).
		3. �� ���������� � ����� ������ �����-���� ������ ���������� ������������ ����� (std::string no-no!).(+++)

		�������� ������ � �������������� ����� ������ ����� � ������-���� ���������� STL.
		��������� ������ ��������� ������ �����, ����� �������� ��� � �������, ��������
		������������������� ��� ����� ��������.

		���������-������ �������� �� ��������� ������.
 */
#include <fstream>
#include <cstdlib>
#include <vector>
#include "stdio.h"
//-----------MyIncludes
#include "./Str/str.h"

//#define PATH_FILE_SRC "/home/vadik/workspace/MyString/Debug/src.txt"
#define PATH_FILE_SRC "C:/Users/Xcem/workspace2/MyString/Debug/src.txt"

using namespace std;

//! �������� ����� �� ���������� ���������� ������ ���������
void testFile(FILE* fileTest);
//! ������ ����� � ������������ �������
vector<Str> parsFile(FILE* parsedFile);
//! ��������� ���������
void BubleSortVector(vector<Str> *input);
//! TODO: ����������� ������� ���������� ��� �����������
void quickSort(vector<Str> *mass,vector<Str>::iterator left,vector<Str>::iterator right);

int main(int argc, char* argv[]){
	FILE *fd;
	vector<Str> vec_sr;
	fd = fopen(argv[1],"r+");
	printf("open - %s\n",argv[1]);
	testFile(fd);
	if(fd!=NULL){
		vec_sr=parsFile(fd);
		quickSort(&vec_sr,vec_sr.begin(),vec_sr.end());
		for(unsigned int i=0;i<vec_sr.size();i++)
			printf("%s\n",vec_sr[i].getStr());
	}else
		printf("�� ���� ������� ���� %s",argv[1]);
	fclose(fd);
	return 0;
}

void testFile(FILE* fileTest){
	fseek(fileTest,-1,SEEK_END);
	if(fgetc(fileTest)!='\n')
	{
		fseek(fileTest,0,SEEK_END);
		fputc('\n',fileTest);
	}
	fseek(fileTest,0,SEEK_SET);
}

void BubleSortVector(vector<Str> *input){
	vector<Str>::iterator iit;
	vector<Str>::iterator jit;
	for(iit=input->begin();iit!=input->end();iit++)
		for(jit=input->begin();jit!=input->end();jit++)
			if(*iit<*jit)
				swap(*iit,*jit);
}

void quickSort(vector<Str> *mass,vector<Str>::iterator left,vector<Str>::iterator right){
	int size=0;
	for(vector<Str>::iterator i=left;i<right;i++,size++);
	vector<Str>::iterator index_root = left;
	for(int i=0;i<size/2;i++)
		index_root++;
	Str root=*index_root;
	vector<Str>::iterator iIter=left;
	vector<Str>::iterator jIter=right-1;
	while(iIter<=jIter){
		while(*iIter < root)
			iIter++;
		while(*jIter > root)
			jIter--;
		if(iIter<=jIter)
		{
			swap(*iIter,*jIter);
			iIter++; jIter--;
		}
	}
	if(jIter!=left)
		quickSort(mass,left,iIter);
	if(iIter<right-1)
		quickSort(mass,jIter+1,right);
}

vector<Str> parsFile(FILE* parsedFile){
	vector<Str> result;
	char tmp;
	Str tmp_str;
	tmp=fgetc(parsedFile);
	do{
		if(tmp!='\n')
			tmp_str+=tmp;
		else{
			if(tmp_str.getSize()>0){
				result.push_back(tmp_str);
				tmp_str.clear();
			}
		}
		tmp=fgetc(parsedFile);
	}while(!feof(parsedFile));
	return result;
}

