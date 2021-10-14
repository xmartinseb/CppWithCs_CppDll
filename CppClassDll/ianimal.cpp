#include "pch.h"
#include "ianimal.h"
#include <atomic>

/// <summary>
/// C# GC asi bìží na svém vláknu, proto radši udìlam
/// multithreadí integer.
/// </summary>
static std::atomic_int animals_num = 0;

int get_animals_num() {
	return animals_num;
}

ianimal::ianimal(const string& name, int age) : name(name), age(age) {
	++animals_num; // Pro kontrolu poètu existujících instancí
}

ianimal::~ianimal() {
	--animals_num; // Pro kontrolu poètu existujících instancí
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