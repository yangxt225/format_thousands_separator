#include <stdio.h>

char* format_thousands_separator(unsigned long  value)
 {
      static char buffer[16][27];
      static int  times = 0;
    
      // m表示每一次切割出来的数字,n表示分隔符位数
      int m, n = 0;
      // unsigned long 最高可有20位数,分隔符最多会有6个,加上'\n'
      char* p = &buffer[times++ % 16][27];
     // 先加上字符串结束字符'\n'
      *p = '\0';
  
    do 
    {
      // 取value的最后一位
        m = value % 10;
        value = value / 10;
        --p;
        // 从数组最后开始存入数字的ASCII码,先存个位,再存百位...依此
        *p = '0' + m;

       // 3 表示分隔符位数,千位分隔符为3
        if (value && !(++n % 3))
        {
            --p;
        // 加入分隔符
            *p = ',';
        }

    } while(value); // 当已经遍历value所有位数,结束循环

    return p;
}

int main()
{
    printf("num1(%s), num2(%s), num3(%s)\n", format_thousands_separator(0),format_thousands_separator(123456),format_thousands_separator(23456789)); 

    return 0;
}
