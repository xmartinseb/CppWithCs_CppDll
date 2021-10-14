#include "pch.h"
#include "ianimal.h"
#include <atomic>

/// <summary>
/// C# GC asi b�� na sv�m vl�knu, proto rad�i ud�lam
/// multithread� integer.
/// </summary>
static std::atomic_int animals_num = 0;

int get_animals_num() {
	return animals_num;
}

ianimal::ianimal(const string& name, int age) : name(name), age(age) {
	++animals_num; // Pro kontrolu po�tu existuj�c�ch instanc�
}

ianimal::~ianimal() {
	--animals_num; // Pro kontrolu po�tu existuj�c�ch instanc�
}

dog::dog(const string& name, int age) : ianimal(name, age) {
}

const string& dog::speak() const {
	return word; // "Haf";
}

bird::bird(const string& name, int age) : ianimal(name, age) {
}

const string& bird::speak() const {
	return word; // "Piiip";
}

sheep::sheep(const string& name, int age) : ianimal(name, age) {
}

const string& sheep::speak() const {
	return word; // "Beee";
}