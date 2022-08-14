//计算器：函数指针数组方法
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("******************************\n");
	printf("****** 1.add      2.sub ******\n");
	printf("****** 3.mul      4.div ******\n");
	printf("******      0.exit     *******\n");
	printf("******************************\n");
}
int main()
{
	int input = 0;
	do
	{
		menu();
		int x = 0;
		int y = 0;
		int ret = 0;
		printf("请选择：>");
		scanf("%d", &input);
		//pfArr就是函数指针数组
        //转移表 --- 《C和指针》--- 根据下标找到函数位置，然后调用。
		int (*pfArr[5])(int, int) = {NULL, Add,Sub,Mul,Div};//NULL空指针，下标从1开始
		
		if (input >= 1 && input <= 4)
		{
			printf("请输入2个操作数：>");
			scanf("%d %d", &x, &y);
			ret = (pfArr[input])(x, y);//调用函数指针数组元素，(*pfArr[input])(x,y);可以不加*。
			printf("%d\n", ret);
		}
		else if(input == 0)
		{
			printf("退出程序\n");
			break;
		}
		else
		{
			printf("选择错误\n");
		}
	} while (input);
	return 0;
}