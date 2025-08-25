#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#ifndef	CONSUMER
#define	CONSUMER	"Consumer"
#endif
struct timespec ts = { 1, 0 };
struct gpiod_line_event event;
struct gpiod_chip *chip;
struct gpiod_line *line;
int ret, val;

int open_chip(char* chipname) {
	chip = gpiod_chip_open_by_name(chipname);
	if (!chip) {
		perror("Open chip failed\n");
		return -1;
	}
	return 0;
}
int get_chip_line(unsigned int line_num) {
	line = gpiod_chip_get_line(chip, line_num);
	if (!line) {
		perror("Get line failed\n");
		close_chip();
		return -1;
	}
	return 0;
}
int line_request_input() {
	ret = gpiod_line_request_input(line, CONSUMER);
	if (ret < 0) {
		perror("Request line as input failed\n");
		gpiod_line_release(line);
	}
	return ret;
}
int line_request_rising_edge_events() {
	ret = gpiod_line_request_rising_edge_events(line, CONSUMER);
	if (ret < 0) {
		perror("Request event notification failed\n");
		gpiod_line_release(line);
	}
	return ret;
}
int line_request_output() {
	ret = gpiod_line_request_output(line, CONSUMER, 0);
	if (ret < 0) {
		perror("Request line as output failed\n");
		gpiod_line_release(line);
	}
	return ret;
}
int line_get_value() {
    val = gpiod_line_get_value(line);
	if (val < 0) {
		perror("Read line input failed\n");
		gpiod_line_release(line);
	}
	return val;
}
int line_set_value(int value) {
    ret = gpiod_line_set_value(line, val);
	if (ret < 0) {
		perror("Set line output failed\n");
		gpiod_line_release(line);
	}
	return ret;
}
int line_event_wait() {	
	ret = gpiod_line_event_wait(line, &ts);
	if (ret < 0) {
		perror("Wait event notification failed\n");
		gpiod_line_release(line);
	} else if (ret == 0) {
		print("Wait event notification timeout\n");
	}
	return ret;
}
int line_event_read() {
	ret = gpiod_line_event_read(line, &event);
	if (ret < 0) {
		perror("Read event notification failed\n");
		gpiod_line_release(line);
		return ret;
	}
    if(event.event_type == GPIOD_LINE_EVENT_RISING_EDGE) {
        print("Rising edge detected on line\n");
		return 1;
	} else if(event.event_type == GPIOD_LINE_EVENT_FALLING_EDGE) {
        print("Falling edge detected on line\n"); 
		return 3;  
    } else {
        print("Unknown event type on line\n");   
	}
	return 0;
}
void close_chip() {
	if (chip) {
		gpiod_chip_close(chip);
		chip = NULL;
	}
}

