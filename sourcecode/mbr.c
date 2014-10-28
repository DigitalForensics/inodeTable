#include <sys/stat.h>
// #include <sys/ioctl.h>
#include <linux/hdreg.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include "/root/Desktop/ext2utils/superblock/test5.h"



extern struct hd_geometry geometry;
#define SIZE_OF_MBR
#define BLK_SIZE
#define MAGIC1 510
#define MAGIC2 511

#define MAGIC_VAL1 0x55
#define MAGIC_VAL2 0xAA
#define START_PARTITION_DATA 446
#define MAXNUM_OF_PARTS 4

void   printMBR( int fd ) {
   unsigned char b[BLK_SIZE];
   int retVal;
   int i, j;
   int countr;
   unsigned short s;
   unsigned long partSize, l;

   if (!ioctl(fd, HDIO_GETGEO, &geometry)) {
                printf(" heads = %d\n", geometry.heads);
                printf(" sectors = %d\n", geometry.sectors);
                printf(" cylinders = %d\n", geometry.cylinders);
   }

   retVal = read(fd, b , SIZE_OF_MBR);
   if ( retVal <=0 ) {
      fprintf(stderr, "unable to read disk, retVal = %d\n", 				retVal );
      return;
   }
   if ( (b[MAGIC1] != MAGIC_VAL1) && (b[MAGIC2] != MAGIC_VAL2) )
   {
      fprintf(stderr, "MBR corrupted ... \n");
      return;
   }

   /* Print the MBR 16 bytes per line */
   j=0;
   for(i=0;i<512;i++)
   {
      fprintf(stdout, "%2x ",b[i]);
      j++;
      if ( j == 16 ) {
         fprintf(stdout, "\n");
         j = 0;
      }
   }
   fprintf(stdout, "\n\n" );
   countr = START_PARTITION_DATA;
   for ( i = 0; i < MAXNUM_OF_PARTS; i++ ) {
      partSzie = b[countr+15];
      partSize = partSize << 8;
      partSize = partSize | b[countr+14];
      partSize = partSize << 8;
      partSize = partSize | b[countr+13];
      partSize = partize << 8;
      partSize = partSize | b[countr+12];
      if ( partsize > 0 ) {
    
         fprintf(stdout, "Boot indicator = %x\n", b[countr] );
         fprintf(stdout, "starting CHS head = %x\n", b[countr+1] );
         fprintf(stdout, "starting CHS sector = %x\n", b[countr+2] & 0x2f );
         s = b[countr+2] & 0xc0 ;
         s = s << 2 ;
         s = s | b[countr+3];
         fprintf(stdout, "starting CHS Cylinder = %x\n", s );
         fprintf(stdout, "Partition type = %x\n", b[countr+4] );
         fprintf(stdout, "Ending CHS head = %x\n", b[countr+5] );
         fprintf(stdout, "Ending CHS sector = %x\n", b[countr+6] & 0x2f );
         s = b[countr+6] & 0xc0 ;
         s = s << 2 ;
         s = s | b[countr+7];
         fprintf(stdout, "Ending CHS Cylinder = %x\n", s );
         l = b[countr+11];
         l = l << 8;
         l = l | b[countr+10];
         l = l << 8;
         l = l | b[countr+9];
         l = l << 8;
         l = l | b[countr+8];
         fprintf(stdout, "Starting Sector = %ld\n", l );
         fprintf(stdout, "partition Size = %ld\n", partSize );
         fprintf(stdout, "\n\n" );
      }
      countr += 16; // next partition
   }

}


