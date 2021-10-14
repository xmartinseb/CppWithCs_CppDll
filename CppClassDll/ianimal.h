#pragma once
#include <string>
using std::string;

/// <summary>
/// Slou�� k ov��en�, �e se vol� destruktor ze strany C# Garbage collectoru
/// (tedy po�et instanc� m� ob�as automaticky klesnout)
/// </summary>
/// <returns>
/// Po�et existuj�c�ch instanc� zv��at
/// </returns>
int get_animals_num();

// Na n�e uveden�ch t��d�ch se uk�e, jak se t��dy mapuj�
// Oby�ejn� struktury jazyka C by �ly p�ed�vat p��mo pomoc� C# Marshalov�n�.
// T��dy s metodamy, zvl�t� pak s virtu�ln�mi a s d�d�n�m tuhle mo�nost fakt nemaj�.

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