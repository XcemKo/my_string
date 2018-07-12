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
\brief ����� ������������ ������
\author AnikinVA
\version 1.3
\date ������ 2017
*/
class Str {
private:
	unsigned char *source;	/// ��������� �� ������ ��������
	int size;				/// ������ �������
public:
	/// ����������� �� ��������� �� ������ ��������
	Str(char* str);
	/// ����������� �� �������
	Str(char str);
	/// ����������� �����������
	Str(const Str&);
	/// ����������� �� ���������
	Str();
	///����������
	~Str();

	/// �������� �������� ���������
	friend bool operator==(const Str&, const Str&);
	/// �������� ������������ �� ������ �� ������
	Str& operator=(const Str&);
	/// �������� ������������ �� ��������� �� ������ ��������
	Str& operator=(const char*);
	/// �������� �������� ���� ����������� ������
	friend Str operator+(const Str&, const Str&);
	/// �������� �������� ���������� ������ � �������
	friend Str operator+(const Str&, char);
	/// ����������� �������� �������� ���� ����������� ������
	Str& operator+=(const Str&);
	/// ����������� �������� �������� ���������� ������ � �������
	Str& operator+=(const char);

	/// �������� ���������

	friend bool operator!=(const Str&, const Str&);
	friend bool operator>(const Str&, const Str&);
	friend bool operator>=(const Str&, const Str&);
	friend bool operator<(const Str&, const Str&);
	friend bool operator<=(const Str&, const Str&);

	/// ������ �� �������

	const char& operator[](int) const;
	unsigned char& operator[](int);
	/*! ������� �������� ������� ������
	* \return ������ ������
	*/
	int getSize();
	//! ������� �������� ��������� �� ������
	char *getStr();
	/// ������� ������� ������
	void clear();
};


#endif /* STR_STR_H_ */
