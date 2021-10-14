#pragma once
#include <string>
using std::string;

/// <summary>
/// Slouží k ovìøení, že se volá destruktor ze strany C# Garbage collectoru
/// (tedy poèet instancí má obèas automaticky klesnout)
/// </summary>
/// <returns>
/// Poèet existujících instancí zvíøat
/// </returns>
int get_animals_num();

// Na níže uvedených tøídách se ukáže, jak se tøídy mapují
// Obyèejné struktury jazyka C by šly pøedávat pøímo pomocí C# Marshalování.
// Tøídy s metodamy, zvláštì pak s virtuálními a s dìdìním tuhle možnost fakt nemají.

class ianimal
{
public:
	string name;
	int age;

	ianimal() = delete;
	ianimal(const string& name, int age);

	virtual const string& speak() const =0;
	virtual ~ianimal();
};

class dog : public ianimal
{
private:
	const string& word = "Haf";
public:
	virtual const string& speak() const;
	dog(const string& name, int age);
	~dog() = default;
};

class bird : public ianimal
{
private:
	const string word = "Piiip";
public:
	virtual const string& speak() const;
	bird(const string& name, int age);
	~bird() = default;
};

class sheep : public ianimal
{
private:
	const string word = "Beeee";
public:
	virtual const string& speak() const;
	sheep(const string& name, int age);
	~sheep() = default;
};