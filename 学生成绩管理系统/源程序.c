#include<stdio.h>
#include<stdlib.h>
#include"Faction.h"
#define MAX 31

int main()
{
	int number;
	printf("*******************************\n");
	printf("请输入有多少名学生：");
	scanf("%d", &number);
	printf("*******************************\n");
	char ch;
	int score[MAX];
	int Sno[MAX];
	printf("***************************************\n");
	printf("*     请选择你要进行的操作            *\n");
	printf("*  1：输入成绩！                      *\n");
	printf("*  2：按学号进行排序输出！            *\n");
	printf("*  3：按成绩进行排序输出！            *\n");
	printf("*  4：按名次查询成绩！                *\n");
	printf("*  5：按学号查询成绩！                *\n");
	printf("*  6：输出每个学生的成绩及总分,平均分 *\n");
	printf("*  7：结束程序                        *\n");
	printf("***************************************\n");
	int chance;
	while (ch = getchar())
	{
		scanf("%d", &chance);
		switch (chance)
		{
		case 1:Enter(Sno, score, number);
			break;
		case 2:sortSno(score, Sno, number);
			avg(score, number);
			break;
		case 3:sortScore(Sno, score, number);
			avg(score, number);
			break;
		case 4:serchRanking(Sno, score, number);
			break;
		case 5:serchSno(Sno, score, number);
			break;
		case 6:direct(Sno, score, number);
			break;
		case 7:ch = '@@';
			break;
		default:
			break;
		}
		if (ch == '@')
			break;
	}
	return 0;
}
//输入学号和成绩
int Enter(int Sno[], int score[], int number)
{
	int i = 0;
	printf("学号与成绩之间用空格分隔！！\n");
	printf("Sno score\n");
	for (i = 0; i < number; i++)
	{
		scanf("%d %d", &Sno[i], &score[i]);//依次输入学号和成绩
	}
	return 0;
}
//对成绩求和和平均分
int avg(int score[], int n)
{
	int i;
	float sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += score[i];
	}
	printf("总分和为：%.0f 平均分为：%.2f\n", sum, sum / (n + 0.0));
	return 0;
}
//按成绩排序输出
int sortScore(int Sno[], int score[], int n)//对成绩排序 并输出
{
	int i;
	printf("***************************************\n");
	printf("*");
	printf("              按成绩排序成绩单       ");
	printf("*\n");
	printf("***************************************\n");
	sortofscore(score, Sno, n);
	for (i = 0; i < n; i++)
	{
		printf("* 第%d名   学号：%-3d   分数： %-3d     *\n", i + 1, Sno[i], score[i]);//按成绩从大到小输出学号和成绩；
	}
	printf("**************************************\n");
	return 0;
}
//按学号排序输出
int sortSno(int score[], int Sno[], int n)//对学号排序 并输出
{
	int i;
	printf("***************************************\n");
	printf("*");
	printf("             按学号排序成绩单        ");
	printf("*\n");
	printf("***************************************\n");
	sortofSno(score, Sno, n);
	for (i = 0; i < n; i++)
	{
		printf("*      学号： %-3d      分数： %-3d     *\n", Sno[i], score[i]);//按学号从小到大输出学号和成绩
	}
	printf("***************************************\n");
	return 0;
}
//按名次查成绩
int serchRanking(int Sno[], int score[], int number)
{
	printf("输入你所要查询的名次：");
	int ranking;
	scanf("%d", &ranking);
	sortofscore(score, Sno, number);
	for (int i = 0; i < number; i++)
	{
		if (ranking == (i + 1))
		{
			printf("名词：%d 学号：%d 成绩：%d", ranking, Sno[i], score[i]);
			break;
		}
	}
	return 0;
}
//按学号查成绩
int serchSno(int Sno[], int score[], int number)
{
	//sortofscore(score, Sno, number);
	printf("输入你所要查询的学号：");
	int sno;
	scanf("%d", &sno);
	for (int i = 0; i < number; i++)
	{
		if (sno = Sno[i])
		{
			printf("学号：%d 成绩：%d", Sno[i], score[i]);
			break;
		}
	}
	return 0;
}
//将成绩排序
void sortofscore(int score[], int Sno[], int number)
{
	int i, j;
	int temp;
	int temp2;
	for (i = 0; i < number; i++)
	{
		for (j = 0; j < number; j++)
			if (score[i] > score[j])
			{
				{
					temp = score[j];
					score[j] = score[i];
					score[i] = temp;
					temp2 = Sno[j];
					Sno[j] = Sno[i];
					Sno[i] = temp2;//使学号与成绩对应
				}
			}
	}
}
//将学号排序
void sortofSno(int score[], int Sno[], int number)
{
	int i, j;
	int temp, temp2;
	for (i = 0; i < number; i++)
	{
		for (j = 0; j < number; j++)
		{
			if (Sno[i] < Sno[j])
			{
				temp = Sno[j];
				Sno[j] = Sno[i];
				Sno[i] = temp;
				temp2 = score[j];
				score[j] = score[i];
				score[i] = temp2;
			}
		}
	}
}
//直接输出学号成绩，总分平均分
void direct(int Sno[], int score[], int number)
{
	int i;
	printf("***************************************\n");
	printf("*    输出每个学生的成绩及总分,平均分  *\n");
	printf("***************************************\n");
	for (i = 0; i < number; i++)
	{
		printf("*      学号：%-3d     分数： %-3d       *\n", Sno[i], score[i]);
	}
	printf("***************************************\n");
	avg(score, number);
}