#include <stdio.h>

int		inputPlayDay(char **project, int *project_play_day);
void	displayall(char	**project, float *blackhole, int *projects_play_day, int *year, int *month, int *day, float *left_blackhole);
void	calculate(int *year, int *month, int *day);
// 1 14 21 2 28 35 15 2 30 35 35 1 45 5

int	cnt = 14;

int	main(void)
{
	int		year = 2022, month = 8, day = 5;
	float	left_blackhole = 26;
	char	*project[14 /* 과제 개수 */] = {
		"exam02", "philosophers", "minishell",
		"exam03", "cpp-module", "cub3d",
		"netpractice", "exam04", "inception",
		"webserv", "ft_containers", "exam05",
		"ft_transendence", "exam06"
	};
	float	blackhole[14 /* 과제 개수 */] = {
		0, 65.17, 0, 0,
		73.61, 35.30, 17.16, 0,
		50.94, 88.12, 36.81, 0,
		57.96, 0
	};
	int		projects_play_day[cnt /* 과제 개수 */];
	inputPlayDay(project, projects_play_day);
	displayall(project, blackhole, projects_play_day, &year, &month, &day, &left_blackhole);
}

int	inputPlayDay(char **project, int *project_play_day)
{
	for (int i = 0; i < cnt /* 과제 개수 */; i++)
	{
		printf("%s 과제 소요일 : ", project[i]);
		scanf("%d", &project_play_day[i]);
	}
	printf("\n");
	return (1);
}

void	displayall(char	**project, float *blackhole, int *projects_play_day, int *year, int *month, int *day, float *left_blackhole)
{
	printf("%15s  |  %13s  |  %10s  |  %10s  |  %10s  |  %s  |\n", "과제명", "과제 시작일", "과제 소요일", "블랙홀 플러스", "과제 마침 날짜", "남은 블랙홀");
	for (int i = 0; i < cnt /* 과제 개수 */; i++)
	{
		printf("%13s\t  %d.%d.%d\t   %4d\t\t     %.2f\t    ", project[i], *year, *month, *day, projects_play_day[i], blackhole[i]);
		*day += projects_play_day[i];
		calculate(year, month, day);
		printf("%d.%d.%d\t       ", *year, *month, *day);
		(*day)++; (*left_blackhole)--;
		calculate(year, month, day);
		*left_blackhole = (*left_blackhole - projects_play_day[i]) + blackhole[i];
		printf("%.2f\n", *left_blackhole);
	}
}

void	calculate(int *year, int *month, int *day)
{
	if (((*month == 2 || *month == 4 || *month == 6 || *month == 9 || *month == 11) && *day > 30)
		|| ((*month == 1 || *month == 3 || *month == 5 || *month == 7 || *month == 8
		|| *month == 10 || *month == 12) && *day > 31))
	{
		if (((*month == 2 || *month == 4 || *month == 6 || *month == 9 || *month == 11) && *day > 30))
			*day -= 30;
		else
			*day -= 31;
		(*month)++;
		if (*month > 12)
		{
			*month = 1;
			(*year)++;
		}
	}
}
