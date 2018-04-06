#ifndef SWITCH_H
#define SWTICH_H

#define FAILURE 1
#define SUCCESS 0

void switch_setup(void);
int test_switch_south(long breaktime);
int test_switch_north(long breaktime);
int test_switch_east(long breaktime);
int test_switch_west(long breaktime);

#endif
