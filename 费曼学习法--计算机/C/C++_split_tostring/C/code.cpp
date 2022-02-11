#include<bits/stdc++.h> // 万能头文件 
//stringstream在头文件 <sstream>
//sscanf, sprintf在头文件 <stdio.h>  
using namespace std;

/*
split_sstream 用stringstream实现以空格分割字符串
输入为string类型变量s 
输出为经过空格分割后,存储在vector中的字符串数组
*/
vector<string> split_sstream(string s){
	stringstream ss;
	string ans_s;
	vector<string> ans_v;
	
	ss << s;
	
	while(ss >> ans_s){
		ans_v.push_back(ans_s);
	}
	
	return ans_v;
}

/*
split_strtok 用strtok实现以delim分割字符串
输入为string类型变量s和分割字符delim 
输出为经过空格分割后,存储在vector中的字符串数组
*/
vector<string> split_strtok(string s, const char* delim = " "){
	string ans_s;
	char * pointer = NULL;
	vector<string> ans_v;
	
	//转换string to char*
	char* s_char = new char[s.size()];
	strcpy(s_char, s.c_str());
	
	pointer = strtok(s_char, delim);
	
	while(pointer != NULL) {
		ans_s = pointer;
		ans_v.push_back(ans_s);
		
		//这里用NULL的原因：
		//源码中会判断是否是第二次调用
		//如果是第二次调用,就会从上次结束的位置后的字符串作为开始 
		pointer = strtok(NULL, delim);
	}
	
	return ans_v;
}

/*
str2num_sstream 用sstream实现将字符串转换成数字 
输入为string类型变量s
输出为double类型变量 
*/

double str2num_sstream(string s){
	
	stringstream ss;
	ss << s;
	
	double ans_d;
	
	ss >> ans_d;
	
	return ans_d; 
}

/*
str2num_sscanf_sprintf 用sscanf和sprintf实现将字符串转换成数字 
输入为string类型变量s
输出为double类型变量 
*/

double str2num_sscanf_sprintf(string s){
	
	const char* s_char = s.c_str();
	
	double ans_d;
	
	
	//sscanf用法和scanf类似，第一个参数表示输入来源，这里即将s_char的内容以%f的形式送给ans_d 
	//注意double用%lf,以及double前面的& 
	sscanf(s_char, "%lf", &ans_d);
	
	return ans_d;
}

/*
num2str_sstream 用sstream实现将数字转换成字符串
输入为double类型变量num
输出为string类型变量 
*/ 
string num2str_sstream(double num){
	
	stringstream ss;

	string ans_s;
	
	ss << num;
	
	//1
	ss >> ans_s; 
	
	//2
	ans_s = ss.str() ;
	
	return ans_s;
} 

/*
num2str_sscanf_sprintf 用sscanf和sprintf实现将数字转换成字符串
输入为double类型变量num
输出为string类型变量 
*/ 
string num2str_sscanf_sprintf(double num){
	
	string ans_s;
	
	char* s_char;
	
	sprintf(s_char, "%lf", num);
	
	ans_s = s_char;
	
	return ans_s;	
} 

//遍历vector 
void printVector(vector<string> v){
	vector<string>::iterator it = v.begin();
	
	while(it != v.end()){
		cout << *it << endl;
		it++;
	}
	cout << endl;
}

//测试上述所写函数功能是否正常 
void test(string s1, string s2, double num){
	vector<string> ans_v;
	string ans_str; 
	double ans_d;
	
	//测试split 
	ans_v = split_sstream(s1);
	cout << "split_sstream函数运行结果:" << endl;
	printVector(ans_v);
	
	ans_v = split_strtok(s1, " ");
	cout << "split_strtok函数运行结果:" << endl;
	printVector(ans_v);
	
	//测试str2num 
	ans_d =  str2num_sstream(s2);
	cout << "str2num_sstream函数运行结果:" << endl;
	cout << ans_d << endl << endl;
	
	ans_d =  str2num_sscanf_sprintf(s2);
	cout << "str2num_sscanf_sprintf函数运行结果:" << endl;
	cout << ans_d << endl << endl;
	
	//测试num2str
	ans_str =  num2str_sstream(num);
	cout << "num2str_sstream函数运行结果:" << endl;
	cout << ans_str << endl << endl;
	
	ans_str =  num2str_sscanf_sprintf(num);
	cout << "num2str_sscanf_sprintf函数运行结果:" << endl;
	cout << ans_str << endl << endl;
}

int main(){
	
	test("I LOVE U","123.456", 789.10);
	cout << endl;
	test("Hello World","777", 888); 
	
	//split delim测试
	vector<string> ans_v;
	ans_v = split_strtok("If I were you, I won't do it, right?", ",");
	cout << "以逗号\',\'分割结果为:" << endl; 
	printVector(ans_v);
	
	ans_v = split_strtok("If I were you*! I won't do it*! right? *!", "*!");
	cout << "以星号+感叹号\'*!\'分割结果为:" << endl; 
	printVector(ans_v);
	
	
	return 0;
}
