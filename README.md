# stock-tdxdll

RJ ��ͨ���� dll ��̡�

## MinGW ����

```shell
# ʹ�� MinGW64 �� g++ ����ɹ��������Ƶ�ͨ���� T0002/dlls �£�������ָ������ʾ - ʧ��
g++ -shared -o build/TestPluginTCale.dll StdAfx.cpp TCalcFuncSets.cpp TestPluginTCale.cpp

# ʹ�� MinGW32 �� g++ ������Գɹ���-m32 �������벻���������� dll���ŵ�ͨ����ʵ�ⶼ OK
g++ -m32 -shared -o build/TestPluginTCale.dll StdAfx.cpp TCalcFuncSets.cpp TestPluginTCale.cpp
g++ -m32 -shared -o build/TestPluginTCale.dll TestPluginTCale.cpp
```