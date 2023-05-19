// 引用声明通达信 DLL 函数的头文件
#include "PluginTCalcFunc.h"

// 如果是 C++ 编译环境才执行的代码块
#ifdef __cplusplus

// `extern "C"` 指定该函数应使用 C 风格的命名约定，
// 这意味着该函数名不会被 C++ 编译器进行名称重整。
extern "C" {
// __declspec(dllexport) 关键字用于将函数从动态链接库（DLL）中导出，从而使通达信可以访问该函数。
__declspec(dllexport) BOOL RegisterTdxFunc(PluginTCalcFuncInfo** pFun);
}

#endif