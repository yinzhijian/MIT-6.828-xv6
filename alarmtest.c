#include "types.h"
#include "stat.h"
#include "user.h"

void periodic();

int
main(int argc, char *argv[])
{
  int i;
  printf(1, "alarmtest starting\n");
  alarm(1, periodic);
  //Challenges: 3)Assuming your code doesn't check that tf->esp is valid, implement a security attack on the kernel that exploits your alarm handler calling code.
  //asm("movl %0,%%esp\n"
//		  :/**/
//		  :"r"(0x8dfbefb0));
  for(i = 0; i < 50*5000000; i++){
    //if((i++ % 500000) == 0)
      //write(2, ".", 1);
      asm("nop\n");
  }
      asm("movl $0x11,%eax\n movl %eax,%cr4\n");
  //for(i = 0; i < 50*5000000; i++){
  //  if((i++ % 500000) == 0)
  //    write(2, ".", 1);
  //}
  exit();
}

void
periodic()
{
  printf(1, "alarm!\n");
}
