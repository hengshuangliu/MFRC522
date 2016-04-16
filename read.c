#include "MFRC522.h"
#include <unistd.h>
/******************************************************************************
 * 函 数 名：main
 * 功能描述：
 ******************************************************************************/
int main(){
  unsigned char s;
  unsigned char id[10];
  int i;
  if (!bcm2835_init()) return -1;
  RFID_init();
 
  while(1){
    if (findCard(0x52,&s)==MI_OK){
       if ( anticoll(id)==MI_OK){
         for(i=0;i<5;i++)  printf("%d ",id[i]);
         printf("\n");
       } else printf("ERR\n");
    }
    sleep(1);
  }
 
  bcm2835_spi_end();
  bcm2835_close();
  return 0;
}