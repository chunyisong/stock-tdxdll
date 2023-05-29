#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <iostream>
using namespace std;

const int MAX = 2;
int main1() {
  int var[MAX] = {10, 100};
  int* ptr[MAX];

  for (int i = 0; i < MAX; i++) {
    ptr[i] = &var[i];  // 赋值为整数的地址
  }
  for (int i = 0; i < MAX; i++) {
    cout << "Value of var[" << i << "] = " << *ptr[i] << endl;
  }
  return 0;
}

int main2() {
  const char* names[MAX] = {
      "Zara Ali",
      "Hina Ali",
  };

  for (int i = 0; i < MAX; i++) {
    cout << "Value of names[" << i << "] = " << names[i] << endl;
  }
  return 0;
}

int main3() {
  // 声明简单的变量
  int i;

  // 声明引用变量(& 读作引用)
  int& r = i;

  i = 5;
  cout << "Value of i : " << i << endl;
  cout << "Value of i reference : " << r << endl;

  r = 6;
  cout << "Value of i : " << i << endl;
  cout << "Value of i reference : " << r << endl;

  return 0;
}

// 函数声明
void swap(int& x, int& y);

int main() {
  // 局部变量声明
  int a = 100;
  int b = 200;

  cout << "交换前，a 的值：" << a << endl;
  cout << "交换前，b 的值：" << b << endl;

  /* 调用函数来交换值 */
  swap(a, b);

  cout << "交换后，a 的值：" << a << endl;
  cout << "交换后，b 的值：" << b << endl;

  return 0;
}

// 函数定义
void swap(int& x, int& y) {
  int temp;
  temp = x; /* 保存地址 x 的值 */
  x = y;    /* 把 y 赋值给 x */
  y = temp; /* 把 x 赋值给 y  */

  return;
}

double vals[] = {1, 2};
double& setValues(int i) {
  double& ref = vals[i];
  return ref;  // 返回第 i 个元素的引用
}
int main5() {
  cout << "改变前的值 vals[1] = " << vals[1] << endl;
  setValues(1) = 3;  // 改变第 2 个元素
  cout << "改变后的值 vals[1] = " << vals[1] << endl;
  return 0;
}