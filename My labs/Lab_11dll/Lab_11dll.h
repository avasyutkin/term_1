#pragma once
#ifdef IS_CREATING_DLL
#define IMPORT_EXPORT_TRIGER extern "C" __declspec(dllexport)
#else
#define IMPORT_EXPORT_TRIGER extern "C" __declspec(dllimport)
#endif

IMPORT_EXPORT_TRIGER double ADD(double a, double b);
