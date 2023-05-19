# 编译生成 dll 并复制到 TDX/T0002/dlls/ 的脚本

# dll 文件名称
name="FuncSets"
dllFile="$name.dll"

# 创建 build 目录
if [ ! -d "build" ]; then
  echo "创建 build 目录"
  mkdir -p "build"
fi

# 执行编译
echo "开始编译生成 dll ..."
if g++ -shared -o "build/$dllFile" "$name.cpp"; then
  echo "编译成功，生成文件 build/$dllFile"

  # 第 1 个参数可以指定 TDX 的安装路径
  if [ ! -n "$1" ]; then
    tdxDir="c:/new_tdx"
  else
    tdxDir=$1
  fi

  # 判断 TDX 是否存在
  if [ ! -d "$tdxDir" ]; then
    echo "通达信安装路径 “$tdxDir” 不存在，请指定为正确的安装路径"
    exit 1
  fi

  # 创建 TDX/T0002/dlls 目录
  if [ ! -d "$tdxDir/T0002/dlls" ]; then
    mkdir $tdxDir/T0002/dlls
    echo "创建 \$TDX/T0002/dlls 目录"
  fi

  # 复制 dll
  if cp -f "build/$dllFile" "$tdxDir/T0002/dlls/"; then
    echo "已复制 build/$dllFile 到 \$TDX/T0002/dlls/$dllFile，启动通达信然后在公式管理器中进行绑定即可"
  else
    echo "复制 dll 到 \$TDX/T0002/dlls 失败，通常如果 TDX 正在运行使用此 dll 就会导致复制失败，此时先关闭 TDX 再执行此脚本，通常都能解决问题"
  fi
else
  echo "编译失败"
fi
