// 声明通达信 DLL 函数的头文件

// 这句删掉会导致通达信崩溃。
// 默认情况下，编译器可能会在结构体成员之间插入填充字节，以便将它们对齐到字或双字边界，
// 提高内存访问效率。但是，这样会浪费内存，并在与其他程序或系统共享数据结构时引发问题。
// #pragma pack(push,1) 指令告诉编译器紧密地打包结构体成员，不插入任何填充字节，从而
// 使结构体的大小最小化。push 关键字将当前编译状态保存在堆栈上，1 参数将新的对齐方式
// 设置为 1 字节。通常在结构体定义末尾配对使用 #pragma pack(pop) 来恢复编译器以前的打包状态。
#pragma pack(push, 1)

// dll 函数声明
// 参数为 (数据个数,输出,输入a,输入b,输入c)
typedef void (*pPluginFUNC)(int, float*, float*, float*, float*);

// 定义 dll 函数结构体并创建类型别名
typedef struct tagPluginTCalcFuncInfo {
  unsigned short nFuncMark;  // 函数编号
  pPluginFUNC pCallFunc;     // 函数地址
} PluginTCalcFuncInfo;

// 声明 dll 注册函数结构
// typedef BOOL (*pRegisterPluginFUNC)(PluginTCalcFuncInfo**);

#pragma pack(pop)
