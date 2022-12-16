#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<linux/fb.h>
int main(int argc,char*argv[])
{
	// decalre variable
	int fd;
	//argv[1] has in format /dev/fb0
	// open a file in read mode
	fd=open(argv[1],O_RDONLY);
	if(fd<0)
	{
		printf("the opening file is error");
		return -1;
	}
	 
	struct fb_var_screeninfo varInfo;
        //function call to get framebuffer size 
    	ioctl(fd, FBIOGET_VSCREENINFO,&varInfo);
    	//screen information
    	printf("res %u\n", varInfo.xres);
    	printf("yres %u\n", varInfo.yres);
    	printf("bits per pixel %u\n", varInfo.bits_per_pixel);
    
   	 return 0;
}
