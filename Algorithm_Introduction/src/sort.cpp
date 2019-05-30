#include "sort.h"
void sort::bubble_sort(vector<double> &data, bool reverse)
{
	/*
	 冒泡排序： 两两比较，
	 */
	bool flag =true;
	double tmp;
	int length = data.size();
	if (reverse)
		while(flag){
			flag = false;
			for (int i=0; i<length-1; i++) {
				if (data[i] < data[i+1]) {
					tmp = data[i];
					data[i] = data[i + 1];
					data[i + 1] = tmp;
					flag = true;
				}
			}
		}
	else
		while (flag) {
			flag = false;
			for (int i = 0; i < length - 1; i++) {
				if (data[i] > data[i + 1]) {
					tmp = data[i];
					data[i] = data[i + 1];
					data[i + 1] = tmp;
					flag = true;
				}
			}
		}
}

void sort::straight_insert_sort(vector<double>& data, bool reverse)
{
	/*
    直接插入排序
	*/
	int length = data.size();
	if (reverse)
		for (int i = 1; i < length; i++) {

			for (int j = 0; j < i; j++) {
				if (data[i] > data[j]) {
					data.insert(data.begin()+j, data[i]);
					data.erase(data.begin() + i + 1);
					break;
				}
			}
		}
	else{
		for (int i = 1; i < length; i++) {

			for (int j = 0; j < i; j++) {
				if (data[i] < data[j]) {
					data.insert(data.begin() + j, data[i]);
					data.erase(data.begin() + i + 1);
					break;
				}
			}
		}
	}
}

void sort::shell_sort(vector<double>& data, bool reverse)
{
    /*
     * 希尔排序基本思想：利用增量increase,分组使用插入排序，然后逐渐减小增量，直到增量increase为1
     */
	int length = data.size();
	double tmp;
	for (int increase = length / 2; increase > 0; increase = increase / 2) {
	    for (int index = 0;index<increase;index++){
            //插入排序
            for(int i = index+increase;i<length;i = i+increase){
                for (int j = index;j<i;j=j+increase){
                    if (reverse){
                        if (data[i]>data[j]){
                            tmp = data[j];
                            data[j] = data[i];
                            data[i] = tmp;
                        }
                    }
                    else
                        if (data[i]<data[j]){
                            tmp = data[j];
                            data[j] = data[i];
                            data[i] = tmp;
                        }
                }
            }
	    }
	}
}

void sort::sample_select_sort(vector<double> &data, bool reverse) {
    int length = data.size();
    int p =0;
    double tmp;
    for (int i = 0;i<length;i++){
        tmp = data[i];
        p = i;
        for (int j = i;j<length;j++){
            if (reverse) {
                if (data[j] > tmp) {
                    tmp = data[j];
                    p = j;
                }
            }
            else{
                 if (data[j]<tmp){
                     tmp = data[j];
                     p = j;
                 }
            }
        }
        tmp = data[p];
        data[p] = data[i];
        data[i] = tmp;
    }
}

void sort::binary_select_sort(vector<double> &data, bool reverse) {
    int length = data.size();
    int half = length/2;
    int maxp,minp;
    double maxtemp,mintemp;
    if (reverse){
        for (int i = 0;i<half;i++){
            maxp = i;
            minp = length-1-i;
            maxtemp = data[maxp];
            mintemp = data[minp];
            for (int j = i;j<length-i;j++){
                if (data[j]>maxtemp){
                    maxp = j;
                    maxtemp = data[j];
                }
                if (data[j]<mintemp){
                    minp = j;
                    mintemp = data[j];
                }
            }
            //交换最大值
            maxtemp = data[maxp];
            data[maxp] = data[i];
            data[i] = maxtemp;
            //交换最小值,防止互相交换以及被换走的情况
            if (minp == i){
                minp = maxp;
            }
            mintemp = data[minp];
            data[minp] = data[length-i-1];
            data[length-i-1] = mintemp;

        }
    }
    else{
        for (int i = 0;i<half;i++){
            maxp = i;
            minp = length-1-i;
            maxtemp = data[maxp];
            mintemp = data[minp];
            for (int j = i;j<length-i;j++){
                if (data[j]<maxtemp){
                    maxp = j;
                    maxtemp = data[j];
                }
                if (data[j]>mintemp){
                    minp = j;
                    mintemp = data[j];
                }
            }
            //交换最大值
            maxtemp = data[maxp];
            data[maxp] = data[i];
            data[i] = maxtemp;
            //交换最小值
            if (minp == i){
                minp = maxp;
            }
            mintemp = data[minp];
            data[minp] = data[length-i-1];
            data[length-i-1] = mintemp;

        }
    }
}
