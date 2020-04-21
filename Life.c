#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <time.h> 
#include <string.h>

#define world_width 30
#define world_height 30

static char world[world_width][world_height];

void InitiateWorld();
void drawWorld();
void Live();
int main ()
{
	
	InitiateWorld();
	while(1){
		drawWorld();
		Live();
		sleep(1);
	}
	return 0;
}

void InitiateWorld()
{
	srand(time(0));
	for (int x = 0 ; x < world_width ; x++)
		for (int y = 0 ; y < world_height ; y++)
		{
			world[x][y] = ( rand() % 6 ) > 1? 1 : 0 ;
		}
}

void drawWorld()
{
	printf("\033c");
	for(int x = 0 ; x < world_width ; x++)
	{
		for (int y = 0 ; y < world_height ; y++)
		{
			printf( world[x][y] ? "*" : " " );
		}
	printf("\r\n");
	}
			
}

void Live()
{
	char newWorld[world_width][world_height];
	for ( int x = 0 ; x < world_width ; x++	)
		for (int y = 0 ; y < world_height ; y++)
		{
			int lives=0;
			for (int nx = x - 1 ; nx <= x + 1 ; nx++ )
				for (int ny = y - 1 ; ny <= y + 1 ; ny++ )
					if(world[(nx + world_width) % world_width][(ny + world_height) % world_height])
						lives++;
			if (world[x][y]) lives--;
			
			newWorld[x][y] = (lives == 3 || (lives	== 2 && world[x][y])? 1 : 0);
		}
	memcpy(world,newWorld,world_width*world_height);
}
