#include <stdio.h>

typedef enum {
	singleTap,
	doubleTap,
	lrSwipe,
	rlSwipe,
	MaxEvents
}eventCodes;

typedef enum {
	idle,
	timeScreen,
	musicScreen,
	pedoScreen,
	MaxScreens
}stateCodes;

typedef struct {
	stateCodes currStateCode;
	eventCodes eventCode;
	stateCodes(* action) (void);
}transition;


//Functions
stateCodes goTime(void);
stateCodes goMusic(void);
stateCodes goPedo(void);
stateCodes goIdle(void);


stateCodes goTime(void)
{
	printf("TIME SCREEN!\n");
	return timeScreen;
}

stateCodes goMusic(void)
{
	printf("MUSIC SCREEN!\n");
	return musicScreen;
}

stateCodes goPedo(void)
{
	printf("PEDO SCREEN!\n");
	return pedoScreen;
}

stateCodes goIdle(void) 
{
	printf("IDLE!\n");
	return idle;
}

transition stateTransitions[] = {
	{idle,singleTap,&goTime},
	{timeScreen,lrSwipe,&goMusic},
	{musicScreen,lrSwipe,&goPedo},
	{pedoScreen,lrSwipe,&goIdle}
};

eventCodes getEvent(void)
{
	eventCodes event = MaxEvents;
	char ch;
	while(event == MaxEvents) {
		printf(">> ");
		scanf(" %c",&ch);
		switch(ch) {
			case 's':
				event  = singleTap;
				break;
			case 'l':
				event =  lrSwipe;
				break;
			default:
				printf("Invalid event\n");

		}
	}
	return event;
}


int main(void)
{
	stateCodes curState = goIdle();
	eventCodes curEvent = MaxEvents;
	while(1) {
		curEvent = getEvent();
		if(stateTransitions[curState].eventCode == curEvent) {
			curState =  stateTransitions[curState].action();
		}
		else {
		}
	}
	return 0;
}

