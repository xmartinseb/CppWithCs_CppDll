#include "pch.h"
#include "ianimal.h"

// Tímto se oznaèují funkce, které mají být v DLL viditelné pro programy, který
//tuo DLL naèítají
#define Dll extern "C" __declspec(dllexport)

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

Dll ianimal* GetRandomAnimal(const char* name, int age) {
    switch (rand() % 3)
    {
    case 0: return new dog(name, age);
    case 1: return new sheep(name, age);
    default: return new bird(name, age);
    }
}

// Níže jsou metody tøíd, konstruktory a destruktory pøepsány do funkcí ve stylu C, protože budou dohledatelné
// ve zkompilované DLL (narozdíl od pùvodních metod tøíd)

Dll void Animal_Dispose(ianimal* a) {
    delete a;
}

Dll const char* Animal_Speak(const ianimal* a) {
    return a->speak().c_str();
}

Dll const char* Animal_GetName(const ianimal* a) {
    return a->name.c_str();
}

Dll void Animal_SetName(ianimal* a, const char* nam) {
    a->name = nam;
}

Dll int Animal_GetAge(const ianimal* a) {
    return a->age;
}

Dll void Animal_SetAge(ianimal* a, int age) {
    a->age = age;
}

Dll int GetAnimalsNum() {
    return get_animals_num();
}

Dll dog* Dog_Create(const char* name, int age) {
    return new dog(name, age);
}

Dll bird* Bird_Create(const char* name, int age) {
    return new bird(name, age);
}

Dll sheep* Sheep_Create(const char* name, int age) {
    return new sheep(name, age);
}

