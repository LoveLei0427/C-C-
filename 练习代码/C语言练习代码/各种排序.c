copy

    //冒泡排序  
    void Bubble_Sort(int *a,int n)  
    {  
        //外层循环，每循环一次，将当前最小值上浮  
        for (int i=0; i<n-1; i++)  
        {  
            //内层循环，反复交换，将最小值移到A[i]处  
            for (int j=n-1;j>i;j--)  
            {  
                //当a[j]<a[j-1]时，交换元素次序，实现递增排序  
                if (a[j] < a[j-1])     
                {  
                    int temp;  
                    temp = a[j-1];  
                    a[j-1] = a[j];  
                    a[j] = temp;  
                }  
            }  
        }  
    }  

因为影响算法复杂度的主要部分是交换和循环，它的时间复杂度是O(N2).

 

交换排序：思路是每次用当前的元素和其后的元素意义比较并交换。
[cpp] view plaincopy

    //交换排序  
    void Exchange_Sort(int *a,int n)  
    {  
        //外层循环，每循环一次，找出当前最小值  
        for (int i=0; i<n-1; i++)  
        {  
            //内层循环，找出当前最小值  
            for (int j=i+1; j<n; j++)  
            {  
                if (a[j] < a[i]) //递增排序  
                {  
                    int temp;  
                    temp = a[i];  
                    a[i] = a[j];  
                    a[j] = temp;  
                }  
            }  
        }  
    }  

算法的时间复杂度是O（N2）。

选择法排序：是指从数据中选择最小的同第一个值交换，再从剩下的部分中选择最小的与第二个值交换，直到所有的数据均有序为止。
[cpp] view plaincopy

    //选择法  
    void Select_Sort(int *a,int n)  
    {  
        int temp;           //存放最小值  
        int pos;            //存放最小值的下标  
      
        //外层循环，每一次循环将最小值放入到位置i  
        for (int i=0; i<n-1; i++)  
        {  
            //初始化  
            temp = a[i];  
            pos = i;  
            for (int j=i+1; j<n; j++)  //内层循环，找出最小值  
            {  
                if (a[j] < temp)  //找出最小值  
                {  
                    temp = a[j];  
                    pos = j;  
                }  
            }  
            //将最小元素与当前位置元素交换  
            a[pos] = a[i];  
            a[i] = temp;  
        }  
    }  

算法的时间复杂度是O（N2）。

插入排序：

要求插入后此数据序列仍然有序，插入排序的基本操作就是将一个数据插入到已经排好序的有序数据中，从而得到一个新的、个数加一的有序数据，算法适用于少量数据的排序，时间复杂度为O(n^2)。是稳定的排序方法。这里讲的只是简单插入排序，关于二路插入排序和希尔排序，在后面的部分会讲到。
[cpp] view plaincopy

    //插入排序  
    void Insert_Sort(int *a,int n)  
    {  
        /*外层循环，每次循环将一个元素插入到有序 
        序列中且保持序列有序*/  
        for (int j=1; j<n; j++)  
        {     
            int key = a[j];     //哨兵  
            int i = j;  
            //内层循环，将a[i]插入到有序序列  
            while (i>0 && a[i-1]>key)  
            {  
                a[i] = a[i-1];  
                i --;  
            }  
      
            a[i] = key;  
        }  
    }  

 

希尔排序：它是插入排序的的一种改进算法，它将原始的序列划分为几个序列，对每个子序列进行插入排序，使得原始序列基本有序后，再进行一次插入排序就可以完成排序了。
[cpp] view plaincopy

    //希尔排序  
    void Shell_Sort(int* a,int n)  
    {  
        int i,j,k,dk;  
        int increment = n;  
        int* delta = (int*)malloc(sizeof(int)*(n/2));  
        //将增量序列初始化  
        i = 0;  
        do   
        {  
            increment = increment/2;  
            delta[i++] = increment;  
        } while (increment>0);  
      
        i = 0;  
        while ((dk = delta[i])>0)  
        {  
            for(k =delta[i]; k<n; k++)  
            {  
                if (a[k]<a[k-dk])    // 需将a[k]插入有序增量子表   
                {   
                    int temp = a[k];             //暂存在t   
                    for(j=k-dk; j>=0 && temp<a[j]; j-=dk)  
                    {  
                        a[j+dk] = a[j]; //记录后移，查找插入位置   
                    }  
                    a[j+dk] = temp; // 插入  
                }  
            }  
            i = i + 1;   //取下一个增量值  
        }  
    }  


 快速排序：

快速排序的基本思想：

通过一趟排序将待排序的记录分割成独立的两部分，其中一部分记录的关键字比另一部分的关键字要小，然后分别对这两部分进行快速排序，已达到最后整个序列有序。
[cpp] view plaincopy

    //快速排序  
    void Quick_Sort(int* a,int low,int high)  
    {  
        int pivotkey = a[low];      //用子表的第一个记录作为枢轴元素  
        int i = low,j = high;  
        while (i < j)            //从表的两端交替地向中间扫描  
        {  
            while (i<j && a[j] >= pivotkey)  
            {  
                --j;  
            }  
            if (i < j)  
            {  
                a[i++] = a[j];      //比枢轴记录小的移动到低端  
            }  
            while (i<j && a[i] <= pivotkey)  
            {  
                ++i;  
            }  
            if (i < j)  
            {  
                a[j--] = a[i];      //比枢轴记录大的移动到高端  
            }  
      
            a[i] = pivotkey;            //枢轴记录到位  
            Quick_Sort(a,low,i-1);      //前半个表排序  
            Quick_Sort(a,i+1,high);     //后半个子表排序  
        }  
    }  


快速排序的时间复杂度O（nlogn）。快速排序虽然是平均性能比较好的一种排序算法，但是当待排序的序列基本有序或者是有序的时候，那么快速排序就退化为冒泡排序，其时间复杂度是O（n2）。

主函数如下：主要是用来测试程序的正确性
[cpp] view plaincopy

    int main()  
    {  
        int a[] = {10,8,9,7,6,5,4};  
        int flag;  
        printf("-----------------------请选择排序方法----------------------\n");  
        printf("-----------------------1、冒泡排序-------------------------\n");  
        printf("-----------------------2、交换排序-------------------------\n");  
        printf("-----------------------3、选择排序-------------------------\n");  
        printf("-----------------------4、简单插入排序---------------------\n");  
        printf("-----------------------5、希尔排序-------------------------\n");  
        printf("-----------------------6、快速排序-------------------------\n");  
        printf("请选择：");  
        scanf("%d",&flag);  
        switch (flag)  
        {  
        case 1:  
            Bubble_Sort(a,7);  
            break;  
        case 2:  
            Exchange_Sort(a,7);  
            break;  
        case 3:  
            Select_Sort(a,7);  
            break;  
        case 4:  
            Insert_Sort(a,7);  
            break;  
        case 5:  
            Shell_Sort(a,7);  
            break;  
        case 6:  
            Quick_Sort(a,0,6);  
            break;  
        default:  
            break;  
        }  
      
        printf("排序的结果为：\n");  
        for (int i=0; i<7; i++)  
        {  
            printf("%d,",a[i]);  
        }  
        printf("\n");  
      
        return 0;  
    }  


