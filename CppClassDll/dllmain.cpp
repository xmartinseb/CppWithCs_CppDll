#include "pch.h"
#include "ianimal.h"

// T�mto se ozna�uj� funkce, kter� maj� b�t v DLL viditeln� pro programy, kter�
//tuo DLL na��taj�
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

// N�e jsou metody t��d, konstruktory a destruktory p�eps�ny do funkc� ve stylu C, proto�e budou dohledateln�
// ve zkompilovan� DLL (narozd�l od p�vodn�ch metod t��d)

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

