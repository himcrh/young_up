//捕捉键值
 #include<stdio.h>
 #include<conio.h>

 int main()
 {
   int ch;
   while( (ch=getch())!=0x1B ) /* Press ESC to quit... */
   {
      switch(ch)
      {
      case 0xE0:
         switch(ch=getch())
         {
            case 72:  printf("UP\n"); break;
            case 80:  printf("DOWN\n"); break;
            case 75:  printf("LEFT\n"); break;
            case 77:  printf("RIGHT\n"); break;
            default:
               break;
         }
         break;
      default:
         break;
      }
   }
}