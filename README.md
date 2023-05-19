# stock-tdxdll

RJ 的通达信 dll 编程。

## 自动编译并发布到通达信

```shell
./build.sh "D:/path-to-install-tdx"
```

执行此 bash 脚本将自动编译 dll 并复制到 `TDX/T0002/dlls/` 目录下，第一个参数需指定为通达信的安装路径（不指定默认为 `c:/new_tdx`）。

## MinGW 编译说明

到 <https://github.com/niXman/mingw-builds-binaries/releases> 下载 MinGW 的 32 位版，其名称类似为 `i686-12.2.0-release-win32-dwarf-msvcrt-rt_v10-rev2.7z`，解压后将 `mingw32/bin` 目录配置到系统环境变量 `Path` 内即可在命令行直接使用 `g++` 来编译 `C++` 源代码。

> 注：不要下载安装 MinGW 的 64 位版，其名称类似为 `x86_64-12.2.0-release-win32-seh-msvcrt-rt_v10-rev2.7z`，实测用 64 位版编译出来的 dll，通达信不认，这也间接证明通达信是 32 位软件。

```shell
# 使用 MinGW32 的 g++ 编译测试成功，-m32 参数设与不设编译出来的 dll，放到通达信实测都 OK
g++ -shared -o build/FuncSets.dll FuncSets.cpp
g++ -m32 -shared -o build/FuncSets.dll FuncSets.cpp
```

> 源代码由 GBK 编码改为 UTF8 编码后，g++ 编译结果实测也 OK。\
> 以上是在 Windows11-x64 下实测通过的。