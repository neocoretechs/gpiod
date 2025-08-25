#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#ifndef	CONSUMER
#define	CONSUMER	"Consumer"
#endif

struct timespec ts = { 1, 0 };
static struct gpiod_line_event event;
static struct gpiod_chip *chip;
static struct gpiod_line **lines;
static char** line_names;
static int max_lines;
int ret;

int open_chip(char* chipname) {
	chip = gpiod_chip_open_by_name(chipname);
	if (!chip) {
		perror("Open chip failed");
		return -1;
	}
	  // Get the number of lines available on the chip
    max_lines = gpiod_chip_num_lines(chip);
    lines = malloc(max_lines * sizeof(struct gpiod_line*));
	line_names = malloc(max_lines * sizeof(char*)); 
    if (!lines || !line_names) {
        close_chip();
        return -1; // Memory allocation error
    }
	 // Initialize line names
    for (int i = 0; i < max_lines; i++) {
        lines[i] = gpiod_chip_get_line(chip, i);
        line_names[i] = gpiod_line_get_name(lines[i]); // Store the line name
    }
	return 0;
}

int find_chip_line(char* linename) {
	for (int i = 0; i < max_lines; i++) {
        if (lines[i] != NULL && strcmp(line_names[i], linename) == 0) {
            return i; // Return the index if found
        }
    }
	return 0;
}
int line_request_input(int line) {
	ret = gpiod_line_request_input(lines[line], CONSUMER);
	if (ret < 0) {
		perror("Request line as input failed");
		line_release(line);
	}
	return ret;
}
int line_request_rising_edge_events(int line) {
	ret = gpiod_line_request_rising_edge_events(lines[line], CONSUMER);
	if (ret < 0) {
		perror("Request event notification failed");
		line_release(line);
	}
	return ret;
}
int line_request_output(int line) {
	ret = gpiod_line_request_output(lines[line], CONSUMER, 0);
	if (ret < 0) {
		perror("Request line as output failed");
		line_release(line);
	}
	return ret;
}
int line_get_value(int line) {
    int val = gpiod_line_get_value(lines[line]);
	if (val < 0) {
		perror("Read line input failed");
		line_release(line);
	}
	return val;
}
int line_set_value(int line, int value) {
    ret = gpiod_line_set_value(lines[line], value);
	if (ret < 0) {
		perror("Set line output failed");
		line_release(line);
	}
	return ret;
}
int line_event_wait(int line) {	
	ret = gpiod_line_event_wait(lines[line], &ts);
	if (ret < 0) {
		perror("Wait event notification failed");
		line_release(line);
	} else if (ret == 0) {
		printf("Wait event notification timeout");
	}
	return ret;
}
int line_event_read(int line) {
	ret = gpiod_line_event_read(lines[line], &event);
	if (ret < 0) {
		perror("Read event notification failed");
		line_release(line);
		return ret;
	}
    if(event.event_type == GPIOD_LINE_EVENT_RISING_EDGE) {
        printf("Rising edge detected on line\n");
		return 1;
	} else if(event.event_type == GPIOD_LINE_EVENT_FALLING_EDGE) {
        printf("Falling edge detected on line\n"); 
		return 3;  
    } else {
        printf("Unknown event type on line\n");   
	}
	return 0;
}
int line_release(int line) {
	if(lines) {
		if(line < 0 || line >= max_lines) {
			fprintf(stderr, "Invalid line number\n");
			return -1;
		}
		if (lines[line]) {
			gpiod_line_release(lines[line]);
			lines[line] = NULL;
		}
		if(line_names[line]) {
			free(line_names[line]);
			line_names[line] = NULL;
		}
	}
	return 0;
}
int lines_release() {
	if (lines) {
		for (int i = 0; i < max_lines; i++) {
			if(lines[i]) {
				gpiod_line_release(lines[i]);
				lines[i] = NULL;
			}
		}
	}
	if(line_names) {
		for (int i = 0; i < max_lines; i++) {
			if(line_names[i]) {
				free(line_names[i]);
				line_names[i] = NULL;
			}
		}
	}
	return 0;
}
void close_chip() {
	if (chip) {
		lines_release();
		if(lines) {
			free(lines);
			lines = NULL;
		}
		if(line_names) {
			free(line_names);
			line_names = NULL;
		}
		gpiod_chip_close(chip);
		chip = NULL;
	}
}

