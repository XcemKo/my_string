/*
* main.cpp
*
*  Created on: 11 янв. 2017 г.
*      Author: Xcem
*       Написать класс динамических строк, который:

1. Имеет конструктор копирования(+), оператор присваивания(+) и "внешний" оператор сложения двух строк(+).
2. Поддерживает строки произвольного размера, используя операции работы с динамическим хипом(+).
3. Не использует в своей основе какую-либо другую реализацию динамических строк (std::string no-no!).(+++)

Написать пример с использованием этого класса строк и какого-либо контейнера STL.
Программа должна принимать список строк, затем выдавать его в порядке, обратном
лексикографическому без учета регистра.

Программа-пример работает из командной строки.
*/
#include <fstream>
#include <vector>
#include <cstdio>
#include "String.h"

#define PATH_FILE_SRC "c:/Users/Xcem/documents/visual studio 2017/Projects/MyString/Debug/src.txt"

using namespace std;

void testFile(FILE* fileTest);
vector<Str> parsFile(FILE* parsedFile);
void BubleSortVector(vector<Str> *input);
void quickSort(vector<Str> *mass, vector<Str>::iterator left, vector<Str>::iterator right);

int main(int argc, char* argv[]) {
	FILE *fd;
	vector<Str> vec_sr;
	errno_t err;
	err = fopen_s(&fd, argv[1], "r+");
	//err = fopen_s(&fd, PATH_FILE_SRC, "r+");
	testFile(fd);
	if (err == 0) {
		printf("open - %s\n", argv[1]);
		vec_sr = parsFile(fd);
		quickSort(&vec_sr, vec_sr.begin(), vec_sr.end());
		for (unsigned int i = 0;i<vec_sr.size();i++)
			printf("%s\n", vec_sr[i].getStr());
	}
	else
		printf("Не могу открыть файл %s",argv[1]);
	fclose(fd);
	system("pause");
	return 0;
}

void testFile(FILE* fileTest) {
	unsigned char test;
	//FIXME: В Widnows не берет последний элемент файла...
	fseek(fileTest, -1, SEEK_END);
	test = fgetc(fileTest);
	if (test != '\n')
	{
		fseek(fileTest, 0, SEEK_END);
		fputc('\n', fileTest);
	}
	fseek(fileTest, 0, SEEK_SET);
}
//FIXME: Можно убрать, сделал быструю сортировку
void BubleSortVector(vector<Str> *input) {
	vector<Str>::iterator iit;
	vector<Str>::iterator jit;
	for (iit = input->begin();iit != input->end();iit++)
		for (jit = input->begin();jit != input->end();jit++)
			if (*iit<*jit)
				swap(*iit, *jit);
}

void quickSort(vector<Str> *mass, vector<Str>::iterator left, vector<Str>::iterator right) {
	int size = 0;
	for (vector<Str>::iterator i = left;i<right;i++, size++);
	vector<Str>::iterator index_root = left;
	for (int i = 0;i<size / 2;i++)
		index_root++;
	Str root = *index_root;
	vector<Str>::iterator iIter = left;
	vector<Str>::iterator jIter = right - 1;
	while (iIter <= jIter) {
		while (*iIter < root)
			iIter++;
		while (*jIter > root)
			jIter--;
		if (iIter <= jIter)
		{
			swap(*iIter, *jIter);
			iIter++; jIter--;
		}
	}
	if (jIter != left)
		quickSort(mass, left, iIter);
	if (iIter<right - 1)
		quickSort(mass, jIter + 1, right);
}

vector<Str> parsFile(FILE* parsedFile) {
	vector<Str> result;
	char tmp;
	Str tmp_str;
	tmp = fgetc(parsedFile);
	do {
		if (tmp != '\n')
			tmp_str += tmp;
		else {
			if (tmp_str.getSize()>0) {
				result.push_back(tmp_str);
				tmp_str.clear();
			}
		}
		tmp = fgetc(parsedFile);
	} while (!feof(parsedFile));
	return result;
}

