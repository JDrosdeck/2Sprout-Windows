#ifdef DLLDIR_EX
   #define DLLDIR  __declspec(dllexport)   // export DLL information

#else
   #define DLLDIR  __declspec(dllimport)   // import DLL information

#endif 

class DLLDIR Sprout
{
   public:
      static char* getSproutItem();   // Class function Add
};