#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

typedef struct tm tm;

int numTestCases = 0;
char tmp[1000];

tm* rootTime = NULL;
tm* endTime = NULL;
time_t rootTimeT = 0;
long size = 0;
int *starts = NULL;

tm* createTime(int year, int month, int day, int hour, int minute);
int process(int index);
int getIndex(time_t t);
int init();

int main(int argc, char const *argv[]){

	init();

	for (int i = 0; i < numTestCases; ++i){
		process(i);
	}
	return 0;
}

int init(){
	char buff[1000];

	rootTime = (tm*) calloc(1, sizeof(tm));
	rootTime->tm_year = 2013;
	rootTime->tm_mon = 0;
	rootTime->tm_mday = 0;
	rootTime->tm_hour = 0;
	rootTime->tm_min = 0;
	rootTimeT = mktime(rootTime);

	endTime = (tm*) calloc(1, sizeof(tm));
	endTime->tm_year = 2018;
	endTime->tm_mon = 0;
	endTime->tm_mday = 0;
	endTime->tm_hour = 0;
	endTime->tm_min = 0;
	mktime(endTime);

	size = (long) difftime(mktime(endTime), rootTimeT) / 60;

	cin >> numTestCases;
}

tm* createTime(int year, int month, int day, int hour, int minute){
	tm *dateTime = (tm*) calloc(1, sizeof(tm));
	dateTime->tm_year = year;
	dateTime->tm_mon = month - 1;
	dateTime->tm_mday = day;
	dateTime->tm_hour = hour;
	dateTime->tm_min = minute;
	mktime(dateTime);
	return dateTime;
}

int process(int index){
	int needCleans = 0;
	int numBookings = 0;
	int minuteCleans = 0;

	starts = (int*) calloc(size, sizeof(int));
	if (!starts){
		puts("not enough memory");
		exit(1);
	}

	cin >> numBookings >> minuteCleans;
	int indexStart = 0;
	int indexFinish = 0;
	for (int i = 0; i < numBookings; ++i){
		fflush(stdin);
		// gets(tmp);
		// printf("tmp[%d] / %d: %s\n", i, numBookings, tmp);
		int sY, sM, sD, sH, sm, fY, fM, fD, fH, fm;
		scanf("%s%d-%d-%d %d:%d %d-%d-%d %d:%d", tmp, &sY, &sM, &sD, &sH, &sm, &fY, &fM, &fD, &fH, &fm);
		starts[getIndex(mktime(createTime(sY, sM, sD, sH, sm)))]++;
		starts[getIndex(mktime(createTime(fY, fM, fD, fH, fm + minuteCleans)))]--;
	}

	int currentBookings = 0;
	for (int i = 0; i < size; i++){
		if (starts[i]){
			currentBookings += starts[i];
			needCleans = (currentBookings > needCleans) ? currentBookings : needCleans;
		}
		
	}

	printf("%d\n", needCleans);

	free(starts);
}

int getIndex(time_t t){
	return (int) difftime(t, rootTimeT) / 60;
}