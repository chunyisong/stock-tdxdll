// 生成的 dll 及相关依赖 dll 请拷贝到通达信安装目录的 T0002/dlls/ 下面,再在公式管理器进行绑定
#include "stdafx.h"
#include "TCalcFuncSets.h"

void TestPlugin1(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc) {
  for (int i = 0; i < DataLen; i++)
    pfOUT[i] = i;
}

void TestPlugin2(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    pfOUT[i] = pfINa[i] + pfINb[i] + pfINc[i];
    pfOUT[i] = pfOUT[i] / 3;
  }
}

// 加载的函数
PluginTCalcFuncInfo g_CalcFuncSets[] = {
    {1, (pPluginFUNC)&TestPlugin1},
    {2, (pPluginFUNC)&TestPlugin2},
    {0, NULL},
};

// 导出给 TCalc 的注册函数
BOOL RegisterTdxFunc(PluginTCalcFuncInfo** pFun) {
  if (*pFun == NULL) {
    (*pFun) = g_CalcFuncSets;
    return TRUE;
  }
  return FALSE;
}
