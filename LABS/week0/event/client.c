//client.c
#include "event.h"
#include<stdio.h>
#include<stdlib.h>


int read_all(FILE *fp, event_t e[], int n)
{
	int dd; int mm; int yy; char detail[100];
	int i = 0;
	while(! feof(fp))
	{
		fscanf(fp, "%d %d %d %s", &dd, &mm, &yy, detail);
		set_event(&e[i], detail, dd, mm, yy);
		++i;
	}
	return i;
}

void disp_all(event_t e[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		disp_event(&e[i]);
	}
}


int main()
{
	event_t events[100];
	int n;
	FILE *fp = fopen("events.dat", "r");
	if(fp == NULL)
	{
		perror("file open:"); exit(1);
	}
	n = read_all(fp, events, 100);
	disp_all(events, n);
	fclose(fp);
}