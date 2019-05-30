#pragma once
#include<vector>
using std::vector;
class sort
{
    /*
     * 代码中设置了正序和逆序，为方便期间，未考虑效率问题
     */
public:
	void bubble_sort(vector<double> &data ,bool reverse = true);

	void straight_insert_sort(vector<double>& data, bool reverse = true);

	void shell_sort(vector<double>& data, bool reverse);

	void sample_select_sort(vector<double> &data, bool reverse);

	void binary_select_sort(vector<double> &data, bool reverse);
};

