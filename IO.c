#include <u.h>

int x;

read(){
  asm(LI,0);
  asm(BIN);	// 键盘输入load到a
  asm(SL,4);
}

write(int x){
  asm(LL,8);
  asm(PSHA);	// 将a的值push进栈
  asm(POPB);	// 键盘输入load进b，等待输出
  asm(LI,1);
  asm(BOUT);	// 输出b
}

main()
{
  while(1){
    x=read();
    if (x!=-1){
      write(x);
      asm(HALT);
    }
  }
  asm(HALT);
}
