#include <stdio.h>
#include <sys/time.h>

time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

time_t  eat(time_t *eat, time_t *last_meal)
{
    return(*eat + *last_meal);
}

int main(void)
{
    time_t	last_meal;
    time_t  time_eat;
    time_t  time_die;
    time_t  death;
    time_t  feeded;

    last_meal = get_time_in_ms();
    time_die = 500;
    time_eat = 600;
    death = last_meal + time_die;
    feeded = eat(&time_eat, &last_meal);
    if (feeded > death)
        printf("You are Dead");
    else
        printf("Start:%ld\nFeeded:%ld\n", last_meal, feeded);    
    return 0;
}