# stock-tdxdll

RJ 的通达信 dll 编程。

## MinGW 编译

```shell
# 使用 MinGW64 的 g++ 编译成功，但复制到通达信 T0002/dlls 下，启动后指标无显示 - 失败
g++ -shared -o build/TestPluginTCale.dll StdAfx.cpp TCalcFuncSets.cpp TestPluginTCale.cpp

# 使用 MinGW32 的 g++ 编译测试成功，-m32 参数设与不设编译出来的 dll，放到通达信实测都 OK
g++ -m32 -shared -o build/TestPluginTCale.dll StdAfx.cpp TCalcFuncSets.cpp TestPluginTCale.cpp
g++ -m32 -shared -o build/TestPluginTCale.dll TestPluginTCale.cpp
```