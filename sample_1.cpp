#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <sys/stat.h>

using namespace std;
int count=0;

int main()
{
	ofstream fout;
 
	system("clear");
        mkdir("/home/nuzhat/my_ramfs", 777);
        system("sudo mount -t tmpfs -o size=512k tmpfs /home/nuzhat/my_ramfs");
	
	fout.open("/home/nuzhat/my_ramfs/temp.txt");
       	system("touch ~/Desktop/dest.txt");

	while(1)
	{
		try
		{
			fout<<"Amit Anjum Nihal Bharath";
			if(!fout)
				throw 1;
		}

		catch(int a)
		{
			system("dd if=/home/nuzhat/my_ramfs/temp.txt bs=524288 count=1 of=/home/nuzhat/Desktop/dest.txt oflag=append conv=notrunc conv=noerror"); 				
			if(count++ == 3)
			{
				fout.close();
				system("rm /home/nuzhat/my_ramfs/temp.txt");
        			system("sudo umount /home/nuzhat/my_ramfs");
        			rmdir("/home/nuzhat/my_ramfs");
				exit(0);
			}
		}
	}
}
