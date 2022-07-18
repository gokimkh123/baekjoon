//난이도 : 브론즈4, 유형 : 수학

#include <stdio.h>
int main()
{	
	int hour,min;
	int min2;
	
	scanf("%d %d",&hour,&min);
	scanf("%d",&min2);
	
	min+=min2;
	
	if(min>=60){
			hour+=(min/60);
			min=min%60;
	}
	
	if(hour==24)	hour=0;
	else if(hour>24)	hour=hour%24;
	
	printf("%d %d",hour,min);
}

