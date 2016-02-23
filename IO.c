#include <u.h>

int x;

read(){
  asm(LI,0);
  asm(BIN);	// ��������load��a
  asm(SL,4);
}

write(int x){
  asm(LL,8);
  asm(PSHA);	// ��a��ֵpush��ջ
  asm(POPB);	// ��������load��b���ȴ����
  asm(LI,1);
  asm(BOUT);	// ���b
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
