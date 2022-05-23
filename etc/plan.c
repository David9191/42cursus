#include <stdio.h>

int		inputPlayDay(char **project, int *project_play_day);
void	displayall(char	**project, float *blackhole, int *projects_play_day, int *year, int *month, int *day, float *left_blackhole);
void	calculate(int *year, int *month, int *day);

int	main(void)
{
	int		year = 2022, month = 5, day = 23;
	float	left_blackhole = 38;
	char	*project[17 /* 과제 개수 */] = {
		"push_swap", "minitalk", "fdf",
		"exam02", "philosophers", "minishell",
		"exam03", "miniRT", "cpp-module",
		"netpractice", "exam04", "inception",
		"webserv", "ft_containers", "exam05",
		"ft_transendence", "exam06"
	};
	float	blackhole[17 /* 과제 개수 */] = {
		29.82, 17.13, 13.53,
		0, 38.9, 27.38, 0,
		47.38, 63.86, 18.22, 0,
		52.07, 92.28, 36.87, 0,
		20.25, 0
	};
	int		projects_play_day[17 /* 과제 개수 */];
	inputPlayDay(project, projects_play_day);
	displayall(project, blackhole, projects_play_day, &year, &month, &day, &left_blackhole);
}

int	inputPlayDay(char **project, int *project_play_day)
{
	for (int i = 0; i < 17 /* 과제 개수 */; i++)
	{
		printf("%s 과제 소요일 : ", project[i]);
		scanf("%d", &project_play_day[i]);
	}
	return (1);
}

void	displayall(char	**project, float *blackhole, int *projects_play_day, int *year, int *month, int *day, float *left_blackhole)
{
	printf("%15s  |  %13s  |  %10s  |  %10s  |  %10s  |  %s  |\n", "과제명", "과제 시작일", "과제 소요일", "블랙홀 플러스", "과제 마침 날짜", "남은 블랙홀");
	for (int i = 0; i < 17 /* 과제 개수 */; i++)
	{
		printf("%13s\t  %d.%d.%d\t %4d\t\t  %.2f\t\t    ", project[i], *year, *month, *day, projects_play_day[i], blackhole[i]);
		*day += projects_play_day[i];
		calculate(year, month, day);
		printf("%d.%d.%d\t       ", *year, *month, *day);
		(*day)++;
		calculate(year, month, day);
		*left_blackhole = (*left_blackhole - projects_play_day[i]) + blackhole[i];
		printf("%.2f\n", *left_blackhole);
		if (project[i] == "*^exam")
			printf("\n");
	}
}

void	calculate(int *year, int *month, int *day)
{
	if (*day > 30)
	{
		*day -= 30;
		(*month)++;
		if (*month > 12)
		{
			*month = 1;
			(*year)++;
		}
	}
}