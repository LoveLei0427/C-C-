var k:integer;
	type item:any;
	buffer:[0,1,...k-1] of item;
	in,out:integer:=0;
	counter:integer:=0;
process producer:
	while(TRUE)
		produce an item in nextp; //生产一个产品
		if(counter==k) sleep();//缓冲满则生产者睡眠
		buffer[in]:=next;//一个产品放入缓冲区
		in:=(in+1)mod k;//指针推进
		counter:=counter+1;//缓冲区内产品数加1
		if(counter==1) wakeup(consumer);//缓冲为空增加 并唤醒消费者
		
process consumer:
	while(TRUE)
		if(counter==0)sleep();//缓冲区空 消费者睡眠
		nextc:=buffer[out];//取一个产品
		out:=(out+1)mod k;
		counter:=counter-1;
		if(counter=k-1)wakeup(producer)
		
		consume thr item in nextc;//消耗产品