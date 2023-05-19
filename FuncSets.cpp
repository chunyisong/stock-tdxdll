/*
执行如下命令编译生成 dll 文件：
```
g++ -shared -o build/FuncSets.dll FuncSets.cpp
```
生成的 dll拷贝到通达信安装目录下的 T0002/dlls/ 子目录下，再在公式管理器中进行绑定即可使用。
*/
#include "FuncSets.h"

// 1 号函数
void Func1(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc) {
  for (int i = 0; i < DataLen; i++)
    pfOUT[i] = i;
}

// 2 号函数
void Func2(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    pfOUT[i] = pfINa[i] + pfINb[i] + pfINc[i];
    pfOUT[i] = pfOUT[i] / 3;
  }
}

// 加载的函数列表。
// 1、2 为对应分配给 dll 函数的调用编号，
// 对应公式 `TDXDLLn(funcid,param1,param2,param3)` 中的 funcid 参数的值，表示调用的 dll 函数的调用编号
FuncInfo funcList[] = {
    {1, (pFunc)&Func1},
    {2, (pFunc)&Func2},
    {0, NULL},
};

// 定义注册函数，固定名称为 RegisterTdxFunc，不可改成其它的名称
BOOL RegisterTdxFunc(FuncInfo** pFun) {
  if (*pFun == NULL) {
    (*pFun) = funcList;
    return TRUE;
  }
  return FALSE;
}
