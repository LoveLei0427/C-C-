var k:integer;
	type item:any;
	buffer:[0,1,...k-1] of item;
	in,out:integer:=0;
	counter:integer:=0;
process producer:
	while(TRUE)
		produce an item in nextp; //����һ����Ʒ
		if(counter==k) sleep();//��������������˯��
		buffer[in]:=next;//һ����Ʒ���뻺����
		in:=(in+1)mod k;//ָ���ƽ�
		counter:=counter+1;//�������ڲ�Ʒ����1
		if(counter==1) wakeup(consumer);//����Ϊ������ ������������
		
process consumer:
	while(TRUE)
		if(counter==0)sleep();//�������� ������˯��
		nextc:=buffer[out];//ȡһ����Ʒ
		out:=(out+1)mod k;
		counter:=counter-1;
		if(counter=k-1)wakeup(producer)
		
		consume thr item in nextc;//���Ĳ�Ʒ