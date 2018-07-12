/*
 * str.cpp
 *
 *  Created on: 11 пїЅпїЅпїЅ. 2017 пїЅ.
 *      Author: Xcem
 */

#include "./str.h"
// Алфавит
//A - 065 : Z - 090
//a - 097 : z - 122
//0 - 048 : 9 - 057

//! Макрос приведения символа к нинему регистру (only ANSI)
#define LOWER_CASE_ANSI(src) (((src>=65 and src<=90) or (src>=192 and src<=223))?src+32:src)

bool operator==(const Str& left, const Str& right)
{
	int i = 0;
	if(left.size!=right.size)
		return false;
	for (; left.source[i] == right.source[i] && i < left.size; i++);
	return (i == left.size) ? true : false;
}

bool operator!=(const Str& left, const Str& right){
	return !(left==right);
}

const unsigned char& Str::operator[](int i) const
{
    return (i >= 0 && i < this->size) ? this->source[i] : 0;
}

unsigned char& Str::operator[](int i)
{
    static unsigned char DUMMY;
    return (i >= 0 && i < this->size) ? this->source[i] : DUMMY;
}

bool operator>(const Str& left, const Str& right){
	bool result=false;

	if(left!=right){
		int min_size=left.size>right.size ? right.size:left.size;
		for(int i=0;i<min_size+1;i++){
			unsigned char tmp_l=LOWER_CASE_ANSI(left.source[i]);
			unsigned char tmp_r=LOWER_CASE_ANSI(right.source[i]);
			if(tmp_l<tmp_r)
			{
				result=true;
				break;
			}else if(tmp_l>tmp_r){
				result=false;
				break;
			}
		}
	}
	return result;
}

bool operator<(const Str& left, const Str& right){
	bool result=false;
	if(left!=right)
		result=!(left>right);
	return result;
}

bool operator>=(const Str& left, const Str& right){
	bool result=true;
	if(left!=right)
		result=(left>right);
	return result;
}

bool operator<=(const Str& left, const Str& right){
	bool result=true;
	if(left!=right)
		result=(left<right);
	return result;
}

Str& Str::operator+=(const Str& right)
{
    int sz = this->size + right.size;
    unsigned char* ts = new unsigned char[sz+1];

    for (int i = 0; i < this->size; i++)
        ts[i] = this->source[i];
    for (int ii = this->size, j = 0; ii <= sz; ii++, j++)
        ts[ii] = right.source[j];

    this->size+=right.size;
    delete [] this->source;
    this->source = ts;

    return *this;
}

Str& Str::operator+=(const char right)
{
    int sz = this->size + 1;
    unsigned char* ts = new unsigned char[sz+1];

    for (int i = 0; i < this->size; i++)
        ts[i] = this->source[i];
    ts[this->size] = right;

    this->size+=1;
    if(this->source!=NULL)
    	delete [] this->source;
    this->source = ts;
    this->source[size]='\0';
    return *this;
}


Str& Str::operator=(const char* right){
	delete [] this->source;
	size = 0;
	for(;right[size] != 0;size++);
	this->source = new unsigned char[size+1];
	for(int i=0;i<size;i++)
		this->source[i]=right[i];
	this->source[size]='\0';
	return *this;
}

Str& Str::operator=(const Str& right){
	if (this != &right)
	{
		delete [] this->source;
		this->source = new unsigned char[right.size+1];
		for(int i=0;i<right.size;i++)
			this->source[i]=right.source[i];
	}
	this->source[right.size]='\0';
	this->size=right.size;
	return *this;
}

Str operator+(const Str& left, const Str& right){
	Str tmp=left;
	tmp+=right;
	return tmp;
}

Str operator+(char left, const Str& right){
	Str tmp(left);
	return (left+tmp);
}

Str operator+(const Str& left,char right){
	Str tmp(right);
	return (left+tmp);
}

Str::Str(char* str){
	size = 0;
	for(;str[size] != 0;size++);
	this->source = new unsigned char[size+1];
	for(int i=0;i<size;i++)
		this->source[i] = str[i];
	this->source[size] = '\0';
}

Str::Str(char str){
	size = 1;
	this->source = new unsigned char[2];
	this->source[0] = str;this->source[1] = '\0';

}

Str::Str(const Str& other){
	this->source = new unsigned char[other.size+1];
	for(int i=0;i<=other.size;i++)
		this->source[i] = other.source[i];
	this->size = other.size;
}

Str::Str(){
	this->source = NULL;
	this->size=0;
}

Str::~Str(){
	delete [] this->source;
}

char* Str::getStr(){
	return (char*)source;
}

int Str::getSize(){
	return this->size;
}

void Str::clear(){
	delete [] this->source;
	this->source = NULL;
	this->size=0;
}
