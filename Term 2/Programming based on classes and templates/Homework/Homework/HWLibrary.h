// ������� ��5 ���� ����� �.�.�������
// �������� ������� (2 �������)
// ������������ ���� ���������� �������
// ������ ����� (��5-23)

#pragma once

#include "resource.h"

#include "stdafx.h" 
#include <iostream> 
#include <fstream>

using namespace std;

#define fileName "Articles.txt"

enum ArticleType {

	Science		= 1,
	Sport		= 2,
	Gaming		= 3,
	Movies		= 4,
	News		= 5,
	Technology	= 6,
	Art			= 7,
	Undefined	= 0

};

// ����������� ����� ������

class AbstractArticle : public CObject {

public:

	virtual int classType() = 0;
	virtual char *className() = 0;
	
	long number;
	
	AbstractArticle() {

		number = NULL;

	}

	AbstractArticle(const AbstractArticle &article) {

		number = article.number;

	}
	
};

// ����� ������

class Article : public AbstractArticle {

public:

	// ��������

	ArticleType type;
	char *title;
	char *description;
	unsigned long wordsCount;

	// ������������

	Article();
	Article(const char *articleTitle);
	Article(const char *articleTitle, const char *articleDescription);
	Article(const char *articleTitle, const char *articleDescription, ArticleType articleType);
	Article(const char *articleTitle, const char *articleDescription, ArticleType articleType, long articleNumber, unsigned long articleWordsCount);

	// �����������

	~Article();

	// ������

	// �����������

	virtual int classType() { return 1; }
	virtual char *className() { return "Article"; }

	// �����������

	void setTitle(const char *articleTitle);
	const char *getTitle();
	void setDescription(const char *articleDescription);
	const char *getDescription();
	void print();

	// ���������

	Article operator = (Article &article);
	friend istream & operator >> (istream &in, Article &article);

	// �����

	void saveToFile();

};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ����������� ����� ��������

class AbstractCatalog {

public:

	virtual int classType() = 0;
	virtual char *className() = 0;

	int id;

	AbstractCatalog() {

		id = NULL;

	}

	AbstractCatalog(const AbstractCatalog &catalog) {

		id = catalog.id;

	}

};

// ����� ��������

class Catalog : public AbstractCatalog, public CArray <CObject *, CObject *> {

public:

	// ��������

	char *name;
	char *description;
	int count;
	bool vertified;

	// ������������

	Catalog();
	Catalog(const char *catalogName);
	Catalog(const char *catalogName, int articlesCount);
	Catalog(const char *catalogName, Article *articles, int articlesCount);
	Catalog(const char *catalogName, const char *catalogDescription, int articlesCount);

	// ����������

	~Catalog();

	// ������

	// �����������

	virtual int classType() { return 2; };
	virtual char *className() { return "Catalog"; };

	// �����������
	
	int getCount();

	void addArticle(Article *article);
	void removeArticle(int index);
	Article * getArticle(int index);

	void setVertified(bool catalogVertified);
	bool getVertified();

	Catalog *catalogWithType(ArticleType articleType);
	
	void sortByType();
	void sortByWordsCount();
	void sortByTitle();

	void print();

	// ���������

	Catalog & operator = (Catalog &catalog);
	friend Catalog & operator + (Catalog &catalog1, Catalog &catalog2);
	friend istream & operator>>(istream &in, Catalog &catalog);

	// �����

	void loadFormFile();
	void writeToFile();

};