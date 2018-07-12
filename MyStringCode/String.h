/*
* str.h
*
*  Created on: 11 01 2017 
*      Author: Xcem
*/

#ifndef STR_STR_H_
#define STR_STR_H_
#include "stdio.h"
/*!
\brief Класс динамической строки
\author AnikinVA
\version 1.3
\date январь 2017
*/
class Str {
private:
	unsigned char *source;	/// Указатель на массив символом
	int size;				/// Размер массива
public:
	/// Конструктор от указателя на массив символов
	Str(char* str);
	/// Коснтруктор от символа
	Str(char str);
	/// Конструктор копирования
	Str(const Str&);
	/// Конструктор по умолчанию
	Str();
	///Деструктор
	~Str();

	/// Условный оператор сравнения
	friend bool operator==(const Str&, const Str&);
	/// Оператор присваивания от такого же класса
	Str& operator=(const Str&);
	/// оператор присваивания от указателя на массив символов
	Str& operator=(const char*);
	/// Оператор сложения двух экземплятор класса
	friend Str operator+(const Str&, const Str&);
	/// Оператор сложения экземпляра класса и символа
	friend Str operator+(const Str&, char);
	/// Сокрашенный опреатор сложения двух Экземпляров класса
	Str& operator+=(const Str&);
	/// Сокрашенный опреатор сложения экземпляра класса и символа
	Str& operator+=(const char);

	/// Условные операторы

	friend bool operator!=(const Str&, const Str&);
	friend bool operator>(const Str&, const Str&);
	friend bool operator>=(const Str&, const Str&);
	friend bool operator<(const Str&, const Str&);
	friend bool operator<=(const Str&, const Str&);

	/// Взятие по индексу

	const char& operator[](int) const;
	unsigned char& operator[](int);
	/*! Функция передачи размера строки
	* \return Размер строки
	*/
	int getSize();
	//! Функция передачи указателя на строку
	char *getStr();
	/// Функция очистки строки
	void clear();
};


#endif /* STR_STR_H_ */
