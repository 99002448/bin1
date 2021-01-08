#ifndef MYSTRUCT_H
#define MYSTRUCT_H

struct myProtocol
{
	__uint8_t preamble_start;
	__uint8_t preamble_end;
	__uint8_t command;
	__uint8_t led_no;
	__uint8_t action;
};

void printData( struct myProtocol *s1 ) {
printf("\n\n  Protocol sent via serial port : %d %d %d %d %d\n", s1->preamble_start, s1->preamble_end, s1->command, s1->led_no, s1->action);
}
#endif