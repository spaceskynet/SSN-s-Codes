//���ٸ���Ҷ�任��FFT��
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

#define PI 3.14159265
#define N  4095       //����256��

typedef struct              //����ṹ��
{
	double real;/*ʵ��*/
	double img;/*�鲿*/
} complex;

complex x[N * 2], *W;                       /*������е�ֵ*/                      //���г��� ȫ�ֱ���

void add(complex a, complex b, complex *c)      //  ����������
{
	c->real = a.real + b.real;
	c->img = a.img + b.img;
}
void sub(complex a, complex b, complex *c)      //  ����������
{
	c->real = a.real - b.real;
	c->img = a.img - b.img;
}
void mul(complex a, complex b, complex *c)      //����������
{
	c->real = a.real*b.real - a.img*b.img;
	c->img = a.real*b.img + a.img*b.real;
}
void divi(complex a, complex b, complex *c)      //  ����������
{
	c->real = (a.real*b.real + a.img*b.img) / (b.real*b.real + b.img*b.img);
	c->img = (a.img*b.real - a.real*b.img) / (b.real*b.real + b.img*b.img);
}

void initW(int size)                                //ŷ����ʽ����
{
	int i;
	W = (complex*)malloc(sizeof(complex)* size);    //�����ڴ�ռ�
	for (i = 0; i<size; i++)
	{
		W[i].real = cos(2 * PI / size*i);
		W[i].img = -1 * sin(2 * PI / size*i);
	}
	/*for (i = 0; i < size; i++)
	{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << W[i].real << " ";
	cout << W[i].img <<"j" << " ";
	}*/
}

void changex(int size)                      //��ַ����
{
	complex temp;
	unsigned int i = 0, j = 0, k = 0;
	double t;
	for (i = 0; i<size; i++)
	{
		k = i;
		j = 0;
		t = (log(size) / log(2));
		while ((t--)>0)
		{
			j = j << 1;
			j |= (k & 1);
			k = k >> 1;
		}
		if (j>i)
		{
			temp = x[i];
			x[i] = x[j];
			x[j] = temp;
		}
	}
}


void fftx()                             //���ٸ���Ҷ����
{
	long    int i = 0, j = 0, k = 0, l = 0;
	complex up, down, product;
	changex(N);
	for (i = 0; i<log(N) / log(2); i++) /*һ����������*/
	{
		l = 1 << i;
		for (j = 0; j<N; j += 2 * l) /*һ���������*/
		{
			for (k = 0; k<l; k++) /*һ����������*/
			{
				mul(x[j + k + l], W[N*k / 2 / l], &product);
				add(x[j + k], product, &up);
				sub(x[j + k], product, &down);
				x[j + k] = up;
				x[j + k + l] = down;
			}
		}
	}
}


void output()   /*���x���*/
{
	int i;
	printf("\nx����Ҷ�任���\n");
	for (i = 0; i<N; i++)
	{
		if (i % 4 == 0 && i != 0) printf("\n");
		printf("  %.2f", x[i].real);
		if (x[i].img >= 0.0001)
			printf("+%.2fj  ", x[i].img);
		else if (fabs(x[i].img)<0.0001)
			printf("+0.0000j  ");
		else
			printf("%.2fj  ", x[i].img);
	}
	printf("\n");
}

/*void save()           //����x����Ҷ�任���
{
    int i;
    ofstream outfile("D:\\result1.txt", ios::out);
    if (!outfile)
    {
        cerr << "open result1.txt erro!" << endl;
        exit(1);
    }
    outfile << "x����Ҷ�任���:" << endl;
    for (i = 0; i<N; i++)
    {
        outfile << x[i].real;
        if (x[i].img >= 0.0001)
            outfile << "+" << x[i].img << "j" << " ";
        else   if (fabs(x[i].img)<0.0001)
            outfile << "+" << "0.00" << "j" << " ";
        else
            outfile << x[i].img << "j" << " ";
    }
    printf("\n");
    outfile.close();
}*/

int main()
{
	clock_t start = clock();
	double duration;
	/*��x���и���Ҷ�任*/
	int i, j = 0, t = 0;
	double data[N * 2] = { 0 };
	double result[N * 2] = { 0 };
	float tx = 0;
	//ofstream outfile1("D:\\result.txt", ios::out);
	for (t = 0; t < N; t++)
	{
		data[t] = 5 + 7 * cos(30 * PI / 128 * t - 30 * PI / 180) + 3 * cos(80 * PI / 128 * t - 90 * PI / 180);
	}
	for (i = 0; i<N; i++)            //���x��256���������ֵ ��һ������Ҷ�仯
	{
		x[i].real = data[i];
		x[i].img = 0;
		//printf("%.4f ", x[i].real);
		//printf("%.4f ", x[i].img);
	}
	initW(N);
	fftx();
	//output();
	cout << "����źŵ�ģ";
	cout << endl;
	for (i = 0; i < N; i++)
	{
		result[i] = sqrt(x[i].real*x[i].real + x[i].img*x[i].img);
		if (i % 4 == 0)
			cout << endl;
		cout << setprecision(2) << result[i]/N*2 << " ";
		//outfile1 << result[i] / N * 2 << endl;
	}
	//save();
	clock_t end = clock();
	cout << "���õ�ʱ�䣺 ";
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	cout << duration << "ms";
	cout << endl;
	return 0;
}
