首先 创建方向结构体、食物结构体、蛇身链表结构体、蛇的属性结构体 

用到windows.h头文件里的gotoxy()函数,作用是将光标定位到指定坐标。

主程序:
int main(void)		//程序入口
{
	Homepage();
	while(1)
	{
		keybordhit();	//监控键盘按键
		move();		//蛇的坐标变化
		draw();		//蛇的重绘
		keybordhit();	//监控键盘按键
		Sleep(SPEECH);	//暂时挂起线程
	}
	return 0;
}
总体思路:处于死循环，所以,蛇循环移动，keybordhit()函数可以监控键盘按键

如果键盘有键被按下，且按下的键是W、A、S、D，则改变蛇的方向。

move()函数，刷新蛇身每个结点的坐标，且根据蛇的方向通过Addnode()函数改变各结点坐标

draw()函数,重绘蛇的形状。

Sleep(time)函数 为蛇行动的速度。