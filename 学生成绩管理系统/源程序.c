#include<stdio.h>
#include<stdlib.h>
#include"Faction.h"
#define MAX 31

int main()
{
	int number;
	printf("*******************************\n");
	printf("�������ж�����ѧ����");
	scanf("%d", &number);
	printf("*******************************\n");
	char ch;
	int score[MAX];
	int Sno[MAX];
	printf("***************************************\n");
	printf("*     ��ѡ����Ҫ���еĲ���            *\n");
	printf("*  1������ɼ���                      *\n");
	printf("*  2����ѧ�Ž������������            *\n");
	printf("*  3�����ɼ��������������            *\n");
	printf("*  4�������β�ѯ�ɼ���                *\n");
	printf("*  5����ѧ�Ų�ѯ�ɼ���                *\n");
	printf("*  6�����ÿ��ѧ���ĳɼ����ܷ�,ƽ���� *\n");
	printf("*  7����������                        *\n");
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
//����ѧ�źͳɼ�
int Enter(int Sno[], int score[], int number)
{
	int i = 0;
	printf("ѧ����ɼ�֮���ÿո�ָ�����\n");
	printf("Sno score\n");
	for (i = 0; i < number; i++)
	{
		scanf("%d %d", &Sno[i], &score[i]);//��������ѧ�źͳɼ�
	}
	return 0;
}
//�Գɼ���ͺ�ƽ����
int avg(int score[], int n)
{
	int i;
	float sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += score[i];
	}
	printf("�ֺܷ�Ϊ��%.0f ƽ����Ϊ��%.2f\n", sum, sum / (n + 0.0));
	return 0;
}
//���ɼ��������
int sortScore(int Sno[], int score[], int n)//�Գɼ����� �����
{
	int i;
	printf("***************************************\n");
	printf("*");
	printf("              ���ɼ�����ɼ���       ");
	printf("*\n");
	printf("***************************************\n");
	sortofscore(score, Sno, n);
	for (i = 0; i < n; i++)
	{
		printf("* ��%d��   ѧ�ţ�%-3d   ������ %-3d     *\n", i + 1, Sno[i], score[i]);//���ɼ��Ӵ�С���ѧ�źͳɼ���
	}
	printf("**************************************\n");
	return 0;
}
//��ѧ���������
int sortSno(int score[], int Sno[], int n)//��ѧ������ �����
{
	int i;
	printf("***************************************\n");
	printf("*");
	printf("             ��ѧ������ɼ���        ");
	printf("*\n");
	printf("***************************************\n");
	sortofSno(score, Sno, n);
	for (i = 0; i < n; i++)
	{
		printf("*      ѧ�ţ� %-3d      ������ %-3d     *\n", Sno[i], score[i]);//��ѧ�Ŵ�С�������ѧ�źͳɼ�
	}
	printf("***************************************\n");
	return 0;
}
//�����β�ɼ�
int serchRanking(int Sno[], int score[], int number)
{
	printf("��������Ҫ��ѯ�����Σ�");
	int ranking;
	scanf("%d", &ranking);
	sortofscore(score, Sno, number);
	for (int i = 0; i < number; i++)
	{
		if (ranking == (i + 1))
		{
			printf("���ʣ�%d ѧ�ţ�%d �ɼ���%d", ranking, Sno[i], score[i]);
			break;
		}
	}
	return 0;
}
//��ѧ�Ų�ɼ�
int serchSno(int Sno[], int score[], int number)
{
	//sortofscore(score, Sno, number);
	printf("��������Ҫ��ѯ��ѧ�ţ�");
	int sno;
	scanf("%d", &sno);
	for (int i = 0; i < number; i++)
	{
		if (sno = Sno[i])
		{
			printf("ѧ�ţ�%d �ɼ���%d", Sno[i], score[i]);
			break;
		}
	}
	return 0;
}
//���ɼ�����
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
					Sno[i] = temp2;//ʹѧ����ɼ���Ӧ
				}
			}
	}
}
//��ѧ������
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
//ֱ�����ѧ�ųɼ����ܷ�ƽ����
void direct(int Sno[], int score[], int number)
{
	int i;
	printf("***************************************\n");
	printf("*    ���ÿ��ѧ���ĳɼ����ܷ�,ƽ����  *\n");
	printf("***************************************\n");
	for (i = 0; i < number; i++)
	{
		printf("*      ѧ�ţ�%-3d     ������ %-3d       *\n", Sno[i], score[i]);
	}
	printf("***************************************\n");
	avg(score, number);
}