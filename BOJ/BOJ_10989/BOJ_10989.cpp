#include<bits/stdc++.h>
using namespace std;

// 여기서 T가 최대가 10,000,000 이다. 배열에 담을려고 하면 다 못담는다 
//int 배열의 최대 크기가 약 이십오만 이란다, 
// 입력값이 백만 이상이면 그냥 다른방법을 사용하자


int mycount[10000];

int N;

int main()

{



	scanf("%d", &N);

	for (int i = 0; i < N; ++i)

	{

		int num;

		scanf("%d", &num);



		mycount[num-1]++;

	}

	for (int i = 0; i < 10000; ++i) {



		if (mycount[i] != 0)

		{

			for (int j = 0; j < mycount[i]; ++j)

			{

				printf("%d \n", i + 1);

			}

		}

	}

	return 0;

}