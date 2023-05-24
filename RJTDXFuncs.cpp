/*
执行如下命令编译生成 dll 文件：
```
g++ -shared -o build/RJTDXFuncs.dll RJTDXFuncs.cpp
```
生成的 dll拷贝到通达信安装目录下的 T0002/dlls/ 子目录下，再在公式管理器中进行绑定即可使用。
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "RJTDXFuncs.h"
using namespace std;

// 获取当前时间的 ISO 格式字符串
std::string getCurrentTime() {
  // 获取当前时间
  auto now = std::chrono::system_clock::now();
  auto time_t_now = std::chrono::system_clock::to_time_t(now);
  auto tm_now = *std::localtime(&time_t_now);  // local time
  // auto tm_now = std::gmtime(&time_t_now); // UTC

  // 将时间转化为ISO格式的字符串
  char buffer[20];
  strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%S", &tm_now);

  // 返回ISO格式的时间字符串
  return std::string(buffer);
}

/*
注：
1. TDXDLLn(DataLen, ...) 函数每个个股只会执行一次，不是每根 K 线执行一次。
2. DataLen 其初始值等于 "系统设置>设置2>初始分析数据个数" 中的设定值，默认 420。
   当缩小 K 线图，导致 K 线数据个数增多时，dll 函数就会重新执行一遍。（放大 K 线图不会重新执行 dll 函数）

TODO：实盘时间隔 ? 秒执行一次呢？
*/

// 1 号函数
void Func1(int dataLen, float* out, float* kH, float* kL, float* _) {
  // 测试代码
  // 函数访问计数器
  static int num = 0;
  num++;
  std::ofstream file("rj_debug.txt", std::ios::app);
  if (file.is_open()) {
    std::string time_str = getCurrentTime();
    file << "Func1 " << std::to_string(num) << " " << std::to_string(dataLen) << " " << time_str << std::endl;
    file.close();
  }

  // 第一个 K 线无包含，值为 0
  out[0] = 0;

  // 找左侧第一根包含 K 的位置 N
  for (int j = 1; j < dataLen; j++) {
    float maxH = kH[j];
    float minL = kL[j];
    out[j] = 0; // 默认假设无包含
    for (int i = j - 1; i >= 0; i--) {
      maxH = max(kH[i], maxH); 
      minL = min(kL[i], minL);
      // Kj 的高低点都在 Ki 的高低点内且 i~j 之间的高低点也在 Ki 高低点内，则 Ki 包含 Kj
      if (kH[i] >= kH[j] && kL[i] <= kL[j] && kH[i] >= maxH && kL[i] <= minL) {
        // 记录为 i~j 之间的周期数
        out[j] = j - i;
        break;
      }
    }
  }
}

// 2 号函数
void Func2(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    pfOUT[i] = i;
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
