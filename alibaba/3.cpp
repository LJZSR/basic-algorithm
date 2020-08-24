#include<vector>
#include<iostream>
#include<random>

using namespace std;

//总金额数
double money;
//参与抢红包的人数
int num;
//最佳手气的最大金额
double maxMoney;

//获得一个红包的金额,money为当前剩余金额数目
double getMoney(double money, int num) {
  
  //产生一个0-1之间的随机数
  double ratio = rand()/double(RAND_MAX);
  //获得当前红包的金额
  double result = ratio * money;
  result = (int)(result * 100) / 100.0;
  
  //当红包金额为0，红包金额为maxMoney或者红包金额为剩余金额时，重新随机
  while (result <= num * 0.01 || result >= maxMoney || result == money) {
    ratio = rand()/double(RAND_MAX);
    result = ratio * money;
    result = (int)(result * 100) / 100.0;
  }
  return result;
}

int main() {
  //结果数组
  vector<double> res;
  cin >> money >> num;
  maxMoney = 0.9 * money;
  
  //获得num-1个红包的金额
  for (int i = 0; i < num-1; ++i) {
    double tmp = (int)(getMoney(money, num-i) * 100) / 100.0;
    res.push_back(tmp);
    money -= tmp;
  }
  
  //最后一个红包的金额
  res.push_back(money);
  
  //输出结果
  for (int i = 0; i < num; ++i) {
    cout << res[i] << " ";
  }
  cout << endl;
}