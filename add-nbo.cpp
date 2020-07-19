#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf


using namespace std;

uint32_t my_htonl(uint32_t n)
{
   uint32_t n1 = (n & 0xFF000000) >> 24;
   uint32_t n2 = (n & 0x00FF0000) >> 8;
   uint32_t n3 = (n & 0x0000FF00) << 8;
   uint32_t n4 = (n & 0x000000FF) << 24;

   return n1 | n2 | n3 | n4;
}
int main(int argc,char ** argv) {
  	FILE *fd_first=fopen(argv[1],"r");
	FILE *fd_second=fopen(argv[2],"r");
	uint32_t n1,n2;
	fread(&n1,4,256,fd_first);
	fread(&n2,4,256,fd_second);
	n1=my_htonl(n1);
	n2=my_htonl(n2);
	printf("%d (0x%x) + %d(0x%x) = %d(0x%x)\n",n1,n1,n2,n2,n1+n2,n1+n2);
	
	fclose(fd_second);
	fclose(fd_first);
}
